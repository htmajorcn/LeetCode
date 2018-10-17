class Solution {
public:
	/* Implemented by: Hantang Zhou @ Oct 15, 2018
	 * Time complexity: O(n), where n is the length of the vector
	 * Space complexity: O(n) since I do not want to change the input
	 *					O(1) if I choose to change the input
	 */
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ret(digits);
		int carry = 0;
		ret.back() = ret.back() + 1;
		for (auto it = ret.end() - 1; it >= ret.begin(); it--) {
			if (*it / 10 == 1) {
				*it = *it - 10;
				carry = 1;
				continue;
			}
			else {
				if (carry) {
					if ((*it + carry) / 10) {
						carry = 1;
						*it = 0;
					}
					else {
						*it = (*it + carry);
						carry = 0;
					}
				}
			}
		}
		if (carry)
			ret.insert(ret.begin(), 1);
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

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> digits = stringToIntegerVector(line);

		vector<int> ret = Solution().plusOne(digits);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}