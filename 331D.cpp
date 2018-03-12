#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> par;
#define f first
#define s second
const int limN = 1e5 + 5;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int ciclPadr[limN];
int ciclPos[limN];
vector <par> cicl[limN];
ll cicLen[limN];
par padr[limN];

void hazArb(bool *usd, bool *actv, int pos) {
    if(usd[pos]) {
        if(!actv[pos])
            return;
        // printf("Encontre ciclo en %d\n", pos);
        // printf("Otros elems son");
        cicl[pos].push_back(par(0,pos));
        ll sumo = padr[pos].f;
        // printf("%d ", pos);
        for(int i=padr[pos].s; i!=pos; i=padr[i].s) {            
            cicl[pos].push_back(par(sumo, i));
            ciclPadr[i] = pos;
            // printf("%d " ,i);
            ciclPos[i] = cicl[pos].size();
            sumo += padr[i].f;
        }
        // printf("\n");
        cicLen[pos] = sumo;
        return;
    }
    // printf("const %d %d\n", pos, padr[pos].s);
    usd[pos] = true;
    actv[pos] = true;
    ciclPadr[pos] = -1;
    hazArb(usd, actv, padr[pos].s);
    actv[pos] = false;
}

void cargaArbs(int N) {
    bool usd[limN], actv[limN];
    memset(usd, 0, sizeof(usd));
    memset(actv, 0, sizeof(actv));
    usd[N] = true;
    for(int i=0; i<N; i++)
        hazArb(usd, actv, i);
}

par calcaFin(int N, int pos, ll k) {
    // printf("inicio en %d con %lld\n", pos, k);
    while(ciclPadr[pos]==-1 && padr[pos].f <= k) {
        // printf("estoy en %d y mi pa es %d a dst %lld\n", pos, padr[pos].s, padr[pos].f);
        k -= padr[pos].f;
        if(padr[pos].s == N)
            return par(padr[pos].f, pos);
        pos = padr[pos].s;
        // printf("cf\n");
    }
    // printf("CF %d %d %lld\n", pos, ciclPadr[pos], padr[pos].f);
    if(padr[pos].f > k) {
        return par(k, pos);
    }
    vector <par> &C = cicl[ciclPadr[pos]];
    int p = ciclPos[pos];
    ll L = cicLen[padr[pos].s];
    int up = pos;
    ll ud = 0;
    N = C.size();
    k %= L;
    for(int i=1; i<N; i++) {
        ll pa = ((L + C[(i+p)%N].f) - C[p].f) % L;
        if(pa > k)
            break;
        ud = k - pa;
        up = C[i].s;
    }
    return par(ud, up);
}

// int encSig(map <int, int> flech[2][limN], int pos[2], int d) {
//     int p = d/2, p2 = 1-p;
//     map <int, int> &F = flech[p][pos[p2]];
//     map <int, int>::iterator it;
//     if(d%2==0) {
//         it = F.upper_bound(pos[p]);
//         if(it==F.begin())
//             it = F.end();
//         else
//             it --;
//     }
//     else {
//         it = F.lower_bound(pos[p]);
//     }
//     return it==F.end()? -1 : it->s;
// }

int calcDstBrd(int B, int pos[2], int d) {
    if(d==0)
        return pos[0];
    else if(d==2)
        return pos[1];
    else if(d==1)
        return B - pos[0];
    else
        return B - pos[1];
}

int calcDstPts(int A[2], int B[2]) {
    return abs(A[0]-B[0]) + abs(A[1]-B[1]);
}


par encSig(int N, int B, int flechIni[][2], int flechFin[][2], int cpy[2], int d) {
    int pos[2] = {cpy[0], cpy[1]};
    while(0 <= pos[0] && pos[0] <= B &&
          0 <= pos[1] && pos[1] <= B) {
        for(int i=0; i<N; i++) {
            int a1, a2, b1, b2;
            a1 = min(flechIni[i][0], flechFin[i][0]);
            a2 = max(flechIni[i][0], flechFin[i][0]);
            b1 = min(flechIni[i][1], flechFin[i][1]);
            b2 = max(flechIni[i][1], flechFin[i][1]);            
            if(a1 <= pos[0] && pos[0] <= a2 &&
               b1 <= pos[1] && pos[1] <= b2)
                return par(calcDstPts(pos, flechIni[i]), i);
        }
        pos[0] += dx[d];
        pos[1] += dy[d];
        ans ++;
    }
    return par(N, 0);
}

map <int, int> flechPoss[2][limN];

int main() {
    int dico[300];
    dico['U'] = 3;
    dico['D'] = 2;
    dico['R'] = 1;
    dico['L'] = 0;
    int N, B, Q;
    int flechIni[limN][2], flechFin[limN][2], flechDir[limN];

    scanf("%d%d", &N, &B);
    for(int i=0; i<N; i++) {
        scanf("%d%d%d%d", &flechIni[i][0], &flechIni[i][1], &flechFin[i][0], &flechFin[i][1]);
        flechDir[i] = (flechIni[i][0]!=flechFin[i][0]? 0 : 2)
            + ((flechIni[i][0] < flechFin[i][0] || flechIni[i][1] < flechFin[i][1])? 1 : 0);
        for(int j=0; j<2; j++)
            flechPoss[j][flechIni[i][1-j]][flechIni[i][j]] = i;
        printf("La flecha %d %d tiene dir %d\n", flechIni[i][0], flechIni[i][1], flechDir[i]);
    }
    for(int i=0; i<N; i++) {
        int pos[] = {flechFin[i][0] + dx[flechDir[i]],
                     flechFin[i][1] + dy[flechDir[i]]};                    
        // int sig = encSig(flechPoss, pos, flechDir[i]);
        int sig = encSig(N, B, flechIni, flechFin, pos, flechDir[i]);
        ll dst ;
        if(sig==-1) {
            sig = N;
            dst = calcDstBrd(B, flechIni[i], flechDir[i]);
        }
        else {
            dst = calcDstPts(flechIni[i], flechIni[sig]);
        }
        padr[i] = par(dst, sig);
        printf("De la flecha %d %d sigue la %d con dst %lld\n", flechIni[i][0], flechIni[i][1], sig, dst);
    }
    cargaArbs(N);

    scanf("%d", &Q);
    while(Q--) {
        ll k, w ;
        int pos[2];
        char str[5];
        int d ;
        int sig ;
        scanf("%d%d%s%lld", &pos[0], &pos[1], str, &k);
        d = dico[(int) str[0]];
        // sig = encSig(flechPoss, pos, d);
        sig = encSig(N, B, flechIni, flechFin, pos, d);
        if(sig==-1) {
            w = calcDstBrd(B, pos, d);
        }
        else {
            w = calcDstPts(pos, flechIni[sig]);
        }
        printf("Del punto %d %d (%d %lld) sigue %d con dst %lld\n", pos[0], pos[1], d, k, sig, w);
        if(w >= k) {
            printf("a %d %d\n", (int) (pos[0] + dx[d]*k), (int) (pos[1] + dy[d]*k));
        }
        else if(sig==-1) {
            printf("b %d %d\n", (int) (pos[0] + dx[d]*w), (int) (pos[1] + dy[d]*w));
        }
        else {
            par fn = calcaFin(N, sig, k-w);
            k = fn.f, sig = fn.s;
            printf("el pf es %d %d con %lld de sobra\n",  flechIni[sig][0], flechIni[sig][1], k);
            printf("%d %d\n", (int) (flechIni[sig][0] + dx[flechDir[sig]]*k), (int) (flechIni[sig][1] + dy[flechDir[sig]]*k));
        }
    }
}
