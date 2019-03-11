#include<iostream>
#include<conio.h>
#include <string>

using namespace std;

void add(int a[], int x[], int sequenceCounter);
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

void ashr(int ac[], int multiplier[], int &qn, int sequenceCounter)
{
	int temp, i;

	temp = ac[0];
	qn = multiplier[0];
	cout << "\t\tashr\t\t";
	for (i = 0; i < sequenceCounter - 1; i++)
	{
		ac[i] = ac[i + 1];
		multiplier[i] = multiplier[i + 1];
	}
	multiplier[sequenceCounter - 1] = temp;
}

void display(int ac[], int multiplier[], int sequenceCounter)
{
	int i;

	for (i = sequenceCounter - 1; i >= 0; i--)
		cout << ac[i];
	cout << " ";
	for (i = sequenceCounter - 1; i >= 0; i--)
		cout << multiplier[i];

}


void decimalToBinary(int n, int binaryArray[]) {
	n = abs(n);
	for(int i = 0; i < 8; i++){
		binaryArray[i] = n % 2;
		n = n / 2;
	}
}

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
}

void binaryToNegative2(int binaryArray[]) {
	int n = (sizeof(binaryArray) / sizeof(*binaryArray));

	// Traverse the string to get first '1' from 
	// the last of string 
	int i;
	for (i = n - 1; i >= 0; i--)
		if (binaryArray[i] == 1)
			break;

	//// If there exists no '1' concatenate 1 at the 
	//// starting of string 
	//if (i == -1)
	//	return 1 + binaryArray;

	// Continue traversal after the position of 
	// first '1' 
	for (int k = i - 1; k >= 0; k--)
	{
		//Just flip the values 
		if (binaryArray[k] == 1)
			binaryArray[k] = 0;
		else
			binaryArray[k] = 1;
	}
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
		if (tempMultiplicand > 127 || tempMultiplicand < -128) {
			cout << "Invalid input" << endl;
		}
		else {
			cout << "Please enter the decimal multiplier: ";
			cin >> tempMuliplier;
			if (tempMuliplier > 127 || tempMuliplier < -128) {
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

	sc = multiplierBits; //sequence counter

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

	cout << "qn\tq[n+1]\t\tStep\t\tAC\tPlier\t\tsc\n";
	cout << "\t\t\tinitial\t\t";
	display(ac, multiplierArray, multiplierBits);
	cout << "\t\t" << sc << "\n";


	//Main Loop
	while (sc != 0)
	{
		cout << multiplierArray[0] << "\t" << qn;
		if ((qn + multiplierArray[0]) == 1)
		{
			if (temp == 0)
			{
				add(ac, mt, multiplierBits);
				cout << "\t\tsubtracting Cand\t";
				for (i = multiplierBits - 1; i >= 0; i--)
					cout << ac[i];
				temp = 1;
			}
			else if (temp == 1)
			{
				add(ac, multiplicandArray, multiplierBits);
				cout << "\t\tadding Cand\t";
				for (i = multiplierBits - 1; i >= 0; i--)
					cout << ac[i];
				temp = 0;
			}
			cout << "\n\t";
			ashr(ac, multiplierArray, qn, multiplierBits);
		}
		else if (qn - multiplierArray[0] == 0)
			ashr(ac, multiplierArray, qn, multiplierBits);

		display(ac, multiplierArray, multiplierBits);
		cout << "\t";

		sc--;
		cout << "\t" << sc << "\n";
	}
	cout << "Result=";
	display(ac, multiplierArray, multiplierBits);
}