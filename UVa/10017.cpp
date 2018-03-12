#include <bits/stdc++.h>
using namespace std;

int rem = 0;
vector <int> stcs[3];

void printStcs() {
    for(int i=0; i<3; i++) {
        printf("%c=>", 'A' + i);
        if(!stcs[i].empty())
            printf("  ");
        for(const int &v:stcs[i])
            printf(" %d", v);
        printf("\n");
    }
    printf("\n");
}

void moveD(int a, int b) {
    stcs[b].push_back(stcs[a].back());
    stcs[a].pop_back();
}

void hanoi(int x, int y, int z, int d) {
    if(!rem)
        return;
    if(d==1) {
        moveD(x, z);
        printStcs();
        rem --;
        return;
    }
    hanoi(x, z, y, d-1);
    if(!rem)
        return;
    rem --;
    moveD(x, z);
    printStcs();
    hanoi(y, x, z, d-1);
}

void testCase(int N, int r) {
    for(int i=0; i<3; i++)
        stcs[i].clear();
    for(int i=N; i; i--)
        stcs[0].push_back(i);
    printStcs();
    rem = r;
    hanoi(0, 1, 2, N);
}

int main() {
    int a, b;
    int tc = 0;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        printf("Problem #%d\n\n", ++tc);
        testCase(a, b);
    }
}
