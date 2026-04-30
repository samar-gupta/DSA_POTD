//Approach-2: (Slight Optimization - {
// only need to check till n/2 - 1, 
// because beyond that all nodes are leaf nodes 
// and don’t have children. } )
class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        for(int i = 0; i <= (n/2) - 1; i++) {
            
            int left = 2*i + 1;
            int right = 2*i + 2;
            
            if(left < n && arr[i] < arr[left]) {
                return false;
            }
            
            if(right < n && arr[i] < arr[right]) {
                return false;
            }
        }
        
        return true;
    }
};



//old
//Approach-1 : 
class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        for(int i = 0; i < n; i++) {
            int leftChildIdx = 2*i + 1;
            int rightChildIdx = 2*i + 2;
            
            if(leftChildIdx < n && arr[leftChildIdx] > arr[i]) {
                return false;
            }
            
            if(rightChildIdx < n && arr[rightChildIdx] > arr[i]) {
                return false;
            }
        }
        
        return true;
    }
};
