#ifndef LAB_4_C___CLASS_H
#define LAB_4_C___CLASS_H
#endif //LAB_4_C___CLASS_H
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class TEquation
{
public:
    virtual string solve(int &r) = 0;
    virtual string check(int x) = 0 ;
    virtual string equation() = 0;
};
class Linear : public TEquation
{
private:
    int a;
    int b;
    int y;
public:
    Linear(int ca, int cb, int cy){
        a = ca;
        b = cb;
        y = cy;
    }

    string solve(int &r)override;
    string check(int x)override;
    string equation() override;
};
class Squared : public TEquation
{
private:
    int a;
    int b;
    int c;
    int y;
public:
    Squared(int ca, int cb, int cc, int cy){
        a = ca;
        b = cb;
        c = cc;
        y = cy;

    }

    string solve(int &r) override;
    string check(int x)override;
    string equation() override;
};