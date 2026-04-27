#include<stdio.h>

//find the first and last index

int first_occurence(int *arr, int l, int h, int x)
{
    if(l<=h)
    {
        int mid=(l+h)/2;

        if(x<arr[mid])
            return first_occurence(arr,l,mid-1,x);

        else if(x>arr[mid])
            return first_occurence(arr,mid+1,h,x);

        else if(x==arr[mid] && (x>arr[mid-1] || mid==l))
            return 1;

        else
            return 0;
    }

    return -1;
}

int last_occurence(int *arr, int l, int h, int x)
{
    if(l<=h)
    {
        int mid=(l+h)/2;

        if(x<arr[mid])
            return last_occurence(arr,l,mid-1,x);

        else if(x>arr[mid])
            return last_occurence(arr,mid+1,h,x);

        else if(x==arr[mid] && (x<arr[mid+1] || mid==h))
            return 1;

        else
            return 0;
    }

    return -1;
}

int count(int *arr, int n, int x)
{
    if(last_occurence(arr,0,n-1,x)!=-1 && first_occurence(arr,0,n-1,x)!=-1)
        return last_occurence(arr,0,n-1,x) - first_occurence(arr,0,n-1,x) + 1 ;

    else
        return 0;
}

int main()
{
    int n,x,i;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];

    printf("\nEnter the array elements:\n\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the value: ");
        scanf("%d",&arr[i]);
    }

    printf("\n\nEnter the element to be searched: ");
    scanf("%d",&x);

    printf("\nNo. of occurrences of %d: %d",x,count(arr,n,x));

    printf("\n\n");
    return 0;
}
