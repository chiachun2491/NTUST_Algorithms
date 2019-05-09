// Student ID: B10615043
// Date: April 14, 2018
// Last Update: April 14, 2018
// Problem statement: This C++ header to declare class Form.
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype> // islower

using namespace std;

class Form
{
private:
	string input;							//��J���r
	string fileName;						//�ɮצW��
	int info[127] = { 0 };					//Record input letter info
	vector <string> found;					//array to save found word

public:
	void SetInputWord(string inputWord);	//�]�wInput
	void ProcessInputWord();				//�B�zInput ����T
	void SetFileName(string fileName);		//�]�w�ɮצW��
	void Load_CompaerWord();				//Ū�ɨåB���
	void PrintFoundWords();					//�L�X�ŦX���r
};