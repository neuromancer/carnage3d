#include "stdafx.h"
#include "GameObjectsManager.h"
#include "Vehicle.h"
#include "Pedestrian.h"
#include "PhysicsComponents.h"
#include "GameMapManager.h"

bool GameObjectsManager::Initialize()
{
    mIDsCounter = 0;

    return true;
}

void GameObjectsManager::Deinit()
{
    DestroyObjectsInList(mActivePedestriansList);
    DestroyObjectsInList(mDeletePedestriansList);

    DestroyObjectsInList(mActiveCarsList);
    DestroyObjectsInList(mDeleteCarsList);
}

void GameObjectsManager::UpdateFrame(Timespan deltaTime)
{
    DestroyPendingObjects();
    
    // update pedestrians
    bool hasDeletePeds = false;
    for (Pedestrian* currentPed: mActivePedestriansList) // warning: dont add or remove peds during this loop
    {
        if (!currentPed->mMarkForDeletion)
        {
            debug_assert(!mDeletePedestriansList.contains(&currentPed->mDeletePedsNode));
            currentPed->UpdateFrame(deltaTime);
        }

        if (currentPed->mMarkForDeletion)
        {
            mDeletePedestriansList.insert(&currentPed->mDeletePedsNode);
            hasDeletePeds = true;
        }
    }

    if (hasDeletePeds)
    {
        // deactivate all peds marked for deletion
        for (Pedestrian* deletePed: mDeletePedestriansList)
        {
            RemoveFromActiveList(deletePed);
        }
    }

    // update cars    
    bool hasDeleteCars = false;
    for (Vehicle* currentCar: mActiveCarsList) // warning: dont add or remove cars during this loop
    {
        if (!currentCar->mMarkForDeletion)
        {
            debug_assert(!mDeleteCarsList.contains(&currentCar->mDeleteCarsNode));
            currentCar->UpdateFrame(deltaTime);
        }

        if (currentCar->mMarkForDeletion)
        {
            mDeleteCarsList.insert(&currentCar->mDeleteCarsNode);
            hasDeleteCars = true;
        }
    }

    if (hasDeleteCars)
    {
        // deactivate all cars marked for deletion
        for (Vehicle* deleteCar: mDeleteCarsList)
        {
            RemoveFromActiveList(deleteCar);
        }
    }
}

void GameObjectsManager::DebugDraw()
{
}

Pedestrian* GameObjectsManager::CreatePedestrian(const glm::vec3& position)
{
    GameObjectID_t pedestrianID = GenerateUniqueID();

    Pedestrian* instance = mPedestriansPool.create(pedestrianID);
    debug_assert(instance);

    AddToActiveList(instance);

    // init
    instance->EnterTheGame();
    instance->mPhysicsComponent->SetPosition(position);
    return instance;
}

Pedestrian* GameObjectsManager::GetPedestrianByID(GameObjectID_t objectID) const
{
    for (const Pedestrian* currVehicle: mActivePedestriansList)
    {
        if (currVehicle->mObjectID == objectID)
            return const_cast<Pedestrian*>(currVehicle);
    }
    return nullptr;
}

Vehicle* GameObjectsManager::CreateCar(const glm::vec3& position, int carTypeId)
{
    StyleData& styleData = gGameMap.mStyleData;

    debug_assert(styleData.IsLoaded());
    debug_assert(carTypeId < (int)styleData.mCars.size());

    GameObjectID_t carID = GenerateUniqueID();

    Vehicle* instance = mCarsPool.create(carID);
    debug_assert(instance);

    AddToActiveList(instance);

    // init
    instance->mCarStyle = &gGameMap.mStyleData.mCars[carTypeId];
    instance->EnterTheGame();
    instance->mPhysicsComponent->SetPosition(position);
    return instance;
}

Vehicle* GameObjectsManager::GetCarByID(GameObjectID_t objectID) const
{
    for (const Vehicle* currVehicle: mActiveCarsList)
    {
        if (currVehicle->mObjectID == objectID)
            return const_cast<Vehicle*>(currVehicle);
    }
    return nullptr;
}

void GameObjectsManager::DestroyGameObject(Pedestrian* object)
{
    if (object == nullptr)
    {
        debug_assert(false);
        return;
    }

    if (mDeletePedestriansList.contains(&object->mDeletePedsNode))
    {
        mDeletePedestriansList.remove(&object->mDeletePedsNode);
    }

    if (mActivePedestriansList.contains(&object->mActivePedsNode))
    {
        mActivePedestriansList.remove(&object->mActivePedsNode);
    }

    mPedestriansPool.destroy(object);
}

void GameObjectsManager::DestroyGameObject(Vehicle* object)
{
    if (object == nullptr)
    {
        debug_assert(false);
        return;
    }

    if (mDeleteCarsList.contains(&object->mDeleteCarsNode))
    {
        mDeleteCarsList.remove(&object->mDeleteCarsNode);
    }

    if (mActiveCarsList.contains(&object->mActiveCarsNode))
    {
        mActiveCarsList.remove(&object->mActiveCarsNode);
    }

    mCarsPool.destroy(object);
}

void GameObjectsManager::DestroyObjectsInList(cxx::intrusive_list<Pedestrian>& objectsList)
{
    while (objectsList.has_elements())
    {
        cxx::intrusive_node<Pedestrian>* pedestrianNode = objectsList.get_head_node();
        objectsList.remove(pedestrianNode);

        Pedestrian* pedestrian = pedestrianNode->get_element();
        mPedestriansPool.destroy(pedestrian);
    }
}

void GameObjectsManager::DestroyObjectsInList(cxx::intrusive_list<Vehicle>& objectsList)
{
    while (objectsList.has_elements())
    {
        cxx::intrusive_node<Vehicle>* carNode = objectsList.get_head_node();
        objectsList.remove(carNode);

        Vehicle* carInstance = carNode->get_element();
        mCarsPool.destroy(carInstance);
    }
}

void GameObjectsManager::AddToActiveList(Pedestrian* object)
{
    debug_assert(object);
    if (object == nullptr)
        return;

    debug_assert(!mActivePedestriansList.contains(&object->mActivePedsNode));
    debug_assert(!mDeletePedestriansList.contains(&object->mDeletePedsNode));
    mActivePedestriansList.insert(&object->mActivePedsNode);
}

void GameObjectsManager::AddToActiveList(Vehicle* object)
{
    debug_assert(object);
    if (object == nullptr)
        return;

    debug_assert(!mActiveCarsList.contains(&object->mActiveCarsNode));
    debug_assert(!mDeleteCarsList.contains(&object->mDeleteCarsNode));
    mActiveCarsList.insert(&object->mActiveCarsNode);
}

void GameObjectsManager::RemoveFromActiveList(Pedestrian* object)
{
    debug_assert(object);
    if (object && mActivePedestriansList.contains(&object->mActivePedsNode))
    {
        mActivePedestriansList.remove(&object->mActivePedsNode);
    }
}

void GameObjectsManager::RemoveFromActiveList(Vehicle* object)
{
    debug_assert(object);
    if (object && mActiveCarsList.contains(&object->mActiveCarsNode))
    {
        mActiveCarsList.remove(&object->mActiveCarsNode);
    }
}

void GameObjectsManager::DestroyPendingObjects()
{
    DestroyObjectsInList(mDeletePedestriansList);
    DestroyObjectsInList(mDeleteCarsList);
}

GameObjectID_t GameObjectsManager::GenerateUniqueID()
{
    GameObjectID_t newID = ++mIDsCounter;
    if (newID == 0) // overflow
    {
        debug_assert(false);
    }
    return newID;
}