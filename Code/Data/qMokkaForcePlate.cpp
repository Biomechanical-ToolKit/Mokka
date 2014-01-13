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
 
#include "qMokkaForcePlate.h"
#include "qMokkaForcePlate_p.h"

// ------------------------------------------------------------------------- //
//                            qMokkaForcePlatePrivate                       //
// ------------------------------------------------------------------------- //

qMokkaForcePlatePrivate::qMokkaForcePlatePrivate(qMokkaForcePlate* q)
: q_ptr(q)
{};

qMokkaForcePlatePrivate::~qMokkaForcePlatePrivate()
{};

// ------------------------------------------------------------------------- //
//                               qMokkaForcePlate                           //
// ------------------------------------------------------------------------- //

qMokkaForcePlate::qMokkaForcePlate(QObject* parent)
: QObject(parent),
  d_ptr(new qMokkaForcePlatePrivate(this))
{};

qMokkaForcePlate::~qMokkaForcePlate()
{};

QString qMokkaForcePlate::label() const
{
  return "";
};

void qMokkaForcePlate::setLabel(const QString& l)
{};

QString qMokkaForcePlate::description() const
{
  return "";
};

void qMokkaForcePlate::setDescription(const QString& d)
{};