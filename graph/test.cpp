#include "graph.h"

int main() {
	kirthi::graph<int> test_graph;
	test_graph.addEdge(0);
	test_graph.addEdge(1, 2);
	test_graph.addEdge(1, 4);
	test_graph.addEdge(2, 3);
	test_graph.addEdge(500, 6);
	test_graph.addEdge(500, 900);
	test_graph.addEdge(3, 0);
	test_graph.addEdge(4, 2);
	test_graph.addEdge(5);
	
	test_graph.print();
}