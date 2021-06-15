#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[5000];
    int N ;
    scanf("%s", str);
    N = strlen(str);
    for(int i=0; i+3<=N; i++) {
        if(str[i] == '.' || str[i+1] == '.' || str[i+2] == '.')
            continue;
        set <int> cols;
        for(int j=0; j<3; j++)
            cols.insert(str[i+j]);
        if(cols.size() == 3) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}
