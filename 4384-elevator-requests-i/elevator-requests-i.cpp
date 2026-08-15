class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int t = 0, currpos = 0;
        for (int i = 0; i < requests.size(); i++) {
            t = t + abs(currpos - requests[i]);
            currpos = requests[i];
        }
        return t;
    }
};