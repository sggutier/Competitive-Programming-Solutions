#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Nodo {
        Nodo* sig[2] = {NULL, NULL};

        ~Nodo() {
            if(sig[0]) delete sig[0];
            if(sig[1]) delete sig[1];
        }
    };

    Nodo raiz;

    void inserta(const int x) {
        Nodo* actual = &raiz;
        for(int i=30; i >= 0; i--) {
            int b = (1 << i) & x? 1 : 0;
            if(actual->sig[b] == NULL) {
                actual->sig[b] = new Nodo();
            }
            actual = actual->sig[b];
        }
    }

    int maxXor(const int x) {
        Nodo* actual = &raiz;
        int ans = 0;
        for(int i=30; i >= 0; i--) {
            int b = (1 << i) & x? 0 : 1;
            if(actual->sig[b] == NULL) {
                b ^= 1;
            }
            ans |= b << i;
            actual = actual->sig[b];
        }
        return ans ^ x;
    }
};

void testCase() {
    int N, x ;
    int acum = 0, ans = 0;
    Trie trie;

    scanf("%d%d", &N, &x);
    for(int i=0, a; i < N; i++) {
        scanf("%d", &a);
        trie.inserta(acum);
        acum ^= a;
        ans = max(ans, trie.maxXor(acum ^ x));
    }

    printf("%d\n", ans ^ x);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--) testCase();
}
