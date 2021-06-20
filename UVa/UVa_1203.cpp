#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue <pair <pair<int,int>, pair<int,int>>> queries;
    char tmp[500];
    while(true) {
        scanf("%s",tmp);
        if(tmp[0]=='#')
            break;
        int a, b;
        scanf("%d%d", &a, &b);
        queries.push(make_pair(make_pair(-b, -a), make_pair(a,b)));
    }

    int k;
    scanf("%d", &k);
    while(k--) {
        pair <pair<int,int>, pair<int,int>> a = queries.top(); queries.pop();
        printf("%d\n", a.second.first);
        a.first.first -= a.second.second;
        queries.push(a);
    }    

    return 0;
}
