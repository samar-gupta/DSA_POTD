class Solution {
  public:
    int digitSum(int n) {
        int sum = 0;
        while(n) {                        // or while(n != 0)
            sum += n%10;
            n = n/10;
        }
        return sum;
    }
  
    int isPossible(int N, int arr[]) {
        int total_sum = 0;
        for(int i=0; i<N; i++) {
            total_sum += digitSum(arr[i]);
        }
        return total_sum % 3 == 0 ? 1 : 0;
    }
};
