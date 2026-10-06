class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, double>> p(n);
        for(int i=0; i<n; i++) {
            double t = (target - position[i]) * 1.0 / speed[i];
            p[i] = {position[i], t};
        }
        sort(p.rbegin(), p.rend());
        int fleet = 0;
        double t = -1;
        for(auto& [pos, time] : p) {
            if (time > t) {
                fleet++;
                t = time;
            }
        }
        return fleet;
    }
};
