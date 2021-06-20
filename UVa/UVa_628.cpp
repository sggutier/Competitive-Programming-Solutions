#include <bits/stdc++.h>
using namespace std;
const int limN = 300;

void generateAllPasswords(char dict[][limN], const int &dictSize, char* query, int* pswd, int passSize) {
    if(query[passSize]==0) {
        for(int i=0; i<passSize; i++) {
            if(query[i]=='#')
                printf("%s", dict[pswd[i]]);
            else
                printf("%c", pswd[i]+'0');
        }
        printf("\n");
        return;
    }
    int lim = (query[passSize]=='#'? dictSize : 10);
    for(pswd[passSize]=0; pswd[passSize]<lim; pswd[passSize]++)
        generateAllPasswords(dict, dictSize, query, pswd, passSize+1);
}

void testCase(int dictSize) {
    char dict[dictSize][limN];
    int queryNum;
    
    for(int i=0; i<dictSize; i++) {
        scanf("%s", dict[i]);
    }
    scanf("%d", &queryNum);
    printf("--\n");
    for(int i=0; i<queryNum; i++) {
        char query[limN];
        int pswd[limN];
        scanf("%s", query);
        generateAllPasswords(dict, dictSize, query, pswd, 0);
    }
}

int main() {
    int n;

    while(scanf("%d", &n)!=EOF)
        testCase(n);
    
    return 0;
}
