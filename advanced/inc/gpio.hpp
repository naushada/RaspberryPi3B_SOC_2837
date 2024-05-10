#ifndef __gpio_hpp__
#define __gpio_hpp__

#include <cstdint>
#include <cstdio>

class GPIO {
    public:
        enum Register: std::uint32_t {
            /* GPIO Function Selection offset */
            BCM2837_GPFSEL0,
            BCM2837_GPFSEL1,
            BCM2837_GPFSEL2,
            BCM2837_GPFSEL3,
            BCM2837_GPFSEL4,
            BCM2837_GPFSEL5,
            BCM2837_GPFSEL_RESERVED,
            /* GPIO SET Address offset */
            BCM2837_GPSET0,
            BCM2837_GPSET1,
            BCM2837_GPSET_RESERVED,
            /* Offset for clearing the GPIO */
            BCM2837_GPCLR0,
            BCM2837_GPCLR1,
            BCM2837_GPCLR_RESERVED,
            /* Offset for GPIO LEV0/1 */
            BCM2837_GPLEV0,
            BCM2837_GPLEV1,
            BCM2837_GPLEV_RESERVED,
            BCM2837_GPEDS0,
            BCM2837_GPEDS1,
            BCM2837_GPEDS_RESERVED,
            BCM2837_GPREN0,
            BCM2837_GPREN1,
            BCM2837_GPREN_RESERVED,
            BCM2837_GPFEN0,
            BCM2837_GPFEN1,
            BCM2837_GPFEN_RESERVED,
            BCM2837_GPHEN0,
            BCM2837_GPHEN1,
            BCM2837_GPHEN_RESERVED,
            BCM2837_GPLEN0,
            BCM2837_GPLEN1,
            BCM2837_GPLEN_RESERVED,
            BCM2837_GPAREN0,
            BCM2837_GPAREN1,
            BCM2837_GPAREN_RESERVED,
            BCM2837_GPAFEN0,
            BCM2837_GPAFEN1,
            BCM2837_GPAFEN_RESERVED,
            BCM2837_GPPUD,
            BCM2837_GPPUDCLK0,
            BCM2837_GPPUDCLK1,
            BCM2837_MAX
        };

        using device_register = std::uint32_t volatile;
        using gpio_number = std::uint32_t;

        /* @brief Compiler give preference to this new operator over global new operator and invoke this new operator. */
        void *operator new(std::size_t) {
            return reinterpret_cast<void *>((0x3F000000) + (0x00200000));
        }

        GPIO() {
            for(auto idx = 0; idx < Register::BCM2837_MAX; ++idx) {
                std::printf("\nAddress of this 0x%X: ", &m_register[idx]);
            }
        }
        ~GPIO() = default;

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
        void in(gpio_number gpio);
        void out(gpio_number gpio);
        std::uint32_t get(gpio_number gpio);
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
        void set(gpio_number gpio);
        void clear(gpio_number gpio);

    private:
        device_register m_register[Register::BCM2837_MAX];

};





























#endif /* __gpio_hpp__*/