#ifndef LOG_HPP
#define LOG_HPP

#include <QMessageLogContext>
#include <QStringList>
#include <QString>

QString getFileName(const QString &filePath);

QString getFunctionName(const QString &function);

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // LOG_HPP
