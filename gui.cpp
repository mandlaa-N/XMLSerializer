
//   Program Module: GUI Class Implementation file
//
//   PURPOSE: Implements the API defined by the GUI header file
//
//   COMMENTS: This class builds the main user interface of the applicaltion


#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include "gui.h"
#include "item.h"
#include "itemprop.h"

// Graphical user interface constructor
Gui::Gui(int argc, char* argv[]):QApplication(argc, argv){
        //{layout and widges have been initialized
        layout=new QGridLayout;

        description = new QLabel("Description");
        enterDescription=new QLineEdit;
        enterDescription->setMaxLength(20);

        barcode = new QLabel("Barcode");
        enterBarcode=new QLineEdit;
        enterBarcode->setMaxLength(20);

        category = new QLabel("Category");
        enterCategory = new QComboBox();
        enterCategory->addItems(Item::sm_Categories);

        buyingPrice = new QLabel("Buying Price");
        enterBuyingPrice = new QDoubleSpinBox();
        enterBuyingPrice->setRange(0.00, 999.99);

        sellingPrice = new QLabel("Selling Price");
        enterSellingPrice = new QDoubleSpinBox();
        enterSellingPrice->setRange(0.00, 999.99);

        submit = new QPushButton("Submit");
        listItems = new QPushButton("Serialize");

        gui=new QWidget();
        gui->setWindowTitle("Capture Item Information");
        //}
        //{widgets are placed in the layout and the layout added to the main widget
        layout->addWidget(description, 0, 0);
        layout->addWidget(enterDescription, 0, 1);
        layout->addWidget(barcode, 1, 0);
        layout->addWidget(enterBarcode, 1, 1);
        layout->addWidget(category, 2, 0);
        layout->addWidget(enterCategory, 2,1);
        layout->addWidget(buyingPrice, 3, 0);
        layout->addWidget(enterBuyingPrice, 3, 1);
        layout->addWidget(sellingPrice, 4, 0);
        layout->addWidget(enterSellingPrice, 4,1);
        layout->addWidget(submit, 5, 0);
        layout->addWidget(listItems, 5, 1);        
        gui->setLayout(layout);
        gui->show();

        //initialize ItemPropList
        il = new ItemPropList();
        //connect relevant signals to appropriate slots
        connect(submit, SIGNAL(clicked()), this, SLOT(addToItemList()));
        connect(listItems, SIGNAL(clicked()), this, SLOT(displayItems()));

}

//destructor
Gui::~Gui(){
    delete layout;
    delete gui;
    delete il;
}

//add an item to the list
void Gui::addToItemList(){
    QString des = enterDescription->text();
    QString bar = enterBarcode->text();
    QString cat = enterCategory->currentText();
    double buy = enterBuyingPrice->value();
    double sell = enterSellingPrice->value();

    ItemProp *i = new ItemProp(des,bar,Item::Categories(Item::sm_Categories.indexOf(cat)),buy,sell);
    il->add(i);
    clearFields();
    QMessageBox::information(gui, "Information", "An item has been added to the list.");

}

//writes the ItemProps to the file ItemList.txt
void Gui::displayItems(){

    if((il->returnList().size())!=0){
        QFile f1("ItemList.xml");
        f1.open(QIODevice::WriteOnly);
        QTextStream out(&f1);

        QString str = xe.objectToXml(il, 3).toUtf8();
        QStringList sl = str.split("\n");
        out << sl.at(1).toUtf8();

        QList<ItemProp*> list =il->returnList();
        QListIterator<ItemProp*> i(list);
        while (i.hasNext())
             out<< (xe.objectToXml(i.next(), 3)).toUtf8();

        out<< sl.at(2).toUtf8();
        f1.close();

        QMessageBox::information(gui, "Information", "Items have been serialized");
    }

}

//to clear widgets and to reset values
void Gui::clearFields(){
    enterDescription->clear();
    enterBarcode->clear();
    enterCategory->setCurrentIndex(0);
    enterBuyingPrice->setValue(0.0);
    enterSellingPrice->setValue(0.0);
}
