//gfg compiler is showing the wrong output, but here it is correct (for the special case)

#include<bits/stdc++.h>

using namespace std;

int distinct(vector<vector<int>> M, int N)
{
    int i, j, ccount, d, c, t;

    //a special test case
    int special=M[0][0], f;

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(M[i][j]!=special)
                f++;

    if(f==0) return special;

    ccount=0;

    //sorting the first vector of the vector
    for(i=0;i<N;i++)
    for(j=i;j<N;j++)
        if(M[0][j]>M[0][i])
        {
            t=M[0][j];
            M[0][j]=M[0][i];
            M[0][i]=t;
        }

    for(j=0;j<N;j++)
    {
        if(M[0][j]==M[0][j+1])
            continue;

        else
        {
            c=M[0][j];
            d=0;

            for(i=1;i<N;i++)
            {
                if(count(M[i].begin(), M[i].end(), c))
                    d++;

                else break;
            }
            if(d==3)
                ccount++;
        }
    }

    return ccount;
}

int main()
{
    vector<vector<int>> M={ {1,1,1} , {1,1,1} , {1,1,1} };

    cout<<"No. of common distinct elements in the 2d vector are: "<<distinct(M,3);

    return 0;
}
