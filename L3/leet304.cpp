class NumMatrix
{
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // padding 0 into matrix first row and first col
        vector<int> zero_row(cols + 1, 0);
        matrix.insert(matrix.begin(), zero_row);
        for (int i = 1; i <= rows; i++)
        {
            matrix[i].insert(matrix[i].begin(), 0);
        }
        // build pref
        pref.resize(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= cols; j++)
            {
                pref[i][j] = pref[i][j - 1] + pref[i - 1][j] + matrix[i][j] - pref[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        row1++;
        col1++;
        row2++;
        col2++;
        return pref[row2][col2] - pref[row2][col1 - 1] - pref[row1 - 1][col2] + pref[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */