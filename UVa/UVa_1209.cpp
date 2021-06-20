#include <bits/stdc++.h>
using namespace std;
const int limN = 100;

int calcDst(char *w, int n) {
    int ans = (1<<30);
    for(int i=1; i<n; i++)
        ans = min(ans, abs(w[i] - w[i-1]));
    return ans;
}

void testCase(char *w, int n) {
    char cpy[limN];
    cpy[n] = 0;
    pair<int, string> ans = make_pair(0, "");
    
    strncpy(cpy, w, n);
    for(int i=0; i<=10; i++) {
        ans = min(ans, make_pair(-calcDst(cpy, n), string(cpy)));
        if(!next_permutation(cpy, cpy+n))
            break ;
    }
    strncpy(cpy, w, n);
    for(int i=0; i<=10; i++) {
        ans = min(ans, make_pair(-calcDst(cpy, n), string(cpy)));
        if(!prev_permutation(cpy, cpy+n))
            break ;
    }

    printf("%s%d\n", ans.second.c_str(), -ans.first);
}

int main() {
    char line[limN];
    char *w = &line[0];
    size_t tam = sizeof(line);
    int n ;

    while((n = getline(&w, &tam, stdin))!=-1) {
        testCase(w, n-1);
    }
    
    return 0;
}
