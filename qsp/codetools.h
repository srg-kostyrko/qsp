/* Copyright (C) 2001-2020 Valeriy Argunov (byte AT qsp DOT org) */
/*
* This library is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2.1 of the License, or
* (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "declarations.h"

#ifndef QSP_CODETOOLSDEFINES
    #define QSP_CODETOOLSDEFINES

    #define QSP_EOLEXT QSP_FMT("_")
    #define QSP_PREEOLEXT QSP_FMT(" ")

    typedef struct
    {
        int StartPos;
        int EndPos;
    } QSPCachedArg;

    typedef struct
    {
        int Stat;
        int ParamPos;
        int EndPos;
        QSPCachedArg *Args;
        int ArgsCount;
        int ErrorCode;
    } QSPCachedStat;

    typedef struct
    {
        QSPString Str;
        int LineNum;
        QSP_BOOL IsMultiline;
        QSPString Label;
        QSPCachedStat *Stats;
        int StatsCount;
    } QSPLineOfCode;

    /* External functions */
    QSPString qspGetLineLabel(QSPString str);
    void qspInitLineOfCode(QSPLineOfCode *line, QSPString str, int lineNum);
    void qspFreeLineOfCode(QSPLineOfCode *line);
    void qspFreePrepLines(QSPLineOfCode *, int);
    void qspCopyPrepLines(QSPLineOfCode **, QSPLineOfCode *, int, int);
    QSPString qspJoinPrepLines(QSPLineOfCode *s, int count, QSPString delim);
    void qspPrepareStringToExecution(QSPString *str);
    int qspPreprocessData(QSPString data, QSPLineOfCode **strs);

#endif
