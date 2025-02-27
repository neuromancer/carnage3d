#include "stdafx.h"
#include "CommonTypes.h"
#include "GameDefs.h"
#include "GraphicsDefs.h"

impl_enum_strings(eLogMessage)
{
    {eLogMessage_Debug, "debug"},
    {eLogMessage_Info, "info"},
    {eLogMessage_Warning, "warning"},
    {eLogMessage_Error, "error"},
};

impl_enum_strings(eLidRotation)
{
    {eLidRotation_0, "0"},
    {eLidRotation_90, "90"},
    {eLidRotation_180, "180"},
    {eLidRotation_270, "270"},
};

impl_enum_strings(eTextureWrapMode)
{
    {eTextureWrapMode_Repeat, "repeat"},
    {eTextureWrapMode_ClampToEdge, "clamp_to_edge"},
};

impl_enum_strings(eTextureFilterMode)
{
    {eTextureFilterMode_Nearest, "nearest"},
    {eTextureFilterMode_Bilinear, "bilinear"},
    {eTextureFilterMode_Trilinear, "trilinear"},
};

impl_enum_strings(eTextureFormat)
{
    {eTextureFormat_Null, "null"},
    {eTextureFormat_R8, "r8"},
    {eTextureFormat_R8_G8, "r8_g8"},
    {eTextureFormat_RGB8, "rgb8"},
    {eTextureFormat_RGBA8, "rgba8"},
    {eTextureFormat_RU16, "ru16"},
};

impl_enum_strings(ePrimitiveType)
{
    {ePrimitiveType_Points, "points"},
    {ePrimitiveType_Lines, "lines"},
    {ePrimitiveType_LineLoop, "line_loop"},
    {ePrimitiveType_Triangles, "triangles"},
    {ePrimitiveType_TriangleStrip, "triangle_strip"},
    {ePrimitiveType_TriangleFan, "triangle_fan"},
};

impl_enum_strings(eIndicesType)
{
    {eIndicesType_i16, "i16"},
    {eIndicesType_i32, "i32"},
};

impl_enum_strings(eTextureUnit)
{
    {eTextureUnit_0, "tex_0"},
    {eTextureUnit_1, "tex_1"},
    {eTextureUnit_2, "tex_2"},
    {eTextureUnit_3, "tex_3"},
    {eTextureUnit_4, "tex_4"},
    {eTextureUnit_5, "tex_5"},
    {eTextureUnit_6, "tex_6"},
    {eTextureUnit_7, "tex_7"},
    {eTextureUnit_8, "tex_8"},
    {eTextureUnit_9, "tex_9"},
    {eTextureUnit_10, "tex_10"},
    {eTextureUnit_11, "tex_11"},
    {eTextureUnit_12, "tex_12"},
    {eTextureUnit_13, "tex_13"},
    {eTextureUnit_14, "tex_14"},
    {eTextureUnit_15, "tex_15"},
};

impl_enum_strings(eVertexAttributeSemantics)
{
    {eVertexAttributeSemantics_Position, "position"},
    {eVertexAttributeSemantics_Normal, "normal"},
    {eVertexAttributeSemantics_Color, "color"},
    {eVertexAttributeSemantics_Texcoord, "texcoord"},
    {eVertexAttributeSemantics_Position2d, "position2d"},
    {eVertexAttributeSemantics_Texcoord3d, "texcoord3d"},
    {eVertexAttributeSemantics_Unknown, "unknown"},
};

impl_enum_strings(eVertexAttribute)
{
    {eVertexAttribute_Position0, "in_pos0"},
    {eVertexAttribute_Position1, "in_pos1"},
    {eVertexAttribute_Texcoord0, "in_texcoord0"},
    {eVertexAttribute_Texcoord1, "in_texcoord1"},
    {eVertexAttribute_Normal0, "in_normal0"},
    {eVertexAttribute_Normal1, "in_normal1"},
    {eVertexAttribute_Color0, "in_color0"},
    {eVertexAttribute_Color1, "in_color1"},
};

impl_enum_strings(eBufferContent)
{
    {eBufferContent_Vertices, "vertices"},
    {eBufferContent_Indices, "indices"},
};

impl_enum_strings(eBufferUsage)
{
    {eBufferUsage_Static, "static"},
    {eBufferUsage_Dynamic, "dynamic"},
    {eBufferUsage_Stream, "stream"},
};

impl_enum_strings(eRenderUniform)
{
    {eRenderUniform_ModelMatrix, "model_matrix"},
    {eRenderUniform_ViewMatrix, "view_matrix"},
    {eRenderUniform_ProjectionMatrix, "projection_matrix"},
    {eRenderUniform_ModelViewMatrix, "model_view_matrix"},
    {eRenderUniform_ModelViewProjectionMatrix, "model_view_projection_matrix"},
    {eRenderUniform_ViewProjectionMatrix, "view_projection_matrix"},
    {eRenderUniform_NormalMatrix, "normal_matrix"},
    {eRenderUniform_CameraPosition, "camera_position"},
    {eRenderUniform_EnableTextureMapping, "enable_texture_mapping"},
};

impl_enum_strings(eBlendMode)
{
    {eBlendMode_Alpha, "alpha"},
    {eBlendMode_Additive, "additive"},
    {eBlendMode_Multiply, "multiply"},
    {eBlendMode_Premultiplied, "premultiplied"},
    {eBlendMode_Screen, "screen"},
};

impl_enum_strings(eDepthTestFunc)
{
    {eDepthTestFunc_Always, "always"},
    {eDepthTestFunc_Equal, "equal"},
    {eDepthTestFunc_NotEqual, "not_equal"},
    {eDepthTestFunc_Less, "less"},
    {eDepthTestFunc_Greater, "greater"},
    {eDepthTestFunc_LessEqual, "less_equal"},
    {eDepthTestFunc_GreaterEqual, "greater_equal"},
};

impl_enum_strings(eCullMode)
{
    {eCullMode_Front, "front"},
    {eCullMode_Back, "back"},
    {eCullMode_FrontAndBack, "front_and_back"},
};

impl_enum_strings(eFillMode)
{
    {eFillMode_Solid, "solid"},
    {eFillMode_WireFrame, "wireframe"},
};

impl_enum_strings(eBlockType)
{
    {eBlockType_Side, "side"},
    {eBlockType_Lid, "lid"},
    {eBlockType_Aux, "aux"},
};

impl_enum_strings(eSpriteType)
{
    {eSpriteType_Arrow, "arrow"},
    {eSpriteType_Digit, "digit"},
    {eSpriteType_Boat, "boat"},
    {eSpriteType_Box, "box"},
    {eSpriteType_Bus, "bus"},
    {eSpriteType_Car, "car"},
    {eSpriteType_Object, "object"},
    {eSpriteType_Ped, "ped"},
    {eSpriteType_Speedo, "speedo"},
    {eSpriteType_Tank, "tank"},
    {eSpriteType_TrafficLight, "traffic_light"},
    {eSpriteType_Train, "train"},
    {eSpriteType_TrDoor, "trdoor"},
    {eSpriteType_Bike, "bike"},
    {eSpriteType_Tram, "tram"},
    {eSpriteType_WCar, "wcar"},
    {eSpriteType_WBus, "wbus"},
    {eSpriteType_Ex, "ex"},
    {eSpriteType_TumCar, "tumcar"},
    {eSpriteType_TumTruck, "tumtruck"},
    {eSpriteType_Ferry, "ferry"},
};

impl_enum_strings(eGroundType)
{
    {eGroundType_Air, "air"},
    {eGroundType_Water, "water"},
    {eGroundType_Road, "road"},
    {eGroundType_Pawement, "pawement"},
    {eGroundType_Field, "field"},
    {eGroundType_Building, "building"},
};

impl_enum_strings(eBlockFace)
{
    {eBlockFace_W, "w"},
    {eBlockFace_E, "e"},
    {eBlockFace_N, "n"},
    {eBlockFace_S, "s"},
    {eBlockFace_Lid, "lid"},
};

impl_enum_strings(eCarVType)
{
    {eCarVType_Bus, "bus"},
    {eCarVType_FrontOfJuggernaut, "front_of_juggernaut"},
    {eCarVType_BackOfJuggernaut, "back_of_juggernaut"},
    {eCarVType_Motorcycle, "motorcycle"},
    {eCarVType_StandardCar, "standard_car"},
    {eCarVType_Train, "train"},
    {eCarVType_Tram, "tram"},
    {eCarVType_Boat, "boat"},
    {eCarVType_Tank, "tank"},
};

impl_enum_strings(eSpriteAnimationID)
{
    {eSpriteAnimationID_Null, "null"},
    {eSpriteAnimationID_Ped_Walk, "ped_walk"},
    {eSpriteAnimationID_Ped_Run, "ped_run"},
    {eSpriteAnimationID_Ped_ExitCar, "ped_exit_car"},
    {eSpriteAnimationID_Ped_EnterCar, "ped_enter_car"},
    {eSpriteAnimationID_Ped_FallLong, "ped_fall_long"},
    {eSpriteAnimationID_Ped_SlideUnderTheCar, "ped_slide_under_the_car"},
    {eSpriteAnimationID_Ped_StandingStill, "ped_standing_still"},
    {eSpriteAnimationID_Ped_JumpOntoCar, "ped_jump_onto_car"},
    {eSpriteAnimationID_Ped_SlideOnCar, "ped_slide_on_car"},
    {eSpriteAnimationID_Ped_DropOffCarSliding, "ped_drop_off_car_sliding"},
    {eSpriteAnimationID_Ped_FallShort, "ped_fall_short"},
    {eSpriteAnimationID_Ped_LiesOnFloor, "ped_lies_on_floor"},
    {eSpriteAnimationID_Ped_PunchingWhileStanding, "ped_punching_while_standing"},
    {eSpriteAnimationID_Ped_PunchingWhileRunning, "ped_punching_while_running"},
    {eSpriteAnimationID_Ped_ShootPistolWhileStanding, "ped_shoot_pistol_while_standing"},
    {eSpriteAnimationID_Ped_ShootPistolWhileWalking, "ped_shoot_pistol_while_walking"},
    {eSpriteAnimationID_Ped_ShootPistolWhileRunning, "ped_shoot_pistol_while_running"},
    {eSpriteAnimationID_Ped_ShootMachinegunWhileStanding, "ped_shoot_machinegun_while_standing"},
    {eSpriteAnimationID_Ped_ShootMachinegunWhileWalking, "ped_shoot_machinegun_while_walking"},
    {eSpriteAnimationID_Ped_ShootMachinegunWhileRunning, "ped_shoot_machinegun_while_running"},
    {eSpriteAnimationID_Ped_ShootFlamethrowerWhileStanding, "ped_shoot_flamethrower_while_standing"},
    {eSpriteAnimationID_Ped_ShootFlamethrowerWhileWalking, "ped_shoot_flamethrower_while_walking"},
    {eSpriteAnimationID_Ped_ShootFlamethrowerWhileRunning, "ped_shoot_flamethrower_while_running"},
    {eSpriteAnimationID_Ped_ShootRPGWhileStanding, "ped_shoot_rpg_while_standing"},
    {eSpriteAnimationID_Ped_ShootRPGWhileWalking, "ped_shoot_rpg_while_walking"},
    {eSpriteAnimationID_Ped_ShootRPGWhileRunning, "ped_shoot_rpg_while_running"},
};

impl_enum_strings(eWeaponType)
{
    {eWeaponType_Fists, "fists"},
    {eWeaponType_Pistol, "pistol"},
    {eWeaponType_Machinegun, "machinegun"},
    {eWeaponType_Flamethrower, "flamethrower"},
    {eWeaponType_RocketLauncher, "rocket_launcher"},
};

impl_enum_strings(ePedestrianAction)
{
    {ePedestrianAction_TurnLeft, "turn_left"},
    {ePedestrianAction_TurnRight, "turn_right"},
    {ePedestrianAction_Jump, "jump"},
    {ePedestrianAction_WalkForward, "walk_forward"},
    {ePedestrianAction_WalkBackward, "walk_backward"},
    {ePedestrianAction_Run, "run"},
    {ePedestrianAction_Shoot, "shoot"},
    {ePedestrianAction_EnterCar, "enter_car"},
    {ePedestrianAction_LeaveCar, "leave_car"},
};

impl_enum_strings(ePedestrianState)
{
    {ePedestrianState_StandingStill, "standing_still"},
    {ePedestrianState_StandsAndShoots, "stands_and_shoots"},
    {ePedestrianState_Walks, "walks"},
    {ePedestrianState_Runs, "runs"},
    {ePedestrianState_WalksAndShoots, "walks_and_shoots"},
    {ePedestrianState_RunsAndShoots, "runs_and_shoots"},
    {ePedestrianState_Falling, "falling"},
    {ePedestrianState_EnteringCar, "entering_car"},
    {ePedestrianState_ExitingCar, "exiting_car"},
    {ePedestrianState_DrivingCar, "driving_car"},
    {ePedestrianState_SlideOnCar, "slide_on_car"},
    {ePedestrianState_Dying, "dying"},
    {ePedestrianState_Dead, "dead"},
    {ePedestrianState_KnockedDown, "knocked_down"},
};

impl_enum_strings(eConsoleLineType)
{
    {eConsoleLineType_Message, "message"},
    {eConsoleLineType_Command, "command"},
};

impl_enum_strings(eSceneCameraMode)
{
    {eSceneCameraMode_Perspective, "perspective"},
    {eSceneCameraMode_Orthographic, "orthographic"},
};

impl_enum_strings(eSpriteAnimStatus)
{
    {eSpriteAnimStatus_Stop, "stop"},
    {eSpriteAnimStatus_PlayForward, "play_forward"},
    {eSpriteAnimStatus_PlayBackward, "play_backward"},
};

impl_enum_strings(eSpriteAnimLoop)
{
    {eSpriteAnimLoop_None, "none"},
    {eSpriteAnimLoop_PingPong, "ping_pong"},
    {eSpriteAnimLoop_FromStart, "from_start"},
};

impl_enum_strings(eCarModel)
{
    {eCarModel_BeastGTS_1, "beast_gts_1"},
    {eCarModel_Bug, "bug"},
    {eCarModel_Counthash, "counthash"},
    {eCarModel_Bike, "bike"},
    {eCarModel_Police, "police"},
    {eCarModel_Ambulance, "ambulance"},
    {eCarModel_RepairVan, "repair_van"},
    {eCarModel_Juggernaut, "juggernaut"},
    {eCarModel_Coach, "coach"},
    {eCarModel_Train, "train"},
    {eCarModel_Tram, "tram"},
    {eCarModel_Boat, "boat"},
    {eCarModel_Penetrator_1, "penetrator_1"},
    {eCarModel_Itali, "itali"},
    {eCarModel_Mundano_1, "mundano_1"},
    {eCarModel_4x4, "4x4"},
    {eCarModel_Stallion, "stallion"},
    {eCarModel_Taxi, "taxi"},
    {eCarModel_Impaler_1, "impaler_1"},
    {eCarModel_Jugular, "jugular"},
    {eCarModel_Pickup_1, "pickup_1"},
    {eCarModel_PorkaTurbo, "porka_turbo"},
    {eCarModel_Cossie, "cossie"},
    {eCarModel_Bulldog, "bulldog"},
    {eCarModel_Challenger, "challenger"},
    {eCarModel_Limousine_1, "limousine_1"},
    {eCarModel_Tank, "tank"},
    {eCarModel_Superbike, "superbike"},
    {eCarModel_FireTruck, "fire_truck"},
    {eCarModel_Bus, "bus"},
    {eCarModel_Tanker, "tanker"},
    {eCarModel_TVVan, "tv_van"},
    {eCarModel_TransitVan, "transit_van"},
    {eCarModel_ModelCar, "model_car"},
    {eCarModel_Roadster, "roadster"},
    {eCarModel_LoveWagon, "love_wagon"},
    {eCarModel_BeastGTS_2, "beast_gts_2"},
    {eCarModel_Mundano_2, "mundano_2"},
    {eCarModel_Mamba, "mamba"},
    {eCarModel_Portsmouth, "portsmouth"},
    {eCarModel_Speeder, "speeder"},
    {eCarModel_Porka, "porka"},
    {eCarModel_Flamer, "flamer"},
    {eCarModel_Vulture, "vulture"},
    {eCarModel_Pickup_2, "pickup_2"},
    {eCarModel_ItaliGTO, "itali_tgo"},
    {eCarModel_Regal, "regal"},
    {eCarModel_MonsterBug, "monster_bug"},
    {eCarModel_Thunderhead, "thunderhead"},
    {eCarModel_Panther, "panther"},
    {eCarModel_Penetrator_2, "penetrator_2"},
    {eCarModel_LeBonham, "lebonham"},
    {eCarModel_Stinger, "stinger"},
    {eCarModel_F19, "f19"},
    {eCarModel_Brigham, "brigham"},
    {eCarModel_StingerZ29, "stinger_z29"},
    {eCarModel_Classic, "classic"},
    {eCarModel_29Special, "29_special"},
    {eCarModel_ItaliGTB, "itali_gtb"},
    {eCarModel_Hotrod, "hotrod"},
    {eCarModel_Limousine_2, "limousine_2"},
    {eCarModel_Impaler_2, "impaler_2"},
    {eCarModel_Helicopter, "helicopter"},
};