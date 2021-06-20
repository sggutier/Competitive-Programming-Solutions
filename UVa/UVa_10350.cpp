#include <bits/stdc++.h>
using namespace std;
const int inf = (1<<30);

vector <int> renoA(20), renoB(20);

void testCase() {
    int N, M;
    vector <int> *curF=&renoA, *sigF=&renoB;
    int tmp;

    scanf("%d%d", &N, &M);    
    for(int i=0; i<M; i++)
        renoA[i] = 0;

    for(int k=1; k<N; k++) {
        for(int i=0; i<M; i++)
            (*sigF)[i] = inf;
        for(int i=0; i<M; i++) {
            for(int j=0; j<M; j++) {
                scanf("%d", &tmp);
                (*sigF)[j] = min((*sigF)[j], (*curF)[i] + tmp + 2);
            }
        }
        // for(int i=0; i<M; i++)
        //     printf("%d ", (*sigF)[i]);
        // printf("\n");
        swap(curF, sigF);
    }

    tmp = inf;
    for(int i=0; i<M; i++)
        tmp = min(tmp, (*curF)[i]);

    printf("%d\n", tmp);
}

int main() {
    char str[50];

    while(scanf("%s", str)!=EOF) {
        printf("%s\n", str);
        testCase();
    }
    
    return 0;
}
