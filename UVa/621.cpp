#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    string S;
    for(cin >> tc; tc; tc --){
        cin >> S;
        cout << ((S=="1" || S=="4" || S=="78")? '+' : (S.substr(S.size()-2, 2)=="35"? '-' : ((S[0]=='9' && S[S.size()-1]=='4')? '*' : '?') )) << endl;
    }

    return 0;
}
