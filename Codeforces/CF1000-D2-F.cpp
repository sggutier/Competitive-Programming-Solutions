#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
	  tree_order_statistics_node_update>;

// void example() {
// 	Tree<int> t, t2; t.insert(8);
// 	auto it = t.insert(10).first;
// 	assert(it == t.lower_bound(9));
// 	assert(t.order_of_key(10) == 1);
// 	assert(t.order_of_key(11) == 2);
// 	assert(*t.find_by_order(0) == 8);
// 	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
// }

typedef pair<int, int> pii;
#define f first
#define s second
const int limN = 5e5 + 5;

Tree <int> ults;
int N, Q;
int arr[limN];
int ultApr[limN];
int ordo[limN];
pii quers[limN];
int anso[limN];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        scanf("%d%d", &quers[i].s, &quers[i].f);
        ordo[i] = i;
    }
    sort(ordo, ordo+Q,
         [](const int a, const int b) {
             return quers[a] < quers[b];
         });

    for(int i=1, q=0; i<=N; i++) {
        if(ultApr[arr[i]]) ults.erase(ultApr[arr[i]]);
        ultApr[arr[i]] = i;
        ults.insert(i);
        while(q<Q && quers[ordo[q]].f == i) {
            printf("Actualmente procesando %d %d\n", quers[ordo[q]].s, quers[ordo[q]].f);
            printf("Contenido del arbol:\n");
            printf("\t");
            for(const int c : ults)
                printf("%d ", c);
            printf("\n");
            anso[ordo[q]] = ults.size() - ults.order_of_key(quers[ordo[q]].s);
            q++;
        }
    }

    for(int i=0; i<Q; i++)
        printf("%d\n", anso[i]);
}
