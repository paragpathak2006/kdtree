#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Nodespace.h"
using namespace Nodedouble;

extern int depth;

ofstream& tabs(ofstream& c, int d) { for (int i = 0; i < d; i++) c << "\t";	return c; }
ofstream& operator<<(ofstream& c, Point& P) { tabs(c, depth) << P[0] << " " << P[1] << " " << P[2] ;	return c; }
ofstream& operator<<(ofstream& c, forward_list<Point*> list) {
	int n = 0, i = 0;;
	for (Point* P : list) n++;;
	for (Point* P : list) { 		i++;		c << *P;		if (i != n) c << " , "; 		c << endl;	}
	return c;
}

ofstream& operator<<(ofstream& c, vector<int>& index) {
//	int n = 0, i = 0;;
//	for (int P : list) n++;;
	for (int i : index) 	c << i << endl;
	return c;
}


ofstream& operator<<(ofstream& c, Kdtree* kdtree) {
	if (kdtree->left == nullptr && kdtree->right == nullptr) {
		tabs(c, depth) << "[" << endl;
		depth++;

		int n = 0;
		for (auto P : kdtree->Plist) n++;

		//		tabs(c, depth) << -n << " " << -n << endl;
		c << kdtree->Plist;
		//		tabs(c, depth) << -n << " " << -n << endl;
		depth--;
		tabs(c, depth) << "]";
		return c;
	}
	tabs(c, depth) << "{" << endl;
	depth++;

	if (!kdtree->Plist.empty()) c << kdtree->Plist << endl;

	tabs(c, depth) << kdtree->dim << " " << kdtree->val << endl;
	c << kdtree->left << endl;
	c << kdtree->right << endl;
	depth--;

	tabs(c, depth) << "}";
	return c;
}
