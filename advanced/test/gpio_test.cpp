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
    //std::uint32_t reg[41];
    GPIOTest inst;
    /**
     * @brief Memory for GPIO instance will be taken from reg memory,
     *        instance layout will be done on memory allocated for reg vector of dimention 41
    */
    //GPIO &gpio = *new(reg) GPIO;

    inst.gpio().in(12);

}















#endif /*__gpio_test_cpp__*/