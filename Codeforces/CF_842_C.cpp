#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;
typedef pair<int,int> pii;
#define f first
#define s second


int nums[limN];
int maxo[limN];
vector <int> adj[limN];
set <int> usd[2][limN];

    
void marca(int pos = 0, int st = 0, int crg = 0, int pv = -1) {
    if(usd[st][pos].count(crg))
        return ;
    usd[st][pos].insert(crg);
    maxo[pos] = max(maxo[pos], __gcd(crg, nums[pos]) );
    if(!st)
        maxo[pos] = max(maxo[pos], crg);
    if(!st) {
        for(const int sig : adj[pos])
            if(sig != pv) {
                marca(sig, 1, crg, pos);
            }
    }
    for(const int sig : adj[pos])
        if(sig != pv) {
            marca(sig, st, __gcd(nums[pos], crg), pos);
        }
}

int main() {
    
    int N ;
    scanf("%d", &N);
    for(int i=0; i<N; i++) 
        scanf("%d", &nums[i]);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    marca();
    for(int i=0; i<N; i++)
        printf("%d ", maxo[i]);
    printf("\n");
}
