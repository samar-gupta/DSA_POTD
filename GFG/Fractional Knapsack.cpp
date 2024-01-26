class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        priority_queue<pair<double,int>> pq;
        
        for(int i = 0; i<n ; i++){
            pq.push({(arr[i].value*1.0/arr[i].weight) , arr[i].weight});
        }
        
        double sum = 0;
        double profit = 0;
        
        while(!pq.empty()){
            auto it = pq.top(); 
            pq.pop();
            
            if(sum + it.second <= W){
                sum += it.second*1.0;
                profit += it.second*it.first*1.0;
            }
            else{
                double rem = W - sum;
                profit += rem*it.first*1.0;
                break;
            }
        }
        
        return profit;
    }
        
};
