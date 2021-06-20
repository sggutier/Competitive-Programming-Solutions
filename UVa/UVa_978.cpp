#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int BF, A[2];
    priority_queue <int> lems[2];
    queue <int> waitu[2];
    char names[2][10] = {"green", "blue"};

    scanf("%d%d%d", &BF, &A[0], &A[1]);
    for(int i=0; i<2; i++) {
        while(A[i]--) {
            int tmp ;
            scanf("%d", &tmp);
            lems[i].push(tmp);
        }
    }

    while(!lems[0].empty() && !lems[1].empty()) {
        for(int i=0; i<BF && (!lems[0].empty() && !lems[1].empty()); i++) {
            int nums[2] = {lems[0].top(), lems[1].top()};
            lems[0].pop();
            lems[1].pop();
            for(int i=0; i<2; i++)
                if(nums[i]>nums[1-i])
                    waitu[i].push(nums[i]-nums[1-i]);
        }
        for(int i=0; i<2; i++) {
            while(!waitu[i].empty()) {
                lems[i].push(waitu[i].front());
                waitu[i].pop();
            }
        }
    }

    if(lems[0].empty() && lems[1].empty()) {
        printf("green and blue died\n");
        return;
    }
    for(int i=0; i<2; i++) {
        if(lems[i].empty())
            continue;
        printf("%s wins\n", names[i]);
        while(!lems[i].empty()) {
            printf("%d\n", lems[i].top()); lems[i].pop();
        }
    }
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
    
    return 0;
}
