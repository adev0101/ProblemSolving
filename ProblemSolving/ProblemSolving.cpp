// ProblemSolving.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		/* code */
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

void InvertedLetterPattern(int Number)
{
	for (int i = 65 + Number - 1; i >= 65; i--)
	{
		// i = B (66)
		for (int j = 1; j <= i - 65 + 1; j++)
		{
			// 67-65+1 = 3 
			cout << char(i);

		}

		cout << endl;
	}
}

void LetterPattern(int Number)
{
	for (int i = 65; i <= 65 + Number - 1; i++)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
		{
			cout << char(i);
		}

		cout << endl;
	}
}

void PrintLettersAAAtoZZZ()
{
	string word = "";
	for (int i = 65; i <= 90; i++)
	{
	
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word += char(i);
				word += char(j);
				word += char(k);

				cout << word << endl;
				word = "";
			}
		}
	}

}

bool Get3LetterPassword(string Password)
{
	if (Password.length() != 3)
		return true;

	int Trials = 0;
	string word = "";

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				Trials++;

				word += char(i);
				word += char(j);
				word += char(k);

				cout << "Trial[" << Trials << "]: " << word << "\n";

				if (word == Password)
				{
					cout << "Password is " << word << "\n";
					cout << "Found after " << Trials << " trial(s).\n";
					return true;
				}

				word = "";
			}
		}
	}

	return false;

}

string EncryptText(string text, int EncryptionKey)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = char((int)text[i] + EncryptionKey);
	}

	return text;
}

string DecryptText(string text, int EncryptionKey)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = char((int)text[i] - EncryptionKey);
	}

	return text;
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int RandomNumber(int From, int To)
{
	if (From > To)
		Swap(From, To);

	return rand() % (To - From + 1) + From;
}

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

char GetSpecialCharacter()
{
	int choice = RandomNumber(1, 4);

	switch (choice)
	{
	case 1: return (char)RandomNumber(32, 47);
	case 2: return (char)RandomNumber(58, 64);
	case 3: return (char)RandomNumber(91, 96);
	case 4: return (char)RandomNumber(123, 126);
	}

	return '\0';
}

char GetCharType(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
		return (char)RandomNumber(97, 122);

	case enCharType::CapitalLetter:
		return (char)RandomNumber(65, 90);

	case enCharType::SpecialCharacter:
		return GetSpecialCharacter();

	case enCharType::Digit:
		return (char)RandomNumber(48, 57);
	}

	return '\0';
}

string GenerateWord(enCharType CharType, int WordLength)
{
	string sWord = "";

	for (int i = 0; i < WordLength; i++)
	{
		sWord += GetCharType(CharType);
	}

	return sWord;
}

string GenerateKey()
{
	string sKey = "";

	sKey += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	sKey += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	sKey += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	sKey += GenerateWord(enCharType::CapitalLetter, 4);

	return sKey;
}

void GenerateKeys(int NumberOfKeys)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Key [" << i << "]: " << GenerateKey() << "\n";
	}
}

void ReadArray(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Element [" << i + 1 << "]: ";
		cin >> arr[i];
	}
}

void PrintArray(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\n";
}

int NumberRepetitionInArray(int NumberToCheck, int arr[], int arrLength)
{

	int counter = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (NumberToCheck == arr[i])
			counter++;
	}

	return counter;
}

void FillArrayWithRandomNumbers(int arr[], int arrLength)
{
	// *arr = arr -> &arr[0]
	for (int i = 0; i < arrLength; i++)
	{

		arr[i] = RandomNumber(1, 100);
	}
}

int MaxNumberInArray(int arr[], int arrLength)
{
	int Max = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] > Max)
			Max = arr[i];
	}

	return Max;
}

int MinNumberInArray(int arr[], int arrLength)
{
	int Min = arr[0];

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] < Min)
			Min = arr[i];
	}

	return Min;
}

int SumOfArray(int arr[], int arrLength)
{
	int sum = 0;

	for (int i = 0; i < arrLength; i++)
	{
		sum += arr[i];
	}

	return sum;
}

float AverageOfArray(int arr[], int arrLength)
{
	return (float)SumOfArray(arr, arrLength) / arrLength;
}

void CopyArray(int arrDestination[], int arrSource[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrDestination[i] = arrSource[i];
	}
}

void Staircase(int n) {

	if (n < 0 || n > 100)
	{
		return;
	}


	for (int i = n; i >= 1; i--) // rows
	{
		// i = 4
		for (int j = 1; j <= n; j++) // columns
		{
			// j = 1
			if (j < i)
				cout << " ";
			else
				cout << "#";

		}

		cout << "\n";
	}


}

void StaircaseOpposite(int n) {

	if (n < 0 || n > 100)
	{
		return;
	}


	for (int i = n; i >= 1; i--) // rows
	{
		// i = 4
		for (int j = 1; j <= n; j++) // columns
		{
			// j = 1
			if (j <= i)
				cout << "#";
			else
				cout << " ";

		}

		cout << "\n";
	}


}

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };


enPrimNotPrime CheckPrime(int Number)
{

	int M = round(Number / 2);

	// Loop from 2 to M to test for divisibility.
	for (int Counter = 2; Counter <= M; Counter++)
	{
		// If Number is divisible by any Counter, then it is not a prime.
		if (Number % Counter == 0)
			return enPrimNotPrime::NotPrime;  // Return NotPrime immediately.
	}

	// If no divisors were found, return Prime.
	return enPrimNotPrime::Prime;
}

void CopyPrimeArray(int arrDestination[], int arrSource[], int arrLength, int &arr2Length)
{
	int index = 0; // the core idea of handling this function

	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
		{
			arrDestination[index] = arrSource[i];
			index++;
		}
	}

	arr2Length = index;
}

void miniMaxSum(vector<int> arr) {
	long long TotalSum = 0;
	int min = arr[0], max = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		TotalSum += arr[i];

		if (arr[i] < min)
		{
			min = arr[i];
		}

		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	long long sumMin = TotalSum - max;
	long long sumMax = TotalSum - min;

	cout << sumMin << " " << sumMax << endl;
}

void SumOf2Arrays(int arrSum[], int arr1[], int arr2[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrSum[i] = arr1[i] + arr2[i];
	}
}

int birthdayCakeCandles(vector<int> candles) {
	int counter = 0;
	int tallestHeight = candles[0];

	for (int i = 0; i < candles.size(); i++)
	{
		if (candles[i] > tallestHeight)
		{
			tallestHeight = candles[i];
			counter = 1;
		}

		else if (candles[i] == tallestHeight)
		{
			counter++;
		}
	}



	return counter;
}

void FillArrayFrom1toN(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = i + 1;
	}
}

void ShuffleArray(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		int j = RandomNumber(i, arrLength - 1); // index of the random choice of range starting after the current element
		Swap(arr[i], arr[j]); // swap it with the current element
	}
}

string timeConversion(string s) {

	string hr = s.substr(0, 2);
	string min = s.substr(3, 2);
	string sec = s.substr(6, 2);
	string am_pm = s.substr(8, 2);

	int hr_time = stoi(hr);

	if (am_pm == "AM" && hr_time == 12)
	{
		hr_time = 0;
	}

	if (am_pm == "PM" && hr_time != 12)
	{
		hr_time = hr_time + 12;
	}

	hr = hr_time < 10 ? "0" + to_string(hr_time) : to_string(hr_time);

	s = hr + ":" + min + ":" + sec;

	return s;

}

vector<int> gradingStudents(vector<int> grades) {

	
	for (int i = 0; i < grades.size(); i++)
	{
		if (grades[i] < 38)
			continue;

		int nearestToMultipleOfFive = 5 * ((grades[i] / 5) + 1);

		if (nearestToMultipleOfFive - grades[i] < 3)
		{
			grades[i] = nearestToMultipleOfFive;
		}

	}

	return grades;

}

void CopyArrayInReversedOrder(int arrDestination[], int arrSource[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrDestination[i] = arrSource[arrLength - 1 - i];
	}
}

int main()
{
	srand(unsigned(time(NULL)));



	int arr[100], arrLength;

	arrLength = ReadPositiveNumber("Please enter array length: ");
	FillArrayWithRandomNumbers(arr, arrLength);

	cout << "\nOriginal Array:\n";
	PrintArray(arr, arrLength);

	int arrReversed[100];
	CopyArrayInReversedOrder(arrReversed, arr, arrLength);

	cout << "\nArray In reverse:\n";
	PrintArray(arrReversed, arrLength);
	
	system("pause>0");

	return 0;
}

