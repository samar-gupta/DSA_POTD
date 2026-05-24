//Approach-1 : 
class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int left = 0;
        
        int right = arr.size() - 1;

        while (left < right) {
            
            if (arr[left] > arr[right]) {
                left++;
            }
            else {
                
                right--;
            }
        }

        return arr[left];
    }
};



//Approach-2 : 
class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        return *min_element(arr.begin(), arr.end());
    }
};
