#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M ;
    string S ;
    cin >> N >> M ;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            cin >> S ;
            if(S!="B" && S!="W" && S!="G") {
                cout << "#Color" << endl;
                return 0;
            }
        }
    cout << "#Black&White" << endl;
}
