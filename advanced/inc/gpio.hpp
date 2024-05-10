#ifndef __gpio_hpp__
#define __gpio_hpp__

#include <cstdint>
#include <cstdio>

class GPIO {
    public:
        using device_register = std::uint32_t volatile;
        using gpio_number = std::uint32_t;

        void *operator new(std::size_t) {
            return reinterpret_cast<void *>((0x3F000000) + (0x00200000));
        }

        GPIO() {
            std::printf("\nAddress of this 0x%X\n", this);
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

        enum class Register: std::uint32_t {
            /* GPIO Function Selection offset */
            BCM2837_GPFSEL0	= 0x00000000,
            BCM2837_GPFSEL1	= 0x00000001,
            BCM2837_GPFSEL2	= 0x00000002,
            BCM2837_GPFSEL3	= 0x00000003,
            BCM2837_GPFSEL4	= 0x00000004,
            BCM2837_GPFSEL5	= 0x00000005,
            BCM2837_GPFSEL_RESERVED = 0x00000006,
            /* GPIO SET Address offset */
            BCM2837_GPSET0 = 0x00000007,
            BCM2837_GPSET1 = 0x00000008,
            BCM2837_GPSET_RESERVED = 0x00000009,
            /* Offset for clearing the GPIO */
            BCM2837_GPCLR0 = 0x0000000A,
            BCM2837_GPCLR1 = 0x0000000B,
            BCM2837_GPCLR_RESERVED = 0x0000000C,
            /* Offset for GPIO LEV0/1 */
            BCM2837_GPLEV0 = 0x0000000D,
            BCM2837_GPLEV1 = 0x0000000E,
            BCM2837_GPLEV_RESERVED = 0x0000000F,
            BCM2837_GPEDS0 = 0x00000010,
            BCM2837_GPEDS1 = 0x00000020,
            BCM2837_GPEDS_RESERVED = 0x00000030,
            BCM2837_GPREN0 = 0x00000040,
            BCM2837_GPREN1 = 0x00000050,
            BCM2837_GPREN_RESERVED = 0x00000060,
            BCM2837_GPFEN0 = 0x00000070,
            BCM2837_GPFEN1 = 0x00000080,
            BCM2837_GPFEN_RESERVED = 0x00000090,
            BCM2837_GPHEN0 = 0x000000A0,
            BCM2837_GPHEN1 = 0x000000B0,
            BCM2837_GPHEN_RESERVED = 0x000000C0,
            BCM2837_GPLEN0 = 0x000000D0,
            BCM2837_GPLEN1 = 0x000000E0,
            BCM2837_GPLEN_RESERVED = 0x000000F0,
            BCM2837_GPAREN0 = 0x00000100,
            BCM2837_GPAREN1 = 0x00000200,
            BCM2837_GPAREN_RESERVED = 0x00000300,
            BCM2837_GPAFEN0 = 0x00000400,
            BCM2837_GPAFEN1 = 0x00000500,
            BCM2837_GPAFEN_RESERVED = 0x00000600,
            BCM2837_GPPUD = 0x00000700,
            BCM2837_GPPUDCLK0 = 0x00000800,
            BCM2837_GPPUDCLK1 = 0x00000900,
            /* 32bits Registers */
            BCM2837_GPFSELn_INPUT = 0x00000000,
            BCM2837_GPFSELn_OUTPUT = 0x00000001
        };
    private:
        device_register m_register;

};





























#endif /* __gpio_hpp__*/