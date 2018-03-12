/*
ID: me60
LANG: C++11
TASK: milk
*/
#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    int priceNum, reqMilk;
    par prices[10000];
    long long ans = 0;

    scanf("%d%d", &reqMilk, &priceNum);
    for(int i=0; i<priceNum; i++) 
        scanf("%d%d", &prices[i].f, &prices[i].second);

    sort(prices, prices+priceNum);
    for(int i=0; i<priceNum; i++) {
        long long buy = min(reqMilk, prices[i].second);
        ans += buy*prices[i].f;
        reqMilk -= buy;
    }

    printf("%lld\n", ans);

    return 0;
}
