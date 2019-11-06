
//   Program Module: Item Class header file
//
//   PURPOSE: Defines the interface for the Item class
//
//   COMMENTS: This class creates main item objects of the applicaltion


#ifndef ITEM_H
#define ITEM_H

#include <QStringList>

class Item{
public:
    enum Categories{Cosmetics, Toiletries, Medicines, Appliances, Stationary};
    Item(QString dc, QString bc, Categories ct, double bp, double sp): m_Description(dc), m_Barcode(bc), m_Category(ct), m_BuyingPrice(bp), m_SellingPrice(sp){}
    virtual ~Item(){}
    QString toString() const;
    static const QStringList sm_Categories;

protected:
    QString m_Description;
    QString m_Barcode;
    Categories m_Category;
    double m_BuyingPrice;
    double m_SellingPrice;

};

#endif // ITEM_H
