#include<stdio.h>

int binary_search_recursive(int *arr,int l,int h,int x)
{
    int mid=(l+h)/2;

    if(x==arr[mid])
        return 1;

    else if(x<arr[mid])
        return binary_search_recursive(arr,0,mid,x);

    else if(x>arr[mid])
        return binary_search_recursive(arr,mid,h,x);

    else
        return 0;
}

int binary_search_iterative(int *arr, int n, int x)
{
    int l,h,mid;

    l=0;
    h=n-1;

    while(l<h)
    {
        mid=(l+h)/2;

        if(x<arr[mid])
            h=mid;

        else if(x>arr[mid])
            l=mid;

        else
            return 1;
    }

    return 0;
}

int main()
{
    int n,x,i;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int array[n];
    int *arr=array;

    printf("\nEnter the array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("\n\nEnter the element to be searched: ");
    scanf("%d",&x);

    if(binary_search_iterative(arr,n,x)==1)
        printf("\nElement found!");

    else
        printf("\nElement not found!");

    if(binary_search_recursive(arr,0,n-1,x)==1)
        printf("\nElement found!");

    else
        printf("\nElement not found!");

    printf("\n\n");
    return 0;
}
