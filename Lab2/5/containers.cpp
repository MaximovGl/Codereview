#include "containers.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iterator> 

bool Input(list<int>& L, int n) {
	int method, x;
	cout << "�������� ������ ���������� ����������:" << endl;
	cout << "1) ���� � ����������" << endl;
	cout << "2) ���� � ������� ������������" << endl;
	cout << "3) ���� �� ���������� �����" << endl;
	cin >> method;

	switch (method) {
	case 1:
		for (int i = 0; i < n; i++) {
			cout << "������� ������� #" << i + 1 << ": ";
			cin >> x;
			L.insert(L.end(), x);
		}
		return true;

	case 2:
		srand(static_cast<unsigned>(time(0)));
		for (int i = 0; i < n; i++) {
			L.insert(L.end(), rand() % 101 - 50);
		}
		return true;

	case 3: {
		ifstream file("a.txt");
		if (!file.is_open()) {
			cerr << "������: ���� �� ������" << endl;
			return false;
		}
		for (int i = 0; i < n; i++) {
			if (!(file >> x)) {
				cerr << "������ ������ �����" << endl;
				file.close();
				return false;
			}
			L.insert(L.end(), x);
		}
		file.close();
		return true;
	}

	default:
		cerr << "������: ������������ ����� �����" << endl;
		return false;
	}
}


void Print(const list<int> L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void Splice(list<int>& L1, list<int>& L2) {
	if (L1.empty()) {
		cerr << "������: ������ L1 ����" << endl;
		return;
	}

	list<int>::iterator it = L1.begin();
	advance(it, L1.size() / 2);
	L2.splice(L2.end(), L1, it);
}