#include "containers.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iterator> 

bool Input(list<int>& L, int n) {
	int method, x;
	cout << "Выберите способ заполнения контейнера:" << endl;
	cout << "1) Ввод с клавиатуры" << endl;
	cout << "2) Ввод с помощью рандомайзера" << endl;
	cout << "3) Ввод из текстового файла" << endl;
	cin >> method;

	switch (method) {
	case 1:
		for (int i = 0; i < n; i++) {
			cout << "Введите элемент #" << i + 1 << ": ";
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
			cerr << "Ошибка: файл не открыт" << endl;
			return false;
		}
		for (int i = 0; i < n; i++) {
			if (!(file >> x)) {
				cerr << "Ошибка чтения файла" << endl;
				file.close();
				return false;
			}
			L.insert(L.end(), x);
		}
		file.close();
		return true;
	}

	default:
		cerr << "Ошибка: некорректный метод ввода" << endl;
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
		cerr << "Ошибка: список L1 пуст" << endl;
		return;
	}

	list<int>::iterator it = L1.begin();
	advance(it, L1.size() / 2);
	L2.splice(L2.end(), L1, it);
}