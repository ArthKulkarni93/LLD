#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//this is fixed window RateLimiter
class RateLimiter {

    int per_user_time;
    int per_user_requests;

    int server_time;
    int server_requests;

    int server_can_process;
    int server_window_end;

    unordered_map<int, pair<int,int>> users;
    // user -> {requests_left, window_end}

public:

    RateLimiter(int put, int pur, int st, int sr) {

        per_user_time = put;
        per_user_requests = pur;

        server_time = st;
        server_requests = sr;

        server_can_process = 0;
        server_window_end = -1;
    }

    void serve(vector<pair<int,int>> &v) {

        for (auto &req : v) {

            int user = req.first;
            int time = req.second;

            if (time > server_window_end) {
                server_can_process = server_requests;
                server_window_end = time + server_time - 1;
            }

            if (server_can_process == 0) {

                cout << "Missed request from user "
                     << user << " at time "
                     << time
                     << " (server limit)\n";

                continue;
            }

            if (users.find(user) == users.end()) {

                users[user] = {per_user_requests, time + per_user_time - 1};
            }

            auto &entry = users[user];

            int &remaining = entry.first;
            int &window_end = entry.second;

            if (time > window_end) {

                remaining = per_user_requests;
                window_end = time + per_user_time - 1;
            }

            if (remaining == 0) {

                cout << "Missed request from user "
                     << user << " at time "
                     << time
                     << " (user limit)\n";

                continue;
            }

            remaining--;
            server_can_process--;

            cout << "Served request from user "
                 << user << " at time "
                 << time << "\n";
        }
    }
};

int main() {

    int per_user_requests, per_user_time;
    int server_requests, server_time;

    cout << "Enter per user requests and time\n";
    cin >> per_user_requests >> per_user_time;

    cout << "Enter server requests and time\n";
    cin >> server_requests >> server_time;

    RateLimiter rl(
        per_user_time,
        per_user_requests,
        server_time,
        server_requests
    );

    int n;
    cin >> n;

    vector<pair<int,int>> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    rl.serve(v);
}