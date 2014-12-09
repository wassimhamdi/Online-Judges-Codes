#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;

const int MX = 1000;//set here maximum no of nodes
int graph[MX][MX];
const int oo = (int)1e9;
int n;
void warshal() {

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}
void constructGraph(){
	int m;
	for (int i = 0; i < n; ++i) {
		fill(graph[i], graph[i]+n+2, oo);
		graph[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		graph[x][y] = c;
		graph[y][x] = c;// for undirected graphs
	}
}
int main() {

	return 0;
}