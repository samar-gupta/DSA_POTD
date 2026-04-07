class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        // code here
        int n = men.size();

        vector<int>womanPartner(n,-1);
        vector<int>manPartner(n,-1);
        vector<int>nextProposal(n,0);

        vector<vector<int>>ranks(n,vector<int>(n,-1));

        for (int w = 0; w < n; w++) {
            for (int rank = 0; rank < n; rank++) {
                ranks[w][women[w][rank]] = rank;
            }
        }

        queue<int> freeMen;
        for (int i = 0; i < n; i++) {
            freeMen.push(i);
        }

        while (!freeMen.empty()) {
            int man = freeMen.front();
            freeMen.pop();

            int woman = men[man][nextProposal[man]];
            nextProposal[man]++;

            if (womanPartner[woman] == -1) {
                womanPartner[woman] = man;
                manPartner[man] = woman;
            } else {
                int currentMan = womanPartner[woman];

                if (ranks[woman][man] < ranks[woman][currentMan]) {
                    womanPartner[woman] = man;
                    manPartner[man] = woman;

                    freeMen.push(currentMan);
                    manPartner[currentMan] = -1;
                } else {
                    freeMen.push(man);
                }
            }
        }

        return manPartner;
    }
};
