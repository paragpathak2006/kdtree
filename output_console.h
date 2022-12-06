#pragma once

#include "Header.h"

#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ostream& tabs(ostream& c, int d) { for (int i = 0; i < d; i++) c << "\t";	return c; }
ostream& operator<<(ostream& c, Point& P) { tabs(c, depth) << P[0] << " " << P[1] << " " << P[2] << endl;	return c; }
ostream& operator<<(ostream& c, forward_list<Point*> list) {
	for (Point* P : list) c << *P;
	return c;
}

ostream& operator<<(ostream& c, Kdtree* kdtree) {
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
