//Approach-1 :
class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int count = 1;
        int maxHeight = arr[0];
        
        for(int i = 1; i < n; i++) {
            if(arr[i] >= maxHeight) {
                count++;
                maxHeight = arr[i];
            }
        }
        
        return count;
    }
};



//Approach-1 :
class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n = arr.size();
        int maxHeightToTheLeft = arr[0];
        int noSunligthBuildings = 0;
        
        for(int i = 1 ; i < n ; i++){
            if(arr[i] < maxHeightToTheLeft){
                noSunligthBuildings++;
            }
            maxHeightToTheLeft = max(maxHeightToTheLeft , arr[i]);
        }
        
        return (n - noSunligthBuildings);
    }
};
