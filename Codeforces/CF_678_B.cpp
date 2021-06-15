#include <bits/stdc++.h>
using namespace std;

int dayN(int y) {
    int leap = (y%400==0? 1 : (y%100==0? 0 : (y%4==0? 1 : 0)));
    return 365 + leap;
}

int main() {
    int s = 0;
    int y ;
    int d ;
    scanf("%d", &y);
    d = dayN(y);
    for(int i=y+1; ; i++) {
        s = (s + dayN(i-1))%7;
        if(dayN(i)==d && s==0) {
            printf("%d\n", i);
            return 0;            
        }
    }
}
