#include "songdialog.h"
#include <QDebug>
#include <QFileDialog>
#include "ul_songdialog.h"
SongDialog::SongDialog (OWidget *parent) : ODialog (parent) , m_ui (new
Ui::SongDialog () )
{
m_ui->setupUi (this);
connect (m_ui->btnPreview, &QPushButton:: clicked,
this, &SongDialog::choosePreview);
QDir dir;
if (!dir.exists (m_imageDir))
dir.mkpath (m_imageDir);
}
SongDialog::~SongDialog()
{
delete m_ui;
}
QString SongDialog: : iconName ()
{
return copyName;
}
QString SongDialog: :author ()
{
return m_ui->lineEdit_author->text ();
}
int SongDialog: :size ()
{
return m_ui->lineEdit_size->text ().toint ();
}
OString SongDialog: : name ()
{
return m_ui->lineEdit_name->text ();
}
int SongDialog::mark ()
{
return m_ui->mark->value();
}
void SongDialog:: setIconName (QString i)
{
m_ui->labelPreview->clear () ;
m_ui->labelPreview->setPixmap (fullImagePath (i) );
}
void SongDialog:: setAuthor (QString a)
{
m_ui->lineEdit_author->clear () ;
m_ui->lineEdit_author->setText(a);
}
void SongDialog:: setSize (QString s)
{
m_ui->lineEdit_size->clear () ;
m_ui->lineEdit_size->setText (s) ;
}
void SongDialog:: setName (QString n)
{
m_ui->lineEdit_name->clear () ;
m_ui->lineEdit_name->setText (n);
}
void SongDialog:: setMark (int m)
{
m_ui->mark->setValue (m) ;
}
void SongDialog: :choosePreview ()
{
const auto filename = QFileDialog::getOpenFileName (this, tr ("выберете
изображение"), QString (),
" (*.jpeg * .jpg *png *gif)");
if (filename.isEmpty ()) return;
copyName = copiedPreview (filename);
showPreview (copyName);
}
OString SongDialog::copiedPreview (const QString &filePath) const
{
const Image image (filePath);
const auto smaller = image.scaled (m_ui->labelPreview->width (), m_ui->labelPreview->height (),
Qt::AspectRatioMode::KeepAspectRatioByExpanding) ;
OString name = QString ("%1").arg (filePath);
if (smaller. save (fullimagePath (name), "PNG")) return QString ();
return name;
}
void SongDialog::showPreview (const OString &relativePath) const
{
if (relativePath.isEmpty ()) return;
const auto fn = fullImagePath (relativePath);
if (QFile::exists (fn) )
return;
const OPixmap pixmap (fn) ;
m_ui->labelPreview->setPixmap (pixmap);
}
String SongDialog:: fullImagePath (const OString &relativePath) const
{
QDir dir;
dir.cd (m_imageDir);
return dir.absoluteFilePath (relativePath);
}
}
void SongDialog:: on_buttonBox_accepted ()
{
accept ();
}
void SongDialog:: on buttonBox_rejected ()
{
reject();
}
