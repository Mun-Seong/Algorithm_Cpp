// Baekjoon
// 14002 가장 긴 증가하는 부분 수열 4

#include <iostream>
#include <algorithm>
#include <vector>

int	n;
int	seq[1001];
int	dp[1001];
int	path[1001];

int	main()
{
	// input
	std::cin >> n;
	for (int i=1;i<=n;++i)
		std::cin >> seq[i];
	
	// solution
	int	res(0), max_idx(0);
	for (int i=1;i<=n;++i) {
		dp[i] = 1;
		path[i] = -1;
	}
	for (int i=2; i<=n; ++i)
	{
		for (int j=1;j<i;++j)
		{
			if (seq[i] > seq[j])
				dp[i] = std::max(dp[i], dp[j] + 1);
			if (dp[i] == dp[j] + 1)
				path[i] = j;
		}
	}
	for (int i=1;i<=n;++i) {
		if (res < dp[i]) {
			res = dp[i];
			max_idx = i;
		}
	}
	std::cout << res << std::endl;
	std::vector<int>	ans;	
	for (int i=max_idx;i>=1;--i) {
		if (dp[i] == res) {
			ans.push_back(seq[i]);
			res--;
		}
	}
	int	size = ans.size();
	for (int i=0;i<size;++i) {
		std::cout << ans.back() << ' ';
		ans.pop_back();
	}
	return (0);
}