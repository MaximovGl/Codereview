#include "list.h"
#include <iostream>

void Add(int data, PNode& Head, PNode& LastNode) {
	PNode Temp;
	if (Head == nullptr) {
		Head = new Node;
		LastNode = Head;
		Head->next = nullptr;
	}
	else {
		Temp = new Node;
		LastNode->next = Temp;
		LastNode = Temp;
		LastNode->next = nullptr;
	}
	LastNode->x = data;
}

PNode Find(int data, PNode& Head) {
	PNode Temp = Head;
	PNode prev = Head;
	while (Temp != nullptr && Temp->x < data) {
		prev = Temp;
		Temp = Temp->next;
	}
	return prev;
}

void Newadd(int data, PNode p, PNode& Head) {
	PNode newNode = new Node;
	newNode->next = nullptr;
	newNode->x = data;
	if (Head == nullptr || Head->x >= data) {
		newNode->next = Head;
		Head = newNode;
	}
	else {
		PNode Prev = Find(data, Head);
		if (Prev != nullptr) {
			newNode->next = Prev->next;
			Prev->next = newNode;
		}
	}
}

void Show_Before(PNode& Head) {
	PNode Mynode = Head;
	int count = 0;
	cout << "��� ���������� �����: ";
	while (Mynode != nullptr) {
		cout << Mynode->x << " ";
		Mynode = Mynode->next;
	}
	cout << endl;
}

void Show_After(PNode& Head) {
	PNode Mynode = Head;
	int count = 0;
	cout << "��� ���������� �����: ";

	while (Mynode != nullptr) {
		cout << Mynode->x << " ";
		Mynode = Mynode->next;
	}
	if (Mynode == nullptr) {
		cout << "�����!";
	}
	cout << endl;
}

PNode Find(PNode Head, int data) {
	PNode q = Head;
	while (q && q->x != data)
		q = q->next;
	return q;
}

void DeleteNode(PNode& Head, PNode OldNode) {
	PNode q = Head;
	if (Head == OldNode) {
		Head = OldNode->next;
	}
	else {
		while (q->next != OldNode) {
			q = q->next;
		}
		q->next = OldNode->next;
	}
	delete OldNode;
}

int Read_int() {
	int m = 0;
	while (!(cin >> m)) {
		cerr << "������ �����! ����������, ������� ����� �����: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return m;
}

void RunTask() {
	PNode p1 = nullptr;
	PNode p2 = nullptr;
	PNode p3 = nullptr;
	PNode p4 = nullptr;
	int n = 0;
	int m = 0;
	cout << "����� ����������!" << endl;
	cout << "����� ���� ��������� ������: " << endl;
	cout << "��� ����������� �������� ������. �������� ��������� ������ ����������� �� �����������." << endl;
	cout << "���������� ������� ����� ��������� ������, ����� ���� �� ����� ��������� ������ ��������" << endl;
	cout << "�������� M ���, ����� �� ������� ������������� � ������� ������ �� ������ ������� ����������� ������ P2." << endl << endl;
	cout << "----------------------------------------------------------------------" << endl << endl;
	cout << "��� ���������� ����� ������ ���������� ��������� � ������," << endl;
	cout << "� ����� ������ �������� ��������� ������ � ������� ����������� " << endl;
	cout << "� ������ ����� ������� �� ������ ��������." << endl;
	cout << "������ ������� ����������� 1 2 3 4 5 6" << endl;
	cout << "---------------------------------------------------------------------" << endl << endl;
	cout << "������� ����� n - ���������� ��������� � ������: ";
	n = Read_int();
	cout << endl << "������� " << n << " ����� � ������� ����������� (!!!!): ";
	for (int i = 0; i < n; ++i) {
		int j = 0;
		j = Read_int();
		Add(j, p1, p2);
		Add(j, p3, p4);
	}

	cout << endl << "������� ����� �������� ����� m, ������� ���������� ����� ��������: ";
	m = Read_int();
	Show_Before(p1);
	cout << endl;
	PNode P = Find(m, p3);
	Newadd(m, P, p3);
	Show_Before(p3);
	int choice;
	cout << endl << "������ ������� �����-������ �������?" << endl;
	cout << "���� ��, �� �������� 1" << endl;
	cout << "���� ���, �� �������� 2" << endl;
	cout << "��� �����: ";
	choice = Read_int();
	cout << endl;
	switch (choice) {
	case 1: {
		cout << "������� ����� - ���������� ��������� ������� �� ������ �������: ";
		int num = 0;
		num = Read_int();
		for (int i = 0; i < num; ++i) {
			cout << "������� �������� ��������, ������� �� ������ �������: ";
			int x = 0;
			x = Read_int();
			PNode p = Find(p3, x);
			cout << endl;
			cout << "��������...." << endl;
			DeleteNode(p3, p);
		}
		Show_After(p3);
	} break;

	case 2: {
		cout << "������� �� ��������!!!" << endl;
		cout << "�� ��������!!!" << endl;
	} break;

	default: {
		cerr << "������� �������� �����";
		break;
	}
	}
}