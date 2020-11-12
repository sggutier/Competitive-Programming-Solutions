#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD_A = 1e9 + 7 ;
const ll MOD_B = 1e8 + 7 ;

struct Mint {
    ll x, y;
    Mint(ll a) {
        this->x = this->y = a;
    }
    Mint(ll x, ll y) {
        this->x = x % MOD_A;
        this->y = y % MOD_B;
    }
    Mint operator+( Mint otr ) {
        return Mint(
            this->x + otr.x,
            this->y + otr.y
        );
    }
    Mint operator-( Mint otr ) {
        return Mint(
            this->x - otr.x + MOD_A,
            this->y - otr.y + MOD_B
        );
    }
    Mint operator*( Mint otr ) {
        return Mint(
            this->x * otr.x,
            this->y * otr.y
        );
    }
    bool operator<(const Mint otr) const {
        if(this->x != otr.x) {
            return this->x < otr.x;
        }
        return this->y < otr.y ;
    }
};

set <Mint> usd;

int main() {
    string cad;
    string buenas;
    vector <int> cpy;
    int k ;
    int N ;

    cin >> cad >> buenas >> k;

    N = cad.size();
    for(int i=0; i < N; i++) {
        cpy.push_back(cad[i] - 'a');
    }
    for(int i = 0; i < (int) buenas.size(); i++) {
        buenas[i] -= '0';
    }

    for(int i=0; i < N; i++) {
        int malaCnt = 0;
        Mint crg = 0;
        for(int j=i; j < N; j++) {
            if(!buenas[cpy[j]]) {
                malaCnt ++;
            }
            crg = crg * 27 + (cpy[j] + 1);
            if(malaCnt > k) {
                break;
            }
            usd.insert(crg);
        }
    }

    printf("%d\n", (int) usd.size());
}
