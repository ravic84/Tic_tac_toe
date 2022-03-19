#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <iostream>
#include "../include/cls.h"
#include "../include/gfx.h"

#define PI 3.14159265

const int ysize = 450;
const int xsize = 400;
bool Game::pvt = false;
bool Game::hod = true;
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");
	gfx_open(xsize,ysize,"curs");
	gfx_color(255, 0, 0);
	

	X *x = new X(10);
	O *o = new O(60);
	gfx_line(0, 133, 400, 133);
	gfx_line(0, 266, 400, 266);
	gfx_line(133, 0, 133, 400);
	gfx_line(266, 0, 266, 400);

	gfx_line(0, 400, 400, 400);

	gfx_line(5, 405, 45, 445);
	gfx_line(45, 405, 5, 445);
	char c;
	char A[3][3];
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			A[i][j] = '-';
		}
	}
	while(1) {

		if(gfx_event_waiting()) {
			c = gfx_wait();
			if(c == 'q') {
				break;
			}
			if(c == 1) {
				int dx = gfx_xpos();
				int dy = gfx_ypos();
				if(Game::hod) {
					x->create(A, dx, dy);
					if(!Game::pvt) {
						Game::hod = false;
						gfx_color(0, 0, 0);
						gfx_line(5, 405, 45, 445);
						gfx_line(45, 405, 5, 445);
						gfx_color(255, 0, 0);
						for(int i = 0; i < 360; i++) {
							int x = 25 + 20*cos(i * PI / 180);
							int y = 425 + 20*sin(i * PI / 180);
							gfx_point(x, y);
						}
					}




				} else {
					o->create(A, dx, dy);

					if(!Game::pvt) {
						Game::hod = true;
						gfx_color(0, 0, 0);

						for(int i = 0; i < 360; i++) {
							int x = 25 + 20*cos(i * PI / 180);
							int y = 425 + 20*sin(i * PI / 180);
							gfx_point(x, y);
						}
						gfx_color(255, 0, 0);
						gfx_line(5, 405, 45, 445);
						gfx_line(45, 405, 5, 445);
					}
				}
				if (((A[0][0] == 'O') && (A[0][1] == 'O') && (A[0][2] == 'O')) ||
				        ((A[1][0] == 'O') && (A[1][1] == 'O') && (A[1][2] == 'O')) ||
				        ((A[2][0] == 'O') && (A[2][1] == 'O') && (A[2][2] == 'O')) ||
				        ((A[0][0] == 'O') && (A[1][0] == 'O') && (A[2][0] == 'O')) ||
				        ((A[0][1] == 'O') && (A[1][1] == 'O') && (A[2][1] == 'O')) ||
				        ((A[0][2] == 'O') && (A[1][2] == 'O') && (A[2][2] == 'O')) ||
				        ((A[0][0] == 'O') && (A[1][1] == 'O') && (A[2][2] == 'O')) ||
				        ((A[2][0] == 'O') && (A[1][1] == 'O') && (A[0][2] == 'O')) ||
				        ((A[0][0] == 'X') && (A[0][1] == 'X') && (A[0][2] == 'X')) ||
				        ((A[1][0] == 'X') && (A[1][1] == 'X') && (A[1][2] == 'X')) ||
				        ((A[2][0] == 'X') && (A[2][1] == 'X') && (A[2][2] == 'X')) ||
				        ((A[0][0] == 'X') && (A[1][0] == 'X') && (A[2][0] == 'X')) ||
				        ((A[0][1] == 'X') && (A[1][1] == 'X') && (A[2][1] == 'X')) ||
				        ((A[0][2] == 'X') && (A[1][2] == 'X') && (A[2][2] == 'X')) ||
				        ((A[0][0] == 'X') && (A[1][1] == 'X') && (A[2][2] == 'X')) ||
				        ((A[2][0] == 'X') && (A[1][1] == 'X') && (A[0][2] == 'X'))) {
					cout << "Игра окончена! " << endl;
					if(Game::hod) {
						cout << "0 победил!" << endl;
					}
					if(!Game::hod) {
						cout << "X победил!" << endl;
					}
					break;
				} else {
					int k = 0;
					for(int i = 0; i < 3; i++) {
						for(int j = 0; j < 3; j++) {
							if(A[i][j] == 'O' || A[i][j] == 'X') {
								k += 1;
							}
						}
					}
					if(k == 9) {
						cout << "Игра окончена! " << endl;
						cout << "Ничья!" << endl;
						break;
					}
				}
			}

		}
		//usleep(10000);
		//gfx_clear();
	}
	//delete x;
	//delete o;
	return 0;
}
