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
typedef int LL;
struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void add_edge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL maxflow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
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
Dinic *pr;

int main() {
    scanf("%d%d", &N, &T);
    int ini=N+T, fin=N+T+1;
    pr = new Dinic(N+T+2);
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
        pr->add_edge(ini, cits[i].s, 1);
    for(int i=0; i<T; i++) {
        if(trs[i].f.s)
            pr->add_edge(trs[i].s, fin, trs[i].f.s);
        // printf("Tren %d %d\n", trs[i].f.f.x, trs[i].f.f.y);
    }
    for(int i=0, j=0; i<N; i++) {
        while(j < T &&  trs[j].f.f < cits[i].f)
            j++;        
        int a = (j-1+T) % T, b = j%T;
        // printf("Ciudad %d (%d %d) entre trenes %d %d y %d %d (%d %d)\n", cits[i].s, cits[i].f.x, cits[i].f.y, trs[a].f.f.x, trs[a].f.f.y, trs[b].f.f.x, trs[b].f.f.y, trs[a].s-N, trs[b].s-N);
        if(!(cits[i].f < trs[a].f.f) && !(cits[i].f > trs[a].f.f)) {
            // printf("Especial: Ciudad %d igual a tren %d\n", cits[i].s, trs[a].s - N);
            pr->add_edge(cits[i].s, trs[a].s, 1);
            continue;
        }
        else if(!(cits[i].f < trs[b].f.f) && !(cits[i].f > trs[b].f.f)) {
            // printf("Especial: Ciudad %d igual a tren %d\n", cits[i].s, trs[b].s - N);
            pr->add_edge(cits[i].s, trs[b].s, 1);
            continue;
        }
        // continue;
        Frac A = calcAng(cits[i].f, trs[a].f.f);
        Frac B = calcAng(cits[i].f, trs[b].f.f);
        // printf("%.4lf %.4lf\n", A, B);
        if(A < B) {
            pr->add_edge(cits[i].s, trs[b].s, 1);
            // printf("Mas cerca de B\n");
        }
        else if(B < A) {
            pr->add_edge(cits[i].s, trs[a].s, 1);
            // printf("Mas cerca de A\n");
        }
        else {
            // printf("Igual\n");
            pr->add_edge(cits[i].s, trs[a].s, 1);
            if(a!=b)
                pr->add_edge(cits[i].s, trs[b].s, 1);
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
    for(const auto &e : pr -> E)
        if(e.flow > 0 && e.u < N)
            printf("%d %d\n", e.u, e.v - N);
}
