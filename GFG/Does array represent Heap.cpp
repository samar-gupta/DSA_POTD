//In a binary heap represented as an array, 
//the left child of a node at index i is located at index 2*i + 1, 
//and the right child is at index 2*i + 2 
//and child nodes are always less than parent nodes.

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
