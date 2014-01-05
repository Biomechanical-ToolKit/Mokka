/* 
 * The Biomechanical ToolKit
 * Copyright (c) 2009-2013, Arnaud Barré
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name(s) of the copyright holders nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "qMokkaCorePythonManager.h"

#include "qMokkaCoreApplication.h"
#include "qMokkaCoreDataManager.h"

#include <PythonQt.h>

qMokkaCorePythonManager::qMokkaCorePythonManager(QObject* parent)
: ctkAbstractPythonManager(parent)
{
  int flags = this->initializationFlags();
  flags &= ~(PythonQt::IgnoreSiteModule); // Clear bit
  this->setInitializationFlags(flags);
};

void qMokkaCorePythonManager::appendPythonPath(const QString& path)
{
  // TODO Make sure PYTHONPATH is updated
  this->executeString(QString("import sys; sys.path.append('%1'); del sys").arg(path));
};

void qMokkaCorePythonManager::appendPythonPaths(const QStringList& paths)
{
  foreach(const QString& path, paths)
    this->appendPythonPath(path);
};

QStringList qMokkaCorePythonManager::pythonPaths()
{
  QStringList paths;
  paths << this->ctkAbstractPythonManager::pythonPaths();
  return paths;
};

void qMokkaCorePythonManager::preInitialization()
{
  this->ctkAbstractPythonManager::preInitialization();
  qMokkaCoreApplication* app = qMokkaCoreApplication::application();
  if (app != 0)
  {
    this->addObjectToPythonMain(QStringLiteral("_qMokkaCoreApplicationInstance"), app);
    this->addObjectToPythonMain(QStringLiteral("_qMokkaCoreDataManagerInstance"), app->dataManager());
  }
};