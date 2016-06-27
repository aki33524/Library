#include "template.cpp"

using Weight = int;
using Capacity = int;
struct Edge {
    int src, dst; Weight weight;
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;
