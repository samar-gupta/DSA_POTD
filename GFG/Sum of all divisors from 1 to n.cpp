/*
                      |    (i)        no. of times     sum
    1 = 1             |     1   ->        5            5 (5*1)
    2 = 1 2           |     2   ->        2            4
    3 = 1 3           |     3   ->        1            3
    4 = 1 2 4         |     4   ->        1            3
    5 = 1 5           |     5   ->        1            5
                      |                             ans = 21
*/

class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long ans = 0;
        for(int i = 1; i<=N; i++) {
            ans += (N/i)*i;            //getting no. of times (frequency) of divisor of a number by N/i
        }
        return ans;
    }
};
