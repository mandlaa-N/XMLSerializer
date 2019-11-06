//   Program Name: XML Serialiser
//   Program Module: GUI Class header file
//
//   PURPOSE: Defines the interface for the GUI class
//
//   COMMENTS: This class builds the main user interface of the applicaltion

//
//
#ifndef GUI_H
#define GUI_H

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QListIterator>


#include "itemproplist.h"
#include "xmlexport.h"

class Gui : public QApplication {
    Q_OBJECT

public:
    //constructor
    Gui(int argc, char* argv[]);
    //destructor
    ~Gui();

private slots:
    //to add an item to the list
    void addToItemList();
    //serializes the item list
    void displayItems();


private:
    //{layout and widgets for the GUI
    QGridLayout* layout;
    QLabel* description;
    QLineEdit* enterDescription;
    QLabel* barcode;
    QLineEdit* enterBarcode;
    QLabel* category;
    QComboBox * enterCategory;
    QLabel* buyingPrice;
    QDoubleSpinBox* enterBuyingPrice;
    QLabel* sellingPrice;
    QDoubleSpinBox* enterSellingPrice;
    QPushButton* submit;
    QPushButton* listItems;
    QWidget* gui;
    //
    //to produce an XML representation of the object
     XMLExport xe;
     //an ItemProp list
     ItemPropList *il;
     //to clear and reset widgets
     void clearFields();
};

#endif // GUI_H
