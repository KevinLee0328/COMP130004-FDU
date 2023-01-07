#include <iostream>
using namespace std;
const int MaxValue = 2147483647;
int graph[5005][5005];
int dist[5005];
bool visited[5005];

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

void ShortestPath(int n, int s) {
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
	int n, m, s;
	cin >> n >> m >> s;
	initiate(n, m);
	ShortestPath(n, s);
	for (int i = 1; i <= n; i++) cout << dist[i] << " ";
	return 0;
}
