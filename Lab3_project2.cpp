// Группа Б
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <iomanip>
//#define DEBUG

void add_container(int size_container, std::vector<std::string>& container)
{
	const int MAX_LENGTH = 200;
	std::string str;
	for (int i = 0; i < size_container; i++)
	{
		std::cout << "Введите " << i + 1 << "-ое слово в контейнер:\n";
		bool valid_input = false;
		while (!valid_input)
		{
			std::cout << "--> ";
			std::cin >> str;

			if (str.length() > MAX_LENGTH)
			{
				std::cout << "Слово слишком длинное! Длина не должна превышать " << MAX_LENGTH << " символов.\n";
				std::cout << "\n1) Повторить ввод\n";
				std::cout << "2) Взять только первые 200 символов\n--> ";
				int choice;
				std::cin >> choice;
				if (choice == 1)
				{
					continue;
				}
				else if (choice == 2)
				{
					str = str.substr(0, MAX_LENGTH);
					std::cout << "Будет использовано первые 200 символов: " << str << "\n";
				}
				else
				{
					str = str.substr(0, MAX_LENGTH);
					std::cout << "Вы ввели значения '" << choice << "' Будет использовано первые 200 символов:\n\n" << str << "\n\n";
				}
			}
			valid_input = true;
		}

		container.push_back(str);
	}
}
void char_vec(int size_con, std::vector<std::string>& container)
{
	const double DIVIDER = 3.0;
	std::vector<std::string> size_more_five;
	std::vector<std::string> duplicate;
	double num1 = 0;
	double index_num = 0;
	for (int i = 0; i < container.size(); i++)
	{
		if (std::all_of(container[i].begin(), container[i].end(), ::isdigit))
		{
			num1 = std::stod(container[i]);
			index_num = num1;
			num1 = num1/ DIVIDER;
			container[i] = std::to_string(num1);
			break;
		}
	}

	std::sort(container.begin(), container.end()); //нужна для нахождения дубликатов(одинаковые элементы встанут рядом)

#ifdef DEBUG
	
	std::cout << std::fixed << std::showpoint;
	for (int i = 0; i < container.size(); i++)
	{
		std::cout << "Число " << i + 1 << " " << std::setprecision(3) << container[i] << std::endl;
	}

	std::cout << "Сортировка\n";
	for (int i = 0; i < size_con; i++)
	{
		std::cout << " -- ";
		std::cout << container[i] << " ";
		std::cout << std::endl;
	}
#endif // DEBUG

	int num;
	for (int i = 0; i < size_con; i++)
	{
		std::string str = container[i];
		num = str.size();
		if (num == 5)
		{
			size_more_five.push_back(str);
		}
	}

	for (int i = 1; i < size_more_five.size(); i++)
	{
		if (size_more_five[i - 1] == size_more_five[i])
		{
			if (duplicate.empty())
			{
				duplicate.push_back(size_more_five[i]);
			}
			else if (size_more_five[i] != duplicate.back())
			{
				duplicate.push_back(size_more_five[i]);
			}
		}
	}

	std::vector<int> count_dup;
	int count = 0;
	for (int i = 0; i < duplicate.size(); i++)
	{
		for (int j = 0; j < container.size(); j++)
		{
			if (duplicate[i] == container[j])
			{
				count++;
			}
		}
		count_dup.push_back(count);
		count = 0;
	}

	system("cls");
	if (duplicate.empty())
	{
		std::cout << "Нет, повторяющихся дубликатов в контейнере!(Размером 5 символов)\n";
	}
	else
	{
		std::cout << "Количество повторяющихся слов:\n\n";
		for (int i = 0; i < duplicate.size(); i++)
		{
			std::cout << i + 1 << ") " << duplicate[i] << " = " << count_dup[i] << std::endl;
		}
		std::cout << std::endl;
	}

	if (index_num == 0)
	{
		std::cout << "\nВ контейнере нет числовых значений!\n";
	}
	else
	{
		std::cout << std::endl << "Первое число уменьшеное в 3 раза:\n";
		std::cout << index_num << " = " << num1 << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 0;
	std::vector<std::string> container_str;

	std::cout << "Сколько слов вы хотите сравнить?\n--> ";
	std::cin >> size;

	add_container(size, container_str);
	char_vec(size, container_str);

	return 0;
}