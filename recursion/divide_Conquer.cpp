#include <iostream>
#include <vector>
using namespace std;
//#define N 10000 //원하는 원소의 갯수

void divide(int, int);
void merges(int, int);

//int result[N];
vector<int> result;
vector<int> arr;

int main() {
	result.clear();
	arr.clear();

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	divide(0, arr.size() - 1);

	system("PAUSE");
	return 0;
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

	for (int a = left; a <= right; a++)
		arr[a] = result[a];
}