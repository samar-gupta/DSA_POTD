//Company Tags   : Accolite, Adobe, Amazon, D-E-Shaw, MakeMyTrip, Microsoft, Payu
//Leetcode Link  : https://leetcode.com/problems/trapping-rain-water/

//Approach-1
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> getLeftMax(vector<int>& height, int n) {
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for(int i = 1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int>& height, int n) {
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax;
    } 
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1 || n == 0)
            return 0;
        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
};



//Approach-2 : (2-Pointer)
//T.C : O(n)
//S.C : O(1)
//If two walls are there and we want want to fill water within that wall 
//we just have to fill the water till min of two wall, if it exceeds the value ,it will overflow.
//So, we can set 2 pointers left_max, right_max and check which side is greater,
//if one side is greater iterate on other side because at the min side the water will be filled at its limit.
//and iterate till pointer is lower than the other one.

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, left_max = height[0], sum = 0;
        int j = height.size() - 1, right_max = height[j];
        
        while (i < j) {
            if (left_max <= right_max) {
                sum += (left_max - height[i]);
                i++;
                left_max = max(left_max, height[i]);
            } else {
                sum += (right_max - height[j]);
                j--;
                right_max = max(right_max, height[j]);
            }
        }
        
        return sum;
    }
};
