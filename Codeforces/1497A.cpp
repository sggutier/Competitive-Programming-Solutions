#include <bits/stdc++.h>
using namespace std;

void testCase() {
    vector <int> ans ;
    int reps[105] = {0};
    int N ;
    scanf("%d", &N);
    for(int i=0, a; i < N; i++) {
        scanf("%d", &a);
        reps[a] ++;
    }
    for(int i=0; i < 105; i++) {
        if(!reps[i]) break;
        ans.push_back(i);
        reps[i] --;
    }
    for(int i=0; i < 105; i++)
        while(reps[i]) {
            reps[i] --;
            ans.push_back(i);
        }
    for(const int x : ans)
        printf("%d ", x);
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        testCase();
    }
}
