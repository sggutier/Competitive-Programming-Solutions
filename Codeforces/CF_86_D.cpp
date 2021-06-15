#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_N = 2e5 + 5;
const int LIM_K = 1e6 + 5;

int N, Q, P ;
ll crg;
int nums[LIM_N];
ll reps[LIM_K];
ll ans[LIM_N];
int ls[LIM_N], rs[LIM_N], ords[LIM_N];

void moveRng(int pos, int tgt, int sm) {
    int dir = pos < tgt? 1 : -1;
    if(dir < 0)
        sm *= -1;
    if(sm < 0) {
        while(pos != tgt) {
            auto &r = reps[nums[pos]];
            crg -= r * r * nums[pos];
            r --;
            crg += r * r * nums[pos];
            pos += dir;
        }
    }
    else {
        while(pos != tgt) {
            pos += dir;
            auto &r = reps[nums[pos]];
            crg -= r * r * nums[pos];
            r ++;
            crg += r * r * nums[pos];
        }
    }
}

int main() {
    scanf("%d%d", &N, &Q);
    P = max(1.0L, sqrtl(N));
    for(int i=1; i <= N; i++) {
        scanf("%d", &nums[i]);
    }
    for(int i=0; i < Q; i++) {
        ords[i] = i;
        scanf("%d%d", &ls[i], &rs[i]);
    }
    sort(ords, ords+Q,
         [](const int x, const int y) {
             const int a = ls[x] / P;
             const int b = ls[y] / P;
             if(a != b)
                 return a < b;
             return rs[x] < rs[y];
         });
    int x=0, y=0, pos;
    for(int i=0; i < Q; i++) {
        pos = ords[i];
        moveRng(y, rs[pos],  1);
        moveRng(x, ls[pos], -1);
        x = ls[pos];
        y = rs[pos];
        ans[pos] = crg;
    }
    for(int i=0; i < Q; i++)
        printf("%lld\n", ans[i]);
}
