#include "Node.h"
template <typename T>
void Node<T>::intializeNode( Points& P) {
	for (size_t i = 0; i < P.size(); i++)
		Plist.push_front(&P[i]);
}

template <typename T>
void Node<T>::buildTree(int n)
{
	#define UPPER_MEDIAN false
	#define LOWER_MEDIAN true

	if (n <= 2) 	return;
	dim = getK(n);										right = new Node<T>;
	val = GetMedian(dim, n, LOWER_MEDIAN)->at(dim);		 left = new Node<T>;

	int k = dim, nLeft = n, nRight = 0, i = 0 , split = (n+1)/2;

	while (!Plist.empty()) {
		auto Pk = Plist.front()->at(k);
		i++;
		if (i > split){
			right->Plist.push_front(Plist.front());
			nRight++;
		}
		else {		 
			left->Plist.push_front(Plist.front());		
		}
		Plist.pop_front();
	}

	nLeft = n - nRight;
	 left->buildTree(nLeft);
	right->buildTree(nRight);
}
