//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения, 
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
//определяется следующим образом(функция M возвращает максимальный из своих параметров,
//а функция m — минимальный) :
//	<выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)

# include <Windows.h>
# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

int num(const string& s, size_t& pos)
{
	int number = 0;
	while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9') {
		number = number * 10 + (s[pos] - '0'); 
		pos++;
	}
	return number;
}

int calc(const string &s,size_t& pos)
{
	if (s[pos] >= '0' && s[pos] <= '9') {
		return num(s, pos);
	}

	if (s[pos] == 'M' || s[pos] == 'm')
	{
		char op = s[pos];
		pos++;

		//пропускаю (
		while (pos < s.length() && s[pos] != '(')
		{
			pos++;
		}
		pos++;

		int left = calc(s, pos);

		// пропускаю ,
		while (pos < s.length() && s[pos] != ',')
		{
			pos++;
		}
		pos++;

		int right = calc(s, pos);

		// пропускаю )
		while (pos < s.length() && s[pos] != ')')
		{
			pos++;
		}
		pos++;

		if (op == 'M')
		{
			//return max(left, right);
			if (left > right)
				return left;
			else
				return right;
		}
		else
		{
			//return min(left, right);
			if (left < right)
				return left;
			else
				return right;
		}
	}

	if (s[pos] == '(') {
		pos++; // Пропускаем '('
		int result = calc(s, pos); // продолжаем вычислять уже внутреннее выражение
		if (s[pos] != ')') {
			cout << "Ожидается закрывающая скобка";
		}
		pos++; // Пропускаем ')'
		return result;
	}
	
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Добро пожаловать! " << endl;
	cout << "Перед нами стоит задача: найти значение выражения типа" << endl;
	cout << " <выражение> ::= <цифра> | M(<выражение> , <выражение>) | "<< endl;
	cout << "m(<выражение>, <выражение>)" << endl;
	cout << "где M - функция, которая выбирает большее значение из двух чисел." << endl;
	cout << "а m - функция, которая выбирает меньшее значение из двух чисел." << endl;
	cout << "-------------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "Ваша задача - записать любое выражение, которое вы захотите" << endl;
	cout << "БЕЗ ИСПОЛЬЗОВАНИЯ ПРОБЕЛОВ" << endl;
	cout << "А мы посчитаем значение и выведем его на экран." << endl;
	cout << "Важное замечание: вводить можно только целые неотрицательные числа." << endl;
	cout << "-------------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "Выражение может выглядеть так:" << endl;
	cout << "M(1234,m(12345,M(175,m(1270,1980))))" << endl;
	cout << "m(M(12759,m(1370,140)),m(1345,6789))" << endl;
	cout << endl;
	cout << endl;
 	string s; 
	cout << "Введите выражение:";
	getline(cin, s);

	size_t pos = 0;
	int result = calc(s, pos);
	cout << endl;
	cout << "Полученный результат равен: ";
	cout << result << " ";

	return 0;
}