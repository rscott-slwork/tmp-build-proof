/**
 * \file
 *
 * \brief AVR UC3 External Interrupt Controller(EIC) driver
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
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef _CONF_BOARD_H_
#define _CONF_BOARD_H_


/*! \name External Interrupt pin Mappings
 */
//! @{

/*
 * With the UC3D datasheet, in section "Peripheral Multiplexing on I/O lines"
 * in the table "GPIO Controller Function Multiplexing", we see that the NMI is
 * mapped on GPIO 13 (i.e. PA13). On the STK600 using the RCUC3D, it is require
 * to connect PORTB.PB5 on SWITCHES.SW0. Thus, a low level on SW01 will generate
 * an NMI. The External Interrupt number 0 is the NMI. It is also required to
 * connect PORTA.PA to LEDS.LEDS0
 */

#  define EXT_INT_EXAMPLE_PIN_LINE1               AVR32_EIC_EXTINT_0_0_PIN
#  define EXT_INT_EXAMPLE_FUNCTION_LINE1          AVR32_EIC_EXTINT_0_0_FUNCTION
#  define EXT_INT_EXAMPLE_LINE1                   EXT_NMI
#  define EXT_INT_EXAMPLE_NB_LINES                1

//! @}

#endif // _CONF_BOARD_H_
