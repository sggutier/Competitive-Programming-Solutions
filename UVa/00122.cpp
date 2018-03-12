#include <bits/stdc++.h>
using namespace std;
const int inf = (1<<30);
const int limN = 500;

int ansSiz = 0;
pair< int,pair<int,int> > ans[limN];

struct nodo {
    nodo *L=NULL, *R=NULL;
    vector<int> vals;
    nodo() {
    }
    ~nodo() {
        delete L;
        delete R;
    }
    void construye(char *str, int val) {
        if(*str) {
            if(*str=='L' && L==NULL)
                L = new nodo();
            if(*str=='R' && R==NULL)
                R = new nodo();
            if(*str=='L')
                L -> construye(str+1, val);
            else
                R -> construye(str+1, val);
        }
        else
            vals.push_back(val);
    }
    bool completo(int dep=0) {
        if((int) vals.size()!=1)
            return false;
        for(const int &v:vals) {
            ans[ansSiz] = make_pair(dep, make_pair(ansSiz, v));
            ansSiz ++;
        }
        return (L==NULL || L->completo(dep+1)) && (R==NULL || R->completo(dep+1));
    }
};

bool leeBasura() {
    int c;
    while(true) {
        c = getchar();
        if(c==EOF)
            return false;
        if(c=='(')
            break;
    }
    return true;
}

bool leeNum(int &n) {
    n = 0;
    char c;
    while(true) {
        c = getchar();
        if(c==',' || c==')')
            break;
        n = n*10 + c - '0';
    }
    if(n==0)
        n = -inf;
    return c==',';
}

void leeStr(char *s) {
    while(true) {
        *s = getchar();
        if(*s==')' ) {
            *s=0;
            break;
        }
        s++;
    }
}

int main() {
    nodo *A = new nodo();
    char str[limN];
    int n;

    while(leeBasura()) {
        if( leeNum(n) ) {
            leeStr(str);
            A->construye(str, n);
            // printf("%s %d\n", str, n);
        }
        else {
            if(A -> completo()) {
                sort(ans, ans+ansSiz);
                for(int i=0; i<ansSiz; i++) {
                    if(i)
                        printf(" ");
                    printf("%d", ans[i].second.second);
                }
                printf("\n");
            }
            else
                printf("not complete\n");            
            delete A;
            A = new nodo();
            ansSiz = 0;
        }
    }
}
