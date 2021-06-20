#include <bits/stdc++.h>
using namespace std;

void testCase(int courseCnt) {
    int queryCnt;
    set <int> taken;
    bool ans = true ;
    scanf("%d", &queryCnt);
    for(int i=0; i<courseCnt; i++) {
        int tmp;
        scanf("%d", &tmp);
        taken.insert(tmp);
    }
    for(; queryCnt; queryCnt--) {
        int a, b, tmp;
        scanf("%d%d", &a, &b);
        for(int i=0; i<a; i++) {
            scanf("%d", &tmp);
            if(taken.count(tmp))
                b-- ;
        }
        ans &= (b<=0);
    }

    printf("%s\n", ans? "yes" : "no");
}

int main() {
    int a;

    while(scanf("%d", &a)!=EOF && a)
        testCase(a);
    
    return 0;
}
