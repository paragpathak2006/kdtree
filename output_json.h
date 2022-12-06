#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Nodespace.h"
using namespace Nodedouble;


extern int depth;
template<class T>
class Wrap
{
public:
	T* obj = nullptr;
	Wrap<T>() {}
	Wrap<T>(T& t) : obj(&t) {}

};

template<class Tostream, typename T>
Tostream& operator<<(Tostream& c, Wrap<T>* W1) { c < *(W1->obj);	return c; }

template<class T>
auto W(T& t) { return new Wrap<T>(t); }

//--------------------------------------------------------------------------------
template<typename Tostream>
Tostream& operator<(Tostream& c, Point& P) { c << "[" << P[0] << "," << P[1] << "," << P[2] << "]";	return c; }


template<typename Tostream>
Tostream& operator<(Tostream& c, forward_list<Point*> list) {
	int n = 0, i = 0;
	for (Point* P : list) n++;
	for (Point* P : list) { i++;c <*P;if (i != n) c << " , "; }
//	for (Point* P : list) { i++;c << W<Point>(*P);if (i != n) c << " , "; }
	return c;
}

template<typename Tostream>
Tostream& operator<(Tostream& c, Kdtree* kdtree) {
	tabs(c, depth) << "{" << endl;
	depth++;
	if (kdtree->left == nullptr && kdtree->right == nullptr) {
		(tabs(c, depth) << "\"list\" : [  " < kdtree->Plist) << "  ] " << endl;
		depth--;
		tabs(c, depth) << "}";
		return c;

	}

	if (!kdtree->Plist.empty()) (c < kdtree->Plist ) << endl;

	tabs(c, depth) << " \"dim\"  : " << kdtree->dim << " , " << " \"val\"  : " << kdtree->val << " , " << endl;
	tabs(c, depth) << "\"left\"  :  " << endl;	(c < kdtree->left )<< "," << endl;
	tabs(c, depth) << " \"right\": " << endl;	(c < kdtree->right ) << endl;
	depth--;

	tabs(c, depth) << "}";
	return c;
}

