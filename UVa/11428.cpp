#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAX_K = 200;

map <int, pii> ans ;

void init() {
    for(int y=MAX_K; y >= 1; y--) {
        for(int x=y; x <= MAX_K; x++) {
            ans[x*x*x - y*y*y] = {x, y};
        }
    }
}

int main() {
    init();
    int N ;
    while(scanf("%d", &N)!=EOF && N) {
        auto it = ans.find(N);
        if(it == ans.end())
            printf("No solution\n");
        else
            printf("%d %d\n", it->second.first, it->second.second);
    }

}
