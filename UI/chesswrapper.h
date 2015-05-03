#ifndef CHESSWRAPPER_H
#define CHESSWRAPPER_H

#include "../chess/chessapi.h"

#include <QObject>

class ChessWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int pos READ pos WRITE setPos NOTIFY posChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)

    Q_PROPERTY(int moveFrom READ moveFrom WRITE setMoveFrom NOTIFY moveFromChanged)
    Q_PROPERTY(int moveTo READ moveTo WRITE setMoveTo NOTIFY moveToChanged)

    Q_PROPERTY(QList<int> moveList READ moveList WRITE setMoveList NOTIFY moveListChanged)
    Q_PROPERTY(QList<int> attackList READ attackList WRITE setAttackList NOTIFY attackListChanged)
    public:
        explicit ChessWrapper(QObject *parent = 0);
        ~ChessWrapper();

        int pos();
        void setPos(int pos);

        int moveTo();
        void setMoveTo(int to);

        int moveFrom();
        void setMoveFrom(int from);

        QString color();
        void setColor(QString color);

        QString type();
        void setType(QString type);

        QList<int> moveList();
        void setMoveList(QList<int> moveList);

        QList<int> attackList();
        void setAttackList(QList<int> attackList);

    signals:
        void posChanged();
        void moveToChanged();
        void moveFromChanged();
        void colorChanged();
        void typeChanged();
        void moveListChanged();
        void attackListChanged();

    public slots:


    private:
        ChessAPI *_api;
        int _pos;
        QString _type;
        QString _color;
        int _moveFrom;
};

#endif // CHESSWRAPPER_H
