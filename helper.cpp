#include "Node.h"

	// ---------------initialize------------------------------------------------
template <typename T>
bool Node<T>::isLeafNode() {
		return left == nullptr && right == nullptr;
	}

template <typename T>
int Node<T>::getK(int n){		
			Point Pmax = {-1000,-1000,-1000 }, Pmin = { 1000,1000,1000 };
			int ksize = Pmax.size(),kmax;

			for (Point* P : Plist) {
				for (int k = 0;k < ksize;k++) {
					Pmax[k] = max(Pmax[k], P->at(k));
					Pmin[k] = min(Pmin[k], P->at(k));
				}
			}

			auto maxRange = Pmax[0] - Pmax[0];
			for (int k = 0;k < ksize;k++) {
				if (maxRange < abs(Pmax[k] - Pmin[k])) {
					maxRange = abs(Pmax[k] - Pmin[k]);
					kmax = k;
				}
			}
			return kmax;
}

template <typename T>
auto Node<T>::GetMedian(int k, int n,bool lowermedian) {

		if (n % 2 == 0 && lowermedian) n--;

		Plist.sort([&k](Point* a, Point* b) {return ((*a)[k] < (*b)[k]);});

		int i = 0;
		for (auto it = Plist.begin(); it != Plist.end(); it++, i++)
			if (i >= n / 2)	return *it;

		return new Point({ 0,0,0 });
	}

template <typename T>
auto Node<T>::nearestPointFrom(Point& Q, Point* A, Point* B) {
		if (A == nullptr) return B;
		if (B == nullptr) return A;
		return dist(Q, *A) < dist(Q, *B) ? A : B;
}


template <typename T>
auto Node<T>::nearestLeafPoint(Point& Q, forward_list<Point*>& Plist) {
		auto it1 = Plist.begin();		
		auto P1 = *it1;
		it1++;

		if (it1 == Plist.end()) 
			return P1;

		auto P2 = *it1;
		return nearestPointFrom(Q, P1, P2);
}

template <typename T>
T Node<T>::dist(Point& P, Point& Q) {
		T sum = 0;
		for (size_t i = 0; i < P.size(); i++)	
			sum += (P[i] - Q[i])* (P[i] - Q[i]);
		return sum;
}


	//struct MyIterator
	//{
	//public:
	//	// Iterator tags here...
	//	using iterator_category = std::forward_iterator_tag;
	//	using difference_type = std::ptrdiff_t;
	//	using value_type = Node;
	//	using pointer = Node*;  // or also value_type*
	//	using reference = Node&;  // or also value_type&

	//private:

	//	pointer nodeptr;

	//public:
	//	// Iterator constructors here...
	//	MyIterator(pointer ptr) : nodeptr(ptr) {}

	//	reference operator*() const { return *nodeptr; }
	//	pointer operator->() { return nodeptr; }

	//	// Prefix increment
	//	MyIterator& operator++() { (this)->nodeptr = (*this)->left; return *this; }

	//	// Postfix increment
	//	MyIterator operator++(int) { MyIterator tmp = *this; (this)->nodeptr = (*this)->left; return tmp; }

	//	friend bool operator== (const MyIterator& a, const MyIterator& b) { return a.nodeptr == b.nodeptr; };
	//	friend bool operator!= (const MyIterator& a, const MyIterator& b) { return a.nodeptr != b.nodeptr; };

	//};

	//MyIterator begin() { return MyIterator(this); }
	//MyIterator end() { return MyIterator(nullptr); } 


	//sort(list.begin(), list.end());

