// C++ Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;
#define INF 0x3f3f3f3f



// djistra's algorithm using adjecency matrix
// void dijkstra(vector<vector<int>> adj,int V,int source){
//     //create a priority queue to store the vertices and their distance from the source
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//     //create a vector to store the distance of each vertex from the source
//     vector<int> dist(V+1,INF);
//     //create a vector to store the parent of each vertex
//     vector<int> parent(V+1,-1);
//     //create a vector to store the visited vertices
//     vector<bool> visited(V+1,false);
//     //push the source vertex and its distance from itself in the priority queue
//     pq.push(make_pair(0,source));
//     //set the distance of source from itself as 0
//     dist[source] = 0;
//     //while the priority queue is not empty
//     while(!pq.empty()){
//         //extract the vertex with minimum distance from the source
//         int u = pq.top().second;
//         //mark the vertex as visited
//         visited[u] = true;
//         //pop the vertex from the priority queue
//         pq.pop();
//         //for each vertex v adjacent to u
//         for(int v=0;v<=V;v++){
//             //if v is not visited and there is an edge between u and v and the distance of v from the source is greater than the distance of u from the source + the weight of the edge between u and v
//             if(!visited[v] && adj[u][v] && dist[v] > dist[u] + adj[u][v]){
//                 //update the distance of v from the source
//                 dist[v] = dist[u] + adj[u][v];
//                 //push the vertex v and its distance from the source in the priority queue
//                 pq.push(make_pair(dist[v],v));
//                 //update the parent of v as u
//                 parent[v] = u;
//             }
//         }
//     }
//     //print the distance of each vertex from the source
//     cout<< "Distance of each vertex from the source" << endl;
//     for(int i=1;i<=V;i++){
//         cout << dist[i] << " ";
//     }
//     cout << endl;
//     //print the parent of each vertex
//     cout << "Parent of each vertex" << endl;
//     for(int i=1;i<=V;i++){
//         cout << parent[i] << " ";
//     }
//     cout << endl;
//     //print the path from the source to each vertex
//     cout << "Path from the source to each vertex" << endl;
//     for(int i=1;i<=V;i++){
//         cout << i << " ";
//         int j = i;
//         while(parent[j] != -1){
//             cout << parent[j] << " ";
//             j = parent[j];
//         }
//         cout << endl;
//     }
// }

int  dijkstra ( vector<vector<int> > G, int n, int startnode, int endnode, vector<int> values){
   
    vector< vector<int> > cost(n, vector<int>(n, 0));
    vector<int> distance(n,0);
    vector<int> pred(n,0);

    int  count, mindistance, nextnode, i,j;
    vector<int> visited(n,0);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INT16_MAX;
            else
                cost[i][j]=G[i][j];
    for(i=0;i<n;i++){
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=-values[startnode];
    visited[startnode]=1;
    count=1;
    while(count<n-1){
        mindistance=INT16_MAX;
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i]){
                    distance[i]=mindistance+cost[nextnode][i] - values[nextnode];
                    pred[i]=nextnode;
                }
        count++;
    }
    for(i=0;i<n;i++)
        if(i==endnode){
            cout<<"\nDistance of node "<<i<<" ="<<distance[i];
            cout<<"\nPath="<<i;
            j=i;
            do{
                j=pred[j];
                cout<<"<-"<<j;
            }while(j!=startnode);
    }
    cout<<endl;
    return distance[endnode];
};



  
// Driver's code
int main()
{
    //input number of vertices
    int V;
    cin >> V;
    cout<< V;
    // input value at each vertex 
    vector<int> values(V+1,0);
    for(int i=0;i<V;i++){
        int j;
        cin >>  j;
        cin >>values[j];
    }

cout<< "values";
    //print the values
    for(int i=0;i<=V;i++){
        cout << values[i] << " ";
    }
    //input number of edges
    int E;
    cin >> E;
    // input the edge and weight  and add to the adjecency matrix 
    vector<vector<int>> adj(V+1,vector<int>(V+1,0));
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    //print the adjecency matrix
    for(int i=0;i<=V;i++){
        for(int j=0;j<=V;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    //input the source vertex
    int source;
    cin >> source;

    //call the djistra's algorithm
    dijkstra(adj,V,source,4,values);


  
    
  
    return 0;
}