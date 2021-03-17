#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void testCase() {
    int N ;
    vector <ll> ys[3];
    ll xs[3] = {1, 2, 3};

    scanf("%d", &N);
    for(int i=0, x, y; i < N; i++) {
        scanf("%d%d", &x, &y);
        ys[x-1].push_back(y);
    }
    for(int i=0; i < 3; i++)
        sort(ys[i].begin(), ys[i].end());

    ll ans = 0 ;
    for(int k=0; k < 3; k++) {
        for(int i=ys[k].size()-1; i >= 0; i--) {
            for(int j=i-1; j >= 0; j--) {
                ll dx = ys[k][i] - ys[k][j];
                for(int a=0; a < 3; a++)
                    ans += abs(k-a) * dx;
            }
        }
    }

    ans *= 5 ;
    printf("%lld.%lld\n", ans / 10, ans % 10);
}

int main() {
    int pts[3][2] = {{0, 0}, {8, 0}, {0, 3}};
    int ans = 0;

    for(int i=0; i < 3; i++) {
        ans += pts[i][0] * pts[(i+1) % 3][1];
        ans -= pts[i][1] * pts[(i+1) % 3][0];
    }

    printf("%d\n", ans);
}
