// Source: https://leetcode.cn/problems/longest-palindromic-substring/
// Tags: string, manacher

#include <iostream>
#include <string>
#include <cstring>
#include "json_input_helper.h"
#include "json_output_helper.h"

using namespace std;

string expand(string raw)
{
    unsigned int len = raw.length();
    string res;
    res.push_back('@');
    for (unsigned int i = 0; i < len; i++)
    {
        res.push_back('#');
        res.push_back(raw[i]);
    }
    res.push_back('#');
    return res;
}

pair<string, int> manacherMaxLength(string raw)
{
    // Get the expanded string
    string s = expand(std::move(raw));

    // Give an array to store the max radius you can get in pos `i`
    int radius[s.length()];
    memset(radius, 0, sizeof radius);
    int refCenter = 0;
    int maxRadius = 0;
    int maxRadiusPos = 0;

    for (int i = 1; i < s.length(); i++)
    {
        // If `i` is in the reference palindrome
        // some pair check can be ignored by referencing the image palindrome on the other side
        if (i < refCenter + radius[refCenter])
            radius[i] = min(radius[2 * refCenter - i], refCenter + radius[refCenter] - i);
        else
            radius[i] = 1;

        // Do the common pair check
        while (s[i + radius[i]] == s[i - radius[i]])
            radius[i]++;

        // Update the refCenter & maxRadius info
        if (i + radius[i] > refCenter + radius[refCenter])
        {
            refCenter = i;
            if (radius[i] > maxRadius)
            {
                maxRadius = radius[i];
                maxRadiusPos = i;
            }
        }
    }

    // Convert the result to the original string & radius
    string maxRadiusStr;
    for (int i = maxRadiusPos - maxRadius + 1; i < maxRadiusPos + maxRadius; i++)
    {
        if (s[i] != '#')
            maxRadiusStr.push_back(s[i]);
    }
    int realMaxRadius = maxRadius % 2 == 0 ? maxRadius - 1 : int(maxRadius / 2) * 2;

    return pair<string, int>(maxRadiusStr, realMaxRadius);
}

class Solution
{
public:
    string longestPalindrome(string s)
    {
        return manacherMaxLength(s).first;
    }
};

int main()
{
    cout << "longest-palindromic-substring" << endl;
    string s = read_quoted_string();

    Solution solution;
    string output = solution.longestPalindrome(s);

    print_quoted_string(output);
}