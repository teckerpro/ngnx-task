#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool brackets_check(string& brackets)
{
	vector<char> stack;
	stack.reserve(brackets.length());

	for (size_t i = 0; i < brackets.length(); i++) {
		if (brackets[i] == '[') {
			stack.push_back(brackets[i]);
			continue;
		}

		if (brackets[i] == ']') {
			if (!stack.empty()) {
				if (stack.back() == '[') {
					stack.pop_back();
				}
			} else {
				return false;
			} 
		}
	}

	if (stack.empty()) {
		return true;
	} else {
		return false;
	}
}

int main() {
	string brackets;

	cin >> brackets;

	cout << brackets_check(brackets);
	return 0;
}