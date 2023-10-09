#pragma once
#include <QDialog>

namespace Ui
{
class SongDialog;
}
class SongDialog : public QDialog
{
Q_OBJECT

public:
SongDialog(QWidget *parent = nullptr); ~SongDialog();

QString iconName();
OString author();
int size();
OString name();
int mark();

void setIconName(OString i);
void setAuthor(QString a);
void setSize(OString s);
void setName(OString n);
void setMark(int m);

void showPreview(const OString GrelativePath) const;

private slots:
void on _buttonBoy_accepted();
void on _buttonBox rejected();

private:
void choosePreview();
OString copiedPreview(const OString &filePath) const;
OString fullimagePath(const OString GrelativePath) const;

Ui.:songDialog *m _ui =nullptr;
const OString m _imageDir = " .. ../data/images";
OString copyName;

};