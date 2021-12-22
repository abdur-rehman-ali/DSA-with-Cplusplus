#include<iostream>
using namespace std;


// Given a zero-based permutation nums (0-indexed), 
// build an array ans of the same length 
// where ans[i] = nums[nums[i]] 
// for each 0 <= i < nums.length and return it.


int* buildArray(int arr[],int size)
{
   int ans[size];
   for (int i =0;i<size;i++)
   {
       ans[i] = arr[arr[i]];
   }
   return ans;
    
}

int main()
{
    // int arr[]={0,2,1,5,3,4};
    int arr[]={5,0,1,2,3,4};
    int *ans;
    int size = sizeof(arr) / sizeof(arr[0]);
    ans=buildArray(arr,size);
    cout<<ans<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

