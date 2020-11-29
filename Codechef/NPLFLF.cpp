#include <bits/stdc++.h>
using namespace std;
const int LIM_C = 26;
const int LIM_N = 1e5 + 5;

inline int toNum(const char c) {
    return c - 'a';
}

struct Trie {
    struct Nodo {
        int cnt ;
        Nodo* sig[LIM_C];

        Nodo() {
            cnt = 0;
            for(int i=0; i < LIM_C; i++) {
                sig[i] = NULL;
            }
        }
    };

    Nodo raiz;
    multiset <int> crgs[LIM_N];

    void insertString(const string &s) {
        Nodo *actual = &raiz;
        int dep = 0;

        actual->cnt ++;
        for(const auto &i : s) {
            const auto c = toNum(i);
            if(actual->sig[c] == NULL) {
                actual->sig[c] = new Nodo();
            }
            actual = actual->sig[c];
            dep ++;
            auto it = crgs[dep].find(-actual->cnt);
            if(it != crgs[dep].end())
                crgs[dep].erase(it);
            actual->cnt ++;
            crgs[dep].insert(-actual->cnt);
        }
    }

    void deleteString(const string &s) {
        Nodo *actual = &raiz;
        int dep = 0;
        actual->cnt --;
        for(const auto &i : s) {
            const auto c = toNum(i);
            actual = actual->sig[c];
            dep ++;
            auto it = crgs[dep].find(-actual->cnt);
            if(it != crgs[dep].end())
                crgs[dep].erase(it);
            actual->cnt --;
            crgs[dep].insert(-actual->cnt);
        }
    }

    bool existsGroup(const int k, const int l) {
        if(crgs[l].empty()) return false;
        auto it = crgs[l].begin();
        return -*it >= k ;
    }
};

int main() {
    cin.sync_with_stdio();
    cout.sync_with_stdio();
    int Q, tq ;
    string S[LIM_N] ;
    Trie trie ;

    cin >> Q ;
    for(int i=0; i < Q; i++) {
        cin >> tq;
        if(tq == 1) {
            cin >> S[i];
            reverse(S[i].begin(), S[i].end());
            trie.insertString(S[i]);
        }
        else if(tq == 2) {
            int k, l;
            cin >> k >> l;
            cout << (trie.existsGroup(k, l)? "YES\n" : "NO\n");
        }
        else if(tq == 3) {
            int d ;
            cin >> d ;
            d --;
            if(S[d].length()) {
                trie.deleteString(S[d]);
                S[d] = "";
            }
        }
    }
}
