#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second
const int LIM_N = 1e5 + 5;
const int INF = 1e9 + 5;
const ll MAX_N = 1e9 + 2;
// const ll MAX_N = 10;

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}


const ll modA = 1e9 + 7;
struct ModA {
    ll x;
    ModA(ll xx = 0) : x(xx) {}
    ModA operator+(ModA b) { return ModA((x + b.x) % modA); }
    ModA operator-(ModA b) { return ModA((x - b.x + modA) % modA); }
    ModA operator*(ModA b) { return ModA((x * b.x) % modA); }
};

const ll modB = 970592641;
struct ModB {
    ll x;
    ModB(ll xx = 0) : x(xx) {}
    ModB operator+(ModB b) { return ModB((x + b.x) % modB); }
    ModB operator-(ModB b) { return ModB((x - b.x + modB) % modB); }
    ModB operator*(ModB b) { return ModB((x * b.x) % modB); }
};

struct Mod {
    ModA x;
    ModB y;
    Mod(const ll z) : x(z), y(z) {}
    Mod(ModA xx = 0, ModB yy = 0) : x(xx), y(yy) {}
    Mod operator+(Mod b) { return Mod(x + b.x, y + b.y); }
    Mod operator-(Mod b) { return Mod(x - b.x, y - b.y); }
    Mod operator*(Mod b) { return Mod(x * b.x, y * b.y); }
    bool operator==(const Mod &b) {
        return x.x == b.x.x && y.x == b.y.x;
    }
};

struct BIT {
    int N ;
    pii arr[LIM_N];
    BIT(int N) : N(N) {
        for(int i=0; i <= N; i++)
            arr[i] = {INF, INF};
    }
    void mete(int pos, const pii nov) {
        for(; pos; pos -= pos & -pos)
            arr[pos] = min(arr[pos], nov);
    }
    pii saca(int pos) {
        pii ans = {INF, INF};
        for(; pos <= N; pos += pos & -pos)
            ans = min(ans, arr[pos]);
        return ans;
    }
};

int N ;
int nums[LIM_N], ords[LIM_N];
int orgV[LIM_N];
int nextP[LIM_N];
Mod modns[LIM_N], pots[LIM_N];
BIT *bt;

Mod getRn(int ini, int fin) {
    ini --;
    return (modns[fin] - modns[ini] * pots[fin - ini]) ;
}

int main() {
    scanf("%d", &N);
    for(int i=1; i <= N; i++) {
        scanf("%d", &nums[i]);
        orgV[i] = nums[i];
        ords[i-1] = i;
    }

    sort(ords, ords+N,
         [](const int a, const int b) {
             if(nums[a] != nums[b])
                 return nums[a] < nums[b];
             return a < b;
         });
    for(int i=0, lastV=-1, curN=0; i < N; i++) {
        int pos = ords[i];
        int v = nums[pos];
        if(v != lastV) {
            lastV = v;
            curN ++;
        }
        else {
            nextP[ords[i-1]] = pos;
        }
        nums[pos] = curN;
    }

    pots[0] = 1;
    for(int i=1; i <= N; i++) {
        modns[i] = modns[i-1] * MAX_N + nums[i];
        pots[i] = pots[i-1] * MAX_N;
    }

    bt = new BIT(N);
    for(int i=1; i <= N; i++) {
        for(int j=nextP[i]; j; j = nextP[j]) {
            int len = j-i;
            if(j + len - 1 > N) {
                break;
            }
            if(getRn(i, j-1) == getRn(j, j+len-1)) {
                bt->mete(i, {len, i});
                // printf("%d -> %d\n", i, len);
                break;
            }
        }
    }

    int L = 1;
    while(true) {
        auto p = bt->saca(L);
        if(p.first == INF) {
            break;
        }
        // printf("%d ==>> %d\n", p.first, p.second);
        L = p.second + p.first ;
    }

    printf("%d\n", N - L + 1);
    for(int i=L; i <= N; i++)
        printf("%d ", orgV[i]);
    printf("\n");
}
