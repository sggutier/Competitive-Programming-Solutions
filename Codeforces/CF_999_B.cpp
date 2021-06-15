#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    string S;
    cin >> N >> S;
    for(int i=1; i<=N; i++) {
        if(N % i) continue;
        reverse(S.begin(), S.begin() + i);
    }
    cout << S << endl;
}
