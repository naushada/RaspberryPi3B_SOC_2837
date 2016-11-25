#define BCM2837_PERIPHERAL_BASE				(0x3F000000)
#define BCM2837_GPIO_IO		            (0x00200000)
#define BCM2837_GPIO_BASE             (BCM2837_PERIPHERAL_BASE + BCM2837_GPIO_IO)

/* GPIO Function Selection offset */
#define BCM2837_GPFSEL0			      (0x00000000)
#define BCM2837_GPFSEL1			      (0x00000001)
#define BCM2837_GPFSEL2			      (0x00000002)
#define BCM2837_GPFSEL3			      (0x00000003)
#define BCM2837_GPFSEL4			      (0x00000004)
#define BCM2837_GPFSEL5			      (0x00000005)
#define BCM2837_GPFSEL_RESERVED   (0x00000006)

/* GPIO SET Address offset */

#define BCM2837_GPSET0			        (0x00000007)
#define BCM2837_GPSET1			        (0x00000008)
#define BCM2837_GPSET_RESERVED			(0x00000009)


/* Offset for clearing the GPIO */

#define BCM2837_GPCLR0			        (0x0000000A)
#define BCM2837_GPCLR1			        (0x0000000B)
#define BCM2837_GPCLR_RESERVED			(0x0000000C)

/* Offset for GPIO LEV0/1 */

#define BCM2837_GPLEV0			        (0x0000000D)
#define BCM2837_GPLEV1		      	  (0x0000000E)
#define BCM2837_GPLEV_RESERVED			(0x0000000F)


#define BCM2837_GPEDS0			        (0x00000010)
#define BCM2837_GPEDS1			        (0x00000020)
#define BCM2837_GPEDS_RESERVED			(0x00000030)

#define BCM2837_GPREN0			        (0x00000040)
#define BCM2837_GPREN1			        (0x00000050)
#define BCM2837_GPREN_RESERVED			(0x00000060)

#define BCM2837_GPFEN0			        (0x00000070)
#define BCM2837_GPFEN1			        (0x00000080)
#define BCM2837_GPFEN_RESERVED			(0x00000090)


#define BCM2837_GPHEN0			        (0x000000A0)
#define BCM2837_GPHEN1			        (0x000000B0)
#define BCM2837_GPHEN_RESERVED			(0x000000C0)


#define BCM2837_GPLEN0			        (0x000000D0)
#define BCM2837_GPLEN1			        (0x000000E0)
#define BCM2837_GPLEN_RESERVED			(0x000000F0)


#define BCM2837_GPAREN0			        (0x00000100)
#define BCM2837_GPAREN1			        (0x00000200)
#define BCM2837_GPAREN_RESERVED			(0x00000300)

#define BCM2837_GPAFEN0			        (0x00000400)
#define BCM2837_GPAFEN1			        (0x00000500)
#define BCM2837_GPAFEN_RESERVED			(0x00000600)

#define BCM2837_GPPUD			          (0x00000700)

#define BCM2837_GPPUDCLK0			      (0x00000800)
#define BCM2837_GPPUDCLK1	   	      (0x00000900)

/* 32bits Registers */


#define BCM2837_GPFSELn_INPUT       0x00000000
#define BCM2837_GPFSELn_OUTPUT      0x00000001


#define BLOCK_SIZE                  (4 * 1024)

typedef struct bcm2837_peripheral {
	/*Physical Address of GPIO*/
  unsigned long         gpio_base_address;
	int                   mem_fd;
	/*Kernel Address map for Physical Address of GPIO*/
	void                  *map;
	volatile unsigned int *gpio_base_addr;
}soc_2837_gpio_controller_t;

