//Approach-1 :
/*
1. First, check if d > max(m, n).
     If yes, answer is -1.

2. Then check if d % gcd(m, n) != 0.
     If yes, answer is -1.

3. Otherwise, simulate both possible directions:
     Pour from m to n
     Pour from n to m

4. In each simulation:
     Fill the source jug if empty
     Pour from source to target
     Empty target if it becomes full
     Continue until either jug contains d litres

5. Return the minimum operations from both simulations.
*/
class Solution {
  public:
    
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    
    int pour(int fromCap, int toCap, int d) {
        int from = fromCap;
        int to = 0;
        int steps = 1;
        
        while (from != d && to != d) {
            
            int transfer = min(from, toCap - to);
            to += transfer;
            from -= transfer;
            steps++;
            
            if (from == d || to == d)
                break;
            
            if (from == 0) {
                from = fromCap;
                steps++;
            }
            
            if (to == toCap) {
                to = 0;
                steps++;
            }
        }
        
        return steps;
    }
    
    int minSteps(int m, int n, int d) {
        
        if (d > max(m, n))
            return -1;
        
        if (d % gcd(m, n) != 0)
            return -1;
        
        return min(pour(m, n, d), pour(n, m, d));
    }
};



//Approach-1 :
class Solution {
public:
    // Helper function to simulate the pouring process
    int simulate(int fromCap, int toCap, int target) {
        int from = fromCap;
        int to = 0;
        int steps = 1; // Initial fill

        while (from != target && to != target) {
            // How much can we pour?
            int temp = min(from, toCap - to);

            // Pour from -> to
            to += temp;
            from -= temp;
            steps++;

            if (from == target || to == target) break;

            // If "from" jug becomes empty, fill it
            if (from == 0) {
                from = fromCap;
                steps++;
            }

            // If "to" jug becomes full, empty it
            if (to == toCap) {
                to = 0;
                steps++;
            }
        }
        return steps;
    }

    int minSteps(int m, int n, int d) {
        // Basic feasibility checks
        if (d > max(m, n)) return -1;
        if (d % __gcd(m, n) != 0) return -1;

        // Return the minimum of the two possible simulation paths
        return min(simulate(m, n, d), simulate(n, m, d));
    }
};
