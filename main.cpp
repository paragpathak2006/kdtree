// kdtree.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <conio.h>

#include "Node.h"
#include "io.h"

#include "helper.cpp"
#include "initialize.cpp"
#include "traversal.cpp"

using namespace std;

using namespace Nodedouble;

void save(Kdtree& kdtree)	{	ofstream f;		f.precision(db::max_digits10);		f.open("kdtree.txt");				f << &kdtree;	f.close();	}
void save_json(Kdtree& kd)	{	ofstream f;		f.precision(db::max_digits10);		f.open("kdtree.json");				f < &kd;		f.close();	}
void save(Index& I)			{	ofstream f;		f.precision(db::max_digits10);		f.open("output_index_file.csv");	f << I;			f.close();	}

void load(Kdtree& kdtree)	{	ifstream f;		f.precision(db::max_digits10);		f.open("kdtree.txt");				f >> &kdtree;	f.close();	}
void load_input(Points& P)	{	ifstream f;		f.precision(db::max_digits10);		f.open("sample_tree_data.csv");		f >> P;			f.close();	cout << endl << "Input number of points = " << P.size(); }
void load_query(Points& P)	{	ifstream f;		f.precision(db::max_digits10);		f.open("sample_tree_query.csv");	f >> P;			f.close();	cout << endl << "Querry number of points = " << P.size() << endl;}

int findIndex(Point& T, Points& Input_Points) {
	for (size_t i = 0; i < Input_Points.size(); i++)
		if (Input_Points[i] == T) return i;

	return -1;
}

void f() {
	char c;
	if (_kbhit()) {
		c = _getch();		cout << endl << "Press any key to continue..." << endl;
		while (!_kbhit());	cout << endl << "Press any key to Pause..."    << endl;
		c = _getch();
	}
}

bool BruteForceValidator(Point Q/*Querry Point*/, Points Input_Points, Point T/*Target Point*/)
{
	Kdtree n;	Point B;/*Brute Force solution*/	double dmin = 1000000;

	for (Point P : Input_Points)
		if (dmin > n.dist(P, Q)) { dmin = n.dist(P, Q);			B = P; }

	if (n.dist(T, B) != 0.0) {
		cout << "distance     : " << n.dist(T, B) << endl;

		cout << "failed point : " << Q[0] << "," << Q[1] << "," << Q[2] << endl;
		cout << "kdtree point : " << T[0] << "," << T[1] << "," << T[2] << endl;
		cout << "Brute force  : " << B[0] << "," << B[1] << "," << B[2] << endl;

		return false;
	}

	return true;
}

void runTest(Kdtree& kdtree2, Points& QueryPoints, Points& Input_Points, Index& Output_Indices){
	bool validation = true;
	bool checkvalidation;int i  = 1;
	for (Point Q : QueryPoints) {

		auto op			= kdtree2.traverse(Q, f);
		checkvalidation	= BruteForceValidator(Q, Input_Points, *op);

		if (validation)			validation = checkvalidation;

		Output_Indices.push_back(findIndex(*op, Input_Points));
		cout << "Querry : " << i++ << "\tindex : " << Output_Indices.back() << "\tPress any key to Pause..." << endl;
	}

	if (validation)		cout << "Brute force validation succeeded !" << endl;
	else				cout << "Brute force validation failed. " << endl;
}

int main()
{
	Points InputPoints;	load_input(InputPoints);
	Points QueryPoints;	load_query(QueryPoints);

	Kdtree kdtree(InputPoints), kdtree2;		

	save(kdtree);	
	load(kdtree2);
	save_json(kdtree);

	Index Output_Indices;

	runTest(kdtree2, QueryPoints, InputPoints, Output_Indices);
	save(Output_Indices);

	return 0;
}