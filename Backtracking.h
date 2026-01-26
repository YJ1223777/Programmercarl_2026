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

class Backtracking
{
public:
	// leetcode 77 组合
	//vector<vector<int>> combine(int n, int k) 
	//{
	//	result.clear();
	//	patch.clear();
	//	backtracking(n, k, 1);
	//	return result;
	//}


	// leetcode 216 组合总和 III
	//vector<vector<int>> combinationSum3(int k, int n) 
	//{
	//	backtracking(k, n, 1);
	//	return result;
	//}


	// leetcode 17 电话号码的字母组合
	//vector<string> letterCombinations(string digits) 
	//{
	//	backtracking(digits, 0);
	//	return str_list;
	//}


	// leetcode 39 组合总和
	//vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	//	patch.clear();
	//	result.clear();
	//	backtracking(candidates, target, 0);
	//	return result;
	//}


	// leetcode 39 组合总和 II
	//vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	//	vector<bool> used(candidates.size(), false);
	//	patch.clear();
	//	result.clear();
	//	sort(candidates.begin(), candidates.end());
	//	backtracking(candidates, target, 0, used);
	//	return result;
	//}


	// leetcode 131 分割回文串
	//vector<vector<string>> partition(string s) {
	//	str_result.clear();
	//	str_path.clear();
	//	backtracking(s, 0);
	//	return str_result;
	//}


	// leetcode 93 复原 IP 地址
	//vector<string> restoreIpAddresses(string s) {
	//	str_list.clear();
	//	backtracking(s, 0, 0);
	//	return str_list;
	//}


	// leetcode 78 子集
	//vector<vector<int>> subsets(vector<int>& nums) {
	//	result.clear();
	//	backtracking(nums, 0);
	//	return result;
	//}


	// leetcode 90 子集II
	//vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	//	patch.clear();
	//	result.clear();
	//	vector<bool> used(nums.size(), false);
	//	sort(nums.begin(), nums.end());
	//	backtracking(nums, 0, used);
	//	return result;
	//}


	// leetcode 491 非递减子序列
	//vector<vector<int>> findSubsequences(vector<int>& nums) {
	//	patch.clear();
	//	result.clear();
	//	backtracking(nums, 0);
	//	return result;
	//}


	// leetcode 46 全排列
	/*vector<vector<int>> permute(vector<int>& nums) {
		patch.clear();
		result.clear();
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		return result;
	}*/


	// leetcode 47 全排列 II
	//vector<vector<int>> permuteUnique(vector<int>& nums) {
	//	patch.clear();
	//	result.clear();
	//	vector<bool> used(nums.size(), false);
	//	sort(nums.begin(), nums.end());
	//	backtracking(nums, used);
	//	return result;
	//}


	// leetcode 51 N 皇后
	vector<vector<string>> solveNQueens(int n) {

	}


private:
	vector<vector<int>> result;
	vector<int> patch;

	vector<string> str_list;
	string str;
	const string letterMap[10] = {
	"", // 0
	"", // 1
	"abc", // 2
	"def", // 3
	"ghi", // 4
	"jkl", // 5
	"mno", // 6
	"pqrs", // 7
	"tuv", // 8
	"wxyz", // 9
	};

	int sum = 0;

	vector<vector<string>> str_result;
	vector<string> str_path;

	// leetcode 77 组合
	//void backtracking(int n, int k, int startIndex)
	//{
	//	if (patch.size() == k)
	//	{
	//		result.push_back(patch);
	//		return;
	//	}

	//	//for (int i = startIndex; i <= n; i++)
	//	//{
	//	//	patch.push_back(i);
	//	//	backtracking(n, k, i + 1);
	//	//	patch.pop_back();
	//	//}

	//	// 剪枝操作
	//	for (int i = startIndex; i <= n-(k-patch.size())+1; i++)
	//	{
	//		patch.push_back(i);
	//		backtracking(n, k, i + 1);
	//		patch.pop_back();
	//	}
	//}

	// leetcode 216 组合总和 III
	//void backtracking(int k, int n, int startIndex)
	//{
	//	if (accumulate(patch.begin(), patch.end(), 0) == n && patch.size() == k)
	//	{
	//		result.push_back(patch);
	//		return;
	//	}

	//	for (int i = startIndex; i <= 9 - (k - patch.size()) + 1; i++)
	//	{
	//		patch.push_back(i);
	//		backtracking(k, n, i+1);
	//		patch.pop_back();
	//	}
	//}

	// leetcode 17 电话号码的字母组合
	//void backtracking(string digits, int index)
	//{
	//	if (str.size() == digits.size())
	//	{
	//		str_list.push_back(str);
	//		return;
	//	}

	//	int n = digits[index] - '0';
	//	string letter = letterMap[n];
	//	index += 1;
	//	for (int i = 0; i < letter.size(); i++)
	//	{
	//		str.push_back(letter[i]);
	//		backtracking(digits, index);
	//		str.pop_back();
	//	}
	//}


	// leetcode 39 组合总和
	//void backtracking(vector<int>& candidates, int target, int startIndex)
	//{
	//	if (sum > target) {
	//		return;
	//	}

	//	if (sum == target)
	//	{
	//		result.push_back(patch);
	//		return;
	//	}

	//	for (int i = startIndex; i < candidates.size(); i++)
	//	{
	//		sum += candidates[i];
	//		patch.push_back(candidates[i]);
	//		backtracking(candidates, target, i);
	//		sum -= candidates[i];
	//		patch.pop_back();
	//	}
	//}


	// leetcode 40 组合总和 II
	//void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool>& used)
	//{
	//	if (sum == target)
	//	{
	//		result.push_back(patch);
	//		return;
	//	}

	//	for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
	//	{
	//		if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == 0)
	//		{
	//			continue;
	//		}
	//		sum += candidates[i];
	//		patch.push_back(candidates[i]);
	//		used[i] = true;
	//		backtracking(candidates, target, i+1, used);
	//		sum -= candidates[i];
	//		patch.pop_back();
	//		used[i] = false;
	//	}	
	//}


	//// 判断是否是回文字符串
	//bool isPalindrome(const string& str, int start, int end)
	//{
	//	for (int i = start, j = end; i <= j; i++, j--)
	//	{
	//		if (str[i] != str[j]) {
	//			return false;
	//		}
	//	}
	//	return true;
	//}

	//// leetcode 131 分割回文串
	//void backtracking(const string& s, int startIndex)
	//{
	//	if (startIndex >= s.size())
	//	{
	//		str_result.push_back(str_path);
	//		return;
	//	}

	//	for (int i = startIndex; i < s.size(); i++)
	//	{
	//		if (isPalindrome(s, startIndex, i))
	//		{
	//			string st = s.substr(startIndex, i - startIndex + 1);
	//			str_path.push_back(st);
	//		}
	//		else {
	//			continue;
	//		}

	//		backtracking(s, i + 1);
	//		str_path.pop_back();
	//	}
	//}


	//// 判断IP是否符合规定
	//bool isIP(const string& str, int start, int end)
	//{
	//	if (start > end)
	//	{
	//		return false;
	//	}

	//	if (str[start] == '0' && start != end)
	//	{
	//		return false;
	//	}

	//	int num = 0;
	//	for (int i = start; i <= end; i++)
	//	{
	//		if (str[i] < '0' || str[i] > '9')
	//		{
	//			return false;
	//		}
	//		num = num * 10 + str[i] - '0';
	//		if (num > 255)
	//		{
	//			return false;
	//		}
	//	}
	//	return true;
	//}

	//// leetcode 93 复原 IP 地址
	//void backtracking(string& s, int startIndex, int pointNum)
	//{
	//	if (pointNum == 3)
	//	{
	//		if (isIP(s, startIndex, s.size() -1))
	//		{
	//			str_list.push_back(s);
	//		}
	//		return;
	//	}

	//	for (int i = startIndex; i < s.size(); i++)
	//	{
	//		if (isIP(s, startIndex, i))
	//		{
	//			s.insert(s.begin() + i + 1, '.');
	//			pointNum++;
	//			backtracking(s, i + 2, pointNum);
	//			pointNum--;
	//			s.erase(s.begin() + i + 1);
	//		}
	//		else
	//		{
	//			break;
	//		}
	//	}
	//}


	// leetcode 78 子集
	//void backtracking(vector<int>& num, int startIndex)
	//{
	//	result.push_back(patch);

	//	for (int i = startIndex; i < num.size(); i++)
	//	{
	//		patch.push_back(num[i]);
	//		backtracking(num, i + 1);
	//		patch.pop_back();
	//	}
	//}


	//// leetcode 90 子集II
	//void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) 
	//{
	//	result.push_back(patch);
	//	for (int i = startIndex; i < nums.size(); i++)
	//	{
	//		if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
	//		{
	//			continue;
	//		}

	//		patch.push_back(nums[i]);
	//		used[i] = true;
	//		backtracking(nums, i + 1, used);
	//		used[i] = false;
	//		patch.pop_back();
	//	}
	//}


	//// leetcode 491 非递减子序列
	//void backtracking(vector<int>& nums, int startIndex)
	//{
	//	if (patch.size() > 1)
	//	{
	//		result.push_back(patch);
	//	}

	//	unordered_set<int> used;
	//	for (int i = startIndex; i < nums.size(); i++)
	//	{
	//		if (!patch.empty() && nums[i] < patch.back() 
	//			|| used.find(nums[i])!=used.end())
	//		{
	//			continue;
	//		}

	//		patch.push_back(nums[i]);
	//		used.insert(nums[i]);
	//		backtracking(nums, i + 1);
	//		patch.pop_back();
	//	}
	//}


	// leetcode 46 全排列	
	/*void backtracking(vector<int>& nums, vector<bool>& used)
	{
		if (patch.size() == nums.size())
		{
			result.push_back(patch);
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (used[i] == false)
			{
				patch.push_back(nums[i]);
				used[i] = true;
			}
			else
			{
				continue;
			}
			backtracking(nums, used);
			used[i] = false;
			patch.pop_back();
		}
	}*/


	// leetcode 47 全排列 II
	/*void backtracking(vector<int>& nums, vector<bool>& used)
	{
		if (patch.size() == nums.size())
		{
			result.push_back(patch);
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false || used[i] == true)
			{
				continue;
			}
			patch.push_back(nums[i]);
			used[i] = true;
			backtracking(nums, used);
			used[i] = false;
			patch.pop_back();
		}
	}*/



	// leetcode 51 N 皇后
	void backtracking(int n)
	{
	
	
	}
	

};

