#include "UserProfile.h"
#include <QJsonObject>
UserProfile::UserProfile()
{
    userName = "Usuario";
    preferredModel = "gemma3:4b";
}

QString UserProfile::getUserName() const
{
    return userName;
}

QString UserProfile::getPreferredModel() const
{
    return preferredModel;
}

void UserProfile::setUserName(const QString &name)
{
    userName = name;
}

void UserProfile::setPreferredModel(const QString &model)
{
    preferredModel = model;
}

QJsonObject UserProfile::toJson() const
{
    QJsonObject obj;

    obj["userName"] = userName;
    obj["preferredModel"] = preferredModel;

    return obj;
}

UserProfile UserProfile::fromJson(const QJsonObject &obj)
{
    UserProfile profile;

    profile.userName =
        obj["userName"].toString("Usuario");

    profile.preferredModel =
        obj["preferredModel"].toString("gemma3:4b");

    return profile;
}
