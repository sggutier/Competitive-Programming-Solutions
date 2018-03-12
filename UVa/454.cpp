#include <bits/stdc++.h>
using namespace std;
const int limN = 255;
char str[limN];

void testCase() {
    int reps[limN][limN];
    string words[limN];
    int n = 0;

    memset(reps, 0, sizeof(reps));

    while(gets(str) && *str) {
        words[n++] = str;
    }
    sort(words, words+n);

    for(int i=0; i<n; i++) {
        for(const char &c:words[i]) {
            if(c!=' ')
                reps[i][c]++;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            bool works = true;
            for(int k=0; k<limN; k++) {
                if(reps[i][k]!=reps[j][k]) {
                    works = false;
                    break;
                }
            }
            if(works) {
                printf("%s = %s\n", words[i].c_str(), words[j].c_str());
            }
        }
    }
}

int main() {
    int tc ;
    gets(str);
    tc = atoi(str);
    gets(str);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
}
