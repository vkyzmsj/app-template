#include "Config.h"
#include "Json.h"

#include <QString>
#include <QStringList>
#include <QSettings>
#include <QTextCodec>

Config::Config() {
    json = new Json("data/config.json", true); // 配置文件路径
    appSettings = new QSettings("data/app.data", QSettings::IniFormat);
    appSettings->setIniCodec(QTextCodec::codecForName("UTF8"));
}

Config::~Config() {
    destroy();
}

void Config::destroy() {
    // 保存配置到文件
    if (NULL != appSettings) {
        appSettings->sync();
    }

    delete json;
    delete appSettings;

    json = NULL;
    appSettings = NULL;
}

QString Config::getDatabaseType() const {
    return json->getString("database.type");
}

QString Config::getDatabaseHost() const {
    return json->getString("database.host");
}

QString Config::getDatabaseName() const {
    return json->getString("database.database_name");
}

QString Config::getDatabaseUsername() const {
    return json->getString("database.username");
}

QString Config::getDatabasePassword() const {
    return json->getString("database.password");
}

bool Config::getDatabaseTestOnBorrow() const {
    return json->getBool("database.test_on_borrow", false);
}

QString Config::getDatabaseTestOnBorrowSql() const {
    return json->getString("database.test_on_borrow_sql", "SELECT 1");
}

int Config::getDatabaseMaxWaitTime() const {
    return json->getInt("database.max_wait_time", 5000);
}

int Config::getDatabaseMaxConnectionCount() const {
    return json->getInt("database.max_connection_count", 5);
}

int Config::getDatabasePort() const {
    return json->getInt("database.port", 0);
}

bool Config::isDatabaseDebug() const {
    return json->getBool("database.debug", false);
}

QStringList Config::getDatabaseSqlFiles() const {
    return json->getStringList("database.sql_files");
}

QStringList Config::getQssFiles() const {
    return json->getStringList("qss_files");
}

QStringList Config::getFontFiles() const {
    return json->getStringList("font_files");
}
