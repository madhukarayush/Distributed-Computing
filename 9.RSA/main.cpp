#include "rsa.h"
#include <iostream>

using namespace std;

int main(void) {
	Rsa rsa;
	Key key = rsa.produce_keys();
	cout << "The Generated keys are："<< endl;
	cout << "p：" << key.pkey << endl;
	cout << "e：" << key.ekey << endl;
	cout << "d：" << key.dkey << endl;
	long msg;
	cout << "Enter the message to be encrypted (integer values): " << endl;
	cin >> msg;
	long msg_des = rsa.endecrypt(msg, key.ekey, key.pkey);
	cout << "Encrypted message: " << msg_des << endl;
	msg_des = rsa.endecrypt(msg_des, key.dkey, key.pkey);
	cout << "Decrypted message: "<< msg_des << endl;
	return 0;
}

