#ifndef _GRAPH_H
#define _GRAPH_H
#include <string>
class Graph
{
public:
	int**arr;
	int row=0;
	std::string send_name="";
	void LoadMatrix(const std::string& filename); 
	void PrintMatrix(); 
	int GetSize();
	void PrintShortestPathWeight(int s);
	void PrintShortestPath(int s);  
};
#endif
