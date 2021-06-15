#include <bits/stdc++.h>
using namespace std;
#define MAXS 50005

bool itWorks(char *str, int pos, int N) {
    bool usd[26] = {false};
    // string ans (str + pos, 26);
    for(int i=0; i<26; i++) {
        if(str[pos + i]=='?' ) {
        }
        else if( str[pos + i] >= 'A' && str[pos + i] <= 'Z' ){
            if(usd[str[pos + i] - 'A'])
                return false;
            usd[str[pos + i] - 'A'] = true;
        }
        else {
            return false;
        }
    }
    for(int i=0; i<26; i++) {
        if(str[pos + i]=='?' ) {
            int j;
            for(j=0; usd[j]; j++);
            str[pos + i] = 'A' + j;
            usd[j] = true;
        }
    }
    for(int i=0; i<pos; i++) {
        str[i] = (str[i]=='?')? 'A' : str[i];
    }
    for(int i=pos + 26; i<N; i++) {
        str[i] = (str[i]=='?')? 'A' : str[i];
    }
    return true;
}

string goodString(char *str, int N) {
    for(int i=0; i+26<=N; i++) {
        bool tmp = itWorks(str, i, N);
        if( tmp ) {
            return string(str, N);
        }
    }
    return "-1";
}

int main() {
    int len ;
    char str[MAXS];
    
    fgets(str, MAXS, stdin);
    len = strlen(str) - 1;
    printf("%s\n", goodString(str, len).c_str() ) ;
    
    return 0;
}
