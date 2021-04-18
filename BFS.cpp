#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::unordered_map;

class Graph{
	private:
		int V;
		//pointer to adjacencly list
		unordered_map<char,list<char>> adj;
	
	public:
		Graph(int v);
		void addEdge(char v , char w);
		unordered_map<char,list<char>>getMap();
		unordered_map<char,int> BFS(char s);
};

Graph::Graph(int v){
	V = v;
}

void Graph::addEdge(char v,char w){ 
	adj[v].push_back(w); 
};

//getter of the adjacency list
unordered_map<char,list<char>>Graph::getMap(){
	return adj;
}

//BFS search in graph
unordered_map<char,int> Graph::BFS(char s){
	//map of vertex and bool - to keep track of visited nodes
	//queue of vertices
	//level of the vertices
	unordered_map<char,int> level;
	int lvl = 1;
	for(auto &i : adj){
		level[i.first] = 0;
	}
	list<char> vList;
	vList.push_back(s);
	while(!vList.empty()){
		char s = vList.front();
		vList.pop_front();
		for(auto &i : adj[s]){
			//if the vertex is not visited ie level = 0
			if(level[i] == 0){
				level[i] = lvl;
				vList.push_back(i);
			}	
		}
		lvl++;
	}
	return level;
}

template <typename T, typename U>
void showAdjList(Graph &p){
	unordered_map<T,list<U>> mp = p.getMap();
	for(auto &i : mp){
		cout<<i.first<<"-> ";
		for(auto &j : mp[i.first]){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}


int main(int argc, char **argv){
	Graph g(3);
	g.addEdge('a','b');
	g.addEdge('a','c');
	g.addEdge('b','d');
	g.addEdge('b','e');
	g.addEdge('c','e');

	showAdjList<char,char>(g);
	unordered_map<char,int> bl = g.BFS('a');

	cout<<endl<<endl;
	for(auto &i : bl){
		cout<<i.first<<"-> "<<i.second<<endl;
	}
	return 0;
}
