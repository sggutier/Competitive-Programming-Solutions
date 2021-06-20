#include <bits/stdc++.h>
using namespace std;

void printEsp(int k) ;
void printFin(int k) ;
void printComp(int a, int b) ;
void printProg(int k = 1) ;
void printComs();
void testCase() ;

int N ;
int arr[10];

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        scanf("%d", &N);
        testCase();
    }
}

void testCase() {
    for(int i=0; i<N; i++)
        arr[i] = i;
    printf("program sort(input,output);\n");
    printf("var\n");
    printComs();
    printf(" : integer;\n");
    printf("begin\n");
    printf("  readln(");
    printComs();
    printf(");\n");
    printProg();
    printf("end.\n");
}

void printProg(int k) {
    if(k==N) {
        printFin(k);
        return;
    }
    for(int i=k-1; i>=0; i--) {
        printEsp(k);
        if(i != k-1)
            printf("else ");
        printComp(arr[i], k);
        printProg(k+1);
        swap(arr[i], arr[i+1]);
    }
    printEsp(k);
    printf("else\n");
    printProg(k+1);
    for(int i=0; i<k; i++)
        swap(arr[i], arr[i+1]);
}

void printFin(int k) {
    printEsp(k);
    printf("writeln(");
    printComs();
    printf(")\n");
}

void printComs() {
    for(int i=0; i<N; i++) {
        if(i)
            printf(",");
        printf("%c", 'a'+arr[i]);
    }
}

void printEsp(int k) {
    while(k--)
        printf("  ");
}

void printComp(int a, int b) {
    printf("if %c < %c then\n", a + 'a', b + 'a');
}
