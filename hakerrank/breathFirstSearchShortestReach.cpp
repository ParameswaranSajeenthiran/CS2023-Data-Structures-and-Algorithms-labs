#include <iostream>
#include <vector>
#include <queue>
using namespace std ;


// void bsf (int n ,vector<int> g[], vector<int > dis,int start){
//    vector <bool> visited (n+1,false);
//    queue < int> q;
//    q.push(start);
//    dis[start]=0;
//    while (q.empty()){
//     start= q.front();
//     q.pop();

//     for ( auto adjNode : g[start]){
//         if( !visited[adjNode]){
//             visited[adjNode]=true;
//             dis[adjNode]=dis[start]+ 6;
//             q.push(adjNode);
//         }
//     }

//    }




// }
 void printVector(vector <int>  &a) {
  cout << "The vector elements are : ";

   for(auto i : a)
  cout << i << ' ';
  cout<< endl;
}


vector<int> bfs(int n, int m, vector<vector<int>> &edges, int s) {
    // printVector(edges[0]);
vector <bool> visited (n+1,false);
vector <int> dist (n+1,-1);
queue < int> q;
vector< vector<int>> g(n+1);
// cout<< m;
int s_copy=s;
for (int i=0; i<m;i++){
    // cout<<"test" << edges[i][1];
    // print
    g[edges[i][0]].push_back(edges[i][1]);
    g[edges[i][1]].push_back(edges[i][0]); //directed graph
    // cout<< "node : "<< edges[i][0] <<" ";
        


}
// cout<< "printing vector ";
// for ( auto node : g){
//     printVector (node);
// }
// cout<< endl;
   q.push(s_copy);
   dist[s_copy]=0;
while (!q.empty()){
    s_copy= q.front();
    q.pop();
    
    // cout<< "printing vector ";
    // printVector( g[s_copy]);
    // cout<<endl;
    cout<< "s_copy  " << s_copy<< endl;
    

    for ( auto adjNode : g[s_copy]){
        cout<< "adjecent : " << adjNode<< " "<<endl;
        if( !visited[adjNode]){
            
            dist[adjNode]=dist[s_copy]+ 6;
            q.push(adjNode);
                visited[s_copy]=true;

        }
    }

   }
   vector<int> result ;
   for ( int i =0; i< dist.size() ; i++){
    if( i!= s && i!=0 )
    result.push_back( dist[i]);

   }
   return result;
}



void test_bfs(){
    int n=4;
    int m=2;
    vector<vector<int> >edges ={{1,2},{1,3}};
    vector<int>  result=bfs(n,m,edges,1);
    for ( int i =0; i< result.size() ;i++){
        
        cout<< result.at(i);
    }


}
// int main() {
//     int n = 3;  // Number of nodes
//     int m = 2;  // Number of edges

//     vector<vector<int>> edges = {{1, 2}, {2, 3}};  // Edges in the graph

//     int s = 1;  // Starting node

//     vector<int> result = bfs(n, m, edges, s);

//     // Expected output: [6, 12]
//     // Distance from node 1 to node 2 is 6
//     // Distance from node 1 to node 3 is 12
//     printVector(result);

//     return 0;
// }

// int main() {
//     int n = 4;  // Number of nodes
//     int m = 3;  // Number of edges

//     vector<vector<int>> edges = {{1, 2}, {3, 4}, {4, 2}};  // Edges in the graph

//     int s = 1;  // Starting node

//     vector<int> result = bfs(n, m, edges, s);

//     // Expected output: [6, -1, -1]
//     // Distance from node 1 to node 2 is 6
//     // Nodes 3 and 4 are disconnected from node 1
//     printVector(result);

//     return 0;
// }
int main() {
    int n = 4;  // Number of nodes
    int m = 4;  // Number of edges

    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 1}};  // Edges in the graph

    int s = 1;  // Starting node

    vector<int> result = bfs(n, m, edges, s);

    // Expected output: [6, 12, 6]
    // Distance from node 1 to node 2 is 6
    // Distance from node 1 to node 3 is 12
    // Distance from node 1 to node 4 is 6
    printVector(result);

    return 0;
}




// int main (){
//     test_bfs();
//     // test case 1
//     int n=4;
//     int m=2;
//     vector<vector<int> >edges ={{1,2},{1,3}};
//     vector<int>  result=bfs(n,m,edges,1);
//     for ( int i =0; i< result.size() ;i++){

//         cout<< result.at(i);
//     }
//     // test case 2
//     int n=3;
//     int m=1;
//    edges ={{2,3}};
//    result=bfs(n,m,edges,2);
//     for ( int i =0; i< result.size() ;i++){

//         cout<< result.at(i);
//     }


//     // test case 3
//     int n=5;
//     int m=3;
//  edges ={{1,2},{1,3},{3,4}};
//     result=bfs(n,m,edges,1);
//     for ( int i =0; i< result.size() ;i++){

//         cout<< result.at(i);
//     }

//     // test case 4
//     int n=6;
//     int m=5;
//     vector<vector<int> >edges ={{1,2},{1,3},{3,4},{2,5},{2,6}};
//     vector<int>  result=bfs(n,m,edges,1);
//     for ( int i =0; i< result.size() ;i++){

//         cout<< result.at(i);
//     }

//     // test case 5 with result 6 6 -1


//     int n=7;
//     int m=6;
//     vector<vector<int> >edges ={{1,2},{1,3},{3,4},{2,5},{2,6},{2,7}};
//     vector<int>  result=bfs(n,m,edges,1);
//     for ( int i =0; i< result.size() ;i++){

//         cout<< result.at(i);
//     }

//     // test case 6 with result 6 6 -1

//     int n=8;
//     int m=6;
//     vector<vector<int> >edges ={{1,2},{1,3},{3,4},{2,5},{2,6},{2,7}};
//     vector<int>  result=bfs(n,m,edges,1);
//     for ( int i =0; i< result.size() ;i++){

//         cout<< result.at(i);
//     }
































//     return 0;
     


// }