Ques 1.Two elements whose sum is closest to zero.

An Array of integers is given, both +ve and -ve. You need to find the two elements such that their sum is closest to zero. For the below array, the program should print -80 and 85.


#include <bits/stdc++.h>
using namespace std;
 
void quickSort(int *, int, int);
 

void fun(int arr[], int n)
{
         
  
    int sum, min_sum = INT_MAX;
     
    
    int l = 0, r = n-1;
     
    
    int min_l = l, min_r = n-1;
     
    
    if(n < 2)
    {
        cout << "Invalid Input";
        return;
    }
     
    
    quickSort(arr, l, r);
     
    while(l < r)
    {
        sum = arr[l] + arr[r];
     
        
        if(abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            min_l = l;
            min_r = r;
        }
        if(sum < 0)
            l++;
        else
            r--;
    }
     
    cout << "The two elements whose sum is minimum are "
         << arr[min_l] << " and " << arr[min_r];
}
 
// Driver Code
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    fun(arr, n);
    return 0;
}

void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
 
int partition(int arr[], int si, int ei)
{
    int x = arr[ei];
    int i = (si - 1);
    int j;
     
    for (j = si; j <= ei - 1; j++)
    {
        if(arr[j] <= x)
        {
            i++;
            exchange(&arr[i], &arr[j]);
        }
    }
    exchange (&arr[i + 1], &arr[ei]);
    return (i + 1);
}
 

void quickSort(int arr[], int si, int ei)
{
    int pi; 
    if(si < ei)
    {
        pi = partition(arr, si, ei);
        quickSort(arr, si, pi - 1);
        quickSort(arr, pi + 1, ei);
    }
}
******************************************************************************************
Ques 2.Given an array of n elements that contains elements from 0 to n-1,
 with any of these numbers appearing any number of times. 
Find these repeating numbers in O(n) and using only constant memory space.



#include <bits/stdc++.h>
using namespace std;
 

void func(int arr[], int size)
{
    int i;
    cout << "The repeating elements are:" << endl;
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i])] >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    func(arr, arr_size);
    return 0;
}
***************************************************************************************************
Ques 3. 

#include <bits/stdc++.h>
using namespace std;
 
int func(int arr[], int n, int x, int y)
{
         
    
    int p = -1, min_dist = INT_MAX;
     
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]==x || arr[i]==y)
        {
            if( p != -1 && arr[i] != arr[p])
                min_dist = min(min_dist , i-p);
              
            
            p=i;
        }
    }
    
    if(min_dist==INT_MAX)
        return -1;
 
    return min_dist;
}
 

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x = 3;
    int y = 6;
 
    cout << "Minimum distance between " << x <<
                        " and " << y << " is "<<
                        func(arr, n, x, y) << endl;
    return 0;
}