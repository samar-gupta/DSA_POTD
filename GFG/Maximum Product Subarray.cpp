//Approach-1 : 
class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n =arr.size();
        int left=1,right=1;
        int maxLeft=INT_MIN,maxRight=INT_MIN;
        
        for(int i=0;i<n;i++){
            left*=arr[i];
            maxLeft=max(maxLeft,left);
            if(left==0) left=1;
        }
        for(int i=n-1;i>=0;i--){
            right*=arr[i];
            maxRight=max(maxRight,right);
            if(right==0) right=1;
        }
        return max(maxLeft,maxRight);
    }
};


//Approach-2 : 
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        long long ma=arr[0];
	    long long mi=arr[0];
	    long long ans=arr[0];
	 
	    for(int i=1;i<n;i++){
	        long long temp=arr[i];
	        if(temp<0)
	            swap(ma,mi);
	        
	        ma=max(temp,ma*temp);
	        mi=min(temp,mi*temp);
	        ans=max(ans,ma);
	    }
	    return ans;
    }
};
