//Company Tags  : Google
//Leetcode Link : https://leetcode.com/problems/my-calendar-i/

//Approach-1 : Brute Force 
//T.C : O(n^2)
//S.C : O(n)
typedef pair<int, int> P;
class MyCalendar {
public:
    
    vector<P> calendar;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        for(int i = 0; i<calendar.size(); i++) {
            P curr = calendar[i];
            if(!(end <= curr.first || start >= curr.second))
                return false;
        }
        
        calendar.push_back({start, end});
        return true;
    }
};


//Approach - 2 (set : lower_bound) : O(nlog(n))
//T.C : O(nlogn)
//S.C : O(n)
class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //Find the first event that starts after or st the same time of {start, end}
        auto it = st.lower_bound({start, end}); //Log(N)

        //Check if the current event overlaps with the next event
        if(it != st.end() && it->first < end) {
            return false;
        }

        //Check if the current event overlaps with the previous event
        if(it != st.begin()) {
            auto prevIt = prev(it);
            if(start < prevIt->second) {
                return false;
            }
        }

        st.insert({start, end});
        return true;
    }
};


//Approach-3 (Set : Upper bound)
//T.C : O(nlogn)
//S.C : O(n)
class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = st.upper_bound({start, end});

        if(it != st.end() && end > it->second) {

            return false;
            
        }
        
        st.insert({end, start});
        return true;
    }
};
