#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

int tamDict;
string dict[limN];

void buscaMatch(const string &S) ;
bool faltante(const string &A, const string &B) ;
int mispel(const string &A, const string &B) ;
void testCase();

void buscaMatch(const string &S) {
    int n = S.size();
    int ult = tamDict;
    for(int i=tamDict-1; i>=0; i--) {
        if(n == (int) dict[i].size()) {
            int w = mispel(S, dict[i]);
            if(w==1) {
                printf("%s is correct\n", S.c_str());
                return;
            }
            if(w==2)
                ult = i;
        }
        else if(abs(n-(int) dict[i].size()) == 1 && faltante(S, dict[i])) {
            ult = i;
        }
    }
    if(ult==tamDict)
        printf("%s is unknown\n", S.c_str());
    else
        printf("%s is a misspelling of %s\n", S.c_str(), dict[ult].c_str());
}

int mispel(const string &A, const string &B) {
    int n = min(A.size(), B.size());
    int malCnt = 0, ult = -1;
    for(int i=0; i<n; i++) {
        if(A[i]==B[i])
            continue;
        if(malCnt==2) {
            return 0;
        }
        malCnt ++;
        ult = i;
    }
    if(malCnt==0)
        return 1;
    return (malCnt==1 || (A[ult]==B[ult-1] && A[ult-1]==B[ult]))? 2 : 0;
}

bool faltante(const string &A, const string &B) {
    if(A.size() > B.size())
        return faltante(B, A);
    int n = A.size();
    int i=0;
    while(i<n && A[i]==B[i]) {
        i++;
    }
    while(i<n) {
        if(A[i]!=B[i+1])
            return false;
        i++;
    }
    return true;
}

void testCase() {
    char tmp[30];
    for(int i=0; i<tamDict; i++) {
        //scanf("%s", tmp);
        gets(tmp);
        dict[i] = tmp;
    }
    int Q;
    gets(tmp);
    Q = atoi(tmp);
    //scanf("%d", &Q);
    while(Q--) {
        //scanf("%s", tmp);
        gets(tmp);
        buscaMatch(tmp);
    }
}

int main() {
    char tmp[30];
    while(gets(tmp)) {
        tamDict = atoi(tmp);
        testCase();
    }
    
    return 0;
}
