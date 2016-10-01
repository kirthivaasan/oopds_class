#include "graph.h"
#include <iostream>
using namespace std;

int main() {
	kirthi::graph<string> test_graph;
	test_graph.addNode("a");
	test_graph.addEdge("a", "b");
	test_graph.addEdge("c", "a");
	test_graph.addEdge("a", "d");
	test_graph.addEdge("d", "c");
	
	test_graph.print();
	
	cout << endl << endl;
	
	if (test_graph.isConnected("a", "c")) {
		cout << "a connected to c" << endl;
	} else {
		cout << "not connected" << endl;
	}
	/*
	test_graph.removeEdge("a", "kirthi");
	cout << endl << "After removing edge a -> kirthi" << endl << endl;
	test_graph.print();
	
	test_graph.removeNode("a");
	cout << endl << "After removing node a" << endl << endl;
	test_graph.print();
	*/
	
	
}