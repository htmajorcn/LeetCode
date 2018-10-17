/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int max = 0;

	/* Implemented by: Hantang Zhou @ Oct 14, 2018
	 * Time complexity: O(n^2), where n is the number of nodes in the tree
	 * Space complexity: O(1) if I choose to change the input
	 */
	int longestUnivaluePath(TreeNode* root) {
		if (!root) return 0;
		pathHelper(root);
		longestUnivaluePath(root->left);
		longestUnivaluePath(root->right);
		return max;
	}
	int pathHelper(TreeNode* n) {
		if (!n) return 0;
		int left = -1;
		if (n->left && n->left->val == n->val)
			left = pathHelper(n->left);
		int right = -1;
		if (n->right && n->right->val == n->val)
			right = pathHelper(n->right);
		if (right + left + 2 > max)
			max = right + left + 2;
		return right > left ? right + 1 : left + 1;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

int main() {
	string line;
	while (getline(cin, line)) {
		TreeNode* root = stringToTreeNode(line);

		int ret = Solution().longestUnivaluePath(root);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}