#include <iostream>
#include<vector>
#include <algorithm>
#include<math.h>
using namespace std;


int main()
{
    vector<float> reward; // �迭
    vector<float> secNum; // �ֹݰ� �ߺ� �迭
    int num; // Ƚ���Է�
    double avg, sum = 0,middle,range, a; // ���, �հ�, �߰�, ����, �Է°�
    double mostNum = 0,highlestNum = 0, curNum = 0; // ���帹�� ���� �� , ������� ī��Ʈ, ī��Ʈ

    //�Է�
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> a;
        reward.push_back(a);
    }

    //����
    sort(reward.begin(), reward.end());

    //�ֺ� ã��
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
    //�ֺ� ����ó��
    if (secNum.size() >= 2)
        mostNum = secNum[1];
    else if (secNum.size() <= 0)
        mostNum = reward.size() == 1 ? reward[0] : reward[1];

    // �߾�,���,����
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