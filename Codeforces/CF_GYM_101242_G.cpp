#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct frac {
	ll a, b;
	
	frac(int _a, int _b) {
		int g = __gcd(abs(_a), abs(_b));
		a = _a / g, b = _b / g;
		if (b < 0) a *= -1, b *= -1;
	}	
};

bool operator <(const frac &a, const frac &b) { return a.a * b.b < b.a * a.b; }
bool operator ==(const frac &a, const frac &b) { return a.a == b.a && a.b == b.b; }

struct deposit {
	ll x0, x1, y;
	
	deposit() {}
	deposit(int _x0, int _x1, int _y) : x0(_x0), x1(_x1), y(_y) {}
	
	ll val() { return abs(x0 - x1); }
};

struct event {
	frac instant;
	ll delta;
	
	event(frac i, ll d) : instant(i), delta(d) { }
};

bool operator <(const event &a, const event &b) {
	if (a.instant == b.instant) return a.delta > b.delta;
	return a.instant < b.instant;
}

int N;
ll ANS;
deposit lst[2005];

int main() {
	scanf("%d", &N);
	
	for(int i=0,x0,x1,y;i<N;i++) {
		scanf("%d %d %d", &x0, &x1, &y);
		if (x0 > x1) swap(x0, x1);
		lst[i] = deposit(x0, x1, y);
	}
	
	for (int i=0;i<N;i++) {
		
		ll NANS = lst[i].val(), CURR;
		vector<event> e;
		
		// START
		CURR = lst[i].val();
		e.clear();
		for (int j=0;j<N;j++) if (lst[i].y != lst[j].y) {
			ll dy = lst[i].y - lst[j].y;
			frac aw = frac(lst[j].x0 - lst[i].x0, dy);
			frac bw = frac(lst[j].x1 - lst[i].x0, dy);
			if(bw < aw)
				swap(aw, bw);
			e.push_back(event(aw,  lst[j].val()));
			e.push_back(event(bw, -lst[j].val()));
		}
		
		sort(e.begin(), e.end());
		
		for (event x : e) {
			CURR += x.delta;
			NANS = max(NANS, CURR);
		}
		
		// END
		CURR = lst[i].val();
		e.clear();
		for (int j=0;j<N;j++) if (lst[i].y != lst[j].y) {
			ll dy = lst[i].y - lst[j].y;
			frac aw = frac(lst[j].x0 - lst[i].x1, dy);
			frac bw = frac(lst[j].x1 - lst[i].x1, dy);
			if(bw < aw)
				swap(aw, bw);
			e.push_back(event(aw,  lst[j].val()));
			e.push_back(event(bw, -lst[j].val()));
		}
		
		sort(e.begin(), e.end());
		
		for (event x : e) {
			//~ printf(":: %lld / %lld \t %lld\n", x.instant.a, x.instant.b, x.delta);
			CURR += x.delta;
			NANS = max(NANS, CURR);
		}
		
		//~ printf("\n");
		
		ANS = max(ANS, NANS);
	}
	
	printf("%lld\n", ANS);
}
