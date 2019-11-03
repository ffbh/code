#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
#include <cassert>

using namespace std;

#ifndef ONLINE_JUDGE
ifstream in("/Users/jiazhi.zhou/CLionProjects/acm/InOutput/input.txt");
#define Debug(v) cerr<<#v<<"="<<v<<'\n'
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#define Debug(v) ;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)
#define rson (root<<1|1)
#define FFLUAHALL fflush(stdin);fflush(stdout);

int n;
pii edge[200010];
vector<pii > vi[400010];// node_a -> {edge_id , node_b}
unordered_map<int, int> M; // for vi
bool vis[400010];//for vi
int ori[400010]; // for vi
int degree[400010]; // for vi
bool cycle[400010];//for vi

void input() {
    // n = 100000;
    in >> n;
    //scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        //  edge[i] = mp(1, 2);
        in >> edge[i].first >> edge[i].second;
        // scanf("%d%d", &edge[i].first, &edge[i].second);
    }

}

void _init() {


}

int getID(int v) {
    if (!M.count(v)) {
        int size = M.size();
        M[v] = size + 1;
        ori[size + 1] = v;
    }
    return M[v];
}

void pre_do() {
    M.clear();
    for (int i = 1; i <= n; ++i) {
        int &a = edge[i].first;
        int &b = edge[i].second;
        a = getID(a);
        b = getID(b);
        vi[a].clear();
        vi[b].clear();
        vis[a] = vis[b] = 0;
        degree[a] = degree[b] = 0;
        cycle[a] = cycle[b] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        int a = edge[i].first;
        int b = edge[i].second;
        vi[a].push_back(mp(i, b));
        vi[b].push_back(mp(i, a));
    }
}

vector<pii > nodes;

void add(int v) {
    degree[edge[v].first]++;
    degree[edge[v].second]++;
    nodes.push_back(mp(edge[v].first, v));
    nodes.push_back(mp(edge[v].second, v));
}

pii find_cycle(int st) {
    queue<pii > Q;
    Q.push(mp(st, edge[st].first));
    Q.push(mp(st, edge[st].second));
    cycle[edge[st].first] = cycle[edge[st].second] = 1;
    while (!Q.empty()) {
        pii u = Q.front();
        Q.pop();
        for (pii son : vi[u.second]) {
            if (son.first == u.first)
                continue;
            if (!cycle[son.second]) {
                cycle[son.second] = 1;
                Q.push(son);
            } else {
                return mp(son.second, son.first);
            }
        }
    }
    assert(0);
}

pii bfs(int v) {
    nodes.clear();
    queue<int> Q;
    vis[edge[v].first] = vis[edge[v].second] = 1;
    Q.push(edge[v].first);
    Q.push(edge[v].second);
    add(v);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (pii son : vi[u]) {
            if (!vis[son.second]) {
                add(son.first);
                vis[son.second] = 1;
                Q.push(son.second);
            }
        }
    }
    for (pii e : nodes) {
        if (degree[e.first] == 1) {
            return e;
        }
    }
    return find_cycle(v);

}

int getAnother(pii one) {
    pii all = edge[one.second];
    if (all.first == one.first) {
        return all.second;
    } else {
        return all.first;
    }
}

int main() {

    int TEST_CASE = 1;
    in >> TEST_CASE;
    while (TEST_CASE-- > 0) {
        _init();
        input();
        pre_do();
        int ans = -1;
        vector<pair<int, pii>> V;
        pii pre;
        for (int i = 1; i <= n; ++i) {
            if (!vis[edge[i].first]) {
                ans++;
                pii t = bfs(i);
                if (ans > 0) {
                    V.push_back(mp(pre.second, mp(pre.first, getAnother(t))));
                }
                pre = t;
            }
        }
        cout << ans << endl;
        for (auto x : V) {
            printf("%d %d %d\n", x.first, ori[x.second.first], ori[x.second.second]);
        }
    }


    return 0;
}





