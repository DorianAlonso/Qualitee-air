#include "qualite_air.h"
#include <iostream>
using namespace std;
Qualite_air::Qualite_air(int i)
{
i+=i;
}

QByteArray Qualite_air::get(QUrl url)
{

    QNetworkRequest requete(url);
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    requete.setSslConfiguration(config);
    QNetworkReply *reply = m.get(requete);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();

    return read;

}

double Qualite_air::get_aqi()
{
    qurl = "https://api.waqi.info/feed/"+this->cville+"/?token=d9636de539c0cc32e3771e378fd51527b70526f1";
    QUrl url = qurl;
    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url));
    QJsonObject objetJSON = documentJSON.object();
    QJsonValue value = objetJSON.value("data");

    QJsonObject objetJSON1 = value.toObject();
    QJsonValue value1 = objetJSON1.value("aqi");

    //refere a data
    QJsonValue city = objetJSON1.value("city");


    QJsonObject value3 = city.toObject();
    QJsonValue nom_ville = value3.value("name");
    this->ville=nom_ville.toString();






    return value1.toDouble();

}

