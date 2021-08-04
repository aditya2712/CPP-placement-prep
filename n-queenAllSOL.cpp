#include<bits/stdc++.h>
#define MX 1000
using namespace std;


int board[MX][MX];

bool isSafe(int x, int y, int n){
    int i,j;
    for(i=0; i<n; i++){
        if(board[x][i])  //for horizontal
        return false;
    }

    for(i=0; i<n; i++){
        if(board[i][y])  //for vertical
        return false;
    }       

    //for primary diagonal
    for(i=x,j=y; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1)
        return false;
    }
    for(i=x,j=y; i<n && j<n; i++, j++){
        if(board[i][j]==1)
        return false;
    }

    //for secondary diagonal
    for(i=x,j=y; i<n && j>=0; i++, j--){
        if(board[i][j]==1)
        return false;
    }
    for(i=x,j=y; i>=0 && j<n; i--, j++){
        if(board[i][j]==1)
        return false;
    }

    return true;
}

bool solve(int n, int col){
    if(col>=n)
    return true;

    int i;
    for(i=0;i<n;i++){
        if(isSafe(i, col, n)){
            board[i][col]=1;
            if(solve(n,  col+1)) 
            return true;
            board[i][col]=0;
        }
    }
    return false;
}


int main(){
    memset(board, 0, sizeof board);
    int n;
    cin>>n;
    cout<<endl;
    if(n==2 || n==3){
        cout<<"Solution is not possible\n";
        return 0;
    }
    solve(n, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cout<<board[i][j]<<" ";
        cout<<endl;
    }
}