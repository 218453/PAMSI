#include <iostream>
#include <fstream>
#include "RBTree.hh"
#include "RBTreeTest.hh"
#include "TimeCounter.hh"

using namespace std;

void DumpToFile(int times[11][6], char * fileName)
{
	ofstream myfile;
	myfile.open(fileName);
	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			myfile << times[i][j] << ";";
		}
		myfile << "\n";
	}
}

int main()
{
	TimeCounter * stoper = new TimeCounter();
	RBTreeTest *drzewoTest = new RBTreeTest();
	int laps = 10;
	int problemSizes [] = {10,100,1000,100000,1000000};
	int times[11][6];
	// i - wiersz
	// j - kolumna
	times[0][0] = 0;
	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(i == 0 && j != 0)
			{
				times[i][j] = problemSizes[j-1];
			}
			if(j == 0 && i != 0)
			{
				times[i][j] = i;
			}
		}
	}
	
	for(int i=0; i < 11; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(i == 0 || j == 0)
			{
				cout << times[i][j] << "   ";
			}
		}
		cout << endl;
	}
	
	
	cout << "RED BLACK TREE TEST" << endl << endl;

	for(int i = 0; i < 5; i++)
	{
		cout << "Problem Size: " << problemSizes[i] << ". Results: " << endl;
		for(int j = 0; j < laps; j++)
		{
			if(!drzewoTest->Prepare(problemSizes[i]))
			{
				cout << "ERROR! PREPARE FAILED!" << endl;
			}
			stoper->Start();
			if(!drzewoTest->Run())
			{
				cout << "ERROR! RUN FAILED!" << endl;
			}
			stoper->Stop();
			//cout << "Lap " << j+1 << ": " << stoper->GetElapsedTime() << " us" << endl;
			times[j+1][i+1] = stoper->GetElapsedTime();
		}
		cout << endl;
	}
	
	cout << "TIMES: " << endl;
	
	for(int i=1; i < 11; i++)
	{
		for(int j = 1; j < 6; j++)
		{
			cout << times[i][j] << "     ";
		}
		cout << endl;
	}
	
	//DumpToFile(times, "pomiary1.csv");
}