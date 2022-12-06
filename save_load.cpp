#include "Node.h"

// ----------------------save---------------------------------

#include <fstream>
#include <string>
#include <stdio.h>

template <typename T>
void Node<T>::writeDFSTree(ofstream& fout)
{
	// Creation of ofstream class object
	if (isLeafNode()) {
		auto it1 = Plist.begin();		auto it2 = it1++;
		if (it2 == Plist.end())	{		cout << -1 << *it1;		return;		}
		cout << -2 <<	*it1 << *it2;	return;
	}
	cout << dim << val<<0<<0<<0;	writeDFSTree(fout);	writeDFSTree(fout);
}
template <typename T>
void Node<T>::readDFSTree(ifstream& fin)
{
	// Creation of ifstream class object to read the file
	int k, val1;		Point P = {0,0,0};

	fin >> k >> val1 >> P[0] >> P[1] >> P[2];

	if (k == -3) {										return;	}
	if (k == -1) {	Plist.push_front(new Point(P));		return;	}
	if (k == -2) {	Plist.push_front(new Point(P));		fin >> k >> val1 >> P[0] >> P[1] >> P[2];		Plist.push_front(new Point(P));		return;	}

	left  = new Node;	 left->readDFSTree(fin);		dim = k;
	right = new Node;	right->readDFSTree(fin);		val = val1;
	
}
template <typename T>
void Node<T>::readPoints(ifstream& fin,Points& P)
{
	int i = 0;
	Point Pin;
	P.reserve(1000);

	while (fin)	{
		fin >> Pin[0] >> Pin[1] >> Pin[2];
		P.push_back(Pin);
	}

}

//void readline(ifstream &fin,int &k, int& val, Point& P){
//	// Returns first token
//	// Read a Line from File
//	string line, token;
//	getline(fin, line);
//	fin >> k >> val >> P[0] >> P[1] >> P[2];
//	//auto line2 = const_cast<char*>(line.c_str());
//	//token = strtok(line2, " ");	k = stoi(token);
//	//token = strtok(NULL, " ");	val = stoi(token);
//
//	//token = strtok(NULL, " ");	P[0] = stof(token);
//	//token = strtok(NULL, " ");	P[1] = stof(token);
//	//token = strtok(NULL, " ");	P[2] = stof(token);
//
//}

//void readfile(ifstream& fin, vector<int>& dim, vector<int>& val, Points& P)
//{
//	// Execute a loop until EOF (End of File)
//	int i = 0, n = 0, n1; Point P1;
//	readline(fin, n, n1, P1);
//	dim.resize(n);
//	val.resize(n);
//	P.resize(n, { 0,0,0 });
//	while (fin) {
//		readline(fin, dim[i], val[i], P[i]);
//		i++;
//	}
//}
//
//Point* Node::BFS(Node* kdtree)
//{
//	deque<Node*> q;
//	int pow2 = 1, n = 0;
//	bool renew = false;
//	while (true)
//	{
//		n++;
//		if (q.front() != nullptr)
//		{
//
//			q.push_back(q.front()->left);
//			q.push_back(q.front()->right);
//			q.pop_front();
//
//			if (q.front()->left != nullptr || q.front()->left != nullptr)
//				renew = true;
//		}
//
//		if (n == pow2) {
//			pow2 = pow2 * 2;
//			if (renew)	renew = false;
//			else		break;
//		}
//
//	}
//
//}
