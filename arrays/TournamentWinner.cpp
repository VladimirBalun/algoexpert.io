// O(n) time / O(k) space
std::string tournamentWinner(
  std::vector<std::vector<std::string>> competitions, std::vector<int> results
) {
  std::string best_team;
  std::unordered_map<std::string, int> team_points;
  for (int idx = 0; idx < competitions.size(); ++idx) {
    const auto& competition = competitions[idx];
    const int winner_idx = results[idx];
    const std::string& winning_team = competition[!winner_idx];
    team_points[winning_team] += 3;

    if (team_points[winning_team] > team_points[best_team])
      best_team = winning_team;
  }

  return best_team;
}