#include <bits/stdc++.h>
using namespace std;
const int LIM_D = 26;

inline int toNum(const char c) {
    return c - 'a';
}

inline int toCha(const int a) {
    return a + 'a';
}

struct Trie {
    struct Nodo {
        bool finalPalabra;
        int palMax ;
        map<int, Nodo*> sig;
    };

    Nodo raiz;
    vector <char> ans;

    void inserta(const char *c, Nodo *actual) {
        if(*c == 0) {
            actual->finalPalabra = true;
            return;
        }
        int val = toNum(*c);
        if(!actual->sig.count(val)) {
            actual->sig[val] = new Nodo();
        }
        inserta(c+1, actual->sig[val]);
        actual->palMax = max(actual->palMax, actual->sig[val]->palMax + 1);
    }

    void inserta(const string &S) {
        inserta(S.c_str(), &raiz);
    }

    void imprime(const Nodo *actual) {
        static vector<function<bool(int,int)>> fncs = {
            [](const int act, const int mv) {return act == mv;},
            [](const int act, const int mv) {return act != mv;}
        };
        if(actual->finalPalabra) {
            ans.push_back('P');
        }
        const int mv = actual->palMax - 1;
        for(const auto &f : fncs) {
            for(const auto &p : actual->sig) {
                const Nodo* sig = p.second;
                if(f(sig->palMax, mv)) continue;
                const int i = p.first;
                ans.push_back(toCha(i));
                imprime(sig);
                ans.push_back('-');
            }
        }
    }

    vector<char> imprime() {
        ans.clear();
        imprime(&raiz);
        return ans;
    }
};

Trie trie;

int main() {
    cin.sync_with_stdio(true);
    cout.sync_with_stdio(true);
    int N ;
    string S ;

    cin >> N ;
    for(int i=0; i < N; i++) {
        cin >> S;
        trie.inserta(S);
    }
    auto ans = trie.imprime();

    int lastC = ans.size();
    for(lastC--; ans[lastC] == '-'; lastC--);
    lastC++;
    cout << lastC << '\n';
    for(int i=0; i < lastC; i++) {
        cout << ans[i] << '\n';
    }
}
