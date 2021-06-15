#include <bits/stdc++.h>
using namespace std;

void printA(int n, char c) {
    while(n--)
        printf("%c", c);    
}

int main() {
    int n, m ;
    cin >> n >> m ;
    for(int i=0; i<n; i++) {
        if(i%2==0)
            printA(m, '#');
        else {
            if(i%4==1) {
                printA(m-1, '.');
                printA(1, '#');
            }
            else {               
                printA(1, '#'); 
                printA(m-1, '.');
            }
        }
        printf("\n");
    }
}
