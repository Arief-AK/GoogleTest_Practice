#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char **argv){
    std::cout << "Hello, from GoogleTestProject!\n";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
