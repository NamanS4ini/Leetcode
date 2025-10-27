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
        int totalLaser = 0;
        for(int i = 0; i < bank.size() - 1; i++){
            int laserRi = countLaser(bank[i]);
            if(!laserRi)
                continue;
            int j = i+1;
            while(j < bank.size() && !countLaser(bank[j])){
                j++;
            }
            if(j < bank.size()){
                int laserRj = countLaser(bank[j]);
                totalLaser += laserRi * laserRj;
            }
        }
        return totalLaser;
    }
};