#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;
const int limB = 11;

class Node {
private:
    int dep ;
    int id;
    Node* prev[limB];
public:
    Node() {
    }
    Node(Node *p, int _id) {
        id = _id;
        prev[0] = p;
        dep = p->dep + 1;
        for(int i=0; i<limB; i++) {
            prev[i] = p;
            p = p->prev[i];
        }
    }
    Node* kthPrev(int k) {
        Node* pos = this;
        for(int i=0; i<limB; i++)
            if((1<<i) & k)
                pos = pos->prev[i];
        return pos;
    }
    void setAsRoot() {
        dep = 0;
        for(int i=0; i<limB; i++)
            prev[i] = this;
    }
    int getDep() {
        return dep;
    }
    int getID() {
        return id;
    }
};

vector <int> adj[limN];
Node nodes[limN];

void buildTree(int pos) {
    for(const int &sig:adj[pos]) {
        nodes[sig] = Node(&nodes[pos], sig);
        buildTree(sig);
    }
}

Node* LCA(Node* x, Node *y) {
    if(x->getDep() > y->getDep())
        swap(x, y);
    y = y->kthPrev(y->getDep() - x->getDep());
    int ini=0, fin=x->getDep();
    while(ini < fin) {
        int piv = (ini+fin)/2;
        if(x->kthPrev(piv) == y->kthPrev(piv))
            fin = piv;
        else
            ini = piv+1;
    }
    return x->kthPrev(ini);
}

void testCase() {
    int N, Q;
    vector <int> ancCnt;

    scanf("%d", &N);
    ancCnt.resize(N);
    for(int i=0; i<N; i++) {
        int w;        
        adj[i].clear();
        scanf("%d", &w);
        while(w--) {
            int a ;
            scanf("%d", &a);
            a--;
            adj[i].push_back(a);
            ancCnt[a]++;
        }
    }

    for(int i=0; i<N; i++) {
        if(ancCnt[i]==0) {
            nodes[i].setAsRoot();
            buildTree(i);
            break;
        }
    }

    scanf("%d", &Q);
    while(Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        Node* ans = LCA(&nodes[a-1], &nodes[b-1]);
        printf("%d\n", ans->getID() + 1);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d:\n", i);
        testCase();
    }
}
