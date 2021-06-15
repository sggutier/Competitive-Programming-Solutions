#include <bits/stdc++.h>
using namespace std;

map <string, string> orgo;

int main() {
    int Q ;
    string A, B, w ;
    cin >> Q ;

    while(Q--) {
        cin >> A >> B ;
        if(orgo.count(A)==0)
            orgo[A] = A;
        auto it = orgo.find(A);
        w = it->second;
        orgo.erase(it);
        orgo[B] = w;
    }

    printf("%d\n", (int) orgo.size());
    for(const auto &p:orgo) {
        cout << p.second << " " << p.first << endl;        
    }
}
