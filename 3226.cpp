#include<iostream>
#include<string>
using namespace std;

/*
통화가 끝나는 시각을 계산하여 중간에 요금이 바뀌는지 안바뀌는지 체크한 후에 각 case에 맞게 계산
*/
int calculateCharge(int h, int m, int time) {
	int end_h = h;
	int end_m = (m + time) % 60; //60의 나머지를 반환해 60을 넘는 경우가 없도록 한다.

	//끝나는 시간 계산
	end_h += ((m + time) / 60) % 24; //60으로 나눴을 때의 몫을 더하지만 24시가 넘지 않도록 한다.

	//요금이 중간에 바뀌는 경우(통화시간이 최대 60분이므로 시간도 최대 1만큼만 바뀔 수 있어서 아래와 같이 조건을 작성했습니다!)
	if (h == 6 && end_h == 7) { //6시 M분에 시작했는데 7시 M분에 끝난 경우 전화요금이 바뀌어
		return (time - end_m) * 5 + end_m * 10; //7시 이전과 이후를 분리한다.
	}
	if (h == 18 && end_h == 19) { //오후 6시 M분에 시작했는데 7시 M분으로 끝난 경우 전화요금이 바뀌어
		return (time - end_m) * 10 + end_m * 5; //그 이전과 이후를 분리해 저장한다.
	}
	//바뀌지 않는 경우
	if (6 < h && h < 19) {
		return 10 * time;
	}
	return 5 * time; //위의 모두 해당하지 않는 경우는 19시 이후 7시 전까지이므로 그 경우에 분 당 5원으로 더해 반환

}


int main() {
	int n, m, time;
	int charge = 0;
	string h;
	cin >> n;
	while (n--) { //전화의 수만큼 반복
		/*getline(입력 스트림, string 객체, 구분자);
		보통 구분자를 지정하지 않고 사용하지만, 필요한 경우 지정한 구분자를 만날 때까지 문자열을 입력받아 string 객체에 저장할 수 있어요!
		*/
		getline(cin, h, ':'); // :을 만날 때까지의 숫자를 입력받기
		cin >> m >> time; //이후의 숫자를 m에 담고, 전화한 시간을 time에 담는다.
		charge += calculateCharge(stoi(h), m, time); //string으로 받은 h를 int로 바꿔 전달 + charge에 sum
	}
	cout << charge;
}