#include "Backtracking.h"

int main()
{
	//Backtracking back_track;
	Backtracking* back_track = new Backtracking();
	vector<vector<int>> result;
	//vector<string> str_list;

	//result = back_track->combine(4, 2);

	//result = back_track->combinationSum3(4, 1);

	//str_list = back_track->letterCombinations("23");

	vector<int> candidates = { 2, 3, 6, 7 };
	result = back_track->combinationSum(candidates, 7);

	//for (int i = 0; i < result.size(); i++) {       
	//	for (int j = 0; j < result[i].size(); j++) {  
	//		cout << result[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << "Backtracking" << endl;

	delete back_track;
}
