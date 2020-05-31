#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
  int sum=0;
  for (int i=0; i<A.size();++i){
  	sum +=A[i];
  } 
  if (sum%3!=0) return 0;
  //int subsum=sum/3;
  int n=A.size();
  bool dp[sum+1][n+1];
  for (int i=0;i<=n; ++i){
  	dp[0][i]=true;
  }
  for (int j=1;j<=sum; ++j ){
  	dp[j][0]=false;
  }
  for (int i=1; i<=sum; ++i){
  	for (int j=1; j<=n; ++j){
  		dp[i][j]=dp[i][j-1];
  		if (i>=A[j-1]){
  			dp[i][j]=dp[i][j]||dp[i-A[j-1]][j-1];
		  }
	  }
}
  return dp[sum/3][n]&&dp[sum/3*2][n];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
