//206917908
//michaeldadush12@gmail.com
//Michael dadush

#include <vector>
#include <iostream>
#include <string>
#pragma once
using std::vector;
using std::string;
using std::ostream;

namespace ariel{
 class Graph
 {
    private:
    vector<vector<int> > g;
    int size;
    bool graph_weighted;//undirected graph==true
    bool graph_symmetric;
   
    
    public:
    void  loadGraph (const vector<vector<int> >);
    void const printGraph();
    vector<vector<int> > getGraph() const ;
    bool getSymmetricAdjMat() const;
    bool getWeight() const;
    size_t countEdges() const ;
   Graph& operator*=(const double scalar);
    Graph& operator*=(const Graph& other);
   Graph& operator+=(const Graph& other);
   Graph operator+(const Graph& other);
   Graph& operator+();
   Graph operator*(const Graph& other);
   Graph& operator/=(const double scalar);
   Graph operator-(const Graph& other);
   Graph& operator-();
   Graph& operator-=(const Graph& other);
   Graph& operator++();
   Graph operator++(int);
   Graph& operator--();
   Graph operator--(int);

   bool isSubmatrix(const vector<vector<int>>& A, const vector<vector<int>>& B)const ;
   bool operator==(const Graph& other) const;
   bool operator!=(const Graph& other) const;
   bool operator<(const Graph& other) const;
   bool operator<=(const Graph& other) const;
   bool operator>(const Graph& other) const;
   bool operator>=(const Graph& other) const;
   
   friend std::ostream& operator<<(std::ostream& os,const Graph& g1)
   {
        
        for (size_t i = 0; i < g1.getGraph().size(); ++i) 
        {
            os << "[";
            for (size_t j = 0; j < g1.getGraph()[i].size(); ++j)
             {
                os << g1.getGraph()[i][j];
                if (j < g1.getGraph()[i].size() - 1) {
                    os << ", ";
                }
            }
            os << "]";
            if (i < g1.getGraph().size() - 1) {
                os << ", ";
            }
        }
        os<<std::endl;
        return os;
    }   
   
 };
};


