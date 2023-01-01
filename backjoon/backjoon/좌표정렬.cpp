#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	return a[1] < b[1];
}



int main() {
	int num, a, b;
	vector<vector<int>> cod;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		cod.push_back(vector<int>());
		cod[i].push_back(a);
		cod[i].push_back(b);
	}
	sort(cod.begin(), cod.end(), compare);

	for (int i = 0; i < num; i++) {
		cout << cod[i][0] << " " << cod[i][1] << '\n';
	}
	return 0;
}