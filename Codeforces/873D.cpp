#include <bits/stdc++.h>
using namespace std;
//const int limN = 1003;
const int limN = 100005;

bool usd[limN];
set <int> avil[limN];

void calca(int N) {
    if(usd[N])
        return ;
    usd[N] = true;
    avil[N].insert(0);
    int x = N/2, y = N-x;
    for(const int &p:avil[x])
        for(const int &q:avil[y])
            avil[N].insert(p+q+2);
}

void flipa(int N, int *arr, int k) {
    static int cpy[limN];
    for(int i=0; i<N; i++)
        cpy[i] = arr[i];
    for(int i=0; i<N; i++)
        arr[i] = cpy[(i+k)%N];
}

void merga(int N, int *arr, int k) {
    if(k==0)
        return;
    int x = N/2;
    flipa(N, arr, N-x);
    k -= 2;
    merga(x, arr, min(x*2 - 2, k));
    merga(N-x, arr+x, k - min(x*2 - 2, k));
}

int main() {
    int N, K ;
    int arr[limN];
    scanf("%d%d", &N, &K);
    if(K%2==0 || K>=2*N) {
        printf("-1\n");
        return 0;
    }
    for(int i=0; i<N; i++)
        arr[i] = i+1;
    merga(N, arr, K-1);
    for(int i=0; i<N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
    cin >> N ;
    for(int i=1; i<=N; i++) {
        calca(i);
        printf("%d [%d] =>", i, (int) avil[i].size());
        for(const int &a:avil[i])
            printf(" %d", a);
        printf("\n");
    }
}
