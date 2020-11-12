#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5;

int toNum(const char a) {
    return a - 'a';
}

struct Trie {
    struct Nodo {
        int cnt;
        Nodo* sig[26];
        Nodo() {
            cnt = 0;
            for(int i=0; i < 26; i++) {
                sig[i] = NULL;
            }
        }
    };
    Nodo raiz;
    multiset<int> reps[LIM_N];

    void insertString(string &s) {
        const char *c = s.c_str();
        Nodo *actual = &raiz;
        int dep = 0;
        auto it = reps[dep].find(-actual->cnt);
        if(it != reps[dep].end())
            reps[dep].erase(it);
        actual->cnt ++;
        reps[dep].insert(-actual->cnt);
        while(*c) {
            int val = toNum(*c);
            if(actual->sig[val] == NULL) {
                actual->sig[val] = new Nodo();
            }
            actual = actual->sig[val];
            c++;
            dep ++;
            it = reps[dep].find(-actual->cnt);
            if(it != reps[dep].end())
                reps[dep].erase(it);
            actual->cnt ++;
            reps[dep].insert(-actual->cnt);
        }
    }

    void deleteString(string &s) {
        const char *c = s.c_str();
        Nodo *actual = &raiz;
        int dep  = 0;
        auto it = reps[dep].find(-actual->cnt);
        if(it != reps[dep].end())
            reps[dep].erase(it);
        actual->cnt --;
        reps[dep].insert(-actual->cnt);
        while(*c) {
            int val = toNum(*c);
            actual = actual->sig[val];
            c++;
            dep ++;
            it = reps[dep].find(-actual->cnt);
            if(it != reps[dep].end())
                reps[dep].erase(it);
            actual->cnt --;
            reps[dep].insert(-actual->cnt);
        }
    }

    bool existsPref(const int k, const int l) {
        if(reps[l].empty()) {
            return false;
        }
        return -(*reps[l].begin()) >= k;
    }
};

Trie trie;
string strs[LIM_N];
bool borrado[LIM_N];

int main() {
    cin.sync_with_stdio();
    cout.sync_with_stdio();
    int Q ;
    cin >> Q ;
    for(int i=0; i < Q; i++) {
        int qt ;
        cin >> qt ;
        if(qt == 1) {
            cin >> strs[i];
            reverse(strs[i].begin(), strs[i].end());
            trie.insertString(strs[i]);
        }
        else if(qt == 2) {
            int k, l ;
            cin >> k >> l ;
            cout << (trie.existsPref(k, l)? "YES\n" : "NO\n") ;
        }
        else if(qt == 3) {
            int qid ;
            cin >> qid;
            qid --;
            if(!borrado[qid]) {
                borrado[qid] = true;
                trie.deleteString(strs[qid]);
            }
        }
    }
}
