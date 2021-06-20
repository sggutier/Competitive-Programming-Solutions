#include <bits/stdc++.h>
using namespace std;

class UFindNode {
private:
    UFindNode* parent;
    int tam;
public:
    UFindNode() {
        parent = NULL;
        tam = 1;
    }
    UFindNode* root() {
        if(this->parent==NULL)
            return this;
        return parent = this->parent->root();
    }
    int join(UFindNode* b) {
        UFindNode* a = this->root();
        b = b->root();
        if(a==b) {
            return a->tam;
        }
        b -> parent = a;
        return a -> tam += b->tam;
    }
};

void testCase(int animCnt, int querCnt) {
    map <string, int> dict;
    vector <UFindNode> nods(animCnt);
    for(int i=0; i<animCnt; i++) {
        char tmp[35];
        scanf("%s", tmp);
        dict[tmp] = i;
    }
    int ans = 1;
    while(querCnt--) {
        char tmpA[35], tmpB[35];
        int a, b;
        scanf("%s%s", tmpA, tmpB);
        a = dict[tmpA], b = dict[tmpB];
        ans = max(ans, nods[a].join(&nods[b]));
    }
    printf("%d\n", ans);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b) ){
        testCase(a,b);
    }
    
    return 0;
}
