
//this program is ccmplete

#include<bits/stdc++.h>
using namespace std;


int i,j;
int a[9][9];


bool valid(int, int, int);
bool unassignedcell(int &r,int &c);
bool solve();

bool unassignedcell(int &r,int &c)
{
    for(r=0;r<9;r++)
    {
        for(c=0;c<9;c++)
        {
            if(a[r][c]==0)
            {
                return true;
            }
        }
    }
    return false;
}


bool valid(int r,int c,int val)
{
    for(i=0;i<9;i++)
    {
        if(a[i][c]==val)
            return false;
    }
    for(j=0;j<9;j++)
    {
        if(a[r][j]==val)
            return false;
    }
    int baserow=r/3;
    int basecol=c/3;
    for(i=baserow*3;i<baserow*3+3;i++)
    {
        for(j=basecol*3;j<basecol*3+3;j++)
        {
            if(a[i][j]==val)
                return false;
        }
    }
    return true;
}

bool solve()
{
    int r,c;
    if(unassignedcell(r,c)==false)
        return true;
    for(int val=1;val<10;val++)
    {
        if(valid(r,c,val)==true)
        {
            a[r][c]=val;
            if(solve()==true)
                return true;
            a[r][c]=0;
        }
    }
    return false;
}

int main()
{
    cout<<"Enter sudoku:\n";
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cin>>a[i][j];
        }
    }
    solve();
    cout<<endl;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}


