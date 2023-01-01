#include <iostream>
#include<vector>
#include <algorithm>
#include<math.h>
using namespace std;


int main()
{
    vector<float> reward; // 배열
    vector<float> secNum; // 최반값 중복 배열
    int num; // 횟수입력
    double avg, sum = 0,middle,range, a; // 평균, 합계, 중간, 범위, 입력값
    double mostNum = 0,highlestNum = 0, curNum = 0; // 가장많이 나온 수 , 가장높은 카운트, 카운트

    //입력
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> a;
        reward.push_back(a);
    }

    //정렬
    sort(reward.begin(), reward.end());

    //최빈값 찾기
    mostNum = 0;
    for (int i = 0; i < reward.size()-1; i++) {
        sum += reward[i];
        if (reward[i] == reward[i + 1]) {
            curNum++;
            if (highlestNum < curNum) {
                highlestNum = curNum;
                curNum = 0;
                mostNum = reward[i];
            }
        }
        else 
            curNum = 0;
    }

    curNum = 0;
    sum += reward[reward.size()-1];

    for (int i = 0; i < reward.size() - 1; i++) {
        if (reward[i] == reward[i + 1]) {
            curNum++;
            if (highlestNum == curNum) {
                curNum = 0;
                secNum.push_back(reward[i]);
            }
        }
        else
            curNum = 0;
    }
    //최빈값 예외처리
    if (secNum.size() >= 2)
        mostNum = secNum[1];
    else if (secNum.size() <= 0)
        mostNum = reward.size() == 1 ? reward[0] : reward[1];

    // 중앙,평균,범위
    middle = reward[reward.size() / 2];
    avg = round(sum / reward.size());
    range = abs(reward[0] - reward[reward.size()-1]);
    if (avg == 0)
        avg = 0;

    cout << avg << endl;
    cout  << middle << endl;
    cout << mostNum << endl;
    cout << range << endl;
    return 0;
}