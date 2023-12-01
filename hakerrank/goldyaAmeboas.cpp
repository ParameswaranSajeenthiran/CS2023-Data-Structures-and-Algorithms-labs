#include <iostream>
#include <vector>
using namespace std;

// struct to store no of X and no of Y;
struct XY
{
    int x;
    int y;
};

// fucntion when X reporduces
XY XReproduce()
{
    XY xy;
    xy.x = 1;
    xy.y = 2;
    return xy;
}

XY YReproduce()
{
    XY xy;
    xy.x = 3;
    xy.y = 1;
    return xy;
}

XY MiracoulosReproduce()
{
    XY xy;
    xy.x = 1;
    xy.y = 3;
    return xy;
}


XY reproduceAndSum ( XY xy){
   
    XY xy1 = XReproduce();
    XY xy2 = YReproduce();
    XY xy3 = MiracoulosReproduce();
    xy.x = (xy1.x ) * xy.x + xy3.x  + xy.y * xy2.x +xy.x;
    xy.y = ( xy2.y ) * xy.y + xy3.y  + xy.x * xy1.y+  xy.y;
    return xy;
}


int main (){



    int x,y;
    cin>> x>> y;
    int n;
    cin>> n;
    XY xy;
    xy.x = x;
    xy.y = y;
    cout<< xy.x<< " "<< xy.y<< endl;
    for (int i=0; i<n; i++){
        xy = reproduceAndSum(xy);
        cout << i << "th "<< xy.x<< " "<< xy.y<< endl;
        // cout <<  " i th"<< i<< " "<< xy.x<< " "<< xy.y<< endl;
    }
    cout<< xy.x<< " "<< xy.y;
    


    return 0;
    }