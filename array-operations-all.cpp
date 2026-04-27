<<<<<<< HEAD
/*
All C++ array operations: 

1.  Accessing element 
2.  Traversal 
3.  Insertion at end (space available, space not available) 
4.  Insertion at beginning 
5.  Insertion at index k 
6.  Deletion from end 
7.  Deletion from beginning 
8.  Deletion at index k 
9.  Searching for an element 
10. Updating element 
11. Reversing an array 
12. Left-rotating an array by k 
13. Right-rotating an array by k
*/

#include<bits/stdc++.h>

using namespace std;

//______________________________________________________________________________________________________
// 1. Accessing element

/*
Below is 

Time complexity:  theta(1)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int accessing_element(int arr[], int size, int index)
{
    /*
    Can't use:
    int size=sizeof(arr)/sizeof(arr[0]);

    Because:
    'sizeof' on array function parameter 'arr' will return size of 'int*' [-Wsizeof-array-argument]
    */

    if(index<0 || index>=size)
    {
        cout<<"\nInvalid index.\n";
        return -1;
    }

    return arr[index];
} 

//______________________________________________________________________________________________________
// 2. Traversal

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
void traverse_array(int arr[], int size)
{
    /*
    Can't use:
    int size=sizeof(arr)/sizeof(arr[0]);

    Because:
    'sizeof' on array function parameter 'arr' will return size of 'int*' [-Wsizeof-array-argument]
    */

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

//______________________________________________________________________________________________________
// 3.  Insertion at end (space available, space not available) 

/*
Below is 

Time complexity:  theta(1)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int* insert_at_end(int* arr, int &size, int new_element)
{
    /*
    The line below only works if extra space is already allocated to the array
    OR
    If the capacity of the array is greater than its current :logical" size

    For eg:
    Inside the main() function, instead of:

    int arr[]={1,2,3,4,5};
    // Here, both the capacity and size of the array are 5.
     
    We need to have something like:

    int arr[10]={1,2,3,4,5};
    // Here, the capacity of the array is 10 but the "logical" size of the array is only 5

    NOTE:
    1. Size: Number of elements currently stored (logical usage)
    2. Capacity: Total memory allocated (maximum elements you can store)
    */

    /* Instead of:
    *(arr+size) = new_element;
    
    Write:
    arr[size]=new_element;
    */
    arr[size]=new_element;
    ++size;

    return arr;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* insert_at_end_alternate(int* arr, int &size, int new_element)
{
    int* arr_new = new int[size+1];

    for(int i=0;i<size;i++)
        arr_new[i]=arr[i];

    /* Instead of:
    *(arr_new+size) = new_element;
    
    Write:
    arr_new[size]=new_element;
    */
    arr_new[size]=new_element;

    ++size;
    cout<<"arr: "<<arr;
    cout<<"\narr_new: "<<arr_new;
    delete[] arr; 
    // free old memory since it's no longer needed
    // Input pointer becomes invalid after call

    return arr_new;
}

//______________________________________________________________________________________________________
// 4. Insertion at beginning 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* insert_at_start(int* arr, int &size, int new_element)
{
    int* arr_new=new int[size+1];

    arr_new[0]=new_element;

    for(int i=1;i<size+1;i++)
        arr_new[i]=arr[i-1];

    ++size;
    cout<<"arr: "<<arr;
    cout<<"\narr_new: "<<arr_new;
    delete[] arr;
    // free old memory since it's no longer needed
    // Input pointer becomes invalid after call

    return arr_new;  
}

//______________________________________________________________________________________________________
// 5.  Insertion at index k 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* insert_at_index_k(int* arr, int &size, int new_element, int k)
{
    int* arr_new=new int[size+1];

    arr_new[k]=new_element;

    int i;
    for(i=0;i<k;i++)
        arr_new[i]=arr[i];
    
    for(int j=k+1;j<(size+1);j++,i++)
        arr_new[j]=arr[i];

    ++size;
    delete[] arr;

    return arr_new;
}

//______________________________________________________________________________________________________
// 6.  Deletion from end 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* delete_from_end(int* arr, int &size)
{
    int* arr_new=new int[size-1];

    for(int i=0;i<size-1;i++)
        arr_new[i]=arr[i];
        
    --size;
    delete[] arr;

    return arr_new;
}

//______________________________________________________________________________________________________
// 7.  Deletion from beginning 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* delete_from_start(int* arr, int &size)
{
    int* arr_new=new int[size-1];

    for(int i=1;i<size;i++)
        arr_new[i-1]=arr[i];

    --size;
    delete[] arr;

    return arr_new;
}

//______________________________________________________________________________________________________
// 8.  Deletion at index k 

/*
Below is 

Time complexity:  theta(n) 

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* delete_from_index_k(int* arr, int &size, int k)
{
    int* arr_new=new int[size-1];

    for(int i=0;i<k;i++)
        arr_new[i]=arr[i];
    
    for(int i=k+1;i<size;i++)
        arr_new[i-1]=arr[i];

    --size;
    delete[] arr;

    return arr_new;
}

//______________________________________________________________________________________________________
// 9.  Searching for an element 

/*
Below is 

Time complexity:  O(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int search_key_in_array(int* arr, int &size, int key)
{
    for(int i=0;i<size;i++)
        if(arr[i]==key)
            return i;
    
    return -1; // key not found in the array
}

//______________________________________________________________________________________________________
// 10. Updating element 

/*
Below is 

Time complexity:   theta(1) 

Space complexity:  theta(1) 
Auxiliary space:   theta(1)
*/
void update_at_index_k(int* arr, int &size, int k, int new_element)
{
    arr[k]=new_element;
}


//______________________________________________________________________________________________________
// 11. Reversing an array 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
void reverse_array(int* arr, int &size)
{
    for(int i=0,j=size-1;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

/*
Below is 

Time complexity:  O(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
void reverse_array_alternate(int* arr, int start_index, int end_index)
{
    for(int i=start_index,j=end_index;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

//______________________________________________________________________________________________________
// 12. Left-rotating an array by k 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* left_rotate_array_by_k(int* arr, int &size, int k)
{
    int* arr_new=new int[size];

    for(int i=0;i<size;i++)
    {
        int new_pos=(i-k+size)%size;
        arr_new[new_pos]=arr[i];
    }

    delete[] arr;
    // free the memory no longer needed

    return arr_new;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int* left_rotate_array_by_k_alternate(int* arr, int &size, int k)
{
    k=k%size;
    
    reverse_array_alternate(arr,0,k-1);
    reverse_array_alternate(arr,k,size-1);
    reverse_array_alternate(arr,0,size-1);

    return arr;
}

//______________________________________________________________________________________________________
// 13. Right-rotating an array by k

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* right_rotate_array_by_k(int* arr, int &size, int k)
{
    int* arr_new=new int[size];
    
    for(int i=0;i<size;i++)
    {
        int new_pos=(i+k)%size;  
        arr_new[new_pos]=arr[i];
    }

    delete[] arr;
    // free the memory no longer needed

    return arr_new;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int* right_rotate_array_by_k_alternate(int* arr, int &size, int k)
{
    k=k%size;

    reverse_array_alternate(arr,0,size-k-1);
    reverse_array_alternate(arr,size-k, size-1);
    reverse_array_alternate(arr,0,size-1);

    return arr;
}

//______________________________________________________________________________________________________
int main()
{
    /*
    In both the functions above, the following line was throwing an error:
    delete[] arr;

    Why?

    Because initially, I had created a static array arr in the main function, who address was held by the pointer ptr.
    Later I tried to delete the old array, an actual array, being passed as a function paramter, I was applying the
    method of deleting a dynamic array pointer to a static array. Hence, the exception.

    Initial declaration and initialization of arr:

    int arr[]={2,4,1,9,0,5,7,3};
    int size=sizeof(arr)/sizeof(arr[0]); //can only use this line for static arrays, not dynamic array pointers

    Later declaration and initialiazation of arr:

    int size=8;
    int* arr=new int[size];

    arr[0]=2;
    arr[1]=4;
    arr[2]=1;
    arr[3]=9;
    arr[4]=0;
    arr[5]=5;
    arr[6]=7;
    arr[7]=3;
    */
    int size=8;
    int* arr=new int[size];

    arr[0]=2;
    arr[1]=4;
    arr[2]=1;
    arr[3]=9;
    arr[4]=0;
    arr[5]=5;
    arr[6]=7;
    arr[7]=3;

    cout<<"Initial array:\n";
    traverse_array(arr,size);

    int index=5;
    cout<<accessing_element(arr, size, index)<<endl;

    int new_element=24;
    int* ptr=arr;

    /*
    POSSIBLE MEMORY LEAK BUG:
    If you forget to reassign:

    insert_at_end_alternate(arr, size, 10); // lost pointer

    You lose access to new array → leak
    */
    ptr=insert_at_end_alternate(ptr, size, new_element);
    cout<<endl;

    traverse_array(ptr,size);

    /*
    POSSIBLE UNDEFINED BEHAVIOUR BUG:

    insert_at_end_alternate(ptr, size, new_element);
    traverse_array(ptr, size); // ❌ use-after-free
    */
    ptr=insert_at_start(ptr,size,new_element);
    cout<<endl;

    traverse_array(ptr,size);

    int k=4;
    ptr=insert_at_index_k(ptr,size,new_element,k);
    cout<<endl;

    traverse_array(ptr,size);

    ptr=delete_from_end(ptr,size);
    cout<<endl;

    traverse_array(ptr,size);

    ptr=delete_from_start(ptr,size);
    cout<<endl;

    traverse_array(ptr,size);

    k=3;
    ptr=delete_from_index_k(ptr,size,k);
    cout<<endl;

    traverse_array(ptr,size);

    int key=345;
    int key_index=search_key_in_array(arr,size,key);

    if(key_index==-1)
        cout<<"\nWhoops! "<<key<<" not found in the array!\n";
    
    else
        cout<<"\nYay! "<<key<<" found at index "<<key_index<<endl;
    
    cout<<endl;
    
    k=4;
    new_element=88;
    update_at_index_k(ptr,size,k,new_element);

    traverse_array(ptr,size);

    reverse_array(ptr, size);

    cout<<"\nReversed array:\n";
    traverse_array(ptr,size);

    k=11;
    ptr=left_rotate_array_by_k_alternate(ptr, size, k);

    cout<<"\nArray after being rotated towards the left by "<<k<<" positions:\n";
    traverse_array(ptr,size);

    k=11;
    ptr=right_rotate_array_by_k_alternate(ptr, size, k);

    cout<<"\nArray after being rotated towards the right by "<<k<<" positions:\n";
    traverse_array(ptr,size);

    delete[] ptr;
    // necessary to prevent memory leak

    return 0;
=======
/*
All C++ array operations: 

1.  Accessing element 
2.  Traversal 
3.  Insertion at end (space available, space not available) 
4.  Insertion at beginning 
5.  Insertion at index k 
6.  Deletion from end 
7.  Deletion from beginning 
8.  Deletion at index k 
9.  Searching for an element 
10. Updating element 
11. Reversing an array 
12. Left-rotating an array by k 
13. Right-rotating an array by k
*/

#include<bits/stdc++.h>

using namespace std;

//______________________________________________________________________________________________________
// 1. Accessing element

/*
Below is 

Time complexity:  theta(1)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int accessing_element(int arr[], int size, int index)
{
    /*
    Can't use:
    int size=sizeof(arr)/sizeof(arr[0]);

    Because:
    'sizeof' on array function parameter 'arr' will return size of 'int*' [-Wsizeof-array-argument]
    */

    if(index<0 || index>=size)
    {
        cout<<"\nInvalid index.\n";
        return -1;
    }

    return arr[index];
} 

//______________________________________________________________________________________________________
// 2. Traversal

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
void traverse_array(int arr[], int size)
{
    /*
    Can't use:
    int size=sizeof(arr)/sizeof(arr[0]);

    Because:
    'sizeof' on array function parameter 'arr' will return size of 'int*' [-Wsizeof-array-argument]
    */

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

//______________________________________________________________________________________________________
// 3.  Insertion at end (space available, space not available) 

/*
Below is 

Time complexity:  theta(1)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int* insert_at_end(int* arr, int &size, int new_element)
{
    /*
    The line below only works if extra space is already allocated to the array
    OR
    If the capacity of the array is greater than its current :logical" size

    For eg:
    Inside the main() function, instead of:

    int arr[]={1,2,3,4,5};
    // Here, both the capacity and size of the array are 5.
     
    We need to have something like:

    int arr[10]={1,2,3,4,5};
    // Here, the capacity of the array is 10 but the "logical" size of the array is only 5

    NOTE:
    1. Size: Number of elements currently stored (logical usage)
    2. Capacity: Total memory allocated (maximum elements you can store)
    */

    /* Instead of:
    *(arr+size) = new_element;
    
    Write:
    arr[size]=new_element;
    */
    arr[size]=new_element;
    ++size;

    return arr;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* insert_at_end_alternate(int* arr, int &size, int new_element)
{
    int* arr_new = new int[size+1];

    for(int i=0;i<size;i++)
        arr_new[i]=arr[i];

    /* Instead of:
    *(arr_new+size) = new_element;
    
    Write:
    arr_new[size]=new_element;
    */
    arr_new[size]=new_element;

    ++size;
    cout<<"arr: "<<arr;
    cout<<"\narr_new: "<<arr_new;
    delete[] arr; 
    // free old memory since it's no longer needed
    // Input pointer becomes invalid after call

    return arr_new;
}

//______________________________________________________________________________________________________
// 4. Insertion at beginning 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* insert_at_start(int* arr, int &size, int new_element)
{
    int* arr_new=new int[size+1];

    arr_new[0]=new_element;

    for(int i=1;i<size+1;i++)
        arr_new[i]=arr[i-1];

    ++size;
    cout<<"arr: "<<arr;
    cout<<"\narr_new: "<<arr_new;
    delete[] arr;
    // free old memory since it's no longer needed
    // Input pointer becomes invalid after call

    return arr_new;  
}

//______________________________________________________________________________________________________
// 5.  Insertion at index k 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* insert_at_index_k(int* arr, int &size, int new_element, int k)
{
    int* arr_new=new int[size+1];

    arr_new[k]=new_element;

    int i;
    for(i=0;i<k;i++)
        arr_new[i]=arr[i];
    
    for(int j=k+1;j<(size+1);j++,i++)
        arr_new[j]=arr[i];

    ++size;
    delete[] arr;

    return arr_new;
}

//______________________________________________________________________________________________________
// 6.  Deletion from end 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* delete_from_end(int* arr, int &size)
{
    int* arr_new=new int[size-1];

    for(int i=0;i<size-1;i++)
        arr_new[i]=arr[i];
        
    --size;
    delete[] arr;

    return arr_new;
}

//______________________________________________________________________________________________________
// 7.  Deletion from beginning 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* delete_from_start(int* arr, int &size)
{
    int* arr_new=new int[size-1];

    for(int i=1;i<size;i++)
        arr_new[i-1]=arr[i];

    --size;
    delete[] arr;

    return arr_new;
}

//______________________________________________________________________________________________________
// 8.  Deletion at index k 

/*
Below is 

Time complexity:  theta(n) 

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* delete_from_index_k(int* arr, int &size, int k)
{
    int* arr_new=new int[size-1];

    for(int i=0;i<k;i++)
        arr_new[i]=arr[i];
    
    for(int i=k+1;i<size;i++)
        arr_new[i-1]=arr[i];

    --size;
    delete[] arr;

    return arr_new;
}

//______________________________________________________________________________________________________
// 9.  Searching for an element 

/*
Below is 

Time complexity:  O(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int search_key_in_array(int* arr, int &size, int key)
{
    for(int i=0;i<size;i++)
        if(arr[i]==key)
            return i;
    
    return -1; // key not found in the array
}

//______________________________________________________________________________________________________
// 10. Updating element 

/*
Below is 

Time complexity:   theta(1) 

Space complexity:  theta(1) 
Auxiliary space:   theta(1)
*/
void update_at_index_k(int* arr, int &size, int k, int new_element)
{
    arr[k]=new_element;
}


//______________________________________________________________________________________________________
// 11. Reversing an array 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
void reverse_array(int* arr, int &size)
{
    for(int i=0,j=size-1;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

/*
Below is 

Time complexity:  O(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
void reverse_array_alternate(int* arr, int start_index, int end_index)
{
    for(int i=start_index,j=end_index;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

//______________________________________________________________________________________________________
// 12. Left-rotating an array by k 

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* left_rotate_array_by_k(int* arr, int &size, int k)
{
    int* arr_new=new int[size];

    for(int i=0;i<size;i++)
    {
        int new_pos=(i-k+size)%size;
        arr_new[new_pos]=arr[i];
    }

    delete[] arr;
    // free the memory no longer needed

    return arr_new;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int* left_rotate_array_by_k_alternate(int* arr, int &size, int k)
{
    k=k%size;
    
    reverse_array_alternate(arr,0,k-1);
    reverse_array_alternate(arr,k,size-1);
    reverse_array_alternate(arr,0,size-1);

    return arr;
}

//______________________________________________________________________________________________________
// 13. Right-rotating an array by k

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(n)
Auxiliary space:  theta(n)
*/
int* right_rotate_array_by_k(int* arr, int &size, int k)
{
    int* arr_new=new int[size];
    
    for(int i=0;i<size;i++)
    {
        int new_pos=(i+k)%size;  
        arr_new[new_pos]=arr[i];
    }

    delete[] arr;
    // free the memory no longer needed

    return arr_new;
}

/*
Below is 

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
int* right_rotate_array_by_k_alternate(int* arr, int &size, int k)
{
    k=k%size;

    reverse_array_alternate(arr,0,size-k-1);
    reverse_array_alternate(arr,size-k, size-1);
    reverse_array_alternate(arr,0,size-1);

    return arr;
}

//______________________________________________________________________________________________________
int main()
{
    /*
    In both the functions above, the following line was throwing an error:
    delete[] arr;

    Why?

    Because initially, I had created a static array arr in the main function, who address was held by the pointer ptr.
    Later I tried to delete the old array, an actual array, being passed as a function paramter, I was applying the
    method of deleting a dynamic array pointer to a static array. Hence, the exception.

    Initial declaration and initialization of arr:

    int arr[]={2,4,1,9,0,5,7,3};
    int size=sizeof(arr)/sizeof(arr[0]); //can only use this line for static arrays, not dynamic array pointers

    Later declaration and initialiazation of arr:

    int size=8;
    int* arr=new int[size];

    arr[0]=2;
    arr[1]=4;
    arr[2]=1;
    arr[3]=9;
    arr[4]=0;
    arr[5]=5;
    arr[6]=7;
    arr[7]=3;
    */
    int size=8;
    int* arr=new int[size];

    arr[0]=2;
    arr[1]=4;
    arr[2]=1;
    arr[3]=9;
    arr[4]=0;
    arr[5]=5;
    arr[6]=7;
    arr[7]=3;

    cout<<"Initial array:\n";
    traverse_array(arr,size);

    int index=5;
    cout<<accessing_element(arr, size, index)<<endl;

    int new_element=24;
    int* ptr=arr;

    /*
    POSSIBLE MEMORY LEAK BUG:
    If you forget to reassign:

    insert_at_end_alternate(arr, size, 10); // lost pointer

    You lose access to new array → leak
    */
    ptr=insert_at_end_alternate(ptr, size, new_element);
    cout<<endl;

    traverse_array(ptr,size);

    /*
    POSSIBLE UNDEFINED BEHAVIOUR BUG:

    insert_at_end_alternate(ptr, size, new_element);
    traverse_array(ptr, size); // ❌ use-after-free
    */
    ptr=insert_at_start(ptr,size,new_element);
    cout<<endl;

    traverse_array(ptr,size);

    int k=4;
    ptr=insert_at_index_k(ptr,size,new_element,k);
    cout<<endl;

    traverse_array(ptr,size);

    ptr=delete_from_end(ptr,size);
    cout<<endl;

    traverse_array(ptr,size);

    ptr=delete_from_start(ptr,size);
    cout<<endl;

    traverse_array(ptr,size);

    k=3;
    ptr=delete_from_index_k(ptr,size,k);
    cout<<endl;

    traverse_array(ptr,size);

    int key=345;
    int key_index=search_key_in_array(arr,size,key);

    if(key_index==-1)
        cout<<"\nWhoops! "<<key<<" not found in the array!\n";
    
    else
        cout<<"\nYay! "<<key<<" found at index "<<key_index<<endl;
    
    cout<<endl;
    
    k=4;
    new_element=88;
    update_at_index_k(ptr,size,k,new_element);

    traverse_array(ptr,size);

    reverse_array(ptr, size);

    cout<<"\nReversed array:\n";
    traverse_array(ptr,size);

    k=11;
    ptr=left_rotate_array_by_k_alternate(ptr, size, k);

    cout<<"\nArray after being rotated towards the left by "<<k<<" positions:\n";
    traverse_array(ptr,size);

    k=11;
    ptr=right_rotate_array_by_k_alternate(ptr, size, k);

    cout<<"\nArray after being rotated towards the right by "<<k<<" positions:\n";
    traverse_array(ptr,size);

    delete[] ptr;
    // necessary to prevent memory leak

    return 0;
>>>>>>> 95a289d2b2620083357fcb405d7b9ac99fd960cb
}