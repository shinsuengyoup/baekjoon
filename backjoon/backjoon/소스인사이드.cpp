#include<iostream>
#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else if(a.size() == b.size()){
		return a < b;
	}
}

int main() {
	vector<string> vec;
	string voca;
	int len;
	cin >> len;
	for (int i = 0; i < len; i++) {
		cin >> voca;
		if (find(vec.begin(), vec.end(), voca) == vec.end())
			vec.push_back(voca);
	}
	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}
	
	return 0;
}
