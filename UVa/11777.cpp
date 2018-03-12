#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int sum = 0;
    int cls[3];

    for(int i=0; i<4; i++) {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
    }
    for(int i=0; i<3; i++) {
        scanf("%d", &cls[i]);
    }
    sort(cls, cls+3);

    sum = sum*2 + cls[1] + cls[2];

    int grad = 180;
    for(; grad>100 && sum<grad; grad -= 20);

    // printf("%d\n", sum);
    // printf("%d\n", grad);

    if(grad!=100)
        printf("%c\n", 'A' + 9-grad/20);
    else
        printf("F\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}
