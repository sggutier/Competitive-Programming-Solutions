#include <bits/stdc++.h>
using namespace std;

bool seprAtmpt(string &A, string &B, int (*fapr)[26], int K) {
    int lA = A.size(), lB = B.size();
    int Q = lB - K ;
    int minL[K + 1][Q + 1] ;
    for(int i=0; i <= K; i++)
        for(int j=0; j <= Q; j++)
            minL[i][j] = lA;
    minL[0][0] = -1;
    for(int i=0; i <= K; i++) {
        for(int j=0; j <= Q; j++) {
            if(minL[i][j] == lA) continue;
            int aPos = minL[i][j] + 1 ;
            if(j != Q)
                minL[i][j + 1] = min(minL[i][j+1], fapr[aPos][B[K + j] - 'a']);
            if(i != K)
                minL[i + 1][j] = min(minL[i+1][j], fapr[aPos][B[    i] - 'a']);
        }
    }
    return minL[K][Q] != lA;
}

bool testCase(string &A, string &B) {
    int lA = A.size(), lB = B.size();
    int fapr[lA + 1][26];
    for(int i=0; i < 26; i++)
        fapr[lA][i] = lA;
    for(int i=lA - 1; i >= 0; i--) {
        for(int j=0; j < 26; j++)
            fapr[i][j] = fapr[i+1][j];
        fapr[i][A[i] - 'a'] = i;
    }
    for(int i=1; i <= lB; i++)
        if(seprAtmpt(A, B, fapr, i))
            return true;
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N ;
    cin >> N ;
    for(int i=0; i < N; i++) {
        string A, B ;
        cin >> A >> B ;
        cout << (testCase(A, B)? "YES" : "NO") << endl;
    }
}
