class Solution {
public:
	/* Implemented by: Hantang Zhou @ Oct 15, 2018
	 * Time complexity: O(nm), where n and m is the shape of the imput matrix
	 * Space complexity: O(1)
	 */
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		spiralOrderHelper(ret, matrix);
		return ret;
	}

	void spiralOrderHelper(vector<int>& v, vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix.front().size();
		if (n == 0) return;

		// push and erase the first row
		for (int i = 0; i < n; i++) {
			v.push_back(matrix.front()[i]);
		}
		matrix.erase(matrix.begin());

		m = matrix.size();
		if (m == 0) return;

		for (int i = 0; i < m; i++) {
			v.push_back(matrix[i].back());
			if (matrix[i].size() > 0) matrix[i].erase(matrix[i].end() - 1); // erase last element
		}

		n = matrix.front().size();
		if (n == 0) return;

		for (int i = n - 1; i >= 0; i--) {
			v.push_back(matrix.back()[i]);
		}
		matrix.erase(matrix.end() - 1);

		m = matrix.size();
		if (m == 0) return;

		for (int i = m - 1; i >= 0; i--) {
			v.push_back(matrix[i].front());
			matrix[i].erase(matrix[i].begin());
		}

		spiralOrderHelper(v, matrix);
	}
};