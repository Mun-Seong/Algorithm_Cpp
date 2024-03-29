// Baekjoon
// 1956 운동

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define	INF	999999999

int	V, E;
int	adj[401][401];
int	dist[401][401];

void	Floyd(void)
{
	// init dist
	for (int i=1;i<=V;++i) {
		for (int j=1;j<=V;++j) {
			if (i == j)
				continue;
			if (adj[i][j])
				dist[i][j] = adj[i][j];
		}
	}
	// calculate shortest
	for (int r=1;r<=V;++r) {
		for (int i=1;i<=V;++i) {
			for (int j=1;j<=V;++j) {
				if (dist[i][r] && dist[r][j]) {
					if (dist[i][j] != 0)
						dist[i][j] = std::min(dist[i][j], dist[i][r] + dist[r][j]);
					else
						dist[i][j] = dist[i][r] + dist[r][j];
				}
			}
		}
	}
}

int	main()
{
	// input
	std::cin >> V >> E;
	for (int i=0;i<E;++i) {
		int	a, b, c;
		std::cin >> a >> b >> c;
		adj[a][b] = c;
	}

	// solution
	int		ans(999999999);
	bool	check(false);
	Floyd();
	for (int i=1;i<=V;++i) {
		if (dist[i][i]) {
			ans = std::min(ans, dist[i][i]);
			check = true;
		}
	}
	if (check)
		std::cout << ans << '\n';
	else
		std::cout << -1 << '\n';
// 0 1 3
// X 0 2
// X 1 0

// dist[2][3] + dist[3][2]
// or
// dist[1][2] + dist[2][3] + dist[3][1]

	return (0);
}