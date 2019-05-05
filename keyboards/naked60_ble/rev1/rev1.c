#include "matrix.h"
#include "quantum.h"
#include "nrf.h"
#include "app_ble_func.h"

void matrix_init_user() {
  set_usb_enabled(true);
}


/*#include "naked60.h"


#ifdef SSD1306OLED

void led_set_kb(uint8_t usb_led) {
}
#endif

void matrix_init_kb(void) {

	matrix_init_user();
};
*/