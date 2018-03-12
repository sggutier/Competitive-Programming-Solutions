#include <bits/stdc++.h>
using namespace std;

struct UFindNode {
    UFindNode* parent;
    int depth;
    UFindNode() {
        parent = NULL;
        depth = 0;
    }
    UFindNode* root() {
        UFindNode* pos = this;
        while(pos->parent != NULL)
            pos = pos->parent;
        return pos;
    }
    int sameSet(UFindNode *b) {
        return this->root() == b->root();
    }
    void join(UFindNode *b) {
        UFindNode *a = this->root();
        b = b->root();
        if(a==b)
            return ;
        if(a ->depth < b->depth)
            swap(a,b);
        a -> depth = max(a->depth, b->depth + 1);
        b -> parent = a;
        return ;
    }
};

void testCase() {
    int n;
    vector <UFindNode*> dict;
    int ans[] = {0, 0};
    char str[500];

    gets(str);
    sscanf(str, "%d", &n);
    dict = vector<UFindNode*>(n+1, NULL);
    while(gets(str) && str[0]!=0 && str[0]!=' ') {
        int a, b;
        char S[5];
        sscanf(str, "%s%d%d", S, &a, &b);
        if(dict[a]==NULL)
            dict[a] = new UFindNode();
        if(dict[b]==NULL)
            dict[b] = new UFindNode();
        if(S[0]=='c')
            dict[a]->join(dict[b]);
        else 
            ans[1 - dict[a]->sameSet(dict[b])] ++;
    }

    for(const auto &d:dict)
        delete d;

    printf("%d,%d\n",ans[0],ans[1]);    
}

int main() {
    char S[500];
    
    int tc;

    gets(S);
    sscanf(S, "%d", &tc);
    if(tc)
        gets(S);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
    
    return 0;
}
