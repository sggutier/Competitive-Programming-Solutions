#include <bits/stdc++.h>
using namespace std;
#define par pair<long long, long long>
#define x first
#define y second
const long long inf = ((1LL<<62)-1)*2;

int main() {
    int gemCnt;
    vector<par> gems;
    vector<long long> maxLIS;
    int R, width, height;

    scanf("%d%d%d%d", &gemCnt, &R, &width, &height);
    gems = vector<par>(gemCnt);
    maxLIS = vector<long long>(gemCnt+1);
    for(int i=0; i<gemCnt; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        gems[i] = par(a, b);
        gems[i] = par(gems[i].x*R + gems[i].y, - gems[i].x*R + gems[i].y);
        maxLIS[i+1] = inf;
    }

    sort(gems.begin(), gems.end());
    maxLIS[0] = -inf;
    for(int i=0; i<gemCnt; i++) {
        int ini, fin;
        ini = 0;
        fin = gemCnt;
        while(ini<fin) {
            int piv = (ini+fin)/2 ;
            if(maxLIS[piv] <= gems[i].y)
                ini = piv+1;
            else
                fin = piv;
        }
        maxLIS[ini] = gems[i].y;
    }

    for(int i=gemCnt; i>=0; i--) {
        if(maxLIS[i]!=inf) {
            printf("%d\n", i);
            break;
        }
    }
    
    return 0;
}
