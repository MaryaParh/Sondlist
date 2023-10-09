#include "gonglistdialog.h"
#include <QDebug>
#include <QDomDocument>
#include<QFileDialog>
#include <QStringList>
#include "songdialog.h"
#include "songlistdialog.h"
SongListDialog::SongListDialog(QWidget"parent):QDialog(parent)
m_ui = new Ui::SongListDialog();
dlg =new SongDialog();
m_ui->setupUi (this) ;
m_ui->information->hide();
readFile ();
createTable();
SongListDialog::~SongListDialog()
{
delete m_ui;
}
void SonglistDialog::createTable ()
{
QStringList header;
header << ("Превью Альбома") << ("Название") << ("Исполнитель")<< ("Продолжительность");
m_ui->tableWidget->setColumnCount(header.count());
m_ui->tableWidget->setHorizontalHeaderLabels(header):
m_ui->tablewidget->resizeRowsToContents(); 
 m_ui->tableWidget->resizeColumnsToContents():
m_ui->tablewidget->setSelectionMode(QAbstractItemView::SingleSelection);
void SongListDialog:: readFile ()
{
QDomDocument doc;
QFile file (path + "/music. xmi"):
if (file.exists ())
m_ui-›information->setText(tr ("Файл существует")) ;
if (file.open (QI0Device:: Text | QI0Device: :ReadOnly))
{
m_ul->information->setText (tr ("Файл открыт"));
int errorl, errorC: QString errors;
11 (Idoc.setContent(&file, true, errors, &errorl, &errorC))
{
qDebug () << "Error
<< errorS<< errorL<<errorC;
file.close ():
}
else
{
QDomElement element = doc.documentElement () ;
QDomNode node = element. firstChild();
while (!node.isNull ())
{
QDomElement elem = node.toElement ();
if (!elem.is null())
{
QBrush brush;
brush. setTextureImage (QImage (elem.attribute ("icon", "")));
 
QTableWidgetitem *item = new QTableWidgetItem();
m_ui->tableWidget->insertRow(m_ui->tableWidget-›rowCount());
m_ui->tableNidget->setItem(m_ui->tableWidget->rowCount()-1,0,item);
m_ui->tablewidget->setItem(m_ui->tableWidget->rouCount()-1, new QTableWidgetItem(elem.attribute("name"
"")));
m_ui->tablewidget->setItem(m_ui->tablewidget->rowCount()-1,2, new QTableWidgetItem(elem.attribute ("author"
"") ));
m ui->tableWidget->setItem(m_ui->tablewidget->rowCount()-1,3, new QTableWidgetItem.attribute ("size"
"")));
node = node.nextsibling () ;
}
}
}
else
m_ui->information->setText (tr ("файла нет"));
void SonglistDialog::on_btnCreate_clicked ()
{
dlg->setWindowTitle (tr ("создание")) ;
int res = dlg->exec();
if (QDialog::Rejected)
return;
QBrush brush;
brush. setTextureImage (QImage (dlg->iconName () )) ;
QTableWidgetItem *item = new QTableWidgetitem() ;
item->setBackground (brush);
m_ui->tableWidget->insertRow(m_ui->tableWidget->rowCount(j);
m_ui->tableWidget->setiIem(m_ui->tableWidget->rowCount()-1,0,item);
m_ui->tableWidget->setItem(m_ui->tablewidget->rowCount()-1, new QTablewidgetItem(dlg->name () )) ;
m_ui->tableWidget->setitem(mui->tableWidget->rowCount()-1,2, new QTableWidgetItem (dlg->author () ));
m_ui->tableWidget->setItem(m_ui->tableWidget->rowCount()-1,3,
new QTableWidgetItem(QString:::number(dlg->size()));
void SongListDialog::on_btnSave_clicked ()
{
QFile file (path + "/music.xml");
if (!file.open (QIODevice::WriteOnly | QIODevice: :Text) )
return;
ODomDocument doc;
doc.setContent (&file);
file.close ();
QDomNode node = doc. createProcessingInstruction ("xmI", "version= '1.0'
encoding= 'UTF-8'");
doc. appendChild (Xnode) ;
QDomElement root = doc. createElement ("compositions" );
doc.appendChild (root);
if (m_ui->tableWidget->selectionModel()->hasSelection())
{
int row = m_ui->tableWidget->currentRow () ;
QDomElement complex = doc.createElement ("composition");
complex. setAttribute ("icon", m_ui-›tableWidget->item(row, 0)->text ()); complex. setAttribute ("name", m_ui->tablewidget->item(row, 1) ->text ()) ; complex.setAttribute ("author", m_ui->tableWidget->item(row, 2)->text () ); complex. setAttribute ("size", m_ui->tablewidget->item(row, 3)->text () ) ;
root.appendChild (complex);
}
file.open (QIODevice: :WriteOnly | QIODevice:: Text | QIODevice:: ReadOnly) ;
QTextStream out (&file);
out << doc.toString ();
file.close () ;
if (file.exists ( ))
{
m_ui->information->setText(tr ("файл сохранён") );
m_ui->information->show () ;
}
}
void SonglistDialog::on_btnUpdate_clicked()
{
if (m_ui->tableWidget->selectionModel()->hasSelection())
{
int row = m_ui-›tableWidget->currentRow () ; 
 dlg->setWindowTitle(tr("редактирование"));
dlg->show ();
dlg->setIconName (m_ui->tableWidget->item (row, 0) ->text () ) ;
dlg->setName (m ui->tablewidget->item(row, 1) ->text ());
dlg->setAuthor (m_ui->tableWidget->item(row, 2) ->text () );
dlg->setSize (m_ui->tablewidget->item (row, 3) ->text ());
}
else
{
m_ui->information->setText (tr ("выделите строку") );
m_ui->information->show ();
}
}
 
