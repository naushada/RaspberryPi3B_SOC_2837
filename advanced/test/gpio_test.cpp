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
    inst.gpio().write(gpio_n, GPIO::Config::InputMode);
    auto res = inst.gpio().read(gpio_n);
    //std::cout << "gpio in Result:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, GPIO::Config::InputMode);
}

TEST(GPIOTestSuite, GPIO_Number_12_OutputMode) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().write(gpio_n, GPIO::Config::OutputMode);
    auto res = inst.gpio().read(gpio_n);
    //std::cout << "gpio out Result:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, GPIO::Config::OutputMode);
}

TEST(GPIOTestSuite, GPIO_Number_12_AlternateFunction0) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction0);
    auto res = inst.gpio().read(gpio_n);
    //std::cout << "AlternateFunction0:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, GPIO::Config::AlternateFunction0);
}

TEST(GPIOTestSuite, GPIO_Number_12_AlternateFunction1) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction1);
    auto res = inst.gpio().read(gpio_n);
    //std::cout << "AlternateFunction1:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, GPIO::Config::AlternateFunction1);
}

TEST(GPIOTestSuite, GPIO_Number_12_AlternateFunction2) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction2);
    auto res = inst.gpio().read(gpio_n);
    //std::cout << "AlternateFunction2:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, GPIO::Config::AlternateFunction2);
}

TEST(GPIOTestSuite, GPIO_Number_12_AlternateFunction3) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction3);
    auto res = inst.gpio().read(gpio_n);
    //std::cout << "AlternateFunction3:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, GPIO::Config::AlternateFunction3);
}

TEST(GPIOTestSuite, GPIO_Number_12_AlternateFunction4) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction4);
    auto res = inst.gpio().read(gpio_n);
    //std::cout << "AlternateFunction4:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, GPIO::Config::AlternateFunction4);
}

TEST(GPIOTestSuite, GPIO_Number_12_AlternateFunction5) {

    GPIOTest inst;
    /**
     * GPIONumber 12 is mapped to GPIO PIN 32
    */
    GPIO::gpio_number gpio_n = 12;
    inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction5);
    auto res = inst.gpio().read(gpio_n);
    //std::cout << "AlternateFunction5:" << std::to_string(res) << std::endl;
    EXPECT_EQ(res, GPIO::Config::AlternateFunction5);
}

TEST(GPIOTestSuite, GPIO_Number_0to9_OutputMode) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 0;
    for(; gpio_n < 10; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::OutputMode);
    }

    gpio_n = 0;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 0 to 9: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x9249249);
}

TEST(GPIOTestSuite, GPIO_Number_10to19_OutputMode) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 10;
    for(; gpio_n < 20; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::OutputMode);
    }

    gpio_n = 10;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 10 to 19: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x9249249);
}

TEST(GPIOTestSuite, GPIO_Number_20to29_OutputMode) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 20;
    for(; gpio_n < 30; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::OutputMode);
    }

    gpio_n = 20;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 20 to 29: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x9249249);
}

TEST(GPIOTestSuite, GPIO_Number_30to39_OutputMode) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 30;
    for(; gpio_n < 40; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::OutputMode);
    }

    gpio_n = 30;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 30 to 39: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x9249249);
}

TEST(GPIOTestSuite, GPIO_Number_40to49_OutputMode) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 40;
    for(; gpio_n < 50; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::OutputMode);
    }

    gpio_n = 40;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 40 to 49: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x9249249);
}

TEST(GPIOTestSuite, GPIO_Number_50to53_OutputMode) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 50;
    for(; gpio_n < 54; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::OutputMode);
    }

    gpio_n = 50;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 50 to 53: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x249);
}

TEST(GPIOTestSuite, GPIO_Number_0to9_AlternateFunction0) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 0;
    for(; gpio_n < 10; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction0);
    }

    gpio_n = 0;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 0 to 9: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x24924924);
}

TEST(GPIOTestSuite, GPIO_Number_10to19_AlternateFunction2) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 10;
    for(; gpio_n < 20; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction2);
    }

    gpio_n = 10;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 10 to 19: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x36db6db6);
}

TEST(GPIOTestSuite, GPIO_Number_20to29_AlternateFunction5) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 20;
    for(; gpio_n < 30; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction5);
    }

    gpio_n = 20;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 20 to 29: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x12492492);
}

TEST(GPIOTestSuite, GPIO_Number_30to39_InputMode) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 30;
    for(; gpio_n < 40; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::InputMode);
    }

    gpio_n = 30;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 30 to 39: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x0);
}

TEST(GPIOTestSuite, GPIO_Number_40to49_OutputMode_AlternateFunction3) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 40;
    for(; gpio_n < 45; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::OutputMode);
    }

    for(; gpio_n < 50; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction3);
    }

    gpio_n = 40;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 40 to 49: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x3fff9249);
}

TEST(GPIOTestSuite, GPIO_Number_50to53_InputMode_AlternateFunction4) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 50;
    for(; gpio_n < 52; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::InputMode);
    }

    for(; gpio_n < 54; ++gpio_n) {
        inst.gpio().write(gpio_n, GPIO::Config::AlternateFunction4);
    }

    gpio_n = 50;
    auto res = inst.gpio().read32(gpio_n);
    //std::cout << "GPIO 50 to 53: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 0x6c0);
}

TEST(GPIOTestSuite, GPIO_Number_0to31_GPSETn) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 0;
    for(; gpio_n < 32; ++gpio_n) {
        inst.gpio().GPSETn(gpio_n);
    }

    gpio_n = 20;
    auto res = inst.gpio().GPGETn(gpio_n);
    //std::cout << "GPIO 0 to 31: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 01);
}

TEST(GPIOTestSuite, GPIO_Number_32to53_GPSETn) {

    GPIOTest inst;

    GPIO::gpio_number gpio_n = 32;
    for(; gpio_n < 54; ++gpio_n) {
        inst.gpio().GPSETn(gpio_n);
    }

    gpio_n = 40;
    auto res = inst.gpio().GPGETn(gpio_n);
    //std::cout << "GPIO 32 to 53: 0x" << std::hex << res << std::dec << std::endl;

    EXPECT_EQ(res, 01);
}

#endif /*__gpio_test_cpp__*/