#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b ;
    cin >> a >> b ;
    printf("%d\n", (int) ((log(b)-log(a))/log(1.5)) + 1 );
}
