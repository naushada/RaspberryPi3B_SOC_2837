#ifndef __gpio_cpp__
#define __gpio_cpp__


#include "gpio.hpp"


void GPIO::in(gpio_number gpio_n) {
    /* bits positions keep changing based on GPIO Number */				
    /* sets the respective bit */					
  
    *(&m_register + (gpio_n / 10)) = (~(7U << (gpio_n % 10U) * 3U));
}

void GPIO::set(gpio_number gpio_n) {
  
    if(gpio_n < 32) {
        *(&m_register + Register::BCM2837_GPSET0) = (1U << gpio_n);
    } else {
        *(&m_register + Register::BCM2837_GPSET1) = (1U << (gpio_n - 32));
	}
}


std::int32_t main() {
    GPIO *gpio = new GPIO;

    gpio->in(12);
}


















#endif /*__gpio_cpp__*/