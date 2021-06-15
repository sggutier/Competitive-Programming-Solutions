#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;
typedef long long ll;

ll crg[limN];

int main() {
    int N, Q;
    int arr[limN];
    ll ans = 0;

    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<Q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        crg[a-1]++;
        crg[b]--;
    }

    for(int i=0, s=0; i<N; i++) {
        s += crg[i];
        crg[i] = s;
    }
    sort(crg, crg+N);
    sort(arr, arr+N);

    for(int i=0; i<N; i++)
        ans += arr[i]*crg[i];

    cout << ans << endl;
}
