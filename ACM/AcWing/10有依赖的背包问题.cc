#include <bits/stdc++.h>
using namespace std;
int v[105], w[105];
int dp[105][105];
int n, V, p;
vector<int> gra[105];

void run();

int main() {
#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

void dfs(int node) {
    //代表必须选择node点
    // cout << "## " << node << ' ' << v[node] << ' ' << V << endl;
    for (int i = v[node]; i <= V; i++) {
        dp[node][i] = w[node];
    }

    for (int i = 0; i < gra[node].size(); ++i) {
        int son = gra[node][i];
        dfs(son);
        for (int j = V; j >= v[node]; --j) {
            for (int k = 0; k <= V - v[node]; k++) {

                dp[node][j] = max(dp[node][j], dp[node][j - k] + dp[son][k]);
            }
        }
    }
}
void run() {

    cin >> n >> V;

    int root;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> p;
        if (p != -1) {
            gra[p].push_back(i);
        } else {
            root = i;
        }
    }
    dfs(root);
    cout << dp[root][V] << endl;
}