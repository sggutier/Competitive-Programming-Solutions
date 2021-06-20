#include <bits/stdc++.h>
using namespace std;

inline bool isVowel(const char &c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y';
}

void testCase(int iregCnt, int querCnt) {
    map <string, string> irregs;
    
    for(int i=0; i<iregCnt; i++) {
        char norm[50], plur[50];
        scanf("%s%s", norm, plur);
        irregs[norm] = plur;
    }

    while(querCnt--) {
        char str[50];
        scanf("%s", str);
        auto it = irregs.find(str);
        if(it!=irregs.end()) {
            printf("%s\n", it->second.c_str());
            continue;
        }
        int n = strlen(str) ;
        if(n>=2 && str[n-1]=='y' && !isVowel(str[n-2])) {
            str[n-1] = 'i';
            str[n] = 'e';
            str[n+1] = 's';
            str[n+2] = 0;
        }
        else if(str[n-1]=='o' || str[n-1]=='s' || str[n-1]=='x' ||
                (n>=2 && str[n-1]=='h' && (str[n-2]=='c' || str[n-2]=='s'))) {
            str[n] = 'e' ;
            str[n+1] = 's';
            str[n+2] = 0;
        }
        else {
            str[n] = 's';
            str[n+1] = 0;
        }
        printf("%s\n", str);
    }
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
    
    return 0;
}
