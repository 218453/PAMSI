#ifndef IStoper_HH
#define IStoper_HH

class IStoper
{
	public : virtual void Start() = 0;
	public : virtual void Stop() = 0;
	public : virtual long GetElapsedTime() = 0;
	public : virtual bool DumpToFile() = 0;
};

#endif