
#include <QApplication>
#include <QDebug>
#include <clocale>
#include"songlistdialog.h"
int main (int argc, char **argv)
{
QApplication app (argc, argv);
SongListDialog dig;
dig. show ();
std:: setlocale (LC_CTYPE, "rus");
return app.exec () :
}