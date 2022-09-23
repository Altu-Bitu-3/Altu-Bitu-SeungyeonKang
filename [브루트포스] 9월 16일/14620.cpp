#include <iostream>
#include <vector>

using namespace std;
const int MAX = 3000;


vector<vector<int>> board; //ȭ���� ������ ������ ���� 2���� ����
vector<vector<bool>> check; //ȭ���� ���� �ɾ��� ���θ� �ľ��ϴ� 2���� ����
int dr[5] = { 0, -1, 1, 0, 0 };//�߾�, �����¿� ������ ���� x��ǥ
int dc[5] = { 0, 0, 0, -1, 1 };//�߾�, �����¿� ������ ���� y��ǥ
int ans = MAX; //���� �ɾ��� ������ ���� ��ģ ����
//int k = 0;

//�ش� ������ �����¿��߾� ������ ���� �ִ��� üũ�ϰ� ���ٸ� ��� ������ ������ ���� ���� ���� �����ϴ� �Լ�
int chkFlower(int r, int c) {

    int sum = 0;
    for (int i = 0; i < 5; i++) { //�����¿��߾� ��� ������ ���Ͽ�
        int nr = r + dr[i]; //������ x��ǥ(dr�迭�� ���� �����¿��߾��� ����)
        int nc = c + dc[i]; //������ y��ǥ(dc�迭�� ���� �����¿��߾��� ����)
        if (check[nr][nc]) { // �̹� �� �ִٸ�
            return -1;
        }
        sum += board[nr][nc]; //�����¿��߾� ������ ������ ��ģ ��
    }
    return sum; //����
}
void plant(int r, int c, bool marking_type) { //�����¿�� �� �ɰų� ��������.

    //�����¿��߾� ���� marking_type�� ���� true, false ��ġ
    for (int i = 0; i < 5; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        check[nr][nc] = marking_type;
    }

}

// ����Լ��� ���� ���� �ɾ�� ��� ����� ���� Ȯ���ϴ� �Լ�
void minFlower(int cnt, int sum) {
    //cnt = ���� ���� ����, sum = ���� ������ ��

    if (cnt == 3) { //���� ���� ������ 3����
        ans = min(ans, sum);//���� ���� ������ ���� ���� ���Ͽ� �� ���� ���� ans�� �ֱ�
        //cout << ans << "�� ���� min ���Դϴ�. " << '\n';
        return;
    }
    for (int i = 1; i < board.size() - 1; i++) {
        for (int j = 1; j < board.size() - 1; j++) {
            int sumFlower = chkFlower(i, j); //�ɾ����ִ��� üũ �� sum �� ��ȯ
            if (sumFlower == -1) {//���� �ɾ��� ���� �� �ϴ� �ڵ� ���� ����
                //cout << "�Ⱒ" << '\n';
                continue;
            }
            plant(i, j, 1); //���� �ɾ������� �ʾҴٸ� �� �ɱ�
            //cout << i << ", " << j << "�� �����¿�� ���� �ɾ����ϴ�. (���� cnt �� : " << cnt << '\n';
            //k++;
            //cout << "minFlower �ȿ� �����ϴ�. ����  : " << k << '\n';
            minFlower(cnt + 1, sum + sumFlower);//(���� ���� ���� + 1, ���� ���� �����¿� ������ ���� ���� ��)���� �ٽ� minFlower �Լ� ����
            //k--;
            //cout << "minFlower �ȿ��� ���Խ��ϴ�. ����  : " << k << '\n';
            //cout << i << ", " << j << "�� �����¿�� ���� �̾ҽ��ϴ�. (���� cnt �� : " << cnt<< '\n';
            plant(i, j, 0); //�ɾ��� ���� �̱�(false�� �����)
        }
    }
}

int main() {

    int n; //2���� �迭(���簢��)�� �� ��

    // �Է�
    cin >> n;

    board.assign(n, vector<int>(n, 0)); //������ ���� �ʱ�ȭ
    check.assign(n, vector<bool>(n, false)); //���� �ɾ����Ŀ� ���� ��� ���� False�� �ʱ�ȭ

    //for�� board�� �� ������ ������ �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // ���� & ���
    minFlower(0, 0);

    //���
    cout << ans;
    return 0;
}