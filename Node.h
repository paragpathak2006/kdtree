#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <forward_list>
#include <queue>
using namespace std;

/* File Handling with C++ using ifstream & ofstream class object*/
/* To write the Content in File*/
/* Then to read the content of file*/
/* fstream header file for ifstream, ofstream,
fstream classes */


template <class T>
class Node
{
public:

	typedef vector<T> Point;
	typedef vector<Point> Points;

	Node* left = nullptr;
	Node* right = nullptr;
	int dim = -1;
	T val = 0;
	forward_list<Point*> Plist;
	~Node() {}  // memory leaks issues
	Node() {};
	Node(Points& P) {		intializeNode(P);		buildTree(P.size());	}
	Node(Node& N) {		copytree(N, this);	}

	void copytree(Node& original, Node* copy)	{
		*copy = original;

		if (original.isLeafNode())
			return;

		copy->left  = new Node;
		copy->right = new Node;

		copytree(original, copy->left);
		copytree(original, copy->right);
	}


	// ---------------intialize------------------------------------------------
	void intializeNode(Points& P);
	void buildTree(int n);

	// ---------------helper------------------------------------------------

	int getK(int n);

	auto GetMedian(int k, int n, bool lowermedian);
	bool isLeafNode();

	// ---------------helper-distances------------------------------------------------
	T dist(Point& P, Point& Q);
	auto nearestPointFrom(Point& Q, Point* A, Point* B);
	auto nearestLeafPoint(Point& Q, forward_list<Point*>& Plist);

	// ----------------------traversal---------------------------------
	auto traverse(Point& Q);
	auto traverse(Point& Q, void (*ptr)());

	bool stop_search(Point& candidatePoint, Point& target, int& k, T& split);
	void getNearfarRegions(Node*& nearRegion, Node*& farRegion, Point& Q);

	// ----------------------read write---------------------------------

	void writeDFSTree(ofstream &fout);
	void readDFSTree(ifstream &fin);
	void readPoints(ifstream& fin, Points& P);

};

