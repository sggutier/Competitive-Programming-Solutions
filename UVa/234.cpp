#include <bits/stdc++.h>
using namespace std;

struct aro {
    int arr[5];
    aro() {
        for(int i=0; i<5; i++)
            arr[i] = 0;
    }
    bool operator<(const aro &otr) const {
        for(int i=0; i<5; i++) {
            if(arr[i]!=otr.arr[i])
                return arr[i] < otr.arr[i];
        }
        return false;
    }
};

void testCase(int progCnt) {
    int progs[progCnt], goodPerm[progCnt];
    int pointCnt;
    int times[15], imps[15];
    aro ans, bo;
    ans.arr[0] = (1<<30);
    
    for(int i=0; i<progCnt; i++)
        scanf("%d", &progs[i]);
    sort(progs, progs+progCnt);
    scanf("%d", &pointCnt);
    for(int i=0; i<pointCnt; i++) {
        scanf("%d%d", &imps[i], &times[i]);
        imps[i] -- ;
    }

    do {
        aro tmp ;
        for(int i=1; i<progCnt; i++)
            progs[i] += progs[i-1];
        for(int i=0; i<pointCnt; i++) {
            int lt = (1<<30);
            for(int j=0; j<progCnt; j++)
                lt = min(lt, abs(progs[j] - times[i]));
            tmp.arr[imps[i]] += lt;
        }
        for(int i=progCnt-1; i; i--)
            progs[i] -= progs[i-1];
        if(tmp < ans) {
            for(int i=0; i<progCnt; i++)
                goodPerm[i] = progs[i];
            ans = tmp;
        }
        
    } while(next_permutation(progs, progs+progCnt));

    printf("Order:");
    for(int i=0; i<progCnt; i++)
        printf(" %d", goodPerm[i]);
    printf("\n");
    int tmp = 0;
    for(int i=0; i<5; i++)
        tmp += ans.arr[i];
    printf("Error: %d\n", tmp);
}

int main() {
    int tc = 0;
    int n;

    while(scanf("%d", &n)!=EOF && n) {
        printf("Data set %d\n", ++tc);
        testCase(n);
    }
    
    return 0;
}
