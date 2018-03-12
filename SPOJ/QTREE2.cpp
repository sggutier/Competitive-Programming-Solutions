#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
typedef std::pair<int, int> par;
const int limN = 1e4 + 5;
const int limB = 14;

class Node {
private:
    int dep ;
    int dst;
    Node* prev[limB];
public:
    int id;
    Node() {
    }
    Node(Node *p, int _id, int d) {
        id = _id;
        dst = p->dst + d;
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
    void setAsRoot(int _id) {
        id = _id;
        dst = dep = 0;        
        for(int i=0; i<limB; i++)
            prev[i] = this;
    }
    int getDep() {
        return dep;
    }
    int getID() {
        return id;
    }
    int getDst() {
        return dst;
    }
};

std::vector <par> adj[limN];
Node nodes[limN];

void buildTree(int pos, int prev=-1) {
    for(const par &sig:adj[pos]) {
        if(sig.second==prev)
            continue;
        nodes[sig.second] = Node(&nodes[pos], sig.second, sig.first);
        buildTree(sig.second, pos);
    }
}

Node* LCA(Node* x, Node *y) {
    if(x->getDep() > y->getDep())
        std::swap(x, y);
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
    int N;
    std::map <int, int> reg;
    std::vector <int> revo;

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        adj[i].clear();
    for(int i=1; i<N; i++) {
        int a, b;
        int c;
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        if(reg.count(a)==0) {
            revo.push_back(a);
            reg[a] = reg.size();
        }
        a = reg[a];
        if(reg.count(b)==0) {
            revo.push_back(b);
            reg[b] = reg.size();
        }
        b = reg[b];
        adj[a].push_back(par(c, b));
        adj[b].push_back(par(c, a));
    }

    // for(int i=0; i<N; i++) {
    //     cout << revo[i] << " =>" ;
    //     for(const par &sig:adj[i])
    //         cout << " {" << revo[sig.second] << " " << sig.first << "}" ;
    //                                                                 cout << endl;
    // }
    nodes[0].setAsRoot(0);
    buildTree(0);

    for(int i=0; N>1 && i<N; i++) {
        while(nodes[i].getID()!=i);
    }
    // while(revo.size() < N);

    char str[10];
    //while(scanf("%s", str)!=EOF && str[1]!='O') {
    while(true) {
        scanf("%s", str);
        if(str[1]=='O')
            break;
        int x, y;
        int a, b;
        int c;
        //scanf("%d%d", &x, &y);
        scanf("%d", &x);
        scanf("%d", &y);
        if(str[1]=='I') {
            if(x==y) {
                printf("0\n");
                continue ;
            }
            a = reg[y], b = reg[x];
            c = LCA(&nodes[a], &nodes[b])->getID();
            printf("%d\n", (nodes[a].getDst() - nodes[c].getDst()) + (nodes[b].getDst() - nodes[c].getDst()));
        }
        else {
            int k;
            int da, db, dc;
            scanf("%d", &k);
            if(x==y) {
                printf("%d\n", x);
                continue ;
            }
            a = reg[x], b = reg[y];
            c = LCA(&nodes[a], &nodes[b])->getID();
            k--;
            da = nodes[a].getDep(); db = nodes[b].getDep(); dc = nodes[c].getDep();
            da -= dc;
            db -= dc;
            if(k==da)
                printf("%d\n", revo[c]);
            else if(k<da)
                printf("%d\n", revo[nodes[a].kthPrev(k)->getID()]);
                //printf("7\n");
            else
                printf("%d\n", revo[nodes[b].kthPrev(da+db-k)->getID()]);
            //printf("8\n");
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
