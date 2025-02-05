#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

// DFS function to find connected regions
void dfs(int i, int j, vector<vector<int>>& grid, set<pair<int, int>>& region, vector<vector<bool>>& visited) {
    int n = grid.size(), m = grid[0].size();
    visited[i][j] = true;
    region.insert({i, j});
    
    for (auto dir : directions) {
        int ni = i + dir[0], nj = j + dir[1];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1 && !visited[ni][nj]) {
            dfs(ni, nj, grid, region, visited);
        }
    }
}

// Function to extract all regions from a grid
vector<set<pair<int, int>>> getRegions(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<set<pair<int, int>>> regions;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                set<pair<int, int>> region;
                dfs(i, j, grid, region, visited);
                regions.push_back(region);
            }
        }
    }
    return regions;
}

// Main function to count matching regions
int countMatchingRegions(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    vector<set<pair<int, int>>> regions1 = getRegions(grid1);
    vector<set<pair<int, int>>> regions2 = getRegions(grid2);
    
    int matchingCount = 0;
    
    for (auto& r1 : regions1) {
        for (auto& r2 : regions2) {
            if (r1 == r2) { 
                matchingCount++;
                break; // A region in grid1 can match at most one in grid2
            }
        }
    }
    return matchingCount;
}

// Driver Code
int main() {
    int n;
    cin >> n;
    vector<vector<int>>grid1(n,vector<int>(n));
    

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            grid1[i][j]=s[j]-'0';
        }
    }
    int m;
    cin>>m;
    vector<vector<int>> grid2(m,vector<int>(m));
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid2[i][j]=s[j]-'0';
        }
    }

    
    cout << countMatchingRegions(grid1, grid2) << endl;
    return 0;
}
