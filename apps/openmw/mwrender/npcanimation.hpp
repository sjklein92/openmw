#ifndef _GAME_RENDER_NPCANIMATION_H
#define _GAME_RENDER_NPCANIMATION_H

#include "animation.hpp"

#include "../mwworld/inventorystore.hpp"
#include "../mwworld/containerstore.hpp"

namespace ESM
{
    struct NPC;
}

namespace MWRender
{

class NpcAnimation : public Animation
{
public:
struct PartInfo {
    ESM::PartReferenceType type;
    NifOgre::EntityList NpcAnimation::*ents;
    const char name[32];
};

private:
    static const size_t sPartListSize = 27;
    static const PartInfo sPartList[sPartListSize];

    MWWorld::InventoryStore& mInv;
    int mStateID;

    //Bounded Parts
    NifOgre::EntityList mClavicleL;
    NifOgre::EntityList mClavicleR;
    NifOgre::EntityList mUpperArmL;
    NifOgre::EntityList mUpperArmR;
    NifOgre::EntityList mUpperLegL;
    NifOgre::EntityList mUpperLegR;
    NifOgre::EntityList mForearmL;
    NifOgre::EntityList mForearmR;
    NifOgre::EntityList mWristL;
    NifOgre::EntityList mWristR;
    NifOgre::EntityList mKneeR;
    NifOgre::EntityList mKneeL;
    NifOgre::EntityList mNeck;
    NifOgre::EntityList mAnkleL;
    NifOgre::EntityList mAnkleR;
    NifOgre::EntityList mGroin;
    NifOgre::EntityList mSkirt;
    NifOgre::EntityList mFootL;
    NifOgre::EntityList mFootR;
    NifOgre::EntityList mHair;
    NifOgre::EntityList mHandL;
    NifOgre::EntityList mHandR;
    NifOgre::EntityList mShield;
    NifOgre::EntityList mWeapon;
    NifOgre::EntityList mHead;
    NifOgre::EntityList mChest;
    NifOgre::EntityList mTail;

    const ESM::NPC  *mNpc;
    std::string     mHeadModel;
    std::string     mHairModel;
    std::string     mBodyPrefix;

    float mTimeToChange;
    MWWorld::ContainerStoreIterator mRobe;
    MWWorld::ContainerStoreIterator mHelmet;
    MWWorld::ContainerStoreIterator mShirt;
    MWWorld::ContainerStoreIterator mCuirass;
    MWWorld::ContainerStoreIterator mGreaves;
    MWWorld::ContainerStoreIterator mPauldronL;
    MWWorld::ContainerStoreIterator mPauldronR;
    MWWorld::ContainerStoreIterator mBoots;
    MWWorld::ContainerStoreIterator mPants;
    MWWorld::ContainerStoreIterator mGloveL;
    MWWorld::ContainerStoreIterator mGloveR;
    MWWorld::ContainerStoreIterator mSkirtIter;

    int mVisibilityFlags;

    int mPartslots[sPartListSize];  //Each part slot is taken by clothing, armor, or is empty
    int mPartPriorities[sPartListSize];

    NifOgre::EntityList insertBoundedPart(const std::string &mesh, int group, const std::string &bonename);
    void updateParts();
    void removeEntities(NifOgre::EntityList &entities);
    void removeIndividualPart(int type);
    void reserveIndividualPart(int type, int group, int priority);

    bool addOrReplaceIndividualPart(int type, int group, int priority, const std::string &mesh);
    void removePartGroup(int group);
    void addPartGroup(int group, int priority, const std::vector<ESM::PartReference> &parts);

public:
    NpcAnimation(const MWWorld::Ptr& ptr, Ogre::SceneNode* node,
                 MWWorld::InventoryStore& inv, int visibilityFlags);
    virtual ~NpcAnimation();

    virtual Ogre::Vector3 runAnimation(float timepassed);

    void forceUpdate();
};

}

#endif
