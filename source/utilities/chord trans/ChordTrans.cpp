// SmartChordGen-utility-ChordTrans v1.5 [Build: 2020.7.2]
// (c) 2020 Wenge Chen, Ji-woon Sim.

#include <fstream>
#include <iostream>
#include <vector>

#include "..\..\main\source\functions.h"
#include "..\..\main\source\functions.cpp"
using namespace std;

int main()
{
	cout << "[[  SmartChordGen v1.5 [Build: 2020.7.2]  ]]\n"
		  << "[[  (c) 2020 Wenge Chen, Ji-woon Sim.     ]]\n\n"
		  << " > Utility - Chord trans:\n";
	
	cout << " > Please input the name of the chord data file (the default extension is '.txt'): ";
	char input[100] = "\0";
	inputFilename(input, ".txt", true);
	
	int trans, axis;
	cout << "\n > Please input the number of seminotes to transpose (press Enter for no trans): ";
	inputNum(trans, -127, 127, 0);
	cout << "\n > Please input the axis note for inversion (press Enter for no inversion): ";
	inputNum(axis, 1, 127, 0);
	
	bool sort;
	cout << "\n > Sort the result (Y / N)? ";
	char ch;  inputY_N(ch);
	if(ch == 'Y' || ch == 'y')
		sort = true;
	else  sort = false;
	
	cout << "\n > Please assign a name for the output file (the default extension is '.txt'): ";
	char output[100] = "\0";
	inputFilename(output, ".txt", false);
	
	ifstream fin(input, ios::in);
	fout.open(output, ios::trunc);
	vector<int> notes, result;
	int note;

	do{
		notes.clear();
		result.clear();
		do{
			fin >> note;
			notes.push_back(note);
		}  while(!fin.eof() && fin.get() != '\n');
		if(notes.size() == 0)  break;

		for(int i = 0; i < notes.size(); ++i)
			notes[i] += trans;
		if(axis == 0)
			result.assign(notes.begin(), notes.end());
		else
		{
			vector<int>::iterator it;
			for(it = notes.begin(); it != notes.end(); ++it)
				result.push_back(2 * axis - *it);
		}
		if(sort)  bubble_sort(result);

		for(int i = 0; i < result.size(); ++i)
		{
			fout << result[i];
			if(i != 0)  fout << ' ';
		}
		fout << endl;
	}  while(!fin.eof());

	cout << "\n > Output finished. Now you can close the program.\n\n";
	fin.close();
	fout.close();
	system("pause"); 
	return 0;
}

