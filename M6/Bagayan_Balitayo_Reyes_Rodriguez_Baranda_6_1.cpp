#include <iostream>

using namespace std;
void findFrequency(int arr[], int n, int i);

int main() {
	int n;
	bool opt = true;
	while(opt == 1) {
		cout << "Enter the size of the array: ";
		cin >> n;
	
		int arr[n];
		cout << "Enter the elements of the array (sorted): ";
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << "\nFrequency of each element:" << endl;
		findFrequency(arr, n, 0);
		
		cout << "\n------------------" << endl;
		cout << "Try another input?" << endl;
		cout << "     Yes [1]" << endl;
		cout << "     No  [0]" << endl;
		cout << "\nChoose: ";
		cin >> opt;
		system("CLS");	
	}
	return 0;
}

void findFrequency(int arr[], int n, int i) {
	if (i == n) {
		return;
	}
	int count = 1;
	while (i < n - 1 && arr[i] == arr[i + 1]) {
		count++;
		i++;
	}
	cout << arr[i] << " appears " << count << " time(s)" << endl;
	findFrequency(arr, n, i + 1);
}
