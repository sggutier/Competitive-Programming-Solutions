#include <bits/stdc++.h>
using namespace std;

struct UFindNode {
    UFindNode *parent;
    int cnt ;
    UFindNode () {
        cnt = 1;
        depth = 0;
        parent = NULL;
    }
    UFindNode* getRoot() {
        // cout << "gettin root" << endl;
        UFindNode* ans = this;
        while(ans->parent!=NULL)
            ans = ans->parent;
        // cout << "done" << endl;
        return ans;
    }
    int join(UFindNode* b) {
        UFindNode* a = this->getRoot();
        b = b->getRoot();
        if(a==b)
            return a -> cnt;
        if(a->depth < b->depth)
            swap(a, b);
        // int ans = ((int) a->cnt) * b -> cnt;
        a -> cnt += b -> cnt;
        b -> parent = a;
        a -> depth = max(a -> depth, b -> depth + 1);
        // return ans;
        return a -> cnt;
    }
};

void testCase() {
    map <string, UFindNode*> people;
    int qCnt ;

    for(scanf("%d", &qCnt); qCnt; qCnt--) {
        char tmp[25];
        string A, B;
        scanf("%s", tmp); A = tmp;
        scanf("%s", tmp); B = tmp;
        if(people.count(A)==0)
            people[A] = new UFindNode();
        if(people.count(B)==0)
            people[B] = new UFindNode();
        printf("%d\n", people[A] -> join(people[B]));
    }

    for(auto &p:people)
        delete p.second;
}

int main() {
    int tc ;

    for(scanf("%d", &tc); tc; tc--)
        testCase();
    
    return 0;
}
