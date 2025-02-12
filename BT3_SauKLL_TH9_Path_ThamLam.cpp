#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int to, weight;
};

vector<int> greedyPath(int start, int end, vector<vector<Edge>>& graph ){
	int n = graph.size();
	vector<bool> visited(n, false);
	vector<int> path;
	int current = start;
	
	path.push_back(current);
	visited[current] = true;
	
	while(current != end){
		int nextNode = -1;
		int minWeight = INT_MAX;
		
		for(Edge edge : graph[current]){
			if(!visited[edge.to] && edge.weight < minWeight){
				minWeight = edge.weight;
				nextNode = edge.to;
			}
		}
		
		if(nextNode == -1){
			cout << "Khong tim tahy duong di \n";
			return {};
		}
		
		current = nextNode;
		visited[current] = true;
		path.push_back(current);
	}
	
	return path;
}

int main(){
	int n = 9;
	vector<vector<Edge>> graph(n);
	vector<tuple<int, int, int>> edges = {
		{0, 2, 16},
		{0, 3, 10},
		{0, 4, 10},
		{2, 3, 18},
		{2, 7, 2},
		{3, 4, 7},
		{3, 5, 7},
		{3, 6, 8},
		{4, 8, 9},
		{5, 6, 2},
		{5, 7, 15},
		{5, 1, 3},
		{6, 8, 4},
		{6, 1, 8},
		{1, 8, 5},
		{1, 7, 12}
	};
	
	for(auto [u, v, w] : edges){
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	
	int A = 0, B= 5;
	vector<int> path = greedyPath(A, B, graph);
	
	if(!path.empty()){
		cout << "Duong di ngan nhat la: \n";
		for(int node : path) {
			cout << node << " ";
		}
		cout << "\n";
	}
	return 0;
}
