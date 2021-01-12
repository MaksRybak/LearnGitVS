#include <iostream>
#include <string>
#include <set>
#include <fstream>


bool CheckRegister(const std::string &value) //To check the range
{
	for (const auto& i : value)
		if (static_cast<int>(i) < 97 || static_cast<int>(i) > 122) //Only a..z
			return false;
	return true;
}

bool CeckUniqueWords(const std::string &word) //The function checks unique words 
{
	std::ifstream fin;
	fin.open("UniqueWords.txt"); //File for unique words
	std::string str;
	while (!fin.eof())
	{
		fin >> str; //Read the word
		if (str == word) //check every word 
		{
			fin.close();
			return false;
		}
	}
	return true;
}


int ReadFromFile(const std::string &fileName)
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open(fileName);
	try
	{
		if (!fin.is_open())
			throw "file not found";
		fout.open("UniqueWords.txt"); //File for unique words
		std::string temp;
		int count = 0; // Count unique words
		while (!fin.eof())
		{
			fin >> temp;
			if (CeckUniqueWords(temp) && CheckRegister(temp))
			{
				fout << temp << std::endl;
				count++;
			}
		}
		fout.close();
		fin.close();
		return count;
	}
	catch (const char* ex)
	{
		std::cout << ex << std::endl;
		fout.close();
		fin.close();
		return 0;
	}
}

int ReadFromCosole()
{
	std::set<std::string> mySet;
	std::cout << "Input your text: ";
	std::string* text = new std::string;

	std::getline(std::cin, *text);

	std::string temp;
	int position(0);

	while (position >= 0)
	{
		position = text->find(' ');//Looking for the index of the end of the word
		temp = text->substr(0, position); //Save this word 
		text->erase(0, position + 1); //Delete from the text
		if (CheckRegister(temp))
			mySet.insert(temp);
	}

	text->clear();

	return mySet.size();
}


int main()
{
	using namespace std;
	int choose;

	try
	{
		cout << "Make your choice: \n\t1)Read text file (for big data);\n\t2)Write in console" << endl;
		cin >> choose;
		cin.ignore(3200, '\n');
		if (choose != 1 && choose != 2)
			throw choose;
	}
	catch (int)
	{
		cout << "You did not enter an integer " << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	if (choose == 1)
	{
		string fileName;
		cout << "Enter your path to your file: "; //For example: B:\Games\text.txt
		getline(cin, fileName);
		cout << "Number of unique words: " << ReadFromFile(fileName) << endl;
	}

	else if (choose == 2)
	{
		int count = ReadFromCosole();
		cout << "Number of unique words: " << count << endl;
	}
	
	system("pause");
	return 0;
}

//if (choose == 1)
//{
//	ifstream fin;
//	fin.open("test.txt");
//
//	string temp;
//
//	while (!fin.eof())
//	{
//		fin >> temp;
//		if (CheckRegister(temp))
//			mySet.insert(temp);
//	}
//	cout << "The count util words is: " << mySet.size() << endl;
//}