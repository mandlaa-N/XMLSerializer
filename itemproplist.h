
//   Program Module: ItemPropList Class header file
//
//   PURPOSE: Defines the API or interface for this class
//
//   COMMENTS: represents a list of item properties

#ifndef ITEMPROPLIST_H
#define ITEMPROPLIST_H

#include <QList>
#include <QObject>
#include "itemprop.h"

class ItemPropList : public QObject {
    Q_OBJECT

public:
    //destructor
    ~ItemPropList();
    //to add an ItemProp
    void add(ItemProp* i);
    //to return a list of ItemProps
    QList<ItemProp*> returnList()const;

private:
    //to represent a list of ItemProps
    QList<ItemProp*> m_listOfItemProps;

};

#endif
