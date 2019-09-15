/*
 * Copyright (C) 2018-2019 QuasarApp.
 * Distributed under the lgplv3 software license, see the accompanying
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */

#ifndef EXTRACTER_H
#define EXTRACTER_H
#include <QDir>
#include <QString>
#include <QStringList>
#include <dependenciesscanner.h>
#include "deploy_global.h"
#include "filemanager.h"
#include "qml.h"

class ConfigParser;
class MetaFileManager;

class DEPLOYSHARED_EXPORT Extracter {
  private:
    DeployCore::QtModule _qtModules = DeployCore::NONE;

    QStringList neadedLibs;
    QStringList systemLibs;

    DependenciesScanner scaner;
    FileManager *_fileManager;
    ConfigParser *_cqt;
    MetaFileManager *_metaFileManager;

    void extract(const QString &file);
    bool copyTranslations(QStringList list);

    bool extractQml();

    QFileInfoList findFilesInsideDir(const QString &name, const QString &dirpath);
    bool extractQmlAll();
    bool extractQmlFromSource(const QString &sourceDir);
    QString filterQmlPath(const QString &path);
    void extractLib(const QString & file);

    bool deployMSVC();
    bool extractWebEngine();


    bool copyPlugin(const QString &plugin);
    void copyPlugins(const QStringList &list);


    void extractAllTargets();
    void initQtModules();
    void clear();
    void extractPlugins();
    void copyFiles();
    void copyTr();
    void copyExtraPlugins();
public:
    explicit Extracter(FileManager *fileManager, ConfigParser * cqt);
    void deploy();

    friend class deploytest;
};

#endif // EXTRACTER_H_H
