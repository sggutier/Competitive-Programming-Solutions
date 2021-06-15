#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int ans = 0;
    set <int> usd;
    int N ;
    int a ;

    cin >> N ;
    for(int i=0; i<N; i++) {
        cin >> a ;
        if(a==0 || usd.count(a))
            continue;
        ans ++;
        usd.insert(a);
    }

    cout << ans << endl;
}
