#include "unk_0207E0B8.h"

#include <nitro.h>
#include <string.h>

#include "constants/items.h"

#include "struct_defs/struct_0207F248.h"
#include "struct_defs/struct_02099F80.h"

#include "applications/pokemon_summary_screen/main.h"
#include "field/field_system.h"
#include "functypes/funcptr_0207E634.h"
#include "overlay118/ov118_021D0D80.h"

#include "bag.h"
#include "bg_window.h"
#include "font.h"
#include "font_special_chars.h"
#include "g3d_pipeline.h"
#include "game_options.h"
#include "game_overlay.h"
#include "graphics.h"
#include "grid_menu_cursor_position.h"
#include "gx_layers.h"
#include "heap.h"
#include "item.h"
#include "item_use_pokemon.h"
#include "journal.h"
#include "menu.h"
#include "message.h"
#include "narc.h"
#include "overlay_manager.h"
#include "party.h"
#include "pokemon.h"
#include "render_window.h"
#include "screen_fade.h"
#include "sound.h"
#include "sound_playback.h"
#include "sprite.h"
#include "sprite_system.h"
#include "strbuf.h"
#include "string_list.h"
#include "string_template.h"
#include "system.h"
#include "text.h"
#include "touch_pad.h"
#include "touch_screen.h"
#include "unk_0202602C.h"
#include "unk_020393C8.h"
#include "unk_0206B9D8.h"
#include "unk_0206CCB0.h"
#include "unk_0207A2A8.h"
#include "unk_020819DC.h"
#include "unk_02082C2C.h"
#include "unk_02083370.h"
#include "unk_02084B70.h"
#include "unk_0208C098.h"
#include "vram_transfer.h"

#include "constdata/const_020F1E88.h"

FS_EXTERN_OVERLAY(overlay118);

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
} UnkStruct_020F1DF8;

static int sub_0207E0B8(ApplicationManager *appMan, int *param1);
static int sub_0207E2A8(ApplicationManager *appMan, int *param1);
static int sub_0207E7E0(ApplicationManager *appMan, int *param1);
static int sub_0207E490(GameWindowLayout *param0);
static int sub_0207E518(GameWindowLayout *param0);
static int sub_0207E5B4(GameWindowLayout *param0);
static int sub_0207E5F4(GameWindowLayout *param0);
static int sub_0207E6C0(GameWindowLayout *param0);
static int sub_0207E6E4(GameWindowLayout *param0);
static int sub_0207E708(GameWindowLayout *param0);
static int sub_0207E714(GameWindowLayout *param0);
static int sub_0207E750(GameWindowLayout *param0);
static int ProcessWindowInput(GameWindowLayout *param0);
static void sub_0207E898(void *param0);
static void sub_0207E8C0(void);
static void sub_0207E918(BgConfig *param0);
static void sub_0207EA24(BgConfig *param0);
static void sub_0207EB6C(GameWindowLayout *param0, NARC *param1);
static GameWindowLayout *sub_0207ECC0(ApplicationManager *appMan);
static void sub_0207EE14(GameWindowLayout *param0);
static void sub_0207F308(GameWindowLayout *param0);
static u8 sub_0207F984(GameWindowLayout *param0, u8 param1);
static u8 sub_0207FE98(GameWindowLayout *param0);
static void sub_02080500(GameWindowLayout *param0, u8 param1, u8 param2);
static void sub_0207F9A0(GameWindowLayout *param0);
static void sub_0207EDC0(GameWindowLayout *param0);
static int HandleGameWindowEvent(GameWindowLayout *param0);
static u8 HandleWindowInputEvent(GameWindowLayout *param0, int *param1);
static u8 sub_020805E4(GameWindowLayout *param0);
static void UpdateWindowLayout(GameWindowLayout *param0, u8 param1, u8 param2);
static int GetValidWindowLayout(GameWindowLayout *param0);
static u8 HandleSpecialInput(GameWindowLayout *param0);
static int ApplyItemEffectOnPokemon(GameWindowLayout *param0);
static u8 CheckItemUsageValidity(GameWindowLayout *param0);
static int ProcessItemApplication(GameWindowLayout *param0);
static int UpdatePokemonWithItem(GameWindowLayout *param0, Pokemon *param1, int *param2);
static int HandleMessageCompletion(GameWindowLayout *param0);
static int FinalizeMessageProcessing(GameWindowLayout *param0);
static int ProcessPokemonItemSwap(GameWindowLayout *param0);
static int sub_0207E634(GameWindowLayout *param0);
static int ResetWindowOnInput(GameWindowLayout *param0);
static int UpdatePokemonFormWithItem(GameWindowLayout *param0);
static void sub_0207F094(GameWindowLayout *param0, Pokemon *param1, u8 param2);
static u32 sub_0207F134(Pokemon *param0, u8 param1);
static void sub_0207FE1C(GameWindowLayout *param0);
static void CalculateWindowPosition(u8 param0, s16 *param1, s16 *param2);
static int CheckForItemApplication(GameWindowLayout *param0);
static u8 CheckDuplicateValues(GameWindowLayout *param0);
static u8 CheckUniqueValues(GameWindowLayout *param0);
static u8 CheckEqualityInArray(GameWindowLayout *param0);
static BOOL ValidateGameWindowState(GameWindowLayout *param0);
static G3DPipelineBuffers *sub_0207EAD4(int heapID);
static void sub_0207EAF4(void);
static void sub_0207EB64(G3DPipelineBuffers *param0);
static int ProcessMessageResult(GameWindowLayout *param0);
static int HandleOverlayCompletion(GameWindowLayout *param0);
static void sub_0207F388(GameWindowLayout *param0, const UnkStruct_020F1DF8 *param1);
static void sub_0207F4AC(GameWindowLayout *param0, const UnkStruct_020F1DF8 *param1);
static void sub_0207F5A0(GameWindowLayout *param0, const UnkStruct_020F1DF8 *param1);
static void sub_0207F694(GameWindowLayout *param0, const UnkStruct_020F1DF8 *param1);
static void sub_0207F788(GameWindowLayout *param0, const UnkStruct_020F1DF8 *param1);
static void sub_0207F884(GameWindowLayout *param0, u8 param1, s16 param2, s16 param3);
static u8 sub_0207FA24(GameWindowLayout *param0);
static u8 sub_0207FBE0(GameWindowLayout *param0, u8 *param1, u8 *param2, u8 param3);
static u8 sub_0207FC30(GameWindowLayout *param0, u8 *param1, u8 *param2, const u8 *param3);
static u8 sub_0207FC94(GameWindowLayout *param0);
static void sub_0207FFC8(GameWindowLayout *param0);
static u8 sub_020800B4(GameWindowLayout *param0, u8 *param1);
static u8 sub_020801F0(GameWindowLayout *param0, u8 *param1);
static u8 sub_0208022C(GameWindowLayout *param0, u8 *param1);
static u8 sub_0208027C(GameWindowLayout *param0, u8 *param1);
static u8 sub_020802CC(GameWindowLayout *param0, u8 *param1);
static u8 sub_0208031C(GameWindowLayout *param0, u8 *param1);
static u8 sub_020801AC(GameWindowLayout *param0, u8 *param1);
static u8 sub_020801B8(GameWindowLayout *param0, u8 *param1);
u8 sub_02080404(GameWindowLayout *param0, u8 param1);
u8 sub_02080488(GameWindowLayout *param0, u8 param1);
static u8 CheckPokemonCondition(GameWindowLayout *param0);
static BOOL UpdatePokemonStatus(GameWindowLayout *param0, u8 param1, s8 param2);

const ApplicationManagerTemplate Unk_020F1E88 = {
    sub_0207E0B8,
    sub_0207E2A8,
    sub_0207E7E0,
    0xFFFFFFFF
};

static const UnkStruct_020F1DF8 Unk_020F1DF8[2][6] = {
    {
        { 0x0, 0x0, 0x1E, 0x10, 0x10, 0xE },
        { 0x10, 0x1, 0x9E, 0x18, 0x90, 0x16 },
        { 0x0, 0x6, 0x1E, 0x40, 0x10, 0x3E },
        { 0x10, 0x7, 0x9E, 0x48, 0x90, 0x46 },
        { 0x0, 0xC, 0x1E, 0x70, 0x10, 0x6E },
        { 0x10, 0xD, 0x9E, 0x78, 0x90, 0x76 },
    },
    {
        { 0x0, 0x0, 0x1E, 0x10, 0x10, 0xE },
        { 0x10, 0x0, 0x9E, 0x10, 0x90, 0xE },
        { 0x0, 0x6, 0x1E, 0x40, 0x10, 0x3E },
        { 0x10, 0x6, 0x9E, 0x40, 0x90, 0x3E },
        { 0x0, 0xC, 0x1E, 0x70, 0x10, 0x6E },
        { 0x10, 0xC, 0x9E, 0x70, 0x90, 0x6E },
    },
};

static const GridMenuCursorPosition Unk_020F1DB8[] = {
    { 0x40, 0x19, 0x0, 0x0, 0x7, 0x2, 0x7, 0x1 },
    { 0xC0, 0x21, 0x0, 0x0, 0x7, 0x3, 0x0, 0x2 },
    { 0x40, 0x49, 0x0, 0x0, 0x0, 0x4, 0x1, 0x3 },
    { 0xC0, 0x51, 0x0, 0x0, 0x1, 0x5, 0x2, 0x4 },
    { 0x40, 0x79, 0x0, 0x0, 0x2, 0x7, 0x3, 0x5 },
    { 0xC0, 0x81, 0x0, 0x0, 0x3, 0x7, 0x4, 0x7 },
    { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
    { 0xE0, 0xA8, 0x0, 0x0, 0x5, 0x1, 0x5, 0x0 },
};

static const GridMenuCursorPosition Unk_020F1CF8[] = {
    { 0x40, 0x19, 0x0, 0x0, 0x4, 0x2, 0x1, 0x1 },
    { 0xC0, 0x19, 0x0, 0x0, 0x7, 0x3, 0x0, 0x0 },
    { 0x40, 0x49, 0x0, 0x0, 0x0, 0x4, 0x3, 0x3 },
    { 0xC0, 0x49, 0x0, 0x0, 0x1, 0x5, 0x2, 0x2 },
    { 0x40, 0x79, 0x0, 0x0, 0x2, 0x0, 0x5, 0x5 },
    { 0xC0, 0x79, 0x0, 0x0, 0x3, 0x7, 0x4, 0x4 },
    { 0xE0, 0xA8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
    { 0xE0, 0xA8, 0x0, 0x0, 0x5, 0x1, 0xFF, 0xFF },
};

static const GridMenuCursorPosition Unk_020F1D38[] = {
    { 0x40, 0x19, 0x0, 0x0, 0x7, 0x2, 0x7, 0x1 },
    { 0xC0, 0x21, 0x0, 0x0, 0x7, 0x3, 0x0, 0x2 },
    { 0x40, 0x49, 0x0, 0x0, 0x0, 0x4, 0x1, 0x3 },
    { 0xC0, 0x51, 0x0, 0x0, 0x1, 0x5, 0x2, 0x4 },
    { 0x40, 0x79, 0x0, 0x0, 0x2, 0x6, 0x3, 0x5 },
    { 0xC0, 0x81, 0x0, 0x0, 0x3, 0x6, 0x4, 0x6 },
    { 0xE0, 0xA8, 0x0, 0x0, 0x5, 0x7, 0x5, 0x7 },
    { 0xE0, 0xB8, 0x0, 0x0, 0x6, 0x1, 0x6, 0x0 },
};

static const GridMenuCursorPosition Unk_020F1D78[] = {
    { 0x40, 0x19, 0x0, 0x0, 0x5, 0x2, 0x5, 0x1 },
    { 0xC0, 0x21, 0x0, 0x0, 0x5, 0x3, 0x0, 0x2 },
    { 0x40, 0x49, 0x0, 0x0, 0x0, 0x4, 0x1, 0x3 },
    { 0xC0, 0x51, 0x0, 0x0, 0x1, 0x5, 0x2, 0x4 },
    { 0x40, 0x79, 0x0, 0x0, 0x2, 0x0, 0x3, 0x5 },
    { 0xC0, 0x81, 0x0, 0x0, 0x3, 0x0, 0x4, 0x0 },
    { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
    { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
};

static const u16 Unk_020F1CB0[] = {
    0xF,
    0x13,
    0x39,
    0x46,
    0x1B0,
    0xF9,
    0x7F,
    0x1AF,
    0x94,
    0x64,
    0x5B,
    0xE6,
    0x1C0,
    0xD0,
    0x87,
};

static int sub_0207E0B8(ApplicationManager *appMan, int *param1)
{
    GameWindowLayout *v0;
    NARC *v1;

    SetVBlankCallback(NULL, NULL);
    DisableHBlank();
    GXLayers_DisableEngineALayers();
    GXLayers_DisableEngineBLayers();

    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    G2_BlendNone();
    G2S_BlendNone();

    SetAutorepeat(4, 8);
    Heap_Create(HEAP_ID_APPLICATION, HEAP_ID_12, 0x30000);

    v1 = NARC_ctor(NARC_INDEX_GRAPHIC__PL_PLIST_GRA, HEAP_ID_12);
    v0 = sub_0207ECC0(appMan);

    StartScreenFade(FADE_MAIN_THEN_SUB, FADE_TYPE_DOWNWARD_IN, FADE_TYPE_DOWNWARD_IN, COLOR_BLACK, 6, 1, HEAP_ID_12);
    sub_0207EDC0(v0);
    sub_0207E8C0();
    sub_0207E918(v0->unk_00);
    sub_0207EB6C(v0, v1);
    EnableTouchPad();
    InitializeTouchPad(4);
    Sound_SetSceneAndPlayBGM(SOUND_SCENE_SUB_57, SEQ_NONE, 0);
    sub_02081A24(v0);
    sub_02082C2C(v0);
    sub_02082E58(v0);
    sub_0207EE14(v0);
    sub_0207F308(v0);
    sub_02080500(v0, v0->partySlot, 1);

    if ((v0->partyManagementData->unk_20 == 5) || (v0->partyManagementData->unk_20 == 16)) {
        if (CheckItemSacredAsh(v0->partyManagementData->usedItemID) == 0) {
            sub_020826E0(v0, 32, 1);
        }
    } else if (v0->partyManagementData->unk_20 == 6) {
        sub_020826E0(v0, 33, 1);
    } else if ((v0->partyManagementData->unk_20 == 9) || (v0->partyManagementData->unk_20 == 14)) {
        sub_020826E0(v0, 31, 1);
    } else if ((v0->partyManagementData->unk_20 == 7) || (v0->partyManagementData->unk_20 == 8) || (v0->partyManagementData->unk_20 == 11) || (v0->partyManagementData->unk_20 == 12)) {
        Sprite_SetExplicitPalette2(v0->unk_5B0[6], 1);
    } else if ((v0->partyManagementData->unk_20 == 2) || (v0->partyManagementData->unk_20 == 17)) {
        sub_020826E0(v0, 34, 1);
    } else if (v0->partyManagementData->unk_20 == 15) {
        sub_020826E0(v0, 34, 1);
    } else if (v0->partyManagementData->unk_20 == 22) {
        sub_020826E0(v0, 34, 1);
    } else if (v0->partyManagementData->unk_20 == 23) {
        sub_020826E0(v0, 34, 1);
    } else if (v0->partyManagementData->unk_20 == 21) {
        sub_020826E0(v0, 197, 1);
    } else if (v0->partyManagementData->unk_20 != 10) {
        sub_020826E0(v0, 29, 1);
    } else {
        Sprite_SetExplicitPalette2(v0->unk_5B0[6], 1);
    }

    sub_02081BC0(v0);
    sub_0207F9A0(v0);

    if (ValidateGameWindowState(v0) == 0) {
        GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, 0);
    }

    SetVBlankCallback(sub_0207E898, v0);
    DrawWifiConnectionIcon();
    NARC_dtor(v1);

    return 1;
}

static int sub_0207E2A8(ApplicationManager *appMan, int *param1)
{
    GameWindowLayout *v0 = ApplicationManager_Data(appMan);

    switch (*param1) {
    case 0:
        *param1 = sub_0207E490(v0);
        break;
    case 1:
        *param1 = sub_0207E518(v0);
        break;
    case 2:
        if (HandleWindowInputEvent(v0, param1) == 1) {
            *param1 = 1;
        }
        break;
    case 3:
        *param1 = sub_02084B34(v0);
        break;
    case 4:
        *param1 = sub_0207E5B4(v0);
        break;
    case 5:
        *param1 = v0->unk_B00(v0);
        break;
    case 6:
        *param1 = sub_02086774(v0);
        break;
    case 7:
        *param1 = sub_02085804(v0);
        break;
    case 8:
        *param1 = sub_0207E5F4(v0);
        break;
    case 9:
        *param1 = FinalizeMessageProcessing(v0);
        break;
    case 10:
        *param1 = ProcessPokemonItemSwap(v0);
        break;
    case 11:
        *param1 = HandleMessageCompletion(v0);
        break;
    case 12:
        *param1 = ProcessMessageResult(v0);
        break;
    case 13:
        *param1 = HandleOverlayCompletion(v0);
        break;
    case 14:
        *param1 = UpdatePokemonFormWithItem(v0);
        break;
    case 15:
        *param1 = sub_0207E634(v0);
        break;
    case 16:
        *param1 = ProcessItemApplication(v0);
        break;
    case 17:
        *param1 = sub_02083658(v0);
        break;
    case 18:
        *param1 = sub_020836A8(v0);
        break;
    case 19:
        *param1 = sub_020836E4(v0);
        break;
    case 20:
        *param1 = sub_020839BC(v0);
        break;
    case 21:
        *param1 = sub_0207E750(v0);
        break;
    case 22:
        *param1 = sub_020863A0(v0);
        break;
    case 23:
        *param1 = sub_020845A8(v0);
        break;
    case 24:
        *param1 = sub_0207E6C0(v0);
        break;
    case 25:
        *param1 = sub_0207E6E4(v0);
        break;
    case 26:
        *param1 = sub_0207E708(v0);
        break;
    case 27:
        *param1 = sub_0207E714(v0);
        break;
    case 28: {
        u8 v1 = sub_020805E4(v0);

        if (v1 == 0) {
            *param1 = 29;
        } else if (v1 == 3) {
            *param1 = 1;
        }
    } break;
    case 29:
        if (sub_02083D1C(v0) == 1) {
            *param1 = 1;
        }
        break;
    case 30:
        *param1 = ProcessWindowInput(v0);
        break;
    case 31:
        if (ov118_021D0DBC(v0) == 1) {
            UnloadOverlay118(v0);
            *param1 = 25;
        } else {
            *param1 = 31;
        }
        break;
    case 32:
        sub_0208C120(1, HEAP_ID_12);
        *param1 = 33;
        break;
    case 33:
        if (IsScreenFadeDone() == TRUE) {
            v0->partyManagementData->selectedMonSlot = v0->partySlot;
            return 1;
        }
        break;
    }

    sub_020831B4(v0);
    sub_02083334(v0);
    sub_0207FE1C(v0);
    SpriteSystem_DrawSprites(v0->unk_5AC);

    return 0;
}

static int sub_0207E490(GameWindowLayout *param0)
{
    if (IsScreenFadeDone() == TRUE) {
        if ((param0->partyManagementData->unk_20 == 5) || (param0->partyManagementData->unk_20 == 16)) {
            if (CheckItemSacredAsh(param0->partyManagementData->usedItemID) == 1) {
                param0->unk_B0E = 0;
                return 7;
            }

            return 4;
        } else if (param0->partyManagementData->unk_20 == 6) {
            return 21;
        } else if (param0->partyManagementData->unk_20 == 7) {
            return sub_020862F8(param0);
        } else if (param0->partyManagementData->unk_20 == 8) {
            return sub_02085EF4(param0);
        } else if ((param0->partyManagementData->unk_20 == 11) || (param0->partyManagementData->unk_20 == 12)) {
            return 14;
        } else if (param0->partyManagementData->unk_20 == 9) {
            return 8;
        } else if (param0->partyManagementData->unk_20 == 10) {
            return 16;
        } else {
            return 1;
        }
    }

    return 0;
}

static int sub_0207E518(GameWindowLayout *param0)
{
    u8 v0 = sub_0207FE98(param0);

    if (v0 == 0) {
        if ((param0->partyManagementData->unk_20 == 3) || (param0->partyManagementData->unk_20 == 20)) {
            param0->partyManagementData->menuSelectionResult = 0;
            return 32;
        } else if (param0->partyManagementData->unk_20 == 14) {
            sub_020868B0(param0);
            return 24;
        } else if (param0->partyManagementData->unk_20 == 19) {
            return CheckForItemApplication(param0);
        } else {
            return 2;
        }
    } else if (v0 == 4) {
        return HandleGameWindowEvent(param0);
    } else if (v0 == 3) {
        param0->partyManagementData->menuSelectionResult = 0;
        return 32;
    } else if (v0 == 2) {
        if (param0->partyManagementData->unk_20 != 15) {
            param0->partyManagementData->menuSelectionResult = 1;
            return 32;
        } else {
            Sprite_SetExplicitPalette2(param0->unk_5B0[6], 1);
            return sub_02084780(param0);
        }
    }

    return 1;
}

static int sub_0207E5B4(GameWindowLayout *param0)
{
    u8 v0 = HandleSpecialInput(param0);

    if ((v0 == 0) || (v0 == 2)) {
        Sprite_SetExplicitPalette2(param0->unk_5B0[6], 1);
        return ApplyItemEffectOnPokemon(param0);
    } else if (v0 == 3) {
        param0->partyManagementData->menuSelectionResult = 0;
        return 32;
    }

    return 4;
}

static int sub_0207E5F4(GameWindowLayout *param0)
{
    u8 v0 = HandleSpecialInput(param0);

    if ((v0 == 0) || (v0 == 2)) {
        Sprite_SetExplicitPalette2(param0->unk_5B0[6], 1);
        return ProcessItemApplication(param0);
    } else if (v0 == 3) {
        param0->partyManagementData->menuSelectionResult = 0;
        return 32;
    }

    return 8;
}

static int sub_0207E634(GameWindowLayout *param0)
{
    u32 v0 = Menu_ProcessInput(param0->unk_700);

    switch (v0) {
    case 0xffffffff:
        break;
    case 0xfffffffe:
        Window_EraseMessageBox(&param0->unk_04[33], 1);
        Window_EraseStandardFrame(&param0->unk_04[35], 1);
        Window_ClearAndScheduleCopyToVRAM(&param0->unk_04[35]);
        Menu_Free(param0->unk_700, NULL);
        StringList_Free(param0->unk_6FC);
        sub_020826E0(param0, 29, 1);
        Sprite_SetExplicitPalette2(param0->unk_5B0[6], 0);
        return 1;
    default: {
        UnkFuncPtr_0207E634 v1;
        int v2;

        v1 = (UnkFuncPtr_0207E634)v0;
        v1(param0, &v2);

        return v2;
    }
    }

    return 15;
}

static int sub_0207E6C0(GameWindowLayout *param0)
{
    if (Text_IsPrinterActive(param0->textPrinterID) == 0) {
        return param0->unk_B0E;
    }

    return 24;
}

static int sub_0207E6E4(GameWindowLayout *param0)
{
    if (gSystem.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        Sound_PlayEffect(SEQ_SE_CONFIRM);
        return 32;
    }

    return 25;
}

static int sub_0207E708(GameWindowLayout *param0)
{
    sub_020827EC(param0);
    return 27;
}

static int sub_0207E714(GameWindowLayout *param0)
{
    switch (Menu_ProcessInputAndHandleExit(param0->unk_700, 12)) {
    case 0:
        return param0->unk_B04.unk_00(param0);
    case 0xfffffffe:
        return param0->unk_B04.unk_04(param0);
    }

    return 27;
}

static int sub_0207E750(GameWindowLayout *param0)
{
    u8 v0 = HandleSpecialInput(param0);

    if ((v0 == 0) || (v0 == 2)) {
        Sprite_SetExplicitPalette2(param0->unk_5B0[6], 1);

        if (param0->unk_704[param0->partySlot].unk_10 != 1) {
            return sub_0208615C(param0);
        } else {
            sub_02082708(param0, 0xffffffff, 1);
            param0->partyManagementData->menuSelectionResult = 0;
            param0->unk_B0E = 25;
            MessageLoader_GetStrbuf(param0->messageLoader, 105, param0->unk_6A4);
            return 24;
        }
    } else if (v0 == 3) {
        param0->partyManagementData->menuSelectionResult = 0;
        return 32;
    }

    return 21;
}

static int sub_0207E7E0(ApplicationManager *appMan, int *param1)
{
    GameWindowLayout *v0 = ApplicationManager_Data(appMan);
    u32 v1;

    SetVBlankCallback(NULL, NULL);
    sub_02082FF4(v0);
    sub_02081B90(v0);
    sub_0207EA24(v0->unk_00);
    DisableTouchPad();
    VramTransfer_Free();

    for (v1 = 0; v1 < 6; v1++) {
        Strbuf_Free(v0->unk_704[v1].unk_00);
    }

    Strbuf_Free(v0->unk_6A4);
    Strbuf_Free(v0->unk_6A8);

    for (v1 = 0; v1 < 20; v1++) {
        Strbuf_Free(v0->unk_6AC[v1]);
    }

    MessageLoader_Free(v0->messageLoader);
    FontSpecialChars_Free(v0->unk_698);
    StringTemplate_Free(v0->template);

    if (v0->unk_B20 != NULL) {
        sub_0207A2C0(v0->unk_B20);
    }

    ApplicationManager_FreeData(appMan);
    Heap_Destroy(HEAP_ID_12);

    return 1;
}

static void sub_0207E898(void *param0)
{
    GameWindowLayout *v0 = param0;

    Bg_RunScheduledUpdates(v0->unk_00);
    VramTransfer_Process();
    SpriteSystem_TransferOam();

    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void sub_0207E8C0(void)
{
    UnkStruct_02099F80 v0 = {
        GX_VRAM_BG_128_A,
        GX_VRAM_BGEXTPLTT_NONE,
        GX_VRAM_SUB_BG_128_C,
        GX_VRAM_SUB_BGEXTPLTT_NONE,
        GX_VRAM_OBJ_64_E,
        GX_VRAM_OBJEXTPLTT_NONE,
        GX_VRAM_SUB_OBJ_16_I,
        GX_VRAM_SUB_OBJEXTPLTT_NONE,
        GX_VRAM_OBJ_128_B,
        GX_VRAM_OBJ_32_FG
    };

    GXLayers_SetBanks(&v0);
}

static void sub_0207E8E0(BgConfig *param0)
{
    BgTemplate v0 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x800,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_256x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0xf800,
        .charBase = GX_BG_CHARBASE_0x00000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 0,
        .areaOver = 0,
        .mosaic = FALSE,
    };

    Bg_InitFromTemplate(param0, BG_LAYER_MAIN_0, &v0, 0);
    Bg_ClearTilemap(param0, BG_LAYER_MAIN_0);
}

static void sub_0207E918(BgConfig *param0)
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
        sub_0207E8E0(param0);
    }

    {
        BgTemplate v1 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xf000,
            .charBase = GX_BG_CHARBASE_0x00000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_MAIN_1, &v1, 0);
        Bg_ClearTilemap(param0, BG_LAYER_MAIN_1);
    }

    {
        BgTemplate v2 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xe800,
            .charBase = GX_BG_CHARBASE_0x10000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 2,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_MAIN_2, &v2, 0);
        Bg_ClearTilemap(param0, BG_LAYER_MAIN_2);
    }

    {
        BgTemplate v3 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xe000,
            .charBase = GX_BG_CHARBASE_0x10000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 3,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_MAIN_3, &v3, 0);
    }

    {
        BgTemplate v4 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xf800,
            .charBase = GX_BG_CHARBASE_0x10000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_SUB_0, &v4, 0);
        Bg_ClearTilemap(param0, BG_LAYER_SUB_0);
    }

    {
        BgTemplate v5 = {
            .x = 0,
            .y = 0,
            .bufferSize = 0x800,
            .baseTile = 0,
            .screenSize = BG_SCREEN_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0xf000,
            .charBase = GX_BG_CHARBASE_0x00000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = 0,
            .mosaic = FALSE,
        };

        Bg_InitFromTemplate(param0, BG_LAYER_SUB_1, &v5, 0);
    }

    Bg_ClearTilesRange(BG_LAYER_MAIN_0, 32, 0, HEAP_ID_12);
    Bg_ClearTilesRange(4, 32, 0, HEAP_ID_12);
}

static void sub_0207EA24(BgConfig *param0)
{
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ, 0);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_OBJ, 0);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_SUB_1);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_SUB_0);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_MAIN_3);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_MAIN_2);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_MAIN_1);
    Bg_FreeTilemapBuffer(param0, BG_LAYER_MAIN_0);
    Heap_FreeExplicit(HEAP_ID_12, param0);
}

void sub_0207EA74(GameWindowLayout *windowLayout, int param1)
{
    if (param1 == 0) {
        Bg_ToggleLayer(BG_LAYER_MAIN_0, 0);
        Bg_FreeTilemapBuffer(windowLayout->unk_00, BG_LAYER_MAIN_0);

        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
        windowLayout->unk_B28 = sub_0207EAD4(HEAP_ID_12);
    } else {
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0, 0);
        sub_0207EB64(windowLayout->unk_B28);

        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);

        sub_0207E8E0(windowLayout->unk_00);
        Bg_ClearTilesRange(BG_LAYER_MAIN_0, 32, 0, HEAP_ID_12);
    }
}

static G3DPipelineBuffers *sub_0207EAD4(int heapID)
{
    return G3DPipeline_Init(heapID, TEXTURE_VRAM_SIZE_128K, PALETTE_VRAM_SIZE_32K, sub_0207EAF4);
}

static void sub_0207EAF4(void)
{
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(1);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    G3X_SetFog(0, GX_FOGBLEND_COLOR_ALPHA, GX_FOGSLOPE_0x8000, 0);
    G3X_SetClearColor(GX_RGB(0, 0, 0), 0, 0x7fff, 63, 0);
    G3_ViewPort(0, 0, 255, 191);
}

static void sub_0207EB64(G3DPipelineBuffers *param0)
{
    G3DPipelineBuffers_Free(param0);
}

static void sub_0207EB6C(GameWindowLayout *param0, NARC *param1)
{
    Graphics_LoadTilesToBgLayerFromOpenNARC(param1, 15, param0->unk_00, 3, 0, 0, 0, HEAP_ID_12);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(param1, 17, param0->unk_00, 3, 0, 0, 0, HEAP_ID_12);

    {
        NNSG2dPaletteData *v0;
        void *v1;
        u16 *v2;

        v1 = NARC_AllocAndReadWholeMember(param1, 16, 12);
        NNS_G2dGetUnpackedPaletteData(v1, &v0);
        Bg_LoadPalette(3, (void *)v0->pRawData, v0->szByte, 0);

        v2 = (u16 *)v0->pRawData;
        memcpy(param0->unk_4A4, &v2[3 * 16], 32 * 8);
        Heap_FreeExplicit(HEAP_ID_12, v1);
    }

    Font_LoadScreenIndicatorsPalette(0, 13 * 32, HEAP_ID_12);
    LoadStandardWindowGraphics(param0->unk_00, BG_LAYER_MAIN_0, 1, 14, 0, HEAP_ID_12);
    LoadMessageBoxGraphics(param0->unk_00, BG_LAYER_MAIN_0, 1 + 9, 15, Options_Frame(param0->partyManagementData->options), HEAP_ID_12);
    Graphics_LoadTilesToBgLayerFromOpenNARC(param1, 3, param0->unk_00, 4, 0, 0, 0, HEAP_ID_12);
    Graphics_LoadPaletteFromOpenNARC(param1, 4, 4, 0x20, 0x20, HEAP_ID_12);
    Graphics_LoadTilesToBgLayerFromOpenNARC(param1, 12, param0->unk_00, 5, 0, 0, 0, HEAP_ID_12);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(param1, 14, param0->unk_00, 5, 0, 0, 0, HEAP_ID_12);
    Graphics_LoadPaletteFromOpenNARC(param1, 13, 4, 0, 0x20, HEAP_ID_12);
    LoadScreenDataFromNARC(12, param0->unk_264, param0->unk_324, param0->unk_3E4);
    Bg_MaskPalette(BG_LAYER_MAIN_0, 0);
    Bg_MaskPalette(BG_LAYER_SUB_0, 0);
}

static GameWindowLayout *sub_0207ECC0(ApplicationManager *appMan)
{
    GameWindowLayout *v0;
    u32 v1;

    v0 = ApplicationManager_NewData(appMan, sizeof(GameWindowLayout), HEAP_ID_12);
    memset(v0, 0, sizeof(GameWindowLayout));

    v0->partyManagementData = ApplicationManager_Args(appMan);
    v0->unk_00 = BgConfig_New(HEAP_ID_12);

    if ((v0->partyManagementData->unk_20 == 2) && (v0->partyManagementData->battleRegulation != NULL)) {
        v0->unk_B20 = sub_0207A2A8(HEAP_ID_12);
    } else {
        v0->unk_B20 = NULL;
    }

    v0->messageLoader = MessageLoader_Init(MESSAGE_LOADER_BANK_HANDLE, NARC_INDEX_MSGDATA__PL_MSG, TEXT_BANK_UNK_0453, HEAP_ID_12);
    v0->unk_698 = FontSpecialChars_Init(15, 14, 0, HEAP_ID_12);
    v0->template = StringTemplate_Default(HEAP_ID_12);

    for (v1 = 0; v1 < 6; v1++) {
        v0->unk_704[v1].unk_00 = Strbuf_Init(10 + 1, HEAP_ID_12);
    }

    v0->unk_6A4 = Strbuf_Init(256, HEAP_ID_12);
    v0->unk_6A8 = Strbuf_Init(256, HEAP_ID_12);

    for (v1 = 0; v1 < 20; v1++) {
        v0->unk_6AC[v1] = Strbuf_Init(32, HEAP_ID_12);
    }

    v0->partySlot = v0->partyManagementData->selectedMonSlot;
    v0->unk_B12 = v0->partySlot;

    return v0;
}

static void sub_0207EDC0(GameWindowLayout *param0)
{
    if ((param0->partyManagementData->unk_20 & 0x80) != 0) {
        param0->unk_B0F_7 = 1;
        param0->partyManagementData->unk_20 ^= 0x80;
    } else if (param0->partyManagementData->unk_20 == 21) {
        param0->unk_B0F_7 = 1;
    } else {
        param0->unk_B0F_7 = 0;
    }
}

static void sub_0207EE14(GameWindowLayout *param0)
{
    u8 v0 = 3;

    if (param0->partyManagementData->unk_21 == 2) {
        param0->unk_7F4 = Unk_020F1CF8;
    } else if ((param0->partyManagementData->unk_20 == 2) || (param0->partyManagementData->unk_20 == 17) || (param0->partyManagementData->unk_20 == 23) || (param0->partyManagementData->unk_20 == 22)) {
        param0->unk_7F4 = Unk_020F1D38;
    } else if (param0->partyManagementData->unk_20 == 21) {
        param0->unk_7F4 = Unk_020F1D78;
    } else {
        param0->unk_7F4 = Unk_020F1DB8;
    }

    if ((param0->partyManagementData->unk_20 != 2) && (param0->partyManagementData->unk_20 != 17) && (param0->partyManagementData->unk_20 != 23) && (param0->partyManagementData->unk_20 != 22)) {
        Sprite_SetDrawFlag(param0->unk_5B0[8], FALSE);
        Sprite_SetAnim(param0->unk_5B0[9], 0);

        {
            s16 v1, v2;

            Sprite_GetPositionXY(param0->unk_5B0[9], &v1, &v2);
            Sprite_SetPositionXY(param0->unk_5B0[9], v1, v2 - 8);
        }

        v0 ^= 1;
    }

    if ((param0->partyManagementData->unk_20 == 4) || (param0->partyManagementData->unk_20 == 21)) {
        Sprite_SetDrawFlag(param0->unk_5B0[9], FALSE);
        v0 ^= 2;
    }

    sub_020825B4(param0, v0);
}

u8 sub_0207EF04(GameWindowLayout *windowLayout, u8 param1)
{
    return windowLayout->unk_704[param1].unk_29;
}

u8 sub_0207EF14(GameWindowLayout *windowLayout, u8 partySlot)
{
    Pokemon *mon;
    u32 v1;
    u16 species;

    windowLayout->unk_704[partySlot].unk_29 = 0;

    if (Party_GetCurrentCount(windowLayout->partyManagementData->party) <= partySlot) {
        return 0;
    }

    mon = Party_GetPokemonBySlotIndex(windowLayout->partyManagementData->party, partySlot);
    species = (u16)Pokemon_GetValue(mon, MON_DATA_SPECIES, NULL);

    if (species == 0) {
        return 0;
    }

    sub_02081ED8(windowLayout, mon, partySlot);

    windowLayout->unk_704[partySlot].unk_04 = species;
    windowLayout->unk_704[partySlot].curHP = (u16)Pokemon_GetValue(mon, MON_DATA_CURRENT_HP, NULL);
    windowLayout->unk_704[partySlot].maxHP = (u16)Pokemon_GetValue(mon, MON_DATA_MAX_HP, NULL);
    windowLayout->unk_704[partySlot].level = (u16)Pokemon_GetValue(mon, MON_DATA_LEVEL, NULL);
    windowLayout->unk_704[partySlot].unk_0C = (u16)Pokemon_GetValue(mon, MON_DATA_HELD_ITEM, NULL);
    windowLayout->unk_704[partySlot].unk_12 = (u16)Pokemon_GetValue(mon, MON_DATA_BALL_CAPSULE_ID, NULL);
    windowLayout->unk_704[partySlot].unk_10 = (u8)Pokemon_GetValue(mon, MON_DATA_IS_EGG, NULL);
    windowLayout->unk_704[partySlot].unk_11 = (u8)Pokemon_GetValue(mon, MON_DATA_FORM, NULL);

    if (Pokemon_GetValue(mon, MON_DATA_NIDORAN_HAS_NICKNAME, NULL) == 1) {
        windowLayout->unk_704[partySlot].unk_0E_12 = 0;
    } else {
        windowLayout->unk_704[partySlot].unk_0E_12 = 1;
    }

    windowLayout->unk_704[partySlot].unk_0E_13 = Pokemon_GetGender(mon);
    windowLayout->unk_704[partySlot].unk_29 = 1;
    windowLayout->unk_704[partySlot].unk_0E_0 = (u8)PokemonSummaryScreen_StatusIconAnimIdx(mon);

    sub_0207F094(windowLayout, mon, partySlot);

    return 1;
}

static void sub_0207F094(GameWindowLayout *param0, Pokemon *param1, u8 param2)
{
    u32 v0;
    u32 v1;

    if (param0->partyManagementData->unk_20 != 13) {
        return;
    }

    if ((param0->unk_704[param2].unk_10 == 1) || (param0->unk_704[param2].curHP == 0)) {
        param0->unk_704[param2].unk_0E_15 = 0;
        return;
    }

    v0 = sub_0207F134(param1, param0->partyManagementData->unk_2A);

    for (v1 = 0; v1 < 4; v1++) {
        if (Pokemon_GetValue(param1, MON_DATA_MOVE1 + v1, NULL) == 0) {
            break;
        }
    }

    if ((param0->partyManagementData->unk_2B <= v0) && (v1 >= 2)) {
        param0->unk_704[param2].unk_0E_15 = 1;
    } else {
        param0->unk_704[param2].unk_0E_15 = 0;
    }
}

static u32 sub_0207F134(Pokemon *param0, u8 param1)
{
    u32 v0;

    switch (param1) {
    case 0:
        v0 = Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_COOL_RIBBON, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_COOL_RIBBON_GREAT, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_COOL_RIBBON_ULTRA, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_COOL_RIBBON_MASTER, NULL);
        break;
    case 1:
        v0 = Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_BEAUTY_RIBBON, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_BEAUTY_RIBBON_GREAT, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_BEAUTY_RIBBON_ULTRA, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_BEAUTY_RIBBON_MASTER, NULL);
        break;
    case 2:
        v0 = Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_CUTE_RIBBON, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_CUTE_RIBBON_GREAT, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_CUTE_RIBBON_ULTRA, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_CUTE_RIBBON_MASTER, NULL);
        break;
    case 3:
        v0 = Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_SMART_RIBBON, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_SMART_RIBBON_GREAT, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_SMART_RIBBON_ULTRA, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_SMART_RIBBON_MASTER, NULL);
        break;
    case 4:
        v0 = Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_TOUGH_RIBBON, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_TOUGH_RIBBON_GREAT, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_TOUGH_RIBBON_ULTRA, NULL);
        v0 += Pokemon_GetValue(param0, MON_DATA_SINNOH_SUPER_TOUGH_RIBBON_MASTER, NULL);
    }

    return v0;
}

const u16 *sub_0207F248(GameWindowLayout *windowLayout)
{
    return &windowLayout->unk_324[3 * 16 + 6];
}

static void sub_0207F250(GameWindowLayout *param0, u8 param1, u8 param2, u8 param3, u8 param4)
{
    const u16 *v0;

    if ((param1 == 0) || ((param0->partyManagementData->unk_21 != 0) && (param1 == 1))) {
        v0 = param0->unk_264;
    } else {
        v0 = param0->unk_324;
    }

    param0->unk_704[param1].unk_14 = (s8)param2;
    param0->unk_704[param1].unk_15 = (s8)param3;

    Bg_CopyToTilemapRect(param0->unk_00, 2, param2, param3, 16, 6, (const void *)v0, 0, 0, 16, 6);

    if (param4 == 0) {
        Bg_FillTilemapRect(
            param0->unk_00, 2, 0x17, param2 + 6, param3 + 3, 9, 1, 16);
    }

    Bg_ChangeTilemapRectPalette(param0->unk_00, 2, param2, param3, 16, 6, 3 + param1);
    sub_0207F8F8(param0, param1);
}

static void sub_0207F308(GameWindowLayout *param0)
{
    const UnkStruct_020F1DF8 *v0;

    if (param0->partyManagementData->unk_21 == 2) {
        v0 = Unk_020F1DF8[1];
    } else {
        v0 = Unk_020F1DF8[0];
    }

    if (param0->partyManagementData->unk_20 == 16) {
        sub_0207F4AC(param0, v0);
    } else if (param0->partyManagementData->unk_20 == 6) {
        sub_0207F5A0(param0, v0);
    } else if (param0->partyManagementData->unk_20 == 13) {
        sub_0207F694(param0, v0);
    } else if ((param0->partyManagementData->unk_20 == 2) || (param0->partyManagementData->unk_20 == 17) || (param0->partyManagementData->unk_20 == 23) || (param0->partyManagementData->unk_20 == 22)) {
        sub_0207F788(param0, v0);
    } else {
        sub_0207F388(param0, v0);
    }

    Bg_ScheduleTilemapTransfer(param0->unk_00, 2);
    Bg_ScheduleTilemapTransfer(param0->unk_00, 4);
}

static void sub_0207F388(GameWindowLayout *param0, const UnkStruct_020F1DF8 *param1)
{
    u8 v0;
    NARC *v1 = NARC_ctor(NARC_INDEX_POKETOOL__ICONGRA__PL_POKE_ICON, HEAP_ID_12);

    for (v0 = 0; v0 < 6; v0++) {
        if (sub_0207EF14(param0, v0) == 1) {
            if (param0->unk_704[v0].unk_10 == 1) {
                sub_0207F250(param0, v0, param1[v0].unk_00, param1[v0].unk_02, 0);
            } else {
                sub_0207F250(param0, v0, param1[v0].unk_00, param1[v0].unk_02, 1);
            }

            sub_020821F8(param0, v0);
            sub_02082CEC(param0, v0, param1[v0].unk_04, param1[v0].unk_06, v1);
            sub_02082FAC(param0, v0, param1[v0].unk_08, param1[v0].unk_0A);
            sub_02083040(param0, v0, param0->unk_704[v0].unk_0C);
            sub_020830A0(param0, v0, param1[v0].unk_04, param1[v0].unk_06);
            sub_02083104(param0, v0);
            sub_020830D4(param0, v0);
            sub_02083014(param0, v0, param0->unk_704[v0].unk_0E_0);
            UpdateWindowLayout(param0, v0, 0);
        } else {
            sub_0207F884(param0, v0, param1[v0].unk_00, param1[v0].unk_02);
        }
    }

    NARC_dtor(v1);
}

static void sub_0207F4AC(GameWindowLayout *param0, const UnkStruct_020F1DF8 *param1)
{
    u8 v0;
    NARC *v1 = NARC_ctor(NARC_INDEX_POKETOOL__ICONGRA__PL_POKE_ICON, HEAP_ID_12);

    for (v0 = 0; v0 < 6; v0++) {
        if (sub_0207EF14(param0, v0) == 1) {
            sub_0207F250(param0, v0, param1[v0].unk_00, param1[v0].unk_02, 0);
            sub_0208232C(param0, v0);
            sub_02082CEC(param0, v0, param1[v0].unk_04, param1[v0].unk_06, v1);
            sub_02082FAC(param0, v0, param1[v0].unk_08, param1[v0].unk_0A);
            sub_02083040(param0, v0, param0->unk_704[v0].unk_0C);
            sub_020830A0(param0, v0, param1[v0].unk_04, param1[v0].unk_06);
            sub_02083104(param0, v0);
            sub_020830D4(param0, v0);
            sub_02083014(param0, v0, param0->unk_704[v0].unk_0E_0);
            UpdateWindowLayout(param0, v0, 0);
        } else {
            sub_0207F884(param0, v0, param1[v0].unk_00, param1[v0].unk_02);
        }
    }

    NARC_dtor(v1);
}

static void sub_0207F5A0(GameWindowLayout *param0, const UnkStruct_020F1DF8 *param1)
{
    u8 v0;
    NARC *v1 = NARC_ctor(NARC_INDEX_POKETOOL__ICONGRA__PL_POKE_ICON, HEAP_ID_12);

    for (v0 = 0; v0 < 6; v0++) {
        if (sub_0207EF14(param0, v0) == 1) {
            sub_0207F250(param0, v0, param1[v0].unk_00, param1[v0].unk_02, 0);
            sub_020823C4(param0, v0);
            sub_02082CEC(param0, v0, param1[v0].unk_04, param1[v0].unk_06, v1);
            sub_02082FAC(param0, v0, param1[v0].unk_08, param1[v0].unk_0A);
            sub_02083040(param0, v0, param0->unk_704[v0].unk_0C);
            sub_020830A0(param0, v0, param1[v0].unk_04, param1[v0].unk_06);
            sub_02083104(param0, v0);
            sub_020830D4(param0, v0);
            sub_02083014(param0, v0, param0->unk_704[v0].unk_0E_0);
            UpdateWindowLayout(param0, v0, 0);
        } else {
            sub_0207F884(param0, v0, param1[v0].unk_00, param1[v0].unk_02);
        }
    }

    NARC_dtor(v1);
}

static void sub_0207F694(GameWindowLayout *param0, const UnkStruct_020F1DF8 *param1)
{
    u8 v0;
    NARC *v1 = NARC_ctor(NARC_INDEX_POKETOOL__ICONGRA__PL_POKE_ICON, HEAP_ID_12);

    for (v0 = 0; v0 < 6; v0++) {
        if (sub_0207EF14(param0, v0) == 1) {
            sub_0207F250(param0, v0, param1[v0].unk_00, param1[v0].unk_02, 0);
            sub_0208245C(param0, v0);
            sub_02082CEC(param0, v0, param1[v0].unk_04, param1[v0].unk_06, v1);
            sub_02082FAC(param0, v0, param1[v0].unk_08, param1[v0].unk_0A);
            sub_02083040(param0, v0, param0->unk_704[v0].unk_0C);
            sub_020830A0(param0, v0, param1[v0].unk_04, param1[v0].unk_06);
            sub_02083104(param0, v0);
            sub_020830D4(param0, v0);
            sub_02083014(param0, v0, param0->unk_704[v0].unk_0E_0);
            UpdateWindowLayout(param0, v0, 0);
        } else {
            sub_0207F884(param0, v0, param1[v0].unk_00, param1[v0].unk_02);
        }
    }

    NARC_dtor(v1);
}

static void sub_0207F788(GameWindowLayout *param0, const UnkStruct_020F1DF8 *param1)
{
    u8 v0;
    NARC *v1 = NARC_ctor(NARC_INDEX_POKETOOL__ICONGRA__PL_POKE_ICON, HEAP_ID_12);

    for (v0 = 0; v0 < 6; v0++) {
        if (sub_0207EF14(param0, v0) == 1) {
            sub_0207F250(param0, v0, param1[v0].unk_00, param1[v0].unk_02, 0);
            sub_020824C0(param0, v0);
            sub_02082508(param0, v0);
            sub_02082CEC(param0, v0, param1[v0].unk_04, param1[v0].unk_06, v1);
            sub_02082FAC(param0, v0, param1[v0].unk_08, param1[v0].unk_0A);
            sub_02083040(param0, v0, param0->unk_704[v0].unk_0C);
            sub_020830A0(param0, v0, param1[v0].unk_04, param1[v0].unk_06);
            sub_02083104(param0, v0);
            sub_020830D4(param0, v0);
            sub_02083014(param0, v0, param0->unk_704[v0].unk_0E_0);
            UpdateWindowLayout(param0, v0, 0);
        } else {
            sub_0207F884(param0, v0, param1[v0].unk_00, param1[v0].unk_02);
        }
    }

    NARC_dtor(v1);
}

static void sub_0207F884(GameWindowLayout *param0, u8 param1, s16 param2, s16 param3)
{
    Bg_CopyToTilemapRect(param0->unk_00, 2, param2, param3, 16, 6, (const void *)param0->unk_3E4, 0, 0, 16, 6);
    Bg_ChangeTilemapRectPalette(param0->unk_00, 2, param2, param3, 16, 6, 1);
    sub_02083014(param0, param1, 7);
    sub_02083040(param0, param1, 0);
    sub_02083104(param0, param1);
}

void sub_0207F8F8(GameWindowLayout *windowLayout, u8 partySlot)
{
    Pokemon *mon;
    u8 v1;

    mon = Party_GetPokemonBySlotIndex(windowLayout->partyManagementData->party, partySlot);

    if ((windowLayout->unk_B0F_6 == 1) && ((partySlot == windowLayout->partySlot) || (partySlot == windowLayout->unk_B0F_0))) {
        v1 = 3 + 4;
    } else {
        if (partySlot == windowLayout->partySlot) {
            v1 = 4;
        } else {
            v1 = 0;
        }

        if (Pokemon_GetValue(mon, MON_DATA_CURRENT_HP, 0) == 0) {
            v1 += 2;
        } else if (sub_0207F984(windowLayout, partySlot) == 1) {
            v1 += 1;
        } else {
            v1 += 0;
        }
    }

    Bg_LoadPalette(2, &windowLayout->unk_4A4[v1 * 16], 8 * 2, (3 + partySlot) * 32);
}

static u8 sub_0207F984(GameWindowLayout *param0, u8 param1)
{
    if ((param0->partyManagementData->unk_21 == 2) && ((param1 & 1) != 0)) {
        return 1;
    }

    return 0;
}

static void sub_0207F9A0(GameWindowLayout *param0)
{
    u8 v0, v1;

    GridMenuCursor_CheckNavigation(param0->unk_7F4, &v0, &v1, NULL, NULL, param0->partySlot, GRID_MENU_CURSOR_POSITION_DIRECTION_NONE);
    Sprite_SetAnim(param0->unk_5B0[6], sub_020805D0(param0->partyManagementData->unk_21, param0->partySlot));
    Sprite_SetPositionXY(param0->unk_5B0[6], v0, v1);
}

static const u8 Unk_020F1BD4[][6] = {
    { 0x0, 0x2, 0x4, 0x1, 0x3, 0x5 },
    { 0x1, 0x3, 0x5, 0x0, 0x2, 0x4 },
    { 0x4, 0x2, 0x0, 0x5, 0x3, 0x1 },
    { 0x5, 0x3, 0x1, 0x4, 0x2, 0x0 }
};

static u8 sub_0207FA00(GameWindowLayout *param0)
{
    if (sub_0207FA24(param0) == 1) {
        return 1;
    }

    if (sub_0207FC94(param0) == 1) {
        return 2;
    }

    return 5;
}

static u8 sub_0207FA24(GameWindowLayout *param0)
{
    u8 v0;
    u8 v1;
    u8 v2, v3;

    v1 = GRID_MENU_CURSOR_POSITION_DIRECTION_NONE;

    if (gSystem.pressedKeysRepeatable & PAD_KEY_UP) {
        v1 = GRID_MENU_CURSOR_POSITION_DIRECTION_UP;
    } else if (gSystem.pressedKeysRepeatable & PAD_KEY_DOWN) {
        v1 = GRID_MENU_CURSOR_POSITION_DIRECTION_DOWN;
    } else if (gSystem.pressedKeysRepeatable & PAD_KEY_LEFT) {
        v1 = GRID_MENU_CURSOR_POSITION_DIRECTION_LEFT;
    } else if (gSystem.pressedKeysRepeatable & PAD_KEY_RIGHT) {
        v1 = GRID_MENU_CURSOR_POSITION_DIRECTION_RIGHT;
    }

    if (v1 == GRID_MENU_CURSOR_POSITION_DIRECTION_NONE) {
        return 0;
    }

    v0 = param0->partySlot;

    if (v0 == 6) {
        if (v1 == GRID_MENU_CURSOR_POSITION_DIRECTION_UP) {
            v0 = sub_0207FC30(param0, &v2, &v3, Unk_020F1BD4[2 + (param0->unk_B12 & 1)]);
        } else {
            v0 = sub_0207FBE0(param0, &v2, &v3, v1);
        }
    } else if (v0 == 7) {
        if ((param0->partyManagementData->unk_20 != 2) && (param0->partyManagementData->unk_20 != 17) && (param0->partyManagementData->unk_20 != 23) && (param0->partyManagementData->unk_20 != 22) && (v1 == 0)) {
            v0 = sub_0207FC30(param0, &v2, &v3, Unk_020F1BD4[2 + (param0->unk_B12 & 1)]);
        } else if (v1 == 1) {
            v0 = sub_0207FC30(param0, &v2, &v3, Unk_020F1BD4[(param0->unk_B12 & 1)]);
        } else {
            v0 = sub_0207FBE0(param0, &v2, &v3, v1);
        }
    } else {
        v0 = sub_0207FBE0(param0, &v2, &v3, v1);
    }

    if ((v0 != param0->partySlot) && (v0 != 0xff)) {
        if ((v0 == 6) || (v0 == 7)) {
            Sprite_SetDrawFlag(param0->unk_5B0[6], FALSE);
        } else {
            Sprite_SetAnim(param0->unk_5B0[6], sub_020805D0(param0->partyManagementData->unk_21, v0));
            Sprite_SetDrawFlag(param0->unk_5B0[6], TRUE);
            Sprite_SetPositionXY(param0->unk_5B0[6], v2, v3);
        }

        {
            u8 v4 = param0->partySlot;
            param0->partySlot = v0;

            sub_02080500(param0, v4, 0);
            sub_02080500(param0, param0->partySlot, 1);
            Sound_PlayEffect(SEQ_SE_CONFIRM);

            if (v4 < 6) {
                UpdateWindowLayout(param0, v4, 0);
                Bg_ScheduleTilemapTransfer(param0->unk_00, 4);
            }

            if ((v4 != 6) && (v4 != 7)) {
                param0->unk_B12 = v4;
            }
        }

        return 1;
    }

    return 0;
}

static u8 sub_0207FBE0(GameWindowLayout *param0, u8 *param1, u8 *param2, u8 param3)
{
    u8 v0 = param0->partySlot;

    while (TRUE) {
        v0 = GridMenuCursor_CheckNavigation(param0->unk_7F4, param1, param2, NULL, NULL, v0, param3);

        if ((v0 == 6) || (v0 == 7) || (v0 == 0xff)) {
            break;
        }

        if (sub_0207EF04(param0, v0) != 0) {
            break;
        }
    }

    return v0;
}

static u8 sub_0207FC30(GameWindowLayout *param0, u8 *param1, u8 *param2, const u8 *param3)
{
    u8 v0 = 0;

    while (TRUE) {
        if (v0 == 6) {
            break;
        }

        if (sub_0207EF04(param0, param3[v0]) != 0) {
            GridMenuCursor_CheckNavigation(param0->unk_7F4, param1, param2, NULL, NULL, param3[v0], GRID_MENU_CURSOR_POSITION_DIRECTION_NONE);
            return param3[v0];
        }

        v0++;
    }

    GridMenuCursor_CheckNavigation(param0->unk_7F4, param1, param2, NULL, NULL, 0, GRID_MENU_CURSOR_POSITION_DIRECTION_NONE);
    return 0;
}

static u8 sub_0207FC94(GameWindowLayout *param0)
{
    int v0 = GetValidWindowLayout(param0);

    if (v0 != 0xffffffff) {
        u8 v1, v2;
        u8 v3;

        v3 = param0->partySlot;
        param0->partySlot = (u8)v0;

        sub_02080500(param0, v3, 0);
        sub_02080500(param0, param0->partySlot, 1);

        if (v3 < 6) {
            UpdateWindowLayout(param0, v3, 0);
        }

        GridMenuCursor_CheckNavigation(param0->unk_7F4, &v1, &v2, NULL, NULL, param0->partySlot, GRID_MENU_CURSOR_POSITION_DIRECTION_NONE);
        Sprite_SetAnim(param0->unk_5B0[6], sub_020805D0(param0->partyManagementData->unk_21, param0->partySlot));
        Sprite_SetDrawFlag(param0->unk_5B0[6], TRUE);
        Sprite_SetPositionXY(param0->unk_5B0[6], v1, v2);

        param0->unk_B0C = 1;
        param0->unk_B0D = param0->partySlot;

        Sound_PlayEffect(SEQ_SE_DP_BUTTON9);

        if ((v3 != 6) && (v3 != 7)) {
            param0->unk_B12 = v3;
        }

        return 1;
    }

    return 0;
}

void sub_0207FD68(GameWindowLayout *windowLayout, u8 partySlot)
{
    if ((partySlot == 6) || (partySlot == 7)) {
        Sprite_SetDrawFlag(windowLayout->unk_5B0[6], FALSE);
    } else {
        u8 v0, v1;

        GridMenuCursor_CheckNavigation(windowLayout->unk_7F4, &v0, &v1, NULL, NULL, windowLayout->partySlot, GRID_MENU_CURSOR_POSITION_DIRECTION_NONE);
        Sprite_SetAnim(windowLayout->unk_5B0[6], sub_020805D0(windowLayout->partyManagementData->unk_21, partySlot));
        Sprite_SetDrawFlag(windowLayout->unk_5B0[6], TRUE);
        Sprite_SetPositionXY(windowLayout->unk_5B0[6], v0, v1);
    }

    {
        u8 v2 = windowLayout->partySlot;
        windowLayout->partySlot = partySlot;

        sub_02080500(windowLayout, v2, 0);
        sub_02080500(windowLayout, windowLayout->partySlot, 1);

        if (v2 < 6) {
            UpdateWindowLayout(windowLayout, v2, 0);
            Bg_ScheduleTilemapTransfer(windowLayout->unk_00, 4);
        }
    }
}

static void sub_0207FE1C(GameWindowLayout *param0)
{
    switch (param0->unk_B0C) {
    case 0:
        break;
    case 1:

    {
        s16 v0, v1;

        CalculateWindowPosition(param0->unk_B0D, &v0, &v1);
        sub_020832E4(param0, v0, v1);
    }
        UpdateWindowLayout(param0, param0->unk_B0D, 2);
        Bg_ScheduleTilemapTransfer(param0->unk_00, 4);
        param0->unk_B0C++;
        break;
    case 2:
        UpdateWindowLayout(param0, param0->unk_B0D, 1);
        Bg_ScheduleTilemapTransfer(param0->unk_00, 4);
        param0->unk_B0C = 0;
        break;
    }
}

static u8 sub_0207FE98(GameWindowLayout *param0)
{
    u8 v0;

    if (gSystem.pressedKeys & PAD_BUTTON_A) {
        if (param0->partySlot == 6) {
            return 4;
        } else if (param0->partySlot == 7) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);

            if (param0->unk_B0F_7 == 0) {
                return 3;
            }
        } else if ((param0->partyManagementData->unk_20 == 3) || (param0->partyManagementData->unk_20 == 19)) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            return 0;
        } else if ((param0->partyManagementData->unk_20 == 20) || (param0->partyManagementData->unk_20 == 14)) {
            if (param0->unk_704[param0->partySlot].unk_10 == 0) {
                Sound_PlayEffect(SEQ_SE_CONFIRM);
                return 0;
            } else {
                Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
                return 5;
            }
        } else if (param0->partyManagementData->unk_20 == 15) {
            if (param0->unk_704[param0->partySlot].unk_10 == 0) {
                Sound_PlayEffect(SEQ_SE_CONFIRM);
                sub_0207FFC8(param0);
                return 0;
            } else {
                Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
                return 5;
            }
        } else if (param0->partyManagementData->unk_20 == 21) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            sub_0207FFC8(param0);
            return 0;
        } else {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            sub_0207FFC8(param0);
            return 0;
        }
    }

    if (gSystem.pressedKeys & PAD_BUTTON_B) {
        if (param0->unk_B0F_7 == 0) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            param0->partySlot = 7;
            return 3;
        }
    }

    v0 = sub_0207FA00(param0);

    if (v0 == 2) {
        if ((param0->partyManagementData->unk_20 == 20) || (param0->partyManagementData->unk_20 == 14) || (param0->partyManagementData->unk_20 == 15)) {
            if (param0->unk_704[param0->partySlot].unk_10 != 0) {
                Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
                return 5;
            }
        }
    }

    return v0;
}

static void sub_0207FFC8(GameWindowLayout *param0)
{
    u8 *v0;
    u8 v1;

    Window_EraseMessageBox(&param0->unk_04[32], 1);
    v0 = Heap_AllocFromHeap(HEAP_ID_12, 8);

    switch (param0->partyManagementData->unk_20) {
    case 0:
        v1 = sub_020800B4(param0, v0);
        break;
    case 2:
    case 17:
        v1 = sub_0208022C(param0, v0);
        break;
    case 15:
        v1 = sub_020801AC(param0, v0);
        break;
    case 18:
        v1 = sub_020801B8(param0, v0);
        break;
    case 21:
        v1 = sub_0208031C(param0, v0);
        break;

    case 22:
        v1 = sub_0208027C(param0, v0);
        break;
    case 23:
        v1 = sub_020802CC(param0, v0);
        break;
    default:
        v1 = sub_020801F0(param0, v0);
    }

    sub_02081CF4(param0, v0, v1);
    Heap_FreeExplicit(HEAP_ID_12, v0);
    sub_02081E08(param0);
    sub_020826F4(param0, 0xffffffff, 1);
    Sprite_SetExplicitPalette2(param0->unk_5B0[6], 1);
}

static u8 sub_020800B4(GameWindowLayout *param0, u8 *param1)
{
    Pokemon *v0 = Party_GetPokemonBySlotIndex(param0->partyManagementData->party, param0->partySlot);
    u16 v1;
    u8 v2 = 0, v3, v4 = 0, v5;

    param1[v4] = 1;
    v4++;

    if (FieldSystem_IsInBattleTowerSalon(param0->partyManagementData->fieldSystem) == FALSE) {
        if (param0->unk_704[param0->partySlot].unk_10 == 0) {
            for (v3 = 0; v3 < 4; v3++) {
                v1 = (u16)Pokemon_GetValue(v0, MON_DATA_MOVE1 + v3, NULL);

                if (v1 == 0) {
                    break;
                }

                v5 = GetElementIndex(v1);

                if (v5 != 0xff) {
                    param1[v4] = v5;
                    v4++;
                    sub_02081CAC(param0, v1, v2);
                    v2++;
                }
            }

            param1[v4] = 0;
            v4++;

            if (Item_IsMail(param0->unk_704[param0->partySlot].unk_0C) == 1) {
                param1[v4] = 5;
            } else {
                param1[v4] = 2;
            }

            v4++;
        } else {
            param1[v4] = 0;
            v4++;
        }
    }

    param1[v4] = 9;
    v4++;

    return v4;
}

static u8 sub_020801AC(GameWindowLayout *param0, u8 *param1)
{
    param1[0] = 14;
    param1[1] = 9;

    return 2;
}

static u8 sub_020801B8(GameWindowLayout *param0, u8 *param1)
{
    if (param0->unk_704[param0->partySlot].unk_10 == 0) {
        param1[0] = 8;
        param1[1] = 1;
        param1[2] = 9;

        return 3;
    }

    param1[0] = 1;
    param1[1] = 9;

    return 2;
}

static u8 sub_020801F0(GameWindowLayout *param0, u8 *param1)
{
    if (param0->unk_704[param0->partySlot].unk_0E_15 == 1) {
        param1[0] = 13;
        param1[1] = 1;
        param1[2] = 9;

        return 3;
    }

    param1[0] = 1;
    param1[1] = 9;

    return 2;
}

static u8 sub_0208022C(GameWindowLayout *param0, u8 *param1)
{
    switch (sub_02080354(param0, param0->partySlot)) {
    case 0:
        param1[0] = 1;
        param1[1] = 9;
        return 2;
    case 1:
        param1[0] = 11;
        param1[1] = 1;
        param1[2] = 9;
        return 3;
    case 2:
        param1[0] = 12;
        param1[1] = 1;
        param1[2] = 9;
        return 3;
    }

    return 0;
}

static u8 sub_0208027C(GameWindowLayout *param0, u8 *param1)
{
    switch (sub_02080404(param0, param0->partySlot)) {
    case 0:
        param1[0] = 1;
        param1[1] = 9;
        return 2;
    case 1:
        param1[0] = 11;
        param1[1] = 1;
        param1[2] = 9;
        return 3;
    case 2:
        param1[0] = 12;
        param1[1] = 1;
        param1[2] = 9;
        return 3;
    }

    return 0;
}

static u8 sub_020802CC(GameWindowLayout *param0, u8 *param1)
{
    switch (sub_02080488(param0, param0->partySlot)) {
    case 0:
        param1[0] = 1;
        param1[1] = 9;
        return 2;
    case 1:
        param1[0] = 11;
        param1[1] = 1;
        param1[2] = 9;
        return 3;
    case 2:
        param1[0] = 12;
        param1[1] = 1;
        param1[2] = 9;
        return 3;
    }

    return 0;
}

static u8 sub_0208031C(GameWindowLayout *param0, u8 *param1)
{
    if (param0->unk_704[param0->partySlot].unk_10 == 1) {
        param1[0] = 1;
        param1[1] = 15;
        param1[2] = 9;
        return 3;
    }

    param1[0] = 1;
    param1[1] = 9;

    return 2;
}

u8 sub_02080354(GameWindowLayout *windowLayout, u8 partySlot)
{
    u8 v0;

    if (windowLayout->partyManagementData->battleRegulation != NULL) {
        Pokemon *v1 = Party_GetPokemonBySlotIndex(windowLayout->partyManagementData->party, partySlot);

        if (sub_0207A2D0(windowLayout->partyManagementData->battleRegulation, v1, windowLayout->unk_B20) == 0) {
            return 0;
        }
    }

    if (windowLayout->partyManagementData->unk_20 == 17) {
        if (sub_02078804(windowLayout->unk_704[partySlot].unk_04) == 1) {
            return 0;
        }
    }

    for (v0 = 0; v0 < windowLayout->partyManagementData->unk_32_4; v0++) {
        if (windowLayout->partyManagementData->unk_2C[v0] == partySlot + 1) {
            return 2;
        }
    }

    if ((windowLayout->unk_704[partySlot].unk_10 == 1) || (windowLayout->unk_704[partySlot].level > windowLayout->partyManagementData->unk_33)) {
        return 0;
    }

    return 1;
}

u8 sub_02080404(GameWindowLayout *windowLayout, u8 partySlot)
{
    u8 v0;

    if (windowLayout->partyManagementData->unk_20 == 22) {
        if (sub_02078804(windowLayout->unk_704[partySlot].unk_04) == 1) {
            return 0;
        }
    }

    for (v0 = 0; v0 < windowLayout->partyManagementData->unk_32_4; v0++) {
        if (windowLayout->partyManagementData->unk_2C[v0] == partySlot + 1) {
            return 2;
        }
    }

    if ((windowLayout->unk_704[partySlot].unk_10 == 1) || (windowLayout->unk_704[partySlot].level < windowLayout->partyManagementData->unk_33)) {
        return 0;
    }

    return 1;
}

u8 sub_02080488(GameWindowLayout *windowLayout, u8 partySlot)
{
    u8 v0;

    if (windowLayout->partyManagementData->unk_20 == 23) {
        if (sub_02078804(windowLayout->unk_704[partySlot].unk_04) == 1) {
            return 0;
        }
    }

    for (v0 = 0; v0 < windowLayout->partyManagementData->unk_32_4; v0++) {
        if (windowLayout->partyManagementData->unk_2C[v0] == partySlot + 1) {
            return 2;
        }
    }

    if (windowLayout->unk_704[partySlot].unk_10 == 1) {
        return 0;
    }

    return 1;
}

static void sub_02080500(GameWindowLayout *param0, u8 param1, u8 param2)
{
    if (param1 == 6) {
        u8 v0 = Sprite_GetActiveAnim(param0->unk_5B0[8]);

        if (param2 == 0) {
            v0 = (v0 & 2);
        } else {
            v0 = (v0 & 2) + 1;
        }

        Sprite_SetAnim(param0->unk_5B0[8], v0);
        return;
    }

    if (param1 == 7) {
        u8 v1 = Sprite_GetActiveAnim(param0->unk_5B0[9]);

        if (param2 == 0) {
            v1 = (v1 & 2);
        } else {
            v1 = (v1 & 2) + 1;
        }

        Sprite_SetAnim(param0->unk_5B0[9], v1);
        return;
    }

    if (param2 == 0) {
        param0->unk_704[param1].unk_16 -= 2;
        param0->unk_704[param1].unk_18 -= 2;

        Sprite_SetAnim(param0->unk_5B0[0 + param1], 0);
    } else {
        param0->unk_704[param1].unk_16 += 2;
        param0->unk_704[param1].unk_18 += 2;

        Sprite_SetAnim(param0->unk_5B0[0 + param1], 1);
    }

    sub_0207F8F8(param0, param1);
}

u8 sub_020805D0(u8 param0, u8 param1)
{
    if ((param1 == 0) || ((param0 != 0) && (param1 == 1))) {
        return 1;
    }

    return 0;
}

static u8 sub_020805E4(GameWindowLayout *param0)
{
    u8 v0;

    if (gSystem.pressedKeys & PAD_BUTTON_A) {
        Sound_PlayEffect(SEQ_SE_CONFIRM);

        if ((param0->partySlot >= 6) || (param0->partySlot == param0->unk_B0F_0)) {
            sub_02083B88(param0);
            return 3;
        } else {
            sub_02083BD4(param0);
            return 0;
        }
    }

    if (gSystem.pressedKeys & PAD_BUTTON_B) {
        Sound_PlayEffect(SEQ_SE_CONFIRM);
        sub_02083B88(param0);
        return 3;
    }

    v0 = sub_0207FA00(param0);

    if (v0 == 2) {
        if (param0->partySlot == param0->unk_B0F_0) {
            sub_02083B88(param0);
            return 3;
        } else {
            sub_02083BD4(param0);
            return 0;
        }
    }

    return v0;
}

static int HandleGameWindowEvent(GameWindowLayout *param0)
{
    u8 v0;

    for (v0 = 0; v0 < param0->partyManagementData->unk_32_0; v0++) {
        if (param0->partyManagementData->unk_2C[v0] == 0) {
            switch (param0->partyManagementData->unk_32_4) {
            case 2:
                sub_02082708(param0, 107, 1);
                break;
            case 3:
                sub_02082708(param0, 119, 1);
                break;
            case 4:
                sub_02082708(param0, 120, 1);
                break;
            case 5:
                sub_02082708(param0, 121, 1);
                break;
            case 6:
                sub_02082708(param0, 122, 1);
                break;
            default:
                sub_02082708(param0, 29, 1);
                break;
            }

            param0->unk_B0E = 23;
            Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
            return 24;
        }
    }

    if (param0->partyManagementData->battleRegulation != NULL) {
        switch (sub_0207A3AC(param0->partyManagementData->battleRegulation, param0->partyManagementData->party, param0->unk_B20, param0->partyManagementData->unk_2C)) {
        case 0:
            break;

        case 1: {
            Strbuf *v1;
            int v2;

            v1 = MessageLoader_GetNewStrbuf(param0->messageLoader, 184);
            v2 = sub_02026074(param0->partyManagementData->battleRegulation, 3);

            StringTemplate_SetNumber(param0->template, 0, v2, 3, 0, 1);
            StringTemplate_Format(param0->template, param0->unk_6A4, v1);
            Strbuf_Free(v1);
        }
            sub_02082708(param0, 0xffffffff, 1);
            param0->unk_B0E = 23;
            Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
            return 24;
        case 2:
            sub_02082708(param0, 182, 1);
            param0->unk_B0E = 23;
            Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
            return 24;
        case 3:
            sub_02082708(param0, 183, 1);
            param0->unk_B0E = 23;
            Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
            return 24;
        }
    }

    if (param0->partyManagementData->unk_20 == 17) {
        switch (CheckDuplicateValues(param0)) {
        case 0:
            break;
        case 1:
            sub_02082708(param0, 182, 1);
            param0->unk_B0E = 23;
            Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
            return 24;
        case 2:
            sub_02082708(param0, 183, 1);
            param0->unk_B0E = 23;
            Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
            return 24;
        }
    }

    if (param0->partyManagementData->unk_20 == 22) {
        switch (CheckUniqueValues(param0)) {
        case 0:
            break;
        case 1:
            sub_02082708(param0, 201, 1);
            param0->unk_B0E = 23;
            Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
            return 24;
        }
    }

    if (param0->partyManagementData->unk_20 == 23) {
        switch (CheckEqualityInArray(param0)) {
        case 0:
            break;
        case 1:
            sub_02082708(param0, 182, 1);
            param0->unk_B0E = 23;
            Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
            return 24;
        }
    }

    param0->partyManagementData->menuSelectionResult = 0;
    Sound_PlayEffect(SEQ_SE_CONFIRM);
    return 32;
}

static u8 CheckDuplicateValues(GameWindowLayout *param0)
{
    u8 v0, v1;

    for (v0 = 0; v0 < 5; v0++) {
        if (param0->partyManagementData->unk_2C[v0] == 0) {
            break;
        }

        for (v1 = v0 + 1; v1 < 6; v1++) {
            if (param0->partyManagementData->unk_2C[v1] == 0) {
                break;
            }

            if (param0->unk_704[param0->partyManagementData->unk_2C[v0] - 1].unk_04 == param0->unk_704[param0->partyManagementData->unk_2C[v1] - 1].unk_04) {
                return 1;
            }

            if ((param0->unk_704[param0->partyManagementData->unk_2C[v0] - 1].unk_0C != 0) && (param0->unk_704[param0->partyManagementData->unk_2C[v0] - 1].unk_0C == param0->unk_704[param0->partyManagementData->unk_2C[v1] - 1].unk_0C)) {
                return 2;
            }
        }
    }

    return 0;
}

static u8 CheckUniqueValues(GameWindowLayout *param0)
{
    u8 v0, v1;

    for (v0 = 0; v0 < 5; v0++) {
        if (param0->partyManagementData->unk_2C[v0] == 0) {
            break;
        }

        for (v1 = v0 + 1; v1 < 6; v1++) {
            if (param0->partyManagementData->unk_2C[v1] == 0) {
                break;
            }

            if (param0->unk_704[param0->partyManagementData->unk_2C[v0] - 1].unk_04 != param0->unk_704[param0->partyManagementData->unk_2C[v1] - 1].unk_04) {
                return 1;
            }
        }
    }

    return 0;
}

static u8 CheckEqualityInArray(GameWindowLayout *param0)
{
    u8 v0, v1;

    for (v0 = 0; v0 < 5; v0++) {
        if (param0->partyManagementData->unk_2C[v0] == 0) {
            break;
        }

        for (v1 = v0 + 1; v1 < 6; v1++) {
            if (param0->partyManagementData->unk_2C[v1] == 0) {
                break;
            }

            if (param0->unk_704[param0->partyManagementData->unk_2C[v0] - 1].unk_04 == param0->unk_704[param0->partyManagementData->unk_2C[v1] - 1].unk_04) {
                return 1;
            }
        }
    }

    return 0;
}

static const u8 Unk_020F1BB8[6][2] = {
    { 0x1, 0x3 },
    { 0x1A, 0x3 },
    { 0x1, 0xA },
    { 0x1A, 0xA },
    { 0x1, 0x11 },
    { 0x1A, 0x11 }
};

static const TouchScreenRect Unk_020F1C94[] = {
    { 0x18, 0x3F, 0x8, 0x2F },
    { 0x18, 0x3F, 0xD0, 0xF7 },
    { 0x50, 0x77, 0x8, 0x2F },
    { 0x50, 0x77, 0xD0, 0xF7 },
    { 0x88, 0xAF, 0x8, 0x2F },
    { 0x88, 0xAF, 0xD0, 0xF7 },
    { 0xFF, 0x0, 0x0, 0x0 }
};

static void UpdateWindowLayout(GameWindowLayout *param0, u8 param1, u8 param2)
{
    u16 *v0;
    u16 v1;
    u8 v2, v3;
    u8 v4, v5;

    v0 = (u16 *)Bg_GetTilemapBuffer(param0->unk_00, 4);
    v1 = 5 + (1 << 12) + 5 * 5 * param2;
    v2 = Unk_020F1BB8[param1][0];
    v3 = Unk_020F1BB8[param1][1];

    for (v4 = 0; v4 < 5; v4++) {
        for (v5 = 0; v5 < 5; v5++) {
            v0[(v3 + v4) * 32 + v2 + v5] = v4 * 5 + v5 + v1;
        }
    }
}

static void CalculateWindowPosition(u8 param0, s16 *param1, s16 *param2)
{
    *param1 = Unk_020F1BB8[param0][0] * 8 + ((5 * 8) >> 1);
    *param2 = Unk_020F1BB8[param0][1] * 8 + ((5 * 8) >> 1);
}

static int GetValidWindowLayout(GameWindowLayout *param0)
{
    int v0;

    if (ValidateGameWindowState(param0) == 0) {
        return 0xffffffff;
    }

    v0 = TouchScreen_CheckRectanglePressed(Unk_020F1C94);

    if (v0 != 0xffffffff) {
        u16 v1 = 0xfffe;

        if (Bg_DoesPixelAtXYMatchVal(param0->unk_00, 4, gSystem.touchX, gSystem.touchY, &v1) == 0) {
            return 0xffffffff;
        }
    }

    return v0;
}

static u8 HandleWindowInputEvent(GameWindowLayout *param0, int *param1)
{
    u32 v0 = Menu_ProcessInput(param0->unk_700);

    switch (v0) {
    case 0xffffffff:
        break;
    case 0xfffffffe:
        Window_EraseMessageBox(&param0->unk_04[33], 1);
        sub_0208337C(param0);

        if ((param0->partyManagementData->unk_20 == 2) || (param0->partyManagementData->unk_20 == 17) || (param0->partyManagementData->unk_20 == 23) || (param0->partyManagementData->unk_20 == 22)) {
            sub_020826E0(param0, 34, 1);
        } else if (param0->partyManagementData->unk_20 == 21) {
            sub_020826E0(param0, 197, 1);
        } else {
            sub_020826E0(param0, 29, 1);
        }

        Sprite_SetExplicitPalette2(param0->unk_5B0[6], 0);
        return 1;
    default: {
        UnkFuncPtr_0207E634 v1 = (UnkFuncPtr_0207E634)v0;
        v1(param0, param1);
    }
    }

    return 0;
}

u8 GetElementIndex(u16 param0)
{
    u8 v0;

    for (v0 = 0; v0 < NELEMS(Unk_020F1CB0); v0++) {
        if (param0 == Unk_020F1CB0[v0]) {
            return v0 + 16;
        }
    }

    return 0xff;
}

static int ProcessWindowInput(GameWindowLayout *param0)
{
    switch (param0->monStats[1]) {
    case 0:
        if (gSystem.pressedKeys & PAD_BUTTON_A) {
            if (param0->partySlot >= 6) {
                Sound_PlayEffect(SEQ_SE_CONFIRM);
                sub_02083B88(param0);
                return 1;
            } else {
                switch (CheckPokemonCondition(param0)) {
                case 0:
                    Sound_PlayEffect(SEQ_SE_DP_KAIFUKU);
                    Sprite_SetExplicitPalette2(param0->unk_5B0[6], 1);

                    if (param0->unk_704[param0->partySlot].maxHP - param0->unk_704[param0->partySlot].curHP < param0->monStats[0]) {
                        param0->monStats[0] = param0->unk_704[param0->partySlot].maxHP - param0->unk_704[param0->partySlot].curHP;
                    }

                    param0->monStats[1] = 2;
                    param0->monStats[2] = 0;
                    break;
                case 1:
                    Sound_PlayEffect(SEQ_SE_CONFIRM);
                    param0->monStats[1] = 1;
                    return 24;
                case 2:
                    Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
                    return 30;
                }
            }
        }

        if (gSystem.pressedKeys & PAD_BUTTON_B) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            sub_02083B88(param0);
            return 1;
        }

        if (sub_0207FA00(param0) == 2) {
            if (param0->partySlot == param0->unk_B0F_0) {
                sub_02083B88(param0);
                return 1;
            } else {
                switch (CheckPokemonCondition(param0)) {
                case 0:
                    Sound_PlayEffect(SEQ_SE_DP_KAIFUKU);
                    Sprite_SetExplicitPalette2(param0->unk_5B0[6], 1);

                    if (param0->unk_704[param0->partySlot].maxHP - param0->unk_704[param0->partySlot].curHP < param0->monStats[0]) {
                        param0->monStats[0] = param0->unk_704[param0->partySlot].maxHP - param0->unk_704[param0->partySlot].curHP;
                    }

                    param0->monStats[1] = 2;
                    param0->monStats[2] = 0;
                    break;
                case 1:
                    param0->monStats[1] = 1;
                    return 24;
                case 2:
                    Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
                    return 30;
                }
            }
        }
        break;
    case 1:
        if (gSystem.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            Window_EraseMessageBox(&param0->unk_04[34], 1);
            Sprite_SetExplicitPalette2(param0->unk_5B0[6], 0);
            sub_020826E0(param0, 36, 1);
            param0->monStats[1] = 0;
        }
        break;
    case 2:
        if (UpdatePokemonStatus(param0, param0->unk_B0F_0, -1) == 1) {
            Sound_PlayEffect(SEQ_SE_DP_KAIFUKU);
            param0->monStats[1] = 3;
            param0->monStats[2] = 0;
        }
        break;
    case 3:
        if (UpdatePokemonStatus(param0, param0->partySlot, 1) == 1) {
            Pokemon *mon;
            Strbuf *v1;
            void *journalEntryLocationEvent;
            FieldSystem *fieldSystem;

            mon = Party_GetPokemonBySlotIndex(param0->partyManagementData->party, param0->partySlot);
            v1 = MessageLoader_GetNewStrbuf(param0->messageLoader, 64);

            StringTemplate_SetNickname(param0->template, 0, Pokemon_GetBoxPokemon(mon));
            StringTemplate_SetNumber(param0->template, 1, param0->monStats[2], 3, 0, 1);
            StringTemplate_Format(param0->template, param0->unk_6A4, v1);
            Strbuf_Free(v1);
            sub_02082708(param0, 0xffffffff, 1);

            journalEntryLocationEvent = JournalEntry_CreateEventUsedMove((u8)param0->monStats[3], 0, 12);
            fieldSystem = param0->partyManagementData->fieldSystem;
            JournalEntry_SaveData(fieldSystem->journalEntry, journalEntryLocationEvent, JOURNAL_LOCATION);
            param0->monStats[1] = 4;
            param0->unk_B0E = 30;
            return 24;
        }
        break;
    case 4:
        if (gSystem.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            Window_EraseMessageBox(&param0->unk_04[34], 1);
            Sprite_SetExplicitPalette2(param0->unk_5B0[6], 0);
            sub_02083B88(param0);
            return 1;
        }
        break;
    }

    return 30;
}

static u8 CheckPokemonCondition(GameWindowLayout *param0)
{
    if (param0->unk_704[param0->partySlot].unk_10 != 0) {
        return 2;
    }

    if ((param0->partySlot == param0->unk_B0F_0) || (param0->unk_704[param0->partySlot].curHP == 0) || (param0->unk_704[param0->partySlot].curHP == param0->unk_704[param0->partySlot].maxHP)) {
        Sprite_SetExplicitPalette2(param0->unk_5B0[6], 1);
        sub_02082708(param0, 131, 1);

        param0->monStats[1] = 1;
        param0->unk_B0E = 30;

        return 1;
    }

    return 0;
}

static BOOL UpdatePokemonStatus(GameWindowLayout *param0, u8 slot, s8 param2)
{
    param0->unk_704[slot].curHP += param2;
    param0->monStats[2]++;

    sub_02082098(param0, slot);
    Window_FillTilemap(&param0->unk_04[3 + slot * 5], 0);
    sub_02082058(param0, slot);
    sub_02082104(param0, slot);

    if ((param0->monStats[0] == param0->monStats[2]) || (param0->unk_704[slot].curHP == param0->unk_704[slot].maxHP)) {
        Pokemon *mon;
        u32 v1;

        mon = Party_GetPokemonBySlotIndex(param0->partyManagementData->party, slot);
        v1 = param0->unk_704[slot].curHP;
        Pokemon_SetValue(mon, MON_DATA_CURRENT_HP, &v1);
        return 1;
    }

    return 0;
}

static u8 HandleSpecialInput(GameWindowLayout *param0)
{
    u8 v0;

    if (gSystem.pressedKeys & PAD_BUTTON_A) {
        if (param0->partySlot == 7) {
            if (param0->unk_B0F_7 == 0) {
                Sound_PlayEffect(SEQ_SE_CONFIRM);
                return 3;
            }
        } else {
            if (param0->unk_704[param0->partySlot].unk_10 == 0) {
                Sound_PlayEffect(SEQ_SE_CONFIRM);
                return 0;
            } else {
                Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
            }
        }

        return 5;
    }

    if (gSystem.pressedKeys & PAD_BUTTON_B) {
        if (param0->unk_B0F_7 == 0) {
            Sound_PlayEffect(SEQ_SE_CONFIRM);
            param0->partySlot = 7;
            return 3;
        }

        return 5;
    }

    v0 = sub_0207FA00(param0);

    if (v0 == 2) {
        if (param0->unk_704[param0->partySlot].unk_10 != 0) {
            Sound_PlayEffect(SEQ_SE_DP_CUSTOM06);
            return 5;
        }
    }

    return v0;
}

static int ApplyItemEffectOnPokemon(GameWindowLayout *param0)
{
    ItemData *v0 = Item_Load(param0->partyManagementData->usedItemID, 0, 12);

    if ((param0->partyManagementData->usedItemID == 466) && (Pokemon_CanShayminSkyForm(Party_GetPokemonBySlotIndex(param0->partyManagementData->party, param0->partySlot)) == 1)) {
        param0->partyManagementData->evoTargetSpecies = 1;
        Heap_Free(v0);
        LoadOverlay118(param0);
        return 31;
    }

    if ((Item_Get(v0, 34) != 0) || (Item_Get(v0, 35) != 0)) {
        Heap_Free(v0);
        sub_020866A0(param0, 0);
        return 6;
    }

    if ((Item_Get(v0, 36) != 0) && (Item_Get(v0, 37) == 0)) {
        Heap_Free(v0);
        sub_020866A0(param0, 1);
        return 6;
    }

    if (Party_CheckItemEffectsOnMember(param0->partyManagementData->party, param0->partyManagementData->usedItemID, param0->partySlot, 0, 12) == 1) {
        Bag_TryRemoveItem(param0->partyManagementData->bag, param0->partyManagementData->usedItemID, 1, HEAP_ID_12);

        if (Item_Get(v0, 26) != 0) {
            Pokemon *v1 = Party_GetPokemonBySlotIndex(param0->partyManagementData->party, param0->partySlot);

            param0->partyManagementData->evoTargetSpecies = Pokemon_GetEvolutionTargetSpecies(NULL, v1, EVO_CLASS_BY_ITEM, param0->partyManagementData->usedItemID, &param0->partyManagementData->evoType);
            param0->partyManagementData->menuSelectionResult = 8;
            Heap_Free(v0);
            return 32;
        }

        if ((Item_IsHerbalMedicine(param0->partyManagementData->usedItemID) == 1) && (param0->partyManagementData->broadcast != NULL)) {
            Pokemon *v2 = Party_GetPokemonBySlotIndex(param0->partyManagementData->party, param0->partySlot);
            sub_0206D90C(param0->partyManagementData->broadcast, v2, param0->partyManagementData->usedItemID);
        }

        sub_020852B8(param0);
    } else {
        sub_02082708(param0, 105, 1);
        param0->partySlot = 7;
        param0->unk_B00 = sub_02085348;
    }

    Heap_Free(v0);
    return 5;
}

static u8 CheckItemUsageValidity(GameWindowLayout *param0)
{
    if (param0->unk_704[param0->partySlot].unk_0C == 0) {
        return 0;
    } else if (Item_IsMail(param0->unk_704[param0->partySlot].unk_0C) == 1) {
        return 2;
    }

    return 1;
}

static int ProcessItemApplication(GameWindowLayout *param0)
{
    Pokemon *v0;
    Window *v1;
    int v2 = -1, v3;
    FieldSystem *fieldSystem;

    v0 = Party_GetPokemonBySlotIndex(param0->partyManagementData->party, param0->partySlot);
    v1 = &param0->unk_04[34];
    fieldSystem = param0->partyManagementData->fieldSystem;

    if (param0->partyManagementData->usedItemID == 112) {
        if (Pokemon_GetValue(v0, MON_DATA_SPECIES, NULL) != SPECIES_GIRATINA) {
            MessageLoader_GetStrbuf(param0->messageLoader, 203, param0->unk_6A8);
            StringTemplate_SetNickname(param0->template, 0, Pokemon_GetBoxPokemon(v0));
            StringTemplate_SetItemNameWithArticle(param0->template, 1, param0->partyManagementData->usedItemID);
            StringTemplate_Format(param0->template, param0->unk_6A4, param0->unk_6A8);
            v2 = 11;
        } else if (fieldSystem != NULL) {
            if (fieldSystem->location->mapId == MAP_HEADER_UNION_ROOM) {
                MessageLoader_GetStrbuf(param0->messageLoader, 204, param0->unk_6A8);
                StringTemplate_SetItemName(param0->template, 0, param0->partyManagementData->usedItemID);
                StringTemplate_Format(param0->template, param0->unk_6A4, param0->unk_6A8);
                v2 = 11;
            }
        }
    }

    if (v2 == -1) {
        switch (CheckItemUsageValidity(param0)) {
        case 0:
            if (Item_IsMail(param0->partyManagementData->usedItemID) == 1) {
                param0->partyManagementData->menuSelectionResult = 6;
                return 32;
            }

            v2 = UpdatePokemonWithItem(param0, v0, &v3);

            MessageLoader_GetStrbuf(param0->messageLoader, 118, param0->unk_6A8);
            StringTemplate_SetNickname(param0->template, 0, Pokemon_GetBoxPokemon(v0));
            StringTemplate_SetItemName(param0->template, 1, param0->partyManagementData->usedItemID);
            StringTemplate_Format(param0->template, param0->unk_6A4, param0->unk_6A8);
            break;
        case 1:
            MessageLoader_GetStrbuf(param0->messageLoader, 78, param0->unk_6A8);
            StringTemplate_SetNickname(param0->template, 0, Pokemon_GetBoxPokemon(v0));
            StringTemplate_SetItemNameWithArticle(param0->template, 1, param0->unk_704[param0->partySlot].unk_0C);
            StringTemplate_Format(param0->template, param0->unk_6A4, param0->unk_6A8);
            v2 = 9;
            break;
        case 2:
            MessageLoader_GetStrbuf(param0->messageLoader, 77, param0->unk_6A4);
            v2 = 11;
            break;
        }
    }

    Window_DrawMessageBoxWithScrollCursor(v1, 1, 1 + 9, 15);
    Window_FillTilemap(v1, 15);
    sub_0208274C(param0);

    return v2;
}

static int UpdatePokemonWithItem(GameWindowLayout *param0, Pokemon *mon, int *param2)
{
    u32 item = param0->partyManagementData->usedItemID;
    FieldSystem *fieldSystem = param0->partyManagementData->fieldSystem;

    Bag_TryRemoveItem(param0->partyManagementData->bag, param0->partyManagementData->usedItemID, 1, HEAP_ID_12);
    Pokemon_SetValue(mon, MON_DATA_HELD_ITEM, &item);
    Pokemon_SetArceusForm(mon);

    if ((fieldSystem == NULL) || (fieldSystem->location->mapId < 573) || (fieldSystem->location->mapId > 583)) {
        *param2 = Pokemon_SetGiratinaFormByHeldItem(mon);
    } else {
        *param2 = -1;
    }

    param0->unk_704[param0->partySlot].unk_0C = param0->partyManagementData->usedItemID;
    sub_02083040(param0, param0->partySlot, param0->unk_704[param0->partySlot].unk_0C);

    if (item == ITEM_GRISEOUS_ORB && ((*param2) != -1)) {
        return 12;
    }

    return 11;
}

static void SwapPokemonItem(GameWindowLayout *param0, Pokemon *mon, u32 param2, u32 param3)
{
    Bag_TryAddItem(param0->partyManagementData->bag, (u16)param2, 1, HEAP_ID_12);
    Pokemon_SetValue(mon, MON_DATA_HELD_ITEM, &param3);
    Pokemon_SetArceusForm(mon);
    Pokemon_SetGiratinaFormByHeldItem(mon);
    param0->unk_704[param0->partySlot].unk_0C = (u16)param3;
    sub_02083040(param0, param0->partySlot, param0->unk_704[param0->partySlot].unk_0C);
}

static int HandleMessageCompletion(GameWindowLayout *param0)
{
    if (Text_IsPrinterActive(param0->textPrinterID) == 0) {
        if (gSystem.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
            return ResetWindowOnInput(param0);
        }
    }

    return 11;
}

static int ProcessMessageResult(GameWindowLayout *param0)
{
    if (Text_IsPrinterActive(param0->textPrinterID) == 0) {
        if (gSystem.pressedKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
            Window_EraseMessageBox(&param0->unk_04[34], 1);
            LoadOverlay118(param0);
            return 13;
        }
    }

    return 12;
}

static int HandleOverlayCompletion(GameWindowLayout *param0)
{
    if (ov118_021D0DBC(param0) == 1) {
        UnloadOverlay118(param0);

        return 11;
    }

    return 13;
}

static int FinalizeMessageProcessing(GameWindowLayout *param0)
{
    if (Text_IsPrinterActive(param0->textPrinterID) == 0) {
        sub_020827EC(param0);
        return 10;
    }

    return 9;
}

static int ProcessPokemonItemSwap(GameWindowLayout *param0)
{
    int v0, v1;

    switch (Menu_ProcessInputAndHandleExit(param0->unk_700, 12)) {
    case 0: {
        Pokemon *v2;
        Window *v3;
        u32 v4;
        u32 v5;

        v2 = Party_GetPokemonBySlotIndex(param0->partyManagementData->party, param0->partySlot);
        v3 = &param0->unk_04[34];
        v4 = param0->partyManagementData->usedItemID;
        v5 = param0->unk_704[param0->partySlot].unk_0C;
        v0 = UpdatePokemonWithItem(param0, v2, &v1);

        if (Bag_TryAddItem(param0->partyManagementData->bag, (u16)v5, 1, HEAP_ID_12) == FALSE) {
            SwapPokemonItem(param0, v2, v4, v5);
            MessageLoader_GetStrbuf(param0->messageLoader, 83, param0->unk_6A4);
            v0 = 11;
        } else {
            if (Item_IsMail(param0->partyManagementData->usedItemID) == 1) {
                Bag_TryRemoveItem(param0->partyManagementData->bag, (u16)v5, 1, HEAP_ID_12);
                SwapPokemonItem(param0, v2, v4, v5);
                param0->partyManagementData->menuSelectionResult = 6;
                return 32;
            }

            MessageLoader_GetStrbuf(param0->messageLoader, 84, param0->unk_6A8);
            StringTemplate_SetItemName(param0->template, 1, v5);
            StringTemplate_SetItemName(param0->template, 2, v4);
            StringTemplate_Format(param0->template, param0->unk_6A4, param0->unk_6A8);

            if ((v4 != 112) && (v5 == 112) && (v1 != -1)) {
                v0 = 12;
            } else if ((v4 == 112) && (v5 == 112)) {
                v0 = 11;
            }
        }

        Window_FillTilemap(v3, 15);
        sub_0208274C(param0);
    }
        return v0;
    case 0xfffffffe:
        return ResetWindowOnInput(param0);
    }

    return 10;
}

static int ResetWindowOnInput(GameWindowLayout *param0)
{
    if (param0->partyManagementData->unk_20 == 10) {
        Window_EraseMessageBox(&param0->unk_04[34], 1);
        sub_020826E0(param0, 29, 1);
        Sprite_SetExplicitPalette2(param0->unk_5B0[6], 0);
        param0->partyManagementData->unk_20 = 0;
        return 1;
    }

    param0->partyManagementData->menuSelectionResult = 10;
    return 32;
}

static int UpdatePokemonFormWithItem(GameWindowLayout *param0)
{
    Pokemon *v0;
    Window *v1;
    u32 v2;
    u32 item;
    int v4, v5;

    v0 = Party_GetPokemonBySlotIndex(param0->partyManagementData->party, param0->partySlot);
    v1 = &param0->unk_04[34];
    v2 = param0->partyManagementData->usedItemID;
    item = param0->unk_704[param0->partySlot].unk_0C;
    v4 = UpdatePokemonWithItem(param0, v0, &v5);

    if ((item == ITEM_GRISEOUS_ORB) && (v4 == 11) && (v5 == 0)) {
        v4 = 12;
    }

    if (item == ITEM_NONE) {
        MessageLoader_GetStrbuf(param0->messageLoader, 118, param0->unk_6A8);
        StringTemplate_SetNickname(param0->template, 0, Pokemon_GetBoxPokemon(v0));
        StringTemplate_SetItemName(param0->template, 1, param0->partyManagementData->usedItemID);
        StringTemplate_Format(param0->template, param0->unk_6A4, param0->unk_6A8);
    } else {
        Bag_TryAddItem(param0->partyManagementData->bag, (u16)item, 1, HEAP_ID_12);
        MessageLoader_GetStrbuf(param0->messageLoader, 84, param0->unk_6A8);
        StringTemplate_SetItemName(param0->template, 1, item);
        StringTemplate_SetItemName(param0->template, 2, v2);
        StringTemplate_Format(param0->template, param0->unk_6A4, param0->unk_6A8);
    }

    Window_DrawMessageBoxWithScrollCursor(v1, 1, 1 + 9, 15);
    Window_FillTilemap(v1, 15);
    sub_0208274C(param0);

    if (param0->partyManagementData->unk_20 == 12) {
        param0->partyManagementData->unk_20 = 10;
    }

    return v4;
}

static int CheckForItemApplication(GameWindowLayout *param0)
{
    if (param0->unk_704[param0->partySlot].unk_12 == 0) {
        param0->partyManagementData->menuSelectionResult = 0;
        return 32;
    }

    Sprite_SetExplicitPalette2(param0->unk_5B0[6], 1);
    sub_02082708(param0, 195, 1);
    param0->unk_B04.unk_00 = sub_02083A78;
    param0->unk_B04.unk_04 = sub_02083AA4;
    param0->unk_B0E = 26;
    return 24;
}

static BOOL ValidateGameWindowState(GameWindowLayout *param0)
{
    if ((param0->partyManagementData->unk_20 == 5) || (param0->partyManagementData->unk_20 == 6) || (param0->partyManagementData->unk_20 == 7) || (param0->partyManagementData->unk_20 == 8) || (param0->partyManagementData->unk_20 == 9) || (param0->partyManagementData->unk_20 == 11) || (param0->partyManagementData->unk_20 == 14) || (param0->partyManagementData->unk_20 == 16) || (param0->partyManagementData->unk_20 == 20)) {
        return 0;
    }

    return 1;
}

u32 sub_02081930(void)
{
    return 20;
}

u32 sub_02081934(void)
{
    return 21;
}

u32 sub_02081938(void)
{
    return 19;
}

u32 sub_0208193C(void)
{
    return 18;
}

void LoadScreenDataFromNARC(u32 param0, u16 *param1, u16 *param2, u16 *param3)
{
    NNSG2dScreenData *v0;
    void *v1;
    u16 *v2;
    u32 v3;

    v1 = NARC_AllocAndReadWholeMemberByIndexPair(NARC_INDEX_GRAPHIC__PL_PLIST_GRA, 22, param0);
    NNS_G2dGetUnpackedScreenData(v1, &v0);
    v2 = (u16 *)v0->rawData;

    for (v3 = 0; v3 < 6; v3++) {
        memcpy(&param1[v3 * 16], &v2[(0 + v3) * 32], 16 * 2);
        memcpy(&param2[v3 * 16], &v2[(6 + v3) * 32], 16 * 2);
        memcpy(&param3[v3 * 16], &v2[((6 + 6) + v3) * 32], 16 * 2);
    }

    Heap_Free(v1);
}

void LoadOverlay118(GameWindowLayout *windowLayout)
{
    Overlay_LoadByID(FS_OVERLAY_ID(overlay118), 2);
    ov118_021D0D80(windowLayout);
}

void UnloadOverlay118(GameWindowLayout *windowLayout)
{
    Overlay_UnloadByID(FS_OVERLAY_ID(overlay118));
}
