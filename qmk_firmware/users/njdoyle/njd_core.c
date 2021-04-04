#include "njdoyle.h"

#define NJD_SIGNATURE1 0x6E /* n */
#define NJD_SIGNATURE2 0x6A /* j */
#define NJD_SIGNATURE3 0x64 /* d */

typedef union {
	uint32_t raw;
	struct {
		unsigned int os_mode    : 2;
		unsigned int oled_mode  : 2;
		unsigned int reserved   : 4;
		unsigned int signature1 : 8;
		unsigned int signature2 : 8;
		unsigned int signature3 : 8;
	};
} njd_config_t;
static njd_config_t njd_config;

extern keymap_config_t keymap_config;

void njd_set_os_mode(enum njd_os_mode mode) {
	clear_keyboard();
	njd_config.os_mode = mode;
	eeconfig_update_user(njd_config.raw);
}

enum njd_os_mode njd_get_os_mode(void) {
	return njd_config.os_mode;
}

uint8_t njd_cycle_oled_mode(void) {
#ifdef OLED_DRIVER_ENABLE
	njd_config.oled_mode = (njd_config.oled_mode + 1) & 0x03;
	eeconfig_update_user(njd_config.raw);
#endif
	return njd_config.oled_mode;
}

uint8_t njd_get_oled_mode(void) {
	return njd_config.oled_mode;
}

void njd_factory_reset(void) {
	clear_keyboard();
	set_single_persistent_default_layer(NJD_L_QWERTY);

#ifdef RGB_MATRIX_ENABLE
	rgb_matrix_sethsv_noeeprom   (HSV_CYAN                 );
	rgb_matrix_set_speed_noeeprom(112                      );
	rgb_matrix_mode_noeeprom     (RGB_MATRIX_SOLID_REACTIVE);
	rgb_matrix_enable_noeeprom();
	eeconfig_update_rgb_matrix();
#endif

	keymap_config.raw  = 0;
	keymap_config.nkro = 1;
	eeconfig_update_keymap(keymap_config.raw);

	njd_config.os_mode    = NJD_OS_MACOS;
	njd_config.oled_mode  = 2;
	njd_config.reserved   = 0;
	njd_config.signature1 = NJD_SIGNATURE1;
	njd_config.signature2 = NJD_SIGNATURE2;
	njd_config.signature3 = NJD_SIGNATURE3;
	eeconfig_update_user(njd_config.raw);
}

void keyboard_post_init_user(void) {
	njd_config.raw = eeconfig_read_user();
	if (
			NJD_SIGNATURE1 != njd_config.signature1 ||
			NJD_SIGNATURE2 != njd_config.signature2 ||
			NJD_SIGNATURE3 != njd_config.signature3 )
		njd_factory_reset();
	keyboard_post_init_njd();
}

layer_state_t layer_state_set_user(layer_state_t state) {
	state = layer_state_set_njd(state);
	return update_tri_layer_state(state, NJD_L_NUMBER, NJD_L_SYMBOL, NJD_L_NAVIGATION);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	if (!process_record_njd(keycode, record)) return false;
	if (record->event.pressed) {
		switch (keycode) {
			/* DEFAULT LAYOUTS */
			case NJD_K_QWERTY     : set_single_persistent_default_layer(NJD_L_QWERTY     ); return false;
			case NJD_K_DVORAK     : set_single_persistent_default_layer(NJD_L_DVORAK     ); return false;
			case NJD_K_COLEMAK    : set_single_persistent_default_layer(NJD_L_COLEMAK    ); return false;
			case NJD_K_COLEMAK_DH : set_single_persistent_default_layer(NJD_L_COLEMAK_DH ); return false;
			case NJD_K_COLEMAK_DHK: set_single_persistent_default_layer(NJD_L_COLEMAK_DHK); return false;
			case NJD_K_WORKMAN    : set_single_persistent_default_layer(NJD_L_WORKMAN    ); return false;
			/* MODES */
			case NJD_K_OS_MACOS  : njd_set_os_mode(NJD_OS_MACOS  ); return false;
			case NJD_K_OS_LINUX  : njd_set_os_mode(NJD_OS_LINUX  ); return false;
			case NJD_K_OS_WINDOWS: njd_set_os_mode(NJD_OS_WINDOWS); return false;
			case NJD_K_OLED_MODE : njd_cycle_oled_mode()          ; return false;
			/* OTHER */
			case NJD_K_FACTORY_RESET: njd_factory_reset();
		}
	}
	return true;
}

const uint16_t PROGMEM njd_os_keycodes[][NJD_OS_END] = {
	[NJD_K_RMAMOD - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = KC_RGUI,
		[NJD_OS_LINUX  ] = KC_RCTL,
		[NJD_OS_WINDOWS] = KC_RCTL},
	[NJD_K_LMAMOD - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LGUI_T(KC_TAB),
		[NJD_OS_LINUX  ] = LCTL_T(KC_TAB),
		[NJD_OS_WINDOWS] = LCTL_T(KC_TAB)},
	[NJD_K_LMIMOD - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LCTL_T(KC_ESC),
		[NJD_OS_LINUX  ] = LGUI_T(KC_ESC),
		[NJD_OS_WINDOWS] = LGUI_T(KC_ESC)},
	[NJD_K_MENU - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LCTL(KC_F2),
		[NJD_OS_LINUX  ] = KC_APP     ,
		[NJD_OS_WINDOWS] = KC_APP     },
	[NJD_K_NV_MOD1 - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = KC_LCTL,
		[NJD_OS_LINUX  ] = KC_LGUI,
		[NJD_OS_WINDOWS] = KC_LGUI},
	[NJD_K_NV_MOD2 - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = KC_LGUI,
		[NJD_OS_LINUX  ] = KC_LALT,
		[NJD_OS_WINDOWS] = KC_LALT},
	[NJD_K_NV_MOD3 - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = KC_LALT,
		[NJD_OS_LINUX  ] = KC_LCTL,
		[NJD_OS_WINDOWS] = KC_LCTL},
	[NJD_K_DM_PREV - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LCTL(     KC_LEFT ),
		[NJD_OS_LINUX  ] = LGUI(     KC_PGUP ),
		[NJD_OS_WINDOWS] = LGUI(LCTL(KC_LEFT))},
	[NJD_K_DM_NEXT - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LCTL(     KC_RIGHT ),
		[NJD_OS_LINUX  ] = LGUI(     KC_PGDN  ),
		[NJD_OS_WINDOWS] = LGUI(LCTL(KC_RIGHT))},
	[NJD_K_TB_PREV - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = SGUI(KC_LBRC),
		[NJD_OS_LINUX  ] = LCTL(KC_PGUP),
		[NJD_OS_WINDOWS] = LCTL(KC_PGUP)},
	[NJD_K_TB_NEXT - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = SGUI(KC_RBRC),
		[NJD_OS_LINUX  ] = LCTL(KC_PGDN),
		[NJD_OS_WINDOWS] = LCTL(KC_PGDN)},
	[NJD_K_TB_NEW - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LGUI(KC_T),
		[NJD_OS_LINUX  ] = LCTL(KC_T),
		[NJD_OS_WINDOWS] = LCTL(KC_T)},
	[NJD_K_BR_BACK - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LGUI(KC_LBRC),
		[NJD_OS_LINUX  ] = LALT(KC_LEFT),
		[NJD_OS_WINDOWS] = LALT(KC_LEFT)},
	[NJD_K_BR_FORWARD - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = LGUI(KC_RBRC ),
		[NJD_OS_LINUX  ] = LALT(KC_RIGHT),
		[NJD_OS_WINDOWS] = LALT(KC_RIGHT)},
	[NJD_K_SS_ALL - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = SGUI(KC_3),
		[NJD_OS_LINUX  ] = KC_PSCR   ,
		[NJD_OS_WINDOWS] = KC_PSCR   },
	[NJD_K_SS_AREA - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = SGUI(KC_4   ),
		[NJD_OS_LINUX  ] = LSFT(KC_PSCR),
		[NJD_OS_WINDOWS] = SGUI(KC_PSCR)},
	[NJD_K_SS_WINDOW - NJD_K_OS_START] = {
		[NJD_OS_MACOS  ] = SGUI(KC_4   ),
		[NJD_OS_LINUX  ] = LCTL(KC_PSCR),
		[NJD_OS_WINDOWS] = LALT(KC_PSCR)}
};

uint16_t keymap_key_to_keycode(uint8_t layer, keypos_t key) {
	uint16_t keycode = pgm_read_word(&keymaps[(layer)][(key.row)][(key.col)]);
	if (keycode >= NJD_K_OS_START && keycode <= NJD_K_OS_END) {
		enum njd_os_mode os_mode = njd_get_os_mode();
		return pgm_read_word(&njd_os_keycodes[(keycode - NJD_K_OS_START)][(os_mode)]);
	}
	return keycode;
}

/* WEAK DEFAULT IMPLEMENTATIONS */
__attribute__((weak)) bool          process_record_njd    (uint16_t keycode, keyrecord_t* record) { return true ; }
__attribute__((weak)) layer_state_t layer_state_set_njd   (layer_state_t state                  ) { return state; }
__attribute__((weak)) void          keyboard_post_init_njd(void                                 ) { return      ; }
