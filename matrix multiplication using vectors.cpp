//gfg compiler is showing segmentation fault

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int i,j,k, ar,ac,br,bc,common;

    vector<vector<int>> res;

    ar=A.size();
    ac=A[0].size();

    br=B.size();
    bc=B[0].size();

    if(ac!=br)
        cout<<"Invalid matrix multiplication!";

    else
    {
        for(i=0;i<ar;i++)
        {
            for(j=0;j<ac;j++)
            {
                res[i][j]=0; //particular element of the result

                for(k=0;k<common;k++)
                    res[i][j]=res[i][j]+A[i][k]*B[k][j];
            }
        }
    }

    return res;
}

