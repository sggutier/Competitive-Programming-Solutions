#include <bits/stdc++.h>
using namespace std;

void testCase(int N) {
    map <int,int> prev;
    int a, b;

    scanf("%d%d", &a, &b);

    //int pos = 0, tim = 0;
    int pos = 0, tim = 0;
    while(prev.count(pos)==0) {
        //printf("%d %d\n", pos, tim);
        prev[pos] = tim++;
        pos = (((((long long) pos)*pos)%N)*a + b)%N;
    }

    printf("%d\n", N - (tim-prev[pos]));
}

int main() {
    int N;
    while(scanf("%d", &N)!=EOF && N)
        testCase(N);
}
