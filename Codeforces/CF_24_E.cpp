#include <bits/stdc++.h>
using namespace std;

struct Frac {
    __int128 num, den;
    Frac(const __int128 a, const __int128 b = 1) : num(a), den(b) {
        // if(den < 0) {
        //     num *= -1 ;
        //     den *= -1;
        // }
        // auto g = __gcd(num < 0? - num : num, den < 0? - den : den);
        // num /= g ;
        // den /= g;
    }
};

bool operator==(const Frac &a, const Frac &b) {
    return a.num * b.den == b.num * a.den;
}

bool operator<(const Frac &a, const Frac &b) {
    return a.num*b.den < b.num*a.den;
}

bool operator<=(const Frac &a, const Frac &b) {
    return a.num*b.den <= b.num*a.den;
}

Frac operator-(const Frac &a, const Frac &b) {
    return Frac(a.num * b.den - b.num * a.den, a.den * b.den);
}

Frac operator+(const Frac &a, const Frac &b) {
    return Frac(a.num * b.den + b.num * a.den, a.den * b.den);
}

Frac operator/(const Frac &a, const Frac &b) {
    return Frac(a.num * b.den, a.den * b.num);
}

Frac operator*(const Frac &a, const Frac &b) {
    return Frac(a.num * b.num, a.den * b.den);
}

// typedef long double D ;
typedef Frac D ;

typedef pair<D, D> pdd;
const D inf = 1e9 + 1;

vector <pdd> spds;
vector <D> xs;

D calcCol(pdd lft, pdd rgt) {
    return (rgt.first - lft.first) / (lft.second - rgt.second);
}

D colTim(pdd cur) {
    if(spds.empty())
        return inf;
    if((int) spds.size() == 1)
        return calcCol(spds[0], cur);
    int ini = 0, fin = spds.size() - 2;
    while(ini < fin) {
        int piv = (ini + fin) / 2;
        D x = calcCol(spds[piv], cur);
        D y = calcCol(spds[piv+1], cur);
        assert(!(x == y));
        if(x < y)
            fin = piv ;
        else
            ini = piv + 1;
    }
    D ans = calcCol(spds[spds.size() - 1], cur) ;
    D cvl = calcCol(spds[ini], cur);
    ans = min(cvl, ans);
    cvl = calcCol(spds[ini+1], cur);
    ans = min(cvl, ans);
    return ans;
}

void updSpds(pdd nov) {
    if(spds.empty()) {
        spds.push_back(nov);
        return ;
    }
    while((int) spds.size() > 1 &&
          xs.back() <= calcCol(spds.back(), nov)) {
        spds.pop_back();
        xs.pop_back();
    }
    xs.push_back(calcCol(spds.back(), nov));
    spds.push_back(nov);
}

int main() {
    int N ;
    D ans = inf ;

    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        pdd cur = {a, b};
        if(b < 0)
            ans = min(ans, colTim(cur));
        else
            updSpds(cur);
    }

    if(ans == inf) {
        printf("-1\n");
        return 0 ;
    }

    __int128 g = __gcd(ans.num < 0? - ans.num : ans.num, ans.den < 0? - ans.den : ans.den);
    ans.num /= g ;
    ans.den /= g;
    printf("%.20lf\n", ((double) ans.num / ans.den));

    // printf("%.20Lf\n", ans);
}
