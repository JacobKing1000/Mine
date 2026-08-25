#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

long long matrixChainMultiplication(const vector<int>& arr) {
	const int matrixCount = static_cast<int>(arr.size()) - 1;
	if (matrixCount <= 1) {
		return 0;
	}

	vector<vector<long long>> dp(
		matrixCount, vector<long long>(matrixCount, 0));

	for (int length = 2; length <= matrixCount; ++length) {
		for (int left = 0; left + length <= matrixCount; ++left) {
			int right = left + length - 1;
			dp[left][right] = numeric_limits<long long>::max();

			for (int split = left; split < right; ++split) {
				long long cost = dp[left][split] + dp[split + 1][right] +
					1LL * arr[left] * arr[split + 1] * arr[right + 1];
				dp[left][right] = min(dp[left][right], cost);
			}
		}
	}

	return dp[0][matrixCount - 1];
}
