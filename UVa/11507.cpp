#include <bits/stdc++.h>
using namespace std ;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    while(scanf("%d", &n), n) {
        char tmp[5];
        char dr[] = "+x";
        for(int i=1; i<n; i++) {
            scanf("%s", tmp);
            if(tmp[0]=='N')
                continue;
            if(dr[1]=='x') {
                dr[1] = tmp[1];
                dr[0] = dr[0]==tmp[0]? '+' : '-';
            }
            else if(dr[1]==tmp[1]) {
                dr[1] = 'x';
                dr[0] = dr[0]!=tmp[0]? '+' : '-';
            }
        }
        cout << dr << endl;
    }

    return 0;
}
