#include <bits/stdc++.h>
using namespace std;

int cnt[300];

int main() {
    int ocnt = 0;
    char str[10000];
    fgets(str, 10000, stdin);
    for(char *c=str; *c!='\n'; c++)
        cnt[(int) *c]++;
    for(int i=0; i<300; i++)
        if(cnt[i]%2)
            ocnt++;
    printf("%s\n", (ocnt==0 || ocnt%2)? "First" : "Second");
}
