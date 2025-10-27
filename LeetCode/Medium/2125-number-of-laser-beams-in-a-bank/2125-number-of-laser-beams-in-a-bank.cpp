class Solution {
    int countLaser(string s){
        int laser = 0;
        for(char c : s){
            if(c == '1')
                laser++;
        }
        return laser;
    }
public:
    int numberOfBeams(vector<string>& bank) {
        int prevRowCount = 0;
        int total = 0;

        for (const std::string& row : bank) {
            int curRowCount = countLaser(row);
            if (curRowCount == 0)
                continue;

            total += curRowCount * prevRowCount;
            prevRowCount = curRowCount;
        }
        return total;
    }
};