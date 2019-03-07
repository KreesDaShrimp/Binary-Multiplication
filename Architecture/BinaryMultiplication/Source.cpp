#include<iostream>
using namespace std;

class booth {
public:
	int n;
	int b[4];
	int comb[4], q[4];              //b=multiplicand q=multiplier
	int bb, qq;                     //bb and qq store actual decimal no.s
	booth() {
		for (int i = 0; i < 4; i++) {
			b[i] = 0;                 //b array stores multiplicand in binary
			q[i] = 0;                 //q array stores multiplier in binary
			comb[i] = 0;       //will store calculated 2s complement in        
			n = 4;
			bb = 0;
			qq = 0;
		}
	}

		//function to accept value from user and
		//converting it into binary in the form of
		//array and then calculating its 2s complement
		void acceptMm()    
		{
			cout << "Enter Multiplicand: ";
			cin >> bb;
			cout << "Enter Multiplier: ";
			cin >> qq;
			//decimal to binary
			int rem1, rem2, i = 0, j = 0; //rem1 and rem2 are remainders
			while (qq != 0)
			{
				rem2 = qq % 2;
				qq /= 2;
				q[i] = rem2;
				i++;
			}
			cout << q[3] << q[2] << q[1] << q[0] << endl;  // to display binary no.
			//again decimal to binary
			while (bb != 0)
			{
				rem1 = bb % 2;
				bb /= 2;
				b[j] = rem1;
				j++;
			}
			cout << b[3] << b[2] << b[1] << b[0] << endl;  //to display binary no.
			// 2s complement:
			int ii = 0;
			int jj = 4;    //4 bit binary number
			while (b[ii] == 0 && jj != 0)
			{
				comb[ii] = b[ii];
				ii++;
				jj--;
			}
			comb[ii] = b[ii];
			cout << b[3] << b[2] << b[1] << b[0] << endl;   //displayed value (problem)
			ii++;
			jj--;
			if (jj == 0)
			{
				return;
			}
			while (jj != 0)
			{
				if (b[ii] == 0)
				{
					comb[ii] = 1;
					ii++;
					jj--;
				}
				else
				{
					comb[ii] = 0;
					ii++;
					jj--;
				}
			}
		}

		void display()
		{
			cout << "multiplicand\n";
			for (int x = 3; x >= 0; x--)
			{
				cout << b[x] << " ";
			}
			cout << endl;
			cout << "multiplier\n";
			for (int j = 3; j > (-1); j--)
			{
				cout << q[j] << " ";
			}
			cout << endl;
			cout << "compliment of multiplicand\n";
			for (int y = 3; y > (-1); y--)
			{
				cout << comb[y] << " ";
			}
		}
	};



int main()
{
	booth obj;
	cout << "Booths Algorithm\n";
	obj.acceptMm();
	obj.display();
	return 0;
}