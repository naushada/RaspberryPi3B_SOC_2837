#ifndef __gpio_cpp__
#define __gpio_cpp__


#include "gpio.hpp"

std::uint32_t GPIO::read(gpio_number gpio_n) {
    return(m_register[gpio_n/10]);
}

std::uint32_t GPIO::level(gpio_number gpio_n) {
    if(gpio_n < 32) {
        return (m_register[Register::BCM2837_GPLEV0] &= (1U << gpio_n));
	}

	return (m_register[Register::BCM2837_GPLEV1] &= (1U << (gpio_n - 32)));
}

void GPIO::output(gpio_number gpio_n) {

    /* @brief:
    *  Each 32bits register can accomodate 10 gpios FSEL, hence division by 10.
    *  gpios (0-9), (10-19), (20-29), (30-39), (40-49) and (50-53) will be 
    *  programmed in register FSEL0, FSEL1, FSEL2, FSEL3, FSEL4 and FSEL5 respectively.
    */
    m_register[(gpio_n / 10)] |= (1U << ((gpio_n % 10) * 3U));
}

void GPIO::input(gpio_number gpio_n) {

    /* @brief:
    *  Each 32bits register can accomodate 10 gpios FSEL, hence division by 10.
    *  gpios (0-9), (10-19), (20-29), (30-39), (40-49) and (50-53) will be 
    *  programmed in register FSEL0, FSEL1, FSEL2, FSEL3, FSEL4 and FSEL5 respectively.
    */		
    m_register[(gpio_n / 10)] &= (~(7U << ((gpio_n % 10U) * 3U)));
}

void GPIO::clear(gpio_number gpio_n) {
    if(gpio_n < 32) {
        /* sets the respective bit */					
        m_register[Register::BCM2837_GPCLR0] &= (~(1U << gpio_n));
	} else {
        /*set the bits 0 - 21 for GPIO greater than 31 */					
        m_register[Register::BCM2837_GPCLR1] &= (~(1U << (gpio_n - 32)));
	}
}

void GPIO::set(gpio_number gpio_n) {
  
    if(gpio_n < 32) {
        m_register[Register::BCM2837_GPSET0] |= (1U << gpio_n);
    } else {
        /*set the bits 0 - 21 for GPIO greater than 31 */
        m_register[Register::BCM2837_GPSET1] |= (1U << (gpio_n - 32));
	}
}



















#endif /*__gpio_cpp__*/