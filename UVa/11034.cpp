#include <bits/stdc++.h>
using namespace std;
#define par pair<int, int>
#define f first
#define s second

class Ferry {
public:
    int nextAvilTime=0, nextSide=0;
    int maxLoad = 0, travTime = 0;
    int load = 0;
    queue <int> cars;
    bool loadCar(int car) {
        // printf("Trying to load car with length %d\n", car);
        if(car + load > maxLoad)
            return false;
        // printf("Success!\n");
        load += car;
        cars.push(car);
        return true;
    }
    void move(int tim) {
        // printf("crossin\n");
        nextAvilTime = tim + travTime ;
        nextSide = 1 - nextSide ;
    }
    bool hasCars() {
        return !cars.empty();
    }
    int unloadCar() {        
        if(cars.empty())
            return 0;
        // printf("Unloading car with length %d\n", cars.front());
        int ans  = cars.front();
        load -= ans;
        cars.pop();
        return ans;
    }
    Ferry(int _maxLoad, int _travTime) {
        maxLoad = _maxLoad;
        travTime = _travTime;
    }
};

void testCase(int n, int t, int carCnt) {
    Ferry fry(n, t);
    vector <int> ans (carCnt) ;
    vector <par> queries(carCnt);
    queue <int> cars[2];
    int coCnt = 0;

    for(int i=0; i<carCnt; i++) {
        int a;
        char S[15];
        scanf("%d%s", &a, S);
        queries[i] = par(a, S[0]=='r');
        // printf("%d %s\n", a, S);
    }

    for(int i=0; i<carCnt || !cars[0].empty() || !cars[1].empty() || fry.hasCars(); ) {
        // printf("%d %d -> Fry: %d %d\n", (int) cars[0].size(), (int) cars[1].size(), fry.nextAvilTime, fry.nextSide);
        // getchar();
        if(i<carCnt && ( (!fry.hasCars() && cars[0].empty() && cars[1].empty()) ||  /*queries[i].f*/i <= fry.nextAvilTime)) {
            // fry.nextAvilTime = max(fry.nextAvilTime, queries[i].f);
            fry.nextAvilTime = max(fry.nextAvilTime, i+1);
            cars[queries[i].s].push(queries[i].f);
            i++;
            continue ;
        }
        int tim = fry.nextAvilTime, sid = fry.nextSide ;
        while(fry.hasCars()) {
            // ans[fry.unloadCar()] = tim;
            fry.unloadCar();
        }
        while(!cars[sid].empty() && fry.loadCar(cars[sid].front()))
            cars[sid].pop();
        if(!cars[1-sid].empty() || fry.hasCars()) {
            fry.move(tim);
            coCnt ++;
        }
    }

    // for(int i=0; i<carCnt; i++) {
    //     printf("%d\n", ans[i]);
    // }
    printf("%d\n", coCnt);
}

int main() {
    int tc;

    scanf("%d", &tc);
    // tc = 1 ;
    for(int i=0; i<tc; i++) {
        // if(i)
        //     printf("\n");
        int a, c;
        scanf("%d%d", &a, &c);
        testCase(a*100, 1, c);
    }
    
    return 0;
}
