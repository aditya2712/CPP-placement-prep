
#include<bits/stdc++.h>
using namespace std;
int a[9][9][10],i,j,k,numofpossi[9][9];


int solvetry1 (int r,int c)
{
    a[r][c][0]=a[r][c][1];
    a[r][c][1]=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            for(k=1;k<10;k++)
            {
                a[i][j][k]=0;
            }
        }
    }
}

int print()
{
    cout<<endl;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cout<<a[i][j][0]<<" ";
        }
        cout<<endl;
    }
}


bool check(int r,int c, int val)
{

    for(i=0;i<9;i++)
    {
        if(a[r][i][0]==val)
        {
            return false;
        }
    }


    for(i=0;i<9;i++)
    {
        if(a[i][c][0]==val)
        {
            return false;
        }
    }

   int  baserow=r/3;
   int  basecol=c/3;

    for(i=(3*baserow);i<3*(baserow)+3;i++)
    {
        for(j=(3*basecol);j<3*(basecol)+3;j++)
        {
            if(a[i][j][0]==val)
            {
                return false;
            }
        }
    }

    return true;
}

int allcellpossiblity()
{

    int val,r,c;
    for(r=0;r<9;r++)
    {
        for(c=0;c<9;c++)
        {
            if(a[r][c][0]==0)
            {
                int cnt=0;
                for(val=1;val<10;val++)
                {
                    if(check(r,c,val)==true)
                    {
                        cnt++;

                        for(k=1;k<10;k++)
                        {
                            if(a[r][c][k]==0)
                            {
                                a[r][c][k]=val;
                                break;
                            }
                        }
                    }
                }
                //cout<<"\nrow col "<<r<<" "<<c<<" val cnt "<<val<<" "<<cnt;
                numofpossi[r][c]=cnt;
                if(cnt)
                {
                    solvetry1(r,c);
                    print();
                    allcellpossiblity();
                }
            }
            else
            {
                numofpossi[r][c]=0;
            }
        }
    }
}

int main()
{

    cout<<"Enter the sudoku:\n";
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cin>>a[i][j][0];
        }
    }

    allcellpossiblity();

  //  while(allcellpossiblity()==true);


     print();

}
