#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second
const int limN = 2e5 + 5;

int N ;
int minP[limN], maxP[limN];
int psh[limN], qt[limN];
int nums[limN] ;
stack <int> S ;

int main() {
    int Q ;
    int zcnt = 0 ;
    bool hasQ = false;
    
    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        if(nums[i] == Q)
            hasQ = true; 
        if(nums[i] % Q == 0)
            zcnt ++;
    }

    if(zcnt == 0) {
        printf("NO\n");
        return 0 ;
    }

    for(int i=1; i<=Q; i++)
        minP[i] = N+1, maxP[i] = -1;

    for(int i=0; i<N; i++) {
        minP[nums[i]] = min(minP[nums[i]], i);
        maxP[nums[i]] = max(maxP[nums[i]], i);
    }
    for(int i=2; i<=Q; i++) {
        if(minP[i] == N+1)
            continue; 
        psh[minP[i]] = i;
        qt[maxP[i] + 1] = i;
        // printf("%d => %d %d\n", i, minP[i], maxP[i] + 1);
    }

    S.push(1);
    for(int i=0; i<N; i++) {
        if(qt[i])
            S.pop();
        if(nums[i] != 0 && nums[i] < S.top()) {
            printf("NO\n");
            return 0 ;
        }
        if(psh[i])
            S.push(psh[i]);
        if(nums[i] == 0) {
            nums[i] = hasQ? S.top() : Q ;
            hasQ = true;
        }        
    }

    printf("YES\n");
    for(int i=0; i<N; i++)
        printf("%d ", nums[i]);
    printf("\n");
}
