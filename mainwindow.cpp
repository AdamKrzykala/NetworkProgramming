#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _socket(this)
{
    ui->setupUi(this);
    _socket.connectToHost(QHostAddress("192.168.4.1"), 80);
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onReadyRead()
{
    QByteArray datas = _socket.readAll();
    qDebug() << datas;
    _socket.write(QByteArray("Thanks_for_data"));
}
