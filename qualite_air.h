#ifndef QUALITE_AIR_H
#define QUALITE_AIR_H

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QtGui>
#include <QMessageBox>

class Qualite_air
{
public:
    double get_aqi();
    Qualite_air(int i);
    QNetworkAccessManager m;
    QString ville;
    QString cville;

private:
    QUrl qurl;
    QByteArray get(QUrl url);



};

#endif // QUALITE_AIR_H
