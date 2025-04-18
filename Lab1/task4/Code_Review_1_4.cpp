//FIXME задани е не по форме
//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения, 
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
//определяется следующим образом(функция M возвращает максимальный из своих параметров,
//а функция m — минимальный) :
//	<выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)

//FIXME Windows.h запрещен
//# include <Windows.h>
# include "Evaluate.h"
# include <iostream>

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

		//пропускаю (
		while (pos < exp.length() && exp[pos] != '('){
			pos++;
		}
		pos++;

		int left = Calc(exp, pos);

		// пропускаю ,
		while (pos < exp.length() && exp[pos] != ','){
			pos++;
		}
		pos++;

		int right = Calc(exp, pos);

		// пропускаю )
		while (pos < exp.length() && exp[pos] != ')'){
			pos++;
		}
		pos++;

		if (operation_sign == 'M'){
			//return max(left, right);
			if (left > right)
				return left;
			else
				return right;
		}else{
			//return min(left, right);
			if (left < right)
				return left;
			else
				return right;
		}
	}

	if (exp[pos] == '(') {
		pos++; // Пропускаем '('
		int result = Calc(exp, pos); // продолжаем вычислять уже внутреннее выражение
		if (exp[pos] != ')') {
			cout << "Ожидается закрывающая скобка";
		}
		pos++; // Пропускаем ')'
		return result;
	}

}

//FIXME скобки
int main(){
	setlocale(LC_ALL, "ru");
/*	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/

	cout << "Добро пожаловать! " << endl;
	cout << "Перед нами стоит задача: найти значение выражения типа" << endl;
	cout << " <выражение> ::= <цифра> | M(<выражение> , <выражение>) | " << endl;
	cout << "m(<выражение>, <выражение>)" << endl;
	//cout << "где M - функция, которая выбирает большее значение из двух чисел." << endl;
	//cout << "а m - функция, которая выбирает меньшее значение из двух чисел." << endl;
	cout << "где M - функция выбора большего числа из двух." << endl;
	cout << "а m - функция выбора меньшего числа из двух." << endl;
	cout << "-------------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "Ваша задача - записать любое выражение, которое вы захотите" << endl;
	cout << "БЕЗ ИСПОЛЬЗОВАНИЯ ПРОБЕЛОВ" << endl;
	cout << "А мы посчитаем значение и выведем его на экран." << endl;
	//cout << "Важное замечание: вводить можно только целые неотрицательные числа." << endl;
	cout << "Важное замечание: вводите целые неотрицательные числа." << endl;
	cout << "-------------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "Выражение может выглядеть так:" << endl;
	cout << "M(1234,m(12345,M(175,m(1270,1980))))" << endl;
	cout << "m(M(12759,m(1370,140)),m(1345,6789))" << endl;
	cout << endl;
	cout << endl;
	//FIXME однобуквенная переменная
	//string s;
	string exp = "";
	cout << "Введите выражение:";
	getline(cin, exp);

	if (exp.empty()) {
		cerr << "Ошибка: Введена пустая строка." << endl;
	}
	Exp_check(exp);

	size_t pos = 0;
	int result = Calc(exp, pos);
	cout << endl;
	cout << "Полученный результат равен: ";
	cout << result << " ";

	return 0;
}
