#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

struct item {
    int val, prior;
    int cnt;
    item *l, *r;
    item() {
    }
    item(int val) : val(val), prior(random()), cnt(1), l(NULL), r(NULL) {}
};
typedef item* pitem;

int cnt(pitem t) {
    return t? t->cnt : 0;
}

void updCnt(pitem t) {
    if(t)
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void merge(pitem &t, pitem l, pitem r) {
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    updCnt(t);
}

int erase(pitem &t, int k) {
    if(!t)
        return -1;
    int ans, pos = cnt(t->l) + 1;
    if(k == pos) {
        ans = t->val;
        pitem w ;
        merge(w, t->l, t->r);
        delete t;
        t = w;
    }
    else if(k<pos)
        ans = erase(t->l, k);
    else
        ans = erase(t->r, k-pos);
    updCnt(t);
    return ans;
}

// void printa(pitem t) {
//     if(t==NULL)
//         return;
//     printf("%d (%d) =>", t->val, cnt(t));
//     if(t->l)
//         printf(" %d", t->l->val);
//     else
//         printf(" x");
//     if(t->r)
//         printf(" %d", t->r->val);
//     else
//         printf(" x");
//     printf("\n");
//     printa(t->l);
//     printa(t->r);
// }

void testCase(int n, int *arr) {
    pitem t = NULL;
    for(int i=1; i<=n; i++)
        merge(t, t, new item(i));
    // printf("Arbol\n");
    // printa(t);
    for(int i=n-1; i>=0; i--) {
        arr[i] = erase(t, arr[i]);
        // printf("Arbol\n");
        // printa(t);
    }
    for(int i=0; i<n; i++) {
        if(i)
            printf(" " );
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    srandom(time(NULL));
    int tc;
    int N;
    int arr[limN];
    scanf("%d", &tc);
    for(int t=1; t<=tc; t++) {
        printf("Test : %d\n", t);
        bool works = true;
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            scanf("%d", &arr[i]);
            if(arr[i] > i)
                works = false;
            else
                arr[i] = (i+1)-arr[i];
            //printf("%d ", arr[i]);
        }
        //printf("\n");
        if(works)
            testCase(N, arr);
        else
            printf("-1\n");
    }
}
    
