//Approach : Boyer-Moore Voting Algorithm
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int count=0, element=-1;
        for(int num: arr){
            if(count==0) element=num;
            count += (num==element)?1:-1;
        }
        count=0;
        for(int num: arr){
            if(num==element){
                count++;
            }
        }
        if(count>arr.size()/2) return element;
        return -1;
    }
};
