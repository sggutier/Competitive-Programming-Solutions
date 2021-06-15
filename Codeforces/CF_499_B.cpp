#include <bits/stdc++.h>
using namespace std;

int main() {
    map <string, string> dico;
    int N, D ;
    cin >> N >> D;
    while(D--) {
        string a, b ;
        cin >> a >> b ;
        dico[a] = b.size() < a.size()? b : a;
    }

    for(int i=0; i<N; i++) {
        string a ;
        cin >> a ;
        auto it = dico.find(a);
        if(i)
            cout << " " ;
        if(it == dico.end())
            cout << a ;
        else
            cout << it->second ;
    }
    cout << endl;
}
