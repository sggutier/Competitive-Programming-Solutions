#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

string S;
int ant[limN][2];
string strs[limN][2];

void printa(int pos, int sg = 0) {
    if(pos == 0) {
        printf("0");
        return ;
    }
    printa(pos-1, ant[pos][sg]);
    printf(" %d", ant[pos][sg]!=sg? 1 : 0);
}

int main() {
    char tmp[limN];
    int N ;
    scanf("%s", tmp);
    S = tmp;
    N = S.size();

    strs[0][0] = strs[0][1] = tmp[0];
    for(int i=1; i<N; i++) {
        string a, b ;
        a = strs[i-1][0] + tmp[i];
        b = strs[i-1][1] + tmp[i];
        reverse(b.begin(), b.end());
        if(b < a) {
            ant[i][0] = 1;
            strs[i][0] = b;
        }
        else {
            ant[i][0] = 0;
            strs[i][0] = a;
        }
        a = strs[i-1][1] + tmp[i];
        b = strs[i-1][0] + tmp[i];
        reverse(b.begin(), b.end());
        if(a < b) {
            ant[i][1] = 0;
            strs[i][1] = b;
        }
        else {
            ant[i][1] = 1;
            strs[i][1] = a;
        }
        // cout << strs[i][0] << " " << strs[i][1] << endl;
    }

    printa(N-1);
    printf("\n");
}
