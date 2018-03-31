#include <bits/stdc++.h>
using namespace std;

int main() {
    int N ;
    int sumos[] = {0, 0, 0};

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int wo[3];
        for(int j=0; j<3; j++) {
            scanf("%d", &wo[j]);
            sumos[j] += wo[j];
        }
    }

    printf("%s\n", (sumos[0]==0 && sumos[1]==0 && sumos[2]==0)? "YES" : "NO");
}
