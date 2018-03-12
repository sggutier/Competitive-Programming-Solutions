/*
ID: me60
LANG: C++11
TASK: skidesign
*/
#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second

int calcCost(vector<int> hills, int minHeight) {
    int maxHeight = minHeight + 17;
    int ans = 0;
    for(int i=0; i<(int) hills.size(); i++) {
        if(hills[i]<minHeight)
            ans += (int) pow(minHeight-hills[i], 2);
        else if(hills[i]>maxHeight)
            ans += (int) pow(maxHeight-hills[i], 2);
    }
    return ans;
}

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    int n;
    vector<int> hills;
    int ans = (1<<30);

    scanf("%d", &n);
    hills = vector<int>(n);
    for(int i=0; i<n; i++)
        scanf("%d", &hills[i]);

    for(int i=-17; i<=100; i++) {
        ans = min(ans, calcCost(hills, i));
    }

    printf("%d\n", ans);

    return 0;
}
