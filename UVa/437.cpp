#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define tri pair<par, int>
#define f first
#define s second

void testCase(int N) {
    tri blqs[N*6];
    for(int i=0; i<N; i++) {
        int arr[3];
        for(int j=0; j<3; j++)
            scanf("%d", &arr[j]);
        sort(arr, arr+3);
        for(int j=0; j<6; j++) {
            blqs[i*6 + j] = tri(par(arr[0], arr[1]), arr[2]);
            next_permutation(arr, arr+3);
        }
    }
    N *= 6;
    int ans[N] ;
    int ansVal = 0;
    sort(blqs, blqs+N);
    reverse(blqs, blqs+N);
    for(int i=0; i<N; i++) {
        int tmpo = 0;
        for(int j=0; j<i; j++) {
            if(blqs[i].f.f < blqs[j].f.f && blqs[i].f.s < blqs[j].f.s)
                tmpo = max(tmpo, ans[j]);
        }
        tmpo += blqs[i].s;
        ansVal = max(ansVal, tmpo);
        ans[i] = tmpo;        
    }
    printf("maximum height = %d\n", ansVal);
}

int main() {
    int tc = 1;
    int tmp;

    while(scanf("%d", &tmp)!=EOF && tmp) {
        printf("Case %d: ", tc++);
        testCase(tmp);
    }
    
    return 0;
}
