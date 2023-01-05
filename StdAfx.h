// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- StdAfx.h : include file for standard system include files,
//-----      or project specific include files that are used frequently,
//-----      but are changed infrequently
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
#ifdef _FULLDEBUG_
#pragma message ("Warning! You should not run this application in a Standard AutoCAD release.")
#pragma message ("         Due to the memory managment constraints.")
#endif

#pragma warning(disable: 4786)
//#pragma warning(disable: 4098)

//-----------------------------------------------------------------------------
#define STRICT

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN			//----- Exclude rarely-used stuff from Windows headers
#endif

//----- Modify the following defines if you have to target a platform prior to the ones specified below.
//----- Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER					//----- Allow use of features specific to Windows 95 and Windows NT 4 or later.
#define WINVER 0X0A00			//----- Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif

#ifndef _WIN32_WINNT			//----- Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0X0A00		//----- Change this to the appropriate value to target Windows 2000 or later.
#endif						

#ifndef _WIN32_WINDOWS			//----- Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0A00	//----- Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE				//----- Allow use of features specific to IE 4.0 or later.
#define _WIN32_IE 0X0A00		//----- Change this to the appropriate value to target IE 5.0 or later.
#endif

//-----------------------------------------------------------------------------
#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	//----- Some CString constructors will be explicit
//----- Turns off ATL's hiding of some common and often safely ignored warning messages
#define _ATL_ALL_WARNINGS

//-----------------------------------------------------------------------------
//----- 'DEBUG workaround' below prevents the MFC or ATL #include-s from pulling 
//----- in "Afx.h" that would force the debug CRT through #pragma-s.
#if defined(_DEBUG) && !defined(_FULLDEBUG_)
#define _DEBUG_WAS_DEFINED
#undef _DEBUG
#pragma message ("     Compiling MFC / STL / ATL header files in release mode.")
#endif

//----- ObjectARX and OMF headers needs this
#include <map>

//-----------------------------------------------------------------------------
#include <afxwin.h>				//----- MFC core and standard components
#include <afxext.h>				//----- MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>				//----- MFC OLE classes
#include <afxodlgs.h>			//----- MFC OLE dialog classes
#include <afxdisp.h>			//----- MFC Automation classes
#endif //----- _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>				//----- MFC ODBC database classes
#endif //----- _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>				//----- MFC DAO database classes
#endif //----- _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>			//----- MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>				//----- MFC support for Windows Common Controls
#endif //----- _AFX_NO_AFXCMN_SUPPORT


//-----------------------------------------------------------------------------
#include <AtlBase.h>
#include <AtlCom.h>
using namespace ATL ;

// AutoCAD MFC Extensions:
#include "adui.h"
#include "acui.h"
#include "acuiComboBox.h"
#include "acuiDialog.h"
//-----------------------------------------------------------------------------
#ifdef _DEBUG_WAS_DEFINED
#define _DEBUG
#undef _DEBUG_WAS_DEFINED
#endif

extern HINSTANCE _hdllInstance ;
#include "rxdebug.h"
// RX Includes
#include "acdb.h"               // acdb definitions
#include "rxregsvc.h"           // ARX linker
#include "dbapserv.h"           // Host application services
#include "aced.h"               // aced stuff
#include "rxmfcapi.h"           // ObjectARX MFC support
#include "AcExtensionModule.h"  // Utility class for extension dlls
#include "AcString.h"
#include "acadi.h"
#include "axtempl.h"
#include "acpi.h"
#include <atlctl.h>
///////////////////////////
#include "AcImportXml.h"
using namespace MSXML;
