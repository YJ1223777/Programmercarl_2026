#include "Backtracking.h"

int main()
{
	//Backtracking back_track;
	Backtracking* back_track = new Backtracking();
	vector<vector<int>> result;
	vector<string> str_list;

	//result = back_track->combine(4, 2);

	//result = back_track->combinationSum3(4, 1);

	str_list = back_track->letterCombinations("23");

	cout << "Backtracking" << endl;
	delete back_track;
}
