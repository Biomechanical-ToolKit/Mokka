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

#ifndef __qMokkaAcquisition_h
#define __qMokkaAcquisition_h

#include <QObject>
#include <QScopedPointer>
#include <QVariantMap>
#include <QVariantList>

class qMokkaPoint;

class qMokkaAcquisitionPrivate;

class qMokkaAcquisition : public QObject
{
  Q_OBJECT
  
  Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
  Q_PROPERTY(QVariantMap points READ variantPoints)
  Q_PROPERTY(QVariantMap analogs READ variantAnalogs)
  Q_PROPERTY(QVariantList events READ variantEvents)
  Q_PROPERTY(QVariantMap forceplates READ variantForcePlates)
  Q_PROPERTY(QVariantMap imus READ variantIMUs)
    
public:
  qMokkaAcquisition(QObject* parent = 0);
  ~qMokkaAcquisition();
  
  const QString& fileName() const;
  void setFileName(const QString& file);

  int frameNumber() const;
  void setFrameNumber(int num);
  
  void appendPoint(qMokkaPoint* p);
public slots:
  void clear();
  
private:
  Q_DECLARE_PRIVATE(qMokkaAcquisition);
  Q_DISABLE_COPY(qMokkaAcquisition);
  
  QVariantMap variantPoints() const;
  QVariantMap variantAnalogs() const;
  QVariantList variantEvents() const;
  QVariantMap variantForcePlates() const;
  QVariantMap variantIMUs() const;
  
  const QScopedPointer<qMokkaAcquisitionPrivate> d_ptr;
};

#endif // __qMokkaAcquisition_h