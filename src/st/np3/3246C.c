/*
 * File: 3246C.c
 * Overlay: NP3
 * Description: Castle Entrance (After entering Alchemy Laboratory)
 */

#include "stage.h"

void SpawnExplosionEntity(u16, Entity*);
void ReplaceBreakableWithItemDrop(Entity*);
int func_801CD658();
void EntityItemDrop(Entity* entity);
void EntityHeartDrop(Entity* entity);

extern u16 D_80180A90[];
extern ObjInit2 D_80180C10[];
extern PfnEntityUpdate PfnEntityUpdates[];
extern s16 D_80181A50[];

void func_801B246C(Entity* arg0) {
    s32 temp_v0;
    ObjInit2* temp_s0 = &D_80180C10[arg0->subId];

    if (arg0->step == 0) {
        InitializeEntity(D_80180A90);
        arg0->animationSet = temp_s0->animationSet;
        arg0->zPriority = temp_s0->zPriority;
        arg0->unk14 = temp_s0->unk4.data1.unk0;
        arg0->unk5A = temp_s0->unk4.data1.unk1;
        arg0->palette = temp_s0->palette;
        arg0->unk19 = temp_s0->unk8;
        arg0->blendMode = temp_s0->blendMode;
        temp_v0 = temp_s0->unkC;
        if (temp_v0 != 0) {
            arg0->unk34 = temp_v0;
        }
    }

    AnimateEntity(temp_s0->unk10, arg0);
}

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B2540);

extern u16 g_eBreakableInit[];
extern u8* g_eBreakableAnimations[8];
extern u8 g_eBreakableHitboxes[];
extern u8 g_eBreakableExplosionTypes[];
extern u16 g_eBreakableAnimationSets[];
extern u8 g_eBreakableBlendModes[];
void EntityBreakable(Entity* entity) {
    u16 breakableType = entity->subId >> 0xC;
    if (entity->step) {
        AnimateEntity(g_eBreakableAnimations[breakableType], entity);
        if (entity->unk44) { // If the candle is destroyed
            Entity* entityDropItem;
            g_pfnPlaySfx(NA_SE_BREAK_CANDLE);
            entityDropItem =
                AllocEntity(D_8007D858, &D_8007D858[MaxEntityCount]);
            if (entityDropItem != NULL) {
                SpawnExplosionEntity(ENTITY_EXPLOSION, entityDropItem);
                entityDropItem->subId =
                    g_eBreakableExplosionTypes[breakableType];
            }
            ReplaceBreakableWithItemDrop(entity);
        }
    } else {
        InitializeEntity(g_eBreakableInit);
        entity->zPriority = g_zEntityCenter - 0x14;
        entity->blendMode = g_eBreakableBlendModes[breakableType];
        entity->hitboxHeight = g_eBreakableHitboxes[breakableType];
        entity->animationSet = g_eBreakableAnimationSets[breakableType];
    }
}

// TODO: Probably aspsx or compiler flags
// https://decomp.me/scratch/sKMmw
#ifndef NON_MATCHING
INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B2830);
#else

extern u16 D_80180A60;

typedef struct {
    /* 0x00 */ char pad00[0x2C];
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ char pad2E[0x4E];
    /* 0x7C */ s8 unk7C;
    /* 0x7D */ s8 unk7D;
    /* 0x7E */ s8 unk7E;
} UnkStruct11; // size = 0x7F

void func_801B2830(Entity* arg0) {
    switch (arg0->step) {
    case 0:
        InitializeEntity(&D_80180A60);
        arg0->unk7C.modeU8.unk0 = 0x10;
        arg0->unk7C.modeU8.unk1 = 8;
        arg0->unk7E = 0x38;

    case 1:
        D_8003CB25 = arg0->unk7C.modeU8.unk0;
        D_8003CB26 = arg0->unk7C.modeU8.unk1;
        D_8003CB27 = arg0->unk7E;
        D_80054319 = arg0->unk7C.modeU8.unk0;
        D_8005431A = arg0->unk7C.modeU8.unk1;
        D_8005431B = arg0->unk7E;
    }
}
#endif

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B28E4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B2C20);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B2F30);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B32A8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B3704);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B39CC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B3D24);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B3E84);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B4004);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B40F8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B44B4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B4558);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B4680);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B4940);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B4BE8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B4D60);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B5108);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B5488);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B560C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B5790);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B5C5C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B5DE8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B5E98);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B5F60);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B6084);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B644C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B653C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B65FC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B6990);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B75EC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B7798);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B78BC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B8CC0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B8D84);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B8E94);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B90BC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", UpdateStageEntities);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B93E8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801B94F0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityNumericDamage);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", CreateEntity);
#else
void CreateEntity(Entity* entity, LayoutObject* initDesc) {
    DestroyEntity(entity);
    entity->objectId = initDesc->objectId & 0x3FF;
    entity->pfnUpdate = PfnEntityUpdates[entity->objectId];
    entity->posX.Data.high = initDesc->posX - D_8007308E;
    entity->posY.Data.high = initDesc->posY - D_80073092;
    entity->subId = initDesc->subId;
    entity->objectRoomIndex = initDesc->objectRoomIndex >> 8;
    entity->unk68 = initDesc->objectId >> 0xA & 7;
}
#endif

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BAD70);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BAE88);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BAFA0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BAFEC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BB044);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BB140);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BB254);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BB2A0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BB2F8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BB3F4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", LoadObjLayout);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BB680);

void SpawnExplosionEntity(u16 objectId, Entity* entity) {
    DestroyEntity(entity);
    entity->objectId = objectId;
    entity->pfnUpdate = PfnEntityUpdates[objectId];
    entity->posX.Data.high = g_CurrentEntity->posX.Data.high;
    entity->posY.Data.high = g_CurrentEntity->posY.Data.high;
}

void func_801BB7A8(u16 objectId, Entity* source, Entity* entity) {
    DestroyEntity(entity);
    entity->objectId = objectId;
    entity->pfnUpdate = PfnEntityUpdates[objectId];
    entity->posX.Data.high = source->posX.Data.high;
    entity->posY.Data.high = source->posY.Data.high;
}

s32 func_801BB824(Unkstruct5* arg0) {
    Entity* player = GET_PLAYER(g_EntityArray);
    s16 diff;

    diff = player->posX.Data.high - arg0->unk2;
    diff = ABS_ALT(diff);

    if (diff >= 17) {
        diff = 0;
    } else {
        diff = player->posY.Data.high - arg0->unk6;
        diff = ABS_ALT(diff);
        diff = diff < 33;
    }

    return diff;
}

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityRedDoor);

void DestroyEntity(Entity* item) {
    s32 i;
    s32 length;
    u32* ptr;

    if (item->unk34 & 0x800000) {
        g_pfnFreePolygons(item->firstPolygonIndex);
    }

    ptr = (u32*)item;
    length = sizeof(Entity) / sizeof(s32);
    for (i = 0; i < length; i++)
        *ptr++ = 0;
}

void DestroyEntityFromIndex(s16 index) {
    Entity* entity = &g_EntityArray[index];

    while (entity < &D_8007EF1C) {
        DestroyEntity(entity);
        entity++;
    }
}

void PreventEntityFromRespawning(Entity* entity) {
    if (entity->objectRoomIndex) {
        u32 value = (entity->objectRoomIndex - 1);
        u16 index = value / 32;
        u16 bit = value % 32;
        g_entityDestroyed[index] |= 1 << bit;
    }
}

#include "st/AnimateEntity.h"

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BC6BC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BC7D4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BC810);

s16 func_801BC844(void) {
    Entity* player = GET_PLAYER(g_EntityArray);
    s16 var_a0 = g_CurrentEntity->posX.Data.high > player->posX.Data.high;

    if (g_CurrentEntity->posY.Data.high > player->posY.Data.high) {
        var_a0 |= 2;
    }
    return var_a0;
}

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BC888);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BC8B8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BC8E4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BCB5C);

Entity* AllocEntity(Entity* start, Entity* end) {
    Entity* current = start;
    while (current < end) {
        if (current->objectId == 0) {
            DestroyEntity(current);
            return current;
        }

        current++;
    }
    return NULL;
}

s32 func_801BCDA4(u8 arg0, s16 arg1) { return D_80181A50[arg0] * arg1; }

s16 func_801BCDD0(u8 arg0) { return D_80181A50[arg0]; }

void func_801BCDEC(s32 arg0, s16 arg1) {
    g_CurrentEntity->accelerationX = func_801BCDA4(arg0, arg1);
    g_CurrentEntity->accelerationY = func_801BCDA4(arg0 - 0x40, arg1);
}

u8 func_801BCE58(s16 x, s16 y) { return ((ratan2(y, x) >> 4) + 0x40); }

u8 func_801BCE90(Entity* a, Entity* b) {
    s32 diffX = (u16)b->posX.Data.high - (u16)a->posX.Data.high;
    s32 diffY = (u16)b->posY.Data.high - (u16)a->posY.Data.high;
    return func_801BCE58(diffX, diffY);
}

u8 func_801BCED8(s32 x, s32 y) {
    s32 diffX = x - (u16)g_CurrentEntity->posX.Data.high;
    s32 diffY = y - (u16)g_CurrentEntity->posY.Data.high;
    return func_801BCE58(diffX, diffY);
}

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BCF20);

void func_801BCF78(u16 slope, s16 speed) {
    Entity* entity;
    s32 moveX;
    s32 moveY;

    moveX = rcos(slope) * speed;
    entity = g_CurrentEntity;
    if (moveX < 0) {
        moveX += 15;
    }
    entity->accelerationX = moveX >> 4;

    moveY = rsin(slope) * speed;
    entity = g_CurrentEntity;
    if (moveY < 0) {
        moveY += 15;
    }
    entity->accelerationY = moveY >> 4;
}

u16 func_801BD004(s16 x, s16 y) { return ratan2(y, x); }

u16 func_801BD034(Entity* a, Entity* b) {
    s32 diffX = b->posX.Data.high - a->posX.Data.high;
    s32 diffY = b->posY.Data.high - a->posY.Data.high;
    return ratan2(diffY, diffX);
}

u16 func_801BD06C(s32 x, s32 y) {
    s16 diffX = x - (u16)g_CurrentEntity->posX.Data.high;
    s16 diffY = y - (u16)g_CurrentEntity->posY.Data.high;
    return ratan2(diffY, diffX);
}

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BD0B4);

void func_801BD114(u8 step) {
    g_CurrentEntity->step = step;
    g_CurrentEntity->unk2E = 0;
    g_CurrentEntity->animationFrameIndex = 0;
    g_CurrentEntity->animationFrameDuration = 0;
}

void func_801BD134(u8 arg0) {
    g_CurrentEntity->unk2E = arg0;
    g_CurrentEntity->animationFrameIndex = 0;
    g_CurrentEntity->animationFrameDuration = 0;
}

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BD150);

void InitializeEntity(const u16 arg0[]) {
    u16 temp_v1;
    Unkstruct5* temp_v0;

    g_CurrentEntity->animationSet = *arg0++;
    g_CurrentEntity->animationFrame = *arg0++;
    g_CurrentEntity->unk5A = *arg0++;
    g_CurrentEntity->palette = *arg0++;
    temp_v1 = *arg0++;
    g_CurrentEntity->unk3A = temp_v1;
    temp_v0 = (Unkstruct5*)(temp_v1 * sizeof(Unkstruct5) + (u32)D_8003C808);
    g_CurrentEntity->unk3E = temp_v0->unk4;
    g_CurrentEntity->unk40 = temp_v0->unk6;
    g_CurrentEntity->unk42 = temp_v0->unk8;
    g_CurrentEntity->unk3C = temp_v0->unkC;
    g_CurrentEntity->hitboxWidth = temp_v0->hitboxWidth;
    g_CurrentEntity->hitboxHeight = temp_v0->hitboxHeight;
    g_CurrentEntity->unk34 = temp_v0->unk24;
    g_CurrentEntity->unk10 = 0;
    g_CurrentEntity->unk12 = 0;
    g_CurrentEntity->unk2E = 0;
    g_CurrentEntity->step++;
    if (g_CurrentEntity->zPriority == 0) {
        g_CurrentEntity->zPriority = g_zEntityCenter - 0xC;
    }
}

void EntityDummy(Entity* arg0) {
    if (arg0->step == 0) {
        arg0->step++;
    }
}

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BD308);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BD430);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BD588);

void ReplaceBreakableWithItemDrop(Entity* entity) {
    u16 temp_a0;
    u16 var_v1;

    PreventEntityFromRespawning(entity);
    if (!(D_8009796E & 2)) {
        DestroyEntity(entity);
        return;
    }

    temp_a0 = entity->subId & 0xFFF;
    var_v1 = temp_a0;
    entity->subId = var_v1;

    if (var_v1 < 0x80) {
        entity->objectId = ENTITY_ITEM_DROP;
        entity->pfnUpdate = EntityItemDrop;
        entity->animationFrameDuration = 0;
        entity->animationFrameIndex = 0;
    } else {
        var_v1 = temp_a0 - 0x80;
        entity->objectId = ENTITY_HEART_DROP;
        entity->pfnUpdate = EntityHeartDrop;
    }

    entity->subId = var_v1;
    temp_a0 = 0;
    entity->unk6D = 0x10;
    entity->step = temp_a0;
}

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BD984);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BDA08);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BDB64);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BDBE4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BDCC0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BDDD8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BDE7C);

void func_801BDECC(void) { DestroyEntity(g_CurrentEntity); }

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityItemDrop);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityExplosion);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BE864);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityHeartDrop);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801BEEF0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityRelicItem);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityInventoryItem);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityUnkId0D);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C02F4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C03E4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C04F4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C0624);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C070C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C07FC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C08F0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C0B20);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C0C1C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityIntenseExplosion);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C129C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C1368);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C1430);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C14E8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C16C0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C1CA0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C23A0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C2598);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C2690);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityStageNamePopup);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityAbsorbOrb);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityEnemyBlood);

extern ObjInit2 D_801820F0[];
void EntityRoomForeground(Entity* entity) {
    ObjInit2* objInit = &D_801820F0[entity->subId];
    if (entity->step == 0) {
        InitializeEntity(D_80180A90);
        entity->animationSet = objInit->animationSet;
        entity->zPriority = objInit->zPriority;
        entity->unk5A = objInit->unk4.data;
        entity->palette = objInit->palette;
        entity->unk19 = objInit->unk8;
        entity->blendMode = objInit->blendMode;
        if (objInit->unkC != 0) {
            entity->unk34 = objInit->unkC;
        }
        if (entity->subId >= 5) {
            entity->unk1E = 0x800;
            entity->unk19 |= 4;
        }
    }
    AnimateEntity(objInit->unk10, entity);
}

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C3E14);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C4144);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C424C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C4DCC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C56D8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C5BC4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C5F58);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C61B4);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C6458);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C6564);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C7650);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C7880);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C7954);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C7D80);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C7E18);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C8010);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityMerman2);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityMerman);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C8DF0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C8F54);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C8FEC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C90E8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityBoneScimitar);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C9874);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityBat);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", EntityZombie);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C9E28);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801C9F98);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CA498);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CA654);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CAE0C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CB018);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CBF18);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CC2E0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CD540);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CD620);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CD658);

void func_801CD734() {
    while (PadRead(0))
        func_801CD658();
    while (!PadRead(0))
        func_801CD658();
}

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CD78C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CD83C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CD91C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CDA14);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CDA6C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CDAC8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CDC80);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CDD00);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CDD80);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CDE10);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CDE88);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CDF1C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CDFD8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CE04C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CE120);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CE1E8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CE228);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CE258);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CE2CC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CE3FC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CE4CC);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CE69C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CF254);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CF5B8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CF778);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CF7A0);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801CF94C);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801D0730);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801D0A00);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801D0B40);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801D0B78);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801D0D40);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801D1BB8);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801D1F38);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801D2320);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801D2470);

INCLUDE_ASM("asm/st/np3/nonmatchings/3246C", func_801D24A0);

POLY_GT4* func_801D251C(POLY_GT4* startPoly, s32 count) {
    POLY_GT4* poly;
    s8 unk;
    s32 i;

    if (startPoly->p3) {
        startPoly->p3 = 0;
    } else {
        startPoly->p3 = 1;
    }

    poly = startPoly;
    for (i = 0; i < count; i++) {
        if (poly->p3) {
            poly->pad3 &= ~8;
            unk = 0;
        } else {
            poly->pad3 |= 8;
            unk = 1;
        }

        poly = (POLY_GT4*)poly->tag;
        if (poly == 0)
            return 0;
        poly->p3 = unk;
    }

    return poly;
}

void func_801D25A4(POLY_GT4* arg0) {
    arg0->p1 = 0;
    arg0->p2 = 0;
    arg0->p3 = 0;
    ((POLY_GT4*)arg0->tag)->x1 = 0;
    ((POLY_GT4*)arg0->tag)->y1 = 0;
    ((POLY_GT4*)arg0->tag)->y0 = 0;
    ((POLY_GT4*)arg0->tag)->x0 = 0;
    ((POLY_GT4*)arg0->tag)->clut = 0;
    *(u16*)&((POLY_GT4*)arg0->tag)->u0 = 0;
    *(u16*)&((POLY_GT4*)arg0->tag)->b1 = 0;
    *(u16*)&((POLY_GT4*)arg0->tag)->r1 = 0;
    *(u16*)&((POLY_GT4*)arg0->tag)->u1 = 0;
    ((POLY_GT4*)arg0->tag)->tpage = 0;
    *(u16*)&((POLY_GT4*)arg0->tag)->r2 = 0;
    *(u16*)&((POLY_GT4*)arg0->tag)->b2 = 0;
    ((POLY_GT4*)arg0->tag)->u2 = 0;
    ((POLY_GT4*)arg0->tag)->v2 = 0;
    ((POLY_GT4*)arg0->tag)->r3 = 0;
    ((POLY_GT4*)arg0->tag)->b3 = 0;
    ((POLY_GT4*)arg0->tag)->x2 = 0;
    ((POLY_GT4*)arg0->tag)->y2 = 0;
}

void func_801D2684(POLY_GT4* arg0) {
    func_801D25A4(arg0);
    arg0->p3 = 8;
    ((POLY_GT4*)arg0->tag)->p3 = 1;
    ((POLY_GT4*)arg0->tag)->code = 2;
    ((POLY_GT4*)arg0->tag)->pad3 = 0xA;
}

void func_801D26D8(POLY_GT4* arg0) {
    arg0->p3 = 0;
    arg0->pad3 = 8;
    ((POLY_GT4*)arg0->tag)->p3 = 0;
    ((POLY_GT4*)arg0->tag)->code = 4;
    ((POLY_GT4*)arg0->tag)->pad3 = 8;
}

s32 func_801D2704(s32 arg0, u8 arg1) {
    s32 var_v0;
    s32 ret = 0;
    u8* var_a0 = arg0 + 4;
    u8* var_v1;
    s32 i;

    for (i = 0; i < 4; i++) {
        var_v1 = var_a0;
        do {
            var_v0 = *var_v1 - arg1;

            if (var_v0 < 0) {
                var_v0 = 0;
            } else {
                ret |= 1;
            }

            *var_v1 = var_v0;
            var_v1++;
        } while (((s32)var_v1 < ((s32)var_a0 + 3)));

        var_a0 += 0xC;
    }

    return ret;
}
