#include <bits/stdc++.h>
using namespace std;

string rotateX(string D) {
    string ans = D;
    ans[2] = D[3];
    ans[3] = D[4];
    ans[4] = D[5];
    ans[5] = D[2];
    return ans;
}

string rotateY(string D) {
    string ans = D;
    ans[0] = D[2];
    ans[2] = D[1];
    ans[1] = D[4];
    ans[4] = D[0];
    return ans;
}

string rotateZ(string D) {
    string ans = D;
    ans[0] = D[3];
    ans[3] = D[1];
    ans[1] = D[5];
    ans[5] = D[0];
    return ans;
}

void testCase() {
    string A, B;
    string P, Q, R;
    cin >> A >> B ;
    P = A;
    for(int i=0; i<4; i++) {
        Q = P;
        for(int j=0; j<4; j++) {
            R = Q;
            for(int k=0; k<4; k++) {
                if(R==B) {
                    printf("Equal\n");
                    return;
                }
                R = rotateZ(R);
            }
            Q = rotateY(Q);
        }
        P = rotateX(P);
    }
    printf("Not Equal\n");
}

int main() {
    int tc;

    cin >> tc;
    while(tc--)
        testCase();
    
    return 0;
}
