#include "gtest.h"

#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
