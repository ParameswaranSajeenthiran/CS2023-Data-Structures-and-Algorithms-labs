
#include <iostream>
using namespace std;


int findNextNode(int distance [6],int visited[6]){
    int min=0;
    for (int i=0;i<6; i++){
        if( distance[min]<min){
            if( visited[i]==0){
                min=i;
            }
            
        }
      
    }

return min;
}

void relax(int  distances[6],int v , int source ){
    if(distances[v]+distances[source] <distances[v] ){
        distances[v]=distances[v]+distances[source];
    }
}


int dijkstra( int G[6][6], int source ,int destination){
int distances[6], visited[6], count =0;
cout<< source<<endl ;
 for (int i=0; i< 6 ; i++ ){
    if (source!=i){
        distances[i]=INT16_MAX;
        visited[i] =0;
    }else {
        distances[i]=0;
        visited[i]=1;

    }; 
   
 }
 cout<< source<<endl ;


 while ( count <= 6){
    cout<< source<<endl ;

    for ( int i =0; i< 6 ;i++){
        if(G[source][i]!=0 && visited[i]!=1){
            relax(distances,i,source);
        }
        
    }
     source= findNextNode (distances,visited);
     count++;
     cout<< "source "+ source <<endl;
 } 
}

int  main(){
  
    int G[6][6] ={
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };

    dijkstra(G, 0, 4);
    return 0;
};