#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int limB = 60;

int N ;
int nums[limN];
int depo[limN];
vector <int> bits[limN];
int ans = 1e9;

void dfs(const int pos, const int prev=-1, const int d=1) {
    if(depo[pos]) {
        ans = min(ans, d-depo[pos]);
        return;
    }
    const int &a = nums[pos];
    for(int i=0; i<60; i++) {
        if((1<<i) & a)
            }
}

int main() {
    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        for(int j=0; j<N; j++) {
            if(((1<<j) & a) == 0)
                continue;
            cnts[j] ++;
            for(int k=0; k<N; k++) {
                if(((1<<k) & a) == 0)
                    continue;
                adj[j][k] ++;
            }
        }
    }
}
