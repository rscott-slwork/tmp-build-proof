/**
 * \file
 *
 * \brief Chip-specific PLL implementation.
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

#include <assert.h>
#include <avr32/io.h>
#include <compiler.h>
#include <pll.h>

void pll_config_write(const struct pll_config *cfg, unsigned int pll_id)
{
	irqflags_t flags;

	Assert(pll_id < NR_PLLS);

	flags = cpu_irq_save();
	AVR32_SCIF.unlock = 0xaa000000 | (AVR32_SCIF_PLL + (4 * pll_id));
	AVR32_SCIF.pll[pll_id] = cfg->ctrl;
	cpu_irq_restore(flags);
}

void pll_enable(const struct pll_config *cfg, unsigned int pll_id)
{
	irqflags_t flags;

	Assert(pll_id < NR_PLLS);

	flags = cpu_irq_save();
	AVR32_SCIF.unlock = 0xaa000000 | (AVR32_SCIF_PLL + (4 * pll_id));
	AVR32_SCIF.pll[pll_id] = cfg->ctrl | (1U << AVR32_SCIF_PLLEN);
	cpu_irq_restore(flags);
}

void pll_disable(unsigned int pll_id)
{
	irqflags_t flags;

	Assert(pll_id < NR_PLLS);

	flags = cpu_irq_save();
	AVR32_SCIF.unlock = 0xaa000000 | (AVR32_SCIF_PLL + (4 * pll_id));
	AVR32_SCIF.pll[pll_id] = 0;
	cpu_irq_restore(flags);
}
