#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int limW = 1005;

struct Nodo {
    int fin = -1;
    Nodo* sigs[26];
    Nodo() {
        memset(sigs, 0, sizeof(sigs));
    }
    void mete(const char *s, const int id) {
        if(*s==0) {
            fin = id;
            return;
        }
        if(!sigs[*s-'a'])
            sigs[*s-'a'] = new Nodo();
        sigs[*s-'a']->mete(s+1, id);
    }
};

string strs[limN];

int main() {
    int N, M;
    char ciph[limN];
    int ans[limN];
    Nodo* tp = new Nodo();

    scanf("%d", &N);
    scanf("%s", ciph);
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        char tmp[limW];
        char *c;
        scanf("%s", tmp);
        strs[i] = tmp;
        for(c=tmp; *c; c++)
            *c = tolower(*c);
        reverse(tmp, c);
        tp->mete(tmp, i);
    }

    ans[N] = 0;
    for(int i=N-1; i>=0; i--) {
        Nodo* pos = tp;
        ans[i] = -1;
        for(int j=i; j<N; j++) {            
            Nodo *sig = pos->sigs[ciph[j]-'a'];
            if(!sig)
                break;
            pos = sig;
            if(pos->fin!=-1 && ans[j+1]!=-1) {
                ans[i] = pos->fin;
                break;
            }
        }
    }

    for(int i=0; i<N; i+=strs[ans[i]].size()) {
        if(i) printf(" ");
        printf("%s", strs[ans[i]].c_str());
    }
    printf("\n");
}
