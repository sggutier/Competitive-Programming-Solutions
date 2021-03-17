#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5 ;

struct Node {
    int key ;
    Node *L = NULL, *R = NULL ;
    int minV, maxV;
    Node(int k = 0): key(k),minV(k),maxV(k) {}
};

Node* tree[LIM_N];

void dfsBas(Node* cur) {
    if(cur->L) {
        dfsBas(cur->L);
        cur->minV = cur->L->minV;
    }
    if(cur->R) {
        dfsBas(cur->R);
        cur->maxV = cur->R->maxV;
    }
    // printf("%d => %d %d\n", cur->key, cur->minV, cur->maxV);
}

map <int, double> ans;

void dfs(const Node* cur, int numK = 0, double sm = 0, const int minV = 0, int maxV = 1e9) {
    if(cur->L == NULL) {
        //  printf("%d %d => %.3lf\n", minV, maxV, sm / numK);
        ans[minV] = sm / numK;
        return ;
    }
    dfs(cur->L, numK + 1, sm + cur->R->minV, minV, min(maxV, cur->key - 1));
    dfs(cur->R, numK + 1, sm + cur->L->maxV, max(minV, cur->key + 1), maxV);
}

int main() {
    int N, Q ;
    int rt = -1;
    scanf("%d", &N);
    int as[LIM_N];
    for(int i=1, a, b; i <= N; i++) {
        scanf("%d%d", &a, &b);
        tree[i] = new Node(b);
        as[i] = a ;
    }
    for(int i=1; i <= N; i++) {
        int a = as[i];
        if(a == -1) {
            rt = i ;
            continue;
        }
        if(tree[i]->key < tree[a]->key)
            tree[a]->L = tree[i];
        else
            tree[a]->R = tree[i];
    }
    dfsBas(tree[rt]);
    dfs(tree[rt]);

    scanf("%d", &Q);
    for(int i=0, a; i < Q; i++) {
        scanf("%d", &a);
        auto it = ans.upper_bound(a);
        if(it != ans.begin())
            it -- ;
        printf("%.9lf\n", it->second);
    }
}
