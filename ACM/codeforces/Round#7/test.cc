#pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;

#define MK make_pair

static const int MAX_WEIGHT = 100000;

vector<int> adjacency_list[1005];
int arr[1005];

int dp[1005];

int node_weight[1005];

bool tag = true;

void dfs(int node) {

    for (int i = 0; i < adjacency_list[node].size(); ++i) {
        dfs(adjacency_list[node][i]);
    }
    for (int i = 0; i <= arr[node]; ++i) {
        dp[i] = 0;
    }

    //
    int all_other_weight = 0;
    int all_son_weight = 0;

    for (int i = 0; i < adjacency_list[node].size(); ++i) {
        int son = adjacency_list[node][i];
        all_other_weight += node_weight[son];
        all_son_weight += arr[son];
        for (int j = arr[node]; j >= arr[son]; j--) {

            if (dp[j] < dp[j - arr[son]] + node_weight[son]) {
                dp[j] = dp[j - arr[son]] + node_weight[son];
            }
        }
    }
    if ((all_other_weight - dp[arr[node]]) > arr[node]) {
        tag = false;
    }
    node_weight[node] = all_other_weight - dp[arr[node]];
}

void run(int n) {

    memset(dp, 0, sizeof(dp));
    tag = true;
    for (int i = 0; i <= n; ++i) {
        adjacency_list[i].clear();
    }
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        adjacency_list[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dfs(1);
    if (tag) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main() {

#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    int n;
    while (cin >> n) {
        run(n);
    }
}
