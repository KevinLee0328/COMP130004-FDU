#include <iostream>
using namespace std;
const int MaxValue = 2147483647;
int graph[5005][5005];
int dist1[5005];
int distn[5005];

void initiate(int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = MaxValue;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w < graph[u][v]) graph[u][v] = w;
	}
}

void ShortestPath(int n, int s, int dist[]) {
	bool visited[5005];
	for (int i = 1; i <= n; i++) {
		dist[i] = graph[s][i];
		visited[i] = false;
	}
	visited[s] = true;
	dist[s] = 0;
	for (int i = 0; i < n - 1; i++) {
		int u = s, min = MaxValue;
		for (int j = 1; j <= n; j++) {
			if (!visited[j] && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		visited[u] = true;
		for (int k = 1; k <= n; k++) {
			if (!visited[k] && graph[u][k] < MaxValue && dist[u] + graph[u][k] < dist[k]) {
				dist[k] = dist[u] + graph[u][k];
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	initiate(n, m);
	ShortestPath(n, 1, dist1);
	ShortestPath(n, n, distn);
	int min = MaxValue;
	for (int i = 2; i < n; i++) {
		if (dist1[i] < MaxValue && distn[i] < MaxValue) {
			if (dist1[i] + distn[i] < min) {
				min = dist1[i] + distn[i];
			}
		}
	}
	if (min < MaxValue) cout << min;
	else cout << -1;
	return 0;
}