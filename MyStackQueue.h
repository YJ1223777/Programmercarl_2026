#pragma once

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;


class MyStackQueue
{
public:

    // 有效的括号
    bool isValid(string s) {
        stack<char> str;
        if (s.size() % 2 != 0)
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '{') str.push('}');
            else if (s[i] == '[') str.push(']');
            else if (s[i] == '(') str.push(')');
            else if (str.empty() || str.top() != s[i]) return false;
            else
            {
                str.pop();
            }
        }
        return str.empty();
    }


    // 删除字符串中的所有相邻重复项
    string removeDuplicates(string s) {
        stack<char> str;
        for (int i = 0; i < s.size(); i++)
        {
            if (!str.empty() && s[i] == str.top())
            {
                str.pop();
            }
            else
            {
                str.push(s[i]);
            }

        }
        string result;
        while (!str.empty())
        {
            result += str.top();
            str.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }


    // 逆波兰表达式求值
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            }
            else
            {
                st.push(stoll(tokens[i]));
            }
        }
        long long result = st.top();
        st.pop(); 
        return result;
    }


    // 滑动窗口最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result = {};
        MyQueue my_queue;

        for (int i = 0; i < k; i++)
        {
            my_queue.push(nums[i]);
        }
        result.push_back(my_queue.front());

        for (int j = k; j < nums.size(); j++)
        {
            my_queue.pop(nums[j - k]);
            my_queue.push(nums[j]);
            result.push_back(my_queue.front());
        }

        return result;
    }


    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& left, const pair<int, int>& right)
        {
            return left.second > right.second;
        }
    };


    // 前 K 个高频元素
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        for (unordered_map<int, int>::iterator it = map.begin(); it!=map.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }


private:
    // 实现一个单调队列
    class MyQueue
    {
    public:
        deque<int> que;

        void pop(int value) 
        {
            if (!que.empty() && value==que.front())
            {
                que.pop_front();
            }
        }

        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }

            que.push_back(value);

        }

        int front()
        {
            return que.front();
        }
    };

};


class MyStack {
public:
    queue<int> que;

    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;
        while (size--)
        {
            que.push(que.front());
            que.pop();
        }
        int res = que.front();
        que.pop();
        return res;
    }

    int top() {
        int size = que.size();
        size--;
        while (size--)
        {
            que.push(que.front());
            que.pop();
        }
        int res = que.front();
        que.push(que.front());
        que.pop();
        return res;
    }

    bool empty() {
        return que.empty();
    }
};


class MyQueue {
public:

    // 用栈实现队列
    //push(x) --将一个元素放入队列的尾部。
    //pop() --从队列首部移除元素。
    //peek() --返回队列首部的元素。
    //empty() --返回队列是否为空。

    stack<int> stcIn;
    stack<int> stcOut;

    MyQueue() {

    }

    void push(int x) {
        stcIn.push(x);
    }

    int pop() {
        if (stcOut.empty())
        {
            while (!stcIn.empty())
            {
                stcOut.push(stcIn.top());
                stcIn.pop();
            }
        }

        int res = stcOut.top();
        stcOut.pop();
        return res;
    }

    int peek() {
        int res = this->pop();
        stcOut.push(res);
        return res;
    }

    bool empty() {
        return stcIn.empty() && stcOut.empty();
    }

};

