#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int pos0, posN;
    int N ;
    int ans = 1e9;

    cin >> N ;
    for(int i=0; i<N; i++) {
        int a ;
        cin >> a;
        if(a==1)
            pos0 = i;
        else if(a==N)
            posN = i;
    }

    ans = abs(pos0-posN);
    for(int w=0; w<=N-1; w+=N-1) {
        if(posN!=w)
            ans = max(ans, abs(w-posN));
        if(pos0!=w)
            ans = max(ans, abs(w-pos0));
    }

    cout << ans << endl;
}
