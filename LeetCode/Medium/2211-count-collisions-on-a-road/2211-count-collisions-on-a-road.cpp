class Solution {
public:
    int countCollisions(string directions) {
        int collisions = 0;
        stack<char> s;
        for(char c: directions){
            if(s.empty()){
                s.push(c);
            }
            else if((c == 'L' && s.top() == 'L') || (c == 'R' && s.top() == 'R') || (c == 'R' && s.top() == 'S') || (c == 'R' && s.top() == 'L')){
                s.push(c);
            }
            else{
                if(c == 'S'){
                    while(s.size() && s.top() == 'R'){
                        collisions++;
                        s.pop();
                    }
                    s.push('S');
                }
                if(s.size() && s.top() == 'R' && c == 'L'){
                    s.pop();
                    s.push('S');
                    collisions += 2;
                }
                else if(s.size() && s.top() == 'S' && c == 'L'){
                    collisions++;
                }
                if(s.size() && s.top() == 'S'){
                    s.pop();
                    while(s.size() && s.top() == 'R'){
                        collisions++;
                        s.pop();
                    }
                    s.push('S');
                }
                
            }
        }
        while(s.size()){
            cout << s.top() << " ";
            s.pop();
        }
        return collisions++;
    }
};