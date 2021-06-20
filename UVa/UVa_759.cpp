#include <bits/stdc++.h>
using namespace std;

string iToR(int n) {
    int indo[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string ans;
    for(int i=0; n; i++) {
        int r = n/indo[i];
        for(int j=0; j<r; j++)
            ans += roman[i];
        n -= indo[i]*r;
    }
    return ans;
}

void preload(map<string, int> &rToI) {
    for(int i=1; i<4000; i++) {
        rToI[iToR(i)] = i;
    }
}

int main() {
    char s[1000];
    map<string, int> rToI;
    preload(rToI);

    while(scanf("%s",s)!=EOF) {
        map<string, int>::iterator it=rToI.find(s);
        if(it==rToI.end())
            printf("This is not a valid number\n");
        else
            printf("%d\n", it->second);
    }
    
    return 0;
}
