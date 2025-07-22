//updated
//Smallest Positive Missing
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        for(int i = 0;i<n;i++){
            while(arr[i]>0 && arr[i]<=n  && arr[arr[i] - 1] != arr[i]){
                swap(arr[i],arr[arr[i]-1]);
            }
        }
        
        for(int i =0 ;i<n;i++){
            if(arr[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};


//old
//Approach-1 : 
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        sort(begin(arr), end(arr));
       int count=1;
       for (int i=0;i<n;i++){
           if (arr[i]==count)
           count++;
       }
       return count;
    }
};


//Approach-2 : 
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        for(int i=0 ; i<n ; i++)
            while(arr[i]>0 and arr[i]<=n and arr[i]!=arr[arr[i]-1])
                swap(arr[i],arr[arr[i]-1]) ;
                
        for(int i=0 ; i<n ; i++)
            if(arr[i]!=i+1) return i+1 ;
        return n+1 ;
    }
};
