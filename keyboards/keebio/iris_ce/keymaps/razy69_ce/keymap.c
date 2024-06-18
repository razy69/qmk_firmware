#include QMK_KEYBOARD_H

// LAYERS ==================================================================

enum layers {
  _QWERTY,
  _GAME,
  _RAISE,
  _MORE,
};


// LEDS  ===================================================================

#define HSV_AZURE_       132, 102, rgb_matrix_get_val()
#define HSV_BLUE_        170, 255, rgb_matrix_get_val()
#define HSV_CHARTREUSE_   64, 255, rgb_matrix_get_val()
#define HSV_CORAL_        11, 176, rgb_matrix_get_val()
#define HSV_CYAN_        128, 255, rgb_matrix_get_val()
#define HSV_GOLD_         36, 255, rgb_matrix_get_val()
#define HSV_GREEN_        85, 255, rgb_matrix_get_val()
#define HSV_MAGENTA_     213, 255, rgb_matrix_get_val()
#define HSV_ORANGE_       21, 255, rgb_matrix_get_val()
#define HSV_PINK_        234, 128, rgb_matrix_get_val()
#define HSV_PURPLE_      191, 255, rgb_matrix_get_val()
#define HSV_RED_           0, 255, rgb_matrix_get_val()
#define HSV_SPRINGGREEN_ 106, 255, rgb_matrix_get_val()
#define HSV_WHITE_         0,   0, rgb_matrix_get_val()
#define HSV_YELLOW_       43, 255, rgb_matrix_get_val()

#define HSV_DEFAULT HSV_SPRINGGREEN_

layer_state_t layer_state_set_user(layer_state_t state) {
	switch(get_highest_layer(state)) {
		case _GAME:
      rgb_matrix_sethsv_noeeprom(HSV_RED_);
			break;
    case _RAISE:
      rgb_matrix_sethsv_noeeprom(HSV_AZURE_);
      break;
    case _MORE:
      rgb_matrix_sethsv_noeeprom(HSV_ORANGE_);
      break;
		default:  // for any other layers, or the default layer
			rgb_matrix_sethsv_noeeprom(HSV_DEFAULT);
			break;
    }
	return state;
}


// USER INIT ========================================================================

void keyboard_post_init_user(void) {
  set_single_persistent_default_layer(_QWERTY);
  layer_clear();
  rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE);
	rgb_matrix_sethsv_noeeprom(HSV_DEFAULT);
}


// CUSTOM KEYCODES ==================================================================

#define KC_LESF LSFT_T(KC_LEFT) // left shift as a left key too
#define KC_RGSF RSFT_T(KC_RIGHT) // right shift as a right key too
#define MO_R MO(_RAISE)
#define TO_Q TO(_QWERTY)
#define TO_G TO(_GAME)
#define TO_M TO(_MORE)


// KEYMAP ===========================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
	   KC_ESC  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                            KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		 KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                            KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		 KC_LCTL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                            KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
		 KC_LESF , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ENT ,          KC_DEL , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RGSF,
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
									                  KC_LGUI , MO_R   , KC_BSPC,                   KC_SPC , MO_R   , KC_RALT
	//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
	),

	[_GAME] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
	    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, TO_Q   ,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		  _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		  _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
		  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
		                							  KC_SPC  , KC_LALT, MO_R   ,                   KC_INS , _______, _______
	//                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
	),

	[_RAISE] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                            KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , TO_G   ,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		  _______, KC_HOME, KC_UP  , KC_END , XXXXXXX, TO_M   ,                            TO_M   , XXXXXXX, KC_PGUP, RM_VALU, KC_VOLU, KC_BRIU,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		  _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_EQL ,                            KC_MINS, XXXXXXX, KC_PGDN, RM_VALD, KC_VOLD, KC_BRID,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
		  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_INS ,          KC_ENT , KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, _______,
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
									                  KC_LALT , _______, KC_DEL ,                  KC_BSPC , _______, KC_INS
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
	),

	[_MORE] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, KC_F11 , KC_F12 , KC_F13 , KC_F14 , KC_F15 ,                            KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , XXXXXXX,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
		  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
									                   XXXXXXX, TO_Q   , XXXXXXX,                   XXXXXXX, TO_Q   , XXXXXXX
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
	),
};
