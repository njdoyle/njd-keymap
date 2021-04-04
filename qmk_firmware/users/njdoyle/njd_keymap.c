#include "njdoyle.h"

/* MACRO FOR DEFAULT LAYERS */
#define \
	NJD_BASE_LAYOUT_DEFAULT( \
		NJD_KM_00, NJD_KM_01, NJD_KM_02, NJD_KM_03, NJD_KM_04, NJD_KM_05, NJD_KM_06, NJD_KM_07, NJD_KM_08, NJD_KM_09, \
		NJD_KM_10, NJD_KM_11, NJD_KM_12, NJD_KM_13, NJD_KM_14, NJD_KM_15, NJD_KM_16, NJD_KM_17, NJD_KM_18, NJD_KM_19, \
		NJD_KM_20, NJD_KM_21, NJD_KM_22, NJD_KM_23, NJD_KM_24, NJD_KM_25, NJD_KM_26, NJD_KM_27, NJD_KM_28, NJD_KM_29) \
	NJD_BASE_LAYOUT( \
		KC_##NJD_KM_00, KC_##NJD_KM_01, KC_##NJD_KM_02, KC_##NJD_KM_03, KC_##NJD_KM_04, KC_##NJD_KM_05, KC_##NJD_KM_06, KC_##NJD_KM_07, KC_##NJD_KM_08, KC_##NJD_KM_09, \
		KC_##NJD_KM_10, KC_##NJD_KM_11, KC_##NJD_KM_12, KC_##NJD_KM_13, KC_##NJD_KM_14, KC_##NJD_KM_15, KC_##NJD_KM_16, KC_##NJD_KM_17, KC_##NJD_KM_18, KC_##NJD_KM_19, \
		KC_##NJD_KM_20, KC_##NJD_KM_21, KC_##NJD_KM_22, KC_##NJD_KM_23, KC_##NJD_KM_24, KC_##NJD_KM_25, KC_##NJD_KM_26, KC_##NJD_KM_27, KC_##NJD_KM_28, KC_##NJD_KM_29, \
		NJD_K_LMAMOD , KC_BSPACE     , \
		NJD_K_LMIMOD , NJD_K_RMAMOD  , \
		OSM(MOD_LSFT), OSM(MOD_RSFT) , \
		KC_SPACE     , KC_ENTER      , \
		NJD_K_NUMBER , NJD_K_SYMBOL  , \
		KC_LALT      , NJD_K_FUNCTION)

/* MACROS FOR LAYER LAYRES */
#ifndef NJD_LAYER_LAYOUT
#	define NJD_LAYER_LAYOUT NJD_BASE_LAYOUT
#endif /* ndef NJD_LAYER_LAYOUT */
#define \
	NJD_LAYER_LAYOUT_KC( \
		NJD_KM_00, NJD_KM_01, NJD_KM_02, NJD_KM_03, NJD_KM_04, NJD_KM_05, NJD_KM_06, NJD_KM_07, NJD_KM_08, NJD_KM_09, \
		NJD_KM_10, NJD_KM_11, NJD_KM_12, NJD_KM_13, NJD_KM_14, NJD_KM_15, NJD_KM_16, NJD_KM_17, NJD_KM_18, NJD_KM_19, \
		NJD_KM_20, NJD_KM_21, NJD_KM_22, NJD_KM_23, NJD_KM_24, NJD_KM_25, NJD_KM_26, NJD_KM_27, NJD_KM_28, NJD_KM_29, \
		NJD_KM_TAB   , NJD_KM_BSPACE  , \
		NJD_KM_MIMOD , NJD_KM_MAMOD   , \
		NJD_KM_LSHIFT, NJD_KM_RSHIFT  , \
		NJD_KM_SPACE , NJD_KM_ENTER   , \
		NJD_KM_NUMBER, NJD_KM_SYMBOL  , \
		NJD_KM_LALT  , NJD_KM_FUNCTION) \
	NJD_LAYER_LAYOUT( \
		KC_##NJD_KM_00, KC_##NJD_KM_01, KC_##NJD_KM_02, KC_##NJD_KM_03, KC_##NJD_KM_04, KC_##NJD_KM_05, KC_##NJD_KM_06, KC_##NJD_KM_07, KC_##NJD_KM_08, KC_##NJD_KM_09, \
		KC_##NJD_KM_10, KC_##NJD_KM_11, KC_##NJD_KM_12, KC_##NJD_KM_13, KC_##NJD_KM_14, KC_##NJD_KM_15, KC_##NJD_KM_16, KC_##NJD_KM_17, KC_##NJD_KM_18, KC_##NJD_KM_19, \
		KC_##NJD_KM_20, KC_##NJD_KM_21, KC_##NJD_KM_22, KC_##NJD_KM_23, KC_##NJD_KM_24, KC_##NJD_KM_25, KC_##NJD_KM_26, KC_##NJD_KM_27, KC_##NJD_KM_28, KC_##NJD_KM_29, \
		KC_##NJD_KM_TAB   , KC_##NJD_KM_BSPACE  , \
		KC_##NJD_KM_MIMOD , KC_##NJD_KM_MAMOD   , \
		KC_##NJD_KM_LSHIFT, KC_##NJD_KM_RSHIFT  , \
		KC_##NJD_KM_SPACE , KC_##NJD_KM_ENTER   , \
		KC_##NJD_KM_NUMBER, KC_##NJD_KM_SYMBOL  , \
		KC_##NJD_KM_LALT  , KC_##NJD_KM_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* DEFAULT LAYERS */
	[NJD_L_QWERTY] = NJD_BASE_LAYOUT_DEFAULT( \
		Q, W, E, R, T, Y, U, I   , O  , P   , \
		A, S, D, F, G, H, J, K   , L  , SCLN, \
		Z, X, C, V, B, N, M, COMM, DOT, SLSH) ,
	[NJD_L_DVORAK] = NJD_BASE_LAYOUT_DEFAULT( \
		SLSH, COMM, DOT, P, Y, F, G, C, R, L, \
		A   , O   , E  , U, I, D, H, T, N, S, \
		SCLN, Q   , J  , K, X, B, M, W, V, Z) ,
	[NJD_L_COLEMAK] = NJD_BASE_LAYOUT_DEFAULT( \
		Q, W, F, P, G, J, L, U   , Y  , SCLN, \
		A, R, S, T, D, H, N, E   , I  , O   , \
		Z, X, C, V, B, K, M, COMM, DOT, SLSH) ,
	[NJD_L_COLEMAK_DH] = NJD_BASE_LAYOUT_DEFAULT( \
		Q, W, F, P, B, J, L, U   , Y  , SCLN, \
		A, R, S, T, G, M, N, E   , I  , O   , \
		Z, X, C, D, V, K, H, COMM, DOT, SLSH) ,
	[NJD_L_COLEMAK_DHK] = NJD_BASE_LAYOUT_DEFAULT( \
		Q, W, F, P, B, J, L, U   , Y  , SCLN, \
		A, R, S, T, G, K, N, E   , I  , O   , \
		Z, X, C, D, V, M, H, COMM, DOT, SLSH) ,
	[NJD_L_WORKMAN] = NJD_BASE_LAYOUT_DEFAULT( \
		Q, D, R, W, B, J, F, U   , P  , SCLN, \
		A, S, H, T, G, Y, N, E   , O  , I   , \
		Z, X, M, C, V, K, L, COMM, DOT, SLSH) ,

	/* NUMBER - Mostly numbers and their shifted symbol counterparts */
	[NJD_L_NUMBER] = NJD_LAYER_LAYOUT_KC( \
		EXLM, AT  , HASH, DLR , PERC, CIRC, AMPR, ASTR, BSLS, PIPE, \
		1   , 2   , 3   , 4   , 5   , 6   , 7   , 8   , 9   , 0   , \
		PLUS, MINS, ASTR, SLSH, UNDS, COLN, EQL , COMM, DOT , SLSH, \
		____, ____, \
		____, ____, \
		LALT, DEL , \
		____, ____, \
		____, ____, \
		____, ____) ,

	/* SYMBOL - Mostly paired enclosures and common programming symbols */
	[NJD_L_SYMBOL] = NJD_LAYER_LAYOUT_KC( \
		XXXX, EXLM, ASTR, PLUS, XXXX, XXXX, MINS, EQL , UNDS, XXXX, \
		LBRC, RBRC, LCBR, RCBR, DLR , HASH, LPRN, RPRN, LT  , GT  , \
		XXXX, XXXX, GRV , QUOT, XXXX, XXXX, DQUO, TILD, XXXX, XXXX, \
		____, ____, \
		____, ____, \
		LALT, DEL , \
		____, ____, \
		____, ____, \
		____, ____) ,

	/* NAVIGATION */
	[NJD_L_NAVIGATION] = NJD_LAYER_LAYOUT( \
		XXXXXXX      , XXXXXXX      , NJD_K_DM_PREV, NJD_K_DM_NEXT, KC_HOME, XXXXXXX, NJD_K_TB_PREV, NJD_K_TB_NEXT   , NJD_K_TB_NEW, KC_PGUP   , \
		NJD_K_NV_MOD1, NJD_K_NV_MOD2, NJD_K_NV_MOD3, KC_LSFT      , KC_END , KC_LEFT, KC_DOWN      , KC_UP           , KC_RGHT     , KC_PGDN   , \
		NJD_K_MENU   , XXXXXXX      , XXXXXXX      , NJD_K_MOUSE  , XXXXXXX, XXXXXXX, NJD_K_BR_BACK, NJD_K_BR_FORWARD, LALT(KC_K)  , LALT(KC_J), \
		_______, _______, \
		_______, _______, \
		_______, _______, \
		_______, _______, \
		_______, _______, \
		_______, _______) ,

	/* MOUSE */
	[NJD_L_MOUSE] = NJD_LAYER_LAYOUT( \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_R, XXXXXXX, KC_WH_U, \
		KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, \
		XXXXXXX    , XXXXXXX, \
		NJD_K_MOUSE, XXXXXXX, \
		XXXXXXX    , XXXXXXX, \
		KC_BTN1    , KC_BTN2, \
		KC_ACL2    , KC_ACL1, \
		XXXXXXX    , XXXXXXX) ,

	/* FUNCTION - F keys, locks, media controls, screen shots */
	[NJD_L_FUNCTION] = NJD_LAYER_LAYOUT( \
		KC_F1, KC_F2 , KC_F3 , KC_F4 , KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX        , XXXXXXX      , XXXXXXX     , \
		KC_F5, KC_F6 , KC_F7 , KC_F8 , KC_CAPS, KC_MRWD, KC_VOLD, KC_VOLU        , KC_MFFD      , KC_MPLY     , \
		KC_F9, KC_F10, KC_F11, KC_F12, KC_NLCK, XXXXXXX, XXXXXXX, NJD_K_SS_WINDOW, NJD_K_SS_AREA, NJD_K_SS_ALL, \
		KC_LGUI, NJD_K_CONFIGURATION, \
		KC_LCTL, KC_MUTE            , \
		KC_LSFT, XXXXXXX            , \
		_______, _______            , \
		_______, _______            , \
		_______, _______            ) ,

	/* CONFIGURATION - Keyboard configuration, not every-day use */
	[NJD_L_CONFIGURATION] = NJD_LAYER_LAYOUT( \
		RGB_HUI        , RGB_SAI, RGB_VAI, RGB_SPI, RGB_TOG, XXXXXXX, XXXXXXX, NJD_K_OS_MACOS  , NJD_K_QWERTY , NJD_K_COLEMAK    , \
		RGB_HUD        , RGB_SAD, RGB_VAD, RGB_SPD, RGB_MOD, XXXXXXX, XXXXXXX, NJD_K_OS_LINUX  , NJD_K_DVORAK , NJD_K_COLEMAK_DH , \
		NJD_K_OLED_MODE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NJD_K_OS_WINDOWS, NJD_K_WORKMAN, NJD_K_COLEMAK_DHK, \
		XXXXXXX            , NJD_K_FACTORY_RESET, \
		NJD_K_CONFIGURATION, XXXXXXX            , \
		XXXXXXX            , XXXXXXX            , \
		XXXXXXX            , XXXXXXX            , \
		XXXXXXX            , XXXXXXX            , \
		XXXXXXX            , XXXXXXX            )
};
