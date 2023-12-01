/*
 * SSSP.cpp
 *
 *  Created on: Jun 1, 2023
 *      Author: Dinithi Liyanage
 */

#include <iostream>
#include <vector>
#include<limits>
using namespace std;

//Find the index with the minimum distance
int minDistance(vector<int> distance, vector<bool> visited){
	int min = INT_MAX;
	int min_index;
	for(int  i=0; i<6; i++){
		if(distance[i] <= min && visited[i] == false){
			min = distance[i];
			min_index = i;
		}
	}
	return min_index;
}

//Return distances from a selected source node
vector<int> Dijkstra(int source, vector<vector<int>> adj){
	vector<bool> visited(6, false);
	vector<int> distance(6, numeric_limits<int>::max());
	distance[source] = 0;
	int vertex = source;
	while(visited[vertex] == false){
		for(int i =0; i<6; i++){
			if(adj[vertex][i] != 0 && visited[i] == false){
				int new_cost = distance[vertex] + adj[vertex][i];
				//Update distance if lower
				if(distance[i] > new_cost){
					distance[i] = new_cost;
				}
			}
		}
		visited[vertex] = true;
		vertex = minDistance(distance, visited);
	}
	return distance;
}

int main(){
	vector<vector<int>> adj = {
	{0, 10, 0, 0, 15, 5},
	{10, 0, 10, 30, 0, 0},
	{0, 10, 0, 12, 5, 0},
	{0, 30, 12, 0, 0, 20},
	{15, 0, 5, 0, 0, 0},
	{5, 0, 0, 20, 0, 0}};

	vector<vector<int>> shortest_paths;

	//Calculate distances for each node as source and add to the matrix
	vector<int> row_0 = Dijkstra(0, adj);
	shortest_paths.push_back(row_0);

	vector<int> row_1 = Dijkstra(1, adj);
	shortest_paths.push_back(row_1);

	vector<int> row_2 = Dijkstra(2, adj);
	shortest_paths.push_back(row_2);

	vector<int> row_3 = Dijkstra(3, adj);
	shortest_paths.push_back(row_3);

	vector<int> row_4 = Dijkstra(4, adj);
	shortest_paths.push_back(row_4);

	vector<int> row_5 = Dijkstra(5, adj);
	shortest_paths.push_back(row_5);

	//Find the avg distance from each source node to other nodes
	float min_distance = INT_MAX;
	vector<float> avg_distance(6);
	for(int i=0; i<6; i++){
		int source_sum = 0;
		float avg_dist = 0;
		for(int j=0; j<6; j++){
			cout<<"source_node: "<<i <<" destination: "<<j<< " -> "<<shortest_paths[i][j]<<endl;
			source_sum += shortest_paths[i][j];
		}
		avg_dist = source_sum /5.0;
		avg_distance[i] = avg_dist;
		if(avg_dist < min_distance){
			min_distance = avg_dist;
		}
	}
	cout<<"City with the smallest time to each city: ";
	for(int i=0; i<6; i++){
		if(avg_distance[i] == min_distance){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	cout<<"Average distance to each city from source city:"<< min_distance<<endl;

	return 0;
}