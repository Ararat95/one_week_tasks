#include "Caesar.h"

Caesar::Caesar() : 
alphabetSize{26}, 
firstSmallLetter{'a'},
lastSmallLetter{'z'},
firstCapitalLetter{'A'},
lastCapitalLetter{'Z'},
witheSpace{' '}
{
    initMap();
}

void Caesar::initMap() {
    key_map["decode"] = Key::DECODE;
    key_map["encode"] = Key::ENCODE;

    function_map[Key::ENCODE] = &Caesar::encode;
    function_map[Key::DECODE] = &Caesar::decode;
}

std::string Caesar::operator()(const std::string& command, std::string& line, const int step) {
    return (this->*function_map[key_map[command]])(line, step);
}

void Caesar::initCommand(std::string& command) {
    std::cout << "Enter command decode or encode: ";
    do {
        std::cin >> command;
        if (isValidCommand(command)) {
            break;
        }
        else {
            std::cout << "wrong command try again decode or encode: ";
        }
    }while(true);
}

void Caesar::initLine(std::string& line) {
    std::cout << "Enter line which you want to encode/decode: ";
    do {
        getline(std::cin, line);
        if (line == "" || line == " ") {
            continue;
        }
        if (isValidLine(line)) {
            break;
        }
        else {
            std::cout << "line contains wrong symbols, try again: ";
        }
    }while(true);
}

void Caesar::initStep(int* step) {
    std::cout << "Enter number of steps you need to encode/decode: ";
    do {
        std::cin >> *step;
        if (*step > 0) {
            break;
        }
        else {
            std::cout << "Invalid number of steps, please try again: ";
        }
    }while(true);
}

void Caesar::init(std::string& command, std::string& line, int* step) {
    initCommand(command);
    initLine(line);
    initStep(step);
}

std::string Caesar::toLowerCase(std::string& src) {
    for (auto& it : src) {
        if (it >= firstCapitalLetter && it <= lastCapitalLetter) {
            it += 32;
        }
    }
    return src;
}

bool Caesar::isValidCommand(std::string& src) {
    if (toLowerCase(src) == "decode" || toLowerCase(src) == "encode") {
        return true;
    }
    return false;
}


bool Caesar::isValidLine(const std::string& src) {
    for (auto it = src.begin(); it < src.end(); ++it) {
        if (!(*it >= firstSmallLetter && *it <= lastSmallLetter) && 
        !(*it >= firstCapitalLetter && *it <= lastCapitalLetter)) {
            return false;
        }
    }
    return true;
}

bool Caesar::isSmallLetter(const char symbol) {
    return (symbol >= firstSmallLetter && symbol <= lastSmallLetter);
}

std::string Caesar::encode(std::string& line, int step) {
    if (step > alphabetSize) {
        step = step - (alphabetSize * (step / alphabetSize));
    }
    for (auto it = line.begin(); it < line.end(); ++it) {
        if (*it == witheSpace) {
            continue;
        }

        if (isSmallLetter(*it)) {
            if ((*it + step) > lastSmallLetter) {
                *it = firstSmallLetter + (step - (lastSmallLetter - *it)) - 1;
                continue;
            }
        }
        else {
            if ((*it + step) > lastCapitalLetter) {
                *it = firstCapitalLetter + (step - (lastCapitalLetter - *it)) - 1;
                continue;
            }
        }
        *it += step;
    }
    return line;
}

std::string Caesar::decode(std::string& line, int step) {
    if (step > alphabetSize) {
        step = step - (alphabetSize * (step / alphabetSize));
    }
    for (auto it = line.begin(); it < line.end(); ++it) {
        if (*it == witheSpace) {
            continue;
        }

        if (isSmallLetter(*it)) {
            if ((*it - step) < firstSmallLetter) {
                *it = lastSmallLetter - ( step - (*it - firstSmallLetter)) + 1;
                continue;
            }
        }
        else {
            if ((*it - step) < firstCapitalLetter) {
                *it = lastCapitalLetter - (step - (*it - firstCapitalLetter)) + 1;
                continue;
            }
        }
        *it -= step;
    }
    return line;
}