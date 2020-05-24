#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int get_change(int m) {
  //write your code here
  if (m < 1) return 0;
  vector<int> deno{1,3,4};
  vector<int> dp(m+1,m+1);
  dp[0]=0;
  for (int i=0; i<=m; ++i){
  	for (int j=0; j<3; ++j) 
  	{
  		dp[i] = min (dp[i],dp[i-deno[j]]+1);
	  }
  }
   
  return (dp[m]>m)?-1 :dp[m];  //如果dp[m]>m的话就return-1，否则return dp[m] 
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

	
