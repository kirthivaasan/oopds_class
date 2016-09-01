#include "graph.h"
#include <iostream>
using namespace std;

int main() {
	kirthi::graph<string> test_graph;
	test_graph.addNode("mau");
	test_graph.addEdge("mau", "haf");
	test_graph.addEdge("mingda", "mau");
	test_graph.addEdge("mau", "kirthi");
	test_graph.addEdge("kirthi", "mingda");
	
	test_graph.print();
	
	test_graph.removeEdge("mau", "kirthi");
	cout << endl << "After removing edge mau -> kirthi" << endl << endl;
	test_graph.print();
	
	test_graph.removeNode("mau");
	cout << endl << "After removing node mau" << endl << endl;
	test_graph.print();
}