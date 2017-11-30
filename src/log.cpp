#include "log.hpp"

#include <stdio.h>
#include <stdlib.h>

QString getFileName(const QString &filePath)
{
    QStringList parts = filePath.split("/");
    QString fileName = parts[parts.size() - 1];
    return fileName;
}

QString getFunctionName(const QString &function)
{
    int parenthesesIndex = function.indexOf('(');
    int firstSpaceIndex = function.indexOf(' ');
    if (firstSpaceIndex == -1 || firstSpaceIndex > parenthesesIndex) {
        return function.mid(0, parenthesesIndex);
    } else {
        int startIndex = firstSpaceIndex + 1;
        return function.mid(startIndex, parenthesesIndex - startIndex);
    }
}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    char typeStr = 'D';
    QByteArray functionName = getFunctionName(QString::fromLocal8Bit(context.function)).toLocal8Bit();
    QByteArray fileName = getFileName(QString::fromLocal8Bit(context.file)).toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        typeStr = 'D';
        break;
    case QtInfoMsg:
        typeStr = 'I';
        break;
    case QtWarningMsg:
        typeStr = 'W';
        break;
    case QtCriticalMsg:
        typeStr = 'C';
        break;
    case QtFatalMsg:
        typeStr = 'F';
        break;
    }

    fprintf(stderr, "%c/%s:%s:%u: %s\n", typeStr, fileName.constData(),functionName.constData(),
            context.line, localMsg.constData());
    if (type == QtFatalMsg)
        abort();
}
