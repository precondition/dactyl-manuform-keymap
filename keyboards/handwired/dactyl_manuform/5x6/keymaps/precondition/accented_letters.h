#pragma once

#include QMK_KEYBOARD_H

enum unicode_names {
        e__ACUT,
        E__ACUT__U,
        u__ACUT,
        U__ACUT__U,
        a__GRAV,
        A__GRAV__U,
        e__GRAV,
        E__GRAV__U,
        u__GRAV,
        U__GRAV__U,
        a__CIRC,
        A__CIRC__U,
        e__CIRC,
        E__CIRC__U,
        i__CIRC,
        I__CIRC__U,
        o__CIRC,
        O__CIRC__U,
        u__CIRC,
        U__CIRC__U,
        i__UML,
        I__UML__U,
        o__UML,
        O__UML__U,
        c__CDIL,
        C__CDIL__U
};

const uint32_t PROGMEM unicode_map[] = {
    [e__ACUT] = 0x00E9,
    [E__ACUT__U] = 0x00C9,
    [u__ACUT] = 0x00F9,
    [U__ACUT__U] = 0x00D9,
    [a__GRAV] = 0x00E0,
    [A__GRAV__U] = 0x00C0,
    [e__GRAV] = 0x00E8,
    [E__GRAV__U] = 0x00C8,
    [u__GRAV] = 0x00F9,
    [U__GRAV__U] = 0x00D9,
    [a__CIRC] = 0x00E2,
    [A__CIRC__U] = 0x00C2,
    [e__CIRC] = 0x00EA,
    [E__CIRC__U] = 0x00CA,
    [i__CIRC] = 0x00EE,
    [I__CIRC__U] = 0x00CE,
    [o__CIRC] = 0x00F4,
    [O__CIRC__U] = 0x00D4,
    [u__CIRC] = 0x00FB,
    [U__CIRC__U] = 0x00DB,
    [i__UML]  = 0x00EF,
    [I__UML__U]  = 0x00CF,
    [o__UML]  = 0x00F6,
    [O__UML__U]  = 0x00DC,
    [c__CDIL] = 0x00E7,
    [C__CDIL__U] = 0x00C7
};

#define E_ACUTE XP(e__ACUT, E__ACUT__U)
#define U_ACUTE XP(u__ACUT, U__ACUT__U)
#define A_GRAVE XP(a__GRAV, A__GRAV__U)
#define E_GRAVE XP(e__GRAV, E__GRAV__U)
#define U_GRAVE XP(u__GRAV, U__GRAV__U)
#define A_CIRCU XP(a__CIRC, A__CIRC__U)
#define E_CIRCU XP(e__CIRC, E__CIRC__U)
#define I_CIRCU XP(i__CIRC, I__CIRC__U)
#define O_CIRCU XP(o__CIRC, O__CIRC__U)
#define U_CIRCU XP(u__CIRC, U__CIRC__U)
#define I_UMLAU XP(i__UML ,  I__UML__U)
#define O_UMLAU XP(o__UML ,  O__UML__U)
#define C_CDILA XP(c__CDIL, C__CDIL__U)

