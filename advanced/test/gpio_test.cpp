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

TEST(GPIOTestSuite, GPIOInputMode) {
    std::uint32_t reg[41];
    GPIO &gpio = *new(reg) GPIO;

    gpio.in(12);

}















#endif /*__gpio_test_cpp__*/