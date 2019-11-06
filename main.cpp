
//   Program Module: XML Serializer client program
//
//   PURPOSE: client program to test XMLSerializer
//
//   COMMENTS:
//            Creates main GUI fot the application and serializise items to XML file format
//


#include "gui.h"

int main(int argc, char *argv[])
{
    Gui userInterface(argc, argv);
    return userInterface.exec();
}

