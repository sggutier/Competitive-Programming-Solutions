#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM = 10;
const int dx[] = {0, 1};
const int dy[] = {1, 0};

int cnt[LIM + 5][LIM + 5];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int N ;

    cin >> N ;
    for(int i=0, x, y, d, l; i < N; i++) {
        cin >> d >> l >> x >> y ;
        x --, y--;
        for(int j=0; j < l; j++) {
            int r = x + dx[d] * j;
            int c = y + dy[d] * j;
            if(r < 0 || r >= LIM || c < 0 || c >= LIM || cnt[r][c]) {
                cout << "N" << endl;
                return 0 ;
            }
            cnt[r][c] ++;
        }
    }

    cout << "Y" << endl;
    return 0 ;
}
