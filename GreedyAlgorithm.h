#pragma once

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <numeric>  
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class GreedyAlgorithm
{
public:

    // 455. 分发饼干
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int index = s.size() - 1;

        for (int i = g.size() - 1; i >= 0; i--)
        {
            if (index >= 0 && s[index] >= g[i])
            {
                res++; 
                index--;
            }
        }
        return res;
    }


    // 376. 摆动序列
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int pre_diff = 0;
        int cur_diff = 0;
        int result = 1;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            cur_diff = nums[i + 1] - nums[i];
            if ((cur_diff > 0 && pre_diff <= 0) || (pre_diff >= 0 && cur_diff < 0))
            {
                result++;
            }

            if (cur_diff != 0)
            {
                pre_diff = cur_diff;
            }

        }

        return result;
    }


private:


};

