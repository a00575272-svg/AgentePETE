#pragma once

#include <QString>
#include <QJsonArray>

#include "UserProfile.h"

class PersistenceManager
{
public:
    PersistenceManager();

    bool initialize();

    bool saveUserProfile(
            const UserProfile &profile);

    UserProfile loadUserProfile();

    bool saveConversation(
            const QString &prompt,
            const QString &response);

    QJsonArray loadHistory();

private:
    QString dataFolder() const;
    QString profileFile() const;
    QString historyFile() const;
};
