class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string c: tokens){
            if(c == "+"){
                int ans = st.top();
                st.pop();
                ans += st.top();
                st.pop();
                st.push(ans);
            }
            else if(c == "-"){
                int ans = st.top();
                st.pop();
                ans = st.top() - ans;
                st.pop();
                st.push(ans);
            }
            else if(c == "/"){
                int ans = st.top();
                st.pop();
                ans = st.top() / ans;
                st.pop();
                st.push(ans);
            }
            else if(c == "*"){
                int ans = st.top();
                st.pop();
                ans *= st.top();
                st.pop();
                st.push(ans);
            }
            else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};