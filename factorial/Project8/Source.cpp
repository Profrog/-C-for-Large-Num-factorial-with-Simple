#include <iostream>
using namespace std;

//////////////////////
char *num = new char[1000];
int getInputSize = 0;
int numLength = 0;
int copyLength = 0;
int resultLength = 0;
int whereline = 1;
int checkMidium = 0;
static int howSize = 100000;
////////////////////////


struct bigNum // set of linked list
{
	bigNum *address;
	bigNum *nextAddress;
	bool isNext = false;
	int value = 0;
	bool nextvalue = false;
};

//////////////////////// parameter for calculating
bigNum *a3 = new bigNum;
bigNum *a1 = new bigNum;
bigNum *result = new bigNum;
////////////////////


/////////////////function list
int main();
void copyNum_(bigNum *a1);
int findNum_(int N);
int findNum_(bigNum *a4, int N);
void firstCalcul_2(bigNum *a4);
void forInputtingValue_();
void shownum_();
void shownum_(bigNum *a4);
void setBigInt_(char *num);
void secondCalcul_1();
void setNum_(bigNum *a4, int N, int value);
void setNum_2(bigNum *a4, int N, int value);
void setMultipleNum_(bigNum *a4, int N, int value);
void setPlusNum_(bigNum *a4, int N, int value);
void startFactorial_();

////////////////





void copyNum_(bigNum *a1)
{
	try {
		for (int i = 0; i <= numLength - 1; i++)
		{
			setNum_2(a1, i, findNum_(i)); //findNum_ mean that getting data in i(line) of original data
		}
	}
	catch (int)
	{
		startFactorial_();
		cout << "error in copyNum_";
	}
}



int findNum_(int N)
{
	bigNum *a4 = a3; //original data is in a3

	try {
		for (int i = 0; i< N - 1; i++) //search for this index
		{

			a4 = (*a4).nextAddress;
		}

		if (a4 == nullptr)
			throw 1;

		return (*a4).value;
	}


	catch (int)
	{
		howSize *= 2;
		startFactorial_();
		cerr << "errorin findNum_\n";
		return 0;
	}; //this is mean that linked list first
}


int findNum_(bigNum *a4, int N) //for getting value in this index
{
	try {
		for (int i = 0; i< N - 1; i++)
		{
			
			a4 = (*a4).nextAddress;
		}

		if (a4 == nullptr)
			throw 1;

		return (*a4).value;
	}

	catch(int)
	{
		howSize *= 2;
		startFactorial_();
		cerr << "error in findNum_\n";
		return 0;
	}; //this is mean that linked list first
}



void firstCalcul_2(bigNum *a4)
{
	try {
		////reult, multiple matter
		resultLength = numLength;
		copyLength = numLength;

		//go each data , if meaning 5, likely 5->4->3->2->1 in setNum function
		for (int j = 0; j < copyLength; j++)
		{
			if (copyLength < 0)
				throw 1;

			setNum_(result, j, findNum_(a4, j));
		}

		
	}
	catch (int)
	{
		howSize *= 2;
		startFactorial_();
	}
}



void forInputtingValue_() //#1 first function 
{
	cout << "input : ";

	try {
		int count = 99;

		while (1)
		{
			char c = getchar();

			if (c == '\n')  //end of line
			{
				num[count] = c;
				break;
			}


			c == 'X' ? exit(0) : 0; //for cancel

			if (c >= '0' && c <= '9')  //only getting 0~9 in each position 
			{
				num[count] = c;
				numLength++;
				count--;
			}

			else //if getting likely $%@$#!@#$!
			{
				cout << "error, and restart";
				forInputtingValue_();
			}
		}

		/////////// saving data of getting size///
		getInputSize = 99 - count;
		(numLength /= 4) += 1;
		/////////////////

		cout << "Input end\n";
	}

	catch (int i)
	{
		cout << "error, and restart";
		startFactorial_();
	}
} //getting value



void shownum_() // showing original data
{
	try {
		for (int i = numLength; i >= 1; i--)
		{
			cout << findNum_(i);
		}

	}


	catch (int)
	{
		startFactorial_();
		cerr << "error in shownum";
	}
}


void shownum_(bigNum *a4) // showing a4's data
{
	try {
		if (a4 == result)
		{
			//cout << resultLength << " " << numLength;
			for (int i = whereline; i >= 1; i--)
			{
				if (whereline < 1)
					throw 1;


				if (i != whereline)
				{
					if (findNum_(a4, i) >= 1000)
						cout << findNum_(a4, i);

					else if (findNum_(a4, i) >= 100)
						cout << "0" << findNum_(a4, i);

					else if (findNum_(a4, i) >= 10)
						cout << "00" << findNum_(a4, i);

					else
						cout << "000" << findNum_(a4, i);
				}

				else
					cout << findNum_(a4, i);

				(i > 1) ? cout << "," : cout << endl;
			}
		}

		else
			for (int i = numLength; i >= 1; i--)
			{

				cout << findNum_(a4, i);
			}
	}

	catch (int) {
		howSize *= 2;
		startFactorial_();
		cerr << "error in shownum_";
	}
}




void setBigInt_(char *num) //for saving in data using likedlist
{

	try {
		bigNum *a2 = a3; //it is used for original data
		bigNum *b1 = result; //it will be used for showing of result
		bigNum *b2 = a1; // it will be used for farameter


		int checkNumSize = 3;

		cout << "Progressing saving getting data by int\n";

		for (int i =  100 - getInputSize; i <= 99; i += 4) //i will putting number in formatting of int and digits of 4
		{

				if (i <= 96)
				{
					int	Value = 0;
					int multipleValue = 1000;

					while (checkNumSize >= 0)
					{
						Value += multipleValue * ((int)num[i + checkNumSize] - 48);
						multipleValue /= 10;
						checkNumSize--;
					}

					(*a2).value = Value;
					checkNumSize = 3;


					/////////////////////////////
					(*a2).nextAddress = new bigNum;
					(*a2).address = a2;
					a2 = (*a2).nextAddress;

					///////////////////////////
					(*b2).nextAddress = new bigNum;
					b2 = (*b2).nextAddress;
				}

				else //last of digit will be able to 1,2,3,4 of digits
				{
					(i < 97 || i > 99) ? throw 1 : 0;

					switch (i)
					{
						
					case 97:
						(*a2).value = ((int)num[99] - 48) * 100 + ((int)num[98] - 48) * 10 + ((int)num[97] - 48);
						break;

					case 98:
						(*a2).value = ((int)num[99] - 48) * 10 + ((int)num[98] - 48);
						break;


					case 99:
						(*a2).value = ((int)num[99] - 48);
						break;

					default:
						break;
					}
				}
		}

		cout << "howSize" << howSize;
			for (int i = 0 ; i < howSize ; i++)  //because of result of digit is bigger than inputting's size of digit
			{
				(*b1).value = 0; //****
				(*b1).nextAddress = new bigNum;
				b1 = (*b1).nextAddress;
			}
		
		b1 = nullptr;
		copyNum_(a1); // it mean that copy in a1 to original data(a3)
	}

	catch (int)
	{
		startFactorial_();
		cerr <<  "error in bigInt";
	}
}


void secondCalcul_1()
{
	try {
		cout << "calculating factorial \n";
		int size = numLength - 1; // no considering index of '\n'
		int k;

		while (size >= 0)
		{
			if (size <= 0 && (k = findNum_(a1, 0) <= 0))
			{
				throw 1;
				break;
			}


			firstCalcul_2(a1);


			// i want if getting 5 making likely 5*4*3*2*1
			if (size >= 0)
			{
				int j = 0;
				int val3 = findNum_(a1, 0);

				if (val3 > 0)
				{
					setNum_2(a1, j, val3 - 1);  //if last value of index bigger than 0, if getting 5, next making 4..3..2
				}


				else
				{
					while (int k = findNum_(a1, j) < 1)  //if last value is 0, need recived data from front index
					{
						if (j == numLength)
						{
							throw 1;
							return;
						}

						j++;
					}

					val3 = findNum_(a1, j);
					setNum_2(a1, j, val3 - 1); //recived data


					for (int i = 0; i < j; i++)
						setNum_2(a1, i, 9999);
				}


				if (findNum_(a1, size) <= 0)
				{

					size--;
					copyLength = size;
	
					if (size < 0)  //it mean that 1000-> 0000
						return;
				}
			}
		}

		cout << "end\n";
	}
	catch (int)
	{
		howSize *= 2;
		startFactorial_();
		cerr << "reloading";	
	}
}



void setNum_(bigNum *a4, int N, int value)
{
	try {
		int i = 0;
		int L = 0;
		bool check = true;

		for (int i = 1; i <= whereline; i++)
		{
			int k = findNum_(result, i)*value; //multiple last data and getting data in firstCalcul_1
	
			if (L > 0) //L is realtive with pick of digit
			{
				k -= L*(value-1);
				L = 0;
			}

			if (k < 10000) //one linked list formatting had 0~9999
				setNum_2(result, i, k);

			
			else
			{
				check = false;

				setPlusNum_(result, i+1, k / 10000);
				L = k / 10000;

				setNum_2(result, i, k % 10000);

				if (whereline < i + 1)
				{
					
					whereline = i + 1;
					break;
				}
			}
		}

	}


	catch (int)
	{
		howSize *= 2;
		startFactorial_();
		cerr << "reloading";	
	}; //this is mean that linked list first
}


void setNum_2(bigNum *a4, int N, int value) //for changing data of N in a4, to value
{
	//bigNum *b1;

	try {
		for (int i = 0; i < N - 1; i++)
		{
			if (a4 == nullptr)
				throw 1;

			a4 = (*a4).nextAddress;
		}

		(*a4).value = value;	
	}

	catch (int)
	{
		howSize *= 2;
		startFactorial_();
	}
}


void setMultipleNum_(bigNum *a4, int N, int value) //for Multiple data of N in a4, to value
{
	try {
		for (int i = 0; i< N - 1; i++)
		{
			if (a4 == nullptr)
				throw 1;

			a4 = (*a4).nextAddress;
		}

	
		(*a4).value *= value;
	}

	catch (int)
	{
		howSize *= 2;
		startFactorial_();
		cerr << "reloading";	
	}; //this is mean that linked list first
}



void setPlusNum_(bigNum *a4, int N, int value) //for Multiple Plus of N in a4, to value
{
	try {
		for (int i = 0; i< N - 1; i++)
		{
			if (a4 == nullptr)
				throw 1;

			a4 = (*a4).nextAddress;
		}


		(*a4).value += value;
		
	}

	catch (int)
	{
		howSize += 20;
		startFactorial_();
		cerr << "reloading";	
	}; //this is mean that linked list first
}


void startFactorial_()
{
	try {
		howSize *= 2;
		setBigInt_(num); //setting original list formatting linked list
		setNum_2(result, 0, 1);// result of value setting to 1(mean that likely 001)
		secondCalcul_1();
		cout << endl;
		shownum_(result);
	}

	catch (int)
	{
	
		startFactorial_();
		cerr << "reloading";
	}
}




int main(void)
{	
	forInputtingValue_();  //getting value that user want, and manufacture
	startFactorial_();
	
	return 0;
}
