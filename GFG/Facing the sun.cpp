class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        int n = height.size();
        int count = 1;
        int lastBuilding = height[0];
        for(int i=1; i<n; i++){
            if(height[i] > lastBuilding){
                lastBuilding = height[i];
                count++;
            }
        }
        
        return count;
    }
};
