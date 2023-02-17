#define ACCEPT_USE_OF_DEPRECATED_PROJ_API_H
#include <proj_api.h>
#include "qtproj.h"

QtProj::QtProj(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.actionTransfer,SIGNAL(triggered()),this,SLOT(slot_transfer()));
}

QtProj::~QtProj()
{

}

void QtProj::slot_transfer()
{
    int flag, digits = 8;
    double lat, lon, height;
    QString qsSrc, qsDst;
    projPJ src, dst;

    //TODO: need check
    lat = ui.le_srcLat->text().toDouble();
    lon = ui.le_srcLon->text().toDouble();
    height = ui.le_srcH->text().toDouble();
    //e.g.
    //double lat=41.44;
    //double lon=103.33;
    //double height=500;

    qsSrc = ui.le_srcCS->text();
    qsDst = ui.le_dstCS->text();

    if (qsSrc.isEmpty())
    {
        qsSrc = QString(PROJSTRDEF);
        ui.le_srcCS->clear();
        ui.le_srcCS->insert(qsSrc);
    }
    if (qsDst.isEmpty())
    {

        qsDst = QString(PROJSTRDEF);
        ui.le_dstCS->clear();
        ui.le_dstCS->insert(qsDst);
    }
    // e.g.
    // QString qsSrc = "+proj=longlat +datum=WGS84 +no_defs";
    // QString qsDst = "+proj=tmerc +lat_0=0 +lon_0=105 +k=1 +x_0=18500000 +y_0=0 +ellps=krass +units=m +no_defs  +towgs84=0,0,0,0,0,0,0";

    src = pj_init_plus(qsSrc.toStdString().c_str());
    dst = pj_init_plus(qsDst.toStdString().c_str());

    if (src == NULL || dst == NULL)
    {
        ui.le_dstLat->setText(QString("Error"));
        if (src == NULL)
            ui.le_dstLon->setText(QString("Bad Src cs"));
        if (dst == NULL)
            ui.le_dstH->setText(QString("Bad Dst cs"));
        return;
    }

    if ((qsSrc.contains("+proj=longlat", Qt::CaseInsensitive)) || (qsSrc.contains("+proj=latlong", Qt::CaseInsensitive)))
    {
        lon *= DEG_TO_RAD;
        lat *= DEG_TO_RAD;
    }

    flag = pj_transform(src, dst, 1, 1, &lon, &lat, &height);

    pj_free(src);
    pj_free(dst);

    if (flag == 0)
    {
        if ((qsDst.contains("+proj=longlat", Qt::CaseInsensitive)) || (qsDst.contains("+proj=latlong", Qt::CaseInsensitive)))
        {
            lon /= DEG_TO_RAD;
            lat /= DEG_TO_RAD;
        }
        else
        {
            digits = 3;
        }

        ui.le_dstLat->setText(QString::number(lat, 'f', digits));
        ui.le_dstLon->setText(QString::number(lon, 'f', digits));
        ui.le_dstH->setText(QString::number(height, 'f', digits));
    }
    else
    {
        ui.le_dstLat->setText(QString("Error"));
        ui.le_dstLon->setText(QString::number(flag, 'd', 2));
        ui.le_dstH->setText(QString("Error"));
    }
}
