#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;

    cin >> N ;
    cout << (N%2? 0  :  N/4 - (N%4==0? 1 : 0)) << endl;
}
