#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 31443539979727LL;
const ll modB = 3006703054056749LL;
const int LIM_S = 1e6 + 5 ;
const int LIM_N = 1e5 + 5 ;

struct Mod {
    ll x, y;
    Mod(ll xx = 0, ll yy = 0) : x(xx), y(yy) {}
    Mod operator+(Mod b) const { return Mod((x + b.x) % mod, (y + b.y) % modB); }
    Mod operator-(Mod b) const { return Mod((x - b.x + mod) % mod, (y - b.y + modB) % modB); }
    Mod operator*(Mod b) const { return Mod((x * b.x) % mod, (y * b.y) % modB); }
    bool operator<(const Mod &b) const {
        if(this->x != b.x)
            return this->x < b.x;
        return this->y < b.y;
    }
};
const Mod DIC = 27;

Mod potDic[LIM_S];
char tmp[LIM_S];
// bool debugo = false;
vector <string> As, Bs;
map <Mod, vector<pii>> triosA;
bool notPecA[LIM_N], notPecB[LIM_N];

inline Mod toModo(const char a) {
    return a - 'a' + 1 ;
}

Mod prefsss[LIM_S];
Mod hashString(const string &S) {
    Mod ans = 0 ;
    int k = 0 ;
    for(const char c : S) {
        ans = ans*DIC + toModo(c);
        prefsss[k++] = ans;
    }
    return ans ;
}

void procFunc(vector <string> &ws, function<Mod(Mod, Mod, int)> calcSuf, function<void(Mod, int, int)> f) {
    map <Mod, int> hss;
    int N = ws.size();
    for(int i=0; i < N; i++) {
        hss[hashString(ws[i])] = i;
    }
    for(int i=0; i < N; i++) {
        string &s = ws[i];
        int L = s.size();
        Mod hsPref = 0, hsSuf = 0, mSi;
        hashString(ws[i]);
        for(int k=L-1, p=0; k; k--, p++) {
            mSi = s[k];
            hsSuf = calcSuf(hsSuf, mSi, p);
            hsPref = prefsss[k-1];
            auto it = hss.find(hsPref);
            if(it != hss.end())
                f(hsSuf, it->second, i);
        }
    }
}

Mod calcSufRev(const Mod &hsSuf, const Mod &mSi, const int &p) {
    return hsSuf * DIC + mSi; ;
}

Mod calcSufOrd(const Mod &hsSuf, const Mod &mSi, const int &p) {
    return hsSuf + potDic[p] * mSi;
}

void matchA(const Mod &h, const int a, const int b) {
    auto it = triosA.find(h);
    if(it == triosA.end()) {
        triosA[h];
        // triosA.emplace(h, vector<pii>());
        it = triosA.find(h);
    }
    // printf("A: %lld, %d %d\n", h.x, a, b);
    it->second.emplace_back(a, b);
}

void matchB(const Mod &h, const int a, const int b) {
    // printf("B: %lld, %d %d\n", h.x, a, b);
    auto it = triosA.find(h);
    if(it == triosA.end())
        return ;
    // if(debugo) {
    //     printf("B: %d %d\n", a, b);
    // }
    notPecB[a] = true;
    notPecB[b] = true;
    for(const auto &p : it->second) {
        notPecA[p.first] = true;
        notPecA[p.second] = true;
        // if(debugo) {
        //     printf("A: %d %d\n", p.first, p.second);
        // }
    }
    it->second.clear();
}

int countNp(bool* notPec, int N) {
    int ans = N ;
    for(int i=0; i < N; i++)
        if(notPec[i])
            ans --;
    return ans;
}

void init() {
    potDic[0] = 1;
    for(int i=1; i < LIM_S; i++)
        potDic[i] = potDic[i-1] * DIC;
}

int main() {
    init();
    int N, M ;
    scanf("%d%d", &N, &M);
    // if(M == 3) debugo = true;
    As.resize(N);
    Bs.resize(M);
    for(int i=0; i < N; i++) {
        scanf("%s", tmp);
        As[i] = tmp;
    }
    for(int i=0; i < M; i++) {
        scanf("%s", tmp);
        Bs[i] = tmp;
        reverse(Bs[i].begin(), Bs[i].end());
    }
    procFunc(As, calcSufOrd, matchA);
    procFunc(Bs, calcSufRev, matchB);
    printf("%d %d\n", countNp(notPecA, N), countNp(notPecB, M));
}
