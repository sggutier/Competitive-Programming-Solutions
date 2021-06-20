#include <bits/stdc++.h>
using namespace std;
const int limP = 2001;

bool isComp[limP];

void criba(int n = limP) {
    isComp[0] = isComp[1] = true;
    for(int i=2; i*i<n; i++)
        if(!isComp[i])
            for(int j=i*i; j<n; j+=i)
                isComp[j] = true;
}

void testCase() {
    char str[limP + 5];
    vector <int> reps(300, 0);
    bool any = false;
    scanf("%s", str);
    for(char *c = str; *c; c++)
        reps[(int) *c]++;
    for(int i=0; i<300; i++) {
        if(isComp[reps[i]])
            continue;
        any = true;
        printf("%c", (char) i);
    }
    printf("%s\n", any? "" : "empty");
}

int main() {
    criba() ;
    int tc ;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}
