//Approach-1 : 
class Solution {
  public:
    int maxWater(vector<int> &A) {
        // code here
        int len = A.size();
        int left=0;
        int right=len-1;
        int ans =0;

    while(left<right){

        int tempwater=min(A[left],A[right])*(right-left);

        ans=max(ans,tempwater);

        if(A[left]<A[right])
            left++;
        else{
            right--;
        }
    }
    
    return ans;      
    }
};


//Appraoch-2 : (Two Pointers)
//T.C : O(N)
//S.C : O(1)
class Solution {
  public:
    int maxWater(vector<int> &A) {
        // code here
        int n = A.size();
        int max_area = 0;
        // Two Pointer Approach
        int i = 0, j = n - 1;
        while(i<j){
            // Area of the container is the product of vertical length and horizontal length
            // Horizontal Length = Difference in X-Coordinates = j - i
            // Vertical Length = Minimum of the two Vertical lines because Water above that height flows away
            max_area = max(max_area, (j-i) * min(A[i], A[j]));
            // We need maximum area
            // Greedy Approach, try to maximize Vertical line height
            if(A[i] < A[j])
                i++;
            else
                j--;
        }
        return max_area;
    }
};
