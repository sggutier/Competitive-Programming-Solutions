#include <bits/stdc++.h>
using namespace std;

bool testCase(int N, int arr[6])  {
    int ult = 1;
    stack <int> S;
    for(int i=1; i<=N; i++) {
        // printf("%d -> ", arr[i]);
        if(arr[i]>=ult) {
            // printf("(");
            while(ult!=arr[i] && ult<=N) {
                // printf("%d ", ult);
                S.push(ult++);
            }
            // printf(")");
            // printf("%d\n", ult);
            if(ult!=arr[i])
                return false;
            ult ++;
        }
        else {
            // printf("%d\n", S.empty()? -1 : S.top());
            if(S.empty() || S.top()!=arr[i])
                return false;            
            S.pop();
        }
    }
    return true;
}

int main() {
    int N;
    int arr[1005];

    while(scanf("%d", &N)!=EOF && N) {
        while(scanf("%d", &arr[1])!=EOF && arr[1]) {
            for(int i=2; i<=N; i++)
                scanf("%d", &arr[i]);
            printf("%s\n", testCase(N, arr)? "Yes" : "No");
        }
        printf("\n");
    }
    
    return 0;
}
