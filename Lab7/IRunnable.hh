#ifndef IRunnable_HH
#define IRunnable_HH

class IRunnable
{
	protected : int MySize;
	
	public : virtual bool Prepare(int size) = 0;
	public : virtual bool Run() = 0;
};

#endif