#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <memory>
#include <QSharedPointer>
#include <QPoint>
#include <QSet>
#include <QVector>
#include <QMatrix>

namespace Logic {

using Points = QVector<QPoint>;
using SizeT = int;

struct Pattern
{
  virtual ~Pattern() = default;
  virtual QString name() const = 0;
  virtual Points const& points() const = 0;
  virtual QPoint size() const = 0;
  virtual SizeT scores() const = 0;
};
using PatternPtr = QSharedPointer<Pattern const>;
using PatternTrs = QPair<PatternPtr, QMatrix>;

struct Patterns
{
  virtual ~Patterns() = default;
  virtual SizeT patternCount() const = 0;
  virtual PatternPtr patternAt(SizeT idx) const = 0;
};
using PatternsPtr = QSharedPointer<Patterns const>;

using LifeUnit = QPoint;
using LifeUnits = QSet<LifeUnit>;

struct GameModel
{
  struct Params
  {
    QPoint cells_;
  };

  virtual ~GameModel() = default;
  virtual QPoint cells() const = 0;
  virtual PatternsPtr const& allPatterns() const = 0;
  virtual LifeUnits const& lifeUnits() const = 0;

  virtual void addUnit(LifeUnit const& life_unit) = 0;
  virtual void makeStep() = 0;
};
using GameModelPtr = QSharedPointer<GameModel const>;
using GameModelMutablePtr = QSharedPointer<GameModel>;
GameModelMutablePtr createGameModel(GameModel::Params const& params);

} // Logic

#endif // GAMEMODEL_H