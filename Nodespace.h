#pragma once
#include "Node.h"
namespace Nodedouble {
	typedef Node<double> Kdtree;
	typedef Kdtree::Point Point;
	typedef Kdtree::Points Points;

	typedef numeric_limits<double> db;
	typedef vector<int> Index;
}
