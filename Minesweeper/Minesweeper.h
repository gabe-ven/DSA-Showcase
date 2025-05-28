#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <Malena/common.hpp>
#include "Model.h"
#include "Backtracking.h"
#include "Malena/Utilities/TextureSlicer.h"

class Minesweeper : public ml::Application {
  Model* model;
  sf::Texture texture;
  Backtracking* backtracking;
  std::vector<ml::Rectangle> tiles;
  ml::ImageRects rects;
  sf::Clock clock;

  std::vector<std::vector<std::vector<char>>> backtrackSteps;

  int rows, cols, bombs;
  int currentStep;
  float delay;

  void update();

public:
  Minesweeper(int rows, int cols, int bombs);

  void initialization() override;
  void registerEvents() override;
  void createTiles(const std::vector<std::vector<char>>& board);
  void refreshBoard(const std::vector<std::vector<char>>& board);
};

#endif // MINESWEEPER_H
