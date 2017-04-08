#include "Output.h"


//************************************************************************


void gotoXY(short x, short y)
{
	static HANDLE outputHande = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(outputHande, { x, y });
}


//************************************************************************


void changeConsoleColor(int bg, int text)
{
	static HANDLE outputHande = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(outputHande, bg << 4 | text);
}


//************************************************************************


//����� ���������
void infoView(char* message)
{
	int code = 0;							//��� ������� �������
	short pos = strlen(message) / 2 + 9;	//������� �������� ���������

	system("cls");
	gotoXY(10, 3);
	printf("%s", message);
	do
	{
		changeConsoleColor(0, 14);
		gotoXY(pos, 6);
		printf("<��>");
		code = getch();

	} while (code != 13);

	system("cls");
	changeConsoleColor(0, 7);

}


//************************************************************************

char* bigNaturalToString(BigNatural number)
{
	char* result = new char[number.size + 1];
	result[0] = '\0';
	for (int i = number.size - 1; i >= 0; i--)
		sprintf(result ,"%s%d",result , number.coef[i]);
	return result;
}

//************************************************************************

char* bigIntegerToString(BigInteger number)
{
	char* result = new char[number.number.size + 2];
	result[0] = '\0';
	if (number.sign == minus)
	{
		result[0] = '-';
		result[1] = '\0';
	}
	char* natural = bigNaturalToString(number.number);

	sprintf(result, "%s%s", result, natural);

	delete[] natural;

	return result;
}

//************************************************************************

char* rationalFractionToString(RationalFraction number)
{
	char* result = new char[number.numenator.number.size + number.denominator.size + 4];
	result[0] = '\0';

	if (INT_Q_B(number))
	{
		delete[] result;
		return bigIntegerToString(TRANS_Q_Z(RED_Q_Q(number)));
	}
		
	char* numenator = bigIntegerToString(number.numenator);
	char* denominator = bigNaturalToString(number.denominator);

	sprintf(result, "%s / %s", numenator, denominator);

	delete[] numenator;
	delete[] denominator;

	return result;
}

//************************************************************************


char* polynomToString(Polynom polynom)
{
	char* result = new char[1024];
	char* rFraction = nullptr;
	result[0] = '\0';
	for (int i = 0; i <= polynom.degree; i++)
	{
		rFraction = rationalFractionToString(polynom.coef[i]);

		if (i == polynom.degree)
			sprintf(result, "%s%s", result, rFraction);
		else if (NZER_N_B(polynom.coef[i].numenator.number))
			sprintf(result, "%s%sx^%d%s", result, rFraction, polynom.degree - i, i == polynom.degree ? "" : " + ");

		delete[] rFraction;
	}

	return result;
}
