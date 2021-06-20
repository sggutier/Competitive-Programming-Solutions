#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int N, sMax, qMax;
    stack <int> cgo;
    queue <int> B[105];
    int rem = 0;

    scanf("%d%d%d", &N, &sMax, &qMax);
    rem = 0;
    for(int i=0; i<N; i++) {
        int K, tmp;
        scanf("%d", &K);
        rem += K;
        while(K--) {
            scanf("%d", &tmp);
            B[i].push(tmp-1);
        }
    }

    int pos = 0, ans = 0;
    while(rem) {
        while(!cgo.empty()) {
            int k = cgo.top();
            if(k!=pos) {
                if((int) B[pos].size() < qMax)
                    B[pos].push(k);
                else
                    break;
            }
            else
                rem --;
            cgo.pop();
            ans ++;
        }
        while((int) cgo.size()<sMax && !B[pos].empty()) {
            cgo.push(B[pos].front());
            B[pos].pop();
            ans ++;
        }
        if(rem)
            ans += 2;
        pos = (pos+1)%N;
    }

    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
