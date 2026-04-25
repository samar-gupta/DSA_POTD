//Leetcode Link : https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/

//Approach-1 (Binary Search + Backtracking Brute Force)
//T.C : O(nCk * k * log side)
//S.C : O(k)
class Solution {
public:
    int manhattanDist(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    bool check(vector<vector<int>>& points, int k, int mid, int i, vector<int>& chosen) {
        if(chosen.size() == k) {
            return true;
        }

        for(int p = i; p < points.size(); p++) {
            bool valid = true;

            for(int idx : chosen) {
                if(manhattanDist(points[p], points[idx]) < mid) {
                    valid = false;
                    break;
                }
            }

            if(!valid) {
                continue;
            }

            chosen.push_back(p);
            if(check(points, k, mid, p+1, chosen)) {
                return true;
            }
            chosen.pop_back();
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int l = 0;
        int r = 2*side;

        int result = 0;

        while(l <= r) {
            int mid = l + (r-l)/2;

            vector<int> chosen;

            if(check(points, k, mid, 0, chosen)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;
    }
};


//Approach-2 (Binary Search + Optimised check)
//T.C : O(nlogn+log(side)⋅n⋅klogn)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;

    ll get1D(int side, int x, int y) {
        if(y == 0) return x;

        if(x == side) return side + y;

        if(y == side) return 3LL * side - x;

        return 4LL * side - y;
    }

    bool check(vector<ll>& doubled, int n, int k, int side, int mid) {
        ll perimeter = 4LL * side;

        for(int i = 0; i < n; i++) { //O(n)
            int count = 1; //Picked one point
            int idx   = i;

            ll lastPos = doubled[idx];

            for(int j = 2; j <= k; j++) { //O(k * log(n))
                ll target = lastPos + mid;

                auto it = lower_bound(begin(doubled) + idx + 1, begin(doubled) + i + n, target);

                if(it == begin(doubled) + i + n) break;

                idx = it - begin(doubled);
                lastPos = doubled[idx];
                count++;
            }

            if(count == k && (doubled[i] + perimeter - lastPos >= mid)) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        ll perimeter = 4LL * side;
        int n = points.size();

        vector<ll> positions(n);

        for(int i = 0; i < n; i++) {
            positions[i] = get1D(side, points[i][0], points[i][1]);
        }

        sort(begin(positions), end(positions));

        //double the positions array to easily handle round wrap
        vector<ll> doubled(2*n);
        for(int i = 0; i < n; i++) {
            doubled[i]   = positions[i];
            doubled[i+n] = positions[i] + perimeter;
        }

        int l = 0;
        int r = 2*side;

        int result = 0;

        //log(side) * n * klog(n)
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(check(doubled, n, k, side, mid)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;


    }
};
