#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols
    DVORAK,
    DVORAK_SYML,
    GAME, // games
    MDIA, // media keys
    MOVE, // move
    NUME, // numberic
    FKEY, // F-keys
    SERV, // service
};

// [Key Lock](feature_key_lock.md)
// |`QK_LOCK`|Hold down the next key pressed, until the key is pressed again|
//
// [Layer Switching](feature_layers.md#switching-and-toggling-layers)
// |`DF(layer)`     |Set the base (default) layer                                                      |
// |`MO(layer)`     |Momentarily turn on `layer` when pressed (requires `KC_TRNS` on destination layer)|
// |`OSL(layer)`    |Momentarily activates `layer` until a key is pressed. See [One Shot Keys](one_shot_keys.md) for details. |
// |`LM(layer, mod)`|Momentarily turn on `layer` (like MO) with `mod` active as well.  Where `mod` is a mods_bit.  Mods can be viewed [here](mod_tap.md).  Example Implementation: `LM(LAYER_1, MOD_LALT)`|
// |`LT(layer, kc)` |Turn on `layer` when held, `kc` when tapped                                       |
// |`TG(layer)`     |Toggle `layer` on or off                                                          |
// |`TO(layer)`     |Turns on `layer` and turns off all other layers, except the default layer |
// |`TT(layer)`     |Normally acts like MO unless it's tapped multiple times, which toggles `layer` on |
//
// [One Shot Keys](one_shot_keys.md)
// |`OSM(mod)`          |         |Hold `mod` for one keypress       |
// |`OSL(layer)`        |         |Switch to `layer` for one keypress|
// |`QK_ONE_SHOT_TOGGLE`|`OS_TOGG`|Toggles One Shot keys status      |
// |`QK_ONE_SHOT_ON`    |`OS_ON`  |Turns One Shot keys on            |
// |`QK_ONE_SHOT_OFF`   |`OS_OFF` |Turns One Shot keys off           |

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  CAPS  |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  | LALT |           | RALT |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  ESC   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| BSPC |           | DEL  |------+------+------+------+------+--------|
 * | LShift |Z/MOVE|X/NUME|   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | LGUI |                                       | RGUI |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | SYMB | SPC  |------|       |------| RCTL   | SYMB |
 *                                 |      |      |  [   |       |  ]   |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  KC_CAPS,        KC_1,          KC_2,          KC_3,     KC_4,    KC_5, XXXXXXX,         XXXXXXX,   KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  KC_TAB,         KC_Q,          KC_W,          KC_E,     KC_R,    KC_T, KC_LALT,         KC_RALT,   KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
  KC_ESC,         KC_A,          KC_S,          KC_D,     KC_F,    KC_G,                             KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  OSM(MOD_LSFT),  LT(MOVE,KC_Z), LT(NUME,KC_X), KC_C,     KC_V,    KC_B, KC_BSPC,         KC_DEL,    KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT),
  MO(SERV),       XXXXXXX,       XXXXXXX,       MO(MDIA), KC_LGUI,                                          KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, MO(SERV),
                                                                XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,
                                                                         XXXXXXX,         XXXXXXX,
                                                       MO(SYMB), KC_SPC, KC_LBRC,         KC_RBRC, KC_LCTL, MO(SYMB)
  ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  !   |   @  |  #   |  $   |  %   |      |           |      |  ^   |  &   |  &   |   *  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  _   | BSCP |  (   |  {   |  [   |------|           |------|  ENT |  -   |  +   |  =   |  :   |  `     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  )   |  }   |  ]   |      |           |      |      | TAB  |  <   |  >   |  ?   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,     KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TILD, KC_UNDS, KC_BSPC, KC_LPRN, KC_LCBR, KC_LBRC,                       KC_ENT,  KC_MINS, KC_PLUS,  KC_EQL,   KC_COLN, KC_GRV,
  KC_TRNS, KC_BSLS, KC_PIPE, KC_RPRN, KC_RCBR, KC_RBRC, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TAB,  KC_LT,    KC_GT,    KC_QUES, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[GAME] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap: Dvorak base
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  +   |  (   |  {   |  [   |  &   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |  ;   |  ,   |  .   |  P   |  Y   |      |           |      |  F   |  G   |  C   |  R   |  L   |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  ESC   |  A   |  O   |  E   |  U   |  I   |------|           |------|  D   |  H   |  T   |  N   |  S   |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LSHIFT |  '   |  Q   |  J   |  K   |  X   |      |           |      |  B   |  M   |  W   |  V   |  Z   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[DVORAK] = LAYOUT_ergodox_pretty(
  KC_CAPS,        KC_PPLS,         KC_LBRC,        KC_LCBR,   KC_LPRN,   KC_AMPR,  XXXXXXX,       XXXXXXX,  KC_EQL,  KC_RPRN,   KC_RCBR,    KC_RBRC,    KC_PAST,      XXXXXXX,
  KC_TAB,         KC_SCLN,         KC_COMM,        KC_DOT,    KC_P,      KC_Y,     XXXXXXX,       XXXXXXX,  KC_F,    KC_G,      KC_C,       KC_R,       KC_L,         KC_SLSH,
  KC_ESC,         KC_A,            KC_O,           KC_E,      KC_U,      KC_I,                              KC_D,    KC_H,      KC_T,       KC_N,       KC_S,         KC_MINS,
  OSM(MOD_LSFT),  LCTL_T(KC_QUOT), LT(NUME, KC_Q), KC_J,      KC_K,      KC_X,     XXXXXXX,       XXXXXXX,  KC_B,    KC_M,      KC_W,       KC_V,       RCTL_T(KC_Z), OSM(MOD_RSFT),
  MO(SERV),       XXXXXXX,         XXXXXXX,        MO(MDIA),  KC_LGUI,                                               KC_LGUI,   XXXXXXX,    XXXXXXX,    XXXXXXX,      MO(SERV),
                                                                         XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX,
                                                                                   XXXXXXX,       XXXXXXX,
                                                               MO(SYMB), KC_SPC,   KC_LBRC,       KC_RBRC,  KC_LCTL,   MO(SYMB)
),

/* Keymap 1: Dvorak Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  :   |   <  |   >  |  $   |  %   |      |           |      |  ^   |  &   |  &   |   *  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  _   | BSCP |  (   |  {   |  [   |------|           |------|  ENT |  -   |  +   |  =   |  :   |  `     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  )   |  }   |  ]   |      |           |      |      | TAB  |  <   |  >   |  ?   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[DOVRAK_SYMB] = LAYOUT_ergodox_pretty(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
                                               XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                                        XXXXXXX,     XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PLAY | STOP |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| PREV | VOLD | VOLU | NEXT |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | MUTE |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_MPLY, KC_MSTP,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_MPRV, KC_VOLD, KC_VOLU,  KC_MNXT,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | HOME | PGDO | PGUP | END  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | LEFT | DOWN |  UP  | RIGHT |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | WHDO | WHUP |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOVE] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_WH_D, KC_WH_U,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  ^   |  7   |  8   |  9   |  ~   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  +   |  4   |  5   |  6   |  -   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | FKEY |  .   |      |      |           |      |  *   |  1   |  2   |  3   |  /   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  =   |  0   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUME] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_CIRC, KC_7,    KC_8,     KC_9,     KC_TILD, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,                       KC_PLUS, KC_4,    KC_5,     KC_6,     KC_MINS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, MO(FKEY), KC_PDOT, KC_TRNS, KC_TRNS,     KC_TRNS, KC_ASTR, KC_1,    KC_2,     KC_3,     KC_SLSH, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,                                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                                KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                         KC_TRNS,     KC_TRNS,
                                       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_EQL, KC_0
),

/* Keymap:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  F10 |  F7  |  F8  |  F9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  F11 |  F4  |  F5  |  F6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  F12 |  F1  |  F2  |  F3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[FKEY] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_F10,  KC_F7,   KC_F8,    KC_F9,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_F11,  KC_F4,   KC_F5,    KC_F6,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_F12,  KC_F1,   KC_F2,    KC_F3,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | RESET  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |on/off| plin | anm+ |      |      | EEPROM |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| hue+ | brt+ | sat+ | spe+ |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |LShift|      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SERV] = LAYOUT_ergodox_pretty(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX, QK_BOOT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, RGB_TOG, RGB_M_P, RGB_MOD,  XXXXXXX,   XXXXXXX, EE_CLR,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     RGB_HUI, RGB_VAI, RGB_SAI,  RGB_SPI, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX,
                                       XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,
                                              XXXXXXX,       XXXXXXX,
                              KC_LSFT, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX
),

};


/* Keymap:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

/* [GAME] = LAYOUT_ergodox_pretty(
 *   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
 *   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
 *   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
 *   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
 *   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
 *                                                KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
 *                                                         KC_TRNS,     KC_TRNS,
 *                                       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
 * ),
 */



const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
[GAME] = {{0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {31, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {31, 255, 255}, {31, 255, 255}, {31, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}, {0, 255, 255}},

[MDIA] = {
// RIGHT
{000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000},
{000, 000, 000}, {243, 222, 234}, {243, 222, 234}, {000, 000, 000}, {000, 000, 000},
{243, 222, 234}, {243, 222, 234}, {243, 222, 234}, {243, 222, 234}, {000, 000, 000},
{000, 000, 000}, {243, 222, 234}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000},
                 {000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000},
// LEFT
{000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000},
{000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000},
{000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000},
{000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000},
                 {000, 000, 000}, {000, 000, 000}, {000, 000, 000}, {000, 000, 000}
  },

[MOVE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {32, 176, 255}, {32, 176, 255}, {32, 176, 255}, {32, 176, 255}, {0, 0, 0}, {10, 225, 255}, {10, 225, 255}, {10, 225, 255}, {10, 225, 255}, {0, 0, 0}, {0, 0, 0}, {32, 176, 255}, {32, 176, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {85, 203, 158}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
[NUME] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {10, 225, 255}, {32, 176, 255}, {32, 176, 255}, {32, 176, 255}, {10, 225, 255}, {10, 225, 255}, {32, 176, 255}, {32, 176, 255}, {32, 176, 255}, {10, 225, 255}, {10, 225, 255}, {32, 176, 255}, {32, 176, 255}, {32, 176, 255}, {10, 225, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
[FKEY] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {10, 225, 255}, {32, 176, 255}, {32, 176, 255}, {32, 176, 255}, {0, 0, 0}, {10, 225, 255}, {32, 176, 255}, {32, 176, 255}, {32, 176, 255}, {0, 0, 0}, {10, 225, 255}, {32, 176, 255}, {32, 176, 255}, {32, 176, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
};
// clang-format on

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

extern rgb_config_t rgb_matrix_config;

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    switch (get_highest_layer(layer_state)) {
        case GAME:
            set_layer_color(GAME);
            break;
        case MDIA:
            set_layer_color(MDIA);
            break;
        case MOVE:
            set_layer_color(MOVE);
            break;
        case NUME:
            set_layer_color(NUME);
            break;
        case FKEY:
            set_layer_color(FKEY);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return false;
}

// Runs whenever there is a layer state change.
uint16_t layer_state_set_user(uint16_t state) {
    uint8_t layer = biton16(state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    return state;
};
