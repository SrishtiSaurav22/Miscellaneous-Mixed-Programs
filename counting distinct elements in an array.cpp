//here they reduced the number of unnecessary iterations by checking only for the elements on the left of the current element
//don't compare each element with every single other element, that is very unnecessary.

#include<iostream>
using namespace std;

int countDistinct(int a[], int n)
{
    int count = 0;
    bool isDistinct = true;
    for(int i = 0; i < n; i++)
    {
        isDistinct = true; //set as 'true' for every element in the array as we traverse it.

        for(int j = i-1; j >= 0; j--)
            if(a[i]==a[j])
            {
                isDistinct = false;
                break;
            }

        if(isDistinct==true)
            count ++ ;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i ++)
        cin >> a[i] ;

    cout << countDistinct(a,n);
    return 0;
}
