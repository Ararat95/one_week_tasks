#include "BitVector.h"

Bitvector::Bitvector() : _size{2} {
    _arr = new int[_size];
}

Bitvector::~Bitvector() {
    clean();
}

Bitvector::Bitvector(const int size) :_size(size) {
    _arr = new int[_size];
}

Bitvector::Bitvector(const Bitvector& src) {
    if (_size < src._size) {
        _size = src._size;
        int* tmp = new int[_size];
        for (int i = 0; i < _size; ++i) {
            tmp[i] = _arr[i];
        }
        clean();
        _arr = tmp;
        tmp = nullptr;
    }
    for (int i = 0; i < _size; ++i) {
        _arr[i] = src._arr[i];
    }
}

Bitvector::Bitvector(Bitvector&& src) {
    _size = src._size;
    src._size = 0;
    _arr = src._arr;
    src._arr = nullptr;
}

int& Bitvector::operator[](const int index) {
    if (index >= _size) {
       return _arr[0];
    }
    return _arr[index];
}

void Bitvector::resize(const int size) {
    int tmp_size = (size / (sizeof(int) * 8)) + 1;
    int* tmp = new int[tmp_size];
    for (int i = 0; i < _size; ++i) {
        tmp[i] = _arr[i];
    }
    clean();
    _arr = tmp;
    tmp = nullptr;
    _size = tmp_size;
}

void Bitvector::set(const int position, const bool value) {
    if (_size <=  position / (sizeof(int) * 8)) {
        resize(position);
    }
    if (position < 0) {
        return;
    }
    int index = position / (sizeof(int) * 8);

    int index_position = ((index + 1) * sizeof(int) * 8) - position;
    if (value) {
        _arr[index] |= (value << index_position);
    }
    else {
        _arr[index] &= ~(1 << index_position);
    }
}

std::ostream& operator << (std::ostream& os, const Bitvector& src) {
    os << '{';
    for (int i = src._size - 1; i >= 0; --i) {
        os << src._arr[i] << ',';
    }
    os << '}';
    return os;
}

bool Bitvector::get(const int position) const {
    if (position >=  _size * (sizeof(int) * 8) || position < 0) {
        return 0;
    }
    int index = position / (sizeof(int) * 8);
    int index_position = ((index + 1) * sizeof(int) * 8) - position;
    return (_arr[index] >> index_position) & 1;
}

int Bitvector::size() const {
    return this->_size;
}

void Bitvector::clean() {
    delete[] _arr;
    _arr = nullptr;
    _size = 0;
}