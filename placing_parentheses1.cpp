#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <limits.h>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long maximum(long long a, long long b, long long c, long long d){
	long long a1=a>b?a:b;
	long long a2=c>d?c:d;
	return a1>a2?a1:a2;
}

long long minimum(long long a, long long b, long long c, long long d){
	long long a1=a<b?a:b;
	long long a2=c<d?c:d;
	return a1<a2?a1:a2;
}

long long get_maximum_value(char *str) {
  //write your code here
  int len=strlen(str);
  int n=(len+1)/2 , i,j,k;
  long long a,b,c,d,a1,b1;
  long long **max=(long long **)malloc(n*sizeof(long long*));
  long long **min=(long long **)malloc(n*sizeof(long long*));
  for (i=0;i<n;i++){
  	max[i]=(long long*)malloc(n*sizeof(long long));
  	min[i]=(long long*)malloc(n*sizeof(long long));
  }
  for (i=0;i<n;i++){
  	max[i][i]=str[i*2]-'0';
  	min[i][i]=str[i*2]-'0';
  }
  for (i=1; i<n;i++){
  	for (j=0; j+i<n;j++){
  		max[j][i+j]=LLONG_MIN;  //表示 long long int 最大值 
  		min[j][i+j]=LLONG_MAX;
  		for (k=j;k<i+j;k++){
  		    a = eval(max[j][k],max[k+1][i+j],str[2*k+1]);
            b = eval(max[j][k],min[k+1][i+j],str[2*k+1]);
            c = eval(min[j][k],max[k+1][i+j],str[2*k+1]);
            d = eval(min[j][k],min[k+1][i+j],str[2*k+1]);
            a1 = maximum(a,b,c,d);
            b1 = minimum(a,b,c,d);
            if(a1>max[j][i+j]) max[j][i+j] = a1;
            if(b1<min[j][i+j]) min[j][i+j] = b1;	
		  }
	  }
  }
  return max[0][n-1];
}
 
int main() {
  string s;
  std::cin >> s;
  char* c = const_cast<char *>(s.c_str());
  std::cout << get_maximum_value(c) << '\n';
}





















