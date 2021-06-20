#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    pair < pair<int,int>, string> arr[10];
    char tmp[1005];

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        int tmpI;
        for(int i=0; i<10; i++) {
            scanf("%s%d", tmp, &tmpI);
            arr[i] = make_pair( make_pair(-tmpI, i), tmp);
        }
        sort(arr, arr+10);
        printf("Case #%d:\n", i);
        for(int j=0; j<10; j++) {
            if(j>0 && arr[j].first.first != arr[j-1].first.first)
                break;
            printf("%s\n", arr[j].second.c_str());
        }
    }
    
    return 0;
}
