#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    int balance[1001];

public:
    Bank() {
        for (int i = 0; i < 1001; i++) {
            balance[i] = -1;   // user not present
        }
    }

    int CREATE(int X, int Y) {
        if (balance[X] == -1) {
            balance[X] = Y;
            return 1;   // true
        }
        else {
            balance[X] = balance[X] + Y;
            return 0;   // false
        }
    }

    int DEBIT(int X, int Y) {
        if (balance[X] == -1 || balance[X] < Y) {
            return 0;   // false
        }
        else {
            balance[X] = balance[X] - Y;
            return 1;   // true
        }
    }

    int CREDIT(int X, int Y) {
        if (balance[X] == -1) {
            return 0;   // false
        }
        else {
            balance[X] = balance[X] + Y;
            return 1;   // true
        }
    }

    int BALANCE(int X) {
        return balance[X];
    }
};

int main() {
    int Q;
    cin >> Q;

    Bank obj;
    string query;

    while (Q--) {
        cin >> query;

        if (query == "CREATE") {
            int X, Y;
            cin >> X >> Y;

            if (obj.CREATE(X, Y) == 1)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (query == "DEBIT") {
            int X, Y;
            cin >> X >> Y;

            if (obj.DEBIT(X, Y) == 1)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (query == "CREDIT") {
            int X, Y;
            cin >> X >> Y;

            if (obj.CREDIT(X, Y) == 1)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (query == "BALANCE") {
            int X;
            cin >> X;

            cout << obj.BALANCE(X) << endl;
        }
    }

    return 0;
}