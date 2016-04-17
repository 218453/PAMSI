#ifndef TimeCounter_HH
#define TimeCounter_HH

#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <typeinfo>
#include "IStoper.hh"
using namespace std;

class TimeCounter : public IStoper
{
	long startTime;
	long endTime;
	long timeSpan;
	
	public : virtual void Start()
	{
		startTime = GetTime();
	}
	
	public : virtual void Stop()
	{
		endTime = GetTime();
	}
	
	public : virtual long GetElapsedTime()
	{
		if(endTime >= startTime)
		{
			return endTime-startTime;			
		}
		else
		{
			cout << "Error! Wrong time: " << endTime-startTime << endl;
			return 0.0;
		}
	}
	
	public : virtual bool DumpToFile()
	{
		return false;
	}
	
	private : long GetTime()
	{
		 struct timeval tv;

		 gettimeofday(&tv, NULL);

		 // returns time in micro seconds (10^-6)
		 return tv.tv_usec + tv.tv_sec *1000000;
	}
	
	public : void Reset()
	{
		startTime = 0;
		endTime = 0;
		timeSpan = 0;
	}	
};

#endif
