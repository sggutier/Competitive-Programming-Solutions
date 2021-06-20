#include <bits/stdc++.h>
using namespace std;

class Treap {
private:
    int y;
    int cost;
    Treap(int y, int cost, Treap* left = NULL, Treap* right = NULL) {
        this->y = y;
        this->cost = cost;
        this->left = left;
        this->right = right;
    }
public:
    Treap *left;
    Treap *right;
    int size = 1;
    static int SizeOf(Treap* treap) {
        return treap == NULL? 0 : treap->size;
    }
    void recalc() {
        size = SizeOf(left) + SizeOf(right) + 1;
    }
    void Split(int x, Treap* &L, Treap* &R) {
        Treap* newTree = NULL;
        int curIndex = SizeOf(left) + 1;
        if(curIndex <= x) {
            if(right == NULL)
                R = NULL;
            else
                right->Split(x - curIndex, newTree, R);
            L = new Treap(y, cost, left, newTree);
            L -> recalc();
        }
        else {
            if(left == NULL)
                L = NULL;
            else
                left->Split(x, L, newTree);
            R = new Treap(y, cost, newTree, right);
            R -> recalc();
        }
    }
    static Treap* Merge(Treap *L, Treap *R) {
        if(L==NULL)
            return R;
        if(R==NULL)
            return L;

        if(L->y > R->y) {
            Treap *newR = Merge(L->right, R);
            return new Treap(L->cost, L->y, L->left, newR);
        }
        else {            
            Treap *newL = Merge(L, R->left);
            return new Treap(R->cost, R->y, newL, R->right);
        }
    }
    Treap* Add(int pos, int cost) {
        Treap *L, *R;
        Split(pos, L, R);
        Treap *m = new Treap(rand(), cost);
        return Merge(Merge(L, m), R);
    }

    Treap* Remove(int pos) {
        Treap *l, *m, *r;
        Split(pos, l, r);
        r->Split(1, m, r);
        delete m;
        return Merge(l, r);
    }
    
    int KthElement(int K) {
        Treap* cur = this;
        while (cur != NULL) {
            int sizeLeft = SizeOf(cur->left);

            if (sizeLeft == K)
                return cur->cost;

            cur = sizeLeft > K ? cur->left : cur->right;
            if (sizeLeft < K)
                K -= sizeLeft + 1;
        }
        return -1;
    }
};

int main() {
}
