#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

enum layer_names { _QWERTY, _RAISE, _GAME };
enum custom_keycodes { QWERTY = SAFE_RANGE, RAISE, GAME };

#define _QWERTY 0
#define _RAISE 1
#define _GAME 2

#define KC_ KC_TRNS
#define KC_QWERTY QWERTY
#define KC_RAISE RAISE
#define KC_GAME GAME
#define KC_LESF LSFT_T(KC_LEFT) // left shift as a left key too - makes perfect sense

// LEDS UNDERGLOW ===================================================================
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_RED},       // Light 6 LEDs, starting with LED 1
    {6, 6, HSV_RED}
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_WHITE},
    {6, 6, HSV_WHITE}
);
const rgblight_segment_t PROGMEM game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_GREEN},
    {6, 6, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    raise_layer,
    game_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

// LAYERS ===========================================================================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_RAISE);
            }
            return false;
            break;
        case GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
            break;
    }
    return true;
}

// KEYMAP ===========================================================================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GESC  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                            KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TAB   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                            KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LCTL  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                            KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LESF  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ENT ,          KC_DEL , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, TT(2)  ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI , KC_LALT, KC_BSPC,                   KC_SPC , MO(1)  , KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_ESC   , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                            KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TAB   , KC_NO  , KC_PGUP, KC_UP  , KC_PGDN, KC_NO  ,                            KC_F12 , KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LCTL  , KC_NO  , KC_LEFT, KC_DOWN, KC_RIGHT, KC_EQL,                            KC_MINS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_F18 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LESF  , KC_NO  , KC_HOME, KC_NO  , KC_END , KC_LBRC, KC_ENT ,          KC_INS , KC_RBRC, KC_NO  , KC_NO  , KC_NO  , KC_PSCR, TT(2)  ,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI , KC_LALT, KC_DEL ,                   KC_SPC , KC_NO  , KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_GAME] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GESC  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                            KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TAB   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                            KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LCTL  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                            KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LESF  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ENT ,          KC_DEL , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, TO(0),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_SPC  , KC_LALT, KC_BSPC,                   KC_LGUI, MO(1)  , KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    )
};
