#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int cnt(int a, int b) {
    if(b < a)
        swap(a, b);
    return a + ((b-a) / 2) ;
}

void testCase() {
    int N ;
    int x1, x2;
    int w, b ;
    cin >> N >> x1 >> x2 ;
    cin >> w >> b ;
    cout << (cnt(x1, x2) >= w && cnt(N-x1, N-x2) >= b? "YES" : "NO") << endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int tc ;
    cin >> tc;
    while(tc--)
        testCase();
}
