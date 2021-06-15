#include <bits/stdc++.h>
using namespace std;
const int limC = 26;
const int limN = 1e5 + 5;

struct Nodo {
    Nodo* sigs[limC];
    Nodo() {
        for(int i=0; i<limC; i++)
            sigs[i] = NULL;
    }
    void mete(char *s) {
        Nodo* pos = this;
        while(*s) {
            if(pos->sigs[*s - 'a'] == NULL)
                pos->sigs[*s - 'a'] = new Nodo();
            pos = pos->sigs[*s - 'a'];
            s++;
        }
    }
    int gana() {
        for(int i=0; i<limC; i++)
            if(sigs[i] && !sigs[i]->gana())
                return 1;
        return 0;
    }
    int gana2() {
        int cld = 0;
        for(int i=0; i<limC; i++) {
            if(sigs[i])
                cld ++;
            if(sigs[i] && !sigs[i]->gana2())
                return 1;
        }        
        return cld? 0 : 1 ;
    }
};

Nodo* rt = new Nodo();

int main() {
    int N, K;
    char str[limN];
    int ans, ans2;
    
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%s", str);
        rt->mete(str);
    }

    ans = rt->gana();
    ans2 = rt->gana2();

    if(ans) {
        if(ans2)
            ans = 0;
        else
            ans = K%2? 0 : 1;
    }
    else {
        ans = 1;
    }

    printf("%s\n", ans? "Second" : "First");
}
