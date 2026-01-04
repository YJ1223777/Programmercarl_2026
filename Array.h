#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Array
{
public:
	// 704 二分查找
	int search(vector<int>& nums, int target) 
	{
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int middle = left + (right - left) / 2;
			if (nums[middle] < target) {
				left = middle + 1;
			}
			else if (nums[middle] > target) {
				right = middle - 1;
			}
			else
			{
				return middle;
			}
				
		}
		return -1;
	}

	// 27 移除元素
	int removeElement(vector<int>& nums, int val) 
	{
		int slowIndex = 0;
		int fastIndex = 0;
		while (fastIndex < nums.size())
		{
			if (nums[fastIndex] != val) 
			{
				nums[slowIndex++] = nums[fastIndex];
			}
			fastIndex++;
		}
		return slowIndex;
	}

	// 977 有序数组的平方
	vector<int> sortedSquares(vector<int>& A)
	{
		int k = A.size() - 1;
		vector<int> res(A.size(), 0);
		for (int i = 0, j = A.size() - 1; i <= j;)
		{
			if (A[i] * A[i] < A[j] * A[j]) {
				res[k--] = A[j] * A[j];
				j--;
			}
			else {
				res[k--] = A[i] * A[i];
				i++;
			}
		}
		return res;
	}

	// 209 长度最小的子数组
	int minSubArrayLen(vector<int>& nums, int s)
	{
		// 暴力解法 双层for循环
		//int result = INT32_MAX;
		//int sum = 0;
		//int subLength = 0;
		//for (int i = 0; i < nums.size(); i++)
		//{
		//	sum = 0;
		//	for (int j = i; j < nums.size(); j++) 
		//	{
		//		sum += nums[j];
		//		if (sum >= s)
		//		{
		//			subLength = j - i + 1;
		//			result = result > subLength ? subLength : result;
		//		}
		//	}
		//}
		//return result == INT32_MAX ? 0 : result;


		// 滑动窗口法
		int i = 0;
		int sum = 0;
		int result = INT32_MAX;
		int subLength = 0;
		for (int j = 0; j < nums.size(); j++)
		{
			sum += nums[j];
			while (sum >= s)
			{
				subLength = j - i + 1;
				result = result > subLength ? subLength : result;
				sum -= nums[i];
				i++;
			}
		}
		return result == INT32_MAX ? 0 : result;
	}

	// 59 螺旋矩阵 II
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> Matrix(n, vector<int>(n, 0));
		int loop = n / 2;
		int mid = n / 2;
		int startx = 0;
		int starty = 0;
		int offset = 1;
		int count = 1;
		int i, j = 0;
		while (loop--)
		{
			i = startx;
			j = starty;
			for (j;j < n - offset;j++)
			{
				Matrix[i][j] = count++;
			}
			for (i; i < n - offset; i++)
			{
				Matrix[i][j] = count++;
			}
			for (j; j > starty; j--)
			{
				Matrix[i][j] = count++;
			}
			for (i; i > startx; i--)
			{
				Matrix[i][j] = count++;
			}
			startx++;
			starty++;
			offset++;
		}
		if (n % 2 != 0)
		{
			Matrix[mid][mid] = count;
		}
		return Matrix;
	}

};
