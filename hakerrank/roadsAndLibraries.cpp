#include <iostream>
#include <vector>
#include <list>
using namespace std;




long dfs(  vector<vector<int>> &v, int source,vector<bool> visited ){
    visited[source]=true;
    int ans =1;
    for (int i=0; i<v[i].size(); i++){
        if(!visited[v[source][i]]){
            ans+=dfs(v,v[source][i],visited);
        }
    }  

}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
   vector<vector<int>> v(n+1);
   for (int i=0; i<cities.size();i++){
    v[cities[i][0]].push_back(cities[i][1]);
    v[cities[i][1]].push_back(cities[i][0]);

   }

   vector<int> subCities;
   vector <bool> visited (n+1,false);
   for ( int i=1; i<n;i++){
    if(v[i].size()>=0 && !visited[i]){
        subCities.push_back(dfs(v,i,visited));
    }
    else if(v[i].size()==0)subCities.push_back(1);
   }
long ans;
for ( int i=0; i<subCities.size();i++){
    ans += min((subCities[i]-1)*c_road+c_lib,subCities[i]*c_lib);
}
    

}




int main(){
    int q;
    cin>>q;
    while(q--){
        int n,m,c_lib,c_road;
        cin>>n>>m>>c_lib>>c_road;
        vector<vector<int>> cities(m);
        for (int i=0; i<m;i++){
            int u,v;
            cin>>u>>v;
            cities[i].push_back(u);
            cities[i].push_back(v);
        }
        cout<<roadsAndLibraries(n,c_lib,c_road,cities)<<endl;
    }
    



    return 0;
}