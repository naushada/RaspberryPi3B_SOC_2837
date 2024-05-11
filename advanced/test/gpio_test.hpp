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
        GPIOTest() : m_gpio(*new(m_reg) GPIO) {}
        ~GPIOTest() = default;
     
        std::string& getFileName() {
            return(fileName);
        }
        
        virtual void SetUp() override;
        virtual void TearDown() override;
        virtual void TestBody() override;

        GPIO& gpio() const {
            return(m_gpio);
        }

    private:
        std::string fileName;
        std::uint32_t m_reg[41];
        GPIO& m_gpio;
};


#endif /*__gpio_test_hpp__*/