#pragma once

#include "GameDefs.h"

// This class implements caching mechanism for graphic resources

// Since engine uses original GTA assets, cache requires styledata to be provided
// Some textures, such as block tiles, may be combined into huge atlases for performance reasons 
class SpriteManager final: public cxx::noncopyable
{
public:
    // animating blocks texture indices table
    GpuTexture1D* mBlocksIndicesTable = nullptr;

    // all blocks are packed into single texture array, where each level is single 64x64 bitmap
    GpuTextureArray2D* mBlocksTextureArray = nullptr;

    // all default objects bitmaps (with no deltas applied) are stored in single 2d texture
    Spritesheet mObjectsSpritesheet;

public:
    // preload sprite textures for current level
    bool InitLevelSprites();

    // flush all currently cached sprites
    void Cleanup();

    void RenderFrameBegin();
    void RenderFrameEnd();

    void UpdateBlocksAnimations(Timespan deltaTime);

    // force drop cached sprites
    // @param objectID: Specific object identifier
    void FlushSpritesCache();
    void FlushSpritesCache(GameObjectID_t objectID);

    // create sprite texture with deltas specified
    // @param objectID: Game object that owns sprite
    // @param spriteIndex: Sprite index, linear
    // @param deltaBits: Sprite delta bits
    // @param sourceSprite: Sprite data
    void GetSpriteTexture(GameObjectID_t objectID, int spriteIndex, SpriteDeltaBits_t deltaBits, Sprite& sourceSprite);
    void GetSpriteTexture(GameObjectID_t objectID, int spriteIndex, Sprite& sourceSprite);

    // save all blocks textures to hard drive
    void DumpBlocksTexture(const char* outputLocation);
    void DumpSpriteTextures(const char* outputLocation);
    void DumpSpriteDeltas(const char* outputLocation);
    void DumpSpriteDeltas(const char* outputLocation, int spriteIndex);
    void DumpCarsTextures(const char* outputLocation);

private:
    bool InitBlocksIndicesTable();
    bool InitBlocksTexture();
    bool InitObjectsSpritesheet();
    void InitBlocksAnimations();

    // find texture with required size and format or create new if nothing found
    GpuTexture2D* GetFreeSpriteTexture(const Size2D& dimensions, eTextureFormat format);
    void DestroySpriteTextures();

private:
    // animation state for blocks sharing specific texture
    struct BlockAnimation: public SpriteAnimation
    {
    public:
        int mBlockIndex; // linear
    };

    std::vector<BlockAnimation> mBlocksAnimations;
    std::vector<unsigned short> mBlocksIndices;
    bool mIndicesTableChanged;

    // usused sprite textures
    std::vector<GpuTexture2D*> mFreeSpriteTextures;

    // cached sprite textures with deltas
    struct SpriteCacheElement
    {
    public:
        GameObjectID_t mObjectID; // object identifier which this sprite belongs to
        int mSpriteIndex;
        SpriteDeltaBits_t mSpriteDeltaBits; // all deltas applied to this sprite
        GpuTexture2D* mTexture;
        TextureRegion mTextureRegion;
    };
    std::vector<SpriteCacheElement> mSpritesCache;
};

extern SpriteManager gSpriteManager;