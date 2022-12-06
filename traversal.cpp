#include "Node.h"


// ----------------------traversal---------------------------------
template <class T>
auto Node<T>::traverse(Point& Q)
{
	int k = dim;

	if (isLeafNode())		// Leaf nodes
		return nearestLeafPoint(Q, Plist);

	Node<T>* nearRegion, * farRegion;
	getNearfarRegions(nearRegion, farRegion, Q);

	auto candidatePoint1 = nearRegion->traverse(Q);
	if (stop_search(*candidatePoint1, Q, k, val))
		return candidatePoint1;

	auto candidatePoint2 = farRegion->traverse(Q); //check out region
	return nearestPointFrom(Q, candidatePoint1, candidatePoint2);
}

template <typename T>
auto Node<T>::traverse(Point& Q, void (*f)())  
{

	int k = dim;
	f();

	if (isLeafNode())		// Leaf nodes
		return nearestLeafPoint(Q, Plist);

	Node *nearRegion, *farRegion;
	getNearfarRegions(nearRegion, farRegion, Q);

	auto candidatePoint1 = nearRegion->traverse(Q,f);
	if (stop_search(*candidatePoint1, Q, k, val))
	{
//		cout << endl << "stop search"<<endl;
		return candidatePoint1;
	}
	auto candidatePoint2 = farRegion->traverse(Q,f); //check out region
	return nearestPointFrom(Q, candidatePoint1, candidatePoint2);
}
template<typename T>
bool Node<T>::stop_search(Point& candidatePoint, Point& target, int& k, T& split){

	//cout << "val = " << val << "\tk = " << k << "\tsplit="<<split << endl;
	//cout << "target Point = " << target[0] << "," << target[1] << "," << target[2] << endl;
	//cout << "candidate Point = "<< candidatePoint[0] << "," << candidatePoint[1] << "," << candidatePoint[2] << endl;
	auto r_target_to_candidate_point = dist(target, candidatePoint);
	auto r_target_to_farRegion = (split - target[k]) * (split - target[k]);
	//cout << "distance target point to candidate point = " << r_target_to_candidate_point << endl;
	//cout << "distance target point to farRegion = " << r_target_to_farRegion << endl;

	return r_target_to_candidate_point < r_target_to_farRegion ? true : false;
}

template <typename T>
void Node<T>::getNearfarRegions(Node*& nearRegion, Node*& farRegion,Point& Q) {
	auto k = dim;
	auto val1 = val;

	if (Q[k] < val) { nearRegion = left;					farRegion = right; }
	else			{ nearRegion = right;					farRegion = left;  }
}




//void buildTree(Node* kdtree, int k, int n)
//{
//	if (kdtree == nullptr) 	return;

//	auto median = GetMedian(kdtree->P, k , n);
//	auto curr = kdtree;			auto val = median->P[k];
//	auto right = kdtree;		int nRight = 0;
//	auto left = kdtree;			int nLeft = n - 1;

//	while (curr != nullptr) {
//		if (val > curr->P[k]) {

//			if (right == kdtree) 	right->right = curr;
//			else 					right->left  = curr;

//			left->left = curr->left;
//			curr->left = nullptr;

//			right = curr;
//			nRight++;

//		}
//		else {
//			left = curr;
//		}

//		curr = curr->left;
//	}

//	nLeft = nLeft - nRight;

//	buildTree(kdtree->left , k + 1 , nLeft);
//	buildTree(kdtree->right, k + 1 , nRight);
//}
