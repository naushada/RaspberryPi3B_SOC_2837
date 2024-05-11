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
        GPIOTest(const std::string& in);
        ~GPIOTest() = default;
     
        std::string& getFileName() {
            return(fileName);
        }
        
        virtual void SetUp() override;
        virtual void TearDown() override;
        virtual void TestBody() override;

    private:
        std::string fileName;
};


#endif /*__gpio_test_hpp__*/