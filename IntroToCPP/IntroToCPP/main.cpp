#include <iostream>

int main()
{

	char firstName[32];
	char lastName[32];
	char fullName[64] = "";

	std::cout << "Please enter your name: ";
	std::cin >> firstName;

	system("cls");

	std::cout << "Now please enter your last name: ";
	std::cin >> lastName;

	system("cls");

	strcat_s(fullName, firstName);
	strcat_s(fullName, lastName);

	std::cout << "Your name is: " << fullName << "\n";
	system("pause");
}
	
