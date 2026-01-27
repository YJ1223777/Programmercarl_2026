#include "Backtracking.h"

int main()
{
	//Backtracking back_track;
	Backtracking* back_track = new Backtracking();
	vector<vector<int>> result;
	vector<vector<string>> str_result;
	vector<string> str_list;

	//result = back_track->combine(4, 2);

	//result = back_track->combinationSum3(4, 1);

	//str_list = back_track->letterCombinations("23");

	//vector<int> candidates = { 2, 5, 2, 1, 2 };
	//result = back_track->combinationSum2(candidates, 5);

	//str_result = back_track->partition("aab");

	//str_list = back_track->restoreIpAddresses("25525511135");

	//vector<int> nums = { 1, 2, 3};
	//result = back_track->subsets(nums);

	//vector<int> nums = { 1, 2, 1 };
	//result = back_track->permuteUnique(nums);


	//str_result = back_track->solveNQueens(4);

	cout << "Backtracking" << endl;

	delete back_track;
}
