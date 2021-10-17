#include <bits/stdc++.h>
typedef  long long int ll;

using namespace std;

//bubble sort
void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
       for(int j=0;j<n-i-1;j++)
       {
           if(arr[j]>arr[j+1])
           swap(arr[j],arr[j+1]);
       }
    }
}

//insertion sort
void insertionSort(int nums[],int n)
{
   	for (int i = 1; i <n;++i)
   	{
   	/* code */
   		int steps=i;
   		for(int j=steps;j>=1;j--)
   		{
   			if(nums[j]<nums[j-1])
   				swap(nums[j],nums[j-1]);
   			else
   				break;
   		}
   	}
}

//merge sort
void merge(int nums[],int low,int high, int mid)
{
    
    int n1=mid-low+1,n2=high-mid;
    int ar1[n1],ar2[n2];
    for(int i=0;i<n1;i++)
    {
        ar1[i]=nums[low+i];
    }
    for(int i=0;i<n2;i++)
    {
        ar2[i]=nums[mid+i+1];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(ar1[i]<ar2[j])
        {
            nums[k]=ar1[i];
            i++;k++;
        }
        else
        {
            nums[k]=ar2[j];
            j++;k++;
        }
    }
    while(i<n1)
    {
        nums[k]=ar1[i];
        k++,i++;
    }
    while(j<n2)
    {
        nums[k]=ar2[j];
        k++,j++;
    }
}
void mergeSort(int nums[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,high,mid);
    }
}

//quick sort
int partition (int arr[], int low, int high)
{
   int part=arr[high],i=low-1;
   for(int j=low;j<high;j++)
   {
       if(arr[j]<part)
       {
           i++;
           swap(arr[i],arr[j]);
       }
   }
   swap(arr[i+1],arr[high]);
   return i+1;
}
void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int part=partition(arr,low,high);
        quickSort(arr,low,part-1);
        quickSort(arr,part+1,high);
    }
}

//selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ar[n]={0};
    for (int i = 0; i < n; ++i)
    {
        cin>>ar[i];
    }
    bubbleSort(ar,n);
//     insertionSort(ar,n);
//     mergeSort(ar,0,n-1);
//     quickSort(ar,0,n-1);
//     selectionSort(ar,n);
    for (int i = 0; i < n; ++i)
    {
        cout<<ar[i]<<" ";
    }
}
/*
Analysis of each sorting algorithms

**********************************************************************************************
1. Bubble Sort: Running n-1 loops and swapping every element to put the largest element at the last unsorted index.
   Time Complexity : Best => O(n) , Worst & Average => O(n*n)
   Space Complexity: O(1) 
   Stablitiy       : Stable
   Is-In-Place     : In-Place	
   When to use     : 1. If array is of small size 
		             2. If array is of large size but nearly sorted
   Remark          : Easiest to implement	

**********************************************************************************************
2. Selection Sort: Traversing the unsorted part and selecting the smallest element and putting it in the first.
   Time Complexity : Best & Worst & Average => O(n*n)
   Space Complexity: O(1) 
   Stablitiy       : Not-Stable
   Is-In-Place     : In-Place
   When to use     : 1. If array is of small size
		             2. To minimise the number of swaps
   Remarks         : Bubble sort has more number of swaps as compare to selection
		             Sort but bubble sort has better best time complexity.
		             It can also be implemented as stabaly.
		             Selection sort makes O(n) swaps which is minimum among all sorting algorithms mentioned above.	


**********************************************************************************************
3. Insertion Sort: While inserting the elements check if it is in correct position or not, if not then traverse the array from that index to 0th index and put that element when the required index is found.
   Time Complexity : Best => O(n) , Worst & Average => O(n*n)
   Space Complexity: O(1) 
   Stablitiy       : Stable
   Is-In-Place     : In-Place
   When to use     : 1. If array is of small size and nearly sorted
   Remark          : Standard Libraray of C uses this algo when n becomes smaller
		             than a threshold and for small size it is better than merge
		             and quick sort becasue of low constant values and non
 		             recusive in nature.
		

**********************************************************************************************
4. Heap Sort: 
   Time Complexity : Best & Worst & Average => O(nLog(n))
   Space Complexity: O(1) 
   Stablitiy       : Not-Stable
   Is-In-Place     : In-Place
   When to use     : When the input array is large and stable sort is not 
                     required.		
   Remark          : It always guaranteed to be O(nLog(n)) with constant space 
                     which solves the problem of overflow of address space of a 
                     process which may occur in merge and quick sort(recursive stack).

**********************************************************************************************
5. Counting Sort: Store the frequency of the elements in an array and then print the frequency array.
   Time Complexity : Best & Worst & Average => O(n+k)
   Space Complexity: O(n+k); k=Maxelement-minelement
   Stablitiy       : Not-Stable
   Is-In-Place     : In-Place


**********************************************************************************************
6. Merge Sort: Divide the Array into two parts and mergesort them again and then merge both.
   Time Complexity : Best & Worst & Average => O(nLog(n))
   Space Complexity: O(n) 
   Stablitiy       : Stable 
   Is-In-Place     : Not-In-Place
   Tag             : Divide & Conquer
   When to use     : 1.When we don't have random access(linked list)
                      [R.A like as we have in array]
                     2.When array is not to large.

**********************************************************************************************
7. Quick Sort: Get the partition point and then sort both the parts
   Time Complexity : Best => O(nLog(n)) , Worst => O(n*n) 
   Space Complexity: O(n) 
   Stablitiy       : Not-Stable 
   Is-In-Place     : In-Place
   Tag             : Divide & Conquer
   When to use     : 1.It is prefered over merge sort for extremely large array
                     2.When you don't care about worst case complexity
----------------------------------------------------------------------------------------------
**********************************************************************************************
             Quick Sort                    *    Merge Sort 
1.Time       O(nLog(n)),O(n*n).            *    O(nLog(n))
2.Space      O(1).                         *    O(n)
3.Advantage  When random access is there.  *    When random access is costly(i.e Linked List)
4.Stability  Not Stable.                   *    Stable
5.In-Place   In-Place.                     *    Not-In-Place
6.Address    Never Rise.                   *    May arise when array/list is extremely large
  Space
  Overflow
  Condition

**********************************************************************************************
*/

