#include "Header.h"

//� ���� ����� ������ ���� ������ ���������� ������� ��� ������ � ������������� �������
BigInteger TRANS_Q_Z(RationalFraction number)
{
	BigInteger result;
	result.sign = number.numenator.sign;
	result.number.size = number.numenator.number.size;
	result.number.coef = (short*)malloc(sizeof(short) * result.number.size);
	memcpy(result.number.coef, number.numenator.number.coef, result.number.size * sizeof(short));
	
	return result;
}


RationalFraction TRANS_Z_Q(BigInteger number)
{
	RationalFraction rezult;

	rezult.numenator.sign = number.sign;
	rezult.numenator.number = TRANS_Z_N(number);

	rezult.denominator.coef =  (short*)malloc(sizeof(short) * (1));
	rezult.denominator.coef[0] = 1;
	rezult.denominator.size = 1;
	return rezult;
}

RationalFraction ADD_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction result; 
	BigInteger nok1, nok2;

	nok1 = TRANS_N_Z(DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (first.denominator)));
	nok2 = TRANS_N_Z(DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (second.denominator)));

	result.numenator = ADD_ZZ_Z(MUL_ZZ_Z(nok1, first.numenator), MUL_ZZ_Z(nok2, second.numenator)); // ����������� ���������
	result.denominator = LCM_NN_N(first.denominator, second.denominator); // ����������� ����� ����������� 
	return result;
}



RationalFraction SUB_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction result;
	BigInteger nok1, nok2;

	nok1 = TRANS_N_Z(DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (first.denominator)));
	nok2 = TRANS_N_Z(DIV_NN_N(LCM_NN_N(first.denominator, second.denominator), (second.denominator)));

	result.numenator =  SUB_ZZ_Z(MUL_ZZ_Z(nok1, first.numenator), MUL_ZZ_Z(nok2, second.numenator));
	result.denominator = LCM_NN_N(first.denominator, second.denominator); 

	return result;
}


bool INT_Q_B(RationalFraction number)
{
	number = RED_Q_Q(number); //��������� �����
	if (number.denominator.coef[0] == 1 && number.denominator.size == 1) //��������� ����������� �� ��������� �������
		return true;
	else
		return false;
}


RationalFraction MUL_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction res;
	res.numenator = MUL_ZZ_Z(first.numenator, second.numenator);
	res.denominator = MUL_NN_N(first.denominator, second.denominator);
	return res;
}



RationalFraction DIV_QQ_Q(RationalFraction first, RationalFraction second)
{
	RationalFraction res;
	res.numenator = MUL_ZZ_Z(first.numenator, TRANS_N_Z(second.denominator));
	res.denominator = MUL_NN_N(first.denominator, TRANS_Z_N(second.numenator));
	res.numenator.sign = (first.numenator.sign == second.numenator.sign) ? plus : minus;
	return res;
}