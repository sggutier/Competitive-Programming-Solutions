#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5;

set <int> avil;
vector <int> adj[LIM_N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int N, E ;
    int ans = 0 ;
    queue <int> Q ;
    cin >> N >> E ;
    for(int i=0, a, b; i < E; i++) {
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    for(int i=1; i <= N; i++)
        avil.insert(i);
    while(!avil.empty()) {
        Q.push(*avil.begin());
        avil.erase(avil.begin());
        while(!Q.empty()){
            int pos = Q.front(); Q.pop();
            // cout << pos << endl << "\t";
            auto &vs = adj[pos];
            auto itAvil = avil.begin();
            auto itAdj = vs.begin();
            while(itAvil != avil.end() && itAdj != vs.end()) {
                // cout << "(" << *itAdj << ") " ;
                while(itAvil != avil.end() && *itAvil < *itAdj) {
                    // cout << *itAvil << " " ;
                    ans ++;
                    Q.push(*itAvil);
                    itAvil = avil.erase(itAvil);
                }
                itAvil = avil.upper_bound(*itAdj);
                itAdj ++;
            }
            while(itAvil != avil.end()) {
                // cout << *itAvil << " " ;
                ans ++;
                Q.push(*itAvil);
                itAvil = avil.erase(itAvil);
            }
            // cout << endl;
        }
        // cout << "--------------" << endl;
    }
    printf("%d\n", N-1-ans);
}
