#include <bits/stdc++.h>
using namespace std;

//you can also use this function
void transpose(vector<vector<int> >& matrix, int n)
{
    int i, j, temp;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(i>j) //you can replace this condition by starting the inner loop with j=i, the rest remains the same
        {
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> vec(n, vector<int> (n, 0));
    vector<vector<int>> ans(n, vector<int> (n, 0));

    for(int i = 0; i < n ;i++)
    {
        for(int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            vec[i][j] = t;
        }
    }

    for(int i = 0; i < n ;i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }

	for(int i = 0; i < n ;i++)
	{
        for(int j = 0; j < n; j++)
        {
            ans[i][j] = vec[j][i];
        }
    }

    cout << "\n\nTranspose: \n\n";

	for(int i = 0; i < n ;i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

	return 0;
}

