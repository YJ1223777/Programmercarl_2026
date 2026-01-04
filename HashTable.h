#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class HashTable
{
public:

    // 有效的字母异位词
    bool isAnagram(string s, string t) {
        int record[26] = { 0 };
        for (int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            record[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }


    // 两个数组的交集
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        unordered_set<int> res;

        //for (int val:set1)
        //{
        //    if (set2.count(val))
        //        res.insert(val);
        //}

        for (int val : nums2)
        {
            if (set1.find(val)!=set1.end())
            {
                res.insert(val);
            }
        }

        return vector<int>(res.begin(), res.end());
    }


    // 获取各个位数上的和
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }


    // 快乐数
    bool isHappy(int n) 
    {
        unordered_set<int> set = {};
        while (1)
        {
            if (getSum(n) == 1) {
                return true;
            }

            if (set.find(getSum(n)) != set.end())
            {
                return false;
            }
            else
            {
                set.insert(getSum(n));
                n = getSum(n);
            }
        }
    }


    // 两数之和
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int>::iterator iter = map.find(target - nums[i]);
            if (iter!=map.end())
            {
                return { iter->second, i };
            }
            else 
            {
                map.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }


    // 四数相加II
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        int count = 0;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                map[a + b]++;
            }
        }

        for (int c : nums3)
        {
            for (int d : nums4)
            {
                if (map.find(-(c+d))!=map.end())
                {
                    count += map[0 - (c + d)];
                }
            }
        }
        return count;
    }


    // 赎金信
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {};
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }

        for (int i = 0; i < magazine.length(); i++) {
            record[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            record[ransomNote[i] - 'a']--;
            if (record[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }


    // 三数之和
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }

            if (i>0 && nums[i] == nums[i-1])
            {
                continue;
            }

            int left = i+1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    result.push_back({ nums[i] , nums[left] , nums[right] });
                    while (left < right && nums[right] == nums[right-1])
                    {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left+1])
                    {
                        left++;
                    }
                    right--;
                    left++;
                }
            }
        }

        return result;
    }


    // 四数之和
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > target && (nums[i]>0 || target>0))
            {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                    break;
                }

                // 对nums[i]去重
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right)
                {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        result.push_back({ nums[i] , nums[j], nums[left] , nums[right] });
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        right--;
                        left++;
                    }
                }

            }

        }
        return result;
    }

};

