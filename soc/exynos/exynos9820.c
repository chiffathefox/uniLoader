/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025 chiffathefox <den.9896@gmail.com>
 */

#include <soc/exynos9820.h>

void soc_init(void) {
	/* Allow framebuffer to be written to */
	*(int*) (DECON_F_BASE + HW_SW_TRIG_CONTROL) = 0x1281;
}
