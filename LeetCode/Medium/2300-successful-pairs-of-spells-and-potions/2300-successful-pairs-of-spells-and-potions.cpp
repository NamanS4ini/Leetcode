class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end(), greater<int>());
        for(int spell: spells){
            int left = 0;
            int right = potions.size() - 1;
            int mid;
            while(left <= right){
                mid = (right + left)/2;
                long s = long(spell) * potions[mid];
                if(s >= success)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            ans.push_back(right + 1);
        }
        return ans;
    }
};