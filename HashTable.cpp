#include "HashTable.h"

int main()
{
	HashTable hashTable;
	//string s = "anagram";
	//string t = "nagaram";
	//cout << hashTable.isAnagram(s, t) << endl;


	//vector<int> a = { 1,2 };
	//vector<int> b = { -2,-1 };
	//vector<int> c = { -1,2 };
	//vector<int> d = { 0,2 };
	//cout << hashTable.fourSumCount(a,b,c,d) << endl;

	//vector<int> nums = { -2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0 };
	vector<int> nums = { 0,0,0,1000000000,1000000000,1000000000,1000000000 };
	vector<vector<int>> res = hashTable.fourSum(nums, 1000000000);

}
