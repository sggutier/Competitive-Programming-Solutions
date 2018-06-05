#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

int main() {
    int A, B, X[limN], Y[limN];
    int ans = 0;
    cin >> A ;
    for(int i=0; i<A; i++)
        cin >> X[i];
    cin >> B ;
    for(int i=0; i<B; i++)
        cin >> Y[i];
    sort(X, X+A);
    sort(Y, Y+B);
    for(int i=0, j=0; i<A && j<B; ) {
        if(abs(X[i] - Y[j]) <= 1) {
            i++, j++;
            ans ++;
        }
        else if(X[i] < Y[j])
            i++;
        else
            j++;
    }

    printf("%d\n", ans);
}
