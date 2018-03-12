#include <bits/stdc++.h>
using namespace std;
const int MAX_E = 10005;
#define par pair<int,int>
#define f first
#define s second
#define tri pair<int, par>

struct UFindNode {
    UFindNode *parent = NULL;
    UFindNode *getRoot() {
        if(parent==NULL)
            return this;
        return parent = parent->getRoot();
    }
    bool join(UFindNode *B) {
        UFindNode *A = this->getRoot();
        B = B->getRoot();
        if(A==B)
            return false;
        B->parent = A;
        return true;
    }
};

int kruskal(const int &N, const int &E, tri *edg, bool *usd, int forb=-1) {
    UFindNode uf[N];
    bool cng = forb<0;
    int ans = 0;
    int cnt = 0;

    //printf("here\n");
    for(int i=0; i<E; i++) {
        //printf("Tryna join %d and %d => ",edg[i].s.f+1, edg[i].s.s+1);
        if(i!=forb && uf[edg[i].s.f].join(&uf[edg[i].s.s])) {
            ans += edg[i].f;
            usd[i] |= cng;
            cnt ++;
            //printf("Yup\n");
        }
        //else
        //printf("No\n");
    }
    //printf("\n");

    return cnt==N-1? ans : (1<<30);
}

void testCase() {
    int N, E;
    int aa, ab;
    
    scanf("%d%d", &N, &E);
    tri edg[MAX_E];
    bool usd[MAX_E];
    
    for(int i=0; i<E; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        edg[i] = tri(c, par(a,b));
        usd[i] = false;
    }

    sort(edg, edg+E);
    aa = kruskal(N, E, edg, usd);
    ab = (1<<30);
    for(int i=0; i<E; i++)
        if(usd[i])
            ab = min(ab, kruskal(N, E, edg, usd, i));
    printf("%d %d\n", aa, ab);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
