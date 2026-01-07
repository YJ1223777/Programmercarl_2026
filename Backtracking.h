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
	vector<vector<int>> combinationSum3(int k, int n) 
	{
		backtracking(k, n, 1);
		return result;
	}


private:
	vector<vector<int>> result;
	vector<int> patch;

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
	void backtracking(int k, int n, int startIndex)
	{
		if (accumulate(patch.begin(), patch.end(), 0) == n && patch.size() == k)
		{
			result.push_back(patch);
			return;
		}

		for (int i = startIndex; i <= 9 - (k - patch.size()) + 1; i++)
		{
			patch.push_back(i);
			backtracking(k, n, i+1);
			patch.pop_back();
		}
	
	}
};
