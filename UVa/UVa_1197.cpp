#include <bits/stdc++.h>
using namespace std;

struct uFindNode {
    int tam = 1;
    uFindNode *parent = NULL;
    uFindNode *root() {
        if(parent==NULL)
            return this;
        return parent = parent -> root();
    }
    bool join(uFindNode *B) {
        uFindNode* A = this -> root();
        B = B -> root();
        if(A == B)
            return false;
        B -> parent = A;
        A -> tam += B -> tam;
        return true;
    }
};

void testCase(    int nodeCnt, int gCnt) {
    vector <uFindNode> stu(nodeCnt);

    for(int i=0; i<gCnt; i++) {
        int k, g;
        scanf("%d", &k);
        for(int j=0; j<k; j++) {
            int w ;
            scanf("%d", &w);
            if(!j)
                g = w;
            stu[g].join(&stu[w]);
        }
    }

    printf("%d\n", stu[0].root() -> tam);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
    
    return 0;
}
