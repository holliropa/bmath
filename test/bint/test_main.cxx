#include <iostream>
#include "test_construction.cxx"


int main(int argc, char *argv[]) {
    std::cout << "[bint] Running tests...\n";

    run_constructor_tests();

    std::cout << "[bint] All tests passed!\n";
    return 0;
}