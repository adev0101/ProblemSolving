// ProblemSolving.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

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
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

int main()
{
	srand(unsigned(time(NULL)));

	int arrLength = ReadPositiveNumber("Please enter array length: ");
	int arr[100];

	FillArrayWithRandomNumbers(arr, arrLength);

	cout << "\nOriginal Array:\n";
	PrintArray(arr, arrLength);



	system("pause>0");

	return 0;
}

