/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025 chiffathefox <den.9896@gmail.com>
 */
#include <board.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>
#include <main.h>

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
#endif

int beyondlte_drv(void)
{
#ifdef CONFIG_SIMPLE_FB
	REGISTER_DRIVER("simplefb", simplefb_probe, &beyondlte_fb);
#endif
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
