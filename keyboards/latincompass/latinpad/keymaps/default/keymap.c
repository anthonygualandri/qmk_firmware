 /* Keymap _0: (Base Layer) Default Layer

   * .-----------.
   * |PGUP | PGDN|
   * |-----------------------.
   * |  7  |  8  |  9  | MO1 |
   * |-----|-----|-----|-----|
   * |  4  |  5  |  6  |  +  |
   * |-----|-----|-----|-----|
   * |  1  |  2  |  3  |  —  |
   * |-----|-----|-----|-----|
   * |  0  |  .  | DEL |Enter|
   * .-----------------------.
   */
     /* Keymap _1: (Second Layer) second Layer

   * .---------------.
   * |NUMLOCK|Calc.  |
   * |--------------------------------.
   * |RM_TOGG|RM_NEXT|RGB_M_K|RGB_M_X |
   * |-------|-------|-------|--------|
   * |RM_SATU|RM_SATD|RM_HUEU|RM_HUED |
   * |-------|-------|-------|--------|
   * |RM_VALU|RM_VALD|RM_SPDU|RM_SPDD |
   * |-------|-------|-------|--------|
   * |RM_SPDU|RM_SPDD|RM_TOGG|KC_TRNS |
   * .--------------------------------.
*/

#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_PGUP, KC_PGDN,
        KC_KP_7, KC_KP_8, KC_KP_9, MO(1),
        KC_P4, KC_P5, KC_P6, KC_KP_PLUS,
        KC_P1, KC_P2, KC_P3, KC_KP_MINUS,
        KC_P0, KC_PDOT,KC_DELETE, KC_KP_ENTER),
    [1] = LAYOUT(
        KC_NUM, KC_CALCULATOR,
        RM_TOGG, RM_NEXT, RGB_M_K, RGB_M_X,
        RM_SATU, RM_SATD, RM_HUEU, RM_HUED,
        RM_VALU, RM_VALD, RM_SPDU, RM_SPDD,
        RM_SPDU, RM_SPDD, RM_TOGG, KC_TRNS),
};

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,  0};
    oled_write_P(qmk_logo, false);
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    return false;
}
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      tap_code(KC_AUDIO_VOL_UP);
    } else {
      tap_code(KC_AUDIO_VOL_DOWN);
    }
  } else if (index == 1) {
    if (clockwise) {
      tap_code(KC_BRIGHTNESS_UP);
    } else {
      tap_code(KC_BRIGHTNESS_DOWN);
    }
  }
    return true;
}
void matrix_init_user(void) { render_logo(); }
