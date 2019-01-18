#include <bits/stdc++.h>
using namespace std;

vector<int> criba(int MAXN) {
	vector<int> ans, u(MAXN + 1);
	
	for(int i = 2; i <= MAXN; i++) if(!u[i]) {
		ans.push_back(i);
		for(int j = i * i; j <= MAXN; j += i)
			u[j] = true;
	}
	
	return ans;
}

int N;
vector<int> pr;

bool isprime(int N) {
	if (N < 2) return false;
	for (int p : pr) {
		if (p >= N) break;
		if (N % p == 0)
			return false;
	}
	return true;
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	pr = criba(3250);
	
	scanf("%d", &N);
	
	for(int i = 0 ; i < (int)pr.size(); i++) {
		int p = pr[i];		
		if (N % p != 0) continue;		
		int c = N / p;
		
		for(int j = i + 1; j < (int)pr.size(); j++) {
			int q = pr[j];
			if (c % q != 0) continue;
			int r = c / q;
			
			if (r != p && r != q && isprime(r)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
			return 0;
		}
		
		printf("NO\n");
		return 0;
	}
	
	printf("NO\n");
	
	return 0;
}
