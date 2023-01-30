#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *arr, int n)
{
    //adaptive, stable
    //k passes give us k largest elements

    int i,j,t,flag;

    for(i=0;i<(n-1);i++)
    {
        flag=0;

        for(j=0; j<(n-1-i); j++)
            if(arr[j]>arr[j+1])
            {
                ++flag;
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }

          if(flag==0)
                break;
    }

    printf("\n\nBubble sort of the array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}

void insertion_sort(int *arr, int n)
{
    //adaptive, stable

    /*
     Since this involves the shifting of elements,
     insertion sort is better suited to linked lists, than to arrays.
    */

    int i,j,key;

    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;

        while(j>-1 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            --j;
        }

    arr[j+1]=key;
    }

    printf("\n\nInsertion sort of the array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}

void selection_sort(int *arr, int n)
{
    // not adaptive, not stable

    /*
     The only search algorithm with the minimum number of swaps (O(n)),
     with the help of a variable k besides pos besides i and j.

     k passes give us k smallest elements
    */

    int i,j,k,t;

    for(i=0;i<n-1;i++)
    {
        for(j=i,k=i;j<n;j++)
           if(arr[j]<arr[k])
               k=j;

        t=arr[i];
        arr[i]=arr[k];
        arr[k]=t;
    }

    printf("\n\nSelection sort of the array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}

//these 3 functions were given in the Abdul Baari code:

void swap(int *x,int *y)
{
    int temp=*x;

    *x=*y;
    *y=temp;
}

int partition(int A[],int l,int h)
{
    int pivot=A[l];
    int i=l,j=h;

    do
    {
        do{i++;}
        while(A[i]<=pivot);

        do{j--;}
        while(A[j]>pivot);

        if(i<j)
            swap(&A[i],&A[j]);
    }
    while(i<j);

    swap(&A[l],&A[j]);

    return j;
}

void QuickSort(int A[],int l,int h)
{
    int j;

    if(l<h)
    {
        j=partition(A,l,h);

        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }

void merge_sort_two_arrays(int* a, int* b, int m, int n)
{
    int i,j,k,new_array[m+n];
    int *c=new_array;

    i=0;
    j=0;
    k=0;

    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            ++i;
            ++k;
        }

        else
        {
            c[k]=b[j];
            ++j;
            ++k;
        }
    }

    if(i==m)
        while(j<n)
        {
            c[k]=b[j];
            ++j;
            ++k;
        }

    else if(j==n)
        while(i<m)
        {
            c[k]=a[i];
            ++i;
            ++k;
        }

    /*
     The above code segment can also be written as:

     for(;i<m;i++)
        c[k++]=a[i];

    for(;j<n;j++)
        c[k++]=b[j];

    only one of the for loops will execute as either i or j will meet the conditions specified.
    */

    printf("\n\nMerge sort of the two arrays:\n");
    for(i=0;i<n;i++)
        printf("%d\t",c[i]);
}



//Abdul Baari code:

void Merge(int A[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int B[100];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];

        else
            B[k++]=A[j++];
    }

    for(;i<=mid;i++)
        B[k++]=A[i];

    for(;j<=h;j++)
        B[k++]=A[j];

    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void IterativeMergeSort(int A[],int n)
{
    int p,l,h,mid,i;

    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<=n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;

            Merge(A,l,mid,h);
        }
    }

    if(p/2<n)
        Merge(A,0,p/2-1,n);

    printf("\n\nMerge sort of the two arrays:\n");
    for(i=0;i<n;i++)
        printf("%d\t",c[i]);
}

void RecursiveMergeSort(int A[],int l,int h)
{
    int mid;

    if(l<h)
    {
        mid=(l+h)/2;

        RecursiveMergeSort(A,l,mid);
        RecursiveMergeSort(A,mid+1,h);

        Merge(A,l,mid,h);
    }
}

int main()
{
    int m,n,i;

    //printf("Enter the number of elements in the array: ");
    //scanf("%d",&m);

    int a[]={7,3,4,8,9,1,3,0};
    int b[n];
    int *ptr_arr;

    m=8;

    /*
    printf("\n\nEnter array values:\n");
    for(i=0;i<m;i++)
    {
        printf("Enter the value: ");
        scanf("%d",&a[i]);
    }
    */

    printf("\n\nArray before sorting:\n");
    for(i=0;i<m;i++)
        printf("%d\t",a[i]);

    //bubble_sort(a,m);
    //insertion_sort(a,m);
    //selection_sort(a,m);
    //merge_sort_two_arrays(a,b,m,n);
    //QuickSort(arr,0,n);
    //IterativeMergeSort(a,m);
    //RecursiveMergeSort(a,0,m);


    printf("\n\nArray after sorting:\n");
    for(i=0;i<(m+n);i++)
        printf("%d\t",ptr_arr[i]);


    printf("\n\n");
    return 0;
}
