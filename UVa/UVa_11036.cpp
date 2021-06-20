#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM_N = 11e6 + 5;

ll mod ;

struct Mod {
    ll x;
    Mod(ll xx = 0) : x(xx) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
};

Mod opr(vector <int> &nms, vector <char> &strs, Mod x) {
    int N = nms.size();
    stack <Mod> S;
    Mod p ;
    for(int i=0; i < N; i++) {
        switch(strs[i]) {
        case ' ':
            S.push(nms[i]);
            break;
        case '+':
            p = S.top(); S.pop();
            p = p + S.top(); S.pop();
            S.push(p);
            break;
        case '*':
            p = S.top(); S.pop();
            p = p * S.top(); S.pop();
            S.push(p);
            break;
        default:
            S.push(x);
        }
    }
    return S.top();
}

int T = 1 ;
int lapr[LIM_N];

void testCase(Mod x) {
    vector <int> nms;
    vector <char> strs;
    char tmp[105];
    int tIni = T ;
    while(true) {
        scanf("%s", tmp);
        if(tmp[0] == '%') break;
        if(isdigit(tmp[0])) {
            strs.push_back(' ');
            nms.push_back(atoi(tmp));
        }
        else if(tmp[0] != 'N') {
            strs.push_back(tmp[0]);
            nms.push_back(-1);
        }
    }
    do {
        lapr[x.x] = T++;
        x = opr(nms, strs, x);
    } while(lapr[x.x] < tIni) ;
    printf("%d\n", T - lapr[x.x]);
}

int main() {
    ll k ;
    while(scanf("%lld%lld", &mod, &k) && mod)
        testCase(k);
}
