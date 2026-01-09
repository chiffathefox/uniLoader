/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025 chiffathefox <den.9896@gmail.com>
 *
 * Exynos Serial Port Driver.
 */

#include <string.h>
#include <drivers/samsung/exynos-s3c2410.h>

#define S3C2410_UTXH		0x20

#define S3C2410_UTRSTAT		0x10
#define S3C2410_UTRSTAT_TXE	(1 << 2)

static struct s3c2410_info *serial_info = NULL;

void s3c2410_probe(void *data)
{
	serial_info = data;
}

#ifdef CONFIG_UART_DEBUG
void uart_putc(char c) {
	if (serial_info == NULL) {
		return;
	}
	while (!(readl(serial_info->membase + S3C2410_UTRSTAT) & S3C2410_UTRSTAT_TXE))
		;
	writeb(c, serial_info->membase + S3C2410_UTXH);
}

void uart_puts(const char *s)
{
	if (serial_info == NULL) {
		return;
	}
	while (*s) {
		uart_putc(*s);
		s++;
	}
}
#endif /* CONFIG_UART_DEBUG */
