#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
const int limN = 1e5 + 5;
const int limB = 14;

vector <par> adj[limN];
bool usd[limN];

void buildTree(int pos, int prev=-1) {
    for(const par &sig:adj[pos]) {
        if(usd[sig.second])
            continue;
        usd[sig.second] = true;
        buildTree(sig.second, pos);
    }
}

void testCase() {
    memset(usd, 0, sizeof(usd));
    int N;
    map <string, int> reg;
    vector <string> revo;

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        adj[i].clear();
    for(int i=1; i<N; i++) {
        char X[10000], Y[10000];
        int a, b;
        //int c;
        long long c;
        scanf("%s%s%lld", X, Y, &c);
        if(reg.count(X)==0) {
            revo.push_back(X);
            reg[X] = reg.size();
        }
        a = reg[X];
        if(reg.count(Y)==0) {
            revo.push_back(Y);
            reg[Y] = reg.size();
        }
        b = reg[Y];
        adj[a].push_back(par(c, b));
        adj[b].push_back(par(c, a));
    }

    usd[0] = true;
    buildTree(0);

    for(int i=0; i<N; i++) {
        while(!usd[i]);
    }
    // while(revo.size() < N);

    // for(int i=0; i<N; i++) {
    //     cout << revo[i] << " =>" ;
    //     for(const par &sig:adj[i])
    //         cout << " {" << revo[sig.second] << " " << sig.first << "}" ;
    //                                                                 cout << endl;
    // }

    char str[10];
    while(scanf("%s", str)!=EOF && str[1]!='O') {
        char x[100], y[100];
        scanf("%s%s", x, y);
        if(str[1]=='I') {
            if(true || x==y) {
                printf("0\n");
                continue ;
            }
        }
        else {
            int k;
            scanf("%d", &k);
            if(true || x==y) {
                printf("%s\n", x);
                continue ;
            }
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        testCase();
        printf("\n");
    }
}
