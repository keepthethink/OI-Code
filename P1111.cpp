//
// Created by Helium on 2019-07-28.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct Line {
    int u, v, w;

    bool operator < (const Line& l) const {
        return w < l.w;
    }
};

const int MAXN = 1000 + 5;
const int MAXM = 100000 + 5;

Line line[MAXM];
int f[MAXN];
int n, m;

int find(int k) {
    if(f[k] == k) {
        return k;
    }

    return f[k] = find(f[k]);
}

void connect(int x, int y) {
    f[find(x)] = find(y);
}

bool query(int x, int y) {
    return find(x) == find(y);
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> line[i].u >> line[i].v >> line[i].w;
    }

    sort(line, line + m);

    int ans = 0, tot = 0;
    for(int i = 0; i < m; i++) {
        if(!query(line[i].u, line[i].v)) {
            connect(line[i].u, line[i].v);
            ans = line[i].w;
            tot++;
        }
    }

    if(tot != n - 1) {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}