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

#ifndef __qMokkaCoreApplication_h
#define __qMokkaCoreApplication_h

#include "qMokkaConfigure.h"

#include <QApplication>
#include <QScopedPointer>

class qMokkaCorePythonManager;

// class QSettings;

class qMokkaCoreApplicationPrivate;

class qMokkaCoreApplication : public QApplication
{
  Q_OBJECT
  
  Q_PROPERTY(int majorVersion READ majorVersion CONSTANT)
  Q_PROPERTY(int minorVersion READ minorVersion CONSTANT)
  Q_PROPERTY(int patchVersion READ patchVersion CONSTANT)
  Q_PROPERTY(QString platform READ platform CONSTANT)
  Q_PROPERTY(QString arch READ arch CONSTANT)
  Q_PROPERTY(QString os READ os CONSTANT)
  
public:
  /// Return a reference to the application singleton
  static qMokkaCoreApplication* application();
  
  qMokkaCoreApplication(int& argc, char** argv);
  virtual ~qMokkaCoreApplication();
  
#ifdef MOKKA_USE_PYTHON
  /// Get python manager
  qMokkaCorePythonManager* pythonManager() const;

  /// Set the python manager and take ownership of it
  void setPythonManager(qMokkaCorePythonManager* manager);
#endif

  /// Return the copyrights of Mokka
  virtual QString copyrights() const;

  /// Return the acknowledgment text of Mokka
  virtual QString acknowledgment() const;

  /// Return the libraries of Mokka
  virtual QString libraries() const;

  /// Return the Mokka major version number
  int majorVersion() const;

  /// Return the Mokka minor version number
  int minorVersion() const;
  
  /// Return the Mokka minor version number
  int patchVersion() const;

  /// Return the \a platform associated to this build
  QString platform() const;

  /// Return the \a arch associated to this build
  QString arch() const;

  /// Return the \a os associated to this build
  QString os() const;
  
  // Return the settings associated with the Mokka application
  // QSettings* settings() const;

public slots:
  /// Restart the application with the arguments passed at startup time
  static void restart();

protected:
  /// Constructor which could be used by inheriting class.
  /// This constructor doesn't call the qMokkaCoreApplicationPrivate::init() method and must be done manually in the inheriting class
  qMokkaCoreApplication(qMokkaCoreApplicationPrivate& dd, int& argc, char** argv);
  
  const QScopedPointer<qMokkaCoreApplicationPrivate> d_ptr;

private:
  Q_DISABLE_COPY(qMokkaCoreApplication);
  Q_DECLARE_PRIVATE(qMokkaCoreApplication);
};

#endif // __qMokkaCoreApplication_h