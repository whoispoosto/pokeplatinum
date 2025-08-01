#include "overlay111/ov111_021D0D80.h"

#include <nitro.h>
#include <string.h>

#include "struct_decls/struct_02015920_decl.h"
#include "struct_defs/struct_02015958.h"
#include "struct_defs/struct_0203E608.h"
#include "struct_defs/struct_02099F80.h"

#include "overlay111/ov111_021D2F80.h"
#include "overlay111/ov111_021D33F4.h"
#include "overlay111/ov111_021D3548.h"
#include "overlay111/struct_ov111_021D0F7C_decl.h"
#include "overlay111/struct_ov111_021D2F80.h"
#include "overlay111/struct_ov111_021D33F4_decl.h"
#include "overlay111/struct_ov111_021D3620.h"

#include "bg_window.h"
#include "font.h"
#include "font_special_chars.h"
#include "game_options.h"
#include "graphics.h"
#include "gx_layers.h"
#include "heap.h"
#include "math_util.h"
#include "message.h"
#include "narc.h"
#include "overlay_manager.h"
#include "palette.h"
#include "render_oam.h"
#include "render_window.h"
#include "save_player.h"
#include "savedata.h"
#include "screen_fade.h"
#include "sound.h"
#include "sound_playback.h"
#include "sprite.h"
#include "strbuf.h"
#include "string_template.h"
#include "system.h"
#include "text.h"
#include "touch_pad.h"
#include "touch_screen.h"
#include "unk_0201567C.h"
#include "unk_02015920.h"
#include "vram_transfer.h"

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} UnkStruct_ov111_021D3728;

struct UnkStruct_ov111_021D0F7C_t {
    ApplicationManager *unk_00;
    ApplicationManager *unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    s16 unk_10;
    s16 unk_12;
    u8 unk_14;
    u8 unk_15[4];
    u8 unk_19[3];
    VecFx32 unk_1C;
    VecFx32 unk_28;
    UnkStruct_020157E4 *unk_34;
    MessageLoader *unk_38;
    StringTemplate *unk_3C;
    Strbuf *unk_40;
    Strbuf *unk_44;
    u16 unk_48[8];
    BgConfig *unk_58;
    Window unk_5C[16];
    PaletteData *unk_15C;
    FontSpecialCharsContext *unk_160;
    Options *options;
    SaveData *saveData;
    UnkStruct_ov111_021D2F80 unk_16C;
    UnkStruct_ov111_021D33F4 *unk_35C[4];
    UnkStruct_ov111_021D33F4 *unk_36C[9];
    UnkStruct_ov111_021D33F4 *unk_390[4];
    UnkStruct_ov111_021D33F4 *unk_3A0;
    UnkStruct_ov111_021D33F4 *unk_3A4;
    UnkStruct_ov111_021D33F4 *unk_3A8[3];
    UnkStruct_ov111_021D33F4 *unk_3B4[3];
    UnkStruct_ov111_021D33F4 *unk_3C0;
    u8 unk_3C4[9];
    u16 unk_3CE[4];
    u16 *unk_3D8;
    u16 *unk_3DC;
    u16 *unk_3E0;
    NARC *unk_3E4;
    u8 padding_3E8[8];
    void *unk_3F0;
    NNSG2dCharacterData *unk_3F4;
    u8 *unk_3F8;
    UnkStruct_02015920 *unk_3FC;
    u8 unk_400[9];
    u8 unk_409;
    u8 unk_40A;
    u8 unk_40B;
    u8 unk_40C_0 : 1;
    u8 unk_40C_1 : 7;
    u8 unk_40D;
    u8 unk_40E[3];
    u8 unk_411[9];
    u32 unk_41C;
    u32 unk_420;
    TouchPadDataBuffer unk_424;
    u8 unk_466[38400];
};

int ov111_021D0D80(ApplicationManager *appMan, int *param1);
int ov111_021D0E34(ApplicationManager *appMan, int *param1);
int ov111_021D0F40(ApplicationManager *appMan, int *param1);
static BOOL ov111_021D0F7C(UnkStruct_ov111_021D0F7C *param0);
static BOOL ov111_021D0FC8(UnkStruct_ov111_021D0F7C *param0);
static BOOL ov111_021D10B8(UnkStruct_ov111_021D0F7C *param0);
static BOOL ov111_021D116C(UnkStruct_ov111_021D0F7C *param0);
static BOOL ov111_021D1284(UnkStruct_ov111_021D0F7C *param0);
static BOOL ov111_021D1508(UnkStruct_ov111_021D0F7C *param0);
static BOOL ov111_021D1980(UnkStruct_ov111_021D0F7C *param0);
static BOOL ov111_021D1A88(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D1AF4(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D1B44(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D1B90(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D1BEC(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D1C0C(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D1D30(void);
static void ov111_021D1D68(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D1F70(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D1F84(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D1FB4(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D2034(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D1FC4(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D2044(BgConfig *param0);
static void ov111_021D2090(void *param0);
static void ov111_021D20CC(void);
static void ov111_021D20EC(BgConfig *param0);
static void ov111_021D2248(UnkStruct_ov111_021D0F7C *param0, u32 param1);
static void ov111_021D22D0(void);
static void ov111_021D228C(UnkStruct_ov111_021D0F7C *param0, u32 param1);
static void ov111_021D233C(UnkStruct_ov111_021D0F7C *param0, u32 param1);
static void ov111_021D2304(void);
static void ov111_021D2380(UnkStruct_ov111_021D0F7C *param0, u32 param1);
static u8 ov111_021D23C4(UnkStruct_ov111_021D0F7C *param0, Window *param1, int param2, u32 param3, u32 param4, u32 param5, u8 param6, u8 param7, u8 param8, u8 param9);
static u8 ov111_021D2424(UnkStruct_ov111_021D0F7C *param0, Window *param1, int param2, u32 param3, u32 param4, u32 param5, u8 param6, u8 param7, u8 param8, u8 param9);
static u8 ov111_021D2494(UnkStruct_ov111_021D0F7C *param0);
static u8 ov111_021D24D4(UnkStruct_ov111_021D0F7C *param0);
static u8 ov111_021D2518(UnkStruct_ov111_021D0F7C *param0);
static u8 ov111_021D255C(UnkStruct_ov111_021D0F7C *param0);
static u8 ov111_021D25BC(UnkStruct_ov111_021D0F7C *param0);
static u8 ov111_021D2604(UnkStruct_ov111_021D0F7C *param0);
static u8 ov111_021D263C(UnkStruct_ov111_021D0F7C *param0);
static u8 ov111_021D2674(UnkStruct_ov111_021D0F7C *param0, u8 param1);
static void ov111_021D26CC(UnkStruct_ov111_021D0F7C *param0, u32 param1, s32 param2);
static void ov111_021D26E4(UnkStruct_ov111_021D0F7C *param0, int *param1, int param2);
static void ov111_021D26EC(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D271C(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D27AC(UnkStruct_ov111_021D0F7C *param0, u8 param1);
static void ov111_021D27BC(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D27D4(UnkStruct_ov111_021D0F7C *param0, u8 param1);
static BOOL ov111_021D2868(UnkStruct_ov111_021D0F7C *param0, u8 param1);
static void ov111_021D28E8(UnkStruct_ov111_021D0F7C *param0, u32 param1, u8 param2, u8 param3, u8 param4);
static u8 ov111_021D2918(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D2940(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D295C(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D297C(UnkStruct_ov111_021D0F7C *param0, int param1);
static void ov111_021D29D8(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D2A18(UnkStruct_ov111_021D0F7C *param0, int param1, int param2);
static BOOL ov111_021D2A68(UnkStruct_ov111_021D0F7C *param0, u8 param1);
static void ov111_021D2B20(UnkStruct_ov111_021D0F7C *param0);
static BOOL ov111_021D2BBC(UnkStruct_ov111_021D0F7C *param0);
static BOOL ov111_021D2D14(UnkStruct_ov111_021D0F7C *param0);
static BOOL ov111_021D2D60(UnkStruct_ov111_021D0F7C *param0, u8 param1);
static void ov111_021D2E18(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D2E20(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D2E28(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D2E4C(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D2E8C(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D2EB4(UnkStruct_ov111_021D0F7C *param0);
static void ov111_021D2ECC(UnkStruct_ov111_021D0F7C *param0, int param1, int param2);
static void ov111_021D2F38(UnkStruct_ov111_021D0F7C *param0, u32 param1, u32 param2);

static const UnkStruct_ov111_021D3620 Unk_ov111_021D3620[3] = {
    { 0x34, 0x44 },
    { 0x6C, 0x44 },
    { 0xA4, 0x44 }
};

static const UnkStruct_ov111_021D3620 Unk_ov111_021D3608 = {
    0x26,
    0x38
};

static const UnkStruct_ov111_021D3620 Unk_ov111_021D3770[9] = {
    { 0x39, 0x12 },
    { 0x7C, 0x12 },
    { 0xBF, 0x12 },
    { 0x39, 0x42 },
    { 0x7C, 0x42 },
    { 0xBF, 0x42 },
    { 0x39, 0x72 },
    { 0x7C, 0x72 },
    { 0xBF, 0x72 }
};

static const UnkStruct_ov111_021D3620 Unk_ov111_021D362C[4] = {
    { 0x0, 0x24 },
    { 0x38, 0x24 },
    { 0x70, 0x24 },
    { 0xA8, 0x24 }
};

static const UnkStruct_ov111_021D3620 Unk_ov111_021D3604 = {
    0x44,
    0xA0
};

static const UnkStruct_ov111_021D3620 Unk_ov111_021D3600 = {
    0x58,
    0xA0
};

static const UnkStruct_ov111_021D3620 Unk_ov111_021D360C = {
    0x44,
    0x44
};

static const u16 Unk_ov111_021D37E4[] = {
    0xA9,
    0xAA,
    0xAB,
    0xAC,
    0xAD,
    0xAE,
    0xB8,
    0xB9,
    0xBA,
    0xBB,
    0xBC,
    0xBD,
    0xBE,
    0xBF,
    0xC0,
    0xC1,
    0xC2,
    0xC3,
    0xC4,
    0xC5,
    0xC6,
    0xC7,
    0xC8
};

static const TouchScreenRect Unk_ov111_021D364C[5] = {
    { 0x2A, 0x9A, 0x0, 0x50 },
    { 0x2A, 0x9A, 0x58, 0x8A },
    { 0x2A, 0x9A, 0x90, 0xC3 },
    { 0x2A, 0x9A, 0xCC, 0xFE },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const TouchScreenRect Unk_ov111_021D3618[] = {
    { 0xA4, 0xBF, 0x4C, 0xB4 },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const TouchScreenRect Unk_ov111_021D3610[] = {
    { 0xA4, 0xBF, 0x5E, 0xA4 },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const TouchScreenRect Unk_ov111_021D3794[] = {
    { 0x15, 0x36, 0x20, 0x59 },
    { 0x15, 0x36, 0x66, 0x9D },
    { 0x15, 0x36, 0xAA, 0xE3 },
    { 0x44, 0x64, 0x20, 0x59 },
    { 0x44, 0x64, 0x66, 0x9D },
    { 0x44, 0x64, 0xAA, 0xE3 },
    { 0x72, 0x94, 0x20, 0x59 },
    { 0x72, 0x94, 0x66, 0x9D },
    { 0x72, 0x94, 0xAA, 0xE3 },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static const UnkStruct_ov111_021D3728 Unk_ov111_021D3728[] = {
    { 0x15, 0x36, 0x20, 0x59 },
    { 0x15, 0x36, 0x66, 0x9D },
    { 0x15, 0x36, 0xAA, 0xE3 },
    { 0x44, 0x64, 0x20, 0x59 },
    { 0x44, 0x64, 0x66, 0x9D },
    { 0x44, 0x64, 0xAA, 0xE3 },
    { 0x72, 0x94, 0x20, 0x59 },
    { 0x72, 0x94, 0x66, 0x9D },
    { 0x72, 0x94, 0xAA, 0xE3 }
};

static const UnkStruct_ov111_021D3620 Unk_ov111_021D374C[9] = {
    { 0x2A, 0x1B },
    { 0x75, 0x1B },
    { 0xBD, 0x1B },
    { 0x2A, 0x4A },
    { 0x75, 0x4A },
    { 0xBD, 0x4A },
    { 0x2A, 0x78 },
    { 0x75, 0x78 },
    { 0xBD, 0x78 }
};

int ov111_021D0D80(ApplicationManager *appMan, int *param1)
{
    int v0;
    UnkStruct_ov111_021D0F7C *v1;
    UnkStruct_0203E608 *v2;

    ov111_021D1D30();
    Heap_Create(HEAP_ID_APPLICATION, HEAP_ID_115, 0x48000);

    v1 = ApplicationManager_NewData(appMan, sizeof(UnkStruct_ov111_021D0F7C), HEAP_ID_115);
    memset(v1, 0, sizeof(UnkStruct_ov111_021D0F7C));

    v1->unk_58 = BgConfig_New(HEAP_ID_115);
    v1->unk_00 = appMan;
    v2 = (UnkStruct_0203E608 *)ApplicationManager_Args(appMan);
    v1->saveData = v2->saveData;
    v1->unk_09 = v2->unk_04;
    v1->unk_3D8 = &v2->unk_14;
    v1->options = SaveData_GetOptions(v1->saveData);
    v1->unk_3DC = &v2->unk_08[0];
    v1->unk_3E0 = &v2->unk_0E[0];

    ov111_021D27BC(v1);

    for (v0 = 0; v0 < 3; v0++) {
        v1->unk_3DC[v0] = 0;
        v1->unk_3E0[v0] = 0;
    }

    v1->unk_409 = 0;

    ov111_021D1D68(v1);
    (*param1) = 0;
    Sound_SetSceneAndPlayBGM(SOUND_SCENE_SUB_68, SEQ_NONE, 0);

    return 1;
}

int ov111_021D0E34(ApplicationManager *appMan, int *param1)
{
    UnkStruct_ov111_021D0F7C *v0 = ApplicationManager_Data(appMan);

    switch (*param1) {
    case 0:
        if (ov111_021D0F7C(v0) == 1) {
            ov111_021D26E4(v0, param1, 1);
        }
        break;
    case 1:
        if (ov111_021D0FC8(v0) == 1) {
            ov111_021D26E4(v0, param1, 2);
        }
        break;
    case 2:
        if (ov111_021D10B8(v0) == 1) {
            ov111_021D26E4(v0, param1, 3);
        }
        break;
    case 3:
        if (ov111_021D116C(v0) == 1) {
            if (v0->unk_0E >= 3) {
                v0->unk_0E = 0;

                ov111_021D1BEC(v0);
                ov111_021D1AF4(v0);
                ov111_021D1B44(v0);
                ov111_021D26E4(v0, param1, 4);
            } else {
                ov111_021D26E4(v0, param1, 1);
            }
        }
        break;
    case 4:
        if (ov111_021D1284(v0) == 1) {
            ov111_021D26E4(v0, param1, 5);
        }
        break;
    case 5:
        if (ov111_021D1508(v0) == 1) {
            if (v0->unk_0E >= 3) {
                ov111_021D26E4(v0, param1, 7);
            } else {
                ov111_021D26E4(v0, param1, 6);
            }
        }
        break;
    case 6:
        if (ov111_021D1980(v0) == 1) {
            ov111_021D26E4(v0, param1, 4);
        }
        break;
    case 7:
        if (ov111_021D1A88(v0) == 1) {
            return 1;
        }
        break;
    }

    SpriteList_Update(v0->unk_16C.unk_00);

    return 0;
}

int ov111_021D0F40(ApplicationManager *appMan, int *param1)
{
    int v0;
    UnkStruct_ov111_021D0F7C *v1 = ApplicationManager_Data(appMan);

    DisableTouchPad();
    *(v1->unk_3D8) = v1->unk_0C;
    VramTransfer_Free();

    ov111_021D1C0C(v1);

    ApplicationManager_FreeData(appMan);
    SetVBlankCallback(NULL, NULL);
    Heap_Destroy(HEAP_ID_115);

    return 1;
}

static BOOL ov111_021D0F7C(UnkStruct_ov111_021D0F7C *param0)
{
    switch (param0->unk_08) {
    case 0:
        StartScreenFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, COLOR_BLACK, 6, 1 * 3, HEAP_ID_115);
        param0->unk_08++;
        break;
    case 1:
        if (IsScreenFadeDone() == TRUE) {
            param0->unk_0E = 0;
            return 1;
        }
        break;
    }

    return 0;
}

static BOOL ov111_021D0FC8(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;

    switch (param0->unk_08) {
    case 0:
        param0->unk_10 = -256;

        for (v0 = 0; v0 < 4; v0++) {
            ov111_021D3474(param0->unk_390[v0], Unk_ov111_021D362C[v0].unk_00 + param0->unk_10, Unk_ov111_021D362C[v0].unk_02);
            ov111_021D3468(param0->unk_390[v0], 20 + v0);
        }

        ov111_021D35C0(&param0->unk_5C[15], Options_Frame(param0->options));
        ov111_021D24D4(param0);
        GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, 1);
        param0->unk_12 = (4 - 1);
        Sound_PlayEffect(SEQ_SE_PL_SYU03);
        param0->unk_08 = 1;
        break;
    case 1:
        param0->unk_10 += 32;
        ov111_021D3474(param0->unk_390[param0->unk_12], Unk_ov111_021D362C[param0->unk_12].unk_00 + param0->unk_10, Unk_ov111_021D362C[param0->unk_12].unk_02);

        if (param0->unk_10 >= 0) {
            if (param0->unk_12 == 0) {
                param0->unk_08 = 2;
            } else {
                Sound_PlayEffect(SEQ_SE_PL_SYU03);
                param0->unk_12--;
                param0->unk_10 = -256;
            }
        }
        break;
    case 2:
        param0->unk_10 = 0;
        return 1;
    }

    return 0;
}

static BOOL ov111_021D10B8(UnkStruct_ov111_021D0F7C *param0)
{
    u32 v0, v1;
    int v2, v3;

    switch (param0->unk_08) {
    case 0:
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, 1);
        param0->unk_0F = 30;
        param0->unk_08 = 1;
        break;
    case 1:
        if (param0->unk_0F == 0) {
            GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, 0);
            ov111_021D345C(param0->unk_3A4, 0);
        } else {
            param0->unk_0F--;
        }

        v3 = TouchScreen_CheckRectangleHeld((const TouchScreenRect *)Unk_ov111_021D364C);

        if (v3 != 0xffffffff) {
            GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, 0);
            ov111_021D345C(param0->unk_3A4, 0);
            Sound_PlayEffect(SEQ_SE_DP_BUTTON9);

            param0->unk_15[param0->unk_0E] = v3;
            param0->unk_0E++;

            TouchScreen_GetHoldState(&v0, &v1);
            Window_EraseMessageBox(&param0->unk_5C[15], 0);
            GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, 0);
            param0->unk_08 = 2;
        }
        break;
    case 2:
        return 1;
    }

    return 0;
}

static BOOL ov111_021D116C(UnkStruct_ov111_021D0F7C *param0)
{
    int v0, v1, v2, v3;

    v1 = param0->unk_15[param0->unk_0E - 1];

    switch (param0->unk_08) {
    case 0:
        param0->unk_1C.x = 0x1000;
        param0->unk_1C.y = 0x1000;
        param0->unk_1C.z = 0x1000;
        param0->unk_10 = 0;
        param0->unk_40C_1 = 0;
        ov111_021D3468(param0->unk_390[v1], 0);
        param0->unk_08 = 1;
        break;
    case 1:
        if (ov111_021D2868(param0, v1) == 1) {
            (void)0;
        }

        param0->unk_1C.x += 0x100;
        param0->unk_1C.y += 0x100;
        param0->unk_1C.z += 0x100;
        param0->unk_10++;

        if ((param0->unk_10 % 1) == 0) {
            ov111_021D34F4(param0->unk_390[v1], &param0->unk_1C);
        }

        if (param0->unk_1C.x == 0x1800) {
            param0->unk_10 = 0;
            param0->unk_1C.x = 0x1000;
            param0->unk_1C.y = 0x1000;
            param0->unk_1C.z = 0x1000;
            Sound_PlayEffect(SEQ_SE_PL_SYU03);
            param0->unk_08 = 2;
        }
        break;
    case 2:
        param0->unk_10 += 16;

        for (v0 = 0; v0 < 4; v0++) {
            ov111_021D349C(param0->unk_390[v0], &v2, &v3);
            ov111_021D3474(param0->unk_390[v0], v2 + 16, v3);
        }

        if (param0->unk_10 >= 256) {
            ov111_021D34E0(param0->unk_390[v1], 0);
            param0->unk_08 = 3;
        }
        break;
    case 3:
        param0->unk_10 = 0;
        return 1;
    }

    return 0;
}

static BOOL ov111_021D1284(UnkStruct_ov111_021D0F7C *param0)
{
    int v0, v1;

    switch (param0->unk_08) {
    case 0:
        ov111_021D2EB4(param0);

        Bg_LoadTiles(param0->unk_58, 0, param0->unk_3F8, param0->unk_3F4->szByte, 0);
        Bg_CopyTilemapBufferToVRAM(param0->unk_58, 0);

        param0->unk_12 = 256;

        Bg_SetOffset(param0->unk_58, BG_LAYER_SUB_2, 0, param0->unk_12);
        Bg_SetOffset(param0->unk_58, BG_LAYER_MAIN_0, 0, param0->unk_12);
        Bg_SetOffset(param0->unk_58, BG_LAYER_MAIN_1, 0, param0->unk_12);

        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0, 1);
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG1, 1);
        GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG2, 1);

        param0->unk_10 = -256;
        param0->unk_19[param0->unk_0E] = 0;

        for (v0 = 0; v0 < (240 * 160); v0++) {
            param0->unk_466[v0] = 0;
        }

        param0->unk_40D = 0;

        ov111_021D27BC(param0);
        ov111_021D27AC(param0, param0->unk_19[param0->unk_0E]);
        ov111_021D27D4(param0, param0->unk_19[param0->unk_0E]);
        ov111_021D2940(param0);
        ov111_021D295C(param0);

        param0->unk_08 = 1;
        break;
    case 1:

        for (v0 = 0; v0 < 4; v0++) {
            ov111_021D3474(param0->unk_35C[v0], 60 + param0->unk_10, 26 + (v0 * 42));
            ov111_021D345C(param0->unk_35C[v0], 1);
        }

        for (v0 = 0; v0 < 3; v0++) {
            ov111_021D3500(param0->unk_3A8[v0], 1);
        }

        param0->unk_409 = 0;
        param0->unk_40C_0 = 0;
        param0->unk_40E[0] = 177;
        param0->unk_40E[1] = 178;
        param0->unk_40E[2] = 179;

        for (v0 = 0; v0 < 9; v0++) {
            ov111_021D3474(param0->unk_36C[v0], Unk_ov111_021D3770[v0].unk_00 + param0->unk_10, Unk_ov111_021D3770[v0].unk_02);
            ov111_021D345C(param0->unk_36C[v0], 1);
            ov111_021D34C4(param0->unk_36C[v0], param0->unk_3C4[v0]);
        }

        ov111_021D28E8(param0, 1, param0->unk_15[param0->unk_0E] + 4, 32, 24);
        ov111_021D28E8(param0, 6, param0->unk_15[param0->unk_0E] + 1, 32, 24);
        Sound_PlayEffect(SEQ_SE_PL_SYU03);
        param0->unk_08 = 2;
        break;
    case 2:
        Bg_SetOffset(param0->unk_58, BG_LAYER_SUB_2, 0, param0->unk_12);
        Bg_SetOffset(param0->unk_58, BG_LAYER_MAIN_0, 0, param0->unk_12);
        Bg_SetOffset(param0->unk_58, BG_LAYER_MAIN_1, 0, param0->unk_12);

        param0->unk_12 += -16;

        if (param0->unk_10 >= 0) {
            param0->unk_08 = 3;
        } else {
            for (v0 = 0; v0 < 4; v0++) {
                ov111_021D3474(param0->unk_35C[v0], 60 + param0->unk_10, 26 + (v0 * 42));
            }

            for (v0 = 0; v0 < 9; v0++) {
                ov111_021D3474(param0->unk_36C[v0], Unk_ov111_021D3770[v0].unk_00 + param0->unk_10, Unk_ov111_021D3770[v0].unk_02);
            }
        }

        param0->unk_10 += 16;
        break;
    case 3:
        param0->unk_10 = 0;
        param0->unk_12 = 0;
        return 1;
    }

    return 0;
}

static BOOL ov111_021D1508(UnkStruct_ov111_021D0F7C *param0)
{
    int v0, v1;
    u32 v2, v3;

    switch (param0->unk_08) {
    case 0:
        if (param0->unk_0E == (3 - 1)) {
            Window_ClearAndCopyToVRAM(&param0->unk_5C[13]);
            ov111_021D263C(param0);
            ov111_021D3474(param0->unk_3A0, Unk_ov111_021D3600.unk_00, Unk_ov111_021D3600.unk_02);
            ov111_021D34C4(param0->unk_3A0, 0);
        } else {
            Window_ClearAndCopyToVRAM(&param0->unk_5C[14]);
            ov111_021D2604(param0);
        }

        param0->unk_0F = 30;

        ov111_021D345C(param0->unk_3A4, 1);
        ov111_021D2518(param0);

        for (v0 = 0; v0 < 4; v0++) {
            ov111_021D2674(param0, v0);
        }

        ov111_021D345C(param0->unk_3A0, 1);
        ov111_021D350C(param0->unk_3A0, 0);
        Sound_PlayEffect(SEQ_SE_PL_UG_020);
        param0->unk_08 = 1;
        break;
    case 1:
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, 1);
        GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, 1);
        param0->unk_08 = 2;
        break;
    case 2:
        if (param0->unk_0F == 0) {
            ov111_021D345C(param0->unk_3A4, 0);
            Window_FillTilemap(&param0->unk_5C[10], 0);
            Window_ScheduleCopyToVRAM(&param0->unk_5C[10]);
            param0->unk_08 = 3;
        } else {
            param0->unk_0F--;
        }
        break;
    case 3:
        WriteAutoSamplingDataToBuffer(&param0->unk_424, TOUCH_PAD_EXTERNAL_BUFFER_WRITE_METHOD_ALL_DATA_WITHOUT_WRAPPING, 2);
        v1 = TouchScreen_CheckRectangleHeld((const TouchScreenRect *)Unk_ov111_021D3794);

        if (v1 != 0xffffffff) {
            if (ov111_021D2918(param0) < 3) {
                param0->unk_400[v1] = 1;
            }

            if (param0->unk_400[v1] == 1) {
                ov111_021D29D8(param0);
                ov111_021D2A68(param0, v1);
                ov111_021D297C(param0, v1);

                if (Sound_IsEffectPlaying(1358) == 0) {
                    Sound_PlayEffect(SEQ_SE_PL_KEZURI);
                }
            }

            if (ov111_021D2BBC(param0) == 1) {
                Sound_StopEffect(1358, 0);
                ov111_021D345C(param0->unk_3A4, 1);

                param0->unk_3DC[param0->unk_0E] = param0->unk_3CE[param0->unk_40B];

                if (param0->unk_3CE[param0->unk_40B] == 92) {
                    param0->unk_3E0[param0->unk_0E] = 1;
                } else {
                    param0->unk_3E0[param0->unk_0E] = 3;
                }

                if (ov111_021D2D14(param0) == 1) {
                    param0->unk_0F = 30;
                } else {
                    param0->unk_0F = 0;
                }

                ov111_021D255C(param0);
                param0->unk_08 = 4;
                return 0;
            }

            if (param0->unk_40D >= 3) {
                Sound_StopEffect(1358, 0);
                param0->unk_0F = 60;
                ov111_021D345C(param0->unk_3A4, 1);
                ov111_021D25BC(param0);
                param0->unk_08 = 7;
                return 0;
            }
        } else {
            Sound_StopEffect(1358, 0);
        }

        if (param0->unk_40C_0 == 1) {
            ov111_021D2B20(param0);
        }

        if (param0->unk_0E == (3 - 1)) {
            v1 = TouchScreen_CheckRectanglePressed((const TouchScreenRect *)Unk_ov111_021D3610);

            if (v1 != 0xffffffff) {
                ov111_021D350C(param0->unk_3A0, 1);
                ov111_021D2494(param0);

                Sound_PlayEffect(SEQ_SE_DP_BUTTON9);

                ov111_021D34C4(param0->unk_3A0, 0);
                ov111_021D1F70(param0);
                ov111_021D1F84(param0);
                param0->unk_08 = 10;
                break;
            }
        } else {
            v1 = TouchScreen_CheckRectanglePressed((const TouchScreenRect *)Unk_ov111_021D3618);

            if (v1 != 0xffffffff) {
                ov111_021D350C(param0->unk_3A0, 1);
                ov111_021D2494(param0);

                Sound_PlayEffect(SEQ_SE_DP_BUTTON9);

                ov111_021D34C4(param0->unk_3A0, 1);
                ov111_021D1F70(param0);
                ov111_021D1F84(param0);
                param0->unk_08 = 9;
                break;
            }
        }
        break;
    case 4:
        if (param0->unk_0F == 0) {
            if (ov111_021D2D60(param0, 0) == 0) {
                param0->unk_08 = 5;
            }
        } else {
            param0->unk_0F--;
        }
        break;
    case 5:
        if (ov111_021D2D60(param0, 1) == 0) {
            param0->unk_0F = 0;
            param0->unk_08 = 6;
        }
        break;
    case 6:
        if (ov111_021D353C(param0->unk_3C0) == 1) {
            break;
        }

        if (param0->unk_0F == 0) {
            for (v0 = 0; v0 < 3; v0++) {
                ov111_021D345C(param0->unk_3B4[v0], 0);
            }

            ov111_021D345C(param0->unk_3C0, 0);
            ov111_021D2E20(param0);
            ov111_021D2E28(param0);
            return 1;
        } else {
            param0->unk_0F--;
        }
        break;
    case 7:
        if (param0->unk_0F == 0) {
            GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0, 0);
            ov111_021D2E20(param0);
            ov111_021D2E28(param0);
            param0->unk_0F = 30;
            param0->unk_08 = 8;
        } else {
            param0->unk_0F--;
        }
        break;
    case 8:
        if (param0->unk_0F == 0) {
            return 1;
        } else {
            param0->unk_0F--;
        }
        break;
    case 9:
        v2 = sub_020159C0(param0->unk_3FC);

        if (v2 == 1) {
            ov111_021D350C(param0->unk_3A0, 0);
            Window_EraseStandardFrame(&param0->unk_5C[0], 0);
            Window_ClearAndCopyToVRAM(&param0->unk_5C[0]);
            ov111_021D2E20(param0);
            ov111_021D1FB4(param0);
            return 1;
        } else if (v2 == 2) {
            ov111_021D350C(param0->unk_3A0, 0);
            Window_EraseStandardFrame(&param0->unk_5C[0], 0);
            Window_ClearAndCopyToVRAM(&param0->unk_5C[0]);
            ov111_021D1FB4(param0);
            param0->unk_08 = 11;
        }
        break;
    case 10:
        v2 = sub_020159C0(param0->unk_3FC);

        if (v2 == 1) {
            ov111_021D350C(param0->unk_3A0, 0);
            Window_EraseStandardFrame(&param0->unk_5C[0], 0);
            Window_ClearAndCopyToVRAM(&param0->unk_5C[0]);
            ov111_021D2E18(param0);
            ov111_021D1FB4(param0);
            return 1;
        } else if (v2 == 2) {
            ov111_021D350C(param0->unk_3A0, 0);
            Window_EraseStandardFrame(&param0->unk_5C[0], 0);
            Window_ClearAndCopyToVRAM(&param0->unk_5C[0]);
            ov111_021D1FB4(param0);
            param0->unk_08 = 11;
        }
        break;
    case 11:
        if (TouchScreen_Touched() == 0) {
            param0->unk_08 = 3;
        }
        break;
    }

    return 0;
}

static BOOL ov111_021D1980(UnkStruct_ov111_021D0F7C *param0)
{
    int v0, v1;

    v1 = param0->unk_15[param0->unk_0E - 1];

    switch (param0->unk_08) {
    case 0:
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, 0);
        GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, 0);
        ov111_021D345C(param0->unk_3A0, 0);

        param0->unk_10 = 0;
        param0->unk_12 = 0;

        Sound_PlayEffect(SEQ_SE_PL_SYU03);

        param0->unk_08 = 1;
        break;

    case 1:
        Bg_SetOffset(param0->unk_58, BG_LAYER_SUB_2, 0, param0->unk_12);
        Bg_SetOffset(param0->unk_58, BG_LAYER_MAIN_0, 0, param0->unk_12);
        Bg_SetOffset(param0->unk_58, BG_LAYER_MAIN_1, 0, param0->unk_12);
        param0->unk_12 += -16;

        if (param0->unk_10 >= 256) {
            param0->unk_08 = 2;
        } else {
            for (v0 = 0; v0 < 4; v0++) {
                ov111_021D3474(param0->unk_35C[v0], 60 + param0->unk_10, 26 + (v0 * 42));
            }

            for (v0 = 0; v0 < 3; v0++) {
                ov111_021D345C(param0->unk_3A8[v0], 0);
            }

            for (v0 = 0; v0 < 9; v0++) {
                ov111_021D3474(param0->unk_36C[v0], Unk_ov111_021D3770[v0].unk_00 + param0->unk_10, Unk_ov111_021D3770[v0].unk_02);
            }
        }

        param0->unk_10 += 16;
        break;

    case 2:
        param0->unk_10 = 0;
        param0->unk_12 = 0;
        return 1;
    }

    return 0;
}

static BOOL ov111_021D1A88(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;

    switch (param0->unk_08) {
    case 0:
        param0->unk_0D = 10;
        param0->unk_08++;
        break;
    case 1:
        param0->unk_0D--;

        if (param0->unk_0D == 0) {
            Window_EraseMessageBox(&param0->unk_5C[0], 0);
            StartScreenFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, COLOR_BLACK, 6, 1, HEAP_ID_115);
            param0->unk_08++;
        }
        break;
    case 2:
        if (IsScreenFadeDone() == TRUE) {
            return 1;
        }
        break;
    }

    return 0;
}

static void ov111_021D1AF4(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;

    for (v0 = 0; v0 < 3; v0++) {
        param0->unk_3A8[v0] = ov111_021D33F4(&param0->unk_16C, 3, 2, Unk_ov111_021D3770[v0].unk_00, Unk_ov111_021D3770[v0].unk_02, 0, 2, 10 + 1);

        ov111_021D345C(param0->unk_3A8[v0], 0);
    }

    return;
}

static void ov111_021D1B44(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;

    for (v0 = 0; v0 < 3; v0++) {
        param0->unk_3B4[v0] = ov111_021D33F4(&param0->unk_16C, 1, 0, Unk_ov111_021D3620[v0].unk_00, Unk_ov111_021D3620[v0].unk_02, 0, 0, 0);
        ov111_021D345C(param0->unk_3B4[v0], 0);
    }

    return;
}

static void ov111_021D1B90(UnkStruct_ov111_021D0F7C *param0)
{
    param0->unk_3A0 = ov111_021D33F4(&param0->unk_16C, 3, 1, Unk_ov111_021D3604.unk_00, Unk_ov111_021D3604.unk_02, 0, 1, 0);
    ov111_021D345C(param0->unk_3A0, 0);

    param0->unk_3A4 = ov111_021D33F4(&param0->unk_16C, 3, 3, Unk_ov111_021D360C.unk_00, Unk_ov111_021D360C.unk_02, 0, 1, 0);
    ov111_021D345C(param0->unk_3A4, 0);

    return;
}

static void ov111_021D1BEC(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;

    for (v0 = 0; v0 < 4; v0++) {
        if (param0->unk_390[v0] != NULL) {
            ov111_021D3448(param0->unk_390[v0]);
        }
    }

    return;
}

static void ov111_021D1C0C(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;

    for (v0 = 0; v0 < 4; v0++) {
        if (param0->unk_35C[v0] != NULL) {
            ov111_021D3448(param0->unk_35C[v0]);
        }
    }

    for (v0 = 0; v0 < 9; v0++) {
        if (param0->unk_36C[v0] != NULL) {
            ov111_021D3448(param0->unk_36C[v0]);
        }
    }

    if (param0->unk_3A0 != NULL) {
        ov111_021D3448(param0->unk_3A0);
    }

    if (param0->unk_3A4 != NULL) {
        ov111_021D3448(param0->unk_3A4);
    }

    for (v0 = 0; v0 < 3; v0++) {
        if (param0->unk_3A8[v0] != NULL) {
            ov111_021D3448(param0->unk_3A8[v0]);
        }
    }

    for (v0 = 0; v0 < 3; v0++) {
        if (param0->unk_3B4[v0] != NULL) {
            ov111_021D3448(param0->unk_3B4[v0]);
        }
    }

    if (param0->unk_3C0 != NULL) {
        ov111_021D3448(param0->unk_3C0);
    }

    Font_Free(FONT_SUBSCREEN);
    PaletteData_FreeBuffer(param0->unk_15C, 2);
    PaletteData_FreeBuffer(param0->unk_15C, 0);
    PaletteData_Free(param0->unk_15C);

    param0->unk_15C = NULL;

    ov111_021D3320(&param0->unk_16C);

    sub_02015760(param0->unk_34);
    MessageLoader_Free(param0->unk_38);
    StringTemplate_Free(param0->unk_3C);
    Strbuf_Free(param0->unk_40);
    Strbuf_Free(param0->unk_44);
    FontSpecialChars_Free(param0->unk_160);
    Heap_Free(param0->unk_3F0);
    Heap_Free(param0->unk_3F8);

    ov111_021D3578(param0->unk_5C);
    ov111_021D2044(param0->unk_58);

    NARC_dtor(param0->unk_3E4);
    return;
}

static void ov111_021D1D30(void)
{
    SetVBlankCallback(NULL, NULL);
    SetHBlankCallback(NULL, NULL);
    GXLayers_DisableEngineALayers();
    GXLayers_DisableEngineBLayers();

    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);

    return;
}

static void ov111_021D1D68(UnkStruct_ov111_021D0F7C *param0)
{
    int v0, v1;

    param0->unk_3E4 = NARC_ctor(NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, HEAP_ID_115);

    ov111_021D1FC4(param0);
    ov111_021D2034(param0);

    param0->unk_38 = MessageLoader_Init(MESSAGE_LOADER_NARC_HANDLE, NARC_INDEX_MSGDATA__PL_MSG, TEXT_BANK_UNK_0540, HEAP_ID_115);
    param0->unk_3C = StringTemplate_Default(HEAP_ID_115);
    param0->unk_40 = Strbuf_Init(600, HEAP_ID_115);
    param0->unk_44 = Strbuf_Init(600, HEAP_ID_115);

    Font_LoadTextPalette(0, 13 * 32, HEAP_ID_115);
    Font_LoadTextPalette(4, 13 * 32, HEAP_ID_115);
    Font_LoadScreenIndicatorsPalette(0, 12 * 32, HEAP_ID_115);
    Font_LoadScreenIndicatorsPalette(4, 12 * 32, HEAP_ID_115);
    Font_InitManager(FONT_SUBSCREEN, HEAP_ID_115);

    param0->unk_160 = FontSpecialChars_Init(15, 14, 0, HEAP_ID_115);
    ov111_021D3548(param0->unk_58, param0->unk_5C);
    param0->unk_34 = sub_0201567C(NULL, 1, 12, HEAP_ID_115);

    ov111_021D2E4C(param0);
    ov111_021D2E8C(param0);
    ov111_021D2EB4(param0);

    GXLayers_TurnBothDispOn();

    for (v0 = 0; v0 < 4; v0++) {
        param0->unk_35C[v0] = ov111_021D33F4(&param0->unk_16C, 0, 0 + v0, 60, 26 + (v0 * 42), 1, 0, 0);
        ov111_021D345C(param0->unk_35C[v0], 0);
    }

    for (v0 = 0; v0 < 9; v0++) {
        param0->unk_36C[v0] = ov111_021D33F4(&param0->unk_16C, 1, 0, Unk_ov111_021D3770[v0].unk_00, Unk_ov111_021D3770[v0].unk_02, 0, 2, 10);
        ov111_021D345C(param0->unk_36C[v0], 0);
    }

    ov111_021D1B90(param0);

    for (v0 = 0; v0 < 4; v0++) {
        param0->unk_390[v0] = ov111_021D33F4(&param0->unk_16C, 2, 0 + v0, Unk_ov111_021D362C[v0].unk_00, Unk_ov111_021D362C[v0].unk_02, 0, 1, 0);

        ov111_021D3474(param0->unk_390[v0], Unk_ov111_021D362C[v0].unk_00 + -256, Unk_ov111_021D362C[v0].unk_02);
        ov111_021D3468(param0->unk_390[v0], 20 + v0);
    }

    param0->unk_3C0 = ov111_021D33F4(&param0->unk_16C, 4, 0, Unk_ov111_021D3608.unk_00, Unk_ov111_021D3608.unk_02, 0, 0, 10);
    ov111_021D345C(param0->unk_3C0, 0);

    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);

    EnableTouchPad();
    InitializeTouchPad(1);
    SetVBlankCallback(ov111_021D2090, (void *)param0);

    return;
}

static void ov111_021D1F70(UnkStruct_ov111_021D0F7C *param0)
{
    param0->unk_3FC = sub_02015920(HEAP_ID_115);
    return;
}

static void ov111_021D1F84(UnkStruct_ov111_021D0F7C *param0)
{
    UnkStruct_02015958 v0;

    v0.unk_00 = param0->unk_58;
    v0.unk_04 = 2;
    v0.unk_08 = (1024 - 128);
    v0.unk_0C = 10;
    v0.unk_10 = 24;
    v0.unk_11 = 8;

    sub_02015958(param0->unk_3FC, &v0);

    return;
}

static void ov111_021D1FB4(UnkStruct_ov111_021D0F7C *param0)
{
    sub_02015938(param0->unk_3FC);
    return;
}

static void ov111_021D1FC4(UnkStruct_ov111_021D0F7C *param0)
{
    ov111_021D20CC();
    ov111_021D20EC(param0->unk_58);

    param0->unk_15C = PaletteData_New(HEAP_ID_115);

    PaletteData_AllocBuffer(param0->unk_15C, 2, 32 * 16, HEAP_ID_115);
    PaletteData_AllocBuffer(param0->unk_15C, 0, 32 * 16, HEAP_ID_115);

    ov111_021D2248(param0, 7);
    ov111_021D22D0();
    ov111_021D228C(param0, 6);
    ov111_021D233C(param0, 1);
    ov111_021D2304();
    ov111_021D2380(param0, 0);

    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, 0);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, 0);

    return;
}

static void ov111_021D2034(UnkStruct_ov111_021D0F7C *param0)
{
    ov111_021D2F80(&param0->unk_16C);
    return;
}

static void ov111_021D2044(BgConfig *param0)
{
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ, 0);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ, 0);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_SUB_3);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_SUB_2);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_SUB_0);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_MAIN_1);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_MAIN_0);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_MAIN_2);
    Heap_Free(param0);

    return;
}

static void ov111_021D2090(void *param0)
{
    UnkStruct_ov111_021D0F7C *v0 = param0;

    if (v0->unk_04 != NULL) {
        return;
    }

    if (v0->unk_15C != NULL) {
        PaletteData_CommitFadedBuffers(v0->unk_15C);
    }

    Bg_RunScheduledUpdates(v0->unk_58);
    VramTransfer_Process();
    RenderOam_Transfer();

    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void ov111_021D20CC(void)
{
    UnkStruct_02099F80 v0 = {
        GX_VRAM_BG_128_A,
        GX_VRAM_BGEXTPLTT_NONE,
        GX_VRAM_SUB_BG_128_C,
        GX_VRAM_SUB_BGEXTPLTT_NONE,
        GX_VRAM_OBJ_128_B,
        GX_VRAM_OBJEXTPLTT_NONE,
        GX_VRAM_SUB_OBJ_16_I,
        GX_VRAM_SUB_OBJEXTPLTT_NONE,
        GX_VRAM_TEX_NONE,
        GX_VRAM_TEXPLTT_NONE
    };

    GXLayers_SetBanks(&v0);
    return;
}

static void ov111_021D20EC(BgConfig *param0)
{
    {
        GraphicsModes v0 = {
            GX_DISPMODE_GRAPHICS,
            GX_BGMODE_0,
            GX_BGMODE_0,
            GX_BG0_AS_2D,
        };

        SetAllGraphicsModes(&v0);
    }

    {
        BgTemplate v1 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x1000,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0000,
            .charBase = GX_BG_CHARBASE_0x04000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_SUB_0, &v1, 0);
        Bg_ClearTilesRange(4, 32, 0, HEAP_ID_115);
        Bg_ClearTilemap(param0, BG_LAYER_SUB_0);
    }

    {
        BgTemplate v2 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x1000,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x1000,
            .charBase = GX_BG_CHARBASE_0x0c000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 3,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_SUB_3, &v2, 0);
        Bg_ClearTilemap(param0, BG_LAYER_SUB_3);
    }

    {
        BgTemplate v3 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x1000,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_512x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x3000,
            .charBase = GX_BG_CHARBASE_0x14000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 2,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_SUB_2, &v3, 0);
        Bg_ClearTilemap(param0, BG_LAYER_SUB_2);
    }

    {
        BgTemplate v4 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x1000,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_512x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x0000,
            .charBase = GX_BG_CHARBASE_0x04000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 2,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_MAIN_1, &v4, 0);
        Bg_ClearTilemap(param0, BG_LAYER_MAIN_1);
    }

    {
        BgTemplate v5 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x1000,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_512x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x1000,
            .charBase = GX_BG_CHARBASE_0x0c000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_MAIN_0, &v5, 0);
        Bg_ClearTilemap(param0, BG_LAYER_MAIN_0);
    }

    {
        BgTemplate v6 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x2000,
            .charBase = GX_BG_CHARBASE_0x14000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_MAIN_2, &v6, 0);
        Bg_ClearTilesRange(BG_LAYER_MAIN_2, 32, 0, HEAP_ID_115);
        Bg_ClearTilemap(param0, BG_LAYER_MAIN_2);
    }

    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0, 0);
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG1, 0);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG2, 0);

    return;
}

static void ov111_021D2248(UnkStruct_ov111_021D0F7C *param0, u32 param1)
{
    Graphics_LoadTilesToBgLayerFromOpenNARC(param0->unk_3E4, 35, param0->unk_58, param1, 0, 0, 0, HEAP_ID_115);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(param0->unk_3E4, 37, param0->unk_58, param1, 0, 0, 0, HEAP_ID_115);

    return;
}

static void ov111_021D228C(UnkStruct_ov111_021D0F7C *param0, u32 param1)
{
    Graphics_LoadTilesToBgLayerFromOpenNARC(param0->unk_3E4, 38, param0->unk_58, param1, 0, 0, 0, HEAP_ID_115);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(param0->unk_3E4, 40, param0->unk_58, param1, 0, 0, 0, HEAP_ID_115);

    return;
}

static void ov111_021D22D0(void)
{
    void *v0;
    NNSG2dPaletteData *v1;

    v0 = Graphics_GetPlttData(NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, 34, &v1, HEAP_ID_115);

    DC_FlushRange(v1->pRawData, sizeof(u16) * 16 * 5);
    GXS_LoadBGPltt(v1->pRawData, 0, sizeof(u16) * 16 * 5);
    Heap_Free(v0);

    return;
}

static void ov111_021D2304(void)
{
    void *v0;
    NNSG2dPaletteData *v1;

    v0 = Graphics_GetPlttData(NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, 0, &v1, HEAP_ID_115);

    DC_FlushRange(v1->pRawData, sizeof(u16) * 16 * 9);
    GX_LoadBGPltt(v1->pRawData, 0, sizeof(u16) * 16 * 10);
    Heap_Free(v0);

    return;
}

static void ov111_021D233C(UnkStruct_ov111_021D0F7C *param0, u32 param1)
{
    Graphics_LoadTilesToBgLayerFromOpenNARC(param0->unk_3E4, 4, param0->unk_58, param1, 0, 0, 0, HEAP_ID_115);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(param0->unk_3E4, 6, param0->unk_58, param1, 0, 0, 0, HEAP_ID_115);

    return;
}

static void ov111_021D2380(UnkStruct_ov111_021D0F7C *param0, u32 param1)
{
    Graphics_LoadTilesToBgLayerFromOpenNARC(param0->unk_3E4, 7, param0->unk_58, param1, 0, 0, 0, HEAP_ID_115);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(param0->unk_3E4, 9, param0->unk_58, param1, 0, 0, 0, HEAP_ID_115);

    return;
}

static u8 ov111_021D23C4(UnkStruct_ov111_021D0F7C *param0, Window *param1, int param2, u32 param3, u32 param4, u32 param5, u8 param6, u8 param7, u8 param8, u8 param9)
{
    Window_FillTilemap(param1, param8);
    MessageLoader_GetStrbuf(param0->unk_38, param2, param0->unk_44);
    StringTemplate_Format(param0->unk_3C, param0->unk_40, param0->unk_44);

    return Text_AddPrinterWithParamsAndColor(param1, param9, param0->unk_40, param3, param4, param5, TEXT_COLOR(param6, param7, param8), NULL);
}

static u8 ov111_021D2424(UnkStruct_ov111_021D0F7C *param0, Window *param1, int param2, u32 param3, u32 param4, u32 param5, u8 param6, u8 param7, u8 param8, u8 param9)
{
    Window_FillTilemap(param1, param8);
    MessageLoader_GetStrbuf(param0->unk_38, param2, param0->unk_44);
    StringTemplate_Format(param0->unk_3C, param0->unk_40, param0->unk_44);
    param3 -= (Font_CalcStrbufWidth(param9, param0->unk_40, 0) + 1) / 2;
    return Text_AddPrinterWithParamsAndColor(param1, param9, param0->unk_40, param3, param4, param5, TEXT_COLOR(param6, param7, param8), NULL);
}

static u8 ov111_021D2494(UnkStruct_ov111_021D0F7C *param0)
{
    u8 v0;

    ov111_021D3594(param0->unk_58, &param0->unk_5C[0]);
    v0 = ov111_021D23C4(param0, &param0->unk_5C[0], 6, 1, 1, TEXT_SPEED_INSTANT, 1, 2, 15, FONT_SYSTEM);
    Window_ScheduleCopyToVRAM(&param0->unk_5C[0]);

    return v0;
}

static u8 ov111_021D24D4(UnkStruct_ov111_021D0F7C *param0)
{
    u8 v0;

    ov111_021D26CC(param0, 0, param0->unk_0E + 1);
    v0 = ov111_021D23C4(param0, &param0->unk_5C[15], 12, 1, 1, TEXT_SPEED_INSTANT, 1, 2, 15, FONT_MESSAGE);
    Window_ScheduleCopyToVRAM(&param0->unk_5C[15]);

    return v0;
}

static u8 ov111_021D2518(UnkStruct_ov111_021D0F7C *param0)
{
    u8 v0;

    ov111_021D26CC(param0, 0, param0->unk_0E + 1);
    v0 = ov111_021D2424(param0, &param0->unk_5C[10], 9, 8 * 6, 1 + 4, TEXT_SPEED_INSTANT, 1, 2, 0, FONT_SYSTEM);
    Window_ScheduleCopyToVRAM(&param0->unk_5C[10]);

    return v0;
}

static u8 ov111_021D255C(UnkStruct_ov111_021D0F7C *param0)
{
    u8 v0 = 0, v1;

    for (v1 = 0; v1 < 3; v1++) {
        ov111_021D34C4(param0->unk_3B4[v1], param0->unk_3C4[param0->unk_40E[v1]]);
        ov111_021D345C(param0->unk_3B4[v1], 1);
    }

    ov111_021D345C(param0->unk_3C0, 1);
    ov111_021D350C(param0->unk_3C0, 1);

    Sound_PlayEffect(SEQ_SE_PL_CALL);

    return v0;
}

static u8 ov111_021D25BC(UnkStruct_ov111_021D0F7C *param0)
{
    u8 v0;

    Sound_PlayEffect(SEQ_SE_DP_BOX03);
    v0 = ov111_021D2424(param0, &param0->unk_5C[12], 11, 8 * 6, 1 + 4, TEXT_SPEED_INSTANT, 1, 2, 0, FONT_SYSTEM);
    Window_ScheduleCopyToVRAM(&param0->unk_5C[12]);

    return v0;
}

static u8 ov111_021D2604(UnkStruct_ov111_021D0F7C *param0)
{
    u8 v0 = ov111_021D2424(param0, &param0->unk_5C[13], 4, 8 * 6, 1, TEXT_SPEED_INSTANT, 1, 1, 0, FONT_SUBSCREEN);
    Window_ScheduleCopyToVRAM(&param0->unk_5C[13]);

    return v0;
}

static u8 ov111_021D263C(UnkStruct_ov111_021D0F7C *param0)
{
    u8 v0 = ov111_021D2424(param0, &param0->unk_5C[14], 5, 8 * 3, 1, TEXT_SPEED_INSTANT, 1, 1, 0, FONT_SUBSCREEN);
    Window_ScheduleCopyToVRAM(&param0->unk_5C[14]);

    return v0;
}

static const u8 Unk_ov111_021D3814[4] = {
    0xA,
    0xC,
    0x6,
    0x8
};

static u8 ov111_021D2674(UnkStruct_ov111_021D0F7C *param0, u8 param1)
{
    u8 v0;

    StringTemplate_SetItemName(param0->unk_3C, 0, param0->unk_3CE[param1]);
    v0 = ov111_021D2424(param0, &param0->unk_5C[2 + param1], 1, 8 * 6 - 4, Unk_ov111_021D3814[param1], TEXT_SPEED_INSTANT, 1, 2, 0, FONT_SYSTEM);
    Window_ScheduleCopyToVRAM(&param0->unk_5C[2 + param1]);

    return v0;
}

static void ov111_021D26CC(UnkStruct_ov111_021D0F7C *param0, u32 param1, s32 param2)
{
    StringTemplate_SetNumber(param0->unk_3C, param1, param2, 1, 0, 1);
    return;
}

static void ov111_021D26E4(UnkStruct_ov111_021D0F7C *param0, int *param1, int param2)
{
    param0->unk_08 = 0;
    *param1 = param2;

    return;
}

static void ov111_021D26EC(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;
    u8 v1;

    for (v0 = 0; v0 < 2; v0++) {
        while (TRUE) {
            v1 = (LCRNG_Next() % 9);

            if (param0->unk_3C4[v1] == 176) {
                param0->unk_3C4[v1] = 4;
                break;
            }
        }
    }

    return;
}

static void ov111_021D271C(UnkStruct_ov111_021D0F7C *param0)
{
    int v0, v1, v2, v3, v4;
    u8 v5 = (LCRNG_Next() % 4);
    v3 = 0;

    for (v0 = 0; v0 < 9; v0++) {
        while (TRUE) {
            v4 = (LCRNG_Next() % 9);

            if (param0->unk_3C4[v4] == 176) {
                v3 = 0;
                param0->unk_3C4[v4] = v5;

                if ((v0 == 2) || (v0 == 4) || (v0 == 6)) {
                    v5++;

                    if (v5 == (5 - 1)) {
                        v5 = 0;
                    }
                }
                break;
            }

            v3++;

            if (v3 >= 30) {
                v3 = 0;

                for (v2 = 0; v2 < 9; v2++) {
                    if (param0->unk_3C4[v2] == 176) {
                        param0->unk_3C4[v2] = v5;

                        if ((v0 == 2) || (v0 == 4) || (v0 == 6)) {
                            v5++;

                            if (v5 == (5 - 1)) {
                                v5 = 0;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }

    for (v0 = 0; v0 < 9; v0++) {
        (void)0;
    }

    return;
}

static void ov111_021D27AC(UnkStruct_ov111_021D0F7C *param0, u8 param1)
{
    ov111_021D26EC(param0);
    ov111_021D271C(param0);

    return;
}

static void ov111_021D27BC(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;

    for (v0 = 0; v0 < 9; v0++) {
        param0->unk_3C4[v0] = 176;
    }

    return;
}

static void ov111_021D27D4(UnkStruct_ov111_021D0F7C *param0, u8 param1)
{
    int v0, v1;
    u16 v2[4];
    u16 v3;

    for (v0 = 0; v0 < 4; v0++) {
        v2[v0] = 0xff;
    }

    v3 = (LCRNG_Next() % 4);

    for (v0 = 0; v0 < 4; v0++) {
        if (v0 == v3) {
            param0->unk_3CE[v0] = 92;
        } else {
            while (TRUE) {
                v2[v0] = (LCRNG_Next() % (NELEMS(Unk_ov111_021D37E4)));

                for (v1 = 0; v1 < v0; v1++) {
                    if (v2[v1] == v2[v0]) {
                        break;
                    }
                }

                if (v1 == v0) {
                    param0->unk_3CE[v0] = Unk_ov111_021D37E4[v2[v0]];
                    break;
                }
            }
        }
    }

    return;
}

static const s8 Unk_ov111_021D3708[4][8] = {
    { 0x9, 0x9, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4 },
    { 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1 },
    { 0xFFFFFFFFFFFFFFF8, 0xFFFFFFFFFFFFFFF8, 0xFFFFFFFFFFFFFFF8, 0xFFFFFFFFFFFFFFF9, 0xFFFFFFFFFFFFFFF9, 0xFFFFFFFFFFFFFFFA, 0xFFFFFFFFFFFFFFFB, 0xFFFFFFFFFFFFFFFC },
    { 0xFFFFFFFFFFFFFFEE, 0xFFFFFFFFFFFFFFF0, 0xFFFFFFFFFFFFFFF1, 0xFFFFFFFFFFFFFFF2, 0xFFFFFFFFFFFFFFF3, 0xFFFFFFFFFFFFFFF4, 0xFFFFFFFFFFFFFFF6, 0xFFFFFFFFFFFFFFF8 }
};

static const s8 Unk_ov111_021D3818[8] = {
    0xFFFFFFFFFFFFFFFC,
    0xFFFFFFFFFFFFFFFC,
    0xFFFFFFFFFFFFFFFC,
    0xFFFFFFFFFFFFFFFC,
    0xFFFFFFFFFFFFFFFC,
    0xFFFFFFFFFFFFFFFC,
    0xFFFFFFFFFFFFFFFC,
    0xFFFFFFFFFFFFFFFC
};

static BOOL ov111_021D2868(UnkStruct_ov111_021D0F7C *param0, u8 param1)
{
    int v0, v1, v2, v3;

    if (param0->unk_40C_1 >= 8) {
        return 1;
    }

    ov111_021D349C(param0->unk_390[param1], &v0, &v1);

    v2 = (v0 + Unk_ov111_021D3708[param1][param0->unk_40C_1]);
    v3 = (v1 + Unk_ov111_021D3818[param0->unk_40C_1]);
    param0->unk_40C_1++;

    ov111_021D3474(param0->unk_390[param1], v2, v3);

    return 0;
}

static void ov111_021D28E8(UnkStruct_ov111_021D0F7C *param0, u32 param1, u8 param2, u8 param3, u8 param4)
{
    Bg_ChangeTilemapRectPalette(param0->unk_58, param1, 0, 0, param3, param4, param2);
    Bg_ScheduleTilemapTransfer(param0->unk_58, param1);

    return;
}

static u8 ov111_021D2918(UnkStruct_ov111_021D0F7C *param0)
{
    u8 v0, v1 = 0;

    for (v0 = 0; v0 < 9; v0++) {
        if (param0->unk_400[v0] == 1) {
            v1++;
        }
    }

    return v1;
}

static void ov111_021D2940(UnkStruct_ov111_021D0F7C *param0)
{
    u8 v0;

    for (v0 = 0; v0 < 9; v0++) {
        param0->unk_400[v0] = 0;
    }

    return;
}

static void ov111_021D295C(UnkStruct_ov111_021D0F7C *param0)
{
    u8 v0;

    for (v0 = 0; v0 < 9; v0++) {
        param0->unk_411[v0] = 0;
    }

    return;
}

static void ov111_021D297C(UnkStruct_ov111_021D0F7C *param0, int param1)
{
    int v0, v1, v2, v3;

    for (v0 = 0; v0 < param0->unk_424.bufferSize; v0++) {
        v2 = param0->unk_424.buffer[v0].x;
        v3 = param0->unk_424.buffer[v0].y;

        if ((Unk_ov111_021D3728[param1].unk_02 <= v2) && (v2 <= Unk_ov111_021D3728[param1].unk_03) && (Unk_ov111_021D3728[param1].unk_00 <= v3) && (v3 <= Unk_ov111_021D3728[param1].unk_01)) {
            ov111_021D2ECC(param0, v2, v3);
        }
    }

    return;
}

static void ov111_021D29D8(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;
    u8 v1, v2;

    for (v0 = 0; v0 < param0->unk_424.bufferSize; v0++) {
        v1 = param0->unk_424.buffer[v0].x;
        v2 = param0->unk_424.buffer[v0].y;

        ov111_021D2A18(param0, v1, v2);
    }

    return;
}

static void ov111_021D2A18(UnkStruct_ov111_021D0F7C *param0, int param1, int param2)
{
    int v0, v1;

    for (v1 = -3; v1 < 3; v1++) {
        for (v0 = -3; v0 < 3; v0++) {
            if (((param1 + v0) > 0) && ((param1 + v0) < 240) && ((param2 + v1) > 0) && ((param2 + v1) < 160)) {
                param0->unk_466[(param1 + v0) + ((param2 + v1) * 240)] = 1;
            }
        }
    }

    return;
}

static BOOL ov111_021D2A68(UnkStruct_ov111_021D0F7C *param0, u8 param1)
{
    int v0, v1, v2, v3, v4;

    v4 = 0;
    v2 = Unk_ov111_021D374C[param1].unk_00;
    v3 = Unk_ov111_021D374C[param1].unk_02;

    for (v0 = v3; v0 < (v3 + 20); v0++) {
        for (v1 = v2; v1 < (v2 + 25); v1++) {
            if (param0->unk_466[v0 * 240 + v1] == 1) {
                v4++;
            }
        }
    }

    if (v4 >= 380) {
        if (param0->unk_411[param1] == 0) {
            Sound_PlayEffect(SEQ_SE_DP_PIRORIRO);
            param0->unk_40E[param0->unk_40D] = param1;
            param0->unk_40D++;
        }

        param0->unk_411[param1] = 1;
        return 1;
    }

    return 0;
}

static void ov111_021D2B20(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;

    param0->unk_40A++;

    if (param0->unk_40A >= 1) {
        param0->unk_40A = 0;

        param0->unk_409++;

        if (param0->unk_409 >= 8) {
            param0->unk_409 = 0;
        }

        if (param0->unk_40D == 2) {
            for (v0 = 0; v0 < 2; v0++) {
                ov111_021D3500(param0->unk_3A8[v0], 3);
                ov111_021D345C(param0->unk_3A8[v0], 1);
                ov111_021D3474(param0->unk_3A8[v0], Unk_ov111_021D3770[param0->unk_40E[v0]].unk_00 + -36, Unk_ov111_021D3770[param0->unk_40E[v0]].unk_02 + -10);
            }
        }

        ov111_021D33B0(&param0->unk_16C, param0->unk_409);
    }

    return;
}

static BOOL ov111_021D2BBC(UnkStruct_ov111_021D0F7C *param0)
{
    int v0, v1 = 0;

    if (param0->unk_40D <= 1) {
        return 0;
    }

    if (param0->unk_3C4[param0->unk_40E[0]] == param0->unk_3C4[param0->unk_40E[1]]) {
        param0->unk_40C_0 = 1;
    } else if (param0->unk_3C4[param0->unk_40E[0]] == 4) {
        param0->unk_40C_0 = 1;
    } else if (param0->unk_3C4[param0->unk_40E[1]] == 4) {
        param0->unk_40C_0 = 1;
    }

    if (param0->unk_40D <= 2) {
        return 0;
    }

    if ((param0->unk_3C4[param0->unk_40E[0]] == param0->unk_3C4[param0->unk_40E[1]]) && (param0->unk_3C4[param0->unk_40E[0]] == param0->unk_3C4[param0->unk_40E[2]])) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[0]] == 4) && (param0->unk_3C4[param0->unk_40E[1]] == 4)) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[0]] == 4) && (param0->unk_3C4[param0->unk_40E[2]] == 4)) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[1]] == 4) && (param0->unk_3C4[param0->unk_40E[2]] == 4)) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[0]] == 4) && (param0->unk_3C4[param0->unk_40E[1]] == param0->unk_3C4[param0->unk_40E[2]])) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[1]] == 4) && (param0->unk_3C4[param0->unk_40E[0]] == param0->unk_3C4[param0->unk_40E[2]])) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[2]] == 4) && (param0->unk_3C4[param0->unk_40E[0]] == param0->unk_3C4[param0->unk_40E[1]])) {
        v1 = 1;
    }

    if (v1 == 1) {
        for (v0 = 0; v0 < 3; v0++) {
            if (param0->unk_3C4[param0->unk_40E[v0]] != 4) {
                param0->unk_40B = param0->unk_3C4[param0->unk_40E[v0]];
                break;
            }
        }

        return 1;
    }

    return 0;
}

static BOOL ov111_021D2D14(UnkStruct_ov111_021D0F7C *param0)
{
    int v0;
    BOOL v1 = 0;

    for (v0 = 0; v0 < 3; v0++) {
        if (param0->unk_3C4[param0->unk_40E[v0]] == 4) {
            ov111_021D3530(param0->unk_3B4[v0], 1);
            v1 = 1;
        }
    }

    param0->unk_14 = 0;

    G2_SetOBJMosaicSize(param0->unk_14, param0->unk_14);

    return v1;
}

static BOOL ov111_021D2D60(UnkStruct_ov111_021D0F7C *param0, u8 param1)
{
    int v0;

    for (v0 = 0; v0 < 3; v0++) {
        if (param0->unk_3C4[param0->unk_40E[v0]] == 4) {
            break;
        }
    }

    if (v0 == 3) {
        return 0;
    }

    if (param1 == 0) {
        if (param0->unk_14 == 0) {
            Sound_PlayEffect(SEQ_SE_PL_W100);
        }

        if (param0->unk_14 < 4) {
            param0->unk_14++;
        } else {
            for (v0 = 0; v0 < 3; v0++) {
                if (param0->unk_3C4[param0->unk_40E[v0]] == 4) {
                    ov111_021D34C4(param0->unk_3B4[v0], param0->unk_40B);
                }
            }

            return 0;
        }
    } else {
        if (param0->unk_14 > 0) {
            param0->unk_14--;
        } else {
            for (v0 = 0; v0 < 3; v0++) {
                ov111_021D3530(param0->unk_3B4[v0], 0);
            }

            return 0;
        }
    }

    G2_SetOBJMosaicSize(param0->unk_14, param0->unk_14);

    return 1;
}

static void ov111_021D2E18(UnkStruct_ov111_021D0F7C *param0)
{
    param0->unk_0E++;
    return;
}

static void ov111_021D2E20(UnkStruct_ov111_021D0F7C *param0)
{
    param0->unk_0E++;
    return;
}

static void ov111_021D2E28(UnkStruct_ov111_021D0F7C *param0)
{
    ov111_021D345C(param0->unk_3A4, 0);
    Window_FillTilemap(&param0->unk_5C[10], 0);
    Window_ScheduleCopyToVRAM(&param0->unk_5C[10]);
    return;
}

static void ov111_021D2E4C(UnkStruct_ov111_021D0F7C *param0)
{
    param0->unk_3F0 = Graphics_GetCharData(NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, 7, 0, &param0->unk_3F4, HEAP_ID_115);

    Bg_LoadTiles(param0->unk_58, 0, param0->unk_3F4->pRawData, param0->unk_3F4->szByte, 0);
    Bg_CopyTilemapBufferToVRAM(param0->unk_58, 0);

    return;
}

static void ov111_021D2E8C(UnkStruct_ov111_021D0F7C *param0)
{
    param0->unk_3F8 = Heap_AllocFromHeap(HEAP_ID_115, param0->unk_3F4->szByte);

    if (param0->unk_3F8 == NULL) {
        GF_ASSERT(param0->unk_3F8 != NULL);
    }

    return;
}

static void ov111_021D2EB4(UnkStruct_ov111_021D0F7C *param0)
{
    memcpy(param0->unk_3F8, param0->unk_3F4->pRawData, param0->unk_3F4->szByte);
    return;
}

static void ov111_021D2ECC(UnkStruct_ov111_021D0F7C *param0, int param1, int param2)
{
    int v0, v1;

    for (v1 = -3; v1 < 3; v1++) {
        for (v0 = -3; v0 < 3; v0++) {
            if (((param1 + v0) > 0) && ((param1 + v0) < 256) && ((param2 + v1) > 0) && ((param2 + v1) < 192)) {
                ov111_021D2F38(param0, param1 + v0, param2 + v1);
            }
        }
    }

    Bg_LoadTiles(param0->unk_58, 0, param0->unk_3F8, param0->unk_3F4->szByte, 0);
    Bg_CopyTilemapBufferToVRAM(param0->unk_58, 0);

    return;
}

static void ov111_021D2F38(UnkStruct_ov111_021D0F7C *param0, u32 param1, u32 param2)
{
    u8 v0;
    u32 v1, v2, v3, v4, v5;

    v0 = 0xff;

    if ((param1 % 2) == 0) {
        v0 ^= 0xf;
    } else {
        v0 ^= 0xf0;
    }

    v1 = (param1 / 8 * 0x20);
    v2 = (param2 / 8 * 0x20 * 32);
    v3 = (param1 % 8 / 2);

    if (param2 < 8) {
        v4 = (param2 * 4);
    } else {
        v4 = (param2 % 8);
        v4 = (v4 * 4);
    }

    v5 = (v2 + v1 + v3 + v4);
    param0->unk_3F8[v5] &= v0;

    return;
}
