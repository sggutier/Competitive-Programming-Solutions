#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

class node {
public:
    //    int nodID ;
    
    int crg ;
    node *l, *r ;
    node(int count, node *left, node *right): crg(count), l(left), r(right) {
        // static int nodCnt = 0;
        // nodID = nodCnt;
        // // cout << "creatin' " << nodCnt++ ;
        // if(this->l!=NULL)
        //     cout << "(children are " << this->l->nodID << " and " << this->r->nodID << ")" ;
        // cout << endl;
    }
    
    node* insert(int l, int r, int pos) ;
};

node* nullNode = new node(0, NULL, NULL);

node* node::insert(int l, int r, int pos) {
    if(l<=pos && pos<r) {
        if(l+1==r) {
            return new node(this->crg + 1, nullNode, nullNode);
        }
        int m = (l + r)>>1;
        return new node(this->crg + 1,
                        this->l->insert(l, m, pos),
                        this->r->insert(m, r, pos));
    }
    return this;
}

void destroyTree(int l, int r, int pos, node *nod) {
    // printf("%d -> %d -> %d (%d)\n", l, r, pos, nod -> nodID);
    if(l<=pos && pos<r) {
        if(l+1==r) {
            // return new node(this->crg + 1, nullNode, nullNode);
            // cout << "deletin' " << nod->nodID << endl;
            delete nod;
            return ;
        }
        int m = (l + r)>>1;
        destroyTree(l, m, pos, nod->l);
        destroyTree(m, r, pos, nod->r);
        // cout << "deletin' " << nod->nodID << endl;
        delete nod;
        return ;
    }
    // cout << "deletin' " << this->nodID << endl;
    // if(this->l != nullNode)
    //     delete this->l;
    // if(this->r != nullNode)
    //     delete this->r;
}

int findKth(node* leftNode, node* rightNode, int l, int r, int k) {
    if(l+1==r)
        return l;
    int m = (l+r)>>1;
    int leftSideCrg = (rightNode -> l -> crg) - (leftNode -> l -> crg);
    if(leftSideCrg>=k)
        return findKth(leftNode -> l, rightNode -> l, l, m, k);
    else
        return findKth(leftNode -> r, rightNode -> r, m, r, k - leftSideCrg);
}



int nums[limN];
node* segTreeRoots[limN];
map<int,int> dict;
int revDict[limN];

void testCase(int numCnt, int qCnt) {
    int permCnt = 0;
    
    for(int i=1; i<=numCnt; i++) {
        scanf("%d", &nums[i]);
        dict[nums[i]] = 0;
    }

    for(auto &de:dict) {
        de.second = permCnt;
        revDict[permCnt] = de.first;
        permCnt ++;
    }

    for(int i=1; i<=numCnt; i++) {
        segTreeRoots[i] = segTreeRoots[i-1]->insert(0, permCnt, dict[nums[i]]);
    }

    for(; qCnt; qCnt--) {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        printf("%d\n", revDict[findKth(segTreeRoots[a-1], segTreeRoots[b], 0, permCnt, k)]);
    }


    for(int i=1; i<=numCnt; i++)
        destroyTree(0, permCnt, dict[nums[i]], segTreeRoots[i]);
    dict.clear();
}

int main() {
    nullNode -> l = nullNode -> r = nullNode;
    segTreeRoots[0] = nullNode;

    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF) {
        testCase(a, b);
    }
    
    return 0;
}
