#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 50;

int main() {
    int N, K ;
    ll cnts[limN];
    ll sumo[limN];
    //ll ans = 0;

    cin >> N >> K ;
    for(int i=0; i<N; i++)
        cin >> cnts[i];
    for(int i=N; i<=30; i++)
        cnts[i] = 2*cnts[i-1];
    N = 30;
    for(int w=0; w<=N; w++) {
        for(int i=N-1; i>=0; i--)
            cnts[i] = min(cnts[i], cnts[i+1]);
        for(int i=1; i<=N; i++)
            cnts[i] = min(cnts[i], 2*cnts[i-1]);
    }
    for(int i=0; i<=N; i++) {
        sumo[i] = i? sumo[i-1] : 0;
        if((1<<i) & K) {
            sumo[i] += cnts[i];
        }
        else {
            sumo[i] = min(sumo[i], cnts[i]);
        }
    }
    // for(int i=N; i>=0; i--) {
    //     if((1<<i) & K) {
    //         ans = min(ans, cnts[i+1]);
    //         break;
    //     }
    // }
    // for(int i=0; i<N; i++)
    //     cout << cnts[i] << " " ;
    // cout << endl;
    // for(int i=0; i<N; i++)
    //     cout << sumo[i] << " " ;
    // cout << endl;
    cout << sumo[N] << endl;
}
