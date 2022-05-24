/**********************************************************************
 *  mainwindow.h
 **********************************************************************
 * Copyright (C) 2017 MX Authors
 *
 * Authors: Adrian
 *          MX Linux <http://mxlinux.org>
 *
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this package. If not, see <http://www.gnu.org/licenses/>.
 **********************************************************************/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QProcess>
#include <QTimer>
#include <QSettings>

#include <cmd.h>

class QFile;

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(const QStringList &args);
    ~MainWindow();

    const QString cli_utils = ". /usr/local/lib/cli-shell-utils/cli-shell-utils.bash;";
    QString LUM;
    QString buildOptionList();
    QStringList buildUsbList();
    QStringList removeUnsuitable(const QStringList &devices); // remove unsuitable disks from the list (live and unremovable)
    bool checkDestSize();
    bool isRunningLive();
    bool isToRam();
    void makeUsb(const QString &options);
    void progress();
    void setGeneralConnections();
    void setup();


public slots:

private slots:
    bool isantiX_mx_family(QString arg1);
    void cleanup();
    void cmdStart();
    void cmdDone();
    void setConnections();
    void setDefaultMode(const QString &iso_name);
    void updateBar();
    void updateOutput();

    void pushAbout_clicked();
    void pushBack_clicked();
    void pushHelp_clicked();
    void pushNext_clicked();
    void pushOptions_clicked();
    void pushRefresh_clicked();
    void pushSelectSource_clicked();
    void checkCloneLive_clicked(bool checked);
    void checkCloneMode_clicked(bool checked);
    void checkDataFirst_clicked(bool checked);
    void checkUpdate_clicked(bool checked);
    void textLabel_textChanged(QString arg1);
    void pushLumLogFile_clicked();
    void radioDd_clicked();
    void radioNormal_clicked();
    void spinBoxSize_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Cmd cmd;
    QFile *stat_file;
    QString device;
    QTimer timer;
    bool advancedOptions;
    int height;
    uint size_check;
};


#endif

