#include "overlay045/ov45_022566EC.h"

#include <nitro.h>
#include <string.h>

#include "applications/poketch/poketch_animation.h"
#include "applications/poketch/poketch_graphics.h"
#include "applications/poketch/poketch_system.h"
#include "applications/poketch/poketch_task.h"
#include "overlay045/struct_ov45_022566EC_1.h"
#include "overlay045/struct_ov45_022566EC_decl.h"

#include "bg_window.h"
#include "graphics.h"
#include "heap.h"
#include "sound_playback.h"
#include "sys_task_manager.h"

struct UnkStruct_ov45_022566EC_t {
    const UnkStruct_ov45_022566EC_1 *unk_00;
    BgConfig *unk_04;
    u32 unk_08[10];
    PoketchAnimation_AnimationManager *unk_30;
    PoketchAnimation_AnimatedSpriteData *unk_34[13];
    PoketchAnimation_SpriteData unk_68;
    PoketchAnimation_SpriteData unk_7C;
    BOOL unk_90;
    u32 unk_94;
    u32 unk_98;
};

static void ov45_0225673C(UnkStruct_ov45_022566EC *param0, const UnkStruct_ov45_022566EC_1 *param1);
static void ov45_02256864(UnkStruct_ov45_022566EC *param0);
static void ov45_02256894(UnkStruct_ov45_022566EC *param0, u32 param1, u32 param2);
static void ov45_02256954(PoketchTaskManager *param0);
static void ov45_02256968(SysTask *param0, void *param1);
static void ov45_022569F8(SysTask *param0, void *param1);
static void ov45_02256A40(SysTask *param0, void *param1);
static void ov45_02256ABC(SysTask *param0, void *param1);
static void ov45_02256B38(SysTask *param0, void *param1);
static void ov45_02256B78(SysTask *param0, void *param1);

BOOL ov45_022566EC(UnkStruct_ov45_022566EC **param0, const UnkStruct_ov45_022566EC_1 *param1, BgConfig *param2)
{
    UnkStruct_ov45_022566EC *v0 = (UnkStruct_ov45_022566EC *)Heap_AllocFromHeap(HEAP_ID_POKETCH_APP, sizeof(UnkStruct_ov45_022566EC));

    if (v0 != NULL) {
        PoketchTask_InitActiveTaskList(v0->unk_08, 8);
        v0->unk_00 = param1;
        v0->unk_04 = PoketchGraphics_GetBgConfig();
        v0->unk_30 = PoketchGraphics_GetAnimationManager();
        ov45_0225673C(v0, param1);
        *param0 = v0;
        return 1;
    }

    return 0;
}

void ov45_02256728(UnkStruct_ov45_022566EC *param0)
{
    if (param0 != NULL) {
        ov45_02256864(param0);
        Heap_Free(param0);
    }
}

static void ov45_0225673C(UnkStruct_ov45_022566EC *param0, const UnkStruct_ov45_022566EC_1 *param1)
{
    static const PoketchAnimation_AnimationData v0[] = {
        {
            { (192 << FX32_SHIFT), (104 << FX32_SHIFT) },
            3,
            0,
            2,
            0,
            0,
        },
        {
            { (48 << FX32_SHIFT), (48 << FX32_SHIFT) },
            0,
            0,
            2,
            0,
            0,
        },
        {
            { (144 << FX32_SHIFT), (48 << FX32_SHIFT) },
            0,
            1,
            2,
            0,
            0,
        },
        {
            { (56 << FX32_SHIFT), (80 << FX32_SHIFT) },
            4,
            0,
            2,
            0,
            0,
        },
        {
            { (136 << FX32_SHIFT), (80 << FX32_SHIFT) },
            4,
            1,
            2,
            0,
            0,
        },
        {
            { (72 << FX32_SHIFT), (120 << FX32_SHIFT) },
            6,
            0,
            2,
            0,
            0,
        },
        {
            { (72 << FX32_SHIFT), (164 << FX32_SHIFT) },
            6,
            2,
            2,
            0,
            0,
        },
        {
            { (120 << FX32_SHIFT), (120 << FX32_SHIFT) },
            6,
            0,
            2,
            0,
            0,
        },
        {
            { (120 << FX32_SHIFT), (164 << FX32_SHIFT) },
            6,
            2,
            2,
            0,
            0,
        },
        {
            { (64 << FX32_SHIFT), (144 << FX32_SHIFT) },
            0,
            0,
            2,
            0,
            0,
        },
        {
            { (80 << FX32_SHIFT), (144 << FX32_SHIFT) },
            0,
            0,
            2,
            0,
            0,
        },
        {
            { (112 << FX32_SHIFT), (144 << FX32_SHIFT) },
            0,
            0,
            2,
            0,
            0,
        },
        {
            { (128 << FX32_SHIFT), (144 << FX32_SHIFT) },
            0,
            0,
            2,
            0,
            0,
        },
    };
    int v1;

    Graphics_LoadObjectTiles(12, 2, 1, 0, 0, 1, HEAP_ID_POKETCH_APP);
    Graphics_LoadObjectTiles(12, 79, 1, 80 * 0x20, 0, 1, HEAP_ID_POKETCH_APP);

    PoketchAnimation_LoadSpriteFromNARC(&param0->unk_68, 12, 77, 78, 8);
    PoketchAnimation_LoadSpriteFromNARC(&param0->unk_7C, 12, 3, 4, 8);

    for (v1 = 0; v1 < 13; v1++) {
        if ((v1 >= 9) && (v1 <= 12)) {
            param0->unk_34[v1] = PoketchAnimation_SetupNewAnimatedSprite(param0->unk_30, &v0[v1], &param0->unk_7C);
        } else {
            param0->unk_34[v1] = PoketchAnimation_SetupNewAnimatedSprite(param0->unk_30, &v0[v1], &param0->unk_68);
            PoketchAnimation_SetSpriteCharNo(param0->unk_34[v1], 80);
        }
    }

    if (param1->unk_00) {
        PoketchAnimation_UpdateAnimationIdx(param0->unk_34[0], 3);
        PoketchAnimation_UpdateAnimationIdx(param0->unk_34[3], 5);
        PoketchAnimation_UpdateAnimationIdx(param0->unk_34[4], 5);
        PoketchAnimation_HideSprite(param0->unk_34[5], 1);
        PoketchAnimation_HideSprite(param0->unk_34[6], 1);
        PoketchAnimation_HideSprite(param0->unk_34[7], 1);
        PoketchAnimation_HideSprite(param0->unk_34[8], 1);
        ov45_02256894(param0, param1->unk_01, param1->unk_02);
    } else {
        PoketchAnimation_UpdateAnimationIdx(param0->unk_34[0], 2);
        PoketchAnimation_UpdateAnimationIdx(param0->unk_34[3], 5);
        PoketchAnimation_UpdateAnimationIdx(param0->unk_34[4], 4);
        ov45_02256894(param0, param1->unk_03, param1->unk_04);
    }
}

static void ov45_02256864(UnkStruct_ov45_022566EC *param0)
{
    int v0;

    for (v0 = 0; v0 < 13; v0++) {
        if (param0->unk_34[v0]) {
            PoketchAnimation_RemoveAnimatedSprite(param0->unk_30, param0->unk_34[v0]);
        }
    }

    PoketchAnimation_FreeSpriteData(&param0->unk_68);
    PoketchAnimation_FreeSpriteData(&param0->unk_7C);
}

static void ov45_02256894(UnkStruct_ov45_022566EC *param0, u32 param1, u32 param2)
{
    CP_SetDiv32_32(param1, 10);

    PoketchAnimation_UpdateAnimationIdx(param0->unk_34[9], CP_GetDivResult32());
    PoketchAnimation_UpdateAnimationIdx(param0->unk_34[10], CP_GetDivRemainder32());

    CP_SetDiv32_32(param2, 10);

    PoketchAnimation_UpdateAnimationIdx(param0->unk_34[11], CP_GetDivResult32());
    PoketchAnimation_UpdateAnimationIdx(param0->unk_34[12], CP_GetDivRemainder32());
}

static const PoketchTask Unk_ov45_02256CE0[] = {
    { 0x0, ov45_02256968, 0x0 },
    { 0x1, ov45_022569F8, 0x0 },
    { 0x2, ov45_02256A40, 0x0 },
    { 0x3, ov45_02256ABC, 0x0 },
    { 0x4, ov45_02256B38, 0x0 },
    { 0x5, ov45_02256B78, 0x0 },
    { 0x0, NULL, 0x0 }
};

void ov45_02256918(UnkStruct_ov45_022566EC *param0, u32 param1)
{
    PoketchTask_Start(Unk_ov45_02256CE0, param1, param0, param0->unk_00, param0->unk_08, 2, 8);
}

BOOL ov45_0225693C(UnkStruct_ov45_022566EC *param0, u32 param1)
{
    return PoketchTask_TaskIsNotActive(param0->unk_08, param1);
}

BOOL ov45_02256948(UnkStruct_ov45_022566EC *param0)
{
    return PoketchTask_NoActiveTasks(param0->unk_08);
}

static void ov45_02256954(PoketchTaskManager *param0)
{
    UnkStruct_ov45_022566EC *v0 = PoketchTask_GetTaskData(param0);
    PoketchTask_EndTask(v0->unk_08, param0);
}

static void ov45_02256968(SysTask *param0, void *param1)
{
    static const BgTemplate v0 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x800,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_256x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0x7000,
        .charBase = GX_BG_CHARBASE_0x00000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 2,
        .areaOver = 0,
        .mosaic = FALSE,
    };
    GXSDispCnt v1;
    UnkStruct_ov45_022566EC *v2;
    void *v3;
    NNSG2dPaletteData *v4;

    v2 = PoketchTask_GetTaskData(param1);

    Bg_InitFromTemplate(v2->unk_04, BG_LAYER_SUB_2, &v0, 0);
    Graphics_LoadTilesToBgLayer(NARC_INDEX_GRAPHIC__POKETCH, 76, v2->unk_04, BG_LAYER_SUB_2, 0, 0, 1, HEAP_ID_POKETCH_APP);
    Graphics_LoadTilemapToBgLayer(NARC_INDEX_GRAPHIC__POKETCH, 75, v2->unk_04, BG_LAYER_SUB_2, 0, 0, 1, HEAP_ID_POKETCH_APP);

    PoketchGraphics_LoadActivePalette(0, 0);
    Bg_CopyTilemapBufferToVRAM(v2->unk_04, 6);

    v1 = GXS_GetDispCnt();
    GXS_SetVisiblePlane(v1.visiblePlane | GX_PLANEMASK_BG2);

    ov45_02256954(param1);
}

static void ov45_022569F8(SysTask *param0, void *param1)
{
    UnkStruct_ov45_022566EC *v0 = PoketchTask_GetTaskData(param1);

    switch (PoketchTask_GetState(param1)) {
    case 0:
        ov45_02256C90(v0);
        PoketchTask_IncrementState(param1);
        break;
    case 1:
        if (ov45_0225693C(v0, 5)) {
            Bg_FreeTilemapBuffer(v0->unk_04, BG_LAYER_SUB_2);
            ov45_02256954(param1);
        }
        break;
    }
}

static void ov45_02256A40(SysTask *param0, void *param1)
{
    UnkStruct_ov45_022566EC *v0 = PoketchTask_GetTaskData(param1);
    const UnkStruct_ov45_022566EC_1 *v1 = PoketchTask_GetConstTaskData(param1);

    PoketchSystem_PlaySoundEffect(1635);

    PoketchAnimation_UpdateAnimationIdx(v0->unk_34[0], 3);
    PoketchAnimation_UpdateAnimationIdx(v0->unk_34[3], 5);
    PoketchAnimation_UpdateAnimationIdx(v0->unk_34[4], 5);
    PoketchAnimation_UpdateAnimationIdx(v0->unk_34[1], 0);
    PoketchAnimation_UpdateAnimationIdx(v0->unk_34[2], 0);
    PoketchAnimation_HideSprite(v0->unk_34[5], 1);
    PoketchAnimation_HideSprite(v0->unk_34[6], 1);
    PoketchAnimation_HideSprite(v0->unk_34[7], 1);
    PoketchAnimation_HideSprite(v0->unk_34[8], 1);
    ov45_02256894(v0, v1->unk_01, v1->unk_02);

    ov45_02256954(param1);
}

static void ov45_02256ABC(SysTask *param0, void *param1)
{
    UnkStruct_ov45_022566EC *v0 = PoketchTask_GetTaskData(param1);
    const UnkStruct_ov45_022566EC_1 *v1 = PoketchTask_GetConstTaskData(param1);

    PoketchSystem_PlaySoundEffect(1635);

    PoketchAnimation_UpdateAnimationIdx(v0->unk_34[0], 2);
    PoketchAnimation_UpdateAnimationIdx(v0->unk_34[3], 5);
    PoketchAnimation_UpdateAnimationIdx(v0->unk_34[4], 4);
    PoketchAnimation_UpdateAnimationIdx(v0->unk_34[1], 0);
    PoketchAnimation_UpdateAnimationIdx(v0->unk_34[2], 0);
    PoketchAnimation_HideSprite(v0->unk_34[5], 0);
    PoketchAnimation_HideSprite(v0->unk_34[6], 0);
    PoketchAnimation_HideSprite(v0->unk_34[7], 0);
    PoketchAnimation_HideSprite(v0->unk_34[8], 0);
    ov45_02256894(v0, v1->unk_03, v1->unk_04);

    ov45_02256954(param1);
}

static void ov45_02256B38(SysTask *param0, void *param1)
{
    UnkStruct_ov45_022566EC *v0 = PoketchTask_GetTaskData(param1);
    const UnkStruct_ov45_022566EC_1 *v1 = PoketchTask_GetConstTaskData(param1);

    if (v1->unk_00) {
        ov45_02256894(v0, v1->unk_01, v1->unk_02);
    } else {
        ov45_02256894(v0, v1->unk_03, v1->unk_04);
    }

    ov45_02256954(param1);
}

static void ov45_02256B78(SysTask *param0, void *param1)
{
    UnkStruct_ov45_022566EC *v0 = PoketchTask_GetTaskData(param1);
    const UnkStruct_ov45_022566EC_1 *v1 = PoketchTask_GetConstTaskData(param1);

    switch (PoketchTask_GetState(param1)) {
    case 0:
        v0->unk_90 = 0;
        PoketchAnimation_UpdateAnimationIdx(v0->unk_34[3], 4);
        PoketchAnimation_UpdateAnimationIdx(v0->unk_34[4], 4);
        PoketchAnimation_UpdateAnimationIdx(v0->unk_34[1], 1);
        PoketchAnimation_UpdateAnimationIdx(v0->unk_34[2], 1);
        PoketchSystem_PlaySoundEffect(1635);
        PoketchSystem_PlayCry(294, 0);
        v0->unk_94 = 0;
        v0->unk_98 = 0;
        PoketchTask_IncrementState(param1);
        break;
    case 1:
        if (v0->unk_90) {
            PoketchAnimation_HideSprite(v0->unk_34[9], 0);
            PoketchAnimation_HideSprite(v0->unk_34[10], 0);
            PoketchAnimation_HideSprite(v0->unk_34[11], 0);
            PoketchAnimation_HideSprite(v0->unk_34[12], 0);
            ov45_02256954(param1);
            return;
        }

        if (Sound_IsPokemonCryPlaying() == 0) {
            PoketchSystem_PlayCry(294, 0);
        }

        if (++(v0->unk_94) >= 15) {
            v0->unk_94 = 0;
            v0->unk_98 ^= 1;

            PoketchAnimation_HideSprite(v0->unk_34[9], v0->unk_98);
            PoketchAnimation_HideSprite(v0->unk_34[10], v0->unk_98);
            PoketchAnimation_HideSprite(v0->unk_34[11], v0->unk_98);
            PoketchAnimation_HideSprite(v0->unk_34[12], v0->unk_98);
        }
        break;
    }
}

void ov45_02256C90(UnkStruct_ov45_022566EC *param0)
{
    param0->unk_90 = 1;
}
