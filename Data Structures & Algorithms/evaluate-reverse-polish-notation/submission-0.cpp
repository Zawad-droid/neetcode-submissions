class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> op = {"+", "-", "*", "/"};
        for(int i = 0; i < tokens.size(); i++){
            if(op.count(tokens[i])){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res;
                if(tokens[i] == "+"){
                    res = a + b;
                    st.push(res);
                }
                else if(tokens[i] == "-"){
                    res = b - a;
                    st.push(res);
                }
                else if(tokens[i] == "*"){
                    res = a * b;
                    st.push(res);
                }
                else if(tokens[i] == "/"){
                    res = b / a;
                    st.push(res);
                }
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
