#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, char> ci; //typedef로 해당 형식의 pair을 ci로 지칭한다.

/*
    - 배열을 ?로 초기화 해주고, 입력대로 처리한다
    - 문제의 경우, 화살표를 고정시키고 바퀴를 돌리는데,
    - 풀 때에는 바퀴를 고정시키고, 화살표를 이동시키는 방식으로 풀었다. (출력시 방향을 바꿔야함)
    <주의 사항>
    1. ?이 아닌 문자가 저장되어있는데, 다른 문자를 저장하려는 경우
    2. 룰렛에 중복되는 문자가 있는 경우
*/

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int index, int n, vector<char>& wheel) {
    string ans = "";

    for (int i = n; i > 0; i--) { //화살표를 이동했으므로 거꾸로 출력
        ans += wheel[(i + index) % n];
    }

    return ans;
}

string makeWheel(int n, vector<ci>& record) {
    vector<char> wheel(n, '?');           //?로 초기화
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int index = 0; //화살표가 가리키는 인덱스

    for (int i = 0; i < record.size(); i++) { //기록 수만큼 반복
        int rot = record[i].first; //rot = 회전 수 저장
        int ch = record[i].second; //ch = 현재 가리키는 문자 저장

        index = (index + rot) % n; //화살표 이동

        //이동된 화살표가 가리키는 곳의 숫자가 현재 문자와 동일할 경우 현재 상태 유지(?라면 ?대로, 알아낸 문자가 있다면 알아낸 문자가 있는대로.)
        if (wheel[index] == ch) {
            continue;
        }

        // 주의사항 체크
        // 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            return "!";
        }

        wheel[index] = ch; //현재 알파벳을 현재 위치에 저장
        is_available[ch - 'A'] = true; // 2번 조건을 체크하기 위함 : 과거 사용된 알파벳 체크
    }

    return arrowStartWheel(index, n, wheel); //행운의 바퀴가 있으므로 출력
}

int main() {
    //입력
    int n, k; //바퀴의 칸 수, 돌리는 횟수 저장
    cin >> n >> k;

    vector<ci> record(k, { 0, 0 }); //바퀴 회전 기록
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second; //pair의 첫번째 인자와 두번째 인자를 돌리는 횟수만큼 입력
    }

    //출력
    cout << makeWheel(n, record);
}