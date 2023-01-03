#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N,number;
	cin >> N;
	vector<int> originVec, copyVec, compareVec;
	for (int i = 0; i < N; i++) {
		cin >> number;
		originVec.push_back(number);
	}
	copyVec = originVec;

	// Á¤·Ä
	sort(copyVec.begin(), copyVec.end());
	
	int myself = copyVec[0];
	compareVec.push_back(myself);

	for (int i = 0; i < N; i++) {
		if (copyVec[i] != myself) {
			compareVec.push_back(copyVec[i]);
			myself = copyVec[i];
		}
	}

	for (int i : compareVec) {
		cout << i << " ";
	}
	cout << endl;
	
	for (int i = 0; i < N; i++) {
		cout << lower_bound(compareVec.begin(), compareVec.end(), originVec[i]) - compareVec.begin() << ' ';
	}

	return 0;
}