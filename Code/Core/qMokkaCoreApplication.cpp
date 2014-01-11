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
 
#include "qMokkaCoreApplication.h"
#include "qMokkaCoreApplication_p.h"
#if defined(MOKKA_USE_PYTHON)
  #include "qMokkaCorePythonManager.h"
  #include <PythonQt.h>
#endif
#include "qMokkaCoreDataManager.h"
#include "qMokkaAcquisition.h"
#include "qMokkaPoint.h"

#include <QProcess>

// ------------------------------------------------------------------------- //
//                         qMokkaCoreApplicationPrivate                      //
// ------------------------------------------------------------------------- //

qMokkaCoreApplicationPrivate::qMokkaCoreApplicationPrivate(qMokkaCoreApplication* q)
: q_ptr(q)
{};

qMokkaCoreApplicationPrivate::~qMokkaCoreApplicationPrivate()
{
#if defined(MOKKA_USE_PYTHON)
  this->CorePythonManager.clear();
#endif
};

void qMokkaCoreApplicationPrivate::initialize()
{
  Q_Q(qMokkaCoreApplication);
  
  QCoreApplication::setOrganizationName("BTK");
  QCoreApplication::setOrganizationDomain("btk.org");
  QCoreApplication::setApplicationName("Mokka");

#if defined(MOKKA_USE_PYTHON)
  if (q->pythonManager())
    q->pythonManager()->mainContext(); // Initialize python
#endif
};

// ------------------------------------------------------------------------- //
//                             qMokkaCoreApplication                         //
// ------------------------------------------------------------------------- //

qMokkaCoreApplication* qMokkaCoreApplication::application()
{
  qMokkaCoreApplication* app = qobject_cast<qMokkaCoreApplication*>(QApplication::instance());
  return app;
};

qMokkaCoreApplication::qMokkaCoreApplication(int& argc, char** argv)
: QApplication(argc, argv),
  d_ptr(new qMokkaCoreApplicationPrivate(this))
{
  Q_D(qMokkaCoreApplication);
  d->initialize();
};

qMokkaCoreApplication::qMokkaCoreApplication(qMokkaCoreApplicationPrivate& dd, int& argc, char** argv)
: QApplication(argc, argv), d_ptr(&dd)
{};

qMokkaCoreApplication::~qMokkaCoreApplication()
{};

// ------------------------------------------------------------------------- //

#if defined(MOKKA_USE_PYTHON)
qMokkaCorePythonManager* qMokkaCoreApplication::pythonManager() const
{
  Q_D(const qMokkaCoreApplication);
  return d->CorePythonManager.data();
};

void qMokkaCoreApplication::setPythonManager(qMokkaCorePythonManager* manager)
{
  Q_D(qMokkaCoreApplication);
  d->CorePythonManager = QSharedPointer<qMokkaCorePythonManager>(manager);
};
#endif

qMokkaCoreDataManager* qMokkaCoreApplication::dataManager() const
{
  Q_D(const qMokkaCoreApplication);
  return d->CoreDataManager.data();
};

void qMokkaCoreApplication::setDataManager(qMokkaCoreDataManager* manager)
{
  Q_D(qMokkaCoreApplication);
  d->CoreDataManager = QSharedPointer<qMokkaCoreDataManager>(manager);
};

// ------------------------------------------------------------------------- //

QString qMokkaCoreApplication::libraries() const
{
  return QStringLiteral(
    "Built on top of: "
    "<a href=\"http://code.google.com/p/b-tk/\">BTK</a>, "
    "<a href=\"http://www.vtk.org/\">VTK</a>, "
    "<a href=\"http://www.commontk.org/\">CTK</a>, "
    "<a href=\"http://qt-project.org/\">Qt</a>, "
    "<a href=\"http://www.python.org/\">Python</a><br />");
};

QString qMokkaCoreApplication::copyrights() const
{
  return QStringLiteral(
    "<table align=\"center\" border=\"0\" width=\"80%\"><tr>"
    "<td align=\"center\"><a href=\"http://code.google.com/p/b-tk/#Copyright_Notice\">Licensing Information</a></td>"
    "<td align=\"center\"><a href=\"http://code.google.com/p/b-tk/\">Website</a></td>"
    "</tr></table>");
};

QString qMokkaCoreApplication::acknowledgment() const
{
  return QStringLiteral(
    "<br /><br />");
};

int qMokkaCoreApplication::majorVersion() const
{
  return MOKKA_VERSION_MAJOR;
};

int qMokkaCoreApplication::minorVersion() const
{
  return MOKKA_VERSION_MINOR;
};

int qMokkaCoreApplication::patchVersion() const
{
  return MOKKA_VERSION_PATCH;
};

QString qMokkaCoreApplication::platform() const
{
  return QString("%1-%2").arg(this->os()).arg(this->arch());
};

QString qMokkaCoreApplication::arch() const
{
#if defined(Q_PROCESSOR_X86_64)
  return QStringLiteral("x86_64");
#else
  return QStringLiteral("x86");
#endif
};

QString qMokkaCoreApplication::os() const
{
#if defined(Q_OS_DARWIN)
    return QStringLiteral("darwin");
#elif defined(Q_OS_LINUX)
    return QStringLiteral("linux");
#elif defined(Q_OS_CYGWIN)
    return QStringLiteral("cygwin");
#elif defined(Q_OS_WIN)
    return QStringLiteral("win");
#else
  return QStringLiteral("unknown");
#endif
};

// ------------------------------------------------------------------------- //

void qMokkaCoreApplication::restart()
{
  qMokkaCoreApplication* app = qMokkaCoreApplication::application();
  QProcess::startDetached(app->applicationFilePath(), app->arguments());
  QCoreApplication::quit();
};

qMokkaAcquisition* qMokkaCoreApplication::openAcquisition(const QString& filename)
{
  Q_D(qMokkaCoreApplication);
  qMokkaAcquisition* acq = new qMokkaAcquisition;
  acq->setFileName(filename);
  qMokkaPoint* p = new qMokkaPoint;
  acq->appendPoint(p);
  d->CoreDataManager->appendAcquisition(acq);
  return acq;
};