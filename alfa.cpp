#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the height of 'A': ";
    cin >> n;

    // Upper part of 'A'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    // Lower part of 'A'
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << " ";
        }
        cout << "*" << endl;
    }

    return 0;
}
