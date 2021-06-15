#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;

int N, K;
ll pod[limN], cns[limN];
vector<int> ord;
ll ans[limN];

int main() {
    ll sumo = 0;
    priority_queue <ll> Q ;
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%lld", &pod[i]);
    for(int i=0; i<N; i++) {
        ord.push_back(i);
        scanf("%lld", &cns[i]);
    }
    sort(ord.begin(), ord.end(),
         [](const int a, const int b) { return pod[a] < pod[b]; });
    for(const int p : ord) {
        ans[p] = sumo + cns[p];
        Q.push(-cns[p]);
        sumo += cns[p];
        while((int) Q.size() > K) {
            sumo += Q.top();
            Q.pop();            
        }        
    }
    for(int i=0; i<N; i++)
        printf("%lld ", ans[i]);
    printf("\n");
}
