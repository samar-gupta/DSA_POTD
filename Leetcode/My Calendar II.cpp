//Company Tags  : Google
//Leetcode Link : https://leetcode.com/problems/my-calendar-ii

//Approach-1 : Simle and straight forward
//T.C : O(n)
//S.C : O(n)
class MyCalendarTwo {
public:
    vector<pair<int, int>> doubleOverlappedRegion;
    vector<pair<int, int>> overallBookings;

    bool checkOverlap(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> findOverlappedRegion(int start1, int end1, int start2, int end2) {
        return {max(start1, start2), min(end1, end2)};
    }

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        //check if tripple booking is being created or not
        for(pair<int, int> region : doubleOverlappedRegion) {
            if(checkOverlap(region.first, region.second, start, end)) {
                return false; //tripple booking created
            }
        }

        //check if it is creating double bookings
        for(pair<int, int> booking : overallBookings) {
            if(checkOverlap(booking.first, booking.second, start, end)) {
                doubleOverlappedRegion.push_back(findOverlappedRegion(booking.first, booking.second, start, end));
            }
        }

        overallBookings.push_back({start, end});
        return true;
    }
};
