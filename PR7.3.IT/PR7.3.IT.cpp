#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(int** mas, const int rowCount, int  colCount, int A, int B) {

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			mas[i][j] = A + rand() % (B - A + 1);
		}
	}
}

void Print(int** mas, const int rowCount, int  colCount) {

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			cout << setw(4) << mas[i][j];
		}
		cout << endl;
	}
}

int  number_ne_0(int** mas, const int rowCount, int colCount) {
	int kne0 = rowCount;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			if (mas[i][j] == 0) {
				--kne0;
				break;
			}
		}

	}

	return kne0;
}



void povEl(int** mas, const int rowCount, int colCount, int& k) {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			int m = 0;

			for (int x = 0; x < rowCount; x++) {
				for (int y = 0; y < colCount; y++) {

					if (mas[i][j] == mas[x][y]) {
						m++;
						if (m > 1) {
							k++;
							//cout << mas[i][j] << " ,";
						}
					}
				}
			}

		}
	}
}

void zapys(int** mas, const int rowCount, const int colCount, int*& pov) {
	int q = 0;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			int m = 0;

			for (int x = 0; x < rowCount; x++) {
				for (int y = 0; y < colCount; y++) {

					if (mas[i][j] == mas[x][y]) {
						m++;
						if (m > 1) {
							pov[q] = mas[i][j];
							q++;
						}
					}

				}
			}

		}
	}

}

void Max(int*& pov, int& k, int& max) {
	for (int i = 0; i < k; i++) {
		if (pov[i] > max) {
			max = pov[i];
		}

	}
}

int main()
{
	srand((unsigned)time(NULL));

	int rowCount;
	int colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** T = new int* [rowCount];
	for (int i = 0; i < rowCount; i++) {

		T[i] = new int[colCount];
	}

	Create(T, rowCount, colCount, -5, 5);
	cout << "T = { " << endl; Print(T, rowCount, colCount); cout << "    }" << endl;

	cout << "k_ne_0 = " << number_ne_0(T, rowCount, colCount) << endl;

	int k = 0;
	povEl(T, rowCount, colCount, k);

	//cout << k;

	int* pov = new int[k];
	zapys(T, rowCount, colCount, pov);

	//for (int i = 0; i < k; i++) {
	//	cout << pov[i] << " ,";
	//}

	int max = pov[0];
	Max(pov, k, max);


	if (k == 0) {
		cout << "no repeating elements " << endl;
	}
	else {
	cout << "max = " << max << endl;
	}


	delete[]pov;

	for (int i = 0; i < rowCount; i++) {
		delete[]T[i];
	}
	delete[]T;

	return 0;
}
