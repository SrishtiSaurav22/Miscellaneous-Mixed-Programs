// check if an array is sorted, with recursion

#include<bits/stdc++.h>
#include<time.h>

using namespace std;

// both these functions are for checking ascending order

bool check_array_sorted_1(int* arr, int n) // this should take O(n) time?
{
    if(n==1)
        return true;

    if(arr[n-1]>=arr[n-2])
        return check_array_sorted_1(arr,n-1);

    return false;
}

bool check_array_sorted_2(int* arr, int n) // this should take O(log(n)) time?
{
    if(n==1 || n==0)
        return true;

    if(arr[n-2]>arr[n-1])
        return false;

    return check_array_sorted_2(arr,n/2);
}

int main()
{
    int arr1[5]={1,2,3,6,8};
    int arr2[5]={3,2,1,6,8};

    /*

    // why am i getting the result as zero?

    time_t START=time(&START);
    check_array_sorted_1(arr1,5);
    time_t END=time(&END);
    */

    // Here, as well I'm only getting the duration as zero?
    // There's something wrong with my function....maybe?
    clock_t START=clock();
    bool val=check_array_sorted_2(arr2,5);
    clock_t END=clock();

    int time_taken=END-START;

    if(val==true)
        cout<<"The array is sorted!"<<endl;

    else
        cout<<"The array is not sorted!"<<endl;

    cout<<"Time taken by this func: "<<time_taken<<" msec"<<endl;
    cout<<"Time taken by this func: "<<time_taken/(CLOCKS_PER_SEC)<<" sec"<<endl;

    /*
    bool arr12=check_array_sorted_1(arr1,5);

    bool arr21=check_array_sorted_2(arr2,5);
    bool arr22=check_array_sorted_2(arr2,5);
    */
    cout<<endl;
    return 0;
}
