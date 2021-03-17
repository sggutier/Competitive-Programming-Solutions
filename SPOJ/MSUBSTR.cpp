#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void manacher(const string& s) {
    int n = sz(s);
    vi p[2] = {vi(n+1), vi(n)};
    rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
        int t = r-i+!z;
        if (i<r) p[z][i] = min(t, p[z][l+t]);
        int L = i-p[z][i], R = i+p[z][i]-!z;
        while (L>=1 && R+1<n && s[L-1] == s[R+1])
            p[z][i]++, L--, R++;
        if (R>r) l=L, r=R;
    }
    int ans = -1 ;
    int ansCnt = 0 ;
    for(int j=0; j < 2; j++) {
        for(int i=0; i < n; i++) {
            int k = 2*p[j][i] + j ;
            if(k > ans) {
                ans = k ;
                ansCnt = 0 ;
            }
            if(k == ans)
                ansCnt ++;
        }
    }
    printf("%d %d\n", ans, ansCnt);
}

string S ;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int N ;
    cin >> N ;
    for(int i=0; i < N; i++) {
        cin >> S ;
        manacher(S);
    }

}
