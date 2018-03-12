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

typedef int Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

struct PushRelabel {
	vector<vector<Edge>> g;
	vector<Flow> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		Edge a = {t, sz(g[t]), 0, cap};
		Edge b = {s, sz(g[s]), 0, rcap};
		g[s].push_back(a);
		g[t].push_back(b);
        // printf("Creando arista de %d a %d con cap %lld\n", s, t, cap);
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = inf;//1e7;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
};

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
PushRelabel *pr;

int main() {
    scanf("%d%d", &N, &T);
    int ini=N+T, fin=N+T+1;
    pr = new PushRelabel(N+T+2);
    for(int i=0, x, y; i<N; i++) {
        scanf("%d%d", &x, &y);
        cits[i].f = Angle(x, y);
        cits[i].s = i;
    }
    for(int i=0, x, y, c; i<T; i++) {
        scanf("%d%d%d", &x, &y, &c);
        trs[i].f = {Angle(x, y), c};
        trs[i].s = i + N;
    }

    if(N==0 || T==0) {
        printf("0\n");
        return 0 ;
    }

    sort(cits, cits+N);
    sort(trs, trs+T);
    for(int i=0; i<N; i++)
        pr->add_edge(cits[i].s, fin, 1);
    for(int i=0; i<T; i++) {
        if(trs[i].f.s)
            pr->add_edge(ini, trs[i].s, trs[i].f.s);
        // printf("Tren %d %d\n", trs[i].f.f.x, trs[i].f.f.y);
    }
    for(int i=0, j=0; i<N; i++) {
        while(j < T &&  trs[j].f.f < cits[i].f)
            j++;        
        int a = (j-1+T) % T, b = j%T;
        // printf("Ciudad %d (%d %d) entre trenes %d %d y %d %d (%d %d)\n", cits[i].s, cits[i].f.x, cits[i].f.y, trs[a].f.f.x, trs[a].f.f.y, trs[b].f.f.x, trs[b].f.f.y, trs[a].s-N, trs[b].s-N);
        if(!(cits[i].f < trs[a].f.f) && !(cits[i].f > trs[a].f.f)) {
            // printf("Especial: Ciudad %d igual a tren %d\n", cits[i].s, trs[a].s - N);
            pr->add_edge(trs[a].s, cits[i].s, 1);
            continue;
        }
        else if(!(cits[i].f < trs[b].f.f) && !(cits[i].f > trs[b].f.f)) {
            // printf("Especial: Ciudad %d igual a tren %d\n", cits[i].s, trs[b].s - N);
            pr->add_edge(trs[b].s, cits[i].s, 1);
            continue;
        }
        // continue;
        Frac A = calcAng(cits[i].f, trs[a].f.f);
        Frac B = calcAng(cits[i].f, trs[b].f.f);
        // printf("%.4lf %.4lf\n", A, B);
        if(A < B) {
            pr->add_edge(trs[b].s, cits[i].s, 1);
            // printf("Mas cerca de B\n");
        }
        else if(B < A) {
            pr->add_edge(trs[a].s, cits[i].s, 1);
            // printf("Mas cerca de A\n");
        }
        else {
            // printf("Igual\n");
            pr->add_edge(trs[a].s, cits[i].s, 1);
            if(a!=b)
                pr->add_edge(trs[b].s, cits[i].s, 1);
        }
    }

    printf("%d\n", pr->maxflow(ini, fin));
    // for(int i=0; i<(int) pr->g.size(); i++) {
    //     printf("%d => ", i);
    //     for(const auto &e:pr->g[i]) {
    //         printf("[%lld %lld %d] ", e.f, e.c, e.dest);
    //     }
    //     printf("\n");
    // }
    for(int i=0; i<T; i++) {
        int p = trs[i].s ;
        for(const auto &e:pr->g[p]) {
            if(e.f > 0) {
                // printf("%d %d\n", p-N, e.dest);
                printf("%d %d\n", e.dest, p-N);
                // break;
            }
        }
    }
                              
}
