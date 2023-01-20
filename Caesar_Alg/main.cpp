#include "Caesar.h"

int main() {

    std::string command{};
    std::string line{};
    int step{};
    Caesar alg;


    alg.init(command, line, &step);
    std::string result = alg(command, line, step);
    std::cout << result << std::endl;


    return 0;
}