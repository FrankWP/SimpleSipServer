#ifndef RTPRECVER_H
#define RTPRECVER_H

#include <QObject>
#include <QThread>

#include <rtpsession.h>
#include <rtpudpv4transmitter.h>
#include <rtpipv4address.h>
#include <rtpsessionparams.h>
#include <rtperrors.h>
#include <rtplibraryversion.h>
#include <rtpsourcedata.h>
#include <rtpsources.h>
#include <rtppacket.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <QQueue>
#include <QByteArray>
#include <QTimer>
using namespace jrtplib;


class RtpRecver : public QThread
{
    Q_OBJECT
public:
    explicit RtpRecver(QObject *parent = 0);
    ~RtpRecver();
    void init(QString recvIp, unsigned short recvPort);
    void destroy();
protected:
    virtual void run();
    void ProcessRTPPacket(const RTPSourceData &srcdat,const RTPPacket &rtppack);
    ;
private:
    RTPSession m_rtpSession;
    bool m_brecvOver;
    char* m_frameBuffer = Q_NULLPTR;
    int m_bufferSize = 0;
    int m_lastSeqNumber = 0;
signals:
    void sigRecvedFrame(QByteArray buff);
public slots:

};

#endif // RTPRECVER_H
