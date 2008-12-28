/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2008 Scientific Computing and Imaging Institute,
   University of Utah.

   
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

/**
  \file    QTOut.h
  \author    Jens Krueger
        SCI Institute
        University of Utah
  \version  1.0
  \date    August 2008
*/


#pragma once

#ifndef QTOut_H
#define QTOut_H

#include "../../Tuvok/DebugOut/AbstrDebugOut.h"
#include <QtGui/QListWidget>

#include <deque>

class QTOut : public AbstrDebugOut{
  public:
    QTOut(QListWidget *listWidget);
    virtual ~QTOut();

    virtual void printf(const char* format, ...);
    virtual void Message(const char* source, const char* format, ...);
    virtual void Warning(const char* source, const char* format, ...);
    virtual void Error(const char* source, const char* format, ...);

    virtual void PrintErrorList();
    virtual void PrintWarningList();
    virtual void PrintMessageList();
    virtual void ClearErrorList()   {m_strErrorList.clear();}
    virtual void ClearWarningList() {m_strWarningList.clear();}
    virtual void ClearMessageList() {m_strMessageList.clear();}
    virtual void SetListRecordingErrors(bool bRecord)   {m_bRecordLists[0] = bRecord;}
    virtual void SetListRecordingWarnings(bool bRecord) {m_bRecordLists[1] = bRecord;}
    virtual void SetListRecordingMessages(bool bRecord) {m_bRecordLists[2] = bRecord;}
    virtual bool GetListRecordingErrors()   {return m_bRecordLists[0];}
    virtual bool GetListRecordingWarnings() {return m_bRecordLists[1];}
    virtual bool GetListRecordingMessages() {return m_bRecordLists[2];}

  private:
    QListWidget *m_listWidget;

    bool                      m_bRecordLists[3];
    std::deque< std::string > m_strErrorList;
    std::deque< std::string > m_strWarningList;
    std::deque< std::string > m_strMessageList;

    void _printf(const char* format, ...);

};

#endif // QTOut_H
