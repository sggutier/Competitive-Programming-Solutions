#include <bits/stdc++.h>
using namespace std;

void testCase(int N, int a, int b) {
    list <int> lta ;    
    for(int i=0; i<N; i++)
        lta.push_back(i+1);
    bool fst = true;
    // printf("%d\n", (int) lta.size());
    list<int>::iterator ini = lta.begin(), fin = lta.end();
    fin--;
    // printf("atsara\n");
    while(true) {
        // printf("iniciclo\n");
        if(!fst)
            printf(",");
        fst = false;
        // printf("acara %d %d %d\n", ini==lta.begin(), ini==lta.end(), *ini);
        // for(int w:lta)
        //     printf("%d ", w);
        // printf("\n");
        for(int i=1; i<a; i++) {
            ini++;
            if(ini==lta.end())
                ini = lta.begin();
        }
        // printf("%d\n", *ini);
        for(int i=1; i<b; i++) {
            if(fin==lta.begin())
                fin = lta.end();
            fin --;
        }        
        // printf("%d\n", *fin);
        if(ini==fin) {            
            // printf("=> ");
            printf("%3d", *ini);
            // printf("\n");
            ini = lta.erase(ini);
            fin = ini;
            // printf("%d restante\n", (int) lta.size());
        }
        else {
            // printf("=> ");
            printf("%3d%3d", *ini, *fin);
            // printf("\n");
            ini = lta.erase(ini);
            if(ini == fin) {
                ini = fin = lta.erase(fin);
            }
            else
                fin = lta.erase(fin);
            // printf("%d aoesnuth restante\n", (int) lta.size());
        }
        if(lta.empty())
            break;
        // printf("%d %d\n", ini==lta.begin(), ini==lta.end());
        // printf("%d %d\n", fin==lta.begin(), fin==lta.end());
        if(fin==lta.begin())
            fin = lta.end();
        fin --;
        if(ini==lta.end())
            ini = lta.begin();
        // printf("%d %d\n", ini==lta.begin(), ini==lta.end());
        // printf("%d %d\n", fin==lta.begin(), fin==lta.end());
        // printf("De momento todo bien\n");
    }
    printf("\n");
}

int main() {
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c)!=EOF && (a || b || c))
        testCase(a, b, c);
}
