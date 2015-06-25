/*
 * dp[i][j]=i-1番目までの品物から重さの総和がj以下となるように選んだ時の、価値総和の最大値 O(nW)
 */

int dp[N+1][W];

int solve(){
	fill(dp[0], dp[0]+W, 0);
	for(int i = 1; i <= N; ++i){
		for(int j = 0; j <= W; ++j){
			int pre = (i-1)&1, cur = i&1;
			if( j < w[i-1] ) dp[cur][j] = dp[pre][j];
			else dp[cur][j] = max(dp[pre][j], dp[cur][j-w[i-1]] + v[i-1] );
		}
	}
	return dp[n&1][W];
}
