#include <queue>
#include <vector>
using namespace std;
class Solution {
    // 拓扑排序板子
    int n;
    vector<vector<int>> edge;
    vector<int> indegree;
    bool bfs() {
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ++count;
            for (int i = 0; i < edge[x].size(); ++i) {
                int to = edge[x][i];
                --indegree[to];
                if (!indegree[to]) {
                    q.push(to);
                }
            }
        }
        return count == n;
    }

    vector<int> state;
    bool hasCycle = false;
    void dfs(int p) {
        state[p] = 1;
        for (auto to : edge[p]) {
            if (state[to] == 0) {
                dfs(to);
                if (hasCycle) {
                    return;
                }
            } else if (state[to] == 1) {
                hasCycle = true;
                return;
            }
        }
        state[p] = 2;
    }

    bool dfs() {
        state = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                dfs(i);
                if (hasCycle) {
                    return false;
                }
            }
        }
        return true;
    }

    //
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        n = numCourses;
        edge = vector<vector<int>>(numCourses, vector<int>());
        indegree = vector<int>(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i) {
            auto v = prerequisites[i];
            edge[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        return dfs();
        // return bfs();
    }
};
