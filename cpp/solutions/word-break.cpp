// Source: https://leetcode.cn/problems/word-break/
// Tags: string, dynamic-programming, hash-table

#include <string>
#include <vector>
#include <iostream>
#include <json_input_helper.h>

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> dict;
        for (auto word : wordDict)
            dict[word] = true;

        bool dp[s.size() + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
            for (int j = 0; j < i; j++)
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    dp[i] = true;
                    break;
                }

        return dp[s.size()];
    }
};

int main()
{
    cout << "word-break" << endl;
    auto s = read_quoted_string();
    auto wordDict = read_vector_from_json_str<string>();

    Solution solution;
    auto output = solution.wordBreak(s, wordDict);

    cout << (output ? "true" : "false") << endl;
}