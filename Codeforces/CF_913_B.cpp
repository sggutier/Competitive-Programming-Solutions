#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

vector <int> adj[limN];

bool isSpruc(int pos) {
    if(adj[pos].empty())
        return true;
    int cnt = 0;
    for(const int &sig:adj[pos]) {
        if(adj[sig].empty())
            cnt ++;
    }
    if(cnt < 3)
        return false;
    for(const int &sig:adj[pos]) {
        if(!isSpruc(sig))
            return false;
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i=2; i<=N; i++) {
        int a ;
        scanf("%d", &a);
        adj[a].push_back(i);
    }    
    printf("%s\n", isSpruc(1)? "Yes" : "No");
}
