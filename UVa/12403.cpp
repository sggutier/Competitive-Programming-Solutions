#include <bits/stdc++.h>
using namespace std;

int main() {
    int queryCnt;
    char S[100];
    int sum = 0;

    scanf("%d", &queryCnt);
    for(int i=0; i<queryCnt; i++) {
        scanf("%s", S);
        if(S[0]=='d') {
            int tmp ;
            scanf("%d", &tmp);
            sum += tmp;
        }
        else
            printf("%d\n", sum);
    }
    
    return 0;
}
