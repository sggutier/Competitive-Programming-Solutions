#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N ;
    char str[limN];
    int ordo[limN];
    int nums[limN];
    vector <pair<int,int>> ans;

    scanf("%s", str);
    N = strlen(str);
    for(int i=0; i<N; i++) {
        ordo[i] = i;
    }

    sort(ordo, ordo+N, [&str] (int a, int b) { return str[a] < str[b]; });
    for(int i=0; i<N; i++)
        nums[ordo[i]] = i;

//    for(int j=0; j<N; j++)
//            printf("%d ", nums[j]+1);
//        printf("\n");
    for(int i=0; i<N; i++) {
        //printf("=> %d %d\n", ordo[i], i);
        if(nums[i]==i)
            continue;
        int sig ;
        for(int j=i+1; j<N; j++) {
            if(nums[j]==i) {
                sig = j ;
                break;
            }
        }
        //printf("%d %d\n", i+1, sig+1);
        ans.push_back({i, sig});
        swap(str[i], str[sig]);
        swap(nums[i], nums[sig]);
        //swap(ordo[i], ordo[ordo[i]]);
        //printf("%s\n", str);
//        for(int j=0; j<N; j++)
//            printf("%d ", nums[j]+1);
//        printf("\n");
    }

    reverse(ans.begin(), ans.end());
    for(auto &p:ans) {
        int x = p.first, y = p.second;
        if(str[x] < str[y])
            printf("%d %d\n", y+1, x+1);
        swap(str[x], str[y]);
    }
}
