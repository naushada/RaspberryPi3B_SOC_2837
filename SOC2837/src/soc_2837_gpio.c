
/* Library header files inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



/* user defined header file inclusion */
#include <soc_2837_gpio.h>

/* Global instance */
static soc_2837_gpio_controller_t gpio     = {BCM2837_GPIO_BASE};

/**
 * @Author      : Mohd Naushad Ahmed   
 * @Email       : NAUSHAD.DLN@GMAIL.COM
 * @Date        : 25-Nov-2016
 *
 * @Description : This function is used to create the mapp between
 *                ARM Peripheral for GPIO Physical memory into kernel
 *                mapped memory/virtual memory. 
 * @Param       : A structure of gpio, which holds GPIO base address
 *                , a mapped address and a file descriptor of mapped region
 * @Return      : Upon success it returns 0 and -1 upon failure.
 *
 **/
int gpio_memmap (soc_2837_gpio_controller_t *gpio) {

  if ((gpio->mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
	  fprintf(stderr, "Failed to open mem device\n");
		return -1;
	}
  
	/* Mapping GPIO Physical memeory into virtual memory */
	gpio->map = mmap(NULL, /*Let the Kernel decisides for us*/
                BLOCK_SIZE,
                (PROT_READ | PROT_WRITE), /*The Mapped region is protected*/
                MAP_SHARED, /*Shared accross Process*/
                gpio->mem_fd, /*File Descriptor of mapped region*/
                gpio->gpio_base_address);

  if (gpio->map == MAP_FAILED) {
    perror("mmap");
    return -1;		
	}	
  
	/* Virtual Address mapped by Kernel */
	gpio->gpio_base_addr = (volatile unsigned int *)gpio->map;
  return 0;
}/* gpio_memmap */


/**
 *
 *
 *
 *
 *
 */
void gpio_memunmap (soc_2837_gpio_controller_t *gpio) {
  
  munmap(gpio->map, BLOCK_SIZE);
  close(gpio->mem_fd);	
}/* gpio_memunmap */


/**
 * @Description: 
 * 000 = GPIO Pin n is an input
 * 001 = GPIO Pin n is an output
 * 100 = GPIO Pin n takes alternate function 0 
 * 101 = GPIO Pin n takes alternate function 1 
 * 110 = GPIO Pin n takes alternate function 2 
 * 111 = GPIO Pin n takes alternate function 3 
 * 011 = GPIO Pin n takes alternate function 4 
 * 010 = GPIO Pin n takes alternate function 5
 * @param          : gpio number
 * @param          : respective GPIO is set OUTPUT
 * @return         : Always return 0
 **/
int set_gpio_out (unsigned int gpio_n, unsigned int *out) {

  *out = 0;
  /* sets the respective bit */					
  *out |= (1 << (gpio_n % 10) * 3);
  *(gpio.gpio_base_addr + (gpio_n / 10)) = *out;
	return 0;
}/* set_gpio_out */


/**
 * @Description: 
 * 000 = GPIO Pin n is an input
 * 001 = GPIO Pin n is an output
 * 100 = GPIO Pin n takes alternate function 0 
 * 101 = GPIO Pin n takes alternate function 1 
 * 110 = GPIO Pin n takes alternate function 2 
 * 111 = GPIO Pin n takes alternate function 3 
 * 011 = GPIO Pin n takes alternate function 4 
 * 010 = GPIO Pin n takes alternate function 5
 * @param          : gpio number
 * @param          : respective GPIO is set OUTPUT
 * @return         : Always return 0
 **/
int set_gpio_in (unsigned int gpio_n, unsigned int *out) {

  *out = 0;
  /* bits positions keep changing based on GPIO Number */				
  /* sets the respective bit */					
  *out  &= ~(7 << (gpio_n % 10) * 3);
  *(gpio.gpio_base_addr + (gpio_n / 10)) = *out;
  return 0;
}/* set_gpio_in */


/**
 * @Description: The output clear registers are used to clear a GPIO pin. 
 *               The CLR{n} field defines the respective GPIO pin to clear, 
 *               writing a “0” to the field has no effect. 
 *               If the GPIO pin is being used as in input (by default) 
 *               then the value in the CLR{n} field is ignored. However, 
 *               if the pin is subsequently defined as an output then the bit will be set according to 
 *               the last set/clear operation. 
 *               Separating the set and clear functions removes the need for read-modify-write operations.
 *
 * */
int set_gpio (unsigned int gpio_n, unsigned int *out) {
  *out = 0;

  if (gpio_n < 32) {
	  *out |= 1 << gpio_n;
    *(gpio.gpio_base_addr + BCM2837_GPSET0) = *out;

	} else {
	  *out |= 1 << (gpio_n - 32); 
    *(gpio.gpio_base_addr + BCM2837_GPSET1) = *out;
	}


  return 0;
}/* set_gpio */


/**
 * @Description: By writing 1 to respective GPIO index will clear the bits 
 * @param          : gpio number
 * @param          : respective GPIO is set to CLR
 * @return         : Always return 0
 **/
int clear_gpio (unsigned int gpio_n, unsigned int *out) {

  *out = 0;

  if (gpio_n < 32) {
    /* sets the respective bit */					
    *out |= 1 << gpio_n;
    *(gpio.gpio_base_addr + BCM2837_GPCLR0) = *out;

	} else {
    /*set the bits 0 - 21 for GPIO greater than 31 */					
    *out |= (1 << (gpio_n - 32));
    *(gpio.gpio_base_addr + BCM2837_GPCLR1) = *out;
	}

	return 0;
}/* clear_gpio */

unsigned int gpio_read (unsigned int gpio_n) {
 				
  if (gpio_n < 32) {
	  return (*(gpio.gpio_base_addr + BCM2837_GPLEV0) &= (1 << gpio_n));
	} else {
	  return (*(gpio.gpio_base_addr + BCM2837_GPLEV1) &= (1 << (gpio_n - 32)));
	}

}/* gpio_read*/


int set_gpio_level (unsigned int gpio_n, 
								    unsigned char lev, 
								    unsigned int *out) {
 
  *out = 0;

  /* GPIO pin n is HIGH */			 	
  if (lev == 1) {				
    if (gpio_n < 32) {
      /* sets the respective bit */					
      *out |= (1 << gpio_n);
			*(gpio.gpio_base_addr + BCM2837_GPLEV0) = *out;

	  } else {
      /*set the bits 0 - 21 for GPIO greater than 31 */					
      *out |= (1 << (gpio_n - 32));
			*(gpio.gpio_base_addr + BCM2837_GPLEV1) = *out;
    }

	} else {
    if (gpio_n < 32) {
      /* sets the respective bit */					
      *out &= ~(1 << gpio_n);
			*(gpio.gpio_base_addr + BCM2837_GPLEV0) = *out;
	  } else {
      /*set the bits 0 - 21 for GPIO greater than 31 */					
      *out &= ~(1 << (gpio_n - 32));
			*(gpio.gpio_base_addr + BCM2837_GPLEV1) = *out;
    }
	}
  
}/* set_gpio_level */


int main(int argc, char *argv[]) {
  
	unsigned int               out      = 0x00000000;
  unsigned int               gpio_pin = 0x00000000;

	if (argc < 2) {
	  fprintf(stderr, "Invalid Number of arguments [arg1 shall be gpio number]\n");
		return -1;
	}

  if (gpio_memmap(&gpio) < 0) {

	  fprintf(stderr, "Failed to map the Physical GPIO registers into virtual memory\n");
		return -1;
	}

  gpio_pin = atoi(argv[1]);

  set_gpio_in(gpio_pin, &out);
  set_gpio_out(gpio_pin, &out);

	while (1) {
					
	 set_gpio(gpio_pin, &out);
	 sleep(1);
   fprintf(stderr, "AFTER SET GPIO %d READ\n",gpio_read(gpio_pin));

	 clear_gpio(gpio_pin, &out);
	 sleep(1);
   fprintf(stderr, "AFTER CLEAR GPIO %d READ\n",gpio_read(gpio_pin));
	}
  return 0;	
}/* main */
