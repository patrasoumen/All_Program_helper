//lets first discuss the O(n) time and O(1) space algorithm.
//problem link: https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <bits/stdc++.h>
using namespace std;
 
// A XOR based function to find
// the element that appears only once
void search(int arr[], int n)
{
    int XOR = 0;
    for (int i = 0; i < n; i++) {
        XOR = XOR ^ arr[i];
    }
    cout << "The required element is " << XOR << "\n";
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
    search(arr, n);
    return 0;
}

/* 
An efficient and optimized approach will be using binary search as 
the array is sorted and check the pairity of the elements at a certain index.
Sample test case:
9
1 1 2 2 3 4 4 5 5

*/
#include<bits/stdc++.h>
typedef  long long int ll;
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    if(n==1)//if there is only one element then the element itself is the required element
    {
        cout<<ar[0]<<endl;
        return;
    }
    if(ar[0]!=ar[1])//to check if the non-repeating element is at first index.
    {
        cout<<ar[0]<<endl;
        return;
    }
    if(ar[n-2]!=ar[n-1])//to check if the non-repeating element is at last index.
    {
        cout<<ar[n-1]<<endl;
        return;
    }
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid= (start+end)/2;
        if(ar[mid]!=ar[mid-1] && ar[mid]!=ar[mid+1])//if the middle element is non repeating then print and return.
        {
            cout<<"The required number is "<< ar[mid]<<endl;
            return;
        }
        else if(mid%2==0 && ar[mid]==ar[mid+1] )//if the index is even and it is same as index+1 then increase the starting index to mid+1.
        {
            start=mid+1;
        }
        else if(mid%2 ==0 && ar[mid]==ar[mid-1])//if the index is even and it is same as index-1 then decrease the ending index to mid-1.
        {
            end=mid-1;
        }
        else if(ar[mid]==ar[mid+1])//if the index is odd and it is same as index+1 then decrease the ending index to mid-1.
        {
            end=mid-1;
        }
        else//if the index is odd and it is same as index-1 then incrcease the starting index to mid+1.
        {
            start=mid+1;
        }
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    solve();
    return 0;
}
