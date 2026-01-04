#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class String
{
public:

	// 反转字符串
    void reverseString(vector<char>& s) {
		for (int i = 0, j=s.size()-1; i <= j; i++, j--)
		{
			swap(s[i], s[j]);
		}
    }


	// 反转字符串 II
	string reverseStr(string s, int k) 
	{
		for (int i = 0; i < s.size(); i+=2*k)
		{
			if ((i + k) < s.size()) 
			{
				reverse(s.begin() + i, s.begin() + i + k);
			}
			else
			{
				reverse(s.begin() + i, s.end());
			}
		}
		return s;
	}


	// 自定义反转字符串
	void my_reverse(string& s, int start, int end)
	{
		for (int i = start, j=end; i < j; i++, j--)
		{
			swap(s[i], s[j]);
		}
	}


	// 去除多余的空格
	void removeExtraSpaces(string& s)
	{
		int index = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] != ' ')
			{
				if (index != 0) s[index++] = ' ';
				while (s[i]!=' ' && i < s.size())
				{
					s[index++] = s[i++];
				}
			}
		}
		s.resize(index);
	}


	string reverseWords(string s) {
		removeExtraSpaces(s);
		my_reverse(s, 0, s.size() - 1);
		int start = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ' && i < s.size()) {
				my_reverse(s, start, i-1);
				start = i + 1;
			}
			if (i == s.size()-1)
			{
				my_reverse(s, start, s.size()-1);
			}
		}
		return s;
	}

};
