// Mierda, por que no leo bien?
#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

int N;
int arr[limN];
int prevo[limN];

int main() {
    int ans = 0;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }
    prevo[0] = -1;
    for(int i=-1, j=0; j<N; ) {
        while(i!=-1 && arr[i]!=arr[j])
            i = prevo[i];
        i++, j++;
        prevo[j] = i;
        ans = max(ans, i);
    }
    printf("%d\n", ans);
}
