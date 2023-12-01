#include <iostream>
using namespace std;


void prism( int G[6][6],int source){
int MST [6][6]={
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0}    
    };
    int visited[6]={0,0,0,0,0,0};
    int min=INT16_MAX;
    int u,v;
    visited[source]=1;
    int  mindistance, nextnode;
    int count=0;
    
    while( count <6){
             

        mindistance=INT16_MAX;
        cout<< "source ="<< source;
        for(int i=0;i<6;i++){
            // cout<<"i= "<<i<<endl ;
            // cout<< "G[source][i]= "<< G[source][i]<< " mindistance= "<<mindistance<<endl;

            if(G[source][i]<mindistance&&!visited[i] && G[source][i]!=0){
                mindistance=G[source][i];
                nextnode=i;
            }
        
        
        }
        MST[source][nextnode]=G[source][nextnode];
        source=nextnode;
        cout<< "Next node "<< nextnode<<endl;
        count++;
        }
     };

int main () {
 int G[6][6] ={
        {0,3,0,0,0,1},
        {3,0,2,0,10,0},
        {0,2,0,3,0,5},
        {0,0,3,0,5,0},
        {0,10,0,5,0,4},
        {1,0,5,0,4,0}
    };
    prism(G,0);
    return 0;
}