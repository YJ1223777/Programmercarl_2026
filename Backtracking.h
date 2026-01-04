#pragma once

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Backtracking
{
public:
	// leetcode 77
	vector<vector<int>> combine(int n, int k) 
	{
		result.clear();
		patch.clear();
		backtracking(n, k, 1);
		return result;
	}

private:
	vector<vector<int>> result;
	vector<int> patch;
	void backtracking(int n, int k, int startIndex)
	{
		if (patch.size() == k)
		{
			result.push_back(patch);
			return;
		}

		//for (int i = startIndex; i <= n; i++)
		//{
		//	patch.push_back(i);
		//	backtracking(n, k, i + 1);
		//	patch.pop_back();
		//}

		// ¼ôÖ¦²Ù×÷
		for (int i = startIndex; i <= n-(k-patch.size())+1; i++)
		{
			patch.push_back(i);
			backtracking(n, k, i + 1);
			patch.pop_back();
		}
	}

};
