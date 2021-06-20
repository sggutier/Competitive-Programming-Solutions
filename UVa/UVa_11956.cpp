#include <bits/stdc++.h>
using namespace std;
const int limN = 100005;
const int limD = 100;

void testCase(char *cad, int cadLen) {
    vector<unsigned char> nums(limD);
    for(int i=0, pos=0; i<cadLen; i++) {
        switch(cad[i]) {
        case '>':
            pos = (pos+1)%limD; break;
        case '<':
            pos = (pos+99)%limD; break;
        case '+':
            nums[pos] ++; break;
        case '-':
            nums[pos] --; break;
        }
    }
    for(int i=0; i<limD; i++) {
        if(i)
            printf(" ");
        printf("%02X", nums[i]);
    }
    printf("\n");
}

int main() {
    char line[limN];
    char *w = &line[0];
    size_t tam = sizeof(line);
    int n, tc ;

    (n = getline(&w, &tam, stdin));
    sscanf(line, "%d", &tc);
    for(int i=0; i<tc; i++) {
        printf("Case %d: ", i+1);
        n = getline(&w, &tam, stdin);
        testCase(w, n-1);
    }
    
    return 0;
}
