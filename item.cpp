
//   Program Module: Item Class implemtation cpp file
//
//   PURPOSE: Implements the API specicied in Item  header file
//
//   COMMENTS: class instances create Item objects for manipulation by the applicaltion


#include "item.h"

//initializing the static data member
const QStringList Item::sm_Categories = (QStringList()<<"Cosmetics" << "Toiletries" << "Medicines" << "Appliances" << "Stationary");

//returns a string representation of an item
QString Item::toString()const{
    QString cat = sm_Categories.at(m_Category);
    QString bPrice = QString::number(m_BuyingPrice);
    QString sPrice = QString::number(m_SellingPrice);
    return ("Description: " + m_Description + ", BC: " + m_Barcode + ", Category: " + cat + ", BP: " + bPrice + ", SP: " + sPrice);
}

