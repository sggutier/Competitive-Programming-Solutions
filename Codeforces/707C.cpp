#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n ;
    cin >> n ;
    if(n==1 || n==2) {
        cout << -1 << endl;
    }
    else if(n%2==0) {
        cout << (n*n)/4 - 1 << " " << (n*n)/4 + 1 << endl;
    }
    else {
        cout << (n*n-1)/2 << " " << (n*n+1)/2 << endl;
    }
}
