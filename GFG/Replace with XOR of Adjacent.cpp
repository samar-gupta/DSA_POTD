//Approach-1 :
class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        int n = arr.size();

        vector<int> temp(n);

        temp[0] = arr[0] ^ arr[1];

        temp[n - 1] = arr[n - 2] ^ arr[n - 1];

        for (int i = 1; i < n - 1; i++) {
            temp[i] = arr[i - 1] ^ arr[i + 1];
        }

        arr = temp;
    }
};


//Approach-2 :
class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int first = arr[0] ^ arr[1];
        int last = arr[n - 2] ^ arr[n - 1];
        int prev = arr[0];
        
        for (int i = 1; i < n - 1; i++) {
            int curr = arr[i];
            arr[i] = prev ^ arr[i + 1];    
            prev = curr;
        }
    
        arr[0] = first;
        arr[n - 1] = last;
    }
};
