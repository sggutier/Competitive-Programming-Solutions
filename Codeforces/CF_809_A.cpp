#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 3e5 + 5;

int main() {
    int N ;
    int arr[limN];
    ll ans = 0, pot=2, crg=0;

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+N);

    for(int i=1; i<N; i++) {
        ll d = arr[i]-arr[i-1];
        crg = (crg*2 + d*(pot-1))%mod;
        pot = (pot*2)%mod;
        ans = (ans+crg)%mod;
    }

    cout << ans << endl;
}
