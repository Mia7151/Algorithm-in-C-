#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using std::vector;
using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int n=a.size();
  int m=b.size();
  if (n*m==0) return n+m;
  
  int dp[n+1][m+1];
  memset(dp,0,sizeof(dp));   //把dp中的元素都设置成0 
  for (int i=0; i<n; ++i){
  	for (int j=0; j<m; ++j){
  		if (a[i]==b[j]){
  			dp[i+1][j+1]=dp[i][j]+1;
		}
		else{
			dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		}
	  }
  }
  return  dp[n][m]; 
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
//[Error] 'memset' was not declared in this scope
