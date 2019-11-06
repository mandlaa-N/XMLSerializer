
//   Program Module: ItemProp class implentation cpp file
//
//   PURPOSE: ItemProp API implementation
//
//   COMMENTS:
//             This class facilitates indirect access to properties /data members  of  Item  class objects
//             via the Q_PROPERTY macro thereby implementing the Meta-object pattern also called Reflection Pattern
//             and simplifying code re-usability.


#include "itemprop.h"
//constructor
ItemProp::ItemProp(QString de, QString ba, Categories ca, double bu, double se): Item(de, ba, ca, bu, se){
}
//to return the description
QString ItemProp::getDescription() const{
    return m_Description;
}
//to return the barcode
QString ItemProp::getBarcode() const{
    return m_Barcode;
}
//to return the category
QString ItemProp::getCategory()const{
    QString ca = Item::sm_Categories.at(m_Category);
    return ca;
}
//to return the buying price
double ItemProp::getBuyingPrice()const{
    return m_BuyingPrice;
}
//to return the selling price
double ItemProp::getSellingPrice()const{
    return m_SellingPrice;
}
//to set the description
void ItemProp::setDescription(QString de){
    m_Description = de;
}
//to set the barcode
void ItemProp::setBarcode(QString ba) {
    m_Barcode = ba;
}
//to set the category
void ItemProp::setCategory(QString ca){
    m_Category = Item::Categories(Item::sm_Categories.indexOf(ca));
}
//to set the buying price
void ItemProp::setBuyingPrice(double bp){
    m_BuyingPrice = bp;
}
//to set the selling price
void ItemProp::setSellingPrice(double sp){
    m_SellingPrice = sp;
}


