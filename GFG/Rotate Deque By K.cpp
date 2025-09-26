//Approach-1 : 
//TC : O(k) 
//SC : O(1)
class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        if(type==2){
            while(k--){
                int e=dq.front();
                dq.pop_front();
                dq.push_back(e);
                
            }
        } else {
            while(k--){
                int e=dq.back();
                dq.pop_back();
                dq.push_front(e);
            }
        }
    }
};
