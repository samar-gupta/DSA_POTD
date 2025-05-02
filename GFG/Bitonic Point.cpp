//Approach-1 : 
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i=0; i<n-1; i++)
	    {
	        if(arr[i]>arr[i+1])
	            return arr[i];
	    }
	    return arr[n-1];
    }
};

//Approach-2 : 
//T.C : O(logn)
//S.C : O(1)
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int ans=-1;
        int low=0, high=arr.size()-1;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(arr[mid]>arr[mid+1]){
                ans=arr[mid];
                high = mid-1;
            }
            else if(arr[mid]<=arr[mid+1]){
                low=mid+1;
            }
            
        }
        return ans;
    }
};
