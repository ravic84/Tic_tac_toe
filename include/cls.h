#include "gfx.h"
#include <cstdlib>

extern const int ysize;
extern const int xsize;

class Obj{
	protected:
		double tr;
		int cnst = 134;
	public:
		Obj(){
			tr = xsize / 3;
		}
	virtual void create(char (&A)[3][3], int dx, int dy);
};

class X: public Obj {
	private:
		int ots;
	public:
		X(){
			ots = 10;
		}
		X(int ots = 10){
			this->ots = ots;
		}
		virtual void create(char (&A)[3][3], int dx, int dy);
};

class O: public Obj{
	private:
		int r;
	public:
		O(){
			r = 60;
		}
		O(int r = 60){
			this->r = r;
		}
		virtual void create(char (&A)[3][3], int dx, int dy);
};

class Game{
	public:
		static bool pvt;
		static bool hod;
};
