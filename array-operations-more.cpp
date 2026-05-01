#include<bits/stdc++.h>

using namespace std;

/*
More C++ array operations:

1.  Finding the largest element in the array
2.  Finding the second largest element in the array
3.  Checking if an array is sorted
4.  Removing duplicates from an UNSORTED integer array
5.  Removing duplicates from a SORTED integer array
6.  Moving zeroes to the end of the array
7.  Solving the leaders in an array problem
8.  Solving the maximum difference problem with order
9.  Finding the frequencies in a SORTED array
10. Solving the stock, buy and sell problem
11. Solving the trapping rainwater problem
12. Finding the maximum consecutive 1s
13. Finding the maximum subarray sum 
*/

//______________________________________________________________________________________________________
// NOTE: Array traversal function

/*
Below is a function to traverse an integer array

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
// NOTE: Key search in an array

/*
Below is a function to search for a given key in an integer array

Time complexity:  theta(n)

Space complexity: theta(1)
Auxiliary space:  theta(1)
*/
bool search_key_in_array(int arr[], int size, int key)
{
    for(int i=0;i<size;i++)
        if(arr[i]==key)
            return true;
    
    return false;
}

//______________________________________________________________________________________________________
// 1. Finding the largest element in the array

/*
Below is a function to find the largest element in an integer array.

Time complexity:  

Space complexity: 
Auxiliary space:  
*/
int find_largest_element_in_array(int* arr, int &size)
{
    int max=arr[0];

    for(int i=1;i<size;i++)
        if(arr[i]>max)
            max=arr[i];

    return max;
}

//______________________________________________________________________________________________________
// 2. Finding the second largest element in the array

/*
Below is a function to find the largest element in an integer array.
EDGE CASE: If all the elements in the array are equal than return -1.

Time complexity:  

Space complexity: 
Auxiliary space:  
*/
int find_second_largest_element_in_array(int* arr, int &size)
{
    int max_pos=0;

    // Pass 1: Find the largest
    for(int i=1;i<size;i++)
        if(arr[i]>arr[max_pos])
            max_pos=i;
    
    int second_max_pos=-1;

    // Pass 2: Find the largest among elements !=max
    for(int i=0;i<size;i++)
        if(arr[i]!=arr[max_pos] && (arr[i]>arr[second_max_pos]) || second_max_pos==-1)
        // the first condition is for cases when the array has multiple copies of the same max element
            second_max_pos=i;

    if(second_max_pos==-1)
        return -1;

    return arr[second_max_pos];
}

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int find_second_largest_element_in_array_alternate(int* arr, int &size)
{
    int max=arr[0], second_max=INT_MIN;
    
    for(int i=1;i<size;i++)
    {
        // if(arr[i] >= max && arr[i] >= second_max)
        if(arr[i] > max)
        {
            second_max=max;
            max=arr[i];
        }

        else if(arr[i] != max && arr[i] > second_max)
            second_max=arr[i];

    }

    if(second_max==INT_MIN)
        return -1;

    return second_max;
}

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int find_second_largest_element_in_array_course_approach(int* arr, int &size)
// most elegant solution
{
    int res=-1, largest=0;

    for(int i=1;i<size;i++)
    {
        if(arr[i] > arr[largest])
        {
            res=largest;
            largest=i;
        }

        else if(arr[i] != arr[largest]) 
        // this is to avoid duplicates
        {
            if(res == -1 || arr[i] > arr[res])
                res=i;
        }
    }

    return res;
}

//______________________________________________________________________________________________________
// 3. Checking if an array is sorted

/*
Below is a function to check if a given integer array is sorted

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

bool check_if_array_sorted(int* arr, int &size)
{
    for(int i=1;i<size;i++)
        if(arr[i] < arr[i-1])
            return false;

    return true;
}

//______________________________________________________________________________________________________
// 4. Removing duplicates from an UNSORTED integer array

/*
Below is a function to remove all the duplicates from an array

This approach uses a 'set', which:
- Automatically removes duplicates
- Stores elements in sorted order

NOTE:
- The original order of elements is NOT preserved
- This works for both sorted and unsorted arrays
- unordered_set can also remove duplicates but does NOT preserve any order

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int* remove_duplicates_from_array_set_approach(int* arr, int &size)
{
    set<int> unique_array_elements;

    for(int i=0;i<size;i++)
        unique_array_elements.insert(arr[i]);

    int set_size=unique_array_elements.size();
    size=set_size;
    int* new_array=new int[set_size];

    set<int>::iterator itr=unique_array_elements.begin();
    for(int i=0 ; itr!=unique_array_elements.end(); ++itr, ++i)
        new_array[i]=*itr;

    delete[] arr;

    return new_array;
}

/*
Below is a function to remove all the duplicates from an array

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int* remove_duplicates_from_array_alternate_approach(int* arr, int &size)
{
    vector<int> vec;

    for(int i=0;i<size;i++)
    {
        if(search_key_in_array(arr,i,arr[i])==false)
            vec.push_back(arr[i]);
    }

    int* new_array=new int[vec.size()];
    size=vec.size();

    for(int i=0;i<vec.size();i++)
        new_array[i]=vec[i];
        
    delete[] arr;

    return new_array;
}

/*
Below is a function to remove all the duplicates from an array

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int* remove_duplicates_from_array_map_approach(int* arr, int &size)
{
    map<int,int> unique_array_elements;

    for(int i=0;i<size;i++)
        unique_array_elements.insert({arr[i],arr[i]});

    int map_size=unique_array_elements.size();
    size=map_size;
    int* new_array=new int[map_size];
    
    map<int,int>::iterator itr=unique_array_elements.begin();
    for(int i=0;i<map_size;i++,itr++)
        new_array[i]=itr->first;
    
    delete[] arr;

    return new_array;
}

/*
Below is a function to remove all the duplicates from an array

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int* remove_duplicates_from_array_set_approach_correct(int* arr, int &size)
{
    unordered_set<int> seen; // tracks seen elements
    vector<int> result; // stores the unique elements in order

    for(int i=0;i<size;i++)
    {
        if(seen.find(arr[i])==seen.end())
        /*
        This asks: “Is arr[i] already in the set?”

        It returns:
            1. Iterator to element → if found
            2. seen.end() → if NOT found
        */
        {
            seen.insert(arr[i]); // mark as seen
            result.push_back(arr[i]); // add to result
        }
    }

    // create a new array
    int* new_array=new int[result.size()];

    for(int i=0;i<result.size();i++)
        new_array[i]=result[i];

    size=result.size(); // update the size

    delete[] arr; // free old memory

    return new_array;
}

//______________________________________________________________________________________________________
// 5. Removing duplicates from an SORTED integer array

/*
Below is a function to remove all the duplicates from a sorted array
NOTE: Preserves the order of the element because I'm using a vector instead of a set

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int* remove_duplicates_from_sorted_array(int* arr, int &size)
{
    vector<int> unique_elements;
    
    int i;
    for(i=0;i+1<size;i++)
        if(arr[i]!=arr[i+1])
            unique_elements.push_back(arr[i]);
      
    if(arr[i]!=arr[i-1])
        unique_elements.push_back(arr[i]);
      
    int new_size=unique_elements.size();
    size=new_size;
    int* new_array=new int[new_size];

    for(int i=0;i<new_size;i++)
        new_array[i]=unique_elements[i];
    
    delete[] arr;

    return new_array;
}

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

void remove_duplicates_from_sorted_array_course_approach(int* arr, int &size)
{
    int* temp=new int[size];
    temp[0]=arr[0];
    
    int res=1;
    
    for(int i=1;i<size;i++)
        if(temp[res-1]!=arr[i])
        {
            temp[res]=arr[i];
            res++;
        }

    for(int i=0;i<res;i++)
        arr[i]=temp[i];

    delete[] temp; 

    size=res;
    // don't deallocate the array memory, only the variable
}

//______________________________________________________________________________________________________
// 6.  Moving zeroes to the end of the array

/*
Below is a function to remove all the duplicates from a sorted array

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

void move_zeroes_to_array_end(int* arr, int &size)
{
    int count=0;
    vector<int> vec;

    for(int i=0;i<size;i++)
    {
        if(arr[i]!=0)
        {
            vec.push_back(arr[i]);
            cout<<"arr["<<i<<"]="<<arr[i]<<endl;
        }

        else
        {
            ++count;
            cout<<"count="<<count<<endl;
        }
    }

    for(int i=0;i<count;i++)
        vec.push_back(0);

    for(int i=0;i<size;i++)
        arr[i]=vec[i];
}

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

void moveToEndNaive(int* arr, int &size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==0)
        {
            for(int j=i+1;j<size;j++)
                if(arr[j]!=0)
                {
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
        }
    }
}

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

void moveToEndEfficient(int* arr, int &size)
{
    int count=0;
    
    for(int i=0;i<size;i++)
    {
        if(arr[i]!=0)
        {
            int temp=arr[i];
            arr[i]=arr[count];
            arr[count]=temp;

            ++count;
        }
    }
}

//______________________________________________________________________________________________________
// 7. Solving the leaders in an array problem

/*
Below is a function to print the leaders in an array

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

void print_array_leaders_naive(int* arr, int &size)
{
    for(int i=0;i<size;i++)
    {
        bool leader_flag=true;

        for(int j=i+1;j<size;j++)
        {
            if(arr[j]>arr[i])
            {
                leader_flag=false;
                break; // only exits the inner loop
            }
        }

        if(leader_flag==true)
            cout<<arr[i]<<"\t";
    }
}

/*
Below is a function to print the leaders in an array

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

void print_array_leaders_optimized(int* arr, int &size)
{
    if(size==0)
        return; 
        // because otherwise the function will try to find arr[-1] if size=0

    int largest_element=arr[size-1];
    vector<int> leaders;
    leaders.push_back(largest_element);

    for(int i=size-2;i>=0;i--)
    {
        if(arr[i]>largest_element)
        {
            largest_element=arr[i];
            leaders.push_back(arr[i]);
            // the vector is only created to print the leaders in the order that they appear from left to right
            // we can directly print the leaders (O(1) space) but they will be in the reversed order
        }
    }

    for(int i=leaders.size()-1;i>=0;i--)
        cout<<leaders[i]<<"\t";
}

//______________________________________________________________________________________________________
// 8. Solving the maximum difference problem with order

/*
Below is a function to solve the maximum difference problem with order

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int max_diff_naive(int* arr, int &size)
{
    int max_diff=arr[1]-arr[0];

    for(int i=size-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if((arr[i]-arr[j]) > max_diff)
                max_diff=arr[i]-arr[j];
        }
    }

    return max_diff;
}

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int max_diff_optimized(int* arr, int &size)
{
    if(size<2)
        return 0;

    int min_so_far=arr[0];
    int max_diff=arr[1]-min_so_far;

    for(int i=1;i<size;i++)
    {
        // update max_diff
        if((arr[i]-min_so_far) > max_diff)
            max_diff=arr[i]-min_so_far;
        
        // update min_so_far
        if(arr[i]<min_so_far)
            min_so_far=arr[i];
    }

    return max_diff;
}

//______________________________________________________________________________________________________
// 9. Finding the frequencies in a SORTED array

/*
Below is a function to finding frequencies in a sorted array

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

void count_freqs_in_sorted_array(int* arr, int &size)
{
    int count=1;

    int i;
    for(i=1;i<size;i++)
    {
        if(arr[i]==arr[i-1])
            ++count;
        
        else
        {
            cout<<arr[i-1]<<"\t"<<count<<"\n";
            count=1;
        }
    }

    cout<<arr[i-1]<<"\t"<<count<<"\n";
}

//______________________________________________________________________________________________________
// 10. Solving the stock, buy and sell problem

/*
Below is a function to solve the stock, buy and sell problem

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int max(int &a, int &b)
{
    return (a>b)?a:b;
}

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int maxProfit(int price[], int start, int end)
{
    if(end <= start)
        return 0;

    int profit=0;

    for(int i=start; i<=end; i++)
    {
        for(int j=i+1; j<=end; j++)
        {
            if(price[j] > price[i])
            {
                int curr_profit = price[j] - price[i] + maxProfit(price, start, i-1) + maxProfit(price, j+1, end);
                profit = max(profit, curr_profit);
            }
        }
    }

    return profit;
}

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int stock_buy_sell_problem_efficient(int* arr, int &size)
{
    if(size<2)
        return 0;

    int sum=0;

    for(int i=1;i<size;i++)
        if(arr[i]>arr[i-1])
            sum=sum+(arr[i]-arr[i-1]);

    return sum;
}

//______________________________________________________________________________________________________
// 11. Solving the trapping rainwater problem

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int max_value(int &a, int &b)
{
    return (a>b)?a:b;
}

int min_value(int &a, int &b)
{
    return (a<b)?a:b;
}

int max_in_array(int* arr, int start, int end)
{
    int max=arr[start];

    for(int i=start+1;i<=end;i++)
        if(arr[i]>max)
            max=arr[i];

    return max;
}

int min_in_array(int* arr, int start, int end)
{
    int min=arr[start];

    for(int i=start+1;i<=end;i++)
        if(arr[i]<min)
            min=arr[i];

    return min;
}

int rainwater_trapping_two_pointer_approach(int* arr, int &size)
{
    int left=0, right=size-1;
    int left_max=0, right_max=0;
    int water=0;

    while(left <= right)
    {
        /*
        Implementing the formula:

        water[i] = min(max_left, max_right) - height[i]
        */
        if(arr[left] <= arr[right]) //because the shorter wall is the limiting wall
        {
            left_max = max_value(left_max,arr[left]);
            water += left_max - arr[left];
            ++left;
        }

        else
        {
            right_max = max_value(right_max,arr[right]);
            water += right_max - arr[right];
            --right;
        }
    }

    return water;
}

int rainwater_trapping_prefix_array_approach(int* arr, int &size)
{
    if(size < 3)
        return 0;

    vector<int> left_max(size), right_max(size);

    // LEFT MAX
    left_max[0] = arr[0];
    for(int i = 1; i < size; i++)
        left_max[i] = max_value(left_max[i-1], arr[i]);

    // RIGHT MAX
    right_max[size-1] = arr[size-1];
    for(int i = size-2; i >= 0; i--)
        right_max[i] = max_value(right_max[i+1], arr[i]);

    /*
    Implementing the formula:

    water[i] = min(max_left, max_right) - height[i]
    */
    int water = 0;
    for(int i = 0; i < size; i++)
        water += min_value(left_max[i], right_max[i]) - arr[i];

    return water;
}

//______________________________________________________________________________________________________
// 12. Finding the maximum consecutive 1s

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int max_consecutive_ones_in_binary_array_naive(int* arr, int &size)
{
    int res=0;

    for(int i=0;i<size;i++)
    {
        int count=0;

        for(int j=i;j<size;j++)
        {
            if(arr[j]==1)
                ++count;

            else
                break;
        }

        res=max_value(count,res);
    }

    return res;
}

int max_consecutive_ones_in_binary_array_optimised(int* arr, int &size)
{
    int max_so_far=0, curr_count=0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]!=1)
        {
            if(curr_count > max_so_far)
                max_so_far=curr_count;

            curr_count=0;
        }

        else
            ++curr_count;
    }

    if(curr_count > max_so_far)
                max_so_far=curr_count;

    return max_so_far;
}

//______________________________________________________________________________________________________
// 13. Finding the maximum subarray sum 

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int max_subarray_sum_naive(int* arr, int &size)
{
    int res=arr[0];

    for(int i=0;i<size;i++)
    {
        int curr_sum=0;

        for(int j=i;j<size;j++)
        {
            curr_sum = curr_sum + arr[j];
            res = max_value(curr_sum, res);
        }
    }

    return res;
}

int max_subarray_sum_optimised(int* arr, int &size)
{
    int res=arr[0];
    int max_sum_so_far=arr[0];

    for(int i=1;i<size;i++)
    {
        int new_max_sum_so_far=max_sum_so_far + arr[i];
        /*
        To remove the error message thatI got when I put the expression instead of the variable 'new_max_sum_so_far':
            initial value of reference to non-const must be an lvalue
        */
        max_sum_so_far=max_value(arr[i], new_max_sum_so_far);
        res=max_value(res, max_sum_so_far);
        /*
        If you used only one variable, say res, and tried to do 
        res = max(arr[i], res + arr[i]), you would be forced to 
        include the current element in your "best" total, even 
        if it actually makes your total worse than a previous peak.
        */
    }

    /*
    Concept:

        maxEnding(i) = max ( maxEnding(i-1) + arr[i], arr[i] )
    */

    return res;
}

//______________________________________________________________________________________________________
// 13. Finding the longest even odd subarray 

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int longest_even_odd_subarray_length_naive(int* arr, int &size)
{
    int length=1;

    for(int i=0;i<size;i++)
    {
        int curr=1;

        for(int j=i+1;j<size;j++)
        {
            if( (arr[j]%2==0 && arr[j-1]%2!=0) || (arr[j-1]%2==0 && arr[j]%2!=0) )
                ++curr;

            else
                break;
        }

        length=max_value(length, curr);
    }

    return length;
}

int longest_even_odd_subarray_length_optimised(int* arr, int &size)
{
    int length=0;

    for(int i=1;i<size;i++)
    {
        if( (arr[i-1] + arr[i]) % 2 != 0)
        {
            if(length==0)
                length=2;
            
            else
                ++length;
        }
    }

    return length;
}

int main()
{
    int size=10;
    int* arr=new int[size];
    
    //for(int i=0;i<size;i++)
    //    arr[i]=i+1;

    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=5;
    arr[4]=85;
    arr[5]=75;
    arr[6]=90;
    arr[7]=11;
    arr[8]=5;
    arr[9]=85;

    int sorted_size=10;
    int* sorted_arr=new int[sorted_size];

    sorted_arr[0]=0;
    sorted_arr[1]=0;
    sorted_arr[2]=1;
    sorted_arr[3]=5;
    sorted_arr[4]=5;
    sorted_arr[5]=7;
    sorted_arr[6]=9;
    sorted_arr[7]=11;
    sorted_arr[8]=11;
    sorted_arr[9]=85; 
    
    int size_z=10;
    int* arr_z=new int[size_z];

    arr_z[0]=8;
    arr_z[1]=5;
    arr_z[2]=0;
    arr_z[3]=10;
    arr_z[4]=2;
    arr_z[5]=0;
    arr_z[6]=1;
    arr_z[7]=0;
    arr_z[8]=7;
    arr_z[9]=0;

    int size_l=10;
    int* arr_l=new int[size_l];

    arr_l[0]=10;
    arr_l[1]=20;
    arr_l[2]=30;
    arr_l[3]=5;
    arr_l[4]=85;
    arr_l[5]=75;
    arr_l[6]=90;
    arr_l[7]=11;
    arr_l[8]=5;
    arr_l[9]=85;

    int size_md=10;
    int* arr_md=new int[size_md];

    arr_md[0]=2;
    arr_md[1]=3;
    arr_md[2]=10;
    arr_md[3]=6;
    arr_md[4]=4;
    arr_md[5]=8;
    arr_md[6]=1;

    int size_cf=6;
    int* arr_cf=new int[size_cf];

    arr_cf[0]=10;
    arr_cf[1]=10;
    arr_cf[2]=25;
    arr_cf[3]=36;
    arr_cf[4]=36;
    arr_cf[5]=36;

    int size_co=7;
    int* arr_co=new int[size_co];

    arr_co[0]=1;
    arr_co[1]=1;
    arr_co[2]=0;
    arr_co[3]=1;
    arr_co[4]=1;
    arr_co[5]=1;
    arr_co[6]=1;

    int size_msas=5;
    int* arr_msas=new int[size_msas];

    arr_msas[0]=1;
    arr_msas[1]=-2;
    arr_msas[2]=3;
    arr_msas[3]=-1;
    arr_msas[4]=2;

    int size_leosl=6;
    int* arr_leosl=new int[size_leosl];

    arr_leosl[0]=10;
    arr_leosl[1]=12;
    arr_leosl[2]=14;
    arr_leosl[3]=7;
    arr_leosl[4]=8;
    arr_leosl[5]=9;

    cout<<"The largest element in the array is "<<find_largest_element_in_array(arr,size);
    cout<<"\nThe 2nd largest elememt in the array is "<<find_second_largest_element_in_array_course_approach(arr,size);
    
    if(check_if_array_sorted(arr,size)==true)
        cout<<"\nThe array is sorted!\n";
    
    else 
        cout<<"\nThe array is NOT sorted!\n";
    
    arr=remove_duplicates_from_array_set_approach_correct(arr,size);

    traverse_array(arr,size);
    
    cout<<endl;

    //sorted_arr=remove_duplicates_from_sorted_array(sorted_arr,sorted_size);

    remove_duplicates_from_sorted_array_course_approach(sorted_arr,sorted_size);
    traverse_array(sorted_arr,sorted_size);

    cout<<endl;
    traverse_array(arr_z,size_z);
    //move_zeroes_to_array_end(arr_z, size_z);
    moveToEndNaive(arr_z,size_z);

    traverse_array(arr_z,size_z);

    // printing the leaders in the array: arr_l
    cout<<"\nPrinting the leaders in the array:\n";
    print_array_leaders_optimized(arr_l, size_l);

    cout<<"\nMax difference problem solution: "<<max_diff_naive(arr_md,size_md);

    cout<<"\nCounting the frequencies in a sorted array:\n";
    count_freqs_in_sorted_array(arr_cf,size_cf);

    cout<<endl;
    cout<<max_consecutive_ones_in_binary_array_naive(arr_co,size_co);

    cout<<endl;
    cout<<max_subarray_sum_naive(arr_msas,size_msas);

    cout<<endl;
    cout<<longest_even_odd_subarray_length_naive(arr_leosl, size_leosl);

    delete[] arr;
    delete[] sorted_arr;
    delete[] arr_z;
    delete[] arr_l;
    delete[] arr_md;
    delete[] arr_cf;
    delete[] arr_co;
    delete[] arr_msas;
    delete[] arr_leosl;
    
    return 0;
}