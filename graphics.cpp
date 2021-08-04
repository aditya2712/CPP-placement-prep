#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;
// driver code
int main()
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int a=graphresult();
    cout<<a;


    //line(150, 150, 450, 150);



    getch();


    closegraph();
}
