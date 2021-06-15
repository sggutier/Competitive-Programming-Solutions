#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

bool itWorks(const int N, const int w, const int minH, const int *arr, int rem) {
    static int delo[limN];
    for(int i=0, crg=0; i<N; i++) {
        if(i - w >=0 )
            crg -= delo[i-w];
        int f = max(0, minH - (arr[i]+crg));
        if(rem < f)
            return false;
        rem -= f;
        crg += f;
        delo[i] = f;
    }
    return true;
}

int main() {
    int N, w, m;
    int arr[limN];
    int ini, fin;

    scanf("%d%d%d", &N, &m, &w);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);

    for(ini=0, fin=1e9 + m; ini<fin; ) {
        int piv = (ini+fin)/2 +1;
        if(itWorks(N, w, piv, arr, m))
            ini = piv;
        else
            fin = piv-1;
    }

    printf("%d\n", ini);
}
