class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i;
        int l = 0, r = A.size() - 1;
        
        while(l <= r) {
            i = (l + r)/2;
            if(A[i-1] < A[i] && A[i] > A[i+1]) return i; // Peak reached
            
            if(A[i] < A[i+1]) l = i + 1;        // Continue search based on given format
            else r = i - 1;
        }
        return -1;
    }
};