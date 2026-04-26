#include <iostream>
#include <string>
using namespace std;

int tickets[1001];
int booked[1001][1001];

class MovieTicket {
public:

    int BOOK(int X, int Y) {
        if (booked[X][Y] == 1) return 0;
        if (tickets[Y] >= 100) return 0;

        booked[X][Y] = 1;
        tickets[Y]++;
        return 1;
    }

    int CANCEL(int X, int Y) {
        if (booked[X][Y] == 0) return 0;

        booked[X][Y] = 0;
        tickets[Y]--;
        return 1;
    }

    int IS_BOOKED(int X, int Y) {
        return booked[X][Y];
    }

    int AVAILABLE_TICKETS(int Y) {
        return 100 - tickets[Y];
    }
};

int main() {
    int Q;
    cin >> Q;

    MovieTicket obj;
    string query;

    while (Q--) {
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (obj.BOOK(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (obj.CANCEL(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (obj.IS_BOOKED(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << obj.AVAILABLE_TICKETS(Y) << endl;
        }
    }

    return 0;
}