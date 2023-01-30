// always delete the dynamically allocated memory

#include<bits/stdc++.h>

using namespace std;

int main()
{
    /*
    int n,i;

    // Creating an array statically and dynamically

    cout<<"Enter the number of elements: ";
    cin>>n;

    // What is the difference between 1 and 2 ?

    int arr[n]; // 1

    int* ptr=new int[n]; // 2

    for(i=0;i<n;i++)
        arr[i]=i+1;

    for(i=0;i<n;i++)
        ptr[i]=i+1;

    cout<<"\n\nPrinting arr:\n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<"\n";

    cout<<"\n\nPrinting ptr:\n";
    for(i=0;i<n;i++)
        cout<<ptr[i]<<"\n";

    // Pointers always hold dynamically allocated memory.

    int *val=new int;
    delete val;

    int *val_array=new int[10];
    delete []val_array; // can we simply write ' delete val_array; '?

    cout<<val_array[3]; // should I be getting an error? I'm getting zero.
    */

    /*
    int i,j;

    int **arr=new int*[5]; // array of int* pointers
    for(i=0;i<5;i++)
        arr[i]=new int[5]; // every int* points to an array of int values

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            arr[i][j]=(i*100)+j;

    cout<<"Printing the dynamically allocated 2D array:\n";
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            cout<<arr[i][j]<<endl;

        cout<<endl;
    }
    */

    int i,j;

    int **arr=new int*[5];

    for(i=0;i<5;i++)
    {
        arr[i]=new int[i+1];
        for(j=0;j<(i+1);j++)
            arr[i][j]=(i*100)+j;
    }

    // printing the lower triangular part of an array created dynamically

    cout<<"Printing the dynamically allocated 2D array:\n";
    for(i=0;i<5;i++)
    {
        for(j=0;j<(i+1);j++)
            cout<<arr[i][j]<<"\t";

        cout<<endl;
    }

    for(i=0;i<5;i++)
        delete[]arr[i];

    delete []arr;

    cout<<endl;
    return 0;
}
