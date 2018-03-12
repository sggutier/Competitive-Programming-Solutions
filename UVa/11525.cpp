#include <bits/stdc++.h>
using namespace std;

class STNode {
public:
    STNode *lCh = NULL, *rCh = NULL;
    int cnt = 0;
    int get_kth(const int k, const int l, const int r) ;
    STNode(int l, int r);
    ~STNode() ;
};

STNode::~STNode() {
    if(lCh)
        delete lCh;
    if(rCh)
        delete rCh;
}

STNode::STNode(int l, int r) {
    cnt = max(0, r-l);
    if(l+1>=r)
        return;
    int mit = (l+r)>>1;
    lCh = new STNode(l, mit);
    rCh = new STNode(mit, r);
}

int STNode::get_kth(const int k, const int l, const int r) {
    cnt --;
    if(l+1 >= r) {
        return l;
    }
    int mit = (l+r)>>1;
    if(k <= lCh->cnt)
        return lCh->get_kth(k, l, mit);
    else
        return rCh->get_kth(k- lCh->cnt, mit, r);
}

void testCase() {
    STNode *st ;
    int N;
    scanf("%d", &N);
    int tmp ;

    st = new STNode(0, N);

    for(int i=0; i<N; i++) {
        scanf("%d", &tmp);
        if(i)
            printf(" ");
        printf("%d", st->get_kth(tmp+1, 0, N) + 1);
    }
    printf("\n");
    
    delete st;
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
