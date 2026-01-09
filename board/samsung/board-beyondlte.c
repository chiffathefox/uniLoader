/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025 chiffathefox <den.9896@gmail.com>
 */
#include <board.h>
#include <drivers/framework.h>
#include <drivers/samsung/exynos-s3c2410.h>
#include <lib/simplefb.h>
#include <main.h>

#define BEYONDLTE_UART (CONFIG_UART_DEBUG && CONFIG_EXYNOS_S3C2410)

// Early initialization
int beyondlte_init(void)
{
	soc_init();
	return 0;
}

#ifdef CONFIG_SIMPLE_FB
static struct video_info beyondlte_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 1440,
	.height = 3040,
	.stride = 4,
	.address = (void *)0xcc000000
};
#endif /* CONFIG_SIMPLE_FB */

#if BEYONDLTE_UART
static struct s3c2410_info beyondlte_uart = {
	.membase = (void *)0x10440000,
};
#endif /* BEYONDLTE_UART */

int beyondlte_drv(void)
{
#ifdef CONFIG_SIMPLE_FB
	REGISTER_DRIVER("simplefb", simplefb_probe, &beyondlte_fb);
#endif /* CONFIG_SIMPLE_FB */
#if BEYONDLTE_UART
	REGISTER_DRIVER("s3c2410", s3c2410_probe, &beyondlte_uart);
#endif /* BEYONDLTE_UART */
	return 0;
}

struct board_data board_ops = {
	.name = "samsung-beyondlte",
	.ops = {
		.early_init = beyondlte_init,
		.drivers_init = beyondlte_drv,
	},
	.quirks = 0
};
