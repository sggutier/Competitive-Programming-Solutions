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
const long double eps = 1e-14;
const int base = 1000000000;
const int base_digits = 9;

struct bigint {
    vector<int> z;
    int sign;

    bigint() :
        sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        z = v.z;
    }

    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        z.clear();
        for (; v > 0; v = v / base)
            z.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(z.size(), v.z.size()) || carry; ++i) {
                if (i == (int) res.z.size())
                    res.z.push_back(0);
                res.z[i] += carry + (i < (int) z.size() ? z[i] : 0);
                carry = res.z[i] >= base;
                if (carry)
                    res.z[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.z.size() || carry; ++i) {
                    res.z[i] -= carry + (i < (int) v.z.size() ? v.z[i] : 0);
                    carry = res.z[i] < 0;
                    if (carry)
                        res.z[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) z.size() || carry; ++i) {
            if (i == (int) z.size())
                z.push_back(0);
            long long cur = z[i] * (long long) v + carry;
            carry = (int) (cur / base);
            z[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.z.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.z.resize(a.z.size());

        for (int i = a.z.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.z[i];
            int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;
            int s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;
            int d = ((long long) s1 * base + s2) / b.z.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.z[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    friend bigint sqrt(const bigint &a1) {
        bigint a = a1;
        while (a.z.empty() || a.z.size() % 2 == 1)
            a.z.push_back(0);

        int n = a.z.size();
        
        int firstDigit = (int) sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
        int norm = base / (firstDigit + 1);
        a *= norm;
        a *= norm;
		while (a.z.empty() || a.z.size() % 2 == 1)
			a.z.push_back(0);
        
        bigint r = (long long) a.z[n - 1] * base + a.z[n - 2];
        firstDigit = (int) sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
        int q = firstDigit;
		bigint res;
 
        for(int j = n / 2 - 1; j >= 0; j--) {
            for(; ; --q) {
                bigint r1 = (r - (res * 2 * base + q) * q) * base * base + (j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
                if (r1 >= 0) {
                    r = r1;
                    break;
                }
            }
            res *= base;
            res += q;

            if (j > 0) {
				int d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;
				int d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;
                int d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0;
                q = ((long long) d1 * base * base + (long long) d2 * base + d3) / (firstDigit * 2);
            }           
        }
        
        res.trim();
        return res / norm;
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) z.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = z[i] + rem * (long long) base;
            z[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = z.size() - 1; i >= 0; --i)
            m = (z[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (z.size() != v.z.size())
            return z.size() * sign < v.z.size() * v.sign;
        for (int i = z.size() - 1; i >= 0; i--)
            if (z[i] != v.z[i])
                return z[i] * sign < v.z[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!z.empty() && z.back() == 0)
            z.pop_back();
        if (z.empty())
            sign = 1;
    }

    bool isZero() const {
        return z.empty() || (z.size() == 1 && !z[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = z.size() - 1; i >= 0; i--)
            res = res * base + z[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        z.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            z.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.z.empty() ? 0 : v.z.back());
        for (int i = (int) v.z.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.z[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && res.back() == 0)
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->z, base_digits, 6);
        vector<int> b6 = convert_base(v.z, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.z.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.z = convert_base(res.z, 6, base_digits);
        res.trim();
        return res;
    }
};

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
    bigint anum(A.num), aden(A.den);
    bigint bnum(B.num), bden(B.den);
    return anum*bden < bnum*aden;
    // long double a = (1.0*A.num), b = (1.0*B.num);
    // return a / A.den + eps < b / B.den;
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


Frac calcAng(Angle A, Angle B) { //, bool printa = false) {
    ll x = A.x, y = A.y;
    ll a = B.x, b = B.y;
    ll P = a*x + b*y;
    ll Q = x*x + y*y, R = a*a + b*b;
    // if(printa) {
    //     printf("%d %d | %d %d    =>   ", A.x, A.y, B.x, B.y);
    //     printf("%lld %lld | %lld %lld\n", x, y, a, b);
    //     printf("%lld %lld %lld\n", P, Q, R);
    //     printf("%.9lf\n", P/(sqrt(Q) * sqrt(R)));
    // }
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
        // if(cits[i].s == 1918)
        //     printf("Ciudad %d (%d %d) entre trenes %d %d y %d %d (%d %d)\n", cits[i].s, cits[i].f.x, cits[i].f.y, trs[a].f.f.x, trs[a].f.f.y, trs[b].f.f.x, trs[b].f.f.y, trs[a].s-N, trs[b].s-N);
        if(!(cits[i].f < trs[a].f.f) && !(cits[i].f > trs[a].f.f)) {
            // if(cits[i].s == 1918)
            // printf("Especial: Ciudad %d igual a tren %d\n", cits[i].s, trs[a].s - N);
            pr->add_edge(cits[i].s, trs[a].s, 1);
            continue;
        }
        else if(!(cits[i].f < trs[b].f.f) && !(cits[i].f > trs[b].f.f)) {
            // if(cits[i].s == 1918)
            // printf("Especial: Ciudad %d igual a tren %d\n", cits[i].s, trs[b].s - N);
            pr->add_edge(cits[i].s, trs[b].s, 1);
            continue;
        }
        // continue;
        Frac A = calcAng(cits[i].f, trs[a].f.f);
        Frac B = calcAng(cits[i].f, trs[b].f.f);
        // if(cits[i].s == 1918)
            //printf("%.4lf %.4lf\n", A, B);
        if(A < B) {
            pr->add_edge(cits[i].s, trs[b].s, 1);
            // if(cits[i].s == 1918)
            // printf("Mas cerca de B\n");
        }
        else if(B < A) {
            pr->add_edge(cits[i].s, trs[a].s, 1);
            // if(cits[i].s == 1918)
            //     printf("Mas cerca de A\n");
        }
        else {
            // if(cits[i].s == 1918)
            //     printf("Igual\n");
            pr->add_edge(cits[i].s, trs[a].s, 1);
            if(a!=b)
                pr->add_edge(cits[i].s, trs[b].s, 1);
        }
        // if(cits[i].s == 1918)
        //     return 0;
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
