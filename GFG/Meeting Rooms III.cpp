class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i)
            freeRooms.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;

        vector<int> roomCount(n, 0);

        for (auto& meet : meetings) {
            int start = meet[0], end = meet[1];

            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                roomCount[room]++;
                busyRooms.push({end, room});
            } else {
                pair<long long, int> top = busyRooms.top();
                busyRooms.pop();
                long long endTime = top.first;
                int room = top.second;
                roomCount[room]++;
                long long newEnd = endTime + (end - start);
                busyRooms.push({newEnd, room});
            }
        }

        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomCount[i] > maxMeetings) {
                maxMeetings = roomCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
