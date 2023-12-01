#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



// dijstra allgorithm
void  dijstra (vector<vector<int> > graph, int source, int destination) {
    // number of cities
    int n = graph.size();
    // distance array
    vector<int> distance(n, INT16_MAX);
    // visited array
    vector<bool> visited(n, false);
    // parent array
    vector<int> parent(n, -1);

    // distance of source from source is 0
    distance[source] = 0;

    // loop for n-1 times
    for (int i=0; i<n-1; i++) {
        // find the minimum distance vertex from the set of unvisited vertices
        int minDistance = INT16_MAX;
        int minDistanceVertex = -1;
        for (int j=0; j<n; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                minDistanceVertex = j;
            }
        }

        // mark the minDistanceVertex as visited
        visited[minDistanceVertex] = true;

        // update the distance array
        for (int j=0; j<n; j++) {
            if (!visited[j] && graph[minDistanceVertex][j] && distance[minDistanceVertex] != INT16_MAX && distance[minDistanceVertex] + graph[minDistanceVertex][j] < distance[j]) {
                distance[j] = distance[minDistanceVertex] + graph[minDistanceVertex][j];
                parent[j] = minDistanceVertex;
            }
        }
    }

    // print the distance array
    for (int i=0; i<n; i++) {
        cout<< i<< " "<< distance[i]<< endl;
    }

    // print the path from source to destination
    int i = destination;
    while (i != -1) {
        cout<< i<< " ";
        i = parent[i];
    }
    cout<< endl;
}



int main () {
    // input number of cities
    int n;
    cin>> n;
    // input number of roads
    int m;
    cin>> m;
    // cout<< n<< " "<< m<< endl;

    // input graph as adjacency matrix
    vector<vector<int> > graph(n, vector<int>(n, 0));
    for (int i=0; i<m; i++) {
        // cout<< i<< endl;
        int a, b, c;
        cin>> a>> b>> c;

        graph[a][b] = c;
        graph[b][a] = c;
        // cout<< a<< " "<< b<< " "<< c<< endl;
    }

    // input source and destination
    int source, destination;
    cin>> source>> destination;
    dijstra(graph, source, destination);






    return 0;
}
