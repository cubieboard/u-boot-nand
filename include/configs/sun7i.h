/*
 * (C) Copyright 2007-2011
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Tom Cubie <tangliang@allwinnertech.com>
 *
 * Configuration settings for the Allwinner sun7i-evb board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 */

//#define DEBUG
//#define DEBUG_TICK_PRINTF

#define CONFIG_ALLWINNER			/* It's a Allwinner chip */
#define	CONFIG_SUNXI				/* which is sunxi family */
#define CONFIG_SUN7I				/* which is sun7i */
//#define CONFIG_FPGA					/* working with fpga board */
#define CONFIG_CMD_BOOTA
#include <asm/arch/cpu.h>			/* get chip and board defs */

#define BOARD_LATE_INIT				/* init the fastboot partitions */

#define SYS_CONFIG_BASE             0x43000000
#define CONFIG_SYS_TEXT_BASE		0x4A000000
#if 0
#define CONFIG_SKIP_LOWLEVEL_INIT	/* currently u-boot is loaded from ice */
#endif
/*
 * Display CPU and Board information
 */
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

/* Clock Defines */


/* Serial & console */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)		/* ns16550 reg in the low bits of cpu reg */
#define CONFIG_SYS_NS16550_CLK		(24000000)
#define CONFIG_SYS_NS16550_COM1		SUNXI_UART0_BASE
#define CONFIG_SYS_NS16550_COM2		SUNXI_UART1_BASE
#define CONFIG_SYS_NS16550_COM3		SUNXI_UART2_BASE
#define CONFIG_SYS_NS16550_COM4		SUNXI_UART3_BASE

#define CONFIG_CONS_INDEX			1			/* which serial channel for console */

/* DRAM Base */
#define CONFIG_SYS_SDRAM_BASE		0x40000000
#define CONFIG_SYS_INIT_RAM_ADDR	0x0
#define CONFIG_SYS_INIT_RAM_SIZE	0x8000      /* 32K */

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* A10-EVB has 1 banks of DRAM, we use only one in U-Boot */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM_1				CONFIG_SYS_SDRAM_BASE	/* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE			(512 << 20)				/* 0x20000000, 512 MB Bank #1 */

//#define CONFIG_SYS_MONITOR_BASE	0x00000000

/* Nand config */
#define CONFIG_NAND
#define CONFIG_NAND_SUNXI
#define CONFIG_CMD_NAND                         /* NAND support */
#define CONFIG_CMD_EXT4				/* with this we can access ext4 bootfs in nand */
#define CONFIG_CMD_EXT2				/* with this we can access ext2 bootfs in nand */
#define CONFIG_FS_EXT4				/* EXT4 filesystem */
#define CONFIG_SYS_MAX_NAND_DEVICE      1
#define CONFIG_SYS_NAND_BASE            0x00
#define CONFIG_CMD_MEMORY
#define CONFIG_SUNXI_DMA

#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG
#define CONFIG_CMDLINE_EDITING

/* mmc config */
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_CMD_MMC
#define CONFIG_MMC_SUNXI
#define CONFIG_MMC_SUNXI_SLOT		2		/* which mmc slot to use, could be 0,1,2,3 */
#define CONFIG_MMC_SUNXI_USE_DMA
#if 0
/* Set in boards.cfg */
#define CONFIG_ENV_IS_IN_MMC
#endif
#define CONFIG_SYS_MMC_ENV_DEV		mmc_card_no
#define CONFIG_STORAGE_EMMC
#define CONFIG_FASTBOOT_MMC_NO		mmc_card_no
#define CONFIG_MMC_LOGICAL_OFFSET   (20 * 1024 * 1024/512)

#define CONFIG_DOS_PARTITION
/*
 * Size of malloc() pool
 * 1MB = 0x100000, 0x100000 = 1024 * 1024
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (4 << 20))

#define CONFIG_FASTBOOT
#define CONFIG_STORAGE_NAND
#define FASTBOOT_TRANSFER_BUFFER		0x41000000
#define FASTBOOT_TRANSFER_BUFFER_SIZE	(256 << 20)

#define FASTBOOT_ERASE_BUFFER			0x40000000
#define FASTBOOT_ERASE_BUFFER_SIZE      (16 << 20)
/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP				/* undef to save memory */
#define CONFIG_SYS_HUSH_PARSER			/* use "hush" command parser	*/
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_PROMPT		"sun7i#"
#define CONFIG_SYS_CBSIZE	256			/* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE	384			/* Print Buffer Size */
#define CONFIG_SYS_MAXARGS	16			/* max number of command args */

/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE			CONFIG_SYS_CBSIZE

/* memtest works on */
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 256<<20)	/* 256M */
#define CONFIG_SYS_LOAD_ADDR		0x50000000					/* default load address */

#define CONFIG_SYS_HZ				1000

/* valid baudrates */
#define CONFIG_BAUDRATE				115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE			(256 << 10)				/* 256 KiB */
#define LOW_LEVEL_SRAM_STACK		0x00003FFC


/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_NO_FLASH

#define CONFIG_SYS_MONITOR_LEN		(256 << 10)	/* 256 KiB */
#define CONFIG_IDENT_STRING			" Allwinner Technology "

#define CONFIG_ENV_IS_NOWHERE 1

#if !defined(CONFIG_ENV_IS_IN_MMC) && !defined(CONFIG_ENV_IS_NOWHERE)
#define CONFIG_ENV_IS_IN_NAND_SUNXI	    /* we store env in one partition of our nand */
#endif
#define CONFIG_SUNXI_ENV_PARTITION		"env"	/* the partition name */

/*------------------------------------------------------------------------
 * we save the environment in a nand partition, the partition name is defined
 * in sysconfig.fex, which must be the same as CONFIG_SUNXI_NAND_ENV_PARTITION
 * if not, below CONFIG_ENV_ADDR and CONFIG_ENV_SIZE will be where to store env.
 * */
#define CONFIG_ENV_ADDR				(53 << 20)  /* 16M */
#define CONFIG_ENV_SIZE				(128 << 10)	/* 128KB */
#define CONFIG_CMD_SAVEENV

#define CONFIG_EXTRA_ENV_SETTINGS \
	"bootdelay=1\0" \
	"bootcmd=run setargs_nand boot_normal\0" \
	"console=ttyS0,115200\0" \
	"nand_root=/dev/nand3\0" \
	"loglevel=8\0" \
	"bootenv=/uEnv.txt\0" \
	"kernel=/uImage\0" \
	"scriptbin=/script.bin\0" \
	"scriptaddr=0x41000000\0" \
	"scriptbinaddr=0x43000000\0" \
	"kerneladdr=0x48000000\0" \
	"loadbootenv=mw 41000000 0 10000;" \
	 "ext4load nand 2:0 $scriptaddr /boot${bootenv} || fatload nand 0:0 $scriptaddr ${bootenv};" \
	 "env import 41000000 10000;" \
	 "setenv bootargs console=${console} root=${nand_root} loglevel=${loglevel} ${extraargs}\0" \
	"loadscriptbin=ext4load nand 2:0 $scriptbinaddr /boot${scriptbin} || fatload nand 0:0 $scriptbinaddr ${scriptbin}\0" \
	"loadkernel=ext4load nand 2:0 $kerneladdr /boot${kernel} || fatload nand 0:0 $kerneladdr ${kernel}\0" \
	"setmachid=setenv machid 10bb\0" \
	"setargs_nand=run loadbootenv loadscriptbin loadkernel setmachid\0" \
    	"boot_normal=bootm 48000000\0" \
	"boot_recovery=sunxi_flash read 40007800 recovery;boota 40007800\0" \
	"boot_fastboot=fastboot\0"


#define CONFIG_BOOTDELAY	1
#define CONFIG_BOOTCOMMAND	"nand read 50000000 boot;boota 50000000"
#define CONFIG_SYS_BOOT_GET_CMDLINE
#define CONFIG_AUTO_COMPLETE

#define CONFIG_CMD_FAT			/* with this we can access bootfs in nand */
#define CONFIG_CMD_BOOTA		/* boot android image */
#define CONFIG_CMD_RUN			/* run a command */
#define CONFIG_CMD_BOOTD		/* boot the default command */

#endif /* __CONFIG_H */
