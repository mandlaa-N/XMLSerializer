
//   Program Module: XMLExport Class header file
//
//   PURPOSE: Defines API or interface for this class
//
//   COMMENTS:
//            This  does not perform any file i/o -
//            just converts a QObject with properties
//            into an XML string representation.


#ifndef XMLEXPORT_H
#define XMLEXPORT_H
#include <QString>
class QObject;
#include "xmlexport.h"

 //using namespace XmlExport;


class XMLExport {
 public:
    virtual ~XMLExport() {}
    virtual QString objectToXml(const QObject* ptr,
                                int indentlevel=0);
};
#endif


