#include <iostream>

using namespace std;

void toh(int n, char so, char ta, char aux) 
{
    if (n > 0) 
	{
        toh(n - 1, so, aux, ta);
        cout << "Move disk " << n << " from " << so << " to " << ta << endl;
        toh(n - 1, aux, ta, so);
    }
}

int main() {
	bool opt = true;
	while (opt == 1) {
		int nd;
    	cout << "Enter the number of disks: ";
    	cin >> nd;

    	toh(nd, 'A', 'C', 'B');
		
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
