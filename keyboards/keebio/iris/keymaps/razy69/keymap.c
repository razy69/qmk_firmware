#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

enum layer_names { QWERTY, GAME, RAISE };

#define QWERTY 0
#define GAME 1
#define RAISE 2

#define KC_LESF LSFT_T(KC_LEFT) // left shift as a left key too - makes perfect sense

// LEDS UNDERGLOW ===================================================================

void led_layer_base(void) {
	rgblight_sethsv_noeeprom(HSV_RED);
	rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
}

void led_layer_game(void) {
	rgblight_sethsv_noeeprom(HSV_GREEN);
	rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
}

void led_layer_raise(void) {
    rgblight_sethsv_noeeprom(HSV_WHITE);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

void keyboard_post_init_user(void) {
	eeconfig_update_default_layer(QWERTY);
	default_layer_set(QWERTY);
    rgblight_enable_noeeprom();
	led_layer_base();
}

layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
		case GAME:
			led_layer_game();
			break;
        case RAISE:
            led_layer_raise();
            break;
		default:  //  for any other layers, or the default layer
			led_layer_base();
			break;
    }
	return state;
}

// KEYMAP ===========================================================================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[QWERTY] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
	LT(RAISE,KC_ESC),KC_1, KC_2  , KC_3   , KC_4   , KC_5   ,                            KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                            KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                            KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
		KC_LESF, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ENT ,          KC_DEL , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, TT(GAME),
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
									  KC_LGUI , KC_LALT, KC_BSPC,                  KC_SPC  ,MO(RAISE), KC_RALT
								  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
	),

	[GAME] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
		KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                            KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                            KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                            KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
		KC_LESF, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ENT ,          KC_DEL , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, TO(QWERTY),
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
									  KC_SPC  , KC_LALT, KC_BSPC,                   KC_INS ,MO(RAISE), KC_RALT
								  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
	),

	[RAISE] = LAYOUT(
	//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                            KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		KC_TAB , EEP_RST, KC_PGUP, KC_UP  , KC_PGDN, KC_ACL0,                            KC_ACL1, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_F12 ,
	//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
		KC_LCTL, DEBUG  , KC_LEFT, KC_DOWN, KC_RIGHT, KC_EQL,                            KC_MINS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_F13,
	//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
		KC_LESF, RESET  , KC_HOME, XXXXXXX, KC_END , KC_LBRC, KC_ENT ,          KC_INS , KC_RBRC, RGB_TOG, RGB_VAI, RGB_VAD, RESET  , _______,
	//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
									  KC_LGUI , KC_LALT, KC_DEL ,                   KC_SPC ,_______ , KC_RALT
  								  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
	)
};
