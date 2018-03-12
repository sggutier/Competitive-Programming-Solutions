/*
ID: me60
LANG: C++11
TASK: namenum
*/
#include <bits/stdc++.h>
using namespace std;

char keypad[10][3] ;
set <string> dict;
int nameCnt = 0;

void init() {
    FILE *dictFile = fopen("dict.txt", "r");
    for(int i=0, cnt=0; i<26; i++) {
        keypad[cnt/3 + 2][cnt%3] = i + 'A';
        if(i+'A'!='Q' && i+'A'!='Z')
            cnt ++;
    }
    char tmp[20];
    while(fscanf(dictFile, "%s", tmp)!=EOF)
        dict.insert(tmp);
    fclose(dictFile);
}

void nameSearch(char* t, string ans) {
    if(*t==0) {
        if(dict.count(ans)) {
            printf("%s\n", ans.c_str());
            nameCnt ++; 
        }
        return;
    }
    for(int i=0; i<3; i++)
        nameSearch(t+1, ans + keypad[*t - '0'][i]);
}

int main() {
    init();
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    char t[200];
    scanf("%s", t);
    nameSearch(t, "");
    if(nameCnt==0)
        printf("NONE\n");
    
    return 0;
}
