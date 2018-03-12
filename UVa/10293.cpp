#include <bits/stdc++.h>
using namespace std;

// using namespace std;


inline bool isPunct(const char &c) {
    return c==' ' || c=='!' || c==',' || c=='.' || c=='?' || c=='\n';
}

void testCase() {
    vector <int> ans(90);
    char c ;
    char hyph = 0;
    int len = 0;
    if((c=getchar())==EOF)
        exit(0);
    while(c!='#') {
        if(isPunct(c)) {
            if(hyph=='-' && c=='\n')
                hyph = false;
            else {
                ans[len] ++;
                len = 0;
                hyph = 0;
            }
        }
        else if(c=='-' || c=='\'') {
            hyph = c;
        }
        else {
            len ++;
            hyph = 0;
        }
        if((c=getchar())==EOF)
            exit(0);
    }
    ans[len] ++;
    int n = ans.size();
    for(int i=1; i<n; i++)
        if(ans[i])
            printf("%d %d\n", i, ans[i]);
    printf("\n");
}

int main() {
    while(true) {
         testCase();
    }
}
