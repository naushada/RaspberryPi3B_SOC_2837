#ifndef __gpio_cpp__
#define __gpio_cpp__


#include "gpio.hpp"



std::uint32_t GPIO::get(gpio_number gpio_n) {
    if(gpio_n < 32) {
        return (m_register[Register::BCM2837_GPLEV0] &= (1U << gpio_n));
	}

	return (m_register[Register::BCM2837_GPLEV1] &= (1U << (gpio_n - 32)));
}

void GPIO::out(gpio_number gpio_n) {
    ///@brief setting GPIO to output mode.
    /* sets the respective bit */					
    m_register[(gpio_n / 10)] = (1U << (gpio_n % 10) * 3U);
}

void GPIO::in(gpio_number gpio_n) {
    ///@brief setting GPIO to input mode.
    /* bits positions keep changing based on GPIO Number */				
    /* sets the respective bit */					
    m_register[(gpio_n / 10)] = (~(7U << (gpio_n % 10U) * 3U));
}

void GPIO::clear(gpio_number gpio_n) {
    if(gpio_n < 32) {
        /* sets the respective bit */					
        m_register[Register::BCM2837_GPCLR0] = (1U << gpio_n);
	} else {
        /*set the bits 0 - 21 for GPIO greater than 31 */					
        m_register[Register::BCM2837_GPCLR1] = (1U << (gpio_n - 32));
	}
}

void GPIO::set(gpio_number gpio_n) {
  
    if(gpio_n < 32) {
        m_register[Register::BCM2837_GPSET0] = (1U << gpio_n);
    } else {
        m_register[Register::BCM2837_GPSET1] = (1U << (gpio_n - 32));
	}
}


std::int32_t main() {
    GPIO &gpio = *new GPIO;
}


















#endif /*__gpio_cpp__*/