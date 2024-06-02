// Source: https://leetcode.com/problems/spiral-matrix/
// Tags: array

#include <iostream>
#include <string>
#include <vector>
#include "json_input_helper.h"
#include "json_output_helper.h"

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};

        vector<int> ans = {};
        int t = 0, l = 0, b = matrix.size() - 1, r = matrix[0].size() - 1;
        while (t <= b && r >= l)
        {
            for (int i = l; i <= r; i++)
                ans.emplace_back(matrix[t][i]);
            for (int i = t + 1; i <= b; i++)
                ans.emplace_back(matrix[i][r]);
            if (t != b && l != r)
            {
                for (int i = r - 1; i > l; i--)
                    ans.emplace_back(matrix[b][i]);
                for (int i = b; i > t; i--)
                    ans.emplace_back(matrix[i][l]);
            }
            t += 1;
            l += 1;
            b -= 1;
            r -= 1;
        }

        return ans;
    }
};

int main()
{
    cout << "spiral-matrix" << endl;
    auto matrix = read_vector_from_json_str<vector<int>>();

    Solution solution;
    vector<int> output = solution.spiralOrder(matrix);

    print_vector_as_json<int>(output);
}