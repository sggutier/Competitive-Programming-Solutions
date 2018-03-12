#include <bits/stdc++.h>
using namespace std;

void testCase(int tc) {
    int N;
    int sum=0, ini=-1, fin=0;
    pair <int, pair<int,int>> ans ;
    scanf("%d", &N);
    N--;
    for(int i=0; i<N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if(sum+tmp<0) {
            sum = 0;
            ini = i;
        }
        else {
            sum += tmp;
            fin = i;
            if(sum>ans.first)
                ans = make_pair(sum, make_pair(ini, fin));
            else if(sum==ans.first && fin-ini>ans.second.second-ans.second.first)
                ans.second = make_pair(ini, fin);
        }
    }
    if(ans.first==0)
        printf("Route %d has no nice parts\n", tc);
    else
        printf("The nicest part of route %d is between stops %d and %d\n", tc, ans.second.first+2, ans.second.second+2);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        testCase(i);
    }
    
    return 0;
}
