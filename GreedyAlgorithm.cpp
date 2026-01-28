#include "GreedyAlgorithm.h"

int main()
{
	GreedyAlgorithm* ga = new GreedyAlgorithm();

	vector<int> g = { 1,2,3 };
	vector<int> s = { 3 };

	int res = ga->findContentChildren(g, s);

	cout << "GreedyAlgorithm" << endl;
	return 0;
}
