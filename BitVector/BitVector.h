#ifndef BITVECTOR_H
#define BITVECTOR_H

#include <iostream>

class Bitvector {
public:
    Bitvector();
    Bitvector(const int);
    Bitvector(const Bitvector&);
    Bitvector(Bitvector&&);
    ~Bitvector();
public:
    int& operator [](const int);
    friend std::ostream& operator <<(std::ostream&, const Bitvector&);
public:
    void set(const int, const bool);
    bool get(const int) const;
    int size() const;
    void clean();
private:
    void resize(const int);
private:
    int* _arr;
    int _size;

};

#endif //BITVECTOR_H