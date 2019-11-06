//   Program Module: ItemProp Class header file
//
//   PURPOSE: Defines the interface for the ItemProp class
//
//   COMMENTS:
//             This class facilitates indirect access to properties /data members  of  Item  class objects
//             via the Q_PROPERTY macro thereby implementing the Meta-object pattern also called Reflection Pattern
//             and simplifying code re-usability.

//



#ifndef ITEMPROP_H
#define ITEMPROP_H

#include <QObject>
#include "item.h"

class ItemProp : public QObject, public Item{
    Q_OBJECT
public:
    //{Q_PROPERTY macros for all the Item data members
    Q_PROPERTY(QString des READ getDescription WRITE setDescription)
    Q_PROPERTY(QString bar READ getBarcode WRITE setBarcode)
    Q_PROPERTY(QString cat READ getCategory WRITE setCategory)
    Q_PROPERTY(double buy READ getBuyingPrice WRITE setBuyingPrice)
    Q_PROPERTY(double sell READ getSellingPrice WRITE setSellingPrice)
    //}

    //constructor
    ItemProp(QString de, QString ba, Categories ca, double bu, double se);

    //{ getters or accessors
    QString getDescription() const;
    QString getBarcode() const;
    QString getCategory()const;
    double getBuyingPrice()const;
    double getSellingPrice()const;
    //

    //{ setters or mutators
    void setDescription(QString de);
    void setBarcode(QString ba) ;
    void setCategory(QString ca);
    void setBuyingPrice(double bp);
    void setSellingPrice(double sp);
    //}

};

#endif // ITEMPROP_H
