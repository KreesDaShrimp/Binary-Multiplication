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

string decimal_to_binary(int n) {
	if (n < 0) { // check if negative and alter the number
		n = 256 + n;
	}
	string result = "";
	while (n > 0) {
		result = string(1, (char)(n % 2 + 48)) + result;
		n = n / 2;
	}
	return result;
}


// function to convert decimal to binary 
int* decToBinary(int n)
{
	// array to store binary number 
	int binaryNum[1000];

	// counter for binary array 
	int i = 0;
	while (n > 0) {

		// storing remainder in binary array 
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	return binaryNum;
	// printing binary array in reverse order 
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}

int main(int argc, char **argv)
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

	int multiplicandArray[7] = *decToBinary(tempMultiplicand);

	cout << "Multiplicand(decimal): " << tempMultiplicand << "\nMultiplicand(binary): " << *decToBinary(tempMultiplicand) << endl;
	cout << "Multiplier(decimal): " << tempMuliplier << "\nMultiplier(binary): " << *decToBinary(tempMuliplier) << endl;



	int mt[10], multiplicand[10], multiplier[10], sc, ac[10] = { 0 };
	int brn;
	int sequenceCounter; //Sequence counter
	int i;
	int qn;
	int temp;
	cout << "--Enter the multiplicand and multipier in signed 2's complement form if negative--" << endl;

	cout << "\n Number of multiplicand bit=";
	cin >> brn;
	cout << "\nmultiplicand=";

	for (i = brn - 1; i >= 0; i--)
		cin >> multiplicand[i]; //multiplicand

	for (i = brn - 1; i >= 0; i--)
		mt[i] = multiplicand[i]; // copy multiplicand to temp array mt[]

	complement(mt, brn);

	cout << "\nNo. of multiplier bit=";
	cin >> sequenceCounter;

	sc = sequenceCounter; //sequence counter

	cout << "Multiplier=";
	for (i = sequenceCounter - 1; i >= 0; i--)
		cin >> multiplier[i]; //multiplier




	//BEGIN BOOTHS ALGORITHM

	qn = 0;
	temp = 0;

	cout << "qn\tq[n+1]\t\tStep\t\tAC\tPlier\t\tsc\n";
	cout << "\t\t\tinitial\t\t";
	display(ac, multiplier, sequenceCounter);
	cout << "\t\t" << sc << "\n";


	//Main Loop
	while (sc != 0)
	{
		cout << multiplier[0] << "\t" << qn;
		if ((qn + multiplier[0]) == 1)
		{
			if (temp == 0)
			{
				add(ac, mt, sequenceCounter);
				cout << "\t\tsubtracting Cand\t";
				for (i = sequenceCounter - 1; i >= 0; i--)
					cout << ac[i];
				temp = 1;
			}
			else if (temp == 1)
			{
				add(ac, multiplicand, sequenceCounter);
				cout << "\t\tadding Cand\t";
				for (i = sequenceCounter - 1; i >= 0; i--)
					cout << ac[i];
				temp = 0;
			}
			cout << "\n\t";
			ashr(ac, multiplier, qn, sequenceCounter);
		}
		else if (qn - multiplier[0] == 0)
			ashr(ac, multiplier, qn, sequenceCounter);

		display(ac, multiplier, sequenceCounter);
		cout << "\t";

		sc--;
		cout << "\t" << sc << "\n";
	}
	cout << "Result=";
	display(ac, multiplier, sequenceCounter);
}