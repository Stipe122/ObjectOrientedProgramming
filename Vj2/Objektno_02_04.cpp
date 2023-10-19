#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct matrica {
	int m = 0;
	int n = 0;
	float** niz;
	void unos_matrice(int m, int n) {
		int i = 0;
		this->m = m;
		this->n = n;
		niz = new float* [m];
		for (i = 0; i < m; i++) {
			niz[i] = new float[n];
		}
	}

	void generiraj_matricu(float a, float b) {
		float r3;
		int i;
		int j;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				niz[i][j] = r3 = a + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (b - a)));
				cout << "[" << niz[i][j] << "]";
			}
			cout << endl;
		}
	}
};

void zbroji_matrice(struct matrica mat1, struct matrica mat2) {
	if (mat1.m != mat2.m || mat1.n != mat2.n) {
		cout << "Nije moguce zbrojiti matricu jer nema isti broj redaka ili stupca." << endl;
		return;
	}
	matrica mat3;
	mat3.unos_matrice(3, 3);
	int i, j;
	for (i = 0; i < mat1.m; i++) {
		for (j = 0; j < mat1.n; j++) {
			mat3.niz[i][j] = mat1.niz[i][j];
		}
	}
	for (i = 0; i < mat2.m; i++) {
		for (j = 0; j < mat2.n; j++) {
			mat3.niz[i][j] += mat2.niz[i][j];
		}
	}
	for (i = 0; i < mat3.m; i++) {
		for (j = 0; j < mat3.n; j++) {
			cout << "[" << mat3.niz[i][j] << "]";
		}
		cout << endl;
	}
}

void oduzmi_matrice(struct matrica mat1, struct matrica mat2) {
	if (mat1.m != mat2.m || mat1.n != mat2.n) {
		cout << "Nije moguce oduzeti matricu jer nema isti broj redaka ili stupca." << endl;
		return;
	}
	matrica mat3;
	mat3.unos_matrice(3, 3);
	int i, j;
	for (i = 0; i < mat1.m; i++) {
		for (j = 0; j < mat1.n; j++) {
			mat3.niz[i][j] = mat1.niz[i][j];
		}
	}
	for (i = 0; i < mat2.m; i++) {
		for (j = 0; j < mat2.n; j++) {
			mat3.niz[i][j] -= mat2.niz[i][j];
		}
	}
	for (i = 0; i < mat3.m; i++) {
		for (j = 0; j < mat3.n; j++) {
			cout << "[" << mat3.niz[i][j] << "]";
		}
		cout << endl;
	}
}
void pomnozi_matrice(struct matrica mat1, struct matrica mat2) {
	if (mat1.n != mat2.m) {
		cout << "Nije moguce pomnoziti matricu jer nisu ulancane." << endl;
		return;
	}
	matrica mat3;
	mat3.unos_matrice(3, 3);
	float temp;
	int i, j, k;
	for (i = 0; i < mat1.m; i++) {
		for (j = 0; j < mat1.n; j++) {
			temp = 0;
			for (k = 0; k < mat1.m; k++)
				temp += mat1.niz[i][k] * mat2.niz[k][j];
			mat3.niz[i][j] = temp;
		}
	}
	for (i = 0; i < mat3.m; i++) {
		for (j = 0; j < mat3.n; j++)
			cout << "[" << mat3.niz[i][j] << "]";

		cout << endl;
	}
}

void transponiraj_matricu(struct matrica mat1) {
	struct matrica tmat;
	tmat = mat1;
	int i, j;
	for (i = 0; i < tmat.n; ++i) {
		for (j = i; j < tmat.m; ++j) {
			float temp = tmat.niz[i][j];
			tmat.niz[i][j] = tmat.niz[j][i];
			tmat.niz[j][i] = temp;
		}
	}
	for (i = 0; i < tmat.m; i++) {
		for (j = 0; j < tmat.n; j++) {
			cout << "[" << tmat.niz[i][j] << "]";
		}
		cout << endl;
	}

}

int main() {
	srand(static_cast <unsigned> (time(0)));
	matrica mat1, mat2;
	cout << "Prva matrica" << endl;
	mat1.unos_matrice(3, 3);
	mat1.generiraj_matricu(1, 5);
	cout << "Druga matrica" << endl;
	mat2.unos_matrice(3, 3);
	mat2.generiraj_matricu(1, 5);
	cout << "Zbrojena matrica" << endl;
	zbroji_matrice(mat1, mat2);
	cout << "Oduzimanje matrica" << endl;
	oduzmi_matrice(mat1, mat2);
	cout << "Mnozenje matrica" << endl;
	pomnozi_matrice(mat1, mat2);
	cout << "Transponirana matrica" << endl;
	transponiraj_matricu(mat1);
}