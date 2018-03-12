#include <bits/stdc++.h>
using namespace std;

struct UFindNode {
    UFindNode* parent;
    int depth ;
    UFindNode() {
        parent = NULL;
        depth = 0;
    }
    UFindNode* getRoot() {
        if(this->parent==NULL)
            return this;        
        return this->parent = parent->getRoot();
    }
    bool join(UFindNode* b) {
        UFindNode* a = this->getRoot();
        b = b->getRoot();
        if(a==b) 
            return false;
        if(a->depth < b->depth)
            swap(a,b);
        a->depth = max(a->depth, b->depth+1);
        b->parent = a;
        return true;
    }
};

void testCase(int nodeCnt, int edgeCnt) {
    vector <UFindNode> nodes(nodeCnt);
    int ans = nodeCnt;
    while(edgeCnt--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(nodes[a-1].join(&nodes[b-1]))
            ans--;
    }
    printf("%d\n", ans);
}

int main() {
    int a, b;
    int tc=0;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        printf("Case %d: ", ++tc);
        testCase(a,b);
    }
    
    return 0;
}
