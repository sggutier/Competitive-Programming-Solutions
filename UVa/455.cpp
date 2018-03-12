#include <bits/stdc++.h>
using namespace std;

int testCase(string S) {
    int n = S.size();
    for(int i=1; i<n; i++) {
        if(n%i)
            continue ;
        string tmp = S.substr(0, i);
        bool itWorks = true ;
        for(int j=i; j<n; j+=i) {
            if(S.substr(j, i)!=tmp) {
                itWorks = false;
                break ;
            }
        }
        if(itWorks)
            return i;
    }
    return n;
}

int main() {
    int tc ;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        char tmp[100];
        scanf("%s", tmp);
        printf("%d\n", testCase(tmp));
    }
    
    return 0 ;
}
