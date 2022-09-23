#include <iostream>
#include <vector>

using namespace std;
const int MAX = 3000;


vector<vector<int>> board; //화단의 지점당 가격을 담은 2차원 벡터
vector<vector<bool>> check; //화단의 꽃이 심어진 여부를 파악하는 2차원 벡터
int dr[5] = { 0, -1, 1, 0, 0 };//중앙, 상하좌우 지점에 대한 x좌표
int dc[5] = { 0, 0, 0, -1, 1 };//중앙, 상하좌우 지점에 대한 y좌표
int ans = MAX; //꽃이 심어진 지점을 전부 합친 가격
//int k = 0;

//해당 지점의 상하좌우중앙 지점에 꽃이 있는지 체크하고 없다면 모든 지점의 가격을 더해 더한 값을 리턴하는 함수
int chkFlower(int r, int c) {

    int sum = 0;
    for (int i = 0; i < 5; i++) { //상하좌우중앙 모든 지점에 대하여
        int nr = r + dr[i]; //지점의 x좌표(dr배열에 따라 상하좌우중앙이 갈림)
        int nc = c + dc[i]; //지점의 y좌표(dc배열에 따라 상하좌우중앙이 갈림)
        if (check[nr][nc]) { // 이미 꽃 있다면
            return -1;
        }
        sum += board[nr][nc]; //상하좌우중앙 지점당 가격을 합친 것
    }
    return sum; //리턴
}
void plant(int r, int c, bool marking_type) { //상하좌우로 꽃 심거나 돌려놓기.

    //상하좌우중앙 들어온 marking_type에 따라 true, false 배치
    for (int i = 0; i < 5; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        check[nr][nc] = marking_type;
    }

}

// 재귀함수를 통해 꽃을 심어보는 모든 경우의 수를 확인하는 함수
void minFlower(int cnt, int sum) {
    //cnt = 심은 꽃의 개수, sum = 지점 가격의 합

    if (cnt == 3) { //심은 꽃의 개수가 3개면
        ans = min(ans, sum);//더한 값을 기존의 더한 값과 비교하여 더 작은 것을 ans에 넣기
        //cout << ans << "가 현재 min 값입니다. " << '\n';
        return;
    }
    for (int i = 1; i < board.size() - 1; i++) {
        for (int j = 1; j < board.size() - 1; j++) {
            int sumFlower = chkFlower(i, j); //심어져있는지 체크 및 sum 값 반환
            if (sumFlower == -1) {//꽃이 심어져 있을 시 하단 코드 전부 무시
                //cout << "기각" << '\n';
                continue;
            }
            plant(i, j, 1); //꽃이 심어져있지 않았다면 꽃 심기
            //cout << i << ", " << j << "에 상하좌우로 꽃을 심었습니다. (현재 cnt 값 : " << cnt << '\n';
            //k++;
            //cout << "minFlower 안에 들어갔습니다. 현재  : " << k << '\n';
            minFlower(cnt + 1, sum + sumFlower);//(심은 꽃의 개수 + 1, 심은 곳의 상하좌우 지점의 합을 더한 값)으로 다시 minFlower 함수 실행
            //k--;
            //cout << "minFlower 안에서 나왔습니다. 현재  : " << k << '\n';
            //cout << i << ", " << j << "에 상하좌우로 꽃을 뽑았습니다. (현재 cnt 값 : " << cnt<< '\n';
            plant(i, j, 0); //심었던 꽃을 뽑기(false로 만들기)
        }
    }
}

int main() {

    int n; //2차원 배열(정사각형)의 한 변

    // 입력
    cin >> n;

    board.assign(n, vector<int>(n, 0)); //지점당 가격 초기화
    check.assign(n, vector<bool>(n, false)); //꽃이 심어졌냐에 대해 모든 지점 False로 초기화

    //for로 board의 각 지점당 가격을 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 연산 & 출력
    minFlower(0, 0);

    //출력
    cout << ans;
    return 0;
}