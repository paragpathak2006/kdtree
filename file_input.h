#pragma once
#include <fstream>
extern int depth;
ostream& tabs2(ostream& c, int d) { for (int i = 0; i < d; i++) c << "\t";	return c; }

#include "Nodespace.h"
using namespace Nodedouble;

ifstream& operator>>(ifstream& c, Kdtree* kdtree) {
	string s;

	c >> s;	
//	tabs2(cout, depth) << s <<endl;
	depth++;
	if (s == "{")
	{
		c >> kdtree->dim >> kdtree->val;
//		tabs2(cout, depth) << kdtree->dim << " " << kdtree->val<<endl;
		kdtree->left = new Kdtree;		c >> kdtree->left;
		kdtree->right = new Kdtree;		c >> kdtree->right;
		c >> s;			
		depth--;
//		tabs2(cout, depth) << s << endl;
	}
	if (s == "[")
	{
		Point P = {0,0,0};
		while (s!="]") {
			c >> P[0] >>P[1] >> P[2];			
//			tabs2(cout, depth) << P[0] << " " << P[1] << " " << P[2] << endl;
			c >> s;	
			kdtree->Plist.push_front(new Point(P));
			kdtree->Plist.reverse();
		}
		depth--;
//		tabs2(cout, depth) << s << endl;
	}
	return c;
}

ifstream& operator>>(ifstream &c, Points &P) {
	char s1;
	char s2;
	double d;
	Point Pi = {0,0,0};
	while(c >> Pi[0]>>s1>>Pi[1]>>s2>>Pi[2])	{
		//cout << Pi[0] << " "<<s1 << " " << Pi[1] << " " << s2 << " " << Pi[2] << endl;
		P.push_back(Pi);
	}
	return c;
}
