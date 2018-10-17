class Solution {
public:
	/* Implemented by: Hantang Zhou @ Oct 16, 2018
	 * Time complexity: O(nk), where n is the length of the vector
	 * Space complexity: O(n)
	 */
	int trap(vector<int>& height) {
		if (height.size() == 0) return 0;
		vector<int> max_left(height), max_right(height);
		int curr_max = 0;
		for (int i = 0; i < height.size(); i++) {
			max_left[i] = curr_max;
			curr_max = height[i] > curr_max ? height[i] : curr_max;
		}
		curr_max = 0;
		for (int i = height.size() - 1; i >= 0; i--) {
			max_right[i] = curr_max;
			curr_max = height[i] > curr_max ? height[i] : curr_max;
		}

		int ret = 0;

		for (int i = 0; i < height.size(); i++) {
			ret += min(max_right[i], max_left[i]) - height[i] > 0 ? min(max_right[i], max_left[i]) - height[i] : 0;
		}
		return ret;
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

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> height = stringToIntegerVector(line);

		int ret = Solution().trap(height);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}