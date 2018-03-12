#include <bits/stdc++.h>
using namespace std;

int a, b;

int main(){
    scanf("%d %d",&a,&b);
    if(a==0 && b==0)
        printf("Not a moose\n");
    else if(a==b)
        printf("Even %d\n",a*2);
    else
        printf("Odd %d\n",(max(a,b)*2));
    return 0;
}
