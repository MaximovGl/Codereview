#include "Evaluate.h"
#include <iostream>
#include <string>

using namespace std;

//FIXME нет проверки водимого выражения
bool Exp_check(const string& exp) {
	int parenthesis_balance = 0;
	for (char c : exp) {
		if (!isdigit(c) && c != 'M' && c != 'm' && c != ',' && c != '(' && c != ')'){
			cerr << "Ошибка: Недопустимый символ '" << c << "' в выражении." << endl;
			return false;
		}
		if (c == '(') {
			parenthesis_balance++;
		}
		else if (c == ')') {
			parenthesis_balance--;
		}
		if (parenthesis_balance < 0) {
			cerr << "Ошибка: Несбалансированные скобки (лишняя закрывающая)." << endl;
			return false;
		}
	}
	if (parenthesis_balance != 0) {
		cerr << "Ошибка: Несбалансированные скобки (не хватает закрывающей)." << endl;
		return false;
	}
	return true;
}


//FIXME скобки
int Num(const string& exp, size_t& pos){
	int number = 0;
	while (pos < exp.length() && exp[pos] >= '0' && exp[pos] <= '9') {
		number = number * 10 + (exp[pos] - '0');
		pos++;
	}
	return number;
}

//FIXME скобки
int Calc(const string& exp, size_t& pos){
	if (exp[pos] >= '0' && exp[pos] <= '9') {
		return Num(exp, pos);
	}

	if (exp[pos] == 'M' || exp[pos] == 'm'){
		//FIXME непонятное название переменной
		//char op = exp[pos];
		char operation_sign = exp[pos];
		pos++;

		while (pos < exp.length() && exp[pos] != '('){
			pos++;
		}
		pos++;

		int left = Calc(exp, pos);

		while (pos < exp.length() && exp[pos] != ','){
			pos++;
		}
		pos++;

		int right = Calc(exp, pos);

		while (pos < exp.length() && exp[pos] != ')'){
			pos++;
		}
		pos++;

		if (operation_sign == 'M'){;
			if (left > right)
				return left;
			else
				return right;
		}else{
			if (left < right)
				return left;
			else
				return right;
		}
	}

	if (exp[pos] == '(') {
		pos++; 
		int result = Calc(exp, pos); 
		if (exp[pos] != ')') {
			cout << "Ожидается закрывающая скобка";
		}
		pos++; 
		return result;
	}
}
