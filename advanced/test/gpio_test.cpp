#ifndef __gpio_test_cpp__
#define __gpio_test_cpp__

#include "gpio_test.hpp"
#include <vector>

void GPIOTest::SetUp() {

}

void GPIOTest::TearDown() {

}

void GPIOTest::TestBody() {

}

TEST(GPIOTestSuite, GPIO_12_InputMode) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().input(gpio_n);
    auto res = inst.gpio().read(gpio_n);
    std::cout << "gpio in Result:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, 0x00);
}

TEST(GPIOTestSuite, GPIO_12_OutputMode) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().output(gpio_n);
    auto res = inst.gpio().read(gpio_n);
    std::cout << "gpio out Result:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, 0x40);
}














#endif /*__gpio_test_cpp__*/