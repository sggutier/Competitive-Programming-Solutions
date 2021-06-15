#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM_N = 2e5 + 5;
const int INF = numeric_limits<int>::max();

struct BIT {
    int N ;
    vector <pii> nums;
    BIT(int n) : N(n), nums(vector<pii>(n+1, {INF, 0})) {}
    void mete(int pos, const int x) {
        int orgPos = pos;
        for(; pos <= N; pos += pos & -pos)
            nums[pos] = min(nums[pos], {x, orgPos});
    }
    pii saca(int pos) {
        pii ans = {INF, 0};
        for(; pos; pos -= pos & -pos)
            ans = min(ans, nums[pos]);
        return ans;
    }
};

int N, M, K, B;
int tips[LIM_N];
ll csts[LIM_N];
BIT *minCs[2];
int ansPos[LIM_N];

bool works(const int maxD) {
    static ll tots[LIM_N];
    static int ords[LIM_N];
    for(int i=0; i < M; i++) {
        auto x = minCs[tips[i]]->saca(maxD);
        tots[i] = x.first * csts[i];
        ansPos[i] = x.second;
        ords[i] = i;
    }
    sort(ords, ords+M,
         [](const int a, const int b) {
             return tots[a] < tots[b];
         });
    ll sm = 0 ;
    for(int i=0; i < K; i++)
        sm += tots[ords[i]];
    for(int i=K; i < M; i++)
        ansPos[ords[i]] = -1;
    return sm <= B;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> N >> M >> K >> B ;
    for(int i=0; i < 2; i++) {
        minCs[i] = new BIT(N);
        for(int j=1; j <= N; j++) {
            int a ;
            cin >> a ;
            minCs[i]->mete(j, a);
        }
    }
    for(int i=0; i < M; i++) {
        cin >> tips[i] >> csts[i];
        tips[i] --;
    }
    int ini=1, fin=N;
    while(ini < fin) {
        int piv = (ini + fin) / 2 ;
        if(works(piv))
            fin = piv;
        else
            ini = piv + 1;
    }
    if(!works(ini)) {
        cout << -1 << endl;
        return 0 ;
    }
    cout << ini << endl;
    works(ini);
    for(int i=0; i < M; i++)
        if(ansPos[i] != -1)
            cout << i+1 << " " << ansPos[i] << endl;
}
