#include QMK_KEYBOARD_H

/*
| Full Modifier Name | Abbreviation | Symbol |
| Shift              | S            | ⇧      |
| Control            | C            | ⎈      |
| Alt/Option         | A            | ⎇      |
| SYMBOL             | Sym          | $      |
| GUI/Win/Command    | G            | ◆      |
Order now is GACS.
*/

// Left-hand home row mods
// #define HOME_A LGUI_T(KC_A)
// #define HOME_R LALT_T(KC_R)
#define SYMB_R LT(1, KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
// #define HOME_I LALT_T(KC_I)
#define SYMB_I LT(1, KC_I)
// #define HOME_O RGUI_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
*  | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   +  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |BackSP|  A   |  R $ |  S ⎈ |  T ⇧ |   G  |-------.    ,-------|  M   |  N ⇧ |  E ⎈ |  I $ |  O   |   '  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | Alt  |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |  ,   |   .  |   /  |  Alt |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |Enter | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|Delete|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
	[0] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
    KC_BSPC, KC_A,    SYMB_R,  HOME_S,  HOME_T,  KC_G,                      KC_M,    HOME_N,  HOME_E,  SYMB_I,  KC_O,    KC_QUOT,
    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_LBRC, KC_RBRC, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
                               KC_ENT,  KC_LGUI, MO(3),   KC_SPC,  KC_ENT,  MO(2),   KC_BSPC, KC_DEL
    ),
/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   `  |   ~  |   #  |   &  |   |  |                    |   !  |   {  |   }  |   [  |   ]  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   '  |   _  |   :  |   "  |   $  |-------.    ,-------|   =  |   (  |   )  |   _  |   ;  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |   %  |   ?  |   *  |   +  |   \  |-------|    |-------|   /  |   -  |   <  |   >  |   '  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |Enter | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|Delete|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [1] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 ,
    _______, KC_GRV,  KC_TILD, KC_HASH, KC_AMPR, KC_PIPE,                   KC_EXLM, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
    _______, KC_QUOT, KC_UNDS, KC_COLN, KC_DQUO, KC_DLR ,                   KC_EQL , KC_LPRN, KC_RPRN, KC_UNDS, KC_SCLN, _______,
    _______, KC_PERC, KC_QUES, KC_ASTR, KC_PLUS, KC_BSLS, _______, _______, KC_SLSH, KC_MINS, KC_LABK, KC_RABK, KC_QUOT, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
    ),
/* RAISE  | NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | Print|      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |PageUp|      |PageDn|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  Alt | Ctrl |Shift |      |-------.    ,-------| Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | Home |      | End  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |Enter | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|Delete|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [2] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                     KC_PSCR, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     _______, KC_PGUP, _______, KC_PGDN, _______, _______,
    XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,  XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
                               _______, _______, _______,  _______, _______,  _______, _______, _______
    ),
/* LOWER | SHORTCUTS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |ShftF6|AltF12|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |Ctrl-A|CtShfR|Ctrl-S|CtShfT|CtAltL|-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |Ctrl-Z|Ctrl-X|Ctrl-C|Ctrl-B|Ctrl-V|-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |Enter | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|Delete|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [3] = LAYOUT(
    KC_F1  , KC_F2   , KC_F3     , KC_F4  , KC_F5     , KC_F6    ,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 ,
    XXXXXXX, XXXXXXX , XXXXXXX   , XXXXXXX, S(KC_F6)  , A(KC_F12),                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, C(KC_A) , C(S(KC_R)), C(KC_S), C(S(KC_T)), LCA(KC_L),                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, C(KC_Z) , C(KC_X)   , C(KC_C), C(KC_B)   , C(KC_V)  ,  _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                _______   , _______    , _______   ,  _______, _______,  _______, _______, _______
    )
};

const uint16_t PROGMEM LALT_COMBO[]         = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM LALT_CTRL_COMBO[]    = { KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM LCTRL_COMBO[]        = { KC_Z, KC_X, COMBO_END};

const uint16_t PROGMEM RALT_COMBO[]         = { KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM RALT_CTRL_COMBO[]    = { KC_COMMA, KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM RCTRL_COMBO[]        = { KC_DOT, KC_SLSH, COMBO_END};

const uint16_t PROGMEM LGUI_COMBO[]         = { KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM RGUI_COMBO[]         = { KC_Y, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(LALT_COMBO,       KC_LEFT_ALT),
    COMBO(LALT_CTRL_COMBO,  LCTL(KC_LEFT_ALT)),
    COMBO(LCTRL_COMBO,      KC_LEFT_CTRL),
    COMBO(RALT_COMBO,       KC_RIGHT_ALT),
    COMBO(RALT_CTRL_COMBO,  LCTL(KC_RIGHT_ALT)),
    COMBO(RCTRL_COMBO,      KC_RIGHT_CTRL),
    COMBO(LGUI_COMBO,       KC_LEFT_GUI),
    COMBO(RGUI_COMBO,       KC_RIGHT_GUI),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A:
            return TAPPING_TERM + 150;
        case KC_O:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}
