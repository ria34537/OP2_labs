//
// Created by ria4232 on 17.06.22.
//

#include "funcs.h"
vector <Squared> squared(int n){
    int sum;
    vector <Squared> vect;
    for (int i = 0; i < n; ++i) {
        Squared a = Squared(rand()%100 - 100, rand()%100 - 100,rand()%100 - 100,rand()%100 - 100);
        vect.push_back(a);
        a.solve(sum);
    }

    return vect;
}
vector <Linear> linear(int n){
    int sum;
    vector <Linear> vect;
    for (int i = 0; i < n; ++i) {
        Linear a = Linear(rand()%100 - 100, rand()%100 - 100,rand()%100 - 100);
        vect.push_back(a);
        a.solve(sum);
    }
    return vect;
}

void print_all(vector <Linear> lin, vector <Squared> squar){
    int sum_l = 0;
    int sum_s = 0;
    for(int i = 0; i < lin.size(); i ++){
        cout << "l"+to_string(i) << endl;
        cout << lin[i].equation() << endl;
        cout << lin[i].solve(sum_l) << endl;
    }
    cout << "sum of linear roots is : " << sum_l << endl;
    for(int i = 0; i < squar.size(); i ++){
        cout << "s" + to_string(i) << endl;
        cout << squar[i].equation() << endl;
        cout << squar[i].solve(sum_s)<<endl;

    }
    cout << "sum of squared roots is : " << sum_s << endl;

}

void do_all(){
    int m,n;
    cout << "plese, input n: ";
    cin >> n;
    cout << "plese, input m: ";
    cin >> m;

    vector<Linear> line = linear(n);
    vector<Squared> square = squared(m);

    print_all(line, square);
    cout << "please, input code of equation: ";
    string code;
    cin >> code;

    if (code[0] =='s'){
        int x;
        cout << "plese, input x: ";
        cin >> x;
        cout << square[(int) code[1]- 48].equation() << endl;
        cout << square[(int) code[1]- 48].check(x)<<endl;
    }
    else{
        int x;
        cout << "plese, input x: ";
        cin >> x;
        cout << line[(int) code[1]- 48].equation() << endl;
        cout << line[(int) code[1]- 48].check(x)<<endl;
    }
}