#include<iostream>
#include<queue>

using namespace std;

int main() {
    std::system("clear");
    cout << "Enter the number of process: ";
    size_t num_processes;
    cin >> num_processes;
    cout << "The identifiers for the processes are [0 - " << num_processes - 1 << "]\n";
    bool next = false;
    char choice;
    size_t num_critical;
    queue<size_t> q;
    do {
        cout << "Enter the process that wants to execute its critical section: ";
        cin >> num_critical;
        if(num_critical < 0 || num_critical >= num_processes) {
            cerr << "Invalid process identifier \n";
            return -1;
        }
        q.push(num_critical);
        cout << "Do you have another process (y/n) :";
        cin >> choice;
        next = (choice == 'y') ? true : false;
    } while(next);

    cout << "\n========================== \n";
    while(!q.empty()) {
        auto process = q.front(); q.pop();
        cout<<"----- \n";
        cout << "Critical Section is executing for process: " << process << " ....\n";
        cout << "Critical Section is finished for the process: " << process << ".\n";
        cout << "Release Message Sent by the process: " << process << ".\n";
    }
    cout<<"----- \n";
    cout << "========================== \n";
    return 0;
}
