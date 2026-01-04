#include "Backtracking.h"

int main()
{
	//Backtracking back_track;
	Backtracking* back_track = new Backtracking();
	vector<vector<int>> result;
	result = back_track->combine(4, 2);
	cout << "Backtracking" << endl;
}
