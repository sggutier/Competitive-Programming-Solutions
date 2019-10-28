#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

int crg[limN];

void mete(int pos, const int nov=1) {
    for(; pos<limN; pos+= pos & -pos)
        crg[pos] += nov;
}

int saca(int pos) {
    int ans = 0;
    for(; pos; pos -= pos&-pos)
        ans += crg[pos];
    return ans;
}

int N;
int nums[limN];
map<int, int> izq, der;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        der[nums[i]]++;
    }

    for(const auto &p : der) {
        for(int i=p.second; i; i--)
            mete(i);
    }

    long long ans = 0;
    for(int i=0; i<N; i++) {
        int v = --der[nums[i]];
        mete(v+1, -1);
        v = ++izq[nums[i]];
        ans += saca(v-1);
    }

    printf("%lld\n", ans);
}
