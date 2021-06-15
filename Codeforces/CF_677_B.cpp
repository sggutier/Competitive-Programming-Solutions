#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int tech(int a, int b) {
    return a/b + (a%b? 1 : 0);
}

int main() {
    long long ans = 0;
    int n, h, k;
    int arr[limN];
    int crg = 0;

    scanf("%d%d%d", &n, &h, &k);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    arr[n] = 0;

    for(int i=0; i<n; i++) {
        crg += arr[i];
        //printf("%d => %d\n", arr[i+1], crg);
        if(crg + arr[i+1] <= h)
            continue;
        int t = tech(crg + arr[i+1] - h, k) ;
        //printf("T es %d\n", t);
        crg = max(0, crg-t*k);
        ans += t;
    }
    ans += tech(crg, k) ;

    cout << ans << endl;
}
