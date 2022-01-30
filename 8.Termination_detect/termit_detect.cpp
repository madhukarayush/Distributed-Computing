#include<iostream>
#include<random>

using namespace std;

int main() {
    system("clear");
    size_t processes, controlling, total_weight;
    cout << "Enter the number of processes: ";
    cin >> processes; 
    cout << "Assign a controlling agent: ";
    cin >> controlling;
    cout << "Enter the total weight: ";
    cin >> total_weight;

    random_device rd;
    default_random_engine e(rd());
    uniform_int_distribution<> random(0, total_weight);

    vector<size_t> weight(processes);
    size_t current_max = total_weight;
    
    for(size_t i = 0; i < processes; i++) {
        weight[i] = random(e) % current_max;
        current_max -= weight[i];
    }
    weight[processes-1] += current_max;
    cout << "\nControlling Agent: " << controlling <<" , " << weight[controlling - 1] << "\n";
    cout << "Sending Computational Message to...\n";
    for(size_t j = 0; j < processes; j++) {
        if(j != (controlling - 1)) {
            cout <<"------------------------\n";
            cout << "Process : " << j + 1 <<" , "<< weight[j] << "\n";
            cout << "Terminated Successfully \n";
        }
    }
    cout <<"-------------------------\n";
    return 0;
}
