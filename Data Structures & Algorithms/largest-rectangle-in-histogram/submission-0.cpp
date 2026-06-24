class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int max_area = 0;
        int width = 0;
        for(int i = 0; i < heights.size(); i++){
            if(!st.empty()){
                while(!st.empty() && heights[i] < heights[st.top()]){
                    int curpop = st.top();
                    st.pop();
                    if(!st.empty()) width = i - st.top() - 1;
                    else width = i - (-1) - 1;
                    int area = heights[curpop] * width;
                    max_area = max(max_area, area);

                }
            }
            st.push(i);
        }
        return max_area;
    }
};
