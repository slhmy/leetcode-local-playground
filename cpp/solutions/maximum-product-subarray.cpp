// Source: https://leetcode.cn/problems/maximum-product-subarray/
// Tags: dynamic-programming, space-optimization

#include <vector>
#include <json_input_helper.h>

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        long long max_product = nums[0], min_product = nums[0], result = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            long long temp_max_product = max_product, temp_min_product = min_product;
            max_product = max({temp_max_product * nums[i],
                               temp_min_product * nums[i],
                               (long long)nums[i]});
            min_product = min({temp_max_product * nums[i],
                               temp_min_product * nums[i],
                               (long long)nums[i]});
            result = max(result, max_product);
        }

        return result;
    }
};

int main()
{
    auto nums = read_vector_from_json_str<int>();

    Solution solution;
    auto output = solution.maxProduct(nums);

    cout << output << endl;
}