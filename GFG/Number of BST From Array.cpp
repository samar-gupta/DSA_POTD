//Approach-1 : (USING CATALAN NUMBERS)
/* Intuition:
     We know that for each root node, 
     the number of child nodes on its left would be the nodes less than it 
     and the number of child nodes on its right would be greater than it.
     Now we know that number of BSTs possible from a root would be:
     catalan(count less than root) * catalan(count greater than root)
*/
class Solution {
  public:
    int mem[30];
    
    int findCatalan(int n) {
        if(n<=1) {
            return 1;
        }
        
        if(mem[n] != 0) return mem[n];
        
        int res = 0;
        
        for(int i=0; i<n; i++) {
            res += findCatalan(i) * findCatalan(n-i-1);
        }
        
        return mem[n] = res;
    }
    
    int countLess(vector<int> arr, int x) {
        int c = 0;
        for(int e : arr) {
            if(e < x) c++;
        }
        
        return c;
    }
    
    
    int countMore(vector<int> arr, int x) {
        int c = 0;
        for(int e : arr) {
            if(e > x) c++;
        }
        
        return c;
    }
    
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        vector<int> ans;
        
        for(int x : arr) {
            int less = countLess(arr, x);
            int more = countMore(arr, x);
            ans.push_back(findCatalan(less) * findCatalan(more));
        }
        
        return ans;
    }
};
