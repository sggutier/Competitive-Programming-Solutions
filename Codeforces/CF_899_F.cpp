#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 2e5 + 5;
typedef long long ll;
const int LIM_L = 10 + 26 + 26;

int toDig(const char a) {
    if(isdigit(a))
        return a - '0';
    if(islower(a))
        return 10 + a - 'a';
    return 36 + a - 'A';
}

char fromDig(const int a) {
    if(a < 10)
        return a + '0';
    if(a < 36)
        return a - 10 + 'a';
    return a - 36 + 'A';
}

struct STNode {
    STNode *L = NULL, *R = NULL;
    int tot = 0 ;
    bool delCrgs[LIM_L];
    int cntLets[LIM_L] = {0};

    void updCnt() {
        this->tot = this->L->tot + this->R->tot;
        for(int i=0; i < LIM_L; i++)
            this->cntLets[i] = this->L->cntLets[i] + this->R->cntLets[i];
    }

    void push() {
        if(L) {
            for(int i=0; i < LIM_L; i++) {
                if(!delCrgs[i]) {
                    continue;
                }
                tot -= cntLets[i];
                cntLets[i] = 0 ;
                delCrgs[i] = 0 ;
                L->delCrgs[i] = 1 ;
                R->delCrgs[i] = 1 ;
            }
            return ;
        }
        for(int i=0; i < LIM_L; i++) {
            if(!delCrgs[i]) {
                continue;
            }
            tot -= cntLets[i];
            cntLets[i] = 0 ;
            delCrgs[i] = 0 ;
        }
    }

    int deleteRng(int pos, int cnt, int delTgt) {
        push();
        // printf("At %d %d %d,  %d %d with %d\n", pos, cnt, delTgt, L, R, tot);
        if(tot <= pos || cnt == 0) {
            return 0 ;
        }
        if(pos == 0 && tot <= cnt) {
            int vl = tot ;
            delCrgs[delTgt] = 1;
            push();
            // printf("Xinished %d %d %d,  %d %d with %d\n", pos, cnt, delTgt, L, R, vl);
            return vl ;
        }
        int x = this->L->deleteRng(pos, cnt, delTgt);
        pos = max(0, pos - this->L->tot);
        cnt -= x;
        x += this->R->deleteRng(pos, cnt, delTgt);
        updCnt();
        // printf("Finished %d %d %d,  %d %d with %d\n", pos, cnt, delTgt, L, R, x);
        return x ;
    }

    void printTree() {
        push();
        if(!L) {
            for(int i=0; i < LIM_L; i++)
                if(cntLets[i])
                    printf("%c", fromDig(i));
            return ;
        }
        L->printTree();
        R->printTree();
    }
};

struct STree {
    int N ;
    STNode* rt ;

    STNode* buildTree(int L, int R, const char *s) {
        STNode* cur = new STNode();
        if(L == R) {
            cur->cntLets[toDig(s[L])] ++;
            cur->tot ++ ;
            return cur;
        }
        int mit = (L + R) >> 1;
        cur->L = buildTree(L, mit, s);
        cur->R = buildTree(mit+1, R, s);
        cur->updCnt();
        return cur ;
    }

    STree(int _N, char *s) : N(_N) {
        rt = buildTree(0, N-1, s);
    }

    void deleteRng(int l, int r, int delTgt) {
        rt->deleteRng(l, r-l+1, delTgt);
    }

    void printTree() {
        // printf(">>>> ");
        rt->printTree();
        printf("\n");
        // printf("\n\n");
    }
};

int main() {
    int N, Q ;
    char tmp[LIM_N];
    STree* st ;

    scanf("%d%d", &N, &Q);
    scanf("%s", tmp);
    st = new STree(N, tmp);
    for(int i=0, a, b; i < Q; i++) {
        scanf("%d%d%s", &a, &b, tmp);
        a--, b--;
        st->deleteRng(a, b, toDig(tmp[0]));
        // st->printTree();
    }

    st->printTree();
}
