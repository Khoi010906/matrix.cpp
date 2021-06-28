#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){

	string str;
	int k,n,temp,max;
	int digits[4002], sum[36001], A[4001];

	cout<<"Enter a sum and a string with multiple digits from 1 to 9"<<endl;
	cin>>k;
	cin>>str;

	for(int i = 1; i<=str.length()+1; i++){
		digits[i] = str[i-1] - 48;
		sum[digits[i]] = sum[digits[i]] + 1;
		A[i] = A[i-1] + digits[i];
	}

	max = 0;
	for(int i = 1; i<=str.length(); i++){
		for( int j = i+1; j<=str.length(); j++){
			temp = A[j] - A[i-1];
			if (temp <= k){
			sum[temp] = sum[temp] + 1;
			}; 
		}

	}
	int s = 0;
	for(int i = 1; i<= str.length(); i++){
		temp = k % digits[i];
		if (temp == 0){
			s = s + (sum[digits[i]] * sum[k / digits[i]] * 2);
			sum[digits[i]] = 0;
		};

	}

	cout<<s<<endl;
	return 0;
};
