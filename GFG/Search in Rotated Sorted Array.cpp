//Approach-1 : 
class Solution {
  public:
    int search(vector<int>& arr, int target) {
        // complete the function here
        int low=0, high=arr.size()-1;
        
        while(low<=high){
            int mid= (high+low)/2;
            
            if(arr[mid]==target) return mid;
            
            if(arr[low]<=arr[mid]){
                if(target>=arr[low] && target<arr[mid]) high=mid-1;
                else low=mid+1;
            }
            else{
                if(target<=arr[high] && target>arr[mid] ) low=mid+1;
                else high=mid-1;
            }
        }
        
        return -1;
    }
};


//Approach-2 : 
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while(low < high){
            int mid = (low + high)/2;
            
            if(arr[mid] > arr[high]){
                if(key > arr[mid] || key <= arr[high])
                    low = mid + 1;
                else
                    high = mid;
            }else{
                if(key > arr[mid] && key <= arr[high])
                    low = mid + 1;
                else 
                    high = mid;     
            }
        }
        if(low == high && key != arr[low])
            return -1;
        return low;
    }
};
