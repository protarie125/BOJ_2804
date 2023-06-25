#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

string str_a;
string str_b;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> str_a >> str_b;

	auto idx_a = int{ 0 };
	auto idx_b = int{ 0 };
	auto is_found = bool{ false };
	for (auto i = 0; !is_found && i < str_a.length(); ++i) {
		for (auto j = 0; !is_found && j < str_b.length(); ++j) {
			if (str_a[i] == str_b[j]) {
				idx_a = i;
				idx_b = j;
				is_found = true;
				break;
			}
		}
	}

	auto ans = vector<vector<char>>(str_b.length(), vector<char>(str_a.length(), '.'));
	for (auto i = 0; i < str_a.length(); ++i) {
		ans[idx_b][i] = str_a[i];
	}
	for (auto i = 0; i < str_b.length(); ++i) {
		ans[i][idx_a] = str_b[i];
	}

	for (const auto& row : ans) {
		for (const auto& x : row) {
			cout << x;
		}
		cout << '\n';
	}

	return 0;
}