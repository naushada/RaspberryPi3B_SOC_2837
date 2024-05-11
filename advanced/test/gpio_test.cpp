#ifndef __gpio_test_cpp__
#define __gpio_test_cpp__

#include "gpio_test.hpp"
#include <vector>

void GPIOTest::SetUp() {

    m_gpio2PinMap = {
        {"GPIO_Number_1", "GPIO_PIN_"},
        {"GPIO_Number_2", "GPIO_PIN_3"},
        {"GPIO_Number_3", "GPIO_PIN_5"},
        {"GPIO_Number_4", "GPIO_PIN_7"},
        {"GPIO_Number_5", "GPIO_PIN_29"},
        {"GPIO_Number_6", "GPIO_PIN_31"},
        {"GPIO_Number_7", "GPIO_PIN_26"},
        {"GPIO_Number_8", "GPIO_PIN_24"},
        {"GPIO_Number_9", "GPIO_PIN_21"},
        {"GPIO_Number_10", "GPIO_PIN_19"},
        {"GPIO_Number_11", "GPIO_PIN_23"},
        {"GPIO_Number_12", "GPIO_PIN_32"},
        {"GPIO_Number_13", "GPIO_PIN_33"},
        {"GPIO_Number_14", "GPIO_PIN_8"},
        {"GPIO_Number_15", "GPIO_PIN_10"},
        {"GPIO_Number_16", "GPIO_PIN_36"},
        {"GPIO_Number_17", "GPIO_PIN_11"},
        {"GPIO_Number_18", "GPIO_PIN_12"},
        {"GPIO_Number_19", "GPIO_PIN_35"},
        {"GPIO_Number_20", "GPIO_PIN_38"},
        {"GPIO_Number_21", "GPIO_PIN_40"},
        {"GPIO_Number_22", "GPIO_PIN_15"},
        {"GPIO_Number_23", "GPIO_PIN_16"},
        {"GPIO_Number_24", "GPIO_PIN_18"},
        {"GPIO_Number_25", "GPIO_PIN_22"},
        {"GPIO_Number_26", "GPIO_PIN_37"},
        {"GPIO_Number_27", "GPIO_PIN_13"},
        {"GPIO_Number_28", "GPIO_PIN_"},
        {"GPIO_Number_29", "GPIO_PIN_"},
        {"GPIO_Number_30", "GPIO_PIN_"},
        {"GPIO_Number_31", "GPIO_PIN_"},
        {"GPIO_Number_32", "GPIO_PIN_"},
        {"GPIO_Number_33", "GPIO_PIN_"},
        {"GPIO_Number_34", "GPIO_PIN_"},
        {"GPIO_Number_35", "GPIO_PIN_"},
        {"GPIO_Number_36", "GPIO_PIN_"},
        {"GPIO_Number_37", "GPIO_PIN_"},
        {"GPIO_Number_38", "GPIO_PIN_"},
        {"GPIO_Number_39", "GPIO_PIN_"},
        {"GPIO_Number_40", "GPIO_PIN_"},
        {"GPIO_Number_41", "GPIO_PIN_"},
        {"GPIO_Number_42", "GPIO_PIN_"},
        {"GPIO_Number_43", "GPIO_PIN_"},
        {"GPIO_Number_44", "GPIO_PIN_"},
        {"GPIO_Number_45", "GPIO_PIN_"},
        {"GPIO_Number_46", "GPIO_PIN_"},
        {"GPIO_Number_47", "GPIO_PIN_"},
        {"GPIO_Number_48", "GPIO_PIN_"},
        {"GPIO_Number_49", "GPIO_PIN_"},
        {"GPIO_Number_50", "GPIO_PIN_"},
    };
}

void GPIOTest::TearDown() {

}

void GPIOTest::TestBody() {

}

TEST(GPIOTestSuite, GPIO_Number_12_InputMode) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().input(gpio_n);
    auto res = inst.gpio().read(gpio_n);
    std::cout << "gpio in Result:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, GPIO::Config::InputMode);
}

TEST(GPIOTestSuite, GPIO_Number_12_OutputMode) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().output(gpio_n);
    auto res = inst.gpio().read(gpio_n);
    std::cout << "gpio out Result:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, GPIO::Config::OutputMode);
}














#endif /*__gpio_test_cpp__*/