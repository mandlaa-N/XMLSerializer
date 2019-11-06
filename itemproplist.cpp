
//   Program Module: ItemPropList Class implemetation cpp file
//
//   PURPOSE: Implements the API or interface for this class
//
//   COMMENTS: represents a list of item properties

#include "itemproplist.h"

//destructor
ItemPropList::~ItemPropList(){
    qDeleteAll(m_listOfItemProps);
}
//to add an ItemProp
void ItemPropList::add(ItemProp* i){
    m_listOfItemProps.append(i);
}
//to return a list of ItemProps
QList<ItemProp*> ItemPropList::returnList()const{
    return m_listOfItemProps;
}

