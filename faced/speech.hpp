#ifndef SPEECH_H
#define SPEECH_H

#ifdef CON_SPEECH

#include <QObject>
#include <QDebug>

#include <espeak/speak_lib.h>

class Speech : public QObject
{
    Q_OBJECT

private:

    int SynthCallback( short *wav, int numsamples, espeak_EVENT *events );

public:

    explicit Speech( QObject *parent = 0 );

    void read( QString text );
};

#endif

#endif // SPEECH_H
