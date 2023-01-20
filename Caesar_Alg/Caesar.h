#ifndef CAESAR_H
#define CAESAR_H

#include <string>
#include <map>
#include <iostream>

class Caesar {
public:
    Caesar();
    Caesar(const Caesar&) = delete;
    Caesar(Caesar&&) = delete;
public:
    std::string operator() (const std::string&, std::string&, const int);
    void init(std::string&, std::string&, int*);
private:
    void initMap();
    bool isSmallLetter(const char);
    bool isValidCommand(std::string&);
    bool isValidLine(const std::string&);
    std::string toLowerCase(std::string&);
    void initStep(int*);
    void initLine(std::string&);
    void initCommand(std::string&);
private:
    enum class Key {
        ENCODE = 1,
        DECODE,
    };
    using Cfunctions = std::string(Caesar::*)(std::string&, const int);
private:
    std::string encode(std::string&, int);
    std::string decode(std::string&, int);
    
private:
    std::map<std::string, Key> key_map;
    std::map<Key, Cfunctions> function_map;
private:
    const int alphabetSize;
    const char lastSmallLetter;
    const char firstSmallLetter;
    const char lastCapitalLetter;
    const char firstCapitalLetter;
    const char witheSpace;
};

#endif // CAESAR_H