
#pragma once
#include <QAbstractitemModel>
#include <QDialog>
#include "songdialog.h"

namespace UI {
class SongListDialog;
}
class SongListDialog: public QDialog {
Q_OBJECT

public:
SongListDialog(QWidget *parent = nullptr);
~SongListDialog();

void createTable();
void readFile();

public slots:
void on_btnCreate_clicked();
void on_btnSave_clicked();
void on_btnUpdate_clicked();

private:
Ui::SongListDialog *m_ui = nullptr; SongDialog *dlg;
QString path = "/home/user/develop/SongList/build/bin";
};
