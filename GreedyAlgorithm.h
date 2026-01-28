#pragma once

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <numeric>  
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class GreedyAlgorithm
{
public:

    // 455. ·Ö·¢±ý¸É
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int index = s.size() - 1;

        for (int i = g.size() - 1; i >= 0; i--)
        {
            if (index >= 0 && s[index] >= g[i])
            {
                res++; 
                index--;
            }
        }
        return res;
    }


private:


};

