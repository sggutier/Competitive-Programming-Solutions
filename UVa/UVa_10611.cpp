#include <bits/stdc++.h>
using namespace std;

int main() {
    int ladyCnt;
    int ladies[50005];
    int querCnt;

    scanf("%d", &ladyCnt);
    for(int i=0; i<ladyCnt; i++)
        scanf("%d", &ladies[i]);
    scanf("%d", &querCnt);

    while(querCnt--) {
        int n, pos;
        scanf("%d", &n);
        pos = (lower_bound(ladies, ladies+ladyCnt, n) - ladies) - 1;
        if(pos>=0)
            printf("%d", ladies[pos]);
        else
            printf("X");
        pos = (upper_bound(ladies, ladies+ladyCnt, n) - ladies);
        if(pos<ladyCnt)
            printf(" %d\n", ladies[pos]);
        else
            printf(" X\n");
    }
}
