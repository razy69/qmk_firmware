#include QMK_KEYBOARD_H

enum layers {
  QWERTY,
  GAME,
  RAISE
};

// qmk flash -kb keebio/iris/rev6 -km razy69_rev6 -j 0

// LEDS  ===================================================================

void keyboard_post_init_user(void) {
  set_single_persistent_default_layer(QWERTY);
  layer_clear();
  rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE);
  rgb_matrix_sethsv_noeeprom(128, 255, rgb_matrix_get_val()); // TEAL
}

layer_state_t layer_state_set_user(layer_state_t layer_state) {
  switch(get_highest_layer(layer_state)) {
    case GAME:
      rgb_matrix_sethsv_noeeprom(0, 255, rgb_matrix_get_val()); // RED
      break;
    case RAISE:
      rgb_matrix_sethsv_noeeprom(106, 255, rgb_matrix_get_val()); // SPRINGGREEN
      break;
    default: //  for any other layers, or the default layer
      rgb_matrix_sethsv_noeeprom(128, 255, rgb_matrix_get_val()); // TEAL
      break;
    }
  return layer_state;
}


// CUSTOM KEYCODES ==================================================================

// Aliases (shortcuts)
#define KC_LESF LSFT_T(KC_LEFT) // left shift as a left key too
#define KC_RGSF RSFT_T(KC_RIGHT) // right shift as a right key too
#define MO_R MO(RAISE)
#define ESC_TOG LT(GAME, KC_ESC)
#define ESC_TOQ LT(QWERTY, KC_NO)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(QWERTY, KC_NO):
      if (record->tap.count && record->event.pressed) {  // Key is being tapped.
        tap_code16(KC_ESC);
      } else if (record->event.pressed) {  // Key is being held.
        layer_move(QWERTY);
      }
      return false;  // Skip default handling.
    case LT(GAME, KC_ESC):
      if (record->tap.count && record->event.pressed) {  // Key is being tapped.
        tap_code16(KC_ESC);
      } else if (record->event.pressed) {  // Key is being held.
        layer_move(GAME);
      }
      return false;  // Skip default handling.
    }
  return true;
}


// KEYMAP ===========================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      ESC_TOG, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                            KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                            KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                            KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LESF, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ENT ,          KC_DEL , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RGSF,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI , MO_R   , KC_BSPC,                   KC_SPC , MO_R   , KC_RALT
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [GAME] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      ESC_TOQ, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_ESC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_SPC  , KC_LALT, _______,                   KC_INS , _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                            KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_HOME, KC_UP  , KC_END , XXXXXXX, KC_PSCR,                            KC_F12 , KC_F13 , KC_F14 , KC_F15 , KC_VOLU, KC_BRIU,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_EQL ,                            KC_MINS, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_BRID,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_PGUP, XXXXXXX, KC_PGDN, XXXXXXX, KC_LBRC, KC_SPC ,          KC_BSPC, KC_RBRC, RGB_TOG, RGB_VAI, RGB_VAD, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT , _______, KC_DEL ,                   KC_ENT , _______, KC_INS
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};
