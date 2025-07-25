#include "macros/btlcmd.inc"


_000:
    TryStealItem _048, _039
    UpdateVar OPCODE_SET, BTLVAR_MOVE_EFFECT_CHANCE, 1
    UpdateVar OPCODE_FLAG_OFF, BTLVAR_BATTLE_CTX_STATUS, SYSCTL_PLAYED_MOVE_ANIMATION
    PlayMoveAnimation BTLSCR_ATTACKER
    Wait 
    // {0} stole {1}’s {2}!
    PrintMessage pl_msg_00000368_00401, TAG_NICKNAME_NICKNAME_ITEM, BTLSCR_ATTACKER, BTLSCR_DEFENDER, BTLSCR_DEFENDER
    Wait 
    WaitButtonABTime 30
    UpdateMonDataFromVar OPCODE_GET, BTLSCR_DEFENDER, BATTLEMON_HELD_ITEM, BTLVAR_SCRIPT_TEMP
    UpdateMonDataFromVar OPCODE_SET, BTLSCR_ATTACKER, BATTLEMON_HELD_ITEM, BTLVAR_SCRIPT_TEMP
    UpdateMonData OPCODE_SET, BTLSCR_DEFENDER, BATTLEMON_HELD_ITEM, ITEM_NONE
    GoTo _048

_039:
    // {0}’s {1} made {2} ineffective!
    PrintMessage pl_msg_00000368_00714, TAG_NICKNAME_ABILITY_MOVE, BTLSCR_DEFENDER, BTLSCR_DEFENDER, BTLSCR_ATTACKER
    Wait 
    WaitButtonABTime 30

_048:
    End 
