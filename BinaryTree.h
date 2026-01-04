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

struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val) :val(_val), left(nullptr), right(nullptr) {}
};


class BinaryTree
{
public:
	TreeNode* createTress(vector<int> nums)
	{
		if (nums.empty() || nums[0] == INT_MIN)
		{
			return nullptr;
		}

		TreeNode* root = new TreeNode(nums[0]);
		queue<TreeNode*> que;
		que.push(root);

		int i = 1;
		while (i < nums.size() && !que.empty())
		{
			TreeNode* cur = que.front();
			que.pop();

			// left
			if (i < nums.size() && nums[i]!= INT_MIN)
			{
				TreeNode* tmp_left = new TreeNode(nums[i]);
				cur->left = tmp_left;
				que.push(cur->left);
			}
			i++;

			// right
			if (i < nums.size() && nums[i] != INT_MIN)
			{
				TreeNode* tmp_right = new TreeNode(nums[i]);
				cur->right = tmp_right;
				que.push(cur->right);
			}
			i++;
		}

		return root;
	}

	// 递归遍历
	void traversal(TreeNode* cur, vector<int>& vec) 
	{
		if (cur==nullptr)
		{
			return;
		}

		// 调整vec.push_back(cur->val);的顺序 实现前中后序遍历
		traversal(cur->left, vec);
		traversal(cur->right, vec);
		vec.push_back(cur->val);
	}


	// 前序遍历（递归） 中左右
	//vector<int> preorderTraversal(TreeNode* root) {
	//	vector<int> result;
	//	traversal(root, result);
	//	return result;
	//}


	// 后序遍历（递归） 左右中
	//vector<int> postorderTraversal(TreeNode* root) {
	//	vector<int> result;
	//	traversal(root, result);
	//	return result;
	//}


	// 中序遍历（递归） 左中右
	//vector<int> inorderTraversal(TreeNode* root) {
	//	vector<int> result;
	//	traversal(root, result);
	//	return result;
	//}


	// 前序遍历（迭代）
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root==nullptr)
		{
			return result;
		}
		st.push(root);
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			result.push_back(cur->val);
			if (cur->right) st.push(cur->right);
			if (cur->left) st.push(cur->left);
		}
		return result;
	}


	// 后序遍历（迭代）
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == nullptr)
		{
			return result;
		}
		st.push(root);
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			result.push_back(cur->val);
			if (cur->left) st.push(cur->left);
			if (cur->right) st.push(cur->right);
		}
		reverse(result.begin(), result.end());
		return result;
	}


	// 中序遍历（迭代）
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		TreeNode* cur = root;
		while (cur!=nullptr && !st.empty())
		{
			if (cur != nullptr) 
			{
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = st.top();
				st.pop();
				result.push_back(cur->val);
				cur = cur->right;
			}
		}
		return result;
	}


	// 层序遍历
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> qt;
		vector<vector<int>> result;
		TreeNode* cur = root;

		if (cur == nullptr)
			return result;
		else
			qt.push(cur);

		while (!qt.empty())
		{
			int size = qt.size();
			vector<int> vec;
			for (int i = 0; i < size; i++)
			{
				TreeNode* tmp = qt.front();
				qt.pop();
				vec.push_back(tmp->val);
				if (tmp->left) qt.push(tmp->left);
				if (tmp->right) qt.push(tmp->right);
			}
			result.push_back(vec);
		}
		return result;
	}


	// 翻转二叉树 层序遍历
	//TreeNode* invertTree(TreeNode* root) {
	//	TreeNode* cur = root;
	//	queue<TreeNode*> qt;
	//	if (cur!=nullptr)
	//	{
	//		qt.push(cur);
	//	}
	//	while (!qt.empty())
	//	{
	//		int size = qt.size();
	//		for (int i = 0; i < size; i++)
	//		{
	//			TreeNode* tmp = qt.front();
	//			qt.pop();
	//			swap(tmp->left, tmp->right);
	//			// 把子节点加入队列
	//			if (tmp->left) qt.push(tmp->left);
	//			if (tmp->right) qt.push(tmp->right);
	//		}
	//	}
	//	return cur;
	//}


	// 翻转二叉树 递归
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)	return root;
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}


	// 对称二叉树 递归法
	//bool compare(TreeNode* left, TreeNode* right) {
	//	if (left == nullptr && right != nullptr) return false;
	//	else if (left != nullptr && right == nullptr) return false;
	//	else if (left == nullptr && right == nullptr) return true;
	//	else if (left->val != right->val) return false;
	//	bool outside = compare(left->left, right->right);
	//	bool inside = compare(left->right, right->left);
	//	return outside && inside;
	//}

	//bool isSymmetric(TreeNode* root) {
	//	if (root == nullptr)	return NULL;
	//	return compare(root->left, root->right);
	//}


	// 对称二叉树 迭代法
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		queue<TreeNode*> que;
		que.push(root->left);
		que.push(root->right);

		while (!que.empty())
		{
			TreeNode* left = que.front();
			que.pop();
			TreeNode* right = que.front();
			que.pop();
			if (left == nullptr && right == nullptr){
				continue;
			}
			if (!left || !right || left->val != right->val) {
				return false;
			}

			que.push(left->left);
			que.push(right->right);
			que.push(left->right);
			que.push(right->left);
		}
		return true;
	}


	// 二叉树的最大深度 递归（后序 求高度=最大深度）
	int getDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		int leftDepth = getDepth(root->left);
		int rightDepth = getDepth(root->right);
		int depth = 1 + max(leftDepth, rightDepth);
		return depth;
	}

	int maxDepth(TreeNode* root) {
		return getDepth(root);
	}


	// 二叉树的最小深度 递归 后序
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		int leftDepth = minDepth(root->left);
		int rightDepth = minDepth(root->right);
		if (root->left == nullptr && root->right != nullptr)
			return 1 + rightDepth;
		if (root->right == nullptr && root->left != nullptr)
			return 1 + leftDepth;
		int depth = 1 + min(leftDepth, rightDepth);
		return depth;
	}


	// 完全二叉树的节点个数
	int countNodes(TreeNode* root) {
		if (root == nullptr) return 0;
		int leftCounts = countNodes(root->left);
		int rightCounts = countNodes(root->right);
		int Count = 1 + leftCounts + rightCounts;
		return Count;
	}


	// 平衡二叉树
	int getHeight(TreeNode* node) {
		if (node == nullptr) return 0;
		int leftHeight = getHeight(node->left);
		if (leftHeight == -1) return -1;
		int rightHeight = getHeight(node->right);
		if (rightHeight == -1) return -1;
		return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
	}

	bool isBalanced(TreeNode* root) {
		return getHeight(root) == -1 ? false : true;
	}


	// 二叉树的所有路径
	void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
		path.push_back(cur->val);
		
		if (cur->left==nullptr && cur->right==nullptr)
		{
			string sPath;
			for (int i = 0; i < path.size()-1; i++)
			{
				sPath += to_string(path[i]);
				sPath += "->";
			}
			sPath += to_string(path[path.size() - 1]);
			result.push_back(sPath);
		}

		if (cur->left)
		{
			traversal(cur->left, path, result);
			path.pop_back();
		}

		if (cur->right)
		{
			traversal(cur->right, path, result);
			path.pop_back();
		}

	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		vector<int> path;

		if (root == nullptr) return result;
		traversal(root, path, result);
		return result;
	}


	// 左叶子之和
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr) return 0;
		int leftNum = sumOfLeftLeaves(root->left);
		if (root->left && root->left->left == nullptr && root->left->right == nullptr)
		{
			leftNum = root->left->val;
		}
		int rightNum = sumOfLeftLeaves(root->right);
		int sum = leftNum + rightNum;
		return sum;
	}


	// 找树左下角的值 层序遍历
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		if (root!=nullptr)
		{
			que.push(root);
		}
		int result = 0;
		while (!que.empty())
		{
			int size = que.size();
			TreeNode* tmp = que.front();
			result = tmp->val;
			for (int i = 0; i < size; i++)
			{
				TreeNode* node= que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return result;
	}


	// 路径总和
	bool traversal(TreeNode* cur, int count) {
		if (!cur->left && !cur->right && count == 0) return true;
		if (!cur->left && !cur->right && count != 0) return false;

		if (cur->left)
		{
			count -= cur->left->val;
			if (traversal(cur->left, count)) return true;
			count += cur->left->val;
		}

		if (cur->right)
		{
			count -= cur->right->val;
			if (traversal(cur->right, count)) return true;
			count += cur->right->val;
		}

		return false;
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) return false;
		return traversal(root, targetSum - root->val);
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		result.clear();
		path.clear();
		if (root == nullptr)
		{
			return result;
		}
		path.push_back(root->val);
		_traversal(root, targetSum - root->val);
		return result;
	}


	// 最大二叉树
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		TreeNode* node = new TreeNode(0);

		if (nums.size() == 1) {
			node->val = nums[0];
			return node;
		}

		int maxNum = INT_MIN;
		int maxIndex = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > maxNum) {
				maxNum = nums[i];
				maxIndex = i;
			}
		}

		node->val = maxNum;

		// left
		if (maxIndex > 0) {
			vector<int> newVec(nums.begin(), nums.begin() + maxIndex);
			node->left = constructMaximumBinaryTree(newVec);
		}

		// right
		if (maxIndex < nums.size() - 1) {
			vector<int> newVec(nums.begin() + maxIndex + 1, nums.end());
			node->right = constructMaximumBinaryTree(newVec);
		}

		return node;
	}


	// 合并二叉树
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;

		root1->val += root2->val;
		root1->left = mergeTrees(root1->left, root2->left);
		root1->right = mergeTrees(root1->right, root2->right);
		return root1;
	}


	// 二叉搜索树中的搜索
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr || root->val == val) return root;
		TreeNode* result = nullptr;
		if (root->val > val) result = searchBST(root->left, val);
		if (root->val < val) result = searchBST(root->right, val);
		return result;
	}


	// 验证二叉搜索树
	bool isValidBST(TreeNode* root) {
		traversal_middle(root);
		for (int i = 0; i < vec.size() - 1; i++)
		{
			if (vec[i] >= vec[i + 1]) return false;
		}
		return true;
	}


	// 二叉搜索树的最小绝对差
	int getMinimumDifference(TreeNode* root) {
		traversal_middle(root);
		int result = INT_MAX;
		for (int i = 0; i < vec.size() - 1; i++)
		{
			result = min(abs(vec[i] - vec[i + 1]), result);
		}
		return result;
	}


	// 二叉搜索树中的众数
	vector<int> findMode(TreeNode* root) {
		traversal_middle(root);
		unordered_map<int, int> map;
		for (int i = 0; i < vec.size(); i++)
		{
			map[vec[i]]++;
		}

		int maxFre = 0;
		for (const pair<int, int>& pair : map)
		{
			if (pair.second > maxFre)
				maxFre = pair.second;
		}

		vector<int> result;
		for (const pair<int, int>& pair : map)
		{
			if (pair.second == maxFre)
				result.push_back(pair.first);
		}

		return result;
	}


	// 二叉树的最近公共祖先
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || p == root || q == root) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left != nullptr && right != nullptr) return root;

		if (left == nullptr && right != nullptr) return right;
		else if (left != nullptr && right == nullptr) return left;
		else
		{
			return nullptr;
		}
	}


private:
	// 路径总和2
	vector<vector<int>> result;
	vector<int> path;

	void _traversal(TreeNode* cur, int count) {
		if (!cur->left && !cur->right && count == 0) { 
			result.push_back(path);
			return; 
		}

		if (!cur->left && !cur->right && count != 0) return ;

		if (cur->left)
		{
			path.push_back(cur->left->val);
			count -= cur->left->val;
			_traversal(cur->left, count);
			path.pop_back();
			count += cur->left->val;
		}

		if (cur->right)
		{
			path.push_back(cur->right->val);
			count -= cur->right->val;
			traversal(cur->right, count);
			path.pop_back();
			count += cur->right->val;
		}

		return;
	}


	// 验证二叉搜索树 采用中序遍历
	vector<int> vec;
	void traversal_middle(TreeNode* root)
	{
		if (root == nullptr) return;
		traversal_middle(root->left);
		vec.push_back(root->val);
		traversal_middle(root->right);
	}

};
