class Solution {
  public:
    bool canServe(vector<int> &bills) {
        // code here
        int five=0,ten=0;
        
        for(int i:bills){
            if(i==5)   //if customer gives $5 we take it as the cost
            five++;
            
            else if(i==10){ //if we get $10,we reduce $5 bill by one and increase $10 bill by one
                five--;
                ten++;
            }
            else if(ten > 0 && five >=1){ //if we get $20,we give back $10+$5
                ten--;
                five--;
            }
            else        //if we are unable to give $10+$5 than we have to give back $5+$5+$5
            five-=3;
            
            if(five < 0)  //if at any time, we don't have $5 we return false
            return false;
        }
        return true;
    }
};
