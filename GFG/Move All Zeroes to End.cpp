//Approach-1 :
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i=0;
	    int j=0;
	    while(j<n)
	    {
	        if(arr[j]!=0)
	        {
	            swap(arr[i], arr[j]);
	            i++;
	        }
	        j++;
	    }
    }
};


//Approach-2 : 
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int slow=0;
        for(int fast=0;fast<arr.size();fast++){
            if(arr[fast]!=0){
                arr[slow]=arr[fast];
                slow++;
            }
            
        }
        
        while(slow<arr.size()){
            arr[slow]=0;
            slow++;
        }
    }
};


// Approach-2 : 
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int slow = 0;

        // Move non-zero elements forward
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                arr[slow] = arr[i];
                slow++;
            }
        }

        // Fill remaining positions with zeros
        for (int i = slow; i < arr.size(); i++) {
            arr[i] = 0;
        }

    }
};
