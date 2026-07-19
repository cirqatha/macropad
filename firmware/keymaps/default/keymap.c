#include QMK_KEYBOARD_H

// volume level tracker (0 to 100)
static uint8_t vol_level = 50;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LCTL(LGUI(KC_LEFT)),  LCTL(LGUI(KC_RGHT)),
        LCTL(LGUI(KC_D)),     KC_MUTE
    )
};

// updates RGB based on volume level
void update_rgb(void) {
    if (vol_level < 33) {
        rgblight_setrgb_at(0, 255, 0, 0);
        rgblight_setrgb_at(0, 255, 0, 1);
        rgblight_setrgb_at(0, 0, 0, 2);
        rgblight_setrgb_at(0, 0, 0, 3);
        rgblight_setrgb_at(0, 0, 0, 4);
        rgblight_setrgb_at(0, 0, 0, 5);
    } else if (vol_level < 66) {
        rgblight_setrgb_at(0, 255, 0, 0);
        rgblight_setrgb_at(0, 255, 0, 1);
        rgblight_setrgb_at(255, 255, 0, 2);
        rgblight_setrgb_at(255, 255, 0, 3);
        rgblight_setrgb_at(0, 0, 0, 4);
        rgblight_setrgb_at(0, 0, 0, 5);
    } else {
        rgblight_setrgb_at(0, 255, 0, 0);
        rgblight_setrgb_at(0, 255, 0, 1);
        rgblight_setrgb_at(255, 255, 0, 2);
        rgblight_setrgb_at(255, 255, 0, 3);
        rgblight_setrgb_at(255, 0, 0, 4);
        rgblight_setrgb_at(255, 0, 0, 5);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
        if (vol_level < 100) vol_level++;
    } else {
        tap_code(KC_VOLD);
        if (vol_level > 0) vol_level--;
    }
    update_rgb();
    return false;
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    update_rgb();
}