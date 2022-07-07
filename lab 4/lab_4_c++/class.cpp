//
// Created by ria4232 on 17.06.22.
//

#include "class.h"
string Linear::solve(int &r) {
    if (b ==0){
        return "dont have roots";;
    }
    int m = (y - a)/b;
    r += m;
    return "x = " + to_string(m);
}
string Linear::check(int x){
    if (a + b*x ==y){
        return "x is root";
    }
    return "not root";
}
string Linear::equation(){
    return to_string(a) + " + (" + to_string(b) + ")*x = " + to_string(y);
}

string Squared::solve(int &r) {
    if (c==0 && b ==0){
        return "dont have roots";
    }
    if (c == 0){
        r += ((y-a)/b);
        return "x = " + to_string((y-a)/b);
    }

    int disk = b * b - 4 * a * c;
    if (disk < 0){
        return "dont have roots";
    }
    int x1 = (-1 * b - sqrt(disk)) / (2 * a);
    int x2 = (-1 * b + sqrt(disk)) / (2 * a);
    int m = x1 + x1;
    r += x1 + x2;
    return "x1 = " + to_string(x1) + " x2 = "+ to_string(x2) + "  sum = " + to_string(m);
}
string Squared::check(int x){
    if (a + b*x +c*x*x ==y){
        return "x is root";
    }
    return "not root";
}
string Squared::equation(){
    return to_string(a) + " + (" + to_string(b) + ")*x +(" + to_string(c) + ")*x^2 = "+ to_string(y);
}