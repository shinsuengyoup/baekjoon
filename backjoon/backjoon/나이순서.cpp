#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool compare(pair<int,string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	int num, age;
	string name;
	vector<pair<int, string>> vec;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> age;
		cin >> name;
		info human = { name,age };
		vec.push_back(human);
	}
	

	stable_sort(vec.begin(), vec.end(), compare);
	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].age << " "<< vec[i].name << '\n';
	}

}