/*****************************************************************************
 *
 * \file
 *
 * \brief Graphical User Interface.
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 *****************************************************************************/
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <stdio.h>
#include "board.h"
#include "gui.h"
#include "gpio.h"
#include "delay.h"
#include "et024006dhu.h"


/*! flag set when joystick display starts to signal main function to clear this display */
unsigned short display = 0;

static void gui_print( TString textToDisplay )
{
  int	i = 0;
  boolean strError = false;

  while ( textToDisplay[i] != 0 )
  {
    // Maximum length for display, adjust in engine
    if ( i == 19 )
    {
      strError = true;
      break;
    }
    i++;
  }

  et024006_PrintString("                                          ", (const unsigned char *)&FONT6x8, 80, 80, WHITE, -1);
  if (!strError )
  {
    et024006_PrintString((char*)textToDisplay, (const unsigned char *)&FONT6x8, 80, 80, WHITE, -1);

  }
  else
  {
    et024006_PrintString("str err" , (const unsigned char *)&FONT6x8, 80, 80, WHITE, -1);

  }
}

/*!
 * \brief function to display default message
 */
static void gui_print_default_message(void)
{
  // Display default message.
  et024006_DrawFilledRect(0 , 0, ET024006_WIDTH, ET024006_HEIGHT, BLACK );
  et024006_PrintString("ATMEL AVR UC3", (const unsigned char *)&FONT6x8, 80, 50, WHITE, -1);
  et024006_PrintString("Cybercom Bluetooth", (const unsigned char *)&FONT6x8, 80, 60, WHITE, -1);
  et024006_PrintString("    SPP Lite Demo  ", (const unsigned char *)&FONT6x8, 80, 70, WHITE, -1);
}

/*!
 * \brief function to configure LCD
 */
void gui_init(U32 fcpu_hz, U32 fhsb_hz, U32 fpbb_hz, U32 fpba_hz)
{

  delay_init(fcpu_hz);
  et024006_Init( fcpu_hz, fhsb_hz );
  gpio_set_gpio_pin(ET024006DHU_BL_PIN);
  et024006_DrawFilledRect(0 , 0, ET024006_WIDTH, ET024006_HEIGHT, BLACK );

  gui_print_default_message();
}

void gui_callback( TString textToDisplay )
{
  display = 1;
  gui_print_default_message();
  gui_print( textToDisplay );
}
