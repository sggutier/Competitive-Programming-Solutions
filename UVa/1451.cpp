#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int, pii> tri;
typedef list < tri >::iterator ito;
#define f first
#define s second
const int limN = 1e5 + 5;

struct Frac {
    int num, den;
    Frac() {}
    Frac(int num, int den) {
        if(den < 0)
            num *= -1;
        int d = __gcd(abs(num), den);
        this->num = num/d;
        this->den = den/d;
    }
};

struct Coso {
    Frac f;
    ito i;
    Coso(Frac f, ito i) {
        this->f = f;
        this->i = i;
    }
};

bool operator<(Frac A, Frac B) {
    // printf("%d / %d   %c   %d / %d\n", A.num, A.den, ((long long) A.num)*B.den < ((long long) B.num)*A.den? '<' : '>', B.num, B.den);
    return ((long long) A.num)*B.den < ((long long) B.num)*A.den;
}

bool operator<(Coso A, Coso B) {
    if(A.f.num != B.f.num || A.f.den != B.f.den)
        return B.f < A.f;
    return A.i->s.f < B.i->s.f;
    // return A->s.f < B->s.f;
}

void testCase() {
    int N, L;
    char str[limN];
    int acums[limN];
    vector <pii> pares;
    list <tri> rangos;
    set < Coso > cmbs;

    scanf("%d%d", &N, &L);
    scanf("%s", str);
    pair<Frac, pii> ans = {Frac(0, 1), {0, (N-1)}};
    acums[0] = 0;
    for(int i=0, u=0; i<=N; i++) {
        acums[i+1] = acums[i] + (str[i] == '1'? 1 : 0);
        if(i+1 >= L)
            ans = max(ans, {Frac(acums[i+1]-acums[i+1-L], L), {-(i-L+1), i}});
        if(str[i]=='1') {
            continue;
        }
        if(u!=i) {
            pares.push_back({u,i-1});
            if(i-u >= L) {
                printf("%d %d\n", u+1, u+L);
                return;
            }
        }
        u = i+1;        
    }

    ito it;
    for(int i=0, n=pares.size(); i<n; i++) {
        printf("%d %d\n", pares[i].first, pares[i].second);
        rangos.push_back({pares[i].second - pares[i].first + 1, pares[i]});
        if(i==0)
            it = rangos.begin();
        else {
            // printf("tam de %d  %d \n", (int) rangos.size(), it == rangos.begin());
            Coso c = {Frac(pares[i].second - pares[i].first + pares[i-1].second - pares[i-1].first + 2,
                                  pares[i].second - pares[i-1].first + 1),
                      it};
            // printf("Metiendo el %d / %d locado en %d a %d\n", c.f.num, c.f.den, c.i->s.f, c.i->s.s);
            cmbs.insert(c);
            it++;
        }
    }

    while(rangos.size() > 1) {
        auto mej = cmbs.begin();
        it = mej->i;
        if(it->s.s - it->s.f + 1 >= L)            
            ans = max(ans, {mej->f, {-it->s.f, it->s.s}});
        if(it->s.s - it->s.f + 1 >= L) {
            ito it3 = it;
            it3++;
            printf("Considerando ahora a %d / %d  locado en %d a %d\n", it->f + it3->f, it3->s.s - it->s.f + 1, it->s.f, it3->s.s);
            printf("\tOriginalmente era el %d a %d\n", it->s.f, it->s.s);
        }
        cmbs.erase(mej);
        int tot = it->f;
        int izq = it->s.f, der = it->s.s;
        it = rangos.erase(it);
        ito it2 = it;
        it2++;
        if(it2 != rangos.end()) {
            cmbs.erase({Frac(it->f + it2->f, it2->s.s - it->s.f + 1), it});
            cmbs.insert({Frac(it->f + it2->f + tot, it2->s.s - izq + 1), it});
        }
        it2 = it;
        if(it2 != rangos.begin() ) {
            it2 --;
            cmbs.erase({Frac(tot + it2->f, der - it2->s.f + 1), it2});
            cmbs.insert({Frac(tot + it->f + it2->f, it->s.s - it2->s.f + 1), it2});
        }
        it->f += tot;
        it->s.f = izq;
    }
    // printf("Finichado\n");

    if(!rangos.empty() ) {
        it = rangos.begin();
        ans = max(ans, {Frac(it->f, it->s.s - it->s.f + 1), it->s});
    }

    printf("%d %d\n", -ans.s.f+1, ans.s.s+1);
    // printf("\t%d %d\n", ans.f.num, ans.f.den);
}

int main() {
    // int tc;
    // for(scanf("%d", &tc); tc; tc--)
        testCase();
}
