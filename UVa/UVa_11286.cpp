#include <bits/stdc++.h>
using namespace std;

void test_case(int n) {
    map <string, int> combs;
    int most_pop_cnt = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        string tmp[5];
        string stu ;
        for(int j=0; j<5; j++) {
            char aaa[5];
            scanf("%s", aaa);
            tmp[j] = aaa;
        }
        sort(tmp, tmp+5);
        for(int j=0; j<5; j++)
            stu += tmp[j];
        most_pop_cnt = max(most_pop_cnt, ++combs[stu]);
    }
    for ( const auto &comb : combs ) {
        if(comb.second==most_pop_cnt)
            ans += comb.second;
    }
    printf("%d\n", ans);
}

int main() {
    int n;

    while(scanf("%d",&n)!=EOF && n!=0)
        test_case(n);
    
    return 0;
}
