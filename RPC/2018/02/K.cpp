#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int arOrg[3];
vector <tuple<int, int, int> > cmbs;
int N ;
int nums[limN];

bool funcaVel(int D) {
    int arr[] = {arOrg[0], arOrg[1], arOrg[2]};
    // printf("Intentando con %d\n", D);
    // printf("{{ %d %d %d }}\n", arr[0], arr[1], arr[2]);
    for(int i=0; i<N; i++) {
        bool funca = false;
        // printf("%d => ", nums[i]);
        for(auto &t : cmbs) {
            int a, b, s ;
            tie(s, a, b) = t;
            arr[a]--, arr[b]--;
            if(s * nums[i] < D || arr[a]<0 || arr[b]<0) {
                arr[a]++, arr[b]++;
                continue;
            }
            // printf("[%d %d %d | %d %d %d | %d] ", s, a, b, s * nums[i] , arr[a], arr[b], (s * nums[i] < D || !arr[a] || !arr[b]));            
            funca = true;
            break;
        }
        // printf("\n");
        // printf("{{ %d %d %d }}\n", arr[0], arr[1], arr[2]);
        if(!funca)
            return false;
    }
    return true;
}

int main() {
    int vals[3];
    for(int i=0; i<3; i++) {
        scanf("%d", &arOrg[i]);
        N += arOrg[i];
    }
    for(int i=0; i<3; i++)
        scanf("%d", &vals[i]);
    for(int i=0; i<3; i++) {
        for(int j=i; j<3; j++) {
            cmbs.emplace_back(vals[i] + vals[j], i, j);
        }
    }
    N /= 2;
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);
    sort(cmbs.begin(), cmbs.end());
    sort(nums, nums+N);
    int ini = 0, fin = 2e9;
    while(ini < fin) {
        int piv = (ini+fin)/2 + 1;
        if(funcaVel(piv))
            ini = piv;
        else
            fin = piv-1;
    }
    printf("%d\n", ini);
}
