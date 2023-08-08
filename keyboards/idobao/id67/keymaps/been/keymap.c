// Copyright 2021 Tybera (@tybera)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum my_layers {
    _QWERTY = 0,
    _FNROW,
    _CTRL,
    _ALT
};

enum alt_keycodes {
    RBG_CLR,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_ansi_blocker(
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        LM(_CTRL,MOD_LCTL), KC_LGUI,  LM(_ALT,MOD_LALT),                            KC_SPC,                             KC_RALT, MO(_FNROW),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_FNROW] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI,  LGUI(LSFT(KC_S)), RGB_SAI, _______, _______,_______, KC_PSCR, _______, _______, _______, KC_END, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD,_______ ,RGB_SAD ,_______ , _______, LGUI(KC_L), _______, _______,          KC_WSCH, _______, \
        _______, RGB_TOG, RBG_CLR, _______, _______, QK_BOOT, _______, KC_MAIL, _______, _______, _______, _______,          KC_VOLU, _______, \
        _______, _______, EE_CLR,                            KC_MPLY,                            _______, _______, KC_MPRV, KC_VOLD, KC_MNXT  \
    ),
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static uint32_t key_timer;

    switch (keycode) {
        default:
            return true; //Process all other keycodes normally
    }
}


void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        rgblight_sethsv(HSV_RED);

    } else {
         rgblight_sethsv(HSV_CYAN);
    }
} 
