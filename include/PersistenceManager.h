#pragma once

#include <QString>
#include <QJsonArray>

#include "UserProfile.h"
#include "IDataStorage.h"

class PersistenceManager : public IDataStorage
{
public:
    PersistenceManager();

    bool initialize() override;

    bool saveUserProfile(
            const UserProfile &profile);

    UserProfile loadUserProfile();

    bool saveConversation(
            const QString &prompt,
            const QString &response);

    // SOBRECARGA
    bool saveConversation(
            const QString &prompt);

    QJsonArray loadHistory();

private:
    QString dataFolder() const;
    QString profileFile() const;
    QString historyFile() const;
};
