#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int limN = 2e5 + 5;
const int inf = 1e7;

struct Frac {
    ll num, den;
    Frac(ll a, ll b) {        
        ll g = __gcd(abs(a), abs(b));
        // if(b==0 || g==0) {
        //     printf("Changos, div por 0\n");
        //     while(true);
        // }
        if(b < 0)
            a *= -1, b *= -1;
        num = a/g, den = b/g;
    }
};

bool operator<(Frac &A, Frac &B) {
    return A.num*B.den < B.num*A.den;
}

struct Angle {
	int x, y;
	int t;
    Angle() {}
	Angle(int x, int y, int t=0) : x(x), y(y), t(t) {}
	Angle operator-(Angle a) const { return {x-a.x, y-a.y, t}; }
	int quad() const {
		assert(x || y);
		if (y < 0) return (x >= 0) + 2;
		if (y > 0) return (x <= 0);
		return (x <= 0) * 2;
	}
	Angle t90() const { return {-y, x, t + (quad() == 3)}; }
	Angle t180() const { return {-x, -y, t + (quad() >= 2)}; }
	Angle t360() const { return {x, y, t + 1}; }
};
bool operator<(Angle a, Angle b) {
	// add a.dist2() and b.dist2() to also compare distances
	return make_tuple(a.t, a.quad(), a.y * (ll)b.x) <
	       make_tuple(b.t, b.quad(), a.x * (ll)b.y);
}
bool operator>=(Angle a, Angle b) { return !(a < b); }
bool operator>(Angle a, Angle b) { return b < a; }
bool operator<=(Angle a, Angle b) { return !(b < a); }

// Given two points, this calculates the smallest angle between
// them, i.e., the angle that covers the defined line segment.
pair<Angle, Angle> segmentAngles(Angle a, Angle b) {
	if (b < a) swap(a, b);
	return (b < a.t180() ?
	        make_pair(a, b) : make_pair(b, a.t360()));
}

Angle operator+(Angle a, Angle b) { // where b is a vector
	Angle r(a.x + b.x, a.y + b.y, a.t);
	if (r > a.t180()) r.t--;
	return r.t180() < a ? r.t360() : r;
}

bool dfs(int a, int layer, const vector<vi>& g, vi& btoa,
			vi& A, vi& B) {
	if (A[a] != layer) return 0;
	A[a] = -1;
	trav(b, g[a]) if (B[b] == layer + 1) {
		B[b] = -1;
		if (btoa[b] == -1 || dfs(btoa[b], layer+2, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(const vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), -1);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		trav(a, btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay += 2) {
			bool islast = 0;
			next.clear();
			trav(a, cur) trav(b, g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && B[b] == -1) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			trav(a, next) A[a] = lay+1;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g)) {
			if(dfs(a, 0, g, btoa, A, B))
				++res;
		}
	}
}

Frac calcAng(Angle A, Angle B) {
    ll x = A.x, y = A.y;
    ll a = B.x, b = B.y;
    ll P = a*x + b*y;
    ll Q = x*x + y*y, R = a*a + b*b;
    // if(Q*R==0) {
    //     printf("Se esta muriendo con \n");
    //     printf("%d %d\n", A.x, A.y);
    //     printf("%d %d\n", B.x, B.y);
    // }
    // return P/(sqrt(Q) * sqrt(R));
    return Frac(P*P*(P < 0? -1 : 1), Q*R);
}

int N, T;
pair< Angle, int> cits[limN];
pair< pair<Angle, int>, int> trs[limN];
int ptrs[limN];
vi asts[limN];
vector <vi> g;
vi oows;

void add_edge(int c, int t) {
    if(trs[t].f.s == 0) return;
    int &p = ptrs[t];
    if((int) asts[t].size()-1 < p) {
        asts[t].push_back((int) g.size());
        g.push_back(vi());
        oows.push_back(t);
    }
    g[c].push_back(asts[t][p]);
    // printf("Arista de %d [%d] a %d [%d] (%d) =>  %d\n", cits[c].s, c, trs[t].s, t, asts[t][p], oows[asts[t][p]-N]);
    p = (p+1) % trs[t].f.s;
}

int main() {
    scanf("%d%d", &N, &T);
    for(int i=0, x, y; i<N; i++) {
        scanf("%d%d", &x, &y);
        cits[i].f = Angle(x, y);
        cits[i].s = i;
        g.push_back(vi());
    }
    for(int i=0, x, y, c; i<T; i++) {
        scanf("%d%d%d", &x, &y, &c);
        trs[i].f = {Angle(x, y), c};
        trs[i].s = i;
    }

    if(N==0 || T==0) {
        printf("0\n");
        return 0 ;
    }

    sort(cits, cits+N);
    sort(trs, trs+T);
    for(int i=0, j=0; i<N; i++) {
        while(j < T &&  trs[j].f.f < cits[i].f)
            j++;        
        int a = (j-1+T) % T, b = j%T;
        // printf("Ciudad %d (%d %d) entre trenes %d %d y %d %d (%d %d)\n", cits[i].s, cits[i].f.x, cits[i].f.y, trs[a].f.f.x, trs[a].f.f.y, trs[b].f.f.x, trs[b].f.f.y, trs[a].s-N, trs[b].s-N);
        if(!(cits[i].f < trs[a].f.f) && !(cits[i].f > trs[a].f.f)) {
            // printf("Especial: Ciudad %d igual a tren %d\n", cits[i].s, trs[a].s - N);
            add_edge(i, a);
            continue;
        }
        else if(!(cits[i].f < trs[b].f.f) && !(cits[i].f > trs[b].f.f)) {
            // printf("Especial: Ciudad %d igual a tren %d\n", cits[i].s, trs[b].s - N);
            add_edge(i, b);
            continue;
        }
        // continue;
        Frac A = calcAng(cits[i].f, trs[a].f.f);
        Frac B = calcAng(cits[i].f, trs[b].f.f);
        // printf("%.4lf %.4lf\n", A, B);
        if(A < B) {
            add_edge(i, b);
            // printf("Mas cerca de B\n");
        }
        else if(B < A) {
            add_edge(i, a);
            // printf("Mas cerca de A\n");
        }
        else {
            // printf("Igual\n");
            add_edge(i, a);
            if(a!=b)
                add_edge(i, b);
        }
    }

    vi ba(g.size(), -1);
    printf("%d\n", hopcroftKarp(g, ba));
    // for(int i=0; i < (int) g.size(); i++) 
    //     printf("\t%d %d\n", i, ba[i]);
    for(int i=ba.size()-1; i>=N; i--) {
        if(ba[i]==-1) continue;
        int y = trs[oows[i-N]].s;
        int x = cits[ba[i]].s;
        printf("%d %d\n", x, y);
    }
}
