class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 1, h = x;
        while(l <= h){
            int mid =  (l + h) / 2;
            int q = x / mid;
            if(q == mid) return mid;
            else if(q > mid) l = mid + 1;
            else h = mid - 1;
        }
        return h;
    }
};