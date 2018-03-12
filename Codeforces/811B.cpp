#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

int main() {
    int N, Q;
    int arr[limN];

    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++)
        scanf("%d", &arr[i]);
    while(Q--) {
        int a, b, c;
        int men = 0;
        scanf("%d%d%d", &a, &b, &c);
        for(int i=1; i<a; i++)
            if(arr[i] < arr[c])
                men ++;
        for(int i=N; i>b; i--)
            if(arr[i] < arr[c])
                men ++;
        printf("%s\n", c-a+1 == arr[c]-men? "Yes" : "No");
    }
}
