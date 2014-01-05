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

#include "qMokkaApplication.h"
#include "qMokkaApplication_p.h"
#include "qMokkaPythonManager.h"
#include "qMokkaDataManager.h"

// ------------------------------------------------------------------------- //
//                           qMokkaApplicationPrivate                        //
// ------------------------------------------------------------------------- //

qMokkaApplicationPrivate::qMokkaApplicationPrivate(qMokkaApplication* q)
: qMokkaCoreApplicationPrivate(q)
{};


qMokkaApplicationPrivate::~qMokkaApplicationPrivate()
{};

void qMokkaApplicationPrivate::initialize()
{
  Q_Q(qMokkaApplication);
  q->setPythonManager(new qMokkaPythonManager);
  q->setDataManager(new qMokkaDataManager);
  
  this->qMokkaCoreApplicationPrivate::initialize();
};

// ------------------------------------------------------------------------- //
//                               qMokkaApplication                           //
// ------------------------------------------------------------------------- //

qMokkaApplication* qMokkaApplication::application()
{
  qMokkaApplication* app = qobject_cast<qMokkaApplication*>(QApplication::instance());
  return app;
};

qMokkaApplication::qMokkaApplication(int& argc, char** argv)
: qMokkaCoreApplication(*new qMokkaApplicationPrivate(this), argc, argv)
{
  Q_D(qMokkaApplication);
  d->initialize();
};

qMokkaApplication::~qMokkaApplication()
{};