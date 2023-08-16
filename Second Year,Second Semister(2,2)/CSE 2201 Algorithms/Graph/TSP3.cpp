#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
#define n 4
int TSP(int graph[n][n],int src,vector<int> &ans){
	vector<int>vertex,vec;
	for(int i=0;i<n;i++){
		if(i != src) 
			vertex.push_back(i);
	}
	int min_cost = INT_MAX;
	do{
		int current_weight = 0;
		int k = src;
		vec.push_back(src);
		for(int i=0;i<vertex.size();i++){
			current_weight += graph[k][vertex[i]];
			k = vertex[i];
			vec.push_back(k);
		}
		current_weight += graph[k][src];
		vec.push_back(src);
		if(min_cost > current_weight){
			min_cost = current_weight;
			ans = vec;
			vec.clear();
		}
		else vec.clear();
	}while(next_permutation(vertex.begin(),vertex.end()));
	return min_cost;
}
int main(){
	code();
	int graph[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	}
	vector<int>ans;
	int src=0;
	int cost = TSP(graph,src,ans);
	cout << "Minimum Path is:\n";
	for(auto it:ans){
		cout << it+1 << " ";
	}
	cout << "\nTotal Cost: " << cost << endl;
}
/*
0 4 1 3
4 0 2 1
1 2 0 5
3 1 5 0
cost: 7(1-3-2-4-1)

0 5 7 3
2 0 4 2
5 2 0 3
4 2 3 0
Cost:10(1-4-3-2-1)

0 1 2 1
1 0 2 3
2 2 0 3
1 3 3 0
Cost: 7(1-2-3-4-1)
*/