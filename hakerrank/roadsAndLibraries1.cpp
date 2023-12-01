#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


// use dfs to find the number of cities in a subgraph
long dfs(  vector<vector<int>> &v, int source,vector<bool> &visited ){
    visited[source]=true;
    int ans =1;
    // cout<< "source is "<<source<<endl;
    for (int i=0; i<v[source].size(); i++){
        if(!visited[v[source][i]]){
            ans+=dfs(v,v[source][i],visited);
            // cout<< "ans is "<<ans<<endl;
        }
    }  
            return ans;

}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
// create a adjency list representation of the graph
   vector<vector<int>> v(n+1);

   for (int i=0; i<cities.size();i++){
    v[cities[i][0]].push_back(cities[i][1]);
    v[cities[i][1]].push_back(cities[i][0]);

   }
   
// group the cities into subcities
   vector<int> subCities;
   vector <bool> visited (n+1,false);
   for ( int i=1; i<=n;i++){
    if(!v[i].empty() && !visited[i]){
        subCities.push_back(dfs(v,i,visited));
           }
    else if(v[i].size()==0)subCities.push_back(1);
   }

// calculate the cost
int ans=0;
for ( int i=0; i<subCities.size();i++){
   cout<< "subCities"<< subCities[i]<<endl;}
for ( int i=0; i<subCities.size();i++){
    ans += min((subCities[i]-1)*c_road+c_lib,subCities[i]*c_lib);
    cout << "ans is "<<ans<<endl;


}
return ans;
    

}


int main(){
   //multiple test cases 
    int q;
    cin>>q;
    for (int i=0; i<q;i++){
        int n,m,c_lib,c_road;
        cin>>n>>m>>c_lib>>c_road;
        vector<vector<int>> cities(m);
        for (int j=0; j<m;j++){
            int a,b;
            cin>>a>>b;
            cities[j].push_back(a);
            cities[j].push_back(b);
        }
        cout<<roadsAndLibraries(n,c_lib,c_road,cities)<<endl;
    }


       return 0;
}
