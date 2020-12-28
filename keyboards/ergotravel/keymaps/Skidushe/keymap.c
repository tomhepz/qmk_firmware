#include QMK_KEYBOARD_H


#define _HALMAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE
};

#define KC_ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_GON GUI_ON
#define KC_GOFF GUI_OFF
#define KC_NKEY NK_TOGG
#define KC_PND LALT(KC_3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  [_HALMAK] = LAYOUT_kc( // Halmack
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
      ESC,   W,   R,   L,   B,   Z,LPRN,      RPRN,SCLN,   Q,   U,   D,   J,BSPC, 
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
      TAB,   S,   H,   N,   T,COMM,LCBR,      RCBR, DOT,   A,   E,   O,   I,QUOT,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     LSFT,   F,   M,   V,   C,SLSH,LBRC,      RBRC,   G,   P,   X,   K,   Y,RSFT,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     LCTL,LGUI,LALT,EXLM,LOWR, SPC,                 ENT,RASE,LEFT,  UP,DOWN,RGHT
  //`----+----+----+----+----/----/               \----\----+----+----+----+----'
  ),

  [_LOWER] = LAYOUT_kc( // Symbols & Math
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
         ,TILD,CIRC,UNDS,HASH, DLR,    ,          ,PLUS,   7,   8,   9,ASTR,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,  AT,EXLM,AMPR,PIPE, GRV,    ,          ,MINS,   4,   5,   6,SLSH,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,BSLS,    ,    , PND,PERC,    ,          ,   0,   1,   2,   3, EQL,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                    ,    ,    ,    ,    ,    
  //`----+----+----+----+----/----/               \----\----+----+----+----+----'
  ),
   
  [_RAISE] = LAYOUT_kc( // Navigation, Function keys, and media
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
         ,    ,BSPC,  UP, DEL,    ,    ,          ,    ,  F7,  F8,  F9, F10,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,HOME,LEFT,DOWN,RGHT, END,    ,          ,    ,  F4,  F5,  F6, F11,MUTE,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,          ,    ,  F1,  F2,  F3, F12,MPLY,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                    ,    ,MPRV,VOLU,VOLD,MNXT
  //`----+----+----+----+----/----/               \----\----+----+----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
         ,    , RST,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,    ,    ,NKEY,    ,    ,    ,          ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,GOFF,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         , GON,    ,    ,    ,    ,                    ,    ,    ,    ,    ,    
  //`----+----+----+----+----/----/               \----\----+----+----+----+----'
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
