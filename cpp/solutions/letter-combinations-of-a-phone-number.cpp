// Source: https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
// Tags: string, backtracking, depth-first-search

#include <vector>
#include <json_input_helper.h>
#include <json_output_helper.h>

class Solution
{
    unordered_map<char, string> phone_map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        string combination_space = "";

        dfs(digits, 0, combination_space, result);

        return result;
    }

    void dfs(const string &digits, int index, string &cur_combination, vector<string> &result)
    {
        if (index == digits.size())
        {
            if (cur_combination.size() > 0)
                result.push_back(cur_combination);
            return;
        }

        for (auto c : phone_map[digits[index]])
        {
            cur_combination.push_back(c);
            dfs(digits, index + 1, cur_combination, result);
            cur_combination.pop_back();
        }
    }
};

int main()
{
    cout << "letter-combinations-of-a-phone-number" << endl;
    auto digits = read_quoted_string();

    Solution solution;
    auto output = solution.letterCombinations(digits);

    print_vector_as_json(output);
}