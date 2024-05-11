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
        GPIOTest() : m_reg(64), m_gpio(*new(m_reg.data()) GPIO) {}
        ~GPIOTest() = default;
        
        virtual void SetUp() override;
        virtual void TearDown() override;
        virtual void TestBody() override;

        GPIO& gpio() const {
            return(m_gpio);
        }

    private:
        std::vector<std::uint32_t> m_reg;
        GPIO& m_gpio;
};


#endif /*__gpio_test_hpp__*/