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
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<bool> used(candidates.size(), false);
		patch.clear();
		result.clear();
		sort(candidates.begin(), candidates.end());
		backtracking(candidates, target, 0, used);
		return result;
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
	void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool>& used)
	{
		if (sum == target)
		{
			result.push_back(patch);
			return;
		}

		for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
		{
			if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == 0)
			{
				continue;
			}
			sum += candidates[i];
			patch.push_back(candidates[i]);
			used[i] = true;
			backtracking(candidates, target, i+1, used);
			sum -= candidates[i];
			patch.pop_back();
			used[i] = false;
		}	
	}

};
