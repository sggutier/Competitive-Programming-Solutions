#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int p, y ;

bool funca(int n) {
    for(int i=2; i*i<=n && i<=p; i++) {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main() {

    scanf("%d%d", &p, &y);

    for(int n=y; n>p; n--) {
        if(funca(n)) {
            printf("%d\n", n);
            return 0;
        }
    }

    printf("-1\n");
}
