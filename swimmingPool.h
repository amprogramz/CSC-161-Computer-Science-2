//															Alec McDaugale
//swimming pool header
//defines swimming pool
//class name
class swimmingPool
{
//public functions
public:
	void setPool(int len, int wid, int dep);
	//sets the pools dimensions in ft
	void setDimensions();
	//allows user to enter the dimensions in ft
	void setVolume();
	//this calculates the volume in feet and gallons
	void setRate();
	//this sets the rate of fill
	void printPool();
	//this prints out the pool data
	
	//int getRate();
	//diddnt need
	//this gets the rate
	swimmingPool(int len, int wid, int dep);
	//constructor for pool, initalizes to 0 but allows user to select dimensions.
	swimmingPool();
	//default constructor

//private variables
private:
	//variables to hold length, width, and depth of the pool
	int length;
	int width;
	int depth;
	//variables to hold the volume in sq ft and gallons
	int volume;
	double volInGallons;

	//watter in the pool, fill rate, and the fill time in hours and minutes.
	int watterInPool;
	int fillRate;
	double fillTimeH;
	double fillTimeM;

};