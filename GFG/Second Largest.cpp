class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int large = arr[0], large2 = -1;
	    for(int i=1; i<n; i++)
	    {
	        if(arr[i] > large)
	        {
	            large2 = large;
	            large = arr[i];
	        }
	        else if(arr[i] < large)
	        {
	            large2 = large2 > arr[i] ? large2 : arr[i];
	        }
	    }
	    return large2;
    }
};
