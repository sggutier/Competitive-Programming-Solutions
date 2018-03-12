#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> par;
typedef pair<int, par> tri;
#define f first
#define s second
const int limN = 2005;
const int div = 45;

int toD(const int x) {
    return x/div + (x%div? 1 : 0);
}

vector <tri> bbok[limN];
bool actv[limN];
int vals[limN][limN];
int dueno[limN][limN];
ll bcks[div + 5][div + 5];

void flipa(int w) {
    int sgn = actv[w]? -1 : 1;
    actv[w] ^= true;
    for(const tri &t:bbok)
        bcks[t.s.f][t.s.s] += t.f*sgn;
}

void diva(int w, vector <tri> &g) {
    vector <vector<int>> ado(div, vector<int>(div, 0));
    for(const tri &g) {
        bcks[t.s.f/div][t.s.s/div] += t.f;
        dueno[t.s.f][t.s.s] = w;
        vals[t.s.f][t.s.s] = t.f;
    }
    for(int i=0; i<div; i++)
        for(int j=0; j<div; j++)
            if(ado[i][j])
                bbok[w].push_back(tri(ado[i][j], par(i, j)));
}

ll cuenta(int rIni, int cIni, int rFin, int cFin) {
    ll ans = 0;
    int rBlIni = toD(rIni), cBlIni = toD(cIni);
    int rBlFin = toD(rFin+1)-1, cBlFin = toD(cFin+1)-1;
    if(
}
