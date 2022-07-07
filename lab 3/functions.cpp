#include "functions.h"
#include <iostream>
#include <string>
using namespace std;



string input(){
    cout << "Please input your number: \n";
    string n;
    cin >> n;
    while (!validate(n)){
        cout << "Please input normal: \n";
        cin >> n;
    }
    return n;
}

bool validate(string number){
    bool marker = true;
    for(int i = 0; i < number.length(); i++){
        if (number[i] < 48 || number[i] > 55){
            marker = false;
        }
    }
    return marker;
}

void do_all(){
    string line = input();
    vector<int> vect = {1, 1, 2, 4};
    Numeral_8 a(line);
    cout << "vector a";
    a.output();
    Numeral_8 b(vect);
    cout << "vector b";
    b.output();
    Numeral_8 c(b);
    cout << "vector c";
    c.output();

    ++a;
    cout << "vector a incremented";
    a.output();
    cout << "what would you like to add?\n";
    string increment = input();
    b += increment;
    cout << "vector b + your num";
    b.output();
    cout << "vector c (a+b)";
    c = a+b;
    c.output();
    cout << "decimal:  " << c.to_decimal() << endl;

}