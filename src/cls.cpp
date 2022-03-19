#include "../include/cls.h"
#include "../include/gfx.h"
#include <stdio.h>
#include <cmath>

#define PI 3.14159265

void Obj::create(char (&A)[3][3], int dx, int dy){

}

void X::create(char (&A)[3][3], int dx, int dy) {
		if (A[dx / cnst][dy / cnst] != 'O' && A[dx / cnst][dy / cnst] != 'X') {
			gfx_line(ots + tr * (dx / cnst), ots + tr * (dy / cnst), 123 + tr * (dx / cnst), 123 + tr * (dy / cnst));
			gfx_line(123 + tr * (dx / cnst), ots + tr * (dy / cnst), ots + tr * (dx / cnst), 123 + tr * (dy / cnst));
			A[dx / cnst][dy / cnst] = 'X';
			Game::pvt = false;
		} else {
			Game::pvt = true;
		}
}

void O::create(char (&A)[3][3], int dx, int dy) {

		if (A[dx / cnst][dy / cnst] != 'O' && A[dx / cnst][dy / cnst] != 'X') {
			for(int i = 0; i < 360; i++) {
				int x = 66 + tr * (dx / cnst) + r*cos(i * PI / 180);
				int y = 66 + tr * (dy / cnst) + r*sin(i * PI / 180);
				gfx_point(x, y);
			}
			A[dx / cnst][dy / cnst] = 'O';
			Game::pvt = false;
		} else {
			Game::pvt = true;
		}

} 
