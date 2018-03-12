#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

int N ;
char str[limN];
int cnt[300];

int main() {
    pair <int, pair<int, int>> ans;
    
    scanf("%d", &N);
    scanf("%s", str);

    for(int i=0, j=0, dt=0; j<N; j++) {
        if(!cnt[(int) str[j]]++)
            dt ++;
        while(i < j && cnt[(int) str[i]] > 1) {
            cnt[(int) str[i]] --;
            i++;
        }
        // printf("%d %d => %d\n", i, j, dt);
        ans = max(ans, {dt, {i-j, i}});
    }

    // printf("%d\n", ans.first);
    // printf("%d %d\n", ans.second.second, ans.second.first);
    // printf("%d %d\n", ans.second.second+1, ans.second.second - ans.second.first +1);
    printf("%d\n", -ans.second.first+1);
}
