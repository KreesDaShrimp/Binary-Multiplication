#include<iostream>
#include<conio.h>
#include <string>

using namespace std;

void add(int a[], int x[], int sequenceCounter);
//Finds the compliment
void complement(int a[], int n)
{
	int i;

	int x[8] = { NULL };
	x[0] = 1;
	for (i = 0; i < n; i++)
	{
		a[i] = (a[i] + 1) % 2;
	}
	add(a, x, n);
}
//Adds
void add(int ac[], int x[], int sequenceCounter)
{
	int i, c = 0;
	for (i = 0; i < sequenceCounter; i++)
	{
		ac[i] = ac[i] + x[i] + c;
		if (ac[i] > 1)
		{
			ac[i] = ac[i] % 2;
			c = 1;
		}
		else
			c = 0;
	}

}
//Arithmatic shift right
void ashr(int ac[], int multiplierArray[], int &qn, int sequenceCounter)
{
	int temp, i;

	temp = ac[0];
	qn = multiplierArray[0];
	cout << "\t\tashr\t\t";
	for (i = 0; i < sequenceCounter - 1; i++)
	{
		ac[i] = ac[i + 1];
		multiplierArray[i] = multiplierArray[i + 1];
	}
	multiplierArray[sequenceCounter - 1] = temp;
}
//Display the currnet version
void display(int ac[], int multiplierArray[], int sequenceCounter)
{
	int i;

	for (i = sequenceCounter - 1; i >= 0; i--)
		cout << ac[i];
	cout << " ";
	for (i = sequenceCounter - 1; i >= 0; i--)
		cout << multiplierArray[i];

}
//Convert from Binary to Decimal
void binaryToDecimal(int ac[], int multiplierArray[], int sequenceCounter)
{
	int i;
	int result[16];

	for (i = sequenceCounter - 1; i >= 0; i--)
		 result[i] = ac[i];

	for (i = sequenceCounter - 1; i >= 0; i--)
		cout << multiplierArray[i];

}

void decimalToBinary(int n, int binaryArray[]) {
	n = abs(n);
	for(int i = 0; i < 8; i++){
		binaryArray[i] = n % 2;
		n = n / 2;
	}
}
//Convert Binary Number to Negative version of Binary Number
void binaryToNegative(int binaryArray[]) {
	int i;
	//Flip the 1s and 0s
	for (i = 0; i < 8; i++) {
		if (binaryArray[i] == 1) {
			binaryArray[i] = 0;
		}
		else if (binaryArray[i] == 0) {
			binaryArray[i] = 1;
		}
	}
	int tempArray[8];
	//Copy values of binary array
	for (i = 0; i < 8; i++) {
		tempArray[i] = binaryArray[i];
	}

	//2s Compliment
	for (int i = 0; i < 8; i++)
	{
		if (tempArray[i] == 1)
			binaryArray[i] = 0;
		else
		{
			binaryArray[i] = 1;
			break;
		}
	}
	// If No break : all are 1  as in 111  or  11111; 
	// in such case, add extra 1 at beginning 
	//if (i == -1) {
	//	binaryArray[0] = 1;
	//}
}

int main()
{
	//Max input is 127 to -128


	//Convert to Binary
	int tempMultiplicand;
	int tempMuliplier;
	bool done = false;
	while (!done) {
		cout << "Please enter the decimal multiplicand: ";
		cin >> tempMultiplicand;
		if (tempMultiplicand > 127 || tempMultiplicand < -127) {
			cout << "Invalid input" << endl;
		}
		else {
			cout << "Please enter the decimal multiplier: ";
			cin >> tempMuliplier;
			if (tempMuliplier > 127 || tempMuliplier < -127) {
				cout << "Invalid input" << endl;
			}
			else {
				done = true;
			}
		}
	}

	int mt[8], multiplicandArray[8], multiplierArray[8], sc, ac[8] = { 0 };
	int multiplicandBits = 8;
	int multiplierBits = 8; //Sequence counter
	int i;
	int qn;
	int temp;
	int resultDecimal = tempMultiplicand * tempMuliplier;
	int booths;
	//cout << "--Enter the multiplicand and multipier in signed 2's complement form if negative--" << endl;

	//cout << "\n Number of multiplicand bit=";
	//cin >> multiplicandBits;
	//cout << "\nmultiplicand=";

	//for (i = multiplicandBits - 1; i >= 0; i--)
	//	cin >> multiplicand[i]; //multiplicand


	decimalToBinary(tempMultiplicand, multiplicandArray);
	if (tempMultiplicand < 0) {
		binaryToNegative(multiplicandArray);
	}

	//Print multiplicand
	cout << "Multiplicand: ";
	for (int i = 7; i >= 0; i--) {
		cout << multiplicandArray[i];
	}
	cout << endl;

	for (i = multiplicandBits - 1; i >= 0; i--)
		mt[i] = multiplicandArray[i]; // copy multiplicand to temp array mt[]

	complement(mt, multiplicandBits);

	//cout << "\nNo. of multiplier bit=";
	//cin >> multiplierBits;

	sc = 0; //sequence counter

	//cout << "Multiplier=";
	//for (i = multiplierBits - 1; i >= 0; i--)
	//	cin >> multiplier[i]; //multiplier

	decimalToBinary(tempMuliplier, multiplierArray);
	if (tempMuliplier < 0) {
		binaryToNegative(multiplierArray);
	}
	//Print multiplier
	cout << "Multiplier: ";
	for (int i = 7; i >= 0; i--) {
		cout << multiplierArray[i];
	}
	cout << endl;

	//BEGIN BOOTHS ALGORITHM

	qn = 0;
	temp = 0;

	booths = 0;


	cout << "\tIteration\tStep\t\tMultiplicand\t\tProduct\n";
	cout << "\t" << sc;
	cout << "\t\tinitial\t\t";
	for (int i = 7; i >= 0; i--) {
		cout << multiplicandArray[i];
	}
	cout << "\t\t";
	display(ac, multiplierArray, multiplierBits);
	cout << " " << booths << "\n";


	//Main Loop
	while (sc != multiplierBits)
	{
		cout << "\t";
		cout << sc + 1;
		if ((qn + multiplierArray[0]) == 1)
		{
			if (temp == 0)
			{
	// Subtracting function
				add(ac, mt, multiplierBits);
				cout << "\t\tsubtracting\t";
				for (int i = 7; i >= 0; i--) {
					cout << multiplicandArray[i];
				}
				cout << "\t\t";
				display(ac, multiplierArray, multiplierBits);
				cout << " " << booths;

				temp = 1;
			}
			else if (temp == 1)
			{
	// Adding function
				add(ac, multiplicandArray, multiplierBits);
				cout << "\t\tadding        \t";
				for (int i = 7; i >= 0; i--) {
					cout << multiplicandArray[i];
				}
				cout << "\t\t";
				display(ac, multiplierArray, multiplierBits);
				cout << " " << booths;
				temp = 0;
			}
			cout << "\n\t";
			if (multiplierArray[0] == 1) {
				booths = 1;
			}
			else {
				booths = 0;
			}
			ashr(ac, multiplierArray, qn, multiplierBits);
		}
		else if (qn - multiplierArray[0] == 0)
		{
			ashr(ac, multiplierArray, qn, multiplierBits);
		}
		for (int i = 7; i >= 0; i--) {
			cout << multiplicandArray[i];
		}
		cout << "\t\t";
		display(ac, multiplierArray, multiplierBits);
		cout << " " << booths << "\n";

		sc++;
	}
	cout << "Result = ";
	display(ac, multiplierArray, multiplierBits);
	cout << "\nDecimal = " << resultDecimal;
}