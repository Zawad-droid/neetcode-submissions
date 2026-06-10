class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0;
        int r = 0;
        int length = 0;
        while(r < s.size()){
            if(!st.count(s[r])){
                st.insert(s[r]);
                int size = r - l + 1;
                length = max(length, size);
                r++;
            }
            else{
                while(st.count(s[r])){
                    st.erase(s[l]);
                    l++;
                }
            }
        }
        return length;
    }
};
