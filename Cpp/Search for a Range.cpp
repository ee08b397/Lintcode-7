class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    int Findleft(vector<int> &A, int target) {
        int left = 0, right = A.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (A[mid] == target) {
                if (mid > 0 && A[mid-1] == target) right = mid - 1;
                else return mid;
            } else if (A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    int Findright(vector<int> &A, int target) {
        int left = 0, right = A.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (A[mid] == target) {
                if (mid < A.size() - 1 && A[mid+1] == target) left = mid + 1;
                else return mid;
            } else if (A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> vec;
        vec.push_back(Findleft(A, target));
        vec.push_back(Findright(A, target));
        return vec;
    }
};
