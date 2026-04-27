#include<bits/stdc++.h>

using namespace std;

int** multiply( int** a, int** b, int ar, int ac, int br, int bc)
{
    if(ac!=br)
        cout<<"The no. of rows of the first matrix and the no. of columns of the second matrix must be equal";

    int i,j,k,s=0, **p;

    for(i=0;i<ar;i++)
    for(j=0;j<ac;j++)
    {
        s=0;

        for(k=0;k<ac;k++)
        s=s+( a[i][k]*b[k][j] );

        p[i][j]=s;
    }
    return p;
}

void display(int **a, int r, int c)
{
    int i, j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        cout<<a[i][j]<<" ";

        cout<<"\n";
    }
}

int main()
{
    int **a={ {1,1,1} , {2,2,2} , {3,3,3} };
    int **b={ {1,1,1} , {2,2,2} , {3,3,3} };

    int **c=multiply(a,b,3,3,3,3);
    display(c,3,3);
}
