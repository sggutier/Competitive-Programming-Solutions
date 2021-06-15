#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

bool isComp[limN];
vector <int> primos;

void criba(int n = limN) {
    isComp[0] = isComp[1] = true;
    for(int i=2; i*i<n; i++)
        if(!isComp[i])
            for(int j=i*i; j<n; j+=i)
                isComp[j] = true;
    for(int i=2; i*i<n; i++)
        if(!isComp[i])
            primos.push_back(i);
}

int main() {
    criba();
    
    int N ;
    int arr[limN];
    int maxW = 0;

    scanf("%d", &N);

    for(int i=2; i<=N+1; i++) {
        long long w = 0;
        for(const int &j:primos) {
            if(j*j > i)
                break;
            if(i%j)
                continue;
            // printf("%d %d\n", i, j);
            w |= (1LL<<arr[j]);
        }
        for(int j=1; ; j++) {
            if(((1LL<<j) & w) == 0) {
                arr[i] = j;
                break;
            }
        }
        maxW = max(maxW, arr[i]);
    }

    printf("%d\n", maxW);
    for(int i=2; i<=N+1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
