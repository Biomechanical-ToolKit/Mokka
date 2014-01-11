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
 
#include "qMokkaAcquisition.h"
#include "qMokkaAcquisition_p.h"
#include "qMokkaPoint.h"
#include "qMokkaAnalog.h"
#include "qMokkaEvent.h"

// ------------------------------------------------------------------------- //
//                            qMokkaAcquisitionPrivate                       //
// ------------------------------------------------------------------------- //

qMokkaAcquisitionPrivate::qMokkaAcquisitionPrivate(qMokkaAcquisition* q)
: q_ptr(q),
  filename(), points(), analogs(), events()
{};

qMokkaAcquisitionPrivate::~qMokkaAcquisitionPrivate()
{
  QList<qMokkaPoint*>::iterator itP = this->points.begin();
  while (itP != this->points.end())
  {
    delete *itP;
    itP = this->points.erase(itP);
  }
  QList<qMokkaAnalog*>::iterator itA = this->analogs.begin();
  while (itA != this->analogs.end())
  {
    delete *itA;
    itA = this->analogs.erase(itA);
  }
  QList<qMokkaEvent*>::iterator itE = this->events.begin();
  while (itE != this->events.end())
  {
    delete *itE;
    itE = this->events.erase(itE);
  }
};

// ------------------------------------------------------------------------- //
//                               qMokkaAcquisition                           //
// ------------------------------------------------------------------------- //

qMokkaAcquisition::qMokkaAcquisition(QObject* parent)
: QObject(parent),
  d_ptr(new qMokkaAcquisitionPrivate(this))
{};

qMokkaAcquisition::~qMokkaAcquisition()
{
  qDebug("qMokkaAcquisition::~qMokkaAcquisition");
};

const QString& qMokkaAcquisition::fileName() const
{
  Q_D(const qMokkaAcquisition);
  return d->filename;
};

void qMokkaAcquisition::setFileName(const QString& path)
{
  Q_D(qMokkaAcquisition);
  d->filename = path;
};

int qMokkaAcquisition::frameNumber() const
{
  return 0;
};

void qMokkaAcquisition::setFrameNumber(int num)
{};


void qMokkaAcquisition::appendPoint(qMokkaPoint* p)
{
  Q_D(qMokkaAcquisition);
  for (QList<qMokkaPoint*>::iterator itP = d->points.begin() ; itP != d->points.end() ; ++itP)
  {
    if (*itP == p)
    {
      qWarning("Point already in the list!");
      return;
    }
  }
  d->points.append(p);
};

QVariantMap qMokkaAcquisition::variantPoints() const
{
  Q_D(const qMokkaAcquisition);
  QVariantMap map;
  for (QList<qMokkaPoint*>::const_iterator itP = d->points.begin() ; itP != d->points.end() ; ++itP)
    map.insert((*itP)->label(), QVariant::fromValue(static_cast<QObject*>(*itP)));
  return map;
};

QVariantMap qMokkaAcquisition::variantAnalogs() const
{
  Q_D(const qMokkaAcquisition);
  QVariantMap map;
  for (QList<qMokkaAnalog*>::const_iterator itA = d->analogs.begin() ; itA != d->analogs.end() ; ++itA)
    map.insert((*itA)->label(), QVariant::fromValue(static_cast<QObject*>(*itA)));
  return map;
};

QVariantList qMokkaAcquisition::variantEvents() const
{
  Q_D(const qMokkaAcquisition);
  QVariantList list;
  for (QList<qMokkaEvent*>::const_iterator itE = d->events.begin() ; itE != d->events.end() ; ++itE)
    list.append(QVariant::fromValue(static_cast<QObject*>(*itE)));
  return list;
};
