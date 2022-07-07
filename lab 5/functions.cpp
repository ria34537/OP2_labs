#include "functions.h"
#include "string"

int input() {
    {
        int n;
        for (;;) {
            cout << "введіть число" << flush;
            if ((cin >> n).good() && n > 1) { return n; }
            else{
                std::cin.clear();
                std::cout << "Невірний ввід.\n";
                std::cin.ignore(100, '\n');
            }
        }
    }
}

void doall(){
    int a = input();
    BinaryTree N(a);
    N.printLevelOrder(N.top, a);
}



