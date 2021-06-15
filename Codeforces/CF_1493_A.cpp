#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    int a, b ;
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%d%d", &a, &b);
        vector <int> ans ;
        for(int j=a; j > b; j--)
            ans.push_back(j);
        for(int j=b-1; j*2 >= b; j--)
            ans.push_back(j);
        printf("%d\n", (int) ans.size());
        for(const int x : ans)
            printf("%d ", x);
        printf("\n");
    }
}
