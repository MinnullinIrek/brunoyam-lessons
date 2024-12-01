class Singlton
{
public:
	
	static Singlton& getInstance() {
		static Singlton s;
		return s;
	}

	~Singlton() {}
	void printMonitor() {};
private:
	Singlton();
};


void CreateSinglton() {

	Singlton& s = Singlton::getInstance();
	s.printMonitor();


}