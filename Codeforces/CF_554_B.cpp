#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    map <string, int> dico;
    string tmp;
    int ans = 0;

    cin >> N ;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        ans = max(ans, ++dico[tmp]);
    }

    printf("%d\n", ans);
}
