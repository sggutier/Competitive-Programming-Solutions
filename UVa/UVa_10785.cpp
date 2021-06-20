#include <bits/stdc++.h>
using namespace std;
const int voRep = 21;
const int csRep = 5;
const int limN = 211;

string ans = "";
// char ans[] = "AJAJAJAJAJASASASASASABABABABABAKAKAKAKAKATUTUTUTUTUCUCUCUCUCULULULULULUDUDUDUDUDUMUMEMEMEMEVEVEVEVEVENENENENENEWEWEWEWEWEFEFEFOFOFOXOXOXOXOXOGOGOGOGOGOPOPOPOPOPOYOYOYOYIYIHIHIHIHIHIQIQIQIQIQIZIZIZIZIZIRIRIRIRIRU";

inline bool isVowel(char a) {
    return a=='A' || a=='E' || a=='I' || a=='O' || a=='U';
}

void precarga(int N=limN) {
    ans = "";
    vector <char> cons;
    vector <char> vows;
    vector <int> csReps, voReps;
    for(int i=0; i<10; i++) {
        for(int j=i + 'A'; j<='Z'; j+=9) {
            if(isVowel(j)) {
                vows.push_back(j);
                voReps.push_back(voRep);
            }
            else {
                cons.push_back(j);
                csReps.push_back(csRep);
            }
        }
    }
    string A, B;
    for(int i=0, a=0, b=0; i<N; i++) {
        if(i%2) {
            if(!csReps[b])
                b++;
            csReps[b] --;
            B += cons[b];
        }
        else {
            if(!voReps[a])
                a++;
            voReps[a] --;
            A += vows[a];
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0; i<N; i++) {
        if(i%2) 
            ans += B[i/2];
        else
            ans += A[i/2];
    }
}

int main() {
    int N;

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        int tmp;
        scanf("%d", &tmp);
        precarga(tmp);
        printf("Case %d: ", i);
        printf("%s", ans.c_str());
        printf("\n");
    }
}

