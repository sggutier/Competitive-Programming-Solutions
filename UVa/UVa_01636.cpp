#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 105;

void testCase(string &s) {
    int N = s.size();
    int uno=0, zerS=0, zer=0;
    for(int i=0; i < N; i++) {
        if(s[i]=='1') {
            uno ++;
        }
        else
            zerS += s[(i+1)%N]=='0'? 1 : 0;
    }
    zer = N - uno;
    int x = zer*zer, y = zerS*N;
    if(x==y)
        puts("EQUAL");
    else
        puts(x > y? "ROTATE" : "SHOOT" );
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string S ;
    while(cin >> S) {
        testCase(S);
    }
}
