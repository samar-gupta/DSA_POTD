class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       int l=0,h=n-1;
       while(l<h){
           int mid=(l+h)/2;
           if(arr[mid]<arr[mid+1]) l=mid+1;
           else h=mid;
       }
       return l;
    }
};



//Approach-1
//T.C - O(n) , S.C : O(1)
class Solution
{
    public:
    int peakElement(int arr[], int n) {
       
       for(int i = 0; i < n-1; i++) {
           if(arr[i] > arr[i+1]) return i;
       }
       
       return n-1;
    }
};



//Approach-2
//T.C - O(logn) , S.C : O(1)
class Solution
{
    public:
    int peakElement(int arr[], int n) {
       
       int start = 0, end = n-1;
       int mid = start + (end - start)/2;
       
       while(start < end) {
           
           if(arr[mid] < arr[mid+1]) {
               start = mid+1;
           } else {
               end = mid;
           }
           
           mid = start + (end-start)/2;
       }
       
       return start;
    }
};
