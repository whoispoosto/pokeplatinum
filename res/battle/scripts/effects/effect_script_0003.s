#include "macros/btlcmd.inc"


_000:
    UpdateVar OPCODE_SET, BTLVAR_SIDE_EFFECT_FLAGS_INDIRECT, MOVE_SIDE_EFFECT_ON_HIT|MOVE_SUBSCRIPT_PTR_DRAIN_HALF_DAMAGE_DEALT
    CalcCrit 
    CalcDamage 
    End 
