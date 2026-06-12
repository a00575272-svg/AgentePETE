#include "UserProfile.h"

UserProfile::UserProfile()
    : userName("Usuario"), preferredModel("gemma3:4b") {}

QString UserProfile::getUserName() const { return userName; }
QString UserProfile::getPreferredModel() const { return preferredModel; }

void UserProfile::setUserName(const QString &name) { userName = name; }
void UserProfile::setPreferredModel(const QString &model) { preferredModel = model; }

QJsonObject UserProfile::toJson() const
{
    QJsonObject obj;
    obj["userName"]       = userName;
    obj["preferredModel"] = preferredModel;
    return obj;
}

UserProfile UserProfile::fromJson(const QJsonObject &obj)
{
    UserProfile profile;
    if (obj.contains("userName"))
        profile.userName = obj["userName"].toString();
    if (obj.contains("preferredModel"))
        profile.preferredModel = obj["preferredModel"].toString();
    return profile;
}
