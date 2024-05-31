//206917908
//michaeldadush12@gmail.com
//Michael dadush

#include "Graph.hpp"
using std::vector;
using std::string;
using namespace ariel;  

    void Graph::loadGraph(const vector<vector<int>> new_graph) {
    if (new_graph.empty() ) {
        throw std:: invalid_argument("Error in load this grap");
    }

    for(size_t i=0; i<new_graph.size();i++)
    {
      if(new_graph.size() != new_graph[0].size() )
      {
       throw std:: invalid_argument("Error in load this grap");
      }
    }
    size=g.size();
    this->g = new_graph; // Assign the provided adjacency matrix to the graph
    this->graph_symmetric=true;
    this->graph_weighted=false;
        for (size_t i = 0; i < g.size(); i++) {
            for (size_t j = 0; j < g[i].size(); j++) {
              if(g[i][i]!=0)
              {
                throw std::invalid_argument("Error in graph- cant have weight from vertx to himself");
              }
                
                if(g[i][j]!=0 && g[i][j]!=1){
                    this->graph_weighted=true;
                }
                if(g[i][j] != g[j][i]){
                    this->graph_symmetric=false;//graph directed
                }
                if(this->graph_weighted==true && this->graph_symmetric==false){
                    return;
                }
            }
        }

    }


void const Graph::printGraph(){
    int edges=0;
    for (size_t i = 0; i < g.size(); i++) {
        for (size_t j = 0; j < g[i].size(); j++) {
            if(g[i][j] != 0){
                edges++;
            }
          
        }
    }
    if(getSymmetricAdjMat()){
        edges=edges/2;
    }
    std:: cout << "Graph with " << g.size() << " vertices and " << edges << " edges." << std :: endl;
        
    }

    vector <vector<int>> Graph ::getGraph() const{
        return this -> g;
    }
     bool Graph::getSymmetricAdjMat() const{
        return this -> graph_symmetric;

    }
     bool Graph::getWeight() const{
        return this -> graph_weighted;
     
    }


Graph& Graph::operator+=(const Graph& other)
    {
   // Check if graphs have the same dimensions
      if (g.size() != other.getGraph().size() ) {
         throw std::invalid_argument("The graphs must have the same dimensions ");
      }
      if(g[0].size() != other.getGraph()[0].size())
      {
        throw std::invalid_argument("The graphs must have the same dimensions ");
      }
      if(other.getGraph().size()!= other.getGraph()[0].size())//another check if the matrix square
      {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix");
      }

   // addition for corresponding elements in the graphs
   for (size_t i = 0; i < g.size(); ++i) {
      for (size_t j = 0; j < g[0].size(); ++j) {
         g[i][j] = g[i][j] + other.getGraph()[i][j];
      }
   }
    return *this;
    
    }

Graph Graph::operator+(const Graph& other)
    {
   // Check if graphs have the same dimensions
      if (g.size() != other.getGraph().size() ) {
         throw std::invalid_argument("The graphs must have the same dimensions");
      }
      if(g[0].size() != other.getGraph()[0].size()){

        throw std::invalid_argument("The graphs must have the same dimensions");
      }

    // Create a result graph
   Graph result;
   vector<vector<int>> result_graph(g.size(), vector<int>(g[0].size()));

   // addition g that is show of the class and other to result_graph
   for (size_t i = 0; i < g.size(); i++) {
      for (size_t j = 0; j < g[0].size(); j++) {
         result_graph[i][j] = g[i][j] + other.getGraph()[i][j];
      }
   }

    // Load the result graph with the calculated element-wise addition
   result.loadGraph(result_graph);
   return result;
   }

//plus Oneri
Graph& Graph::operator+()
{
 return *this;
}
   
Graph& Graph::operator++( ){
        for (size_t i = 0; i < g.size(); ++i) 
        {
          for (size_t j = 0; j < g[0].size(); ++j) 
          { 
            if(g[i][j]!=0)
            {
              g[i][j] = g[i][j] +1;
            }
          }
        }
         return *this;
    }

//after-increment operator.
   Graph Graph::operator++(int)
   {

    Graph copy = *this;
    ++*this;
    return copy;

     }

Graph Graph::operator*(const Graph& other)
   {
      if (g.size()!= other.getGraph()[0].size()) {
         throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix");
      }

        size_t num_rows = g.size();
        size_t num_cols = other.getGraph()[0].size(); // Assuming consistent number of columns in 'other'
        vector<vector<int>> g2(num_rows, vector<int>(g[0].size()));  

    for (size_t i = 0; i < num_rows; ++i) 
    {
    for (size_t j = 0; j < num_cols; ++j) 
     {
        g2[i][j]=0; // Set all elements to 0 initially
      }
    }

  //matrix multiplication using nested loops
  for (size_t i = 0; i < num_rows; i++) {
    for (size_t j = 0; j < num_cols; j++) {
      for (size_t k = 0; k < num_rows; k++) { // Iterate through intermediate vertices
        g2[i][j]= g2[i][j] + g[i][k] * other.getGraph()[k][j];
        g2[i][i]=0;//Reset the diagonal, because all graphs have no side from the vertex to itself
      }
    }
  }


 // Create a result graph 
  Graph result;
  result.loadGraph(g2);
  return result;
}

Graph& Graph::operator*=(const double scalar)
   {
     for (size_t i = 0; i < g.size(); i++) {
      for (size_t j = 0; j < g[0].size(); j++) {
         g[i][j] =g[i][j]*scalar;
      }
   }
   return *this;
   }

Graph& Graph::operator*=(const Graph& other)
{
   if (g.size()!= other.getGraph()[0].size()) {
         throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix");
      }

        size_t num_rows = g.size();
        size_t num_cols = other.getGraph()[0].size(); // Assuming consistent number of columns in 'other'
        vector<vector<int>> g2(num_rows, vector<int>(g[0].size()));  

    for (size_t i = 0; i < num_rows; ++i) 
    {
    for (size_t j = 0; j < num_cols; ++j) 
     {
        g2[i][j]=0; // Set all elements to 0 initially
      }
    }

  //matrix multiplication using nested loops
  for (size_t i = 0; i < num_rows; i++) {
    for (size_t j = 0; j < num_cols; j++) {
      for (size_t k = 0; k < num_rows; k++) { // Iterate through intermediate vertices
        g2[i][j]= g2[i][j] + this->getGraph()[i][k] * other.getGraph()[k][j];
        this->getGraph()[i][j]=g2[i][j];
        this->getGraph()[i][i]=0;
      }
    }
  }



  return *this;
}


Graph& Graph::operator/=(const double scalar){
if(scalar==0)
{
  throw std::invalid_argument("Cannot divided by 0");
}

    operator*=(1/scalar);
   
   return *this;

}

Graph Graph::operator-(const Graph& other)
 {
   // Check if graphs have the same dimensions
      if (g.size() != other.getGraph().size() ) {
         throw std::invalid_argument("The graphs must have the same dimensions");
      }
      if(g[0].size() != other.getGraph()[0].size()){

       throw std::invalid_argument("The graphs must have the same dimensions");
      }

    // Create a result graph
   Graph result;
   vector<vector<int>> g2(this->getGraph().size(),vector<int>(this->getGraph()[0].size()));

   
   for (size_t i = 0; i < g.size(); ++i) {
      for (size_t j = 0; j < g[0].size(); ++j) 
      {
         g2[i][j] = g[i][j] - other.getGraph()[i][j];
      }
   }
   result.loadGraph(g2);
  return result;
}

Graph& Graph::operator-=(const Graph& other)
    {
   // Check if graphs have the same dimensions
      if (g.size() != other.getGraph().size() ) {
         throw std::invalid_argument("The graphs must have the same dimensions");
      }
      if(g[0].size() != other.getGraph()[0].size()){
        throw std::invalid_argument("The graphs must have the same dimensions");
      }

 
   // Perform element-wise addition for corresponding elements in the graphs
   for (size_t i = 0; i < this->getGraph().size(); i++) {
      for (size_t j = 0; j < this->getGraph()[0].size(); j++) {
         g[i][j] =g[i][j] - other.getGraph()[i][j];
      }
   }
    return *this;
    
    
    
    }

Graph& Graph::operator-()
{
  return *this*=-1;
}  

////after-decrement operator.
Graph& Graph::operator--(){
        for (size_t i = 0; i < g.size(); ++i) 
        {
          for (size_t j = 0; j < g[0].size(); ++j) 
          {  if(g[i][j]!=0)
            {
              g[i][j] = g[i][j] - 1;
            }
          }
        }
         return *this;
    }

Graph Graph::operator--(int)
{ 
  Graph copy = *this;
    --*this;
    return copy;

}
bool Graph::operator==(const Graph& other) const
{
    if (g.size() != other.getGraph().size() || g[0].size() != other.getGraph()[0].size()) 
    {
            return false;
    }
      if(isSub(getGraph(),other.getGraph())&&isSub(other.getGraph(),getGraph()))
      {
        return true;
      }
      
      return false;
    }

bool Graph::operator!=(const Graph& other) const
{
  if(*this==other)
  {
    return false;
  }
  return true;
}

size_t Graph::Edges_counter() const
 {
        size_t count = 0;
        bool sysmatric=true;
        for (size_t i = 0; i < g.size(); ++i) {
            for (size_t j = 0; j < g[0].size(); ++j) {
                if (g[i][j]!=0)
                {
                    count++;
                    if(g[i][j]!=g[j][i])
                    {
                      sysmatric=false;
                    }
                }
            }
        }
        if(sysmatric)
        {
          count=count/2;
        }
        return count;
    }


bool Graph::operator<=(const Graph& other) const{
 if((*this<other)||( *this==other))
 {
  return true;
 }
  return false;
}

bool Graph::operator>=(const Graph& other) const{
  if((*this>other)||( *this==other))
  {
    return true;
  }
  return false;
}

bool Graph::operator>(const Graph& other) const
{

if (!(*this<=other)) {
      return true;
}
return false;
}

bool Graph::isSub(const vector<vector<int>>& A, const vector<vector<int>>& B) const
{
    size_t n = A.size();
    size_t m = B.size();

    if (n > m) {
        return false; // A cannot be contained in B if A is larger
    }

    // Iterate through each possible position in B to place the top-left corner of A
    for (size_t i = 0; i <= m - n; ++i) {
    for (size_t j = 0; j <= m - n; ++j) {
        bool match = true;
        // Check if A matches B at position (i, j)
        for (size_t u = 0; u < n && match; ++u) {
            for (size_t v = 0; v < n && match; ++v) {
                if (A[u][v] != 0 && A[u][v] != B[i + u][j + v]) {
                    match = false;
                }
            }
        }
            if (match) {
                return true;
            }
        }
    }

    return false;
}

bool Graph::operator<(const Graph& other) const {
if(isSub(other.getGraph(),getGraph()))
{
  return false;
}

if(isSub(getGraph(),other.getGraph()))
{
  return true;
}


// Compare the number of edges
size_t CountG1 = this->Edges_counter();
size_t CountG2 = other.Edges_counter();
if (CountG2 > CountG1) {
                return true;
            } 
              else if (CountG2 == CountG1) 
              {
                 // Compare the order of magnitude of the representative matrix
                  if (other.getGraph().size() > getGraph().size()) 
                  {
                     return true;
                  }
              }
        return false;
    }


 