#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

int N, M ;
long long arr[limN];
int modCont[limN];
vector <int> poss[limN];

int main() {
    int K ;
    long long ans = 0;
    scanf("%d%d", &N, &M);
    K = N/M;
    for(int i=0; i<N; i++) {
        scanf("%lld", &arr[i]);
        poss[arr[i]%M].push_back(i);
    }
    for(int i=0; i<M; i++) {
        modCont[i] = poss[i].size();
    }
    for(int i=0, j=0; i<M; i++) {
        if(modCont[i] <= K) continue;
        j = max(j, i);
        for(int w=K; w<modCont[i]; w++) {
            while(modCont[j%M] >= K)
                j++;
            modCont[j%M]++;
            ans += (j-i)%M;
            arr[poss[i][w]] += (j-i)%M;
        }
        modCont[i] = K;
    }
    printf("%lld\n", ans);
    for(int i=0; i<N; i++)
        printf("%lld ", arr[i]);
    printf("\n");
}
