#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
const int limN = 200;
#define x first
#define y second

class UFN {
public:
    UFN *prev = NULL;
    void join(UFN* b) {
        UFN* a = this->root();
        b = b->root();
        if(a==b)
            return;
        b->prev = a;
    }
    UFN* root() {
        if(prev==NULL)
            return this;
        else
            return prev = prev->root();
    }
};

int dst(const par &A, const par &B) {
    int dx = A.x - B.x ;
    int dy = A.y - B.y ;
    return dx*dx + dy*dy;
}

bool distLT(vector <par> &A, vector <par> &B, const int k) {
    for(const par &a:A)
        for(const par &b:B)
            if(dst(a, b) <= k)
                return true;
    return false;
}

bool testCase() {
    UFN nods[limN];
    vector <par> trees[limN];
    int N, M, k, d;
    scanf("%d%d%d%d", &N, &M, &k, &d);
    k *= k;
    d *= d;
    // for(int i=0; i<N+M; i++) {
    //     printf("%d => %lld\n", i, (long long) nods[i].root());
    // }
    for(int i=0; i<M; i++) {
        int x, y ;
        scanf("%d%d", &x, &y);
        trees[i+N].push_back(par(x,y));
    }
    for(int i=0; i<N; i++) {
        int b ;
        scanf("%d", &b);
        trees[i].resize(b);
        for(int j=0; j<b; j++)
            scanf("%d%d", &trees[i][j].x, &trees[i][j].y);
        // printf("Arbol %d contiene => ", i);
        // for(const par &p:trees[i])
        //     printf("[%d %d] ", p.x, p.y);
        // printf("\n");
        for(int j=0; j<i; j++) {
            if(nods[i].root() == nods[j].root()) {
                //printf("%d y %d mueren aac\n", i, j);
                continue;
            }
            if(distLT(trees[i], trees[j], k)) {
                nods[i].join(&nods[j]);
                //printf("Joining %d and %d\n", i, j);
            }
        }
    }
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(distLT(trees[i+N], trees[j], d)) {
                nods[i+N].join(&nods[j]);
                //printf("Doctor %d near tree %d\n", i, j);
                if(nods[0].root() == nods[i+N].root())
                    return true;
            }
        }
    }
    // for(int i=0; i<N+M; i++) {
    //     printf("%d <=> %lld\n", i, (long long) nods[i].root());
    // }
    return false;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        printf("%s\n", testCase()? "Tree can be saved :)" : "Tree can't be saved :(");
}
