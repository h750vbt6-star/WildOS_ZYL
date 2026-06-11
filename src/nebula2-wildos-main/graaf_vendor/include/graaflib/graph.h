#pragma once

#include <cstddef>
#include <map>
#include <stdexcept>
#include <unordered_map>

namespace graaf
{

using vertex_id_t = std::size_t;

template <typename VertexT, typename WeightT>
class undirected_graph
{
public:
  using vertex_type = VertexT;
  using weight_type = WeightT;
  using edge_map = std::unordered_map<vertex_id_t, WeightT>;

  undirected_graph() = default;

  void add_vertex(const VertexT& vertex, vertex_id_t id)
  {
    vertices_[id] = vertex;
    adjacency_.try_emplace(id);
    if (id >= next_vertex_id_)
    {
      next_vertex_id_ = id + 1;
    }
  }

  vertex_id_t add_vertex(const VertexT& vertex)
  {
    const vertex_id_t id = next_vertex_id_;
    add_vertex(vertex, id);
    return id;
  }

  bool has_vertex(vertex_id_t id) const
  {
    return vertices_.find(id) != vertices_.end();
  }

  void add_edge(vertex_id_t from, vertex_id_t to, const WeightT& weight)
  {
    if (!has_vertex(from) || !has_vertex(to))
    {
      throw std::out_of_range("Cannot add an edge with a missing vertex");
    }

    adjacency_[from][to] = weight;
    adjacency_[to][from] = weight;
  }

  void remove_vertex(vertex_id_t id)
  {
    vertices_.erase(id);
    adjacency_.erase(id);

    for (auto& adjacency_entry : adjacency_)
    {
      adjacency_entry.second.erase(id);
    }
  }

  const std::map<vertex_id_t, VertexT>& get_vertices() const
  {
    return vertices_;
  }

  const VertexT& get_vertex(vertex_id_t id) const
  {
    return vertices_.at(id);
  }

  VertexT& get_vertex(vertex_id_t id)
  {
    return vertices_.at(id);
  }

  const edge_map& get_edges(vertex_id_t id) const
  {
    static const edge_map empty_edges;
    const auto edge_it = adjacency_.find(id);
    if (edge_it == adjacency_.end())
    {
      return empty_edges;
    }
    return edge_it->second;
  }

private:
  std::map<vertex_id_t, VertexT> vertices_;
  std::unordered_map<vertex_id_t, edge_map> adjacency_;
  vertex_id_t next_vertex_id_ = 0;
};

}  // namespace graaf
