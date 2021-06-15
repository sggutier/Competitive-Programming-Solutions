#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N ;
int arr[limN];

int main() {
    int fin, p ;
    scanf("%d%d", &N, &fin);
    for(int i=1; i<N; i++)
        scanf("%d", &arr[i]);

    for(p=1; p<N; ) {
        if(p==fin)
            break;
        p = p+arr[p];
    }

    printf("%s\n", p==fin? "YES" : "NO");
}
