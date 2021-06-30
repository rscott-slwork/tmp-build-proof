/*
 * Configuration for PIO pin and perihpheral settings
 */

#ifndef CONF_PIO_H_INCLUDED
#define CONF_PIO_H_INCLUDED

#include "asf.h"
void configure_io();

void configure_io()
{
  pmc_enable_periph_clk(ID_PIOA);

  pio_set_output(PIOA, PIO_PA23, LOW, DISABLE, ENABLE);
  pio_set_input(PIOA, PIO_PA16, PIO_PULLUP);
}
/** Button name. */
#define BUTTON_STRING            "USR_LEFT"

/** UART Hw ID used by the console (UART0). */
#define CONSOLE_UART_ID          ID_UART0

/** UART baudrate. */
#define BOARD_UART_BAUDRATE      115200

/** Push button pin definition. */
#define PUSH_BUTTON_PIO          PIOA
#define PUSH_BUTTON_ID           ID_PIOA
#define PUSH_BUTTON_PIN_MSK      (1 << 15)
#define PUSH_BUTTON_ATTR         (PIO_PULLUP | PIO_DEBOUNCE | PIO_IT_RISE_EDGE)

/** The erase pin mask value in the PIO mode and erase mode. */
#define PIN_PIO_MODE_MSK         CCFG_SYSIO_SYSIO12
#define PIN_ERASE_MODE_MSK       0

/** Test page start address. */
#define TEST_PAGE_ADDRESS        (IFLASH_ADDR + IFLASH_SIZE - IFLASH_PAGE_SIZE)

#endif /* CONF_PIO_H_INCLUDED */
