// Source: https://leetcode.cn/problems/course-schedule/
// Tags: depth-first-search, directed-acyclic-graph

#include <vector>
#include <iostream>
#include "json_input_helper.h"
#include "json_output_helper.h"

class Solution
{
    vector<vector<int>> edges;
    vector<int> visit;
    bool valid = true;

    void dfs(int cur)
    {
        visit[cur] = 1;
        for (auto next : edges[cur])
            switch (visit[next])
            {
            case 0:
                dfs(next);
                break;
            case 1:
                valid = false;
                return;
            default:
                // When `visit[next] == 2`
                // the node is already visited and is on a DAG path
                break;
            }

        // Mark the node as visited & it's following nodes are all valid
        // Since it's following nodes always go earlier in the DFS
        // we don't need to check the following nodes again
        visit[cur] = 2;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visit.resize(numCourses);
        for (auto prerequisite : prerequisites)
            edges[prerequisite[0]].push_back(prerequisite[1]);

        for (int i = 0; i < numCourses; i++)
            if (visit[i] == 0)
            {
                Solution::dfs(i);
                if (!valid)
                    return false;
            }

        return true;
    }
};

int main()
{
    cout << "course-schedule" << endl;

    int numCourses;
    cin >> numCourses;
    auto prerequisites = read_vector_from_json_str<vector<int>>();

    Solution solution;
    bool output = solution.canFinish(numCourses, prerequisites);

    cout << (output ? "true" : "false") << endl;
}