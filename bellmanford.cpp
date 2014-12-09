
#include <vector>


using namespace std;


struct edge
{
	int from, to;
	double cost;
	edge(){}
	edge(int _from, int _to, double _cost) {
		from = _from, to = _to, cost = _cost;
	}
};
vector<edge>edges;

const int MX = 10000;//set MAX no of nodes here
double dist[MX];
int n;
bool bellmaford(int src) {

	fill(dist, dist+n+1, 1<<28);

	dist[src] = 0;

	bool flag = true;
	bool isDone = false;
	for (int i = 0; i < n && !isDone; ++i)
	{
		isDone = true;
		for (int j = 0; j < (int)edges.size(); ++j)
		{
			if(dist[edges[j].to] > dist[edges[j].from] + edges[j].cost) {
				isDone = false;
				dist[edges[j].to] = dist[edges[j].from] + edges[j].cost;
				if(i == n-1) 
					flag = false;
			}
		}
	}
	return flag;
}

int main() {

	return 0;
}