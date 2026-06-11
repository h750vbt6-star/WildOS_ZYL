#pragma once

#include <algorithm>
#include <limits>
#include <optional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

#include <graaflib/graph.h>

namespace graaf::algorithm
{

struct shortest_path_result
{
  std::vector<vertex_id_t> vertices;
  double distance = 0.0;
};

template <typename VertexT, typename WeightT>
std::optional<shortest_path_result> dijkstra_shortest_path(
  const undirected_graph<VertexT, WeightT>& graph, vertex_id_t start, vertex_id_t goal)
{
  using QueueItem = std::pair<double, vertex_id_t>;

  if (!graph.has_vertex(start) || !graph.has_vertex(goal))
  {
    return std::nullopt;
  }

  std::priority_queue<QueueItem, std::vector<QueueItem>, std::greater<QueueItem>> queue;
  std::unordered_map<vertex_id_t, double> distances;
  std::unordered_map<vertex_id_t, vertex_id_t> previous;

  for (const auto& vertex_entry : graph.get_vertices())
  {
    distances[vertex_entry.first] = std::numeric_limits<double>::infinity();
  }

  distances[start] = 0.0;
  queue.emplace(0.0, start);

  while (!queue.empty())
  {
    const auto [current_distance, current_id] = queue.top();
    queue.pop();

    if (current_distance > distances[current_id])
    {
      continue;
    }

    if (current_id == goal)
    {
      break;
    }

    for (const auto& edge_entry : graph.get_edges(current_id))
    {
      const vertex_id_t neighbor_id = edge_entry.first;
      const double edge_cost = static_cast<double>(edge_entry.second);
      const double candidate_distance = current_distance + edge_cost;

      if (candidate_distance < distances[neighbor_id])
      {
        distances[neighbor_id] = candidate_distance;
        previous[neighbor_id] = current_id;
        queue.emplace(candidate_distance, neighbor_id);
      }
    }
  }

  if (distances[goal] == std::numeric_limits<double>::infinity())
  {
    return std::nullopt;
  }

  shortest_path_result result;
  result.distance = distances[goal];

  for (vertex_id_t id = goal;; id = previous[id])
  {
    result.vertices.push_back(id);
    if (id == start)
    {
      break;
    }
  }

  std::reverse(result.vertices.begin(), result.vertices.end());
  return result;
}

}  // namespace graaf::algorithm
