/*
ID: me60
LANG: C++11
TASK: ride
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string A, B;
    cin >> A >> B;
    int sumA = 1, sumB = 1;
    for(int i=0; i<(int) A.size(); i++)
        sumA = (sumA * (A[i] - 'A'+1)) % 47;
    for(int i=0; i<(int) B.size(); i++)
        sumB = (sumB * (B[i] - 'A'+1)) % 47;
    cout << (sumA==sumB? "GO" : "STAY") << endl;
    return 0;
}
