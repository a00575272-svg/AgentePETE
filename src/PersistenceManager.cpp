#include "PersistenceManager.h"

#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QDateTime>

PersistenceManager::PersistenceManager() {}

QString PersistenceManager::dataFolder() const
{
    return "agentePeteData";
}

QString PersistenceManager::profileFile() const
{
    return dataFolder() + "/userProfile.json";
}

QString PersistenceManager::historyFile() const
{
    return dataFolder() + "/history.json";
}

bool PersistenceManager::initialize()
{
    QDir dir;
    return dir.mkpath(dataFolder());
}

bool PersistenceManager::saveUserProfile(const UserProfile &profile)
{
    QFile file(profileFile());
    if (!file.open(QIODevice::WriteOnly))
        return false;
    file.write(QJsonDocument(profile.toJson()).toJson());
    return true;
}

UserProfile PersistenceManager::loadUserProfile()
{
    QFile file(profileFile());
    if (!file.open(QIODevice::ReadOnly))
        return UserProfile();
    const QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (!doc.isObject())
        return UserProfile();
    return UserProfile::fromJson(doc.object());
}

bool PersistenceManager::saveConversation(const QString &prompt, const QString &response)
{
    QJsonArray history = loadHistory();

    QJsonObject entry;
    entry["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
    entry["prompt"]    = prompt;
    entry["response"]  = response;
    history.append(entry);

    QFile file(historyFile());
    if (!file.open(QIODevice::WriteOnly))
        return false;
    file.write(QJsonDocument(history).toJson());
    return true;
}

QJsonArray PersistenceManager::loadHistory()
{
    QFile file(historyFile());
    if (!file.open(QIODevice::ReadOnly))
        return QJsonArray();
    const QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (!doc.isArray())
        return QJsonArray();
    return doc.array();
}
