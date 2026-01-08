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
	vector<string> letterCombinations(string digits) 
	{
		backtracking(digits, 0);
		return str_list;
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
	void backtracking(string digits, int index)
	{
		if (str.size() == digits.size())
		{
			str_list.push_back(str);
			return;
		}

		int digit = digits[index] - '0';
		string letters = letterMap[digit];
		for (int i = 0; i < letters.size(); i++)
		{
			str.push_back(letters[i]);
			backtracking(digits, index + 1);
			str.pop_back();
		}
	}

};
