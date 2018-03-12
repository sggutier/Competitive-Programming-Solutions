/*
ID: me60
LANG: C++11
TASK: preface
*/
#include <bits/stdc++.h>
using namespace std;
const string romNums[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const int romVals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const int romCnt = 13;

string aRom(int n) {
    string ans = "";
    for(int i=0; i<romCnt; i++) {
        while(n>=romVals[i]) {
            ans += romNums[i];
            n -= romVals[i];
        }
    }
    return ans;
}

int charCnt[300];

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    
    int n;

    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) {
        string tmp = aRom(i);
        for(int i=(int) tmp.size()-1; i>=0; i--) {
            charCnt[(int) tmp[i]]++;
        }
    }

    for(int i=romCnt-1; i>=0; i-=2) {
        if(charCnt[(int) romNums[i][0]]>0) {
            printf("%c %d\n", romNums[i][0], charCnt[(int) romNums[i][0]]);
        }
    }
    
    return 0;
}
