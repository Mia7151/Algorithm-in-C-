#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  
  int n=str1.size();
  int m=str2.size();
  int E[n+1][m+1];
  if (n*m==0) return n+m;
  
  for (int i=0; i<=n;i++){
  	E[i][0]=i;
  	}
  for (int j=0; j<=m;j++){
  	E[0][j]=j;
  } 
  for (int i=1; i<=n; i++){
  	for (int j=1; j<=m; j++){
  		int cost=str1[i-1]==str2[j-1]?0:1;
		E[i][j]=min(min(E[i-1][j]+1,E[i][j-1]+1),E[i-1][j-1]+cost);
	  }
  }
  return E[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
