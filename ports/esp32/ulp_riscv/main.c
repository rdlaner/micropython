/* ULP-RISC-V example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.

   This code runs on ULP-RISC-V  coprocessor
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "ulp_riscv.h"
#include "ulp_riscv_utils.h"
#include "ulp_riscv_gpio.h"

/* this variable will be exported as a public symbol, visible from main CPU: */
// bool gpio_level = true;

int main (void)
{
   // Wake AP
   ulp_riscv_wakeup_main_processor();

   // Init gpio pins
   ulp_riscv_gpio_init(7);
   ulp_riscv_gpio_input_enable(7);
   ulp_riscv_gpio_init(13);
   ulp_riscv_gpio_set_output_mode(13, RTCIO_MODE_OUTPUT);
   ulp_riscv_gpio_output_enable(13);

   // Poor man's debounce to prevent waking up the ULP multiple times
   ulp_riscv_delay_cycles(50 * ULP_RISCV_CYCLES_PER_MS);
   while (ulp_riscv_gpio_get_level(7) == 0);
   ulp_riscv_delay_cycles(50 * ULP_RISCV_CYCLES_PER_MS);
   while (ulp_riscv_gpio_get_level(7) == 0);

   // Clear
   ulp_riscv_gpio_wakeup_clear();

   // Turn on GPIO
   ulp_riscv_gpio_output_level(13, 1);

   // NOTE: ulp_riscv_halt() is called automatically when main exits
   return 0;
}