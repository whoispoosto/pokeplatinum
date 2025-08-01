#include "overlay023/ov23_0224F294.h"

#include <nitro.h>
#include <string.h>

#include "constants/heap.h"

#include "struct_defs/underground.h"

#include "field/field_system.h"
#include "overlay005/ov5_021D2F14.h"
#include "overlay023/funcptr_ov23_02248D20.h"
#include "overlay023/funcptr_ov23_0224F758.h"
#include "overlay023/funcptr_ov23_0224F914.h"
#include "overlay023/funcptr_ov23_0224FD84.h"
#include "overlay023/funcptr_ov23_0224FE38.h"
#include "overlay023/funcptr_ov23_0225021C.h"
#include "overlay023/ov23_0223E140.h"
#include "overlay023/ov23_022416A8.h"
#include "overlay023/ov23_02241F74.h"
#include "overlay023/ov23_0224340C.h"
#include "overlay023/ov23_02248C08.h"
#include "overlay023/ov23_0224A1D0.h"
#include "overlay023/ov23_0224B05C.h"
#include "overlay023/ov23_0225128C.h"
#include "overlay023/ov23_022521F0.h"
#include "overlay023/ov23_02253598.h"
#include "overlay023/struct_ov23_02250CD4.h"
#include "overlay023/underground_text_printer.h"

#include "bag.h"
#include "bg_window.h"
#include "brightness_controller.h"
#include "comm_player_manager.h"
#include "communication_system.h"
#include "field_map_change.h"
#include "field_system.h"
#include "font.h"
#include "gx_layers.h"
#include "heap.h"
#include "list_menu.h"
#include "menu.h"
#include "message.h"
#include "narc.h"
#include "player_avatar.h"
#include "render_window.h"
#include "save_player.h"
#include "sound_playback.h"
#include "sprite.h"
#include "sprite_system.h"
#include "strbuf.h"
#include "string_list.h"
#include "string_template.h"
#include "sys_task.h"
#include "sys_task_manager.h"
#include "system.h"
#include "trainer_info.h"
#include "unk_0202854C.h"
#include "unk_0206A780.h"

typedef void (*UnkFuncPtr_ov23_0224FA58)(UnkStruct_ov23_02250CD4 *);

typedef struct {
    Underground *underground;
    u8 unk_04;
    u8 unk_05;
} UnkStruct_ov23_022577B8;

typedef struct {
    u32 unk_00;
    u32 unk_04;
} UnkStruct_ov23_02257644;

static void ov23_0224F460(UnkStruct_ov23_02250CD4 *param0);
static void ov23_0224F498(UnkStruct_ov23_02250CD4 *param0);
static void ov23_0224F4D0(Sprite *param0, u32 param1);
static void ov23_0224F500(Sprite *param0, u16 param1, u16 param2);
static void ov23_0224F52C(UnkStruct_ov23_02250CD4 *param0, u16 param1, u16 param2);
static void ov23_0224F560(Sprite *param0);
static void ov23_0224F914(SysTask *param0, void *param1);
static BOOL ov23_0224FA58(SysTask *param0, void *param1);
static void ov23_0224FE38(UnkStruct_ov23_02250CD4 *param0, UnkFuncPtr_ov23_02248D20 param1);
static BOOL ov23_0224FF58(SysTask *param0, void *param1);
static void ov23_0225021C(UnkStruct_ov23_02250CD4 *param0, UnkFuncPtr_ov23_02248D20 param1);
static BOOL ov23_02250378(SysTask *param0, void *param1);
static BOOL ov23_0225044C(SysTask *param0, void *param1);
static void ov23_022501BC(UnkStruct_ov23_02250CD4 *param0);
static void ov23_022505EC(UnkStruct_ov23_02250CD4 *param0, UnkFuncPtr_ov23_02248D20 param1);
static BOOL ov23_02250704(SysTask *param0, void *param1);
static BOOL ov23_022507D8(SysTask *param0, void *param1);
static void ov23_02250930(UnkStruct_ov23_02250CD4 *param0);
static void ov23_0225093C(UnkStruct_ov23_02250CD4 *param0);
static void ov23_02250A14(UnkStruct_ov23_02250CD4 *param0);
static BOOL ov23_02250048(SysTask *param0, void *param1);
static BOOL ov23_02250F8C(SysTask *param0, void *param1);
static void ov23_02250B9C(SysTask *param0, void *param1);
static void ov23_02250D90(UnkStruct_ov23_02250CD4 *param0, UnkFuncPtr_ov23_02248D20 param1);
static BOOL ov23_02250EAC(SysTask *param0, void *param1);
static BOOL ov23_022510F0(SysTask *param0, void *param1);
static void ov23_02250998(SysTask *param0, void *param1);
static void ov23_022509D4(SysTask *param0, void *param1);
static void ov23_02250B34(SysTask *param0, UnkStruct_ov23_02250CD4 *param1, BOOL param2);

static UnkStruct_ov23_022577B8 *Unk_ov23_022577B8 = NULL;

static const WindowTemplate Unk_ov23_022568D8 = {
    0x3,
    0x19,
    0xD,
    0x6,
    0x4,
    0xD,
    0x21F
};

static const struct {
    u32 unk_00;
    u32 unk_04;
} Unk_ov23_02256924[] = {
    { 0x79, (u32)ov23_0224FDE0 },
    { 0x7A, (u32)ov23_022501BC },
    { 0x7B, (u32)ov23_02250CD4 },
    { 0x7C, (u32)ov23_02250598 },
    { 0x7D, (u32)ov23_02250A14 },
    { 0x7E, (u32)ov23_0225093C },
    { 0x7F, (u32)ov23_02250930 }
};

static const ListMenuTemplate Unk_ov23_02256904 = {
    NULL,
    NULL,
    NULL,
    NULL,
    0x14,
    0x14,
    0x0,
    0x8,
    0x0,
    0x0,
    0x1,
    0xF,
    0x2,
    0x0,
    0x10,
    0x1,
    0x0,
    0x0,
    NULL
};

static const SpriteTemplate Unk_ov23_0225695C[] = {
    {
        0xCC,
        0x14,
        0x0,
        0x0,
        0x1,
        0x1,
        NNS_G2D_VRAM_TYPE_2DMAIN,
        { 0x38C0, 0x38C0, 0x38C0, 0x38C0, 0x0, 0x0 },
        0x0,
        0x0,
    },
    {
        0xAE,
        0x14,
        0x0,
        0x0,
        0x0,
        0x0,
        NNS_G2D_VRAM_TYPE_2DMAIN,
        { 0x38C1, 0x38C0, 0x38C1, 0x38C1, 0x0, 0x0 },
        0x0,
        0x0,
    }
};

static void ov23_0224F294(UnkStruct_ov23_02250CD4 *param0, u8 *param1, u32 param2)
{
    SpriteResourceCapacities v0 = {
        8, 1, 2, 2, 0, 0
    };
    u32 v1;
    NARC *v2 = NARC_ctor(NARC_INDEX_GRAPHIC__MENU_GRA, HEAP_ID_FIELDMAP);

    ov5_021D3190(&param0->unk_74, &v0, (7 + 1), HEAP_ID_FIELDMAP);
    ov5_021D32E8(&param0->unk_74, v2, 9, 0, 2, NNS_G2D_VRAM_TYPE_2DMAIN, 14528);
    ov5_021D3374(&param0->unk_74, v2, 1, 0, 14528);
    ov5_021D339C(&param0->unk_74, v2, 0, 0, 14528);
    ov5_021D3414(&param0->unk_74, v2, 2, 0, NNS_G2D_VRAM_TYPE_2DMAIN, 14528);

    param0->unk_23C[0] = ov5_021D3584(&param0->unk_74, &Unk_ov23_0225695C[0]);

    ov23_0224F4D0(param0->unk_23C[0]->sprite, param0->unk_29C);

    ov5_021D3374(&param0->unk_74, v2, 8, 0, 14529);
    ov5_021D339C(&param0->unk_74, v2, 7, 0, 14529);
    ov5_021D3414(&param0->unk_74, v2, 10, 0, NNS_G2D_VRAM_TYPE_2DMAIN, 14529);

    NARC_dtor(v2);

    for (v1 = 0; v1 < param2; v1++) {
        SpriteTemplate v3;

        v3 = Unk_ov23_0225695C[1];
        v3.y += 24 * v1;
        v3.animIdx = param1[v1] * 3;

        param0->unk_23C[1 + v1] = ov5_021D3584(&param0->unk_74, &v3);

        {
            VecFx32 v4 = { FX32_ONE, FX32_ONE, FX32_ONE };
            Sprite_SetAffineScaleEx(param0->unk_23C[1 + v1]->sprite, &v4, 1);
        }
    }

    ov23_0224F500(param0->unk_23C[1 + param0->unk_29C]->sprite, 2, 1);
    param0->unk_25C = param2 + 1;
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_OBJ, 1);
}

static void ov23_0224F460(UnkStruct_ov23_02250CD4 *param0)
{
    u16 v0;

    for (v0 = 0; v0 < param0->unk_25C; v0++) {
        Sprite_DeleteAndFreeResources(param0->unk_23C[v0]);
    }

    ov5_021D375C(&param0->unk_74);
}

static void ov23_0224F498(UnkStruct_ov23_02250CD4 *param0)
{
    u16 v0;

    for (v0 = 0; v0 < param0->unk_25C; v0++) {
        Sprite_UpdateAnim(param0->unk_23C[v0]->sprite, FX32_ONE);
    }
}

static void ov23_0224F4D0(Sprite *param0, u32 param1)
{
    VecFx32 v0;

    v0 = *(Sprite_GetPosition(param0));
    v0.y = (20 + 24 * param1) * FX32_ONE;

    Sprite_SetPosition(param0, &v0);
}

static void ov23_0224F500(Sprite *param0, u16 param1, u16 param2)
{
    u32 v0 = Sprite_GetActiveAnim(param0);

    Sprite_SetAnim(param0, (v0 / 3) * 3 + param1);
    Sprite_SetExplicitPaletteWithOffset(param0, param2);
}

static void ov23_0224F52C(UnkStruct_ov23_02250CD4 *param0, u16 param1, u16 param2)
{
    ov23_0224F500(param0->unk_23C[1 + param1]->sprite, 0, 0);
    ov23_0224F500(param0->unk_23C[1 + param2]->sprite, 1, 1);
}

static void ov23_0224F560(Sprite *param0)
{
    if ((Sprite_GetActiveAnim(param0) % 3) != 1) {
        return;
    }

    if (Sprite_IsAnimated(param0) == 0) {
        ov23_0224F500(param0, 2, 1);
    }
}

void ov23_0224F588(Underground *underground)
{
    Unk_ov23_022577B8 = Heap_AllocFromHeap(HEAP_ID_COMMUNICATION, sizeof(UnkStruct_ov23_022577B8));
    MI_CpuClear8(Unk_ov23_022577B8, sizeof(UnkStruct_ov23_022577B8));
    Unk_ov23_022577B8->unk_04 = 0;
    Unk_ov23_022577B8->unk_05 = 0;
    Unk_ov23_022577B8->underground = underground;
}

void ov23_0224F5B8(void)
{
    Heap_Free(Unk_ov23_022577B8);
}

static int ov23_0224F5C8(void *param0)
{
    UnkStruct_ov23_02250CD4 *v0 = param0;
    Underground *v1 = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return sub_02028E28(v1);
}

static int ov23_0224F5DC(void *param0)
{
    UnkStruct_ov23_02250CD4 *v0 = param0;
    Underground *v1 = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return sub_020289A0(v1);
}

int ov23_0224F5F0(int param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    Underground *v1 = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return sub_020289B8(v1, param0);
}

static int ov23_0224F608(void *param0)
{
    UnkStruct_ov23_02250CD4 *v0 = param0;
    Underground *v1 = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return sub_02028B70(v1);
}

int ov23_0224F61C(int param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    Underground *v1 = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return sub_02028B88(v1, param0);
}

void ov23_0224F634(int param0)
{
    GF_ASSERT(Unk_ov23_022577B8->unk_05 == param0);
    sub_02028B94(Unk_ov23_022577B8->underground, Unk_ov23_022577B8->unk_04);
}

static int ov23_0224F658(void *param0)
{
    UnkStruct_ov23_02250CD4 *v0 = param0;
    Underground *underground = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return Underground_GetSphereCount(underground);
}

int ov23_0224F66C(int param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    Underground *v1 = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return sub_02028E44(v1, param0);
}

int ov23_0224F684(int param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    Underground *v1 = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return sub_02028C54(v1, param0);
}

int ov23_0224F69C(int param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    Underground *v1 = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return sub_02028C60(v1, param0);
}

static int ov23_0224F6B4(void *param0)
{
    UnkStruct_ov23_02250CD4 *v0 = param0;
    Underground *underground = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return Underground_GetTreasureCount(underground);
}

int ov23_0224F6C8(int param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    Underground *v1 = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    return sub_02028D74(v1, param0);
}

BOOL Underground_TryAddSphere2(int sphereID, int sphereSize)
{
    int sphereType = sphereID;

    GF_ASSERT(sphereID < MINING_TREASURE_OVAL_STONE);

    if (sphereID >= MINING_LARGE_PRISM_SPHERE) {
        sphereType -= (MINING_LARGE_PRISM_SPHERE - 1);
    }

    if (sphereSize > 99) {
        sphereSize = 99;
    }

    return Underground_TryAddSphere(Unk_ov23_022577B8->underground, sphereType, sphereSize);
}

BOOL Underground_TryAddTreasure2(int treasureID)
{
    GF_ASSERT(treasureID < MINING_ROCK_1);
    return Underground_TryAddTreasure(Unk_ov23_022577B8->underground, treasureID);
}

BOOL ov23_0224F730(int param0)
{
    return sub_02028E84(Unk_ov23_022577B8->underground, param0);
}

BOOL ov23_0224F744(int param0)
{
    return sub_02028BC8(Unk_ov23_022577B8->underground, param0);
}

void ov23_0224F758(UnkFuncPtr_ov23_0224F758 param0, FieldSystem *fieldSystem)
{
    UnkStruct_ov23_02250CD4 *v0;
    ListMenuTemplate v1;

    Sound_PlayEffect(SEQ_SE_DP_WIN_OPEN);
    ov23_022430D0(2);

    v0 = Heap_AllocFromHeap(HEAP_ID_FIELD, sizeof(UnkStruct_ov23_02250CD4));

    MI_CpuFill8(v0, 0, sizeof(UnkStruct_ov23_02250CD4));

    v0->fieldSystem = fieldSystem;
    v0->unk_260 = param0;
    v0->unk_2AA = 0;
    v0->unk_68 = Strbuf_Init((50 * 2), HEAP_ID_FIELD);
    v0->unk_6C = Strbuf_Init((50 * 2), HEAP_ID_FIELD);
    v0->unk_70 = StringTemplate_Default(HEAP_ID_FIELD);
    v0->unk_04 = SysTask_Start(ov23_0224F914, v0, 10000);

    ov23_022431EC(v0, v0->unk_04, ov23_02251270);
}

static u32 ov23_0224F7D4(u8 *param0)
{
    u32 v0 = 0;

    param0[v0] = 0;
    v0++;

    param0[v0] = 1;
    v0++;

    param0[v0] = 2;
    v0++;

    param0[v0] = 3;
    v0++;

    param0[v0] = 4;
    v0++;

    param0[v0] = 5;
    v0++;

    param0[v0] = 6;
    v0++;

    return v0;
}

static void ov23_0224F7F4(UnkStruct_ov23_02250CD4 *param0)
{
    MenuTemplate v0;
    const int v1 = 4;
    u8 v2[7];
    int v3 = ov23_0224F7D4(v2);
    param0->unk_40 = StringList_New(NELEMS(Unk_ov23_02256924), HEAP_ID_FIELD);

    Window_Add(param0->fieldSystem->bgConfig, &param0->unk_10, 3, 20, 1, 11, NELEMS(Unk_ov23_02256924) * 3, 13, (1024 - (18 + 12) - 9 - 11 * 22));
    Window_DrawStandardFrame(&param0->unk_10, 1, 1024 - (18 + 12) - 9, 11);

    {
        MessageLoader *v3;
        int v4;

        v3 = UndergroundTextPrinter_GetMessageLoader(CommManUnderground_GetCommonTextPrinter());

        for (v4 = 0; v4 < NELEMS(Unk_ov23_02256924); v4++) {
            if (v4 == v1) {
                const TrainerInfo *v5 = SaveData_GetTrainerInfo(FieldSystem_GetSaveData(param0->fieldSystem));
                Strbuf *v6 = TrainerInfo_NameNewStrbuf(v5, 4);

                StringList_AddFromStrbuf(param0->unk_40, v6, Unk_ov23_02256924[v4].unk_04);
                Strbuf_Free(v6);
            } else {
                StringList_AddFromMessageBank(param0->unk_40, v3, Unk_ov23_02256924[v4].unk_00, Unk_ov23_02256924[v4].unk_04);
            }
        }
    }

    param0->unk_29C = param0->fieldSystem->unk_90;

    v0.choices = param0->unk_40;
    v0.window = &param0->unk_10;
    v0.fontID = FONT_MESSAGE;
    v0.xSize = 1;
    v0.ySize = NELEMS(Unk_ov23_02256924);
    v0.lineSpacing = 8;
    v0.suppressCursor = TRUE;

    if (NELEMS(Unk_ov23_02256924) >= 4) {
        v0.loopAround = TRUE;
    } else {
        v0.loopAround = FALSE;
    }

    param0->unk_54 = Menu_New(&v0, 28, 4, param0->unk_29C, HEAP_ID_FIELDMAP, PAD_BUTTON_B | PAD_BUTTON_X);
    param0->unk_48 = NULL;

    Window_ScheduleCopyToVRAM(&param0->unk_10);
    ov23_0224F294(param0, v2, NELEMS(Unk_ov23_02256924));
    sub_020594FC();
}

static void ov23_0224F914(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u32 v1;

    switch (v0->unk_2AA) {
    case 0:
        ov23_0224F7F4(v0);
        v0->unk_2AA++;
        break;
    case 1:
        ov23_0224FA58(param0, param1);
        break;
    case 2:
        ov23_0224FB7C(v0);
        ov23_02243204();
        ov23_02250B34(param0, v0, 0);
        return;
    case 3:
        ov23_0224FB7C(v0);
        ov23_02243204();
        ov23_02250B34(param0, v0, 1);
        return;
    case 5:
        ov23_0224FF58(param0, param1);
        break;
    case 6:
        ov23_02250378(param0, param1);
        break;
    case 7:
        ov23_02250704(param0, param1);
        break;
    case 8:
        ov23_02250EAC(param0, param1);
        break;
    case 9:
        ov23_022510F0(param0, param1);
        break;
    case 10:
        break;
    case 11:
        ov23_02250998(param0, param1);
        break;
    case 12:
        ov23_022509D4(param0, param1);
        break;
    case 13:
        if (UndergroundTextPrinter_IsPrinterActive(CommManUnderground_GetCommonTextPrinter()) == FALSE) {
            if (gSystem.pressedKeys & PAD_BUTTON_A) {
                UndergroundTextPrinter_EraseMessageBoxWindow(CommManUnderground_GetCommonTextPrinter());
                ov23_02250B34(param0, v0, 0);
                ov23_02243204();
                return;
            }
        }
        break;
    case 14:
        if (UndergroundTextPrinter_IsPrinterActive(CommManUnderground_GetCommonTextPrinter()) == FALSE) {
            if (gSystem.pressedKeys & PAD_BUTTON_A) {
                UnkFuncPtr_ov23_0224F914 v2 = (UnkFuncPtr_ov23_0224F914)v0->unk_00;

                v2(v0);
                v0->unk_2AA = v0->unk_2A9;
            }
        }
        break;
    case 15:
        ov23_0224FB7C(v0);
        ov23_02250B34(param0, v0, 1);
        ov23_02243204();
        FieldTask_SetUndergroundMapChange(v0->fieldSystem);
        return;
    case 18:
        ov23_02250048(param0, param1);
        break;
    case 16:
        ov23_0225044C(param0, param1);
        break;
    case 17:
        ov23_022507D8(param0, param1);
        break;
    case 19:
        ov23_02250F8C(param0, param1);
        break;
    }
}

static BOOL ov23_0224FA58(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u16 v1 = Menu_GetCursorPos(v0->unk_54);
    v0->unk_2A0 = Menu_ProcessInputWithSound(v0->unk_54, 1504);
    v0->unk_29C = Menu_GetCursorPos(v0->unk_54);

    if (v1 != v0->unk_29C) {
        ov23_0224F4D0(v0->unk_23C[0]->sprite, v0->unk_29C);
        ov23_0224F52C(v0, v1, v0->unk_29C);
        v0->fieldSystem->unk_90 = v0->unk_29C;
    }

    ov23_0224F560(v0->unk_23C[1 + v0->unk_29C]->sprite);

    if (CommSys_CheckError()) {
        v0->unk_2A0 = 0xfffffffe;
    }

    switch (v0->unk_2A0) {
    case 0xffffffff:
        ov23_0224F498(v0);
        SpriteList_Update(v0->unk_74.unk_00);
        return 0;
    case 0xfffffffe:
        v0->unk_2AA = 2;
        break;
    default:
        if ((v0->unk_2A0 == (u32)ov23_0224FDE0) || (v0->unk_2A0 == (u32)ov23_022501BC) || (v0->unk_2A0 == (u32)ov23_02250CD4) || (v0->unk_2A0 == (u32)ov23_02250598)) {
            v0->unk_08 = sub_0206A780(HEAP_ID_FIELD);
            sub_0206A8A0(v0->unk_08, 200, 20, 122);
            sub_0206A8C4(v0->unk_08, 0, 0);
            sub_0206A8C4(v0->unk_08, 1, 0);
        }

        if (v0->unk_25C) {
            ov23_0224F460(v0);
            Menu_Free(v0->unk_54, NULL);
            v0->unk_25C = 0;
        }

        {
            UnkFuncPtr_ov23_0224FA58 v2 = (UnkFuncPtr_ov23_0224FA58)v0->unk_2A0;
            v2(v0);
        }
        break;
    }

    return 1;
}

void ov23_0224FB7C(UnkStruct_ov23_02250CD4 *param0)
{
    if (param0->unk_4C) {
        ov23_02248EF8(param0->unk_4C, NULL, NULL);
        param0->unk_4C = NULL;
    }

    if (param0->unk_48) {
        ListMenu_Free(param0->unk_48, NULL, NULL);
        param0->unk_48 = NULL;
    } else if (param0->unk_25C) {
        ov23_0224F460(param0);
        Menu_Free(param0->unk_54, NULL);
        param0->unk_25C = 0;
    }

    if (Window_IsInUse(&param0->unk_10)) {
        Window_EraseStandardFrame(&param0->unk_10, 1);
        Bg_ScheduleTilemapTransfer(param0->unk_10.bgConfig, param0->unk_10.bgLayer);
        Window_Remove(&param0->unk_10);
        StringList_Free(param0->unk_40);
        ov23_02252DF4(param0);
    }
}

static UnkStruct_ov23_02257644 Unk_ov23_02257644[] = {
    { 0x86, (u32)1 },
    { 0x84, (u32)2 },
    { 0x85, (u32)0xfffffffe }
};

static UnkStruct_ov23_02257644 Unk_ov23_02257634[] = {
    { 0x84, (u32)2 },
    { 0x85, (u32)0xfffffffe }
};

static UnkStruct_ov23_02257644 Unk_ov23_0225765C[] = {
    { 0x87, (u32)3 },
    { 0x84, (u32)2 },
    { 0x85, (u32)0xfffffffe }
};

static void ov23_0224FBFC(UnkStruct_ov23_02250CD4 *param0, int param1)
{
    ListMenuTemplate v0;
    int v1, v2;
    int v3 = 11;
    int v4 = 6;
    int v5 = (31 - 6);
    UnkStruct_ov23_02257644 *v6;

    switch (param1) {
    case 1:
        v1 = 3;
        v6 = Unk_ov23_02257644;
        break;
    case 2:
        v1 = 2;
        v3 = 11 + 2;
        v6 = Unk_ov23_02257634;
        break;
    case 3:
        v1 = 3;
        v4 = 6 + 5;
        v5 = (31 - 6) - 5;
        v6 = Unk_ov23_0225765C;
        break;
    }

    param0->unk_44 = StringList_New(v1, HEAP_ID_FIELD);

    Window_Add(param0->fieldSystem->bgConfig, &param0->unk_20, 3, v5, v3, v4, v1 * 2, 13, (1024 - (18 + 12) - 9 - 11 * 22));
    Window_DrawStandardFrame(&param0->unk_20, 1, 1024 - (18 + 12) - 9, 11);

    {
        MessageLoader *v7;
        int v8;

        v7 = UndergroundTextPrinter_GetMessageLoader(CommManUnderground_GetCommonTextPrinter());

        for (v8 = 0; v8 < v1; v8++) {
            StringList_AddFromMessageBank(param0->unk_44, v7, v6->unk_00, v6->unk_04);
            v6++;
        }
    }

    v0 = Unk_ov23_02256904;
    v0.count = v1;
    v0.maxDisplay = v1;
    v0.choices = param0->unk_44;
    v0.window = &param0->unk_20;
    v0.parent = param0;

    param0->unk_50 = ListMenu_New(&v0, 0, 0, HEAP_ID_FIELD);
}

static void ov23_0224FCF4(UnkStruct_ov23_02250CD4 *param0)
{
    if (param0->unk_50) {
        ListMenu_Free(param0->unk_50, NULL, NULL);
        Bg_ScheduleTilemapTransfer(param0->unk_20.bgConfig, param0->unk_20.bgLayer);
        StringList_Free(param0->unk_44);

        param0->unk_50 = NULL;
    }

    if (Window_IsInUse(&param0->unk_20)) {
        Window_EraseStandardFrame(&param0->unk_20, 1);
        Window_Remove(&param0->unk_20);
    }
}

static void ov23_0224FD3C(UnkStruct_ov23_02250CD4 *param0)
{
    ov23_0224FB7C(param0);

    if (param0->unk_08) {
        sub_0206A844(param0->unk_08);
        param0->unk_08 = NULL;
    }

    param0->unk_2AA = 0;
    UndergroundTextPrinter_EraseMessageBoxWindow(CommManUnderground_GetItemNameTextPrinter());
}

void ov23_0224FD68(int param0)
{
    if (Unk_ov23_022577B8->unk_05 == param0) {
        sub_02028E50(Unk_ov23_022577B8->underground, Unk_ov23_022577B8->unk_04);
    }
}

void ov23_0224FD84(ListMenu *param0, u32 param1, u8 param2)
{
    UnkStruct_ov23_02250CD4 *v0 = (UnkStruct_ov23_02250CD4 *)ListMenu_GetAttribute(param0, 19);
    UnkFuncPtr_ov23_0224FD84 v1 = v0->unk_268;
    int v2 = param1;
    int v3 = v1(v2, v0);

    if (param1 == 0xfffffffe) {
        v2 = 68;
    } else {
        v2 = 35 + v3 - 1;
    }

    UndergroundTextPrinter_PrintTextInstant(CommManUnderground_GetItemNameTextPrinter(), v2, FALSE, NULL);
}

void ov23_0224FDBC(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_264 = ov23_0224F5C8;
    param0->unk_268 = ov23_0224F66C;
    param0->unk_64 = NULL;

    ov23_0224FE38(param0, NULL);
}

void ov23_0224FDE0(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_290 = ov23_0224318C(8);
    param0->unk_294 = ov23_02243154(8);
    param0->unk_264 = ov23_0224F5C8;
    param0->unk_268 = ov23_0224F66C;
    param0->unk_60 = ov23_0224FD84;
    param0->unk_64 = NULL;
    param0->unk_2B0 = param0->unk_290;

    ov23_0224FE38(param0, sub_02028EA8);
}

static void ov23_0224FE38(UnkStruct_ov23_02250CD4 *param0, UnkFuncPtr_ov23_02248D20 param1)
{
    UnkFuncPtr_ov23_0224FE38 v0 = param0->unk_264;
    UnkFuncPtr_ov23_0224FD84 v1 = param0->unk_268;
    ListMenuTemplate v2;
    int v3 = v0(param0);
    int v4 = 6;

    ov23_0224FB7C(param0);
    UndergroundTextPrinter_ChangeMessageLoaderBank(CommManUnderground_GetItemNameTextPrinter(), TEXT_BANK_UNDERGROUND_TRAP_NAMES, MESSAGE_LOADER_BANK_HANDLE);

    param0->unk_40 = StringList_New(v3 + 1, HEAP_ID_FIELD);

    Window_Add(param0->fieldSystem->bgConfig, &param0->unk_10, 3, 19, 3, 12, (6 * 2), 13, ((1024 - (18 + 12) - 9 - 11 * 22) - 12 * (6 * 2)));
    Window_DrawStandardFrame(&param0->unk_10, 1, 1024 - (18 + 12) - 9, 11);

    {
        MessageLoader *v5;
        int v6 = 0;

        v5 = UndergroundTextPrinter_GetMessageLoader(CommManUnderground_GetItemNameTextPrinter());

        for (v6 = 0; v6 < v3; v6++) {
            StringList_AddFromMessageBank(param0->unk_40, v5, v1(v6, param0), v6);
        }

        StringList_AddFromMessageBank(param0->unk_40, v5, 34, 0xfffffffe);
    }

    v2 = Unk_ov23_02256904;
    v2.count = v3 + 1;
    v2.maxDisplay = v4;
    v2.choices = param0->unk_40;
    v2.window = &param0->unk_10;
    v2.cursorCallback = param0->unk_60;
    v2.printCallback = param0->unk_64;
    v2.parent = param0;

    ov23_02251238(param0, v4, v2.count);

    param0->unk_4C = ov23_02248C08(&v2, param0->unk_294, param0->unk_290, HEAP_ID_FIELD, param1, Unk_ov23_022577B8->underground, 0);
    param0->unk_2AA = 5;
}

static BOOL ov23_0224FF58(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u32 v1;
    u16 v2, v3;

    v1 = ov23_02248D20(v0->unk_4C);

    ListMenu_GetListAndCursorPos(v0->unk_4C->unk_0C, &v2, &v3);
    ov23_022430E0(8, v3, v2);

    if (CommSys_CheckError()) {
        v1 = 0xfffffffe;
    }

    if (v1 == 0xfffffffe) {
        v1 = 0xfffffffe;
    }

    switch (v1) {
    case 0xffffffff:
        ov23_0225128C(v0, v2, ListMenu_GetAttribute(v0->unk_4C->unk_0C, 2), 6);
        return 0;
    case 0xfffffffe:
        ov23_0224FD3C(v0);
        break;
    default: {
        UndergroundTextPrinter_EraseMessageBoxWindow(CommManUnderground_GetItemNameTextPrinter());

        Unk_ov23_022577B8->unk_04 = v1;
        Unk_ov23_022577B8->unk_05 = ov23_0224F66C(v1, v0);

        if (Unk_ov23_022577B8->unk_05 == 33) {
            ov23_0224CD68();
            v0->unk_2AA = 3;
        } else {
            ov23_0224FB7C(v0);
            ov23_0224FBFC(v0, 1);

            v0->unk_2AA = 18;

            UndergroundTextPrinter_SetUndergroundTrapNameWithIndex(CommManUnderground_GetCommonTextPrinter(), 2, Unk_ov23_022577B8->unk_05);
            UndergroundTextPrinter_PrintTextInstant(CommManUnderground_GetCommonTextPrinter(), 129, FALSE, NULL);
        }
    }
        sub_0206A8C4(v0->unk_08, 0, 0);
        sub_0206A8C4(v0->unk_08, 1, 0);
        break;
    }

    return 1;
}

static BOOL ov23_02250048(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u32 v1;
    u16 v2;

    v1 = ListMenu_ProcessInput(v0->unk_50);
    v2 = v0->unk_2B0;

    ListMenu_CalcTrueCursorPos(v0->unk_50, &v0->unk_2B0);

    if (v2 != v0->unk_2B0) {
        Sound_PlayEffect(SEQ_SE_CONFIRM);
    }

    switch (v1) {
    case 0xffffffff:
        return 0;
    case 0xfffffffe:
        Sound_PlayEffect(SEQ_SE_CONFIRM);
        ov23_0224FCF4(v0);
        ov23_0224FDE0(v0);
        v0->unk_2AA = 5;
        break;
    default:
        ov23_0224FCF4(v0);

        if (v1 == 1) {
            ov23_02243AD4(ov23_0224F66C(Unk_ov23_022577B8->unk_04, v0));
            Sound_PlayEffect(SEQ_SE_DP_SUTYA);
            v0->unk_2AA = 3;
        } else if (v1 == 2) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);

            ov23_0224FD68(Unk_ov23_022577B8->unk_05);
            UndergroundTextPrinter_SetUndergroundTrapNameWithIndex(CommManUnderground_GetCommonTextPrinter(), 2, Unk_ov23_022577B8->unk_05);
            UndergroundTextPrinter_PrintText(CommManUnderground_GetCommonTextPrinter(), 130, FALSE, NULL);

            v0->unk_00 = (void *)ov23_0224FDE0;
            v0->unk_2A9 = 5;
            v0->unk_2AA = 14;
        }
        break;
    }

    return 1;
}

void ov23_02250128(int param0)
{
    GF_ASSERT(Unk_ov23_022577B8->unk_05 == param0);
    sub_02028C6C(Unk_ov23_022577B8->underground, Unk_ov23_022577B8->unk_04);
}

static void ov23_0225014C(ListMenu *param0, u32 param1, u8 param2)
{
    UnkStruct_ov23_02250CD4 *v0 = (UnkStruct_ov23_02250CD4 *)ListMenu_GetAttribute(param0, 19);
    UnkFuncPtr_ov23_0224FD84 v1 = v0->unk_268;
    int v2 = param1;
    int v3 = v1(v2, v0);

    if (param1 == 0xfffffffe) {
        v2 = 61;
    } else {
        v2 = 62 + v3;
    }

    UndergroundTextPrinter_PrintTextInstant(CommManUnderground_GetItemNameTextPrinter(), v2, FALSE, NULL);
}

void ov23_02250184(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_264 = ov23_0224F658;
    param0->unk_268 = ov23_0224F684;
    param0->unk_26C = ov23_0224F69C;
    param0->unk_60 = ov23_0225014C;

    ov23_0225021C(param0, sub_02028CD8);
}

static void ov23_022501BC(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_290 = ov23_0224318C(9);
    param0->unk_294 = ov23_02243154(9);
    param0->unk_264 = ov23_0224F658;
    param0->unk_268 = ov23_0224F684;
    param0->unk_26C = ov23_0224F69C;
    param0->unk_60 = ov23_0225014C;
    param0->unk_2B0 = param0->unk_290;

    ov23_0225021C(param0, sub_02028CD8);
}

static void ov23_0225021C(UnkStruct_ov23_02250CD4 *param0, UnkFuncPtr_ov23_02248D20 param1)
{
    UnkFuncPtr_ov23_0224FE38 v0 = param0->unk_264;
    UnkFuncPtr_ov23_0224FD84 v1 = param0->unk_268;
    UnkFuncPtr_ov23_0225021C v2 = param0->unk_26C;
    ListMenuTemplate v3;
    int v4 = v0(param0);
    int v5 = 6;

    ov23_0224FB7C(param0);
    UndergroundTextPrinter_ChangeMessageLoaderBank(CommManUnderground_GetItemNameTextPrinter(), TEXT_BANK_UNDERGROUND_ITEM_NAMES, MESSAGE_LOADER_BANK_HANDLE);

    param0->unk_40 = StringList_New(v4 + 1, HEAP_ID_FIELD);

    Window_Add(param0->fieldSystem->bgConfig, &param0->unk_10, 3, 19, 3, 12, (6 * 2), 13, ((1024 - (18 + 12) - 9 - 11 * 22) - 12 * (6 * 2)));
    Window_DrawStandardFrame(&param0->unk_10, 1, 1024 - (18 + 12) - 9, 11);

    {
        MessageLoader *v6;
        int v7;

        v6 = UndergroundTextPrinter_GetMessageLoader(CommManUnderground_GetItemNameTextPrinter());

        for (v7 = 0; v7 < v4; v7++) {
            StringTemplate_SetUndergroundItemName(param0->unk_70, 2, v1(v7, param0));
            StringTemplate_SetNumber(param0->unk_70, 6, v2(v7, param0), 2, 2, 1);
            MessageLoader_GetStrbuf(UndergroundTextPrinter_GetMessageLoader(CommManUnderground_GetCommonTextPrinter()), 128, param0->unk_6C);
            StringTemplate_Format(param0->unk_70, param0->unk_68, param0->unk_6C);
            StringList_AddFromStrbuf(param0->unk_40, param0->unk_68, v7);
        }

        StringList_AddFromMessageBank(param0->unk_40, v6, 60, 0xfffffffe);
    }

    v3 = Unk_ov23_02256904;
    v3.count = v4 + 1;
    v3.maxDisplay = v5;
    v3.choices = param0->unk_40;
    v3.window = &param0->unk_10;
    v3.cursorCallback = param0->unk_60;
    v3.parent = param0;

    ov23_02251238(param0, v5, v3.count);

    param0->unk_4C = ov23_02248C08(&v3, param0->unk_294, param0->unk_290, HEAP_ID_FIELD, param1, Unk_ov23_022577B8->underground, 0);
    param0->unk_2AA = 6;
}

static BOOL ov23_02250378(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u32 v1;
    u16 v2, v3;

    v1 = ov23_02248D20(v0->unk_4C);

    ListMenu_GetListAndCursorPos(v0->unk_4C->unk_0C, &v2, &v3);
    ov23_022430E0(9, v3, v2);

    if (CommSys_CheckError()) {
        v1 = 0xfffffffe;
    }

    if (v1 == 0xfffffffe) {
        v1 = 0xfffffffe;
    }

    switch (v1) {
    case 0xffffffff:
        ov23_0225128C(v0, v2, ListMenu_GetAttribute(v0->unk_4C->unk_0C, 2), 6);
        return 0;
    case 0xfffffffe:
        ov23_0224FD3C(v0);
        break;
    default:
        ov23_0224FB7C(v0);
        Unk_ov23_022577B8->unk_04 = v1;
        Unk_ov23_022577B8->unk_05 = ov23_0224F684(v1, v0);
        ov23_0224FBFC(v0, 1);
        v0->unk_2AA = 16;
        UndergroundTextPrinter_SetUndergroundItemName(CommManUnderground_GetCommonTextPrinter(), 2, Unk_ov23_022577B8->unk_05);
        UndergroundTextPrinter_PrintTextInstant(CommManUnderground_GetCommonTextPrinter(), 129, FALSE, NULL);
        sub_0206A8C4(v0->unk_08, 0, 0);
        sub_0206A8C4(v0->unk_08, 1, 0);
        break;
    }

    return 1;
}

static BOOL ov23_0225044C(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u32 v1;
    u16 v2;

    v1 = ListMenu_ProcessInput(v0->unk_50);
    v2 = v0->unk_2B0;

    ListMenu_CalcTrueCursorPos(v0->unk_50, &v0->unk_2B0);

    if (v2 != v0->unk_2B0) {
        Sound_PlayEffect(SEQ_SE_CONFIRM);
    }

    switch (v1) {
    case 0xffffffff:
        return 0;
    case 0xfffffffe:
        Sound_PlayEffect(SEQ_SE_CONFIRM);
        ov23_0224FCF4(v0);
        ov23_022501BC(v0);
        v0->unk_2AA = 6;
        break;
    default:
        ov23_0224FCF4(v0);

        if (v1 == 1) {
            int v3 = CommSys_CurNetId();
            int v4 = sub_02058D88(v3);
            int v5 = sub_02058DC0(v3);

            UndergroundTextPrinter_EraseMessageBoxWindow(CommManUnderground_GetItemNameTextPrinter());
            ov23_02241AE8(Unk_ov23_022577B8->unk_05, ov23_0224F69C(Unk_ov23_022577B8->unk_04, v0), v4, v5);
        } else if (v1 == 2) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            ov23_02250128(Unk_ov23_022577B8->unk_05);
            UndergroundTextPrinter_SetUndergroundItemName(CommManUnderground_GetCommonTextPrinter(), 2, Unk_ov23_022577B8->unk_05);
            UndergroundTextPrinter_PrintText(CommManUnderground_GetCommonTextPrinter(), 130, FALSE, NULL);
        }

        v0->unk_00 = (void *)ov23_022501BC;
        v0->unk_2A9 = 6;
        v0->unk_2AA = 14;

        break;
    }

    return 1;
}

void ov23_02250540(ListMenu *param0, u32 param1, u8 param2)
{
    UnkStruct_ov23_02250CD4 *v0 = (UnkStruct_ov23_02250CD4 *)ListMenu_GetAttribute(param0, 19);
    UnkFuncPtr_ov23_0224FD84 v1 = v0->unk_268;
    int v2 = param1;
    int v3 = v1(v2, v0);

    if (param1 == 0xfffffffe) {
        v2 = 61;
    } else {
        v2 = 62 + v3;
    }

    UndergroundTextPrinter_PrintTextInstant(CommManUnderground_GetItemNameTextPrinter(), v2, FALSE, NULL);
}

void ov23_02250578(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_264 = ov23_0224F6B4;
    param0->unk_268 = ov23_0224F6C8;

    ov23_022505EC(param0, NULL);
}

void ov23_02250598(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_290 = ov23_0224318C(11);
    param0->unk_294 = ov23_02243154(11);
    param0->unk_264 = ov23_0224F6B4;
    param0->unk_268 = ov23_0224F6C8;
    param0->unk_60 = ov23_02250540;
    param0->unk_2B0 = param0->unk_290;

    ov23_022505EC(param0, sub_02028DD8);
}

static void ov23_022505EC(UnkStruct_ov23_02250CD4 *param0, UnkFuncPtr_ov23_02248D20 param1)
{
    UnkFuncPtr_ov23_0224FE38 v0 = param0->unk_264;
    UnkFuncPtr_ov23_0224FD84 v1 = param0->unk_268;
    ListMenuTemplate v2;
    int v3 = v0(param0);
    int v4 = 6;

    ov23_0224FB7C(param0);
    UndergroundTextPrinter_ChangeMessageLoaderBank(CommManUnderground_GetItemNameTextPrinter(), TEXT_BANK_UNDERGROUND_ITEM_NAMES, MESSAGE_LOADER_BANK_HANDLE);

    param0->unk_40 = StringList_New(v3 + 1, HEAP_ID_FIELD);

    Window_Add(param0->fieldSystem->bgConfig, &param0->unk_10, 3, 19, 3, 12, (6 * 2), 13, ((1024 - (18 + 12) - 9 - 11 * 22) - 12 * (6 * 2)));
    Window_DrawStandardFrame(&param0->unk_10, 1, 1024 - (18 + 12) - 9, 11);

    {
        MessageLoader *v5;
        int v6 = 0;

        v5 = UndergroundTextPrinter_GetMessageLoader(CommManUnderground_GetItemNameTextPrinter());

        for (v6 = 0; v6 < v3; v6++) {
            StringList_AddFromMessageBank(param0->unk_40, v5, v1(v6, param0), v6);
        }

        StringList_AddFromMessageBank(param0->unk_40, v5, 60, 0xfffffffe);
    }

    v2 = Unk_ov23_02256904;
    v2.count = v3 + 1;
    v2.maxDisplay = v4;
    v2.choices = param0->unk_40;
    v2.window = &param0->unk_10;
    v2.cursorCallback = param0->unk_60;
    v2.parent = param0;

    ov23_02251238(param0, v4, v2.count);

    param0->unk_4C = ov23_02248C08(&v2, param0->unk_294, param0->unk_290, HEAP_ID_FIELD, param1, Unk_ov23_022577B8->underground, 0);
    param0->unk_2AA = 7;
}

static BOOL ov23_02250704(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u32 v1;
    u16 v2, v3;

    v1 = ov23_02248D20(v0->unk_4C);

    ListMenu_GetListAndCursorPos(v0->unk_4C->unk_0C, &v2, &v3);
    ov23_022430E0(11, v3, v2);

    if (CommSys_CheckError()) {
        v1 = 0xfffffffe;
    }

    if (v1 == 0xfffffffe) {
        v1 = 0xfffffffe;
    }

    switch (v1) {
    case 0xffffffff:
        ov23_0225128C(v0, v2, ListMenu_GetAttribute(v0->unk_4C->unk_0C, 2), 6);
        return 0;
    case 0xfffffffe:
        ov23_0224FD3C(v0);
        break;
    default:
        ov23_0224FB7C(v0);

        Unk_ov23_022577B8->unk_04 = v1;
        Unk_ov23_022577B8->unk_05 = ov23_0224F6C8(v1, v0);

        ov23_0224FBFC(v0, 3);
        UndergroundTextPrinter_SetUndergroundItemName(CommManUnderground_GetCommonTextPrinter(), 2, Unk_ov23_022577B8->unk_05);
        UndergroundTextPrinter_PrintTextInstant(CommManUnderground_GetCommonTextPrinter(), 129, FALSE, NULL);

        v0->unk_2AA = 17;

        sub_0206A8C4(v0->unk_08, 0, 0);
        sub_0206A8C4(v0->unk_08, 1, 0);
        break;
    }

    return 1;
}

static BOOL ov23_022507D8(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u32 v1;
    u16 v2;

    v1 = ListMenu_ProcessInput(v0->unk_50);
    v2 = v0->unk_2B0;

    ListMenu_CalcTrueCursorPos(v0->unk_50, &v0->unk_2B0);

    if (v2 != v0->unk_2B0) {
        Sound_PlayEffect(SEQ_SE_CONFIRM);
    }

    switch (v1) {
    case 0xffffffff:
        return 0;
    case 0xfffffffe:
        Sound_PlayEffect(SEQ_SE_CONFIRM);
        ov23_0224FCF4(v0);
        ov23_02250598(v0);
        v0->unk_2AA = 7;
        break;
    default:
        ov23_0224FCF4(v0);

        if (v1 == 3) {
            int item = Underground_ConvertTreasureToBagItem(Unk_ov23_022577B8->unk_05);
            Bag *v4 = SaveData_GetBag(v0->fieldSystem->saveData);

            Sound_PlayEffect(SEQ_SE_CONFIRM);

            if (Bag_TryAddItem(v4, item, 1, HEAP_ID_FIELD)) {
                sub_02028D80(Unk_ov23_022577B8->underground, Unk_ov23_022577B8->unk_04);
                UndergroundTextPrinter_SetUndergroundItemName(CommManUnderground_GetCommonTextPrinter(), 0, Unk_ov23_022577B8->unk_05);

                if ((Unk_ov23_022577B8->unk_05 == 29) || (Unk_ov23_022577B8->unk_05 == 30)) {
                    UndergroundTextPrinter_PrintText(CommManUnderground_GetCommonTextPrinter(), 81, FALSE, NULL);
                } else {
                    UndergroundTextPrinter_PrintText(CommManUnderground_GetCommonTextPrinter(), 79, FALSE, NULL);
                }
            } else {
                UndergroundTextPrinter_SetUndergroundItemName(CommManUnderground_GetCommonTextPrinter(), 0, Unk_ov23_022577B8->unk_05);
                UndergroundTextPrinter_PrintText(CommManUnderground_GetCommonTextPrinter(), 80, FALSE, NULL);
            }
        } else if (v1 == 2) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            sub_02028D80(Unk_ov23_022577B8->underground, Unk_ov23_022577B8->unk_04);

            UndergroundTextPrinter_SetUndergroundItemName(CommManUnderground_GetCommonTextPrinter(), 2, Unk_ov23_022577B8->unk_05);
            UndergroundTextPrinter_PrintText(CommManUnderground_GetCommonTextPrinter(), 130, FALSE, NULL);
        }

        v0->unk_00 = (void *)ov23_02250598;
        v0->unk_2A9 = 7;
        v0->unk_2AA = 14;

        break;
    }

    return 1;
}

static void ov23_02250930(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_2AA = 2;
}

static void ov23_0225093C(UnkStruct_ov23_02250CD4 *param0)
{
    ov23_0224FB7C(param0);

    if (ov23_02242E58(Player_GetXPos(param0->fieldSystem->playerAvatar), Player_GetZPos(param0->fieldSystem->playerAvatar))) {
        UndergroundTextPrinter_PrintText(CommManUnderground_GetCommonTextPrinter(), 66, FALSE, NULL);
        param0->unk_2AA = 13;
    } else {
        param0->unk_28C = UndergroundTextPrinter_PrintText(CommManUnderground_GetCommonTextPrinter(), 52, FALSE, NULL);
        param0->unk_2AA = 11;
    }
}

static void ov23_02250998(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;

    if (UndergroundTextPrinter_IsPrinterActive(CommManUnderground_GetCommonTextPrinter()) == FALSE) {
        v0->unk_5C = Menu_MakeYesNoChoice(v0->fieldSystem->bgConfig, &Unk_ov23_022568D8, 1024 - (18 + 12) - 9, 11, 4);
        v0->unk_2AA = 12;
    }
}

static void ov23_022509D4(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    int v1 = Menu_ProcessInputAndHandleExit(v0->unk_5C, 4);

    if (v1 == 0xffffffff) {
        return;
    } else if (v1 == 0) {
        v0->unk_2AA = 15;
    } else {
        UndergroundTextPrinter_EraseMessageBoxWindow(CommManUnderground_GetCommonTextPrinter());
        ov23_0224FD3C(v0);
    }

    v0->unk_5C = NULL;
}

static void ov23_02250A0C(void *param0)
{
    UnkStruct_ov23_02250CD4 *v0 = param0;
    ov23_0224FD3C(v0);
}

static void ov23_02250A14(UnkStruct_ov23_02250CD4 *param0)
{
    ov23_0224FB7C(param0);
    ov23_02253968();
    ov23_02253834(param0->fieldSystem->bgConfig, SaveData_GetTrainerInfo(FieldSystem_GetSaveData(param0->fieldSystem)), ov23_02250A0C, param0, 1);
    param0->unk_2AA = 10;
}

void ov23_02250A50(UnkFuncPtr_ov23_0224F758 param0, FieldSystem *fieldSystem)
{
    UnkStruct_ov23_02250CD4 *v0;
    ListMenuTemplate v1;

    v0 = Heap_AllocFromHeap(HEAP_ID_FIELD, sizeof(UnkStruct_ov23_02250CD4));

    MI_CpuFill8(v0, 0, sizeof(UnkStruct_ov23_02250CD4));

    v0->fieldSystem = fieldSystem;
    v0->unk_260 = param0;
    v0->unk_2AA = 0;
    v0->unk_68 = Strbuf_Init((50 * 2), HEAP_ID_FIELD);
    v0->unk_6C = Strbuf_Init((50 * 2), HEAP_ID_FIELD);
    v0->unk_70 = StringTemplate_Default(HEAP_ID_FIELD);

    sub_020594FC();

    UndergroundTextPrinter_PrintText(CommManUnderground_GetCaptureFlagTextPrinter(), 0, FALSE, NULL);
    v0->unk_04 = SysTask_Start(ov23_02250B9C, v0, 10000);
    ov23_022431EC(v0, v0->unk_04, ov23_02251270);
}

static void ov23_02250ACC(UnkStruct_ov23_02250CD4 *param0)
{
    if (UndergroundTextPrinter_IsPrinterActive(CommManUnderground_GetCaptureFlagTextPrinter()) == FALSE) {
        param0->unk_5C = Menu_MakeYesNoChoice(param0->fieldSystem->bgConfig, &Unk_ov23_022568D8, 1024 - (18 + 12) - 9, 11, 4);
        param0->unk_2AA = 1;
    }
}

static void ov23_02250B08(UnkStruct_ov23_02250CD4 *param0)
{
    int v0 = Menu_ProcessInputAndHandleExit(param0->unk_5C, 4);

    if (v0 == 0xffffffff) {
        return;
    } else if (v0 == 0) {
        param0->unk_2AA = 3;
    } else {
        param0->unk_2AA = 2;
    }

    param0->unk_5C = NULL;
}

static void ov23_02250B34(SysTask *param0, UnkStruct_ov23_02250CD4 *param1, BOOL param2)
{
    if (param1->unk_5C) {
        Menu_DestroyForExit(param1->unk_5C, 4);
    }

    Strbuf_Free(param1->unk_68);
    Strbuf_Free(param1->unk_6C);
    StringTemplate_Free(param1->unk_70);

    UndergroundTextPrinter_EraseMessageBoxWindow(CommManUnderground_GetCaptureFlagTextPrinter());
    UndergroundTextPrinter_EraseMessageBoxWindow(CommManUnderground_GetCommonTextPrinter());

    if (param1->unk_260 != NULL) {
        param1->unk_260(0);
    }

    param1->unk_04 = NULL;

    if (param1->unk_08) {
        sub_0206A844(param1->unk_08);
    }

    Heap_Free(param1);

    if (!param2) {
        sub_02059514();
    }

    SysTask_Done(param0);
}

static void ov23_02250B9C(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;

    if (!ov23_0224AEA4(CommSys_CurNetId())) {
        if ((v0->unk_2AA == 0) || (v0->unk_2AA == 1)) {
            v0->unk_2AA = 2;
        }
    }

    switch (v0->unk_2AA) {
    case 0:
        ov23_02250ACC(param1);
        break;
    case 1:
        ov23_02250B08(param1);
        break;
    case 2:
        ov23_02243204();
        ov23_02250B34(param0, param1, 0);
        return;
    case 3:
        ov23_02243204();
        ov23_02250B34(param0, param1, 1);
        {
            u8 v1 = 0;

            CommSys_SendDataFixedSize(84, &v1);
        }
        return;
    case 4:
        if (UndergroundTextPrinter_IsPrinterActive(CommManUnderground_GetCaptureFlagTextPrinter()) == FALSE) {
            if (gSystem.pressedKeys & PAD_BUTTON_A) {
                v0->unk_2AA = 2;
            }
        }
        break;
    }
}

void ov23_02250C3C(ListMenu *param0, u32 param1, u8 param2)
{
    UnkStruct_ov23_02250CD4 *v0 = (UnkStruct_ov23_02250CD4 *)ListMenu_GetAttribute(param0, 19);
    UnkFuncPtr_ov23_0224FD84 v1 = v0->unk_268;
    int v2 = param1;
    int v3 = v1(v2, v0);

    if (param1 == 0xfffffffe) {
        v2 = 139;
    } else {
        v2 = 145 + v3 - 7;
    }

    UndergroundTextPrinter_PrintTextInstant(CommManUnderground_GetItemNameTextPrinter(), v2, FALSE, NULL);
}

static void ov23_02250C74(ListMenu *param0, u32 param1, u8 param2)
{
    UnkStruct_ov23_02250CD4 *v0 = (UnkStruct_ov23_02250CD4 *)ListMenu_GetAttribute(param0, 19);
    int v1 = param1;
    Underground *v2 = SaveData_GetUnderground(FieldSystem_GetSaveData(v0->fieldSystem));

    if (!sub_02028AFC(v2, v1)) {
        ListMenu_SetAltTextColors(param0, 1, 15, 2);
    } else {
        ListMenu_SetAltTextColors(param0, 2, 15, 2);
    }
}

void ov23_02250CB0(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_264 = ov23_0224F608;
    param0->unk_268 = ov23_0224F61C;
    param0->unk_64 = NULL;

    ov23_02250D90(param0, NULL);
}

void ov23_02250CD4(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_290 = ov23_0224318C(10);
    param0->unk_294 = ov23_02243154(10);
    param0->unk_264 = ov23_0224F608;
    param0->unk_268 = ov23_0224F61C;
    param0->unk_60 = ov23_02250C3C;
    param0->unk_64 = NULL;
    param0->unk_2B0 = param0->unk_290;

    ov23_02250D90(param0, sub_02028BE8);
}

void ov23_02250D2C(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_264 = ov23_0224F608;
    param0->unk_268 = ov23_0224F61C;
    param0->unk_60 = ov23_02250C3C;
    param0->unk_64 = NULL;

    ov23_02250D90(param0, sub_02028BE8);
}

void ov23_02250D5C(UnkStruct_ov23_02250CD4 *param0)
{
    param0->unk_264 = ov23_0224F5DC;
    param0->unk_268 = ov23_0224F5F0;
    param0->unk_60 = ov23_02250C3C;
    param0->unk_64 = ov23_02250C74;

    ov23_02250D90(param0, sub_02028A10);
}

static void ov23_02250D90(UnkStruct_ov23_02250CD4 *param0, UnkFuncPtr_ov23_02248D20 param1)
{
    UnkFuncPtr_ov23_0224FE38 v0 = param0->unk_264;
    UnkFuncPtr_ov23_0224FD84 v1 = param0->unk_268;
    ListMenuTemplate v2;
    int v3 = v0(param0);
    int v4 = 6;

    ov23_0224FB7C(param0);
    UndergroundTextPrinter_ChangeMessageLoaderBank(CommManUnderground_GetItemNameTextPrinter(), TEXT_BANK_UNDERGROUND_GOODS, MESSAGE_LOADER_BANK_HANDLE);

    param0->unk_40 = StringList_New(v3 + 1, HEAP_ID_FIELD);

    Window_Add(param0->fieldSystem->bgConfig, &param0->unk_10, 3, 19, 3, 12, (6 * 2), 13, ((1024 - (18 + 12) - 9 - 11 * 22) - 12 * (6 * 2)));
    Window_DrawStandardFrame(&param0->unk_10, 1, 1024 - (18 + 12) - 9, 11);

    {
        MessageLoader *v5;
        int v6 = 0;

        v5 = UndergroundTextPrinter_GetMessageLoader(CommManUnderground_GetItemNameTextPrinter());

        for (v6 = 0; v6 < v3; v6++) {
            StringList_AddFromMessageBank(param0->unk_40, v5, v1(v6, param0), v6);
        }

        StringList_AddFromMessageBank(param0->unk_40, v5, 0, 0xfffffffe);
    }

    v2 = Unk_ov23_02256904;
    v2.count = v3 + 1;
    v2.maxDisplay = v4;
    v2.printCallback = param0->unk_64;
    v2.choices = param0->unk_40;
    v2.window = &param0->unk_10;
    v2.cursorCallback = param0->unk_60;
    v2.parent = param0;

    ov23_02251238(param0, v4, v2.count);

    param0->unk_4C = ov23_02248C08(&v2, param0->unk_294, param0->unk_290, HEAP_ID_FIELD, param1, Unk_ov23_022577B8->underground, 0);
    param0->unk_2AA = 8;
}

static BOOL ov23_02250EAC(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u32 v1;
    u16 v2, v3;

    v1 = ov23_02248D20(v0->unk_4C);

    ListMenu_GetListAndCursorPos(v0->unk_4C->unk_0C, &v2, &v3);
    ov23_022430E0(10, v3, v2);

    if (CommSys_CheckError()) {
        v1 = 0xfffffffe;
    }

    if (v1 == 0xfffffffe) {
        v1 = 0xfffffffe;
    }

    switch (v1) {
    case 0xffffffff:
        ov23_0225128C(v0, v2, ListMenu_GetAttribute(v0->unk_4C->unk_0C, 2), 6);
        return 0;
    case 0xfffffffe:
        Sound_PlayEffect(SEQ_SE_CONFIRM);
        ov23_0224FD3C(v0);
        break;
    default:
        ov23_0224FB7C(v0);

        Unk_ov23_022577B8->unk_04 = v1;
        Unk_ov23_022577B8->unk_05 = ov23_0224F61C(v1, v0);

        ov23_0224FBFC(v0, 2);
        UndergroundTextPrinter_SetUndergroundGoodsNameWithIndex(CommManUnderground_GetCommonTextPrinter(), 2, Unk_ov23_022577B8->unk_05);
        UndergroundTextPrinter_PrintTextInstant(CommManUnderground_GetCommonTextPrinter(), 129, FALSE, NULL);

        v0->unk_2AA = 19;

        sub_0206A8C4(v0->unk_08, 0, 0);
        sub_0206A8C4(v0->unk_08, 1, 0);
        break;
    }

    return 1;
}

static BOOL ov23_02250F8C(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u32 v1;
    u16 v2;

    v1 = ListMenu_ProcessInput(v0->unk_50);
    v2 = v0->unk_2B0;

    ListMenu_CalcTrueCursorPos(v0->unk_50, &v0->unk_2B0);

    if (v2 != v0->unk_2B0) {
        Sound_PlayEffect(SEQ_SE_CONFIRM);
    }

    switch (v1) {
    case 0xffffffff:
        return 0;
    case 0xfffffffe:
        Sound_PlayEffect(SEQ_SE_CONFIRM);
        ov23_0224FCF4(v0);
        ov23_02250CD4(v0);
        v0->unk_2AA = 8;
        break;
    default:
        ov23_0224FCF4(v0);

        if (v1 == 2) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            sub_02028B94(Unk_ov23_022577B8->underground, Unk_ov23_022577B8->unk_04);
            UndergroundTextPrinter_SetUndergroundGoodsNameWithIndex(CommManUnderground_GetCommonTextPrinter(), 2, Unk_ov23_022577B8->unk_05);
            UndergroundTextPrinter_PrintText(CommManUnderground_GetCommonTextPrinter(), 130, FALSE, NULL);
        }

        v0->unk_00 = (void *)ov23_02250CD4;
        v0->unk_2A9 = 8;
        v0->unk_2AA = 14;

        break;
    }

    return 1;
}

void ov23_02251044(void *param0, u32 param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param0;

    ov23_0224FB7C(v0);
    ov23_02242FBC();
    ov23_022535EC();
    ov23_02245784();
    ov23_02241364();
    ov23_02241ED0();

    if (v0->unk_270) {
        ov23_02253D10(v0->unk_270);
    }

    if (v0->unk_5C) {
        Menu_DestroyForExit(v0->unk_5C, 4);
    }

    ov23_0224FCF4(v0);

    if (v0->unk_08) {
        sub_0206A844(v0->unk_08);
    }

    if (v0->unk_260 != NULL) {
        Unk_ov23_022577B8->unk_04 = param1;
        Unk_ov23_022577B8->unk_05 = ov23_0224F61C(param1, v0);
        v0->unk_260(0);
        v0->unk_260 = NULL;
    }

    if (v0->unk_68) {
        Strbuf_Free(v0->unk_68);
    }

    if (v0->unk_6C) {
        Strbuf_Free(v0->unk_6C);
    }

    if (v0->unk_70) {
        StringTemplate_Free(v0->unk_70);
    }

    if (v0->unk_04) {
        SysTask_Done(v0->unk_04);
    }

    Heap_Free(v0);
}

static BOOL ov23_022510F0(SysTask *param0, void *param1)
{
    UnkStruct_ov23_02250CD4 *v0 = param1;
    u32 v1 = ov23_02248D20(v0->unk_4C);

    if (CommSys_CheckError()) {
        v1 = 0xfffffffe;
    }

    if (v1 == 0xfffffffe) {
        v1 = 0xfffffffe;
    }

    switch (v1) {
    case 0xffffffff:
        return 0;
    case 0xfffffffe:
        if (v0->unk_260 != NULL) {
            Unk_ov23_022577B8->unk_04 = v1;
            Unk_ov23_022577B8->unk_05 = 0;
            v0->unk_260(Unk_ov23_022577B8->unk_05);
            v0->unk_260 = NULL;
        }

        UndergroundTextPrinter_EraseMessageBoxWindow(CommManUnderground_GetItemNameTextPrinter());
        ov23_02251044(v0, v1);
        ov23_02243204();
        return 1;
    default:

        if (v0->unk_260 != NULL) {
            Unk_ov23_022577B8->unk_04 = v1;
            Unk_ov23_022577B8->unk_05 = ov23_0224F61C(v1, v0);
            v0->unk_260(Unk_ov23_022577B8->unk_05);
            v0->unk_260 = NULL;
        }

        UndergroundTextPrinter_EraseMessageBoxWindow(CommManUnderground_GetItemNameTextPrinter());
        ov23_02251044(v0, v1);
        ov23_02243204();
        return 1;
        break;
    }

    return 1;
}

void *ov23_022511B0(UnkFuncPtr_ov23_0224F758 param0, FieldSystem *fieldSystem)
{
    UnkStruct_ov23_02250CD4 *v0;
    ListMenuTemplate v1;

    v0 = Heap_AllocFromHeap(HEAP_ID_FIELD, sizeof(UnkStruct_ov23_02250CD4));

    MI_CpuFill8(v0, 0, sizeof(UnkStruct_ov23_02250CD4));

    v0->fieldSystem = fieldSystem;
    v0->unk_260 = param0;
    v0->unk_2AA = 0;
    v0->unk_25C = 0;
    v0->unk_48 = NULL;
    v0->unk_60 = NULL;
    v0->unk_68 = Strbuf_Init((50 * 2), HEAP_ID_FIELD);
    v0->unk_6C = Strbuf_Init((50 * 2), HEAP_ID_FIELD);
    v0->unk_70 = StringTemplate_Default(HEAP_ID_FIELD);

    ov23_02250CD4(v0);

    v0->unk_2AA = 9;
    v0->unk_04 = SysTask_Start(ov23_0224F914, v0, 10000);

    ov23_022431EC(v0, v0->unk_04, ov23_02251270);
    return v0;
}

void ov23_02251238(UnkStruct_ov23_02250CD4 *param0, int param1, int param2)
{
    if ((param0->unk_294 + param1) >= param2) {
        param0->unk_294 = param2 - param1;

        if (param0->unk_294 < 0) {
            param0->unk_294 = 0;
        }
    }

    if (param0->unk_290 >= (param2 - 1)) {
        param0->unk_290 = param2 - 1;

        if (param0->unk_290 < 0) {
            param0->unk_290 = 0;
        }
    }
}

void ov23_02251270(SysTask *param0, void *param1)
{
    BrightnessController_SetScreenBrightness(0, GX_BLEND_PLANEMASK_BG0, BRIGHTNESS_MAIN_SCREEN);
    ov23_02251044(param1, 0xfffffffe);
}
