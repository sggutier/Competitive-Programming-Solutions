#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second
const int LIM_N = 1e5 + 5 ;

int N, P ;
pii pts[LIM_N];
vector<int> fils[LIM_N];

int main() {
	vector <int> ans ;
	set <int, function<bool(const int,const int)>> st(
		[](const int a, const int b) {
			return pts[a] < pts[b];
		});

	scanf("%d", &N);
	scanf("%d", &P);
	for(int i=0; i < P; i++) {
		scanf("%d%d", &pts[i].x, &pts[i].y);
		fils[pts[i].y].push_back(i);
	}

	for(int r=N, c=1; c <= N; c++, r--) {
		while(!st.empty() && pts[*st.begin()].x < c) {
			st.erase(st.begin());
		}
		for(const int x : fils[r])
			st.insert(x);
		if(!st.empty()) {
			// printf("%d %d => %d\n", r, c, *st.begin() + 1);
			ans.push_back(*st.begin());
			st.erase(st.begin());
		}
	}

	printf("%d\n", (int) ans.size());
	for(const int x : ans)
		printf("%d ", x + 1);
	printf("\n");
}
