#ifndef __gpio_test_hpp__
#define __gpio_test_hpp__


#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gpio.hpp"

class GPIOTest : public ::testing::Test
{
    public:
        /**
         * @brief Memory region for GPIO instance will be taken from m_memory_region,
         *        the GPIO instance layout will be done from m_memory_region.
        */
        GPIOTest() : m_gpio(*new(m_memory_region) GPIO) {}
        ~GPIOTest() = default;
        
        virtual void SetUp() override;
        virtual void TearDown() override;
        virtual void TestBody() override;

        GPIO& gpio() const {
            return(m_gpio);
        }

    private:
        std::uint32_t m_memory_region[64];
        GPIO& m_gpio;
};


#endif /*__gpio_test_hpp__*/