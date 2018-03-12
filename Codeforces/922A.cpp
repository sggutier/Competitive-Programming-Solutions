#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b ;
    cin >> a >> b ;
    printf("%s\n", (b>=1 && a >= b-1 && (a-b)%2 && (a==0 || b>1))? "Yes" : "No");
}
