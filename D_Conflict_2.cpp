#include <bits/stdc++.h>
using namespace std;

// BFS to compute shortest path between two nodes in a tree
int bfs(int start, int goal, vector<vector<int>>& adj) {
    queue<pair<int, int>> q;
    vector<bool> visited(adj.size(), false);
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        auto [node, dist] = q.front(); q.pop();
        if (node == goal) return dist;
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                visited[nei] = true;
                q.push({nei, dist + 1});
            }
        }
    }
    return -1; // unreachable, should never happen in a tree
}

// Main function to calculate minimum time
int getMinimumTime(int tree_nodes, vector<int> tree_from, vector<int> tree_to,
                   int start_node, int end_node, vector<int> task_nodes) {
    vector<vector<int>> adj(tree_nodes + 1);
    for (int i = 0; i < tree_from.size(); ++i) {
        adj[tree_from[i]].push_back(tree_to[i]);
        adj[tree_to[i]].push_back(tree_from[i]);
    }

    vector<int> points = task_nodes;
    points.push_back(start_node);
    points.push_back(end_node);

    int k = points.size();
    unordered_map<int, int> index;
    for (int i = 0; i < k; ++i) index[points[i]] = i;

    vector<vector<int>> dist(k, vector<int>(k, 0));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i != j)
                dist[i][j] = bfs(points[i], points[j], adj);
        }
    }

    int startIdx = index[start_node];
    int endIdx = index[end_node];

    vector<int> perm;
    for (int i = 0; i < k; ++i) {
        if (i != startIdx && i != endIdx) perm.push_back(i);
    }

    int minCost = INT_MAX;
    sort(perm.begin(), perm.end());
    do {
        int cost = dist[startIdx][perm[0]];
        for (int i = 1; i < perm.size(); ++i) {
            cost += dist[perm[i - 1]][perm[i]];
        }
        cost += dist[perm.back()][endIdx];
        minCost = min(minCost, cost);
    } while (next_permutation(perm.begin(), perm.end()));

    return minCost;
}

// Driver code with sample test case
int main() {
    int tree_nodes = 4;
    vector<int> tree_from = {1, 2, 2};
    vector<int> tree_to = {3, 3, 4};
    int start_node = 1;
    int end_node = 2;
    vector<int> task_nodes = {4};

    int result = getMinimumTime(tree_nodes, tree_from, tree_to, start_node, end_node, task_nodes);
    cout << "Minimum time required: " << result << endl;

    return 0;
}
