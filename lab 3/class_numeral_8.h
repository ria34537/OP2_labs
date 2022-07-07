#pragma once
#include <iostream>
#include "vector"

using namespace std;

class Numeral_8 {
    int size;
    vector<int> vec;
public:
    Numeral_8(const Numeral_8 &obj);
    explicit  Numeral_8(string line);
    explicit Numeral_8(vector<int> vector);
    vector <int> get_vec() const{return vec;}
    int get_size() const{return size;}

    double to_decimal();
    void output();
    void operator++();
    Numeral_8 operator+(const Numeral_8& num);
    void operator+=(string num);

};
