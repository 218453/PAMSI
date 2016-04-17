#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "ArrayRunner.hh"
#include "TimeCounter.hh"
#include "ListTest.hh"
#include "HashTable.hh"
#include "AssociativeArray.hh"
#include "AssociativeArrayTest.hh"
using namespace std;

int main()
{
	int size;
	int laps = 10;
	long * timesPut = new long[laps];
	long * timesRemove = new long[laps];
	long averageTimePut = 0;
	long averageTimeRemove = 0;
	TimeCounter *stoper = new TimeCounter();
	AssociativeArrayTest *runner = new AssociativeArrayTest();
	

	cout << "Set problem size: ";
	cin >> size;
	
	
	cout << "TESTY" << endl;
	
	
	
	for(int i = 0; i < laps; i++)
	{
		if(!runner->Prepare(size))
		{
			cout << "Can't prepare runner." << endl;
			return 0;
		}
		stoper->Start();
		if(!runner->RunPut())
		{
			cout << "Runner can't finish." << endl;
			return 0;
		}
		stoper->Stop();
		timesPut[i] = stoper->GetElapsedTime();
		cout << "Put element->Lap " << (i+1) << endl;
		runner->ShowLists();
		stoper->Start();
		if(!runner->RunRemove())
		{
			cout << "Runner can't finish." << endl;
			return 0;
		}
		stoper->Stop();
		timesRemove[i] = stoper->GetElapsedTime();
		cout << "Remove element->Lap " << (i+1) << endl;
	}
	
	
	
	cout << endl << "TIMES PUT" << endl;
	for(int i = 0; i < laps; i++)
	{
		cout << "Lap " << (i+1) << " : " << setprecision(6) << fixed << timesPut[i]/1000000.0 << " s" << endl;
		averageTimePut += timesPut[i];
	}
	averageTimePut = averageTimePut/laps;
	cout << "Average time: " << setprecision(6) << fixed << averageTimePut / 1000000.0 << " s" << endl;
	
	cout << endl << "TIMES REMOVE" << endl;
	for(int i = 0; i < laps; i++)
	{
		cout << "Lap " << (i+1) << " : " << setprecision(6) << fixed << timesRemove[i]/1000000.0 << " s" << endl;
		averageTimeRemove += timesRemove[i];
	}
	averageTimeRemove = averageTimeRemove/laps;
	cout << "Average time: " << setprecision(6) << fixed << averageTimeRemove / 1000000.0 << " s" << endl;
}