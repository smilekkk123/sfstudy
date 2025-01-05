vector<vector<int>> generateMatrix(int n)
{
    int cur = 1;
    int sum = n / 2; // 总圈数
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < sum; i++)
    {
        for (int t = i; t < n - i - 1; t++) {
            res[i][t] = cur++;
        }
        for (int r = i; r < n - i - 1; r++) {
            res[r][n - i - 1] = cur++;
        }
        for (int b = n - i - 1; b > i; b--) {
            res[n - i - 1][b] = cur++;
        }
        for (int l = n - i - 1; l > i; l--) {
            res[l][i] = cur++;
        }
    }
    if (n % 2 == 1) {
        res[sum][sum] = cur;
    }
    return res;
}