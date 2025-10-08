class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end(), greater<int>());
        for(int spell: spells){
            int left = 0;
            int right = potions.size() - 1;
            while(left <= right){
                int mid = (right + left)/2;
                if(long(spell) * potions[mid] >= success)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            ans.push_back(right + 1);
        }
        return ans;
    }
};