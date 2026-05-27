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

//______________________________________________________________________________________________________
// 14. Finding the maximum circular subarray sum

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int max_circular_subarray_sum_naive_course_approach(int* arr, int &size)
{
    int res=arr[0];

    for(int i=0; i<size; i++)
    {
        int curr_max = arr[i];
        int curr_sum = arr[i];

        for(int j=i; j<size; j++)
        {
            int index = (i+j) % size;

            curr_sum = curr_sum + arr[index];
            curr_max = max_value(curr_max, curr_sum);
            /*
            If you write:

            int curr_sum = curr_sum + arr[index];
            int curr_max = max_value(curr_max, curr_sum);

            Then you'll get an incorrect input because the variables are being declared, so they're new variables inside the j loop, 
            different from those declared inside the i loop
            /*
            */
        }

        res = max_value(res, curr_max);
    }

    return res;
}

/*
MAXIMUM CIRCULAR SUBARRAY SUM (Kadane-based approach)

----------------------------------------
1. normalMaxSum() → Standard Kadane’s Algorithm
----------------------------------------

Goal:
- Find maximum sum of a normal (non-circular) subarray

Key idea:
- At each index, decide:
    → Extend previous subarray
    OR
    → Start a new subarray

Variables:
- max_sum_so_far → max subarray ending at current index
- res → global maximum subarray sum

Logic:
- new_max_sum_so_far = max_sum_so_far + arr[i]
- max_sum_so_far = max(arr[i], new_max_sum_so_far)
- res = max(res, max_sum_so_far)

Intuition:
- Either continue the previous sequence
- Or restart from current element

----------------------------------------
2. overallMaxSum() → Circular extension
----------------------------------------

Goal:
- Handle circular subarrays (wrapping allowed)

Two cases:
1. Normal subarray (no wrap)
2. Circular subarray (wrap around)

----------------------------------------
Step 1: Compute normal max
----------------------------------------

int maxNormal = normalMaxSum(arr, size);

- This handles non-circular case
- Also covers case when all elements are negative

----------------------------------------
Step 2: Handle all-negative case
----------------------------------------

if(maxNormal < 0)
    return maxNormal;

- If all elements are negative:
    → circular logic breaks
    → answer is simply the maximum element

----------------------------------------
Step 3: Compute total sum + invert array
----------------------------------------

arrSum = sum of all elements

Then:
    arr[i] = -arr[i]

Why invert?
- To convert minimum subarray problem into maximum subarray problem

Key identity:
    max(inverted array) = -min(original array)

----------------------------------------
Step 4: Find maximum circular sum
----------------------------------------

maxCircular = arrSum + normalMaxSum(inverted array)

Why this works:
- Circular subarray = total sum - minimum subarray
- Instead of finding minimum directly:
    → invert array
    → find maximum subarray

So:
    maxCircular = totalSum - minSubarray
                = totalSum + maxSubarray(inverted)

----------------------------------------
Step 5: Final answer
----------------------------------------

return max(maxNormal, maxCircular);

- Compare:
    → best non-circular subarray
    → best circular subarray

----------------------------------------
Key Intuition Summary:
----------------------------------------

1. Normal case → Kadane’s algorithm
2. Circular case → Remove the "worst" (minimum) subarray
3. Inversion trick → converts min problem into max problem

----------------------------------------
Time & Space Complexity:
----------------------------------------

Time:  O(n)
Space: O(1)

----------------------------------------
One-line takeaway:
----------------------------------------

Max Circular Sum =
max( Kadane(arr), totalSum - minSubarray )

*/

int normalMaxSum(int* arr, int &size)
{
    int res=arr[0];
    int max_sum_so_far=arr[0];

    for(int i=1;i<size;i++)
    {
        int new_max_sum_so_far=max_sum_so_far + arr[i];

        max_sum_so_far=max_value(arr[i], new_max_sum_so_far);
        res=max_value(res, max_sum_so_far);
    }

    return res;
}

int overallMaxSum(int* arr, int &size)
{
    int maxNormal=normalMaxSum(arr, size);

    if(maxNormal < 0)
        return maxNormal;

    int arrSum=0;

    for(int i=0;i<size;i++)
    {
        arrSum += arr[i];
        arr[i] = -arr[i];
    }

    int maxCircular = arrSum + normalMaxSum(arr, size);

    return max_value(maxNormal , maxCircular);
}

/*
Why this approach is incorrect:

1. Violates subarray length constraint:
   - A valid circular subarray can include at most 'n' elements.
   - This loop runs ~2n iterations, allowing subarrays longer than 'n'.

2. Reuses elements (invalid for this problem):
   - Circular array allows wrapping, but NOT reusing elements.
   - This approach may include the same element multiple times.

3. Incorrect problem being solved:
   - Effectively computes max subarray over a "repeated" array.
   - Equivalent to solving on an infinite/duplicated array, not circular array.

4. Kadane’s algorithm assumption breaks:
   - Kadane assumes linear traversal without revisiting indices.
   - Using (i + 1) % size revisits elements → invalidates Kadane logic.

5. No control over subarray boundaries:
   - There is no mechanism to ensure subarray size ≤ n.
   - Leads to invalid subarrays like [5, -2, 3, 4, 5].

6. Produces incorrect results:
   - Can overestimate answer by including repeated high-value elements.
*/
/*
int max_circular_subarray_sum_optimised(int* arr, int &size)
{
    int res=arr[0];
    int max_sum_so_far=arr[0];

    for(int i=1,j=1;j<((2*size)-1);i=(i+1)%size,j++)
    {
        int new_max_sum_so_far=max_sum_so_far + arr[i];

        max_sum_so_far=max_value(arr[i], new_max_sum_so_far);
        res=max_value(res, max_sum_so_far);
    }

    return res;
}
*/

//______________________________________________________________________________________________________
// 15. Find the majority element

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int majority_element_naive(int* arr, int &size)
{
    int max=0, pos=-1;;

    for(int i=0;i<size;i++)
    {
        int count=0;
        
        for(int j=0;j<size;j++)
            if(arr[j]==arr[i])
                ++count;

        if(count > max)
        {
            max=count;
            pos=i;
        }
    }

    if(max > (size/2))
        return pos;

    else
        return -1;
}

int majority_element_optimised(int* arr, int &size)
{
    if(size<=0)
        return -1;

    int max=0, pos=-1;
    map<int, int> m;

    for(int i=0; i<size; i++)
    {
        /*
        auto itr=m.find(arr[i]);

        if(itr!=m.end())
        {
            ++(itr->second);

            if( (itr->second) > max )
            {
                max=itr->second;
                pos=i;
            }
        }

        else
            m.insert({arr[i], 1});
        */

        m[arr[i]]++; // automatically initializes to 0, then increments to 1

        if(m[arr[i]] > max)
        {
            max=m[arr[i]];
            pos=i; // store the index of the element
        }
    }

    if(max > (size/2) )
        return pos;

    return -1;
}

int findMajority(int* arr, int &size)
{

    if(size <= 0)
        return -1;

    int pos=0,count=1; 
    // initially the result is assumed to be the first element of the array

    // find a candidate
    for(int i=1;i<size;i++)
    {
        if(arr[pos]==arr[i])
            ++count;
        
        else
            --count;

        if(count==0)
        {
            pos=i;
            count=1;
        }
    }

    // now if the candidate is actually a majority
    count=0;
    for(int i=0;i<size;i++)
        if(arr[i] == arr[pos])
            ++count;
    
    if(count <= (size/2))
        pos=-1;
    
    return pos;
}

//______________________________________________________________________________________________________
// 16. Minimum consecutive flips

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

//______________________________________________________________________________________________________
// 17. Sliding window technique

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int sliding_window_sum_naive(int* arr, int &size, int k)
{
    if(size <= 0 || k <= 0 || k > size)
        return -1;

    int start=0, end=k-1, max=INT_MIN;

    while(end<size)
    {
        int sum=0;

        for(int i=start;i<=end;i++)
            sum = sum + arr[i];
        
        max = max_value(max, sum);
        
        // slide the window further
        ++start;
        ++end;
    }

    return max;
}

int sliding_window_sum_naive_alternate(int* arr, int &size, int k)
{
    if(size <= 0 || k <= 0 || k > size)
        return -1;
    
    int max=INT_MIN;

    for(int i=0; (i+k-1) < size; i++)
    {
        int sum=0;
        
        for(int j=0;j<k;j++)
            sum = sum + arr[i+j];
            
        max=max_value(max,sum);
    }

    return max;
}

int sliding_window_sum_optimised(int* arr, int &size, int k)
{
    if(size <= 0 || k <= 0 || k > size)
        return -1;

    int curr_sum=0;

    for(int i=0; i<k; i++)
        curr_sum = curr_sum + arr[i];
    
    int max = curr_sum;

    for(int i=k; i<size; i++)
    {
        curr_sum = curr_sum + arr[i] - arr[i-k];
        // add the next element in the new window, subtract the element that just went out of the window 
        max = max_value(max, curr_sum);
    }    

    return max;
}

//______________________________________________________________________________________________________
// 18. Subarray with given sum

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

string subarray_with_given_sum_naive(int* arr, int &size, int SUM)
{
    for(int i=0; i<size; i++)
    {
        int curr_sum=0;

        for(int j=i; j<size; j++)
        {
            curr_sum = curr_sum + arr[j];

            if(curr_sum == SUM)
                return "Yes";
        }
    }

    return "No";
}

string subarray_with_given_sum_optimised(int* arr, int &size, int SUM)
{
    int curr_sum=0, start=0, end=0;

    while(start<=end && end<=size)
    // here, end is <= size because your loop will check the sum after expansion
    {
        if(curr_sum == SUM)
            return "Yes";
        
        else if(curr_sum < SUM)
            curr_sum = curr_sum + arr[end++];
            // this is why it's "end<=size"
        
        else
            curr_sum = curr_sum - arr[start++];
    }

    return "No";
}

string subarray_with_given_sum_subarray(int* arr, int &size, int SUM)
{
    int s=0, curr_sum=0;

    for(int e=0; e<size; e++)
    // here expansion does not depend on any condition other than (e < size)
    {
        curr_sum = curr_sum + arr[e];
        
        while(curr_sum > SUM)
            curr_sum = curr_sum - arr[s++];

        if(curr_sum == SUM)
            return "Yes";
    }
    
    return "No";
}

//______________________________________________________________________________________________________
// 19. Equilibrium point

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

bool find_equilibrium_point_naive(int* arr, int &size)
{
    if(size<=0)
        return false;

    if(size==1)
        return true;

    for(int i=0; i<size; i++)
    {
        int lsum=0, rsum=0;

        for(int k=0; k<i; k++)
            lsum=lsum+arr[k];
        
        for(int k=i+1; k<size; k++)
            rsum=rsum+arr[k];

        if(lsum == rsum)
            return true;
    }

    return false;
}

bool find_equilibrium_point_optimised(int* arr, int &size)
{
    if(size<=0)
        return false;

    if(size==1)
        return true;

    int total_sum=0;
    for(int i=0;i<size;i++)
        total_sum = total_sum + arr[i];

    int lsum = 0, rsum = total_sum;
    for(int i=0; i<size; i++)
    {
        lsum = (i==0) ? 0 : (lsum + arr[i-1]);
        rsum = rsum - arr[i];

        if(lsum == rsum)
            return true;
    }

    return false;
}

bool find_equilibrium_point_optimised_alternate(int* arr, int &size)
{
    if(size<=0)
        return false;

    if(size==1)
        return true;

    int rsum=0;
    for(int i=0; i<size; i++)
        rsum = rsum + arr[i];
    
    int lsum=0;
    for(int i=0; i<size; i++)
    {
        rsum = rsum - arr[i];

        if(lsum == rsum)
            return true;
        
        lsum = lsum + arr[i];
    }

    return false;
}

//______________________________________________________________________________________________________
// 20. Prefix sum

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int range_sum_naive(int* arr, int &size, int start, int end)
{
    if(size<=0)
        return -1;

    int sum=0;
    for(int i=start; i<=end; i++)
        sum = sum + arr[i];
    
    return sum;
}

int* compute_prefix_sum(int* arr, int &size)
{
    int* psum=new int[size];
    psum[0]=arr[0];
    
    for(int i=1; i<size; i++)
        psum[i] = psum[i-1] + arr[i];

    return psum;
}

int size_rs=7;
int arr_rs[]={2,8,3,9,6,5,4};
// allowed globally as this is treated as a declaration by the compiler

/*
arr_rs[0]=2;
arr_rs[1]=8;
arr_rs[2]=3;
arr_rs[3]=9;
arr_rs[4]=6;
arr_rs[5]=5;
arr_rs[6]=4;

// This is NOT allowed globally because outside the main function the compiler expects a declaration not a operation,
// and the above lines are treated as operations
*/

int* psum=compute_prefix_sum(arr_rs, size_rs);

int range_sum_optimised(int l, int r)
{
    // we're assuming the (l <= r)
    if(l>r)
    {
        int temp=l;
        l=r;
        r=temp;
    }

    if(l==0)
        return psum[r];
    
    return psum[r] - psum[l-1];
}

//______________________________________________________________________________________________________
// 21. Weighted prefix sum

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int weights[]={1,2,3,4,5,6,7};

int* compute_weighted_prefix_sum(int* arr, int size, int weights[])
{
    int* pwsum=new int[size];
    pwsum[0] = ( weights[0] * arr[0] );
    
    for(int i=1; i<size; i++)
        pwsum[i] = pwsum[i-1] +( weights[i] * arr[i] );

    return pwsum;
}

int* pwsum=compute_weighted_prefix_sum(arr_rs, size_rs, weights);

int range_weighted_sum_optimised(int l, int r)
{
    // we're assuming the (l <= r)
    if(l>r)
    {
        int temp=l;
        l=r;
        r=temp;
    }

    if(l==0)
        return pwsum[r];
    
    return pwsum[r] - pwsum[l-1];
}

//______________________________________________________________________________________________________
// 22. Finding the maximum appearing element

/*
Below is a function to 

Time complexity:  

Space complexity: 
Auxiliary space:  
*/

int find_max_appearing_element(int* left_array, int* right_array, int &size)
{
    if(size==0)
        return -1;
    
    // 1. Create a vector that is the cobmination of the 'size' number of ranges
    vector<int> combined_ranges;

    for(int i=0; i<size; i++)
    {
        for(int j=left_array[i]; j<=right_array[i]; j++)
            combined_ranges.push_back(j);
    }

    // 2. Sort this vector
    sort(combined_ranges.begin(), combined_ranges.end());

    // 3. Create a map of frequencies for the vector elements
    map<int, int> freqs;

    int count=1, i;
    for(i=1; i < combined_ranges.size(); i++)
    {
        if(combined_ranges[i] == combined_ranges[i-1])
            ++count;
        
        else
        {
            //freqs.insert( {combined_ranges[i-1], count} );
            freqs[combined_ranges[i-1]] = count; 
            // safer because if by chance the key already exists then the insert function will silently fail 
            // the vector element is the key, their frequency is the value

            count=1;
            // reset the counter for the new element
        }

        // if we reached the last element then we need to insert it otherwise we will miss it
        if(i == combined_ranges.size()-1)
        {
            if(combined_ranges[i] == combined_ranges[i-1])
            freqs[combined_ranges[i-1]] = ++count;

        else
            freqs[combined_ranges[i]] = count;
        }
    }

    // 4. Find the maximum frequency and that corresponding element in the map of vector elements and their frequencies
    int key=-1;
    int max=INT_MIN;

    for(auto itr = freqs.begin(); itr != freqs.end(); itr++)
    {
        if( itr->second > max )
        {
            max = itr->second;
            key = itr->first;
        }
    }

    return key;
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

    int size_mcsas=3;
    int* arr_mcsas=new int[size_mcsas];

    arr_mcsas[0]=-8;
    arr_mcsas[1]=7;
    arr_mcsas[2]=6;

    int size_me=6;
    int* arr_me=new int[size_me];

    arr_me[0]=3;
    arr_me[1]=7;
    arr_me[2]=4;
    arr_me[3]=7;
    arr_me[4]=7;
    arr_me[5]=5;

    int size_sws=6;
    int* arr_sws=new int[size_sws];

    arr_sws[0]=1;
    arr_sws[1]=8;
    arr_sws[2]=30;
    arr_sws[3]=-5;
    arr_sws[4]=20;
    arr_sws[5]=7;

    int size_saws=5;
    int* arr_saws=new int[size_saws];

    arr_saws[0]=0;
    arr_saws[1]=1;
    arr_saws[2]=2;
    arr_saws[3]=3;
    arr_saws[4]=30;

    int size_ep=3;
    int*  arr_ep=new int[size_ep];

    arr_ep[0]=4;
    arr_ep[1]=2;
    arr_ep[2]=-2;

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

    cout<<endl;
    cout<<max_circular_subarray_sum_naive_course_approach(arr_mcsas, size_mcsas);

    cout<<endl;
    cout<<"Majority element in arr_me array: "<<findMajority(arr_me, size_me);

    cout<<endl;
    cout<<"Sliding window sum for the arr_sws: "<<sliding_window_sum_optimised(arr_sws, size_sws, 3);

    cout<<endl;
    cout<<"Subarray with given sum check: "<<subarray_with_given_sum_optimised(arr_saws, size_saws, 33);

    string ans = (find_equilibrium_point_optimised_alternate(arr_ep, size_ep)==true) ? "Yes" : "No";
    cout<<endl;
    cout<<"Is there an equilibrium point in the array arr_ep? "<<ans;

    cout<<endl;
    cout<<"Prefix sum: "<<range_weighted_sum_optimised(5, 6);

    int left_array[]={1, 2, 5, 15};
    int right_array[]={5, 8, 7, 18};
    int range_count=4;

    cout<<"Maximum appearing element in the ranges: "<<find_max_appearing_element(left_array, right_array, range_count);

    delete[] arr;
    delete[] sorted_arr;
    delete[] arr_z;
    delete[] arr_l;
    delete[] arr_md;
    delete[] arr_cf;
    delete[] arr_co;
    delete[] arr_msas;
    delete[] arr_leosl;
    delete[] arr_mcsas;
    delete[] arr_me;
    delete[] arr_sws;
    delete[] arr_saws;

    delete[] psum;
    delete[] pwsum;
    
    return 0;
}