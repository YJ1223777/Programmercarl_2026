#include "Array.h"

int main()
{
	// 二分查找
	//vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };
	//Array array;
	//cout << array.search(nums, 6) << endl;


	// 移除元素
	//vector<int> nums = { 3,2,2,3 };
	//Array array;
	//cout << array.removeElement(nums, 2) << endl;


	// 有序数组的平方
	//vector<int> A = { -7,-3,2,3,11 };
	//Array array;
	//vector<int> result = array.sortedSquares(A);
	//for (int i = 0; i < result.size(); i++)
	//{
	//	cout << result[i] << " ";
	//}


	// 长度最小的子数组
	//vector<int> nums = { 2,3,4,3,1,2 };
	//Array array;
	//cout << array.minSubArrayLen(nums, 7) << endl;


	// 螺旋矩阵II
	//Array array;
	//vector<vector<int>> res = array.generateMatrix(1);


	// 区间和
	//int n, a, b;
	//cin >> n;
	//vector<int> num(n);
	//vector<int> p(n);
	//int psum = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> num[i];
	//	psum += num[i];
	//	p[i] = psum;
	//}
	//while (cin >> a >> b)
	//{
	//	int sum;
	//	if (a == 0)
	//		sum = p[b];
	//	else
	//		sum = p[b] - p[a - 1];
	//	cout << sum << endl;
	//}


	// 开发商购买土地
	int n, m;
	cin >> n >> m;
	vector<vector<int>> num(n, vector<int>(m, 0));
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) 
		{
			cin >> num[i][j];
			sum += num[i][j];
		}
	}
	int res = INT32_MAX;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			count += num[i][j];
			if (j == m-1)
			{
				res = min(res, abs(sum - count - count));
			}
		}
	}
	count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			count += num[j][i];
			if (j == n - 1)
			{
				res = min(res, abs(sum - count - count));
			}
		}
	}
	cout << res << endl;

}
