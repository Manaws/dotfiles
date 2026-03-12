#include QMK_KEYBOARD_H
#include <keymap_german.h>
#include <sendstring_german.h>

// Tap Dance declarations
enum tap_keycodes{
    Q,
    A,
    O,
    U,
    S,
    E,
    ALT,
    CP,
    PST,
    POWR,
    UNDO,
    RPRN,
    CPRN,
    SPRN,
    TPRN,
    DECI,
    GRTR,
    LESS,
    TAGO,
    TAGC,
    LN,
    CMNT,
    ARROW,
    AND,
    OR,
    QUOT,
};

enum send_keycodes {
    SS_DOUBLE_ARROW = SAFE_RANGE,
    SS_ARROW,
    SS_NOT_EQUAL,

    SS_GRATER_EQUAL,
    SS_LESSER_EQUAL,
    SS_DOUBLE_RIGHT,
    SS_DOUBLE_LEFT,
    SS_TAG_OPEN,
    SS_TAG_CLOSE,
    SS_COMMENT_OPEN,
    SS_COMMENT_CLOSE,
    SS_EQUAL,
    SS_NOT,
    SS_HELLO,
    SS_AND,
    SS_OR,
    SS_ACUT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [ALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_ALGR),
    [POWR] = ACTION_TAP_DANCE_DOUBLE(KC_KB_POWER, KC_PWR),
    [CP] = ACTION_TAP_DANCE_DOUBLE(C(DE_C), C(DE_X)),
    [PST] = ACTION_TAP_DANCE_DOUBLE(C(DE_V), C(S(DE_V))),
    [UNDO] = ACTION_TAP_DANCE_DOUBLE(KC_UNDO, KC_AGIN),
    [RPRN] = ACTION_TAP_DANCE_DOUBLE(DE_LPRN, DE_RPRN),
    [SPRN] = ACTION_TAP_DANCE_DOUBLE(DE_LCBR, DE_RCBR),
    [CPRN] = ACTION_TAP_DANCE_DOUBLE(DE_LPRN, DE_RPRN),
    [TPRN] = ACTION_TAP_DANCE_DOUBLE(DE_LABK, DE_RABK),
    [DECI] = ACTION_TAP_DANCE_DOUBLE(DE_DOT, DE_COMM),
    [GRTR] = ACTION_TAP_DANCE_DOUBLE(SS_GRATER_EQUAL, SS_DOUBLE_RIGHT),
    [LESS] = ACTION_TAP_DANCE_DOUBLE(SS_LESSER_EQUAL, SS_DOUBLE_LEFT),
    [TAGO] = ACTION_TAP_DANCE_DOUBLE(DE_LABK, SS_TAG_OPEN),
    [TAGC] = ACTION_TAP_DANCE_DOUBLE(DE_RABK, SS_TAG_CLOSE),
    [LN] = ACTION_TAP_DANCE_DOUBLE(SS_COMMENT_OPEN, SS_TAG_CLOSE),
    [CMNT] = ACTION_TAP_DANCE_DOUBLE(SS_EQUAL, SS_NOT_EQUAL),
    [ARROW] = ACTION_TAP_DANCE_DOUBLE(SS_ARROW, SS_DOUBLE_ARROW),
    [OR] = ACTION_TAP_DANCE_DOUBLE(DE_PIPE, SS_OR),
    [AND] = ACTION_TAP_DANCE_DOUBLE(DE_AMPR, SS_AND),
    [QUOT] = ACTION_TAP_DANCE_DOUBLE(DE_DQUO, DE_QUOT),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_DOUBLE_ARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        case SS_ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case SS_NOT_EQUAL:
            if (record->event.pressed) {
                SEND_STRING("!=");
            }
            break;
        case SS_GRATER_EQUAL:
            if (record->event.pressed) {
                SEND_STRING(">=");
            }
            break;
        case SS_LESSER_EQUAL:
            if (record->event.pressed) {
                SEND_STRING("<=");
            }
            break;
        case SS_DOUBLE_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(">>");
            }
            break;

        case SS_DOUBLE_LEFT:
            if (record->event.pressed) {
                SEND_STRING("<<");
            }
            break;

        case SS_TAG_OPEN:
            if (record->event.pressed) {
                SEND_STRING("</");
            }
            break;
        case SS_TAG_CLOSE:
            if (record->event.pressed) {
                SEND_STRING("/>");
            }
            break;
        case SS_EQUAL:
            if (record->event.pressed) {
                SEND_STRING("==");
            }
            break;
        case SS_OR:
            if (record->event.pressed) {
                SEND_STRING("||");
            }
            break;
        case SS_AND:
            if (record->event.pressed) {
                SEND_STRING("&&");
            }
            break;
        case SS_ACUT:
            if (record->event.pressed) {
                SEND_STRING("`");
            }
            break;
    }
    return true;
}


const uint16_t PROGMEM left_strg[] = {DE_U, DE_I, COMBO_END};
const uint16_t PROGMEM left_met[] = {DE_I, DE_A, COMBO_END};
const uint16_t PROGMEM left_shft[] = {DE_A, DE_E, COMBO_END};
const uint16_t PROGMEM right_strg[] = {DE_D, DE_T, COMBO_END};
const uint16_t PROGMEM right_met[] = {DE_T, DE_R, COMBO_END};
const uint16_t PROGMEM right_shft[] = {DE_R, DE_N, COMBO_END};

combo_t key_combos[] = {
    COMBO(left_strg, KC_LCTL),
    COMBO(left_met, KC_LGUI),
    COMBO(left_shft, KC_LSFT),
    COMBO(right_strg, KC_RCTL),
    COMBO(right_met, KC_RGUI),
    COMBO(right_shft, KC_RSFT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  //BLACK (default layer)
  [0] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     KC_TAB,       DE_X,      DE_V,      DE_L,      DE_C,      DE_W,                             DE_K,       DE_H,      DE_G,      DE_F,      DE_Q,      DE_SS,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
      KC_ESC,       DE_U,      DE_I,      DE_A,      DE_E,      DE_O,                           DE_S,       DE_N,      DE_R,      DE_T,      DE_D,     DE_Y,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
      KC_LCTL,       DE_UDIA,      DE_ODIA,     DE_ADIA,      DE_P,      DE_Z,                     DE_B,       DE_M,      DE_COMM,   DE_DOT,    DE_J,    DE_PLUS,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                              LT(2, KC_BSPC),   MO(3),   KC_SPC,       LT(1, KC_ENT),    LT(2, KC_TAB),         TD(ALT)        ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯



  [9] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     XXXXXXX,   DE_AT,     XXXXXXX,   DE_EURO,XXXXXXX,   XXXXXXX,                          XXXXXXX,    DE_UDIA,   XXXXXXX,   DE_ODIA,   XXXXXXX,   KC_DEL,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     KC_LSFT,   DE_ADIA,   DE_SS,   XXXXXXX,   XXXXXXX,   XXXXXXX,                          XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   DE_QUES,   KC_TAB,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     KC_LCTL,   XXXXXXX,   XXXXXXX,   TD(CP),   TD(PST),  XXXXXXX,                          XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  KC_APP,  _______ ,   MO(9),     _______,  XXXXXXX,    _______  ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

  [2] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     QK_GESC,    XXXXXXX,    KC_7,   DE_8,   DE_9,   XXXXXXX,                          KC_WBAK,   KC_WREF ,   KC_WFWD,   XXXXXXX,   XXXXXXX,   KC_WSCH,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     KC_LSFT,    XXXXXXX,   KC_4, KC_5,   KC_6,   XXXXXXX,                              XXXXXXX, KC_LEFT,    KC_DOWN,   KC_UP,   KC_RIGHT,   XXXXXXX,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     KC_LCTL,    XXXXXXX,   KC_1,   KC_2,   KC_3,   XXXXXXX,                          KC_MPRV, KC_MPLY,   KC_MNXT,   XXXXXXX,   KC_VOLD,   KC_VOLU,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  DE_0 ,   _______,   QK_LLCK,      _______, _______,    _______  ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

  [3] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     QK_GESC,    XXXXXXX,   DE_UNDS,  DE_LBRC,   DE_RBRC,   DE_CIRC,                   DE_EXLM,    DE_LABK,   DE_RABK,   DE_EQL,   DE_AMPR,KC_BSPC,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     KC_LSFT,    DE_BSLS,   DE_SLSH,   DE_LCBR,   DE_RCBR,   DE_ASTR,                   DE_QUES,    DE_LPRN,   DE_RPRN,   DE_MINS,   S(DE_DOT), DE_AT,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    KC_LCTL,    DE_HASH,   DE_DLR,   DE_PIPE, ALGR(DE_PLUS),   DE_GRV,                      DE_PLUS,  DE_PERC,  S(DE_HASH),   TD(QUOT),   DE_SCLN,   XXXXXXX,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  KC_LGUI,   _______,   QK_LLCK,      _______, _______,    _______  ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

  [1] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     QK_GESC,    KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,                           KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_BSPC,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     KC_LSFT,    _______,   _______,   _______,   DE_EURO,   KC_F11,                     KC_F12,    _______,   _______,   _______,   _______,   KC_TAB,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     KC_LCTL,    _______,   _______,    TD(CP),   TD(PST),   _______,                    _______,    _______,   _______,   _______,   _______,   _______,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  KC_LGUI,   _______,   QK_LLCK,      _______, _______,    _______  ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

    /*
  //PINK
  [1] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
      KC_ESC,    KC_F1,  KC_F2,   KC_F3,     KC_F4,   KC_F5,                         KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,   XXXXXXX,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
      C(KC_F5),   XXXXXXX,   XXXXXXX,     XXXXXXX,   XXXXXXX,     KC_F11,                         KC_F12,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
       KC_MUTE,      KC_VOLD,  KC_VOLU,    XXXXXXX,     XXXXXXX,  XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MEDIA_PREV_TRACK,    KC_MEDIA_NEXT_TRACK,    KC_MEDIA_PLAY_PAUSE,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  MO(1),   MO(2),    QK_LLCK,      KC_ENT,       MO(3),         MO(4)       ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

  //PURPLE
  [2] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,                             XXXXXXX,    DE_1,      DE_2,      DE_3,      DE_PERC,   KC_BSPC,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     KC_LWIN,    XXXXXXX,    C(KC_S),      C(KC_Z),      C(S(KC_Z)),      XXXXXXX,                          TD(DECI),   DE_4,      DE_5,      DE_6,      DE_MINS,   DE_PLUS,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    KC_BRID,   KC_BRIU,     TD(CP),   TD(PST),    XXXXXXX,                            TD(PRN),    DE_7,      DE_8,      DE_9,      DE_SLSH,   DE_ASTR,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  MO(1),    MO(2),  QK_LLCK,     KC_ENT,       MO(3),       DE_0      ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

  //RED
  [3] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     S(KC_TAB), DE_AT,    KC_UP,   XXXXXXX,  DE_LBRC,   DE_RBRC,                          TD(GRTR),   TD(TAGO),  TD(TAGC),  DE_PIPE,   DE_EXLM,   KC_DEL,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     DE_SLSH,   KC_LEFT,   KC_DOWN,   KC_RIGHT,XXXXXXX,  SS_DOUBLE_ARROW,                            TD(LESS),   DE_LPRN,   DE_RPRN,   DE_AMPR,   DE_QUES,   DE_ASTR,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     DE_BSLS,    XXXXXXX,   XXXXXXX,XXXXXXX,     DE_HASH,   SS_ARROW,                           SS_NOT_EQUAL,     DE_LCBR,   DE_RCBR,   DE_PERC,   DE_CIRC,       XXXXXXX,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  MO(1),    MO(2),  QK_LLCK,         KC_ENT,       MO(3),         MO(4)       ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

  //GREEN
  [4] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     XXXXXXX,    XXXXXXX,   KC_PGUP,XXXXXXX,   XXXXXXX,   XXXXXXX,                          XXXXXXX,    XXXXXXX,      C(DE_PLUS),      C(DE_MINS),     XXXXXXX,  C(KC_BSPC),
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,   A(KC_LEFT), KC_PGDN,   A(KC_RIGHT),XXXXXXX,   XXXXXXX,                          C(S(DE_G)),    C(DE_F),    C(DE_G),   KC_UP,     KC_DEL,    XXXXXXX,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX,   XXXXXXX,   TD(LN),    TD(CMNT),  XXXXXXX,                          XXXXXXX,    XXXXXXX,     KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_LSFT,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  MO(1),    MO(2),  QK_LLCK,         KC_ENT,       MO(3),         MO(4)       ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

  //BLUE
  [5] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     XXXXXXX,    XXXXXXX,   XXXXXXX,   G(KC_HOME),       XXXXXXX,   XXXXXXX,                          XXXXXXX,     XXXXXXX,   XXXXXXX,     XXXXXXX,   XXXXXXX,        XXXXXXX,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,      XXXXXXX,   KC_HOME,     G(KC_END),    KC_END,      XXXXXXX,                          XXXXXXX,     XXXXXXX,      XXXXXXX,   XXXXXXX,     XXXXXXX,   XXXXXXX,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                          XXXXXXX,       XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  MO(1),    MO(2),  QK_LLCK,         KC_ENT,       MO(3),         MO(4)       ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯


  //LIME
  [6] = LAYOUT_split_3x6_3(
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                          XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,       XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                          XXXXXXX,    XXXXXXX,   XXXXXXX,    LWIN(KC_L),    XXXXXXX,     XXXXXXX,
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                          XXXXXXX,    XXXXXXX,   KC_MEDIA_PREV_TRACK,    KC_MEDIA_NEXT_TRACK,    KC_MEDIA_PLAY_PAUSE,      XXXXXXX,
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  MO(1),    MO(2),  QK_LLCK,         KC_ENT,       MO(3),         MO(4)       ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯
*/
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
