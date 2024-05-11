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
            BCM2837_RESERVED,
            BCM2837_TEST1,
            BCM2837_TEST2,
            BCM2837_TEST3,
            BCM2837_TEST4,
            BCM2837_MAX
        };

        using device_register = std::uint32_t volatile;
        using gpio_number = std::uint32_t;

        /** 
         * @brief Compiler give preference to this new operator over global new operator and invoke this new operator. 
         * @param nBytes Number of bytes to be allocated
         * @param region is the memory region to be return if present.
         * @return pointer to void
         */
        void *operator new(std::size_t nBytes, void *region=nullptr) {

            if(nullptr == region) {
                /**
                 * @brief 
                 *  The address is Physical address of GPIO for Raspberry Pi 3B and
                 *  is used for memory map for GPIO.
                 */
                return reinterpret_cast<void *>((0x3F000000) + (0x00200000));
            }
            return(region);
        }

        GPIO() {
            for(auto idx = 0; idx < Register::BCM2837_MAX; ++idx) {
                std::printf("\nAddress of this 0x%X: ", &m_register[idx]);
            }
            std::printf("\n");
        }

        ~GPIO() = default;

        /**
         * @brief
            * 000 = GPIO Pin n is an input
            * 001 = GPIO Pin n is an output
            * 100 = GPIO Pin n takes alternate function 0
            * 101 = GPIO Pin n takes alternate function 1
            * 110 = GPIO Pin n takes alternate function 2
            * 111 = GPIO Pin n takes alternate function 3
            * 011 = GPIO Pin n takes alternate function 4
            * 010 = GPIO Pin n takes alternate function 5
            * 
         * @param gpio number
         * @return none
         **/
        void input(gpio_number gpio);
        void output(gpio_number gpio);
        std::uint32_t level(gpio_number gpio);

        /**
         * @brief
            * The output clear registers are used to clear a GPIO pin. 
            * The CLR{n} field defines the respective GPIO pin to clear, 
            * writing a “0” to the field has no effect. 
            * If the GPIO pin is being used as in input (by default) 
            * then the value in the CLR{n} field is ignored. However, 
            * if the pin is subsequently defined as an output then the bit will be set according to 
            * the last set/clear operation. 
            * Separating the set and clear functions removes the need for read-modify-write operations.
            *
         * @param gpio_number
         * @return none
         * */
        void clear(gpio_number gpio);
        void set(gpio_number gpio);
        std::uint32_t read(gpio_number gpio_n);

    private:
        /** 
         * @brief
         * address for m_register will be 
         * [0x3F200000, 0x3F200004, 0x3F200008, 0x3F20000C, 0x3F200010, 0x3F200014, 0x3F200018, 0x3F20001C  ... 0x3F2000B0] 
         **/
        device_register m_register[Register::BCM2837_MAX];

};





























#endif /* __gpio_hpp__*/