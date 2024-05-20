//206917908
//michaeldadush12@gmail.com
//Michael dadush

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using std::vector;


TEST_CASE("Count edges") {
    ariel:: Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {4, 0, 3},
        {7, 1, 0}
    };
    g1.loadGraph(graph1);
    CHECK(g1.countEdges() == 6);

     ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 5, 1},
        {5, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);
    CHECK(g2.countEdges() == 3);
    
      ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    g3.loadGraph(graph3);
    CHECK(g3.countEdges() == 0);
    

}

TEST_CASE("Scalar *") {
     ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);
    g1 *= 4;
    vector<vector<int>> result = {
        {0, 4, 0},
        {4, 0, 4},
        {0, 4, 0}
    };
    CHECK(g1.getGraph() == result);
     
     g1 *= 0;
    vector<vector<int>> result2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    CHECK(g1.getGraph() == result2);
}

TEST_CASE("Graph *") {
     ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);

     ariel::Graph g3;
    vector<vector<int>> expectedResult = {
        {0, 0, 3},
        {1, 0, 1},
        {2, 0, 0}
    };
    g3 = g1 * g2;
    CHECK(g3.getGraph() == expectedResult);
    
    ariel::Graph g4;
      vector<vector<int>> graph4 = {
        {0, 0},
        {1, 0}, 
    };
    g4.loadGraph(graph4);

    CHECK_THROWS(g3=g3*g4);
    

}

TEST_CASE("Graph +") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);

     ariel::Graph g3;
    vector<vector<int>> expectedResult = {
        {0, 3, 1},
        {3, 0, 4},
        {1, 4, 0}
    };
    g3 = g1 + g2;
    CHECK(g3.getGraph() == expectedResult);
}

TEST_CASE("Graph +=") {
     ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, -1, 0},
        {1, 0, 1},
        {0, -1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);

    g1 += g2;
    vector<vector<int>> expectedResult = {
        {0, 1, 1},
        {3, 0, 4},
        {1, 2, 0}
    };
    CHECK(g1.getGraph() == expectedResult);
    
    
    vector<vector<int>> graph3 = {
        {0, 2, 1,4},
        {2, 0, 3,5},
        {1, 3, 0,6},
        {12, 7, 0,1}
    };
    ariel::Graph g3;
    g3.loadGraph(graph3);

    CHECK_THROWS(g1 += g3);
}

TEST_CASE("Graph =") {
     ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);

     ariel::Graph g3;
    vector<vector<int>> expectedResult = {
        {0, -1, -1},
        {-1, 0, -2},
        {-1, -2, 0}
    };
    g3 = g1 - g2;
    CHECK(g3.getGraph() == expectedResult);
}

TEST_CASE("Graph -=") {
     ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);

    g1 -= g2;
    vector<vector<int>> expectedResult = {
        {0, -1, -1},
        {-1, 0, -2},
        {-1, -2, 0}
    };
    CHECK(g1.getGraph() == expectedResult);
}

TEST_CASE("Graph ++ and --") {
     ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ++g1;
    vector<vector<int>> incrementResult = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    CHECK(g1.getGraph() == incrementResult);

    --g1;
    CHECK(g1.getGraph() == graph1);
    
}

TEST_CASE("Graph /") {
     ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    g1 /= 2;
    vector<vector<int>> divisionResult = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    CHECK(g1.getGraph() == divisionResult);
    CHECK_THROWS(g1/=0);

}

TEST_CASE("Submatrix check") {
     ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    vector<vector<int>> submatrix = {
        {0, 1},
        {1, 0}
    };
    CHECK(g1.isSubmatrix(submatrix,graph1) == true);
    CHECK(g1.isSubmatrix(graph1, submatrix) == false);


    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2},
        {3, 0},
        
    };

    g2.loadGraph(graph2);
    vector<vector<int>> submatrix2 = {
        {0, 2},
        {0, 0}
    };
    CHECK(g2.isSubmatrix(submatrix2,graph2) == true);


}

TEST_CASE("== and !=") {
     ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    g2.loadGraph(graph1);
    CHECK(g1 == g2);
    CHECK_FALSE(g1 != g2);

     ariel::Graph g3;
    vector<vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g3.loadGraph(graph2);
    CHECK(g1 != g3);
    CHECK_FALSE(g1 == g3);
}

TEST_CASE("=>, <= , < , > ") {
     ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

     ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g2.loadGraph(graph2);

      ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1},
        {1, 0}
        
    };
    g3.loadGraph(graph3);

    CHECK(g1 < g2);
    CHECK(g1 <= g2);
    CHECK_FALSE(g1 > g2);
    CHECK(g2 >= g1);
    CHECK_FALSE(g2 < g1);
    CHECK(g1>g3);
    CHECK_FALSE(g1<=g3);

    
}