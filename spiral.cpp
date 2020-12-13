#include <iostream>
#include <math.h>

using namespace std;

bool lookRight(char dir, int x, int y, int mat[][10]) {
	switch (dir) {
	case 'e':
		return (mat[x + 1][y] != 0);
	case 's':
		return (mat[x][y - 1] != 0);
	case 'w':
		return (mat[x - 1][y] != 0);
	case 'n':
		return (mat[x][y + 1] != 0);
	}
}

char turn(char dir) {
	switch (dir) {
	case 'e':
		return ('s');
	case 's':
		return ('w');
	case 'w':
		return ('n');
	case 'n':
		return ('e');
	}
}

int spiralIt() {
	int n=1;
	cout << "\nEnter n: ";
	cin >> n;
	while (n != 0) {

		int mat[10][10];
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				mat[i][j] = 0;
			}
		int m = sqrt(n);
		mat[m/2][m/2] = 1;
		char dir = 'n';
		int x = m/2, y = m/2;
		for (int i = 1; i < n; i++) {
			if (!lookRight(dir, x, y, mat)) {
				dir = turn(dir);
			}
			switch (dir) {
			case 'e':
				y++;
				break;
			case 's':
				x++;
				break;
			case 'w':
				y--;
				break;
			case 'n':
				x--;
				break;
			}
			mat[x][y] = i + 1;
		}

		for (int i = 0; i < m+1; i++) {
			for (int j = 0; j < m+1; j++) {
				if(mat[i][j]!=0)
					cout << mat[i][j]<<"\t";
				else
					cout<<" \t";
			}
			cout << "\n";
		}
		cout << "\nEnter n: ";
		cin >> n;
	}
}
