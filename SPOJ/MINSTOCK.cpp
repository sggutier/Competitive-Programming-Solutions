#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;
typedef pair<int,int> pii;
#define f first
#define s second


int W ;
map <string, int> anum;
int curV[limN];
string noms[limN];

int getN(string s) {
    auto it = anum.find(s);
    if(it == anum.end()) {
        noms[W] = s;
        return anum[s] = W++;
    }
    return it->second;
}

set <pii> PQ ;

void quer1(int id, int nv) {
    PQ.erase({curV[id], id});
    curV[id] = nv;
    PQ.insert({curV[id], id});
}

int quer3() {
    int ans = PQ.begin()->s;
    PQ.erase(PQ.begin());
    return ans;
}

int main() {
    int Q ;
    char tmp[15];

    int t, nv;
    scanf("%d", &Q);
    int d = 1;
    while(Q--) {
        scanf("%d%s", &t, tmp);
        if(t < 3) {
            scanf("%d", &nv);
            quer1(getN(tmp), nv);
        }
        else {
            printf("%s %d\n", noms[quer3()].c_str(), d);
        }
        d++;
    }
}

