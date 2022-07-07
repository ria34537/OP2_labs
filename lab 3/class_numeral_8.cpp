#include "class_numeral_8.h"
#include "math.h"
#include <iostream>

using namespace std;

Numeral_8::Numeral_8(const Numeral_8 &obj) {
    size = obj.size;
    for (int i = 0; i < size; ++i) {
        vec.push_back( obj.vec[i]);
    }
}

Numeral_8::Numeral_8(vector<int> vector) {
    size = vector.size();
    for (int i = 0; i < size; i++) {
        vec.push_back(vector[i]);
    }
}

Numeral_8::Numeral_8(string line) {
    size = line.length();
    for (int i = 0; i < size; i++) {
        vec.push_back((int(line[i]) - 48));
    }
}


double Numeral_8::to_decimal() {
    double result = 0;
    for (int i = 0; i < size; i++) {
        result += vec[i] * pow(8, (size - i));
    }
    return result;
}


void Numeral_8::operator++() {
    int marker = 0;
    for (int i = size - 1; i >= 0; i--){
        if(i == size-1){
            vec[i] += 1;
        }
        else{
            vec[i] += marker;
        }

        if (vec[i] >= 8) {
            vec[i] %= 8;
            marker = 1;
        } else {
            marker = 0;
        }
        if (i == 0 && marker == 1) {
            vec.insert(vec.begin(), 1);
        }
    }
}

Numeral_8 Numeral_8::operator+(const Numeral_8 &num) {
    int marker = 0;
    vector<int> vect1 = vec;
    vector<int> vect2 = num.vec;
    string result = "";

    if (vect1.size() > vect2.size()) {
        for (int i = 0; i <= vect1.size() - vect2.size(); i++) {
            vect2.insert(vect2.begin(), 0);
        }
    }
    else{
        if (vect1.size() < vect2.size()) {
            for (int i = 0; i <= vect2.size() - vect1.size(); i++) {
                vect1.insert(vect1.begin(), 0);
            }
        }
    }
    marker = 0;
    int current_num = 0;
    for (int i = vect1.size() - 1; i >= 0; i--) {
        current_num += vect1[i] + vect2[i] + marker;
        if (current_num >= 8) {
            current_num %= 8;
            marker = 1;
        } else {
            marker = 0;
        }
        result = to_string(current_num) + result;
        if (i == 0 && marker == 1) {
           result  = '1' + result;
        }
    }
    return Numeral_8(result);
}

void Numeral_8::operator+=(string num){
    Numeral_8 N(num);
    Numeral_8 Add = (*this) + N;

    size = Add.get_size();
    vec = Add.get_vec();
}

void Numeral_8::output(){
    cout <<" your vector\n";
    for(int i = 0; i< size; i++){
        cout << vec[i];
    }
    cout << "\n";
}


