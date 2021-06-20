#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define px first.first
#define py first.second
#define val second
#define tri pair<par, int>
#define mp make_pair
const int limN = 1e3 + 5;

int D, D2;

inline int calcX(const int &b) {
    return max(0, b-D2);
    // return b-D;
}

void testCase() {
    pair<int, par> ans ;
    int ratCnt;
    scanf("%d%d", &D, &ratCnt);
    D2 = D;
    D *= 2;
    vector <tri> rats(ratCnt);
    for(int i=0; i<ratCnt; i++) {
        scanf("%d%d%d", &rats[i].px, &rats[i].py, &rats[i].val);
        // yes.insert(rats[i].py);
    }
    
    sort(rats.begin(), rats.end());
    // int ans = 0;
    // for(const int &y:yes) {
    for(int y=limN-D2; y>=-D2; y--) {
        queue <par> Q;
        for(int i=0, sum=0; i<ratCnt; i++) {
            if(rats[i].py < y || rats[i].py > y+D)
                continue;
            sum += rats[i].val;
            Q.push(mp(rats[i].px, rats[i].val));
            while(rats[i].px - Q.front().first > D) {
                sum -= Q.front().second;
                Q.pop();
            }
            ans = max(ans, mp(sum, mp(-calcX(rats[i].px), -(y + D2))));
        }
    }
    printf("%d %d %d\n", -ans.second.first, -ans.second.second, ans.first);
}


int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
