#include <iostream>
#include <math.h>
using namespace std;
void options();

//Ex.1
int sum(int n)
{
	if (n != 0)
		return n + sum(n - 1);
	return 0;

}
void Ex1()
{
	int n;
	cout << "Write an integer number: ";
	cin >> n;

	cout << "Sum= " << sum(n);
}

//Ex.2
int calculatePower(int base, int powerRaised)
{
	if (powerRaised != 0)
		return (base * calculatePower(base, powerRaised - 1));
	else
		return 1;

}
void Ex2()
{
	int base, powerRaised, result;
	cout << "Enter base number: ";
	cin >> base;

	cout << "Enter power number(positive integer): ";
	cin >> powerRaised;

	result = calculatePower(base, powerRaised);
	cout << base << "^" << powerRaised << " = " << result;
}
//Ex.3
void fibSeries(int n) {
	static int n1 = 0, n2 = 1, n3;
	if (n > 0) {
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		cout << n3 << " ";
		fibSeries(n - 1);
	}
}
void Ex3() {
	int num;
	cout << "Enter the number of elements for Fibonacci series: ";
	cin >> num;
	cout << "Fibonacci Series for " << num << " numbers: ";
	cout << "0 " << "1 ";
	fibSeries(num - 2);
	cout << "\n\n";
}

//Ex.4
int reverse_digits(int n, int temp)
{
	if (n == 0)
		return temp;

	temp = (temp * 10) + (n % 10);
	return reverse_digits(n / 10, temp);
}
void Ex4()
{
	int num;
	cout << "Enter the number to check palindrome:"; cin >> num;

	int result = reverse_digits(num, 0);

	if (result == num)
		cout << "Number " << num << " is a palindrome" << endl;
	else
		cout << "Number " << num << " is not a palindrome" << endl;
}

//Ex.5
int hcf(int n1, int n2)
{
	if (n2 != 0)
		return hcf(n2, n1 % n2);
	else
		return n1;
}
void Ex5()
{	
	cout << "Calculate H.C.F:\n ";
	int n1, n2;
	cout << "Enter two positive integers: ";
	cin >> n1 >> n2;
	cout << "H.C.F of " << n1 << " & " << n2 << " is: " << hcf(n1, n2);
}

//Ex.6
bool isPrime(int n, int i = 2)
{
	// Base cases 
	if (n <= 2)
		return (n == 2) ? true : false;
	if (n % i == 0)
		return false;
	if (i * i > n)
		return true;

	// Check for next divisor 
	return isPrime(n, i + 1);
}
void Ex6()
{
	int n;
	cout << "Number: ";
	cin >> n;
	if (isPrime(n))
		cout << "The given is a prime number!";
	else
		cout << "The given number is not a prime number!";
}

//Ex.7
void print(int n) {
	cout << "\n" << n;
	if (n < 100) {
		print(n + 1);
	}
}
void Ex7()
{
	print(1);
}

//Ex.8
void towerOfHanoi(int n, char from_rod,
	char to_rod, char aux_rod)
{
	if (n == 1)
	{
		cout << "Move disk 1 from rod " << from_rod <<
			" to rod " << to_rod << endl;
		return;
	}
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	cout << "Move disk " << n << " from rod " << from_rod <<
		" to rod " << to_rod << endl;
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
void Ex8()
{
	int n; // Number of disks 
	cout << "Enter the number of disks: ";
	cin >> n;
	cout << "\nFor " << n << " disks,the steps you need to take are:\n\n";
	towerOfHanoi(n, 'A', 'B', 'C'); // A, B and C are names of rods  
}

//Ex.9
void mul_table(int n, int i)
{
	cout << n << " * " << i << " = " << n * i << "\n";
	if (i != 10)
		mul_table(n, i + 1);
}
void Ex9()
{
	int n;
	cout << "Enter one integer number: ";
	cin >> n;
	mul_table(n, 1);
}

//Ex.10
int sum_digit(int n)
{
	//to calculate the number of digits in a number
	int number_of_digits = ((int)log10(n)) + 1;
	if (number_of_digits == 1)
		return n;
	else
		return n % 10 + sum_digit(n / 10);
}

void Ex10()
{
	int n;
	cout << "Enter the number: ";
	cin >> n;
	cout << "Sum of all the digits of the given number is: " << sum_digit(n);
}

//Ex.11
void reverse(string& str, int k)
{
	static int i = 0;

	// if we have reached the end of the string
	if (k == str.length())
		return;

	reverse(str, k + 1);

	if (i <= k)
		swap(str[i++], str[k]);
}
void Ex11()
{
	string str;
	cout << "String: ";
	cin >> str;
	reverse(str, 0);
	cout << "\nReverse of the given string is : " << str;
}

//Ex.12
// function to print a row 
void printn(int num)
{
	// base case 
	if (num == 0)
		return;
	cout << "* ";

	// recursively calling printn() 
	printn(num - 1);
}

// function to print the pattern 
void pattern(int n, int i)
{
	// base case 
	if (n == 0)
		return;
	printn(i);
	cout << endl;

	// recursively calling pattern() 
	pattern(n - 1, i + 1);
}

// driver function 
void Ex12()
{
	int n ;
	cout << "Number of rows: ";
	cin >> n;
	pattern(n, 1);
}

//Ex.13
int product(int x, int y)
{
	// if x is less than  
	// y swap the numbers 
	if (x < y)
		return product(y, x);

	// iteratively calculate  
	// y times sum of x 
	else if (y != 0)
		return (x + product(x, y - 1));

	// if any of the two numbers is  
	// zero return zero 
	else
		return 0;
}
void Ex13()
{
	int x, y;
	cout << "Number x= ";
	cin >> x;
	cout << "Number y= ";
	cin >> y;
	cout <<"Product: " <<product(x, y);
}

/*-----------------------------------------------------------------------------------------------------------*/
void options() {
	int select = 0;
	cout << "                              Using Recursion \n";
P:
	cout << "<---------------------------------------------------------------------------------->\n\n";
	cout << " 1-Exercise  1: Sum of n-natyral numbers\n"
		<<  " 2-Exercise  2: Calculate Power \n"
		<<  " 3-Exercise  3: Fibonacci Series \n"
		<<  " 4-Exercise  4: Check if the given number is a palindrome \n"
		<<  " 5-Exercise  5: Calculate HCF (highest common factor) \n"
		<<  " 6-Exercise  6: Check whether a Number is prime or not \n"
		<<  " 7-Exercise  7: Print 1 to 100 \n"
		<<  " 8-Exercise  8: Tower of Hanoi \n"
		<<  " 9-Exercise  9: Multiplication table \n"
		<<  "10-Exercise 10: Sum of all the digits of a number \n"
		<<  "11-Exercise 11: Reverse a string  \n"
		<<  "12-Exercise 12: Printing pyramid pattern \n"
		<<  "13-Exercise 13: Calculate Power \n\n";
	cout << "<----------------------------------------------------------------------------------->\n\n";
	cout << "Choose the number of the task: ";
	cin >> select;
	cout << "\n.....................................................................................\n\n";
	switch (select)
	{
	case 1:
		Ex1();
		break;
	case 2:
		Ex2();
		break;
	case 3:
		Ex3();
		break;
	case 4:
		Ex4();
		break;
	case 5:
		Ex5();
		break;
	case 6:
		Ex6();
		break;
	case 7:
		Ex7();
		break;
	case 8:
		Ex8();
		break;
	case 9:
		Ex9();
		break;
	case 10:
		Ex10();
		break;
	case 11:
		Ex11();
		break;
	case 12:
		Ex12();
		break;
	case 13:
		Ex13();
		break;
	default:
		cout << "\nChoose a number between 1-13 ! \n\n";
		goto P; break;
	}
	cout << endl;
	char answer;
	cout << "Would you want to choose another number?\nY-for Yes \nN-for No\n";
	cin >> answer;
	if (answer == 'Y' || answer == 'y')
		goto P;
	cout << "\n\n";
}
int main() {
	options();
	return 0;
}