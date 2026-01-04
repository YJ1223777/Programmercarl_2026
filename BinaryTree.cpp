#include "BinaryTree.h"

int main()
{
	BinaryTree binary_tree;
	vector<int> nums = { 1,2,3,4,5,6,7 };
	TreeNode* root = binary_tree.createTress(nums);

	vector<int> result;
	//result = binary_tree.preorderTraversal(root);

	//vector<vector<int>> result;
	//result = binary_tree.levelOrder(root);

	TreeNode* new_root = binary_tree.invertTree(root);
	result = binary_tree.preorderTraversal(new_root);


}
