class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxEnergy = INT_MIN;
        for(int i = energy.size() - 1; i > energy.size() - k - 1; i--){
            maxEnergy = max(maxEnergy, energy[i]);
            int index = i;
            int curr = 0;
            while(index >= 0){
                curr += energy[index];
                index -= k;
                maxEnergy = max(maxEnergy, curr);
            }
        }
        return maxEnergy;
    }
};