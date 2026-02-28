#include<bits/stdc++.h>

using namespace std;

/*
Below is a naive approach to get if the k-th bit is set

Time complexity:   O(k) or since k is a constant O(1)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

bool check_if_kth_bit_set_naive(int n, int k)
{
    int x=1;

    for(int i=0;i<(k-1);i++)
        x=x*2;
        /*
        Multipying by 2 because: 

        2^1 = 2 => 00000010
        2^2 = 4 => 00000100
        2^3 = 8 => 00001000
        and so on.....
        */

    if(n&x)
        return true;

    else
        return false;
}

/*
Below is an optimized approach to get if the k-th bit is set

Time complexity:   O(1)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

bool check_if_kth_bit_set_optimized(int n, int k)
{
    /*
    if( n & (1<<(k-1)) )
        return true;

    else return false;
    */

    // more succinct than the previous version
    return ( n & (1u << (k-1)) )!=0;

    /*
    Concept:

    We need to compare n with a only whose only the first bit is set which is 
    1. And to get the kth bit that is set, we shift the one towars the left
    (k-1) (considering 0 based indexing) positions.

    Initially:
    00000001

    After shifting by, let's say (k-1) positions where k=4
    00000100
    */

    /*
    Note regarding edge case:

    1<<31 is dangerous because we're using int, which is signed by default.

    The 31st bit (considering 0 based indexing) or the MSB is the sign bit.

    Binary of 1:
    00000000 00000000 00000000 00000001

    Shift left 31:
    10000000 00000000 00000000 00000000
    
    That is -2147483648 because MSB=1 means it's a negative number.

    Now, signed overflow or sign bit shifting is undefined behaviour in C++.
    So, to be safe, use unsigned one when doing bit masks:
    1u << (k - 1)

    Now you're shifting an unsigned 1. Unsigned shifting is well-defined.
    */
}

/*
Below is a function to print the result of the preceding function (to check if the k-th bit is set or not)

Time complexity:   O(1)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

void print_result_of_kth_bit_check(int n, int k)
{

    // Because C++ only guarantees that the size of int >= 16 bits, not strictly 32 bits
    if(k<1 || k> sizeof(int)*8 )
    {
        cout<<"The value of "<<k<<" is not valid."<<endl;
        return;
    }

    bool result=check_if_kth_bit_set_optimized(n,k);

    string ordinal_num;
    
    if(k%10==1 && k%100!=11)
        ordinal_num="st";
    
    else if(k%10==2 && k%100!=12)
        ordinal_num="nd";
    
    else if(k%10==3 && k%100!=13)
        ordinal_num="rd";
    
    else
        ordinal_num="th";

    /*
    string set_or_not="No";

    if(result==true)
        set_or_not="Yes";
    
    else
        set_or_not="No";
    */

    // more succinct than the previous version
    string set_or_not = result ? "set" : "not set";

    cout<<k<<ordinal_num<<" bit of "<<n<<" is "<<set_or_not<<endl;
}

/*
Below is a naive approach to count the set bits in an input number

Time complexity:   O(log m) where m is the no. of bits in the input number

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

int count_set_bits_naive(int n)
{
    int count=0;

    while(n>0)
    {
        if(n%2==1) // if the bit is set then n%2 will NOT be zero
            ++count;
        
        n=n/2;
    }

    return count;
}

/*
Below is an optimized approach to count the set bits in an input number

Time complexity:   O(1)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

int count_set_bits_optimized(int n)
{
    int count=0;

    for( int i=1; i < (sizeof(int)*8) ; i++ )
    // i starts from 1 instead of zero to avoid (i-1) becomes -1 when i=0 and left shift -1 is undefined
        if( n & (1u << (i-1) ) )
            ++count;

    return count;
}

/*
Below is an alternate optimized approach to count the set bits in an input number

Time complexity:   O(1)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

int count_set_bits_optimized_alternate(int n)
{
    int count=0;

    while(n>0)
    {
        n=n&(n-1);
        ++count;
    }

    return count;
}

/*
Below is a function to be called for preprocessing of the array to be referenced when running the next function 
(to count the set bits in an input number)

Time complexity:   O(1)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

int table[256];

void initialize()
{
    table[0]=0;

    for(int i=1;i<256;i++)
        table[i]=table[i & (i-1)] + 1;
}

/*
Below is an alternate optimized approach with some preprocessing to make it faster to count the set bits in an input number

Time complexity:   O(1)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

int count_set_bits_optimized_further(int n)
{
    initialize();
    
    return table[(n) & 255] + table[(n>>8) & 255] + table[(n>>16) & 255] + table[(n>>24)];
}

/*
Below is a naive implementation of a function to check if the input number is a power of 2

Time complexity:   O(log n)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

bool check_power_of_2_more_naive(int n)
{
    if(n==0)
        return false;
    
    while(n!=1)
    {
        if(n%2!=0)
            return false;

        n=n/2;
    }

    return true;
}

/*
Below is a optimized implementation of a function to check if the input number is a power of 2

Time complexity:   O(log n)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

bool check_power_of_2_naive(int n)
{
    if(n<=0)
        return false;
    
    if(n==1)
        return true;

    //if(n%2!=0)
    //    return false;

    int i=1;
    while(i<(sizeof(int)*8))
    {
        if((n&(1u<<i))==n)
            return true;

        ++i;
    }
        
    return false;
}

/*
Below is a optimized implementation of a function to check if the input number is a power of 2

Time complexity:   O(1)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

bool check_power_of_2_optimized(int n)
{
    return  (n>0) && (( n & (n-1)) == 0 );
    // return (condition1) && (condition2);
}

/*
Below is a naive implementation of a function to find the only element that occurs an odd number of 
times in the input array

Time complexity:   O(n^2)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

int find_only_odd_occurring_element_more_naive(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        int count=0;

        for(int j=0;j<size;j++)
            if(arr[i]==arr[j])
                ++count;

        if(count%2!=0)
            return arr[i];
    }

    return -1;
}

/*
Below is a naive implementation of a function to find the only element that occurs an odd number of 
times in the input array

Time complexity:   O(n logn)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

int find_only_odd_occurring_element_naive(int arr[], int size)
{
    if(size==1)
        return arr[0];
    
    // this copies the array elements into the vector
    vector<int> vec(arr, arr+size);

    sort(vec.begin(), vec.end());

    int count=0;

    vector<int> elements; 
    vector<int> freqs;

    elements.push_back(vec[0]);
    freqs.push_back(1);

    int j=0;

    for(int i=0;i+1<size;i++)
    {
        if(vec[i]==vec[i+1])
            ++freqs[j];

        else
        {
            elements.push_back(vec[i+1]);
            freqs.push_back(1);
            ++j;
        }
    }

    for(int i=0;i<freqs.size();i++)
    {
        /*
        we return straightaway because we assume that in this problem there is only
        one element that occurs in the array an odd number of times.
        */ 
        if(freqs[i]%2!=0)
            return elements[i];
    }

    return -1;
}

/*
Below is an optimized implementation of a function to find the only element that occurs an odd number of 
times in the input array

Time complexity:   O(n)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

int find_only_odd_occurring_element_optimized(int arr[], int size)
{
    int res=arr[0];

    for(int i=1;i<size;i++)
        res=res^arr[i];

    return res;
}

/*
Below is a naive implementation of a function to find the two elements that occur an odd number of 
times in the input array

Time complexity:   O(n^2)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

pair<int,int> find_2_odd_occurring_elements_naive(int arr[], int size)
{
    pair<int,int> pr(0,0);
    bool res=false;
    
    for(int i=0;i<size;i++)
    {
        int count=0;

        for(int j=0;j<size;j++)
            if(arr[i]==arr[j])
                ++count;  
                
        if(count%2!=0)
        {
            if(res==true)
            {
                pr.second=arr[i];
                return pr;
            }

            pr.first=arr[i];
            res=true;
        }
    }

    return pr;
}

/*
Below is an optimized implementation of a function to find the two elements that occur an odd number of 
times in the input array

Time complexity:   O(n)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

pair<int,int> find_2_odd_occurring_elements_optimized(int arr[], int size)
{
    int x=arr[0];

    for(int i=1;i<size;i++)
        x=x^arr[i];

    int y=(x&(~(x-1)));

    pair<int,int> pr(0,0);

    for(int i=0;i<size;i++)
    {
        if((arr[i]&y)!=0) 
            pr.first=pr.first^arr[i];
        
        else
            pr.second=pr.second^arr[i];
    }

    return pr;
}

/*
Below is an implementation of a function to find the power set of an input string

Time complexity:   O(n.2^n)

Space complexity:  O(1) 
Auxiliary space:   O(1)
*/

void print_power_set(string str)
{
    int length=str.length();
    int p_size=(1<<length);

    for(int i=0;i<p_size;i++)
    {
        for(int j=0;j<length;j++)
            if((i&(1<<j))!=0)
                cout<<str[j];
        cout<<"\n";
    }
}

int main()
{
    /*
    // the below code is correct and working, just not needed for testing anymore so I've commented them out

    int n,k;

    cout<<"Enter an integer n=";
    cin>>n;

    cout<<"Enter a natural number k=";
    cin>>k;

    print_result_of_kth_bit_check(n,k);

    cout<<"Number of set bits in "<<n<<" are "<<count_set_bits_optimized(n)<<endl;

    cout<<"Number of set bits in "<<n<<" are (using the table lookup method) "<<count_set_bits_optimized_further(n)<<endl;
    
    int arr[]={8,34,8,7,99,99,34};
    int size=sizeof(arr)/sizeof(arr[0]);

    int result=find_only_odd_occurring_element_optimized(arr,size);

    if(result==-1)
        cout<<"This input is invalid."<<endl;
    
    else
        cout<<"Only element in the array that occurs an odd number of times: "<<result<<endl;

    int arr[]={1,3,2,3,3,1};
    int size=sizeof(arr)/sizeof(arr[0]);

    pair<int,int> pr=find_2_odd_occurring_elements_optimized(arr,size);

    cout<<"The two elements that are occurring an odd number of times in the array are "<<pr.first<<" and "<<pr.second<<endl;
    */

    print_power_set("ab");

    return 0;
}