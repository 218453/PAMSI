#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "ArrayRunner.hh"
#include "TimeCounter.hh"
#include "ListTest.hh"
#include "HashTable.hh"
using namespace std;

int main()
{
	int size;
	int laps = 10;
	long * times = new long[laps];;
	long averageTime = 0;
	
	
	HashTable *hashTable = new HashTable(5);
	/*for(int i = 0; i < 5; i++)
	{
		ostringstream ss;
		ss << i;
		string str = ss.str();
		string napis = "napis" + str;
		hashTable->Put(napis, i);
	}
	
	for(int i = 0; i < 5; i++)
	{
		ostringstream ss;
		ss << 4-i;
		string str = ss.str();
		string napis = "napis" + str;
		cout << "Element " << i  << ":  " << hashTable->Get(napis) << endl;
	}*/
	
	cout << endl << endl <<"PUT" << endl << endl;
	hashTable->Put("Kowalski", 123456);
	hashTable->Put("Kowalska", 111222);
	hashTable->Put("Kobyla", 231321);
	hashTable->Put("Zly", 666666);
	
	cout << endl << endl <<"GET" << endl << endl;
	cout << "Zly " << ":  " << hashTable->Get("Zly") << endl;
	cout << "Kowalski " << ":  " << hashTable->Get("Kowalski") << endl;
	cout << "Kobyla " << ":  " << hashTable->Get("Kobyla") << endl;
	cout << "Kowalska " << ":  " << hashTable->Get("Kowalska") << endl;
	
	
}