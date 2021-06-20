#include <bits/stdc++.h>
using namespace std;

void testCase(char *w, int wSize) {
    int a=0, b=0;
    int cnt = 0;
    for(int i=0; i<wSize; i++) {
        if(w[i]==' ')
            continue ;        
        if(w[i]=='F' && w[i+1]=='F')
            a++;
        else if(w[i]=='M' && w[i+1]=='M')
            b++;
        cnt ++;
        i++;
    }
    printf("%sLOOP\n", (a!=b || cnt==1)? "NO " : "");
}

int main() {
    char line[500];
    char *w = &line[0];
    size_t tam = sizeof(line);
    int n, tc ;

    (n = getline(&w, &tam, stdin));    
    for(sscanf(line, "%d", &tc); tc>0; tc--)  {
        n = getline(&w, &tam, stdin);
        testCase(w, n-1);
    }
    
    return 0;
}
