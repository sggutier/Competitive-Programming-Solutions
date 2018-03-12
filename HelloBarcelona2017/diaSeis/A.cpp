#include <cstdio>
#include <ctime>
#include <random>
using namespace std;

struct TreapNode {
    int key, priority;
    TreapNode *L, *R;
    TreapNode() {
    }
    TreapNode(int k) {
        key = k;
        priority = rand();
        L = R = NULL;
    }
    TreapNode* rightRotate() {
        TreapNode *x = L, *T2 = x->R;
        x->R = this;
        L = T2;
        return x;
    }
    TreapNode* leftRotate() {
        TreapNode *y = R, *T2 = y->L;
        y->L = this;
        R = T2;
        return y;
    }    
};

class Treap {
private:
    TreapNode* prev(int key, TreapNode* r) {
        TreapNode* ans = NULL;
        while(r!=NULL) {
            if(key > r->key) {
                ans = r;
                r = r->R;
            }
            else if(key <= r->key) {
                r = r->L;
            }
        }
        return ans;
        // if(r==NULL)
        //     return r;
        // //printf("Prev at %d %d\n", r->key, r->priority);
        // if(key > r->key) { 
        //     if(r->R) {
        //         TreapNode* t = prev(key, r->R);
        //         if(t && t->key < key)
        //             r = t;
        //     }
        //     return r;
        // }
        // return prev(key, r->L);
    }
    TreapNode* next(int key, TreapNode* r) {
        TreapNode* ans = NULL;
        while(r!=NULL) {
            if(key >= r->key) {
                r = r->R;
            }
            else if(key < r->key) {
                ans = r;
                r = r->L;
            }
        }
        return ans;
        // if(r==NULL)
        //     return r;
        // //printf("Next at %d %d\n", r->key, r->priority);
        // if(key < r->key) { 
        //     if(r->L) {
        //         TreapNode* t = next(key, r->L);
        //         if(t && t->key > key)
        //             r = t;
        //     }
        //     return r;
        // }
        // return next(key, r->R);
    }
    TreapNode* search(int key, TreapNode* r) {
        while(r!=NULL && r->key != key) {
            r = key < r->key? r->L : r->R;
        }
        return r;
        // if(r==NULL || r->key == key)
        //     return r;
        // return search(key, key < r->key? r->L : r->R);
    }
    TreapNode* insert(int key, TreapNode* r) {
        if(r==NULL) {
            return new TreapNode(key);
        }
        if(key < r->key) {
            r->L = insert(key, r->L);
            if(r->L->priority > r->priority)
                r = r->rightRotate();
        }
        else if(key > r->key) {
            r->R = insert(key, r->R);
            if(r->R->priority > r->priority)
                r = r->leftRotate();
        }
        return r;
    }
    TreapNode* deleteNod(int key, TreapNode* r) {
        if(r==NULL)
            return r;
        else if(r->key > key)
            r->L = deleteNod(key, r->L);
        else if(r->key < key)
            r->R = deleteNod(key, r->R);
        else if(r->L == NULL) {
            TreapNode* tmp = r->R;
            delete(r);
            r = tmp;
        }
        else if(r->R == NULL) {
            TreapNode* tmp = r->L;
            delete(r);
            r = tmp;
        }
        else if(r->L->priority   <   r->R->priority) {
            r = r->leftRotate();
            deleteNod(key, r->L);
        }
        else {
            r = r->rightRotate();
            deleteNod(key, r->R);
        }
        return r;
    }
public:
    TreapNode* root = NULL;
    TreapNode* prev(int key) {
        return this->prev(key, root);
    }
    TreapNode* next(int key) {
        return this->next(key, root);
    }
    TreapNode* search(int key) {
        return this->search(key, root);
    }
    void insert(int key) {
        root = this->insert(key, root);
        //root = new TreapNode(key);
    }
    void deleteNod(int key) {
        root = deleteNod(key, root);
    }
    void printa(TreapNode* r) {
        if(r==NULL)
            return;
        printf("(%d %d) ", r->key, r->priority);
        printf("[");
        printa(r->L);
        printf("]  {");
        printa(r->R);
        printf("}");
    }
    void printa() {
        printa(root);
        printf("\n");
    }
};

int main() {
    srand (time(NULL));
    Treap tr;
    char tmp[15];
    int n ;
    while(scanf("%s%d", tmp, &n)!=EOF) {
        if(tmp[0]=='i') {
            tr.insert(n);
        }
        else if(tmp[0]=='d') {
            tr.deleteNod(n);
        }
        else if(tmp[0]=='e') {
            printf("%s\n", tr.search(n)==NULL? "false" : "true");
        }
        else if(tmp[0]=='n') {
            TreapNode* t = tr.next(n);
            if(t)
                printf("%d\n", t->key);
            else
                printf("none\n");
        }
        else if(tmp[0]=='p') {
            TreapNode* t = tr.prev(n);
            if(t)
                printf("%d\n", t->key);
            else
                printf("none\n");
        }
        else {
            //tr.printa();
            printf("*shrugs*\n");
        }
    }
}
