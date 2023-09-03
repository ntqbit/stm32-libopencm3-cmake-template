#ifdef __cplusplus
extern "C" {
#endif
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#ifdef __cplusplus
}
#endif

#define LED_PORT GPIOC
#define RCC_LED_PORT RCC_GPIOC
#define LED_PIN GPIO13

int main() {
  rcc_periph_clock_enable(RCC_GPIOC);
  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

  gpio_set(LED_PORT, LED_PIN);

  while(1) {
    gpio_toggle(LED_PORT, LED_PIN);
    
    for (int i = 0; i < 800000; i++) {
      __asm__("nop");
    }
  }
}
