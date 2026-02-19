class Solution {
  // 拓扑排序板子
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> edge[numCourses];
    vector<int> indegree(numCourses);

    for (int i = 0; i < prerequisites.size(); ++i) {
      auto v = prerequisites[i];
      edge[v[1]].push_back(v[0]);
      indegree[v[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
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
    return count == numCourses;
  }
};
