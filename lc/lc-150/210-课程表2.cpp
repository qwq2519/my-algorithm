#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> v(numCourses, vector<int>());
        vector<int> in(numCourses);
        for (auto p : prerequisites) {
            v[p[1]].push_back(p[0]);
            in[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!in[i]) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            order.push_back(x);
            for (auto to : v[x]) {
                --in[to];
                if (!in[to]) {
                    q.push(to);
                }
            }
        }

        if (order.size() == numCourses) {
            return order;
        }
        return vector<int>();
    }
};
