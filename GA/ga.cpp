#include "ga.h"
#include <QDebug>

GA::GA(Color color) :
    _api(nullptr), _color(color), _first(false)
{
    _api = new ChessAPI();
    _first = _color == Color::White ? true : false;
}

GA::~GA() { delete _api; }

Color GA::color() { return _color; }

MoveList GA::move(Move from, Move to) {
    qDebug() << "GA move in GA\n";
    if (_first) return generateMove();
    if (_api->attack(from, to) || _api->move(from, to) || _api->castle(from, to)) return generateMove();
    else return {};
}

MoveList GA::generateMove() {
    _first = false;
    qDebug() << "GA generateMove: ";
    if (_color != _api->getColor()) return {};
    qDebug() << "GA generateMove after return{}\n";
    MoveList moveList;

    for (auto i = STARTFIELD; i <= ENDFIELD; i++) {
        for (auto j = STARTFIELD; j <= ENDFIELD; j++) {
            if (_api->getAttackList({i, j}).size()) {
                moveList.push_back({i, j});
                moveList.push_back(_api->getAttackList({i, j})[0]);
                if (!_api->move(moveList[0], moveList[1]))
                    _api->attack(moveList[0], moveList[1]);
                return moveList;
            }
            if (_api->getMoveList({i, j}).size()) {
                moveList.push_back({i, j});
                moveList.push_back(_api->getMoveList({i, j})[0]);
                if (!_api->move(moveList[0], moveList[1]))
                    _api->attack(moveList[0], moveList[1]);
                return moveList;
            }
        }
    }
    return moveList;
}