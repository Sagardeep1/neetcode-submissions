class Solution {

    private boolean bsearch_row(int[] matrix, int target) {
        int l = 0, r = matrix.length - 1, mid;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (matrix[mid] == target)
                return true;
            else if (matrix[mid] < target)
                l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int l = 0, r = m-1, mid;
        if (target < matrix[0][0] || target > matrix[m-1][n-1])
            return false;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target)
                r = mid - 1;
            else {
                if (matrix[mid][n-1] == target)
                    return true;
                else if (matrix[mid][n-1] > target)
                    return bsearch_row(matrix[mid], target);
                else l = mid + 1;
            }
        }
        return false;
    }
}
