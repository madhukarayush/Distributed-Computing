#include<iostream>
#include<random>
#include<cmath>

using namespace std;

long mod_pow(long base, long power, long mod) {
    return (long) pow(base, power) % mod;
}

pair<long, long> get_random() {
    random_device rd;
    default_random_engine eg(rd());
    uniform_int_distribution<long> dist(1, 15);
    return make_pair(dist(eg), dist(eg));
}

pair<long, long> compute_remainder(long base, long prime, pair<long, long> priv_keys) {
    return make_pair(
            mod_pow(base, priv_keys.first, prime),
            mod_pow(base, priv_keys.second, prime)
            );
}

pair<long, long> generate_keys(pair<long, long> remainders, pair<long, long> priv_keys, long prime) {
    return make_pair (
            mod_pow(remainders.second , priv_keys.first, prime),
            mod_pow(remainders.first, priv_keys.second, prime)
            );
}


int main() {
    long base, prime;
    cout << "Enter the base value (chosen by both parties): ";
    cin >> base;
    cout << "Enter a prime number (chosen by both parties): ";
    cin >> prime;
    auto private_keys = get_random();

    auto computed_remainder = compute_remainder(base, prime, private_keys);
    cout << "Computed values to be exchanged between the users : \n";
    cout << "\t User 1: " << computed_remainder.first << "\n";
    cout << "\t User 2: " << computed_remainder.second << "\n";

    auto secret_keys = generate_keys(computed_remainder, private_keys, prime);
    cout << "Secret keys generated (should be same): \n";
    cout << "\t User 1: " << secret_keys.first << "\n";
    cout << "\t User 2: " << secret_keys.second << "\n";
    return 0;
}
