/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2025 chiffathefox <den.9896@gmail.com>
 *
 * Exynos Serial Port Driver.
 */

 #ifndef EXYNOS_S3C2410_H_
 #define EXYNOS_S3C2410_H_

struct s3c2410_info {
	void *membase;
};

void s3c2410_probe(void *data);
void uart_putc(char c);
void uart_puts(const char *s);

#endif /* EXYNOS_S3C2410_H_ */
 