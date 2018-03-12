#include <bits/stdc++.h>
using namespace std;

int ans[4000];
int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
int cers[] = {4, 6, 3, 5, 2, 4, 2, 4, 2, 3, 2, 3, 1};
int S = 13;

void precarga(int N=4000) {
    for(int i=1; i<N; i++) {
        int w = i;
        int a = 0;
        for(int j=0; j<S; j++) {
            while(w>=vals[j]) {
                w -= vals[j];
                a += cers[j];
            }
        }
        ans[i] = a;
    }
}

int main() {
    precarga();
    int n;
    while(scanf("%d", &n)!=EOF)
        printf("%d\n", ans[n]);
}
