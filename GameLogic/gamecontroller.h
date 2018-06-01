#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QPointer>

#include "gamemodel.h"

namespace Logic {

struct GameController : public QObject
{
  Q_OBJECT

public:
  struct Params
  {
    GameModelMutablePtr game_model_;
    int update_time_ = 100;
    PlayerId current_player_ = 0;
  };

  using QObject::QObject;

public slots:
  virtual void addPattern(PatternTrs pattern_trs) = 0;

signals:
  void stepMade();
};
using GameControllerPtr = QPointer<GameController>;
GameControllerPtr createGameController(QObject* parent, GameController::Params const& params);

} // Logic

#endif // GAMECONTROLLER_H
