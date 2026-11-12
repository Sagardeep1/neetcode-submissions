class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int ROWS = matrix.length, COLS = matrix[0].length;

        int l = 0, r = ROWS * COLS - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            int ind_r = mid / COLS;
            int ind_c = mid % COLS;
            if (matrix[ind_r][ind_c] == target)
                return true;
            else if (matrix[ind_r][ind_c] > target)
                r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
}
