#include <bits/stdc++.h>
using namespace std;

void test_case() {
    int n;
    string *names;
    int *minPrice, *maxPrice;
    int Q;
    scanf("%d", &n);
    names = new string[n];
    minPrice = new int[n];
    maxPrice = new int[n];
    for(int i=0; i<n; i++) {
        char tmp[25];
        scanf("%s%d%d", tmp, &minPrice[i], &maxPrice[i]);
        names[i] = tmp;
    }
    scanf("%d", &Q);
    for(; Q; Q--) {
        int p ;
        scanf("%d", &p);
        int fnd=0;
        string ans;
        for(int i=0; i<n && fnd<2; i++) {
            if(minPrice[i]<=p && p<=maxPrice[i]) {
                ans = names[i];
                fnd ++;
            }
        }
        printf("%s\n", fnd==1? ans.c_str() : "UNDETERMINED");
    }
    
    delete[] names;
    delete[] minPrice;
    delete[] maxPrice;
}

int main() {
    int T ;
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        if(i)
            printf("\n");
        test_case();
    }
    return 0;
}
