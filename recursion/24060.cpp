#include <iostream>
#include <vector>
using namespace std;
void divide(int left, int right);
void merges(int left, int right);

vector<int> arr;
vector<int> result;
int resultInt;

int printResult = -1, cnt = 0;
int K = 0;

int main(void) {
	arr.clear();
	result.clear();

	//N���� ���� �ٸ� ���� ������ ����� �迭 A.
	//���� ���ķ� �迭 A �������� ���� -> A[K]���ϱ�

	//K�� ���� Ƚ��
	int N;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	result = arr;

	divide(0, arr.size() - 1);

	cout << printResult;
}

void divide(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		divide(left, mid);
		divide(mid + 1, right);
		merges(left, right);
	}
}

void merges(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	//[i, i+1, i+2..., j, j+1, j+2,...]
	while (i <= mid && j <= right) {
		if (arr[i] > arr[j])
			result[k++] = arr[j++];
		else
			result[k++] = arr[i++];
	}

	if (i > mid) {
		while (j <= right) {
			result[k++] = arr[j++];
		}
	}
	else {
		while (i <= mid) {
			result[k++] = arr[i++];
		}
	}

	for (int a = left; a <= right; a++) {
		cnt += 1;
		arr[a] = result[a];
		if (cnt == K)
			printResult = arr[a];
	}

	/*cout << "\n" << cnt << "��° : ";

	for (int b = 0; b < arr.size(); b++) {
		cout << arr[b] << " ";
	}*/
}