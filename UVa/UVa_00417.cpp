#include <bits/stdc++.h>
using namespace std;

int tamDict = 0;
map <int, int> dict;

void precarga(int pos, int crg=0, int ult=0) {
    if(pos==0) {
        dict[crg] = ++tamDict;
        return;
    }
    for(int i=ult+1; i<27; i++) {
        precarga(pos-1, crg*27 + i, i);
    }
}

int toI(char *s) {
    int ans = 0;
    while(*s) {
        ans = ans*27 + (*s-'a'+1);
        s++;
    }
    return ans;
}

int main() {
    for(int i=1; i<=5; i++)
        precarga(i);
    char str[15];
    while(gets(str)) {
        int n = toI(str);
        auto it = dict.find(n);
        if(it==dict.end())
            printf("0\n");
        else
            printf("%d\n", it->second);
    }
}
