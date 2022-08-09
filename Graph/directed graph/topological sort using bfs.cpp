
class Graph {
	list<int> *l;
	int v;
public:
	Graph(int v) {
		this->v = v;
		l = new list<int> [v];
	}
	void addEdge(int x, int y) {
		//directed graph
		l[x].push_back(y);
	}
	void topological_sort() {
		//indegree
		int *indegree = new int[v];
		// 0 indegree
		for(int i = 0; i < v; ++i) {
			indegree[i] = 0;
		}
		//update indegree by traversing edges x -> y
		//indegree[y]++;
		for(int i = 0; i < v; ++i) {
			for(auto x : l[i]) {
				indegree[x]++;
			}
		}
		//bfs
		queue<int> q;
		//1st step : find nodes with 0 indegree
		for(int i = 0; i < v; ++i) {
			if(indegree[i] == 0) {
				q.push(i);
			}
		}
		//start removing elements from the queue
		while(!q.empty()) {
			int node = q.front();
			cout << node << " ";
			q.pop();
			//iterate over the nbrs and reduce their indegree by 1
			for(auto nbr : l[node]) {
				indegree[nbr]--;
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}
};
