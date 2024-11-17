#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include <QObject>

class MessageSender : public QObject
{
    Q_OBJECT
public:


signals:
    void sendMessage(QString message);
};

#endif // MESSAGESENDER_H
