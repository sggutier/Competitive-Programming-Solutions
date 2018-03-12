#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int x;

int divo(int n) {
    return n/x ;
}

int calca(int N, int *arr, int k, int w) {
    int pa, pb;
    int ini=0, fin=N-1;
    if(arr[w]%x==0) {
        k--;
        if(k<0)
            return 0;
    }
    int d = divo(arr[w]);
    while(ini < fin) {
        int piv = (ini+fin)/2 + 1;
        if(arr[piv] < arr[w] || divo(arr[piv]) - d <= k)
            ini = piv;
        else
            fin = piv-1;
    }
    if(divo(arr[ini])-d != k)
        return 0;
    pb = ini;
    ini=0, fin=N-1;
    while(ini < fin) {
        int piv = (ini+fin)/2 ;
        if(arr[piv] < arr[w] || divo(arr[piv]) - d < k)
            ini = piv + 1;
        else
            fin = piv;
    }
    pa = ini;
    return pb-pa+1;
}

int main() {
    int N, K;
    int arr[limN];
    long long ans = 0;

    scanf("%d%d%d", &N, &x, &K);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+N);

    for(int i=0; i<N; i++)
        ans += calca(N, arr, K, i);

    printf("%lld\n", ans);
}
