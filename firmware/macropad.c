#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
bool oled_task_kb(void) {
    oled_write_P(PSTR("MACROPAD"), false);
    return false;
}
#endif