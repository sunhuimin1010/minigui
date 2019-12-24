///////////////////////////////////////////////////////////////////////////////
//
//                          IMPORTANT NOTICE
//
// The following open source license statement does not apply to any
// entity in the Exception List published by FMSoft.
//
// For more information, please visit:
//
// https://www.fmsoft.cn/exception-list
//
//////////////////////////////////////////////////////////////////////////////
/*
 *   This file is part of MiniGUI, a mature cross-platform windowing 
 *   and Graphics User Interface (GUI) support system for embedded systems
 *   and smart IoT devices.
 * 
 *   Copyright (C) 2002~2018, Beijing FMSoft Technologies Co., Ltd.
 *   Copyright (C) 1998~2002, WEI Yongming
 * 
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 * 
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 * 
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *   Or,
 * 
 *   As this program is a library, any link to this program must follow
 *   GNU General Public License version 3 (GPLv3). If you cannot accept
 *   GPLv3, you need to be licensed from FMSoft.
 * 
 *   If you have got a commercial license of this program, please use it
 *   under the terms and conditions of the commercial license.
 * 
 *   For more information about the commercial license, please refer to
 *   <http://www.minigui.com/blog/minigui-licensing-policy/>.
 */
/*
** systext.c: GetSysText function.
**
** Current maintainer: Wei Yongming.
**
** Create date: 2000/12/31
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "minigui.h"
#include "gdi.h"
#include "window.h"

/*
 * This function translates system strings.
 * You can use gettext to return the text.
 *
 * System text as follows:
 *
 const char* SysText [] =
 {
    "Windows",                  // 0
    "Start",                    // 1
    "Refresh Background",       // 2
    "Close All Windows",        // 3
    "End Session",              // 4
    "Operations",               // 5
    "Minimize",                 // 6
    "Maximize",                 // 7
    "Restore",                  // 8
    "Close",                    // 9
    "OK",                       // 10
    "Next",                     // 11
    "Cancel",                   // 12
    "Previous",                 // 13
    "Yes",                      // 14
    "No",                       // 15
    "Abort",                    // 16
    "Retry",                    // 17
    "Ignore",                   // 18
    "About MiniGUI...",         // 19
    "Open File",                // 20
    "Save File",                // 21
    "Color Selection",          // 22
    "Switch Layer",             // 23
    "Delete Layer",             // 24
    "Error",                     // 25
    "LOGO",                      // 26 
    "Current Path",              // 27 
    "File",                      // 28 
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_MGCTRL_LISTVIEW)
    "Location",                 //0 + 29
    "Up",                       //1 + 29
    "Name",                     //2 + 29
    "Size",                     //3 + 29
    "Access Mode",              //4 + 29
    "Last Modify Time",         //5 + 29
    "Open",                     //6 + 29
    "File Name",                //7 + 29
    "File Type",                //8 + 29
    "Show Hide File",           //9 + 29
    "Sorry! not find %s ", //10 + 29
    "Can't Read %s !",        //11 + 29
    "Can't Write  %s !",      //12 + 29
    "Information",              //13 + 29
    "R",                        //14 + 29
    "W",                        //15 + 29
    "WR",                       //16 + 29
    "Save",                     //17 + 29
    "File %s exists, Replace or not?", //18 + 29
#endif
    NULL
};
*/

const char** local_SysText;

const char* SysText [] =
{
    "Windows",                  // 0
    "Start",                    // 1
    "Refresh Background",       // 2
    "Close All Windows",        // 3
    "End Session",              // 4
    "Operations",               // 5
    "Minimize",                 // 6
    "Maximize",                 // 7
    "Restore",                  // 8
    "Close",                    // 9
    "OK",                       // 10
    "Next",                     // 11
    "Cancel",                   // 12
    "Previous",                 // 13
    "Yes",                      // 14
    "No",                       // 15
    "Abort",                    // 16
    "Retry",                    // 17
    "Ignore",                   // 18
    "About MiniGUI...",         // 19
    "Open File",                // 20
    "Save File",                // 21
    "Color Selection",          // 22
    "Switch Layer",             // 23
    "Delete Layer",             // 24
    "Error",                     // 25
    "LOGO",                      // 26 
    "Current Path",              // 27 
    "File",                      // 28 
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_MGCTRL_LISTVIEW)
    "Location",                 //0 + 29
    "Up",                       //1 + 29
    "Name",                     //2 + 29
    "Size",                     //3 + 29
    "Access Mode",              //4 + 29
    "Last Modify Time",         //5 + 29
    "Open",                     //6 + 29
    "File Name",                //7 + 29
    "File Type",                //8 + 29
    "Show Hide File",           //9 + 29
    "Sorry! not find %s ", //10 + 29
    "Can't Read %s !",        //11 + 29
    "Can't Write  %s !",      //12 + 29
    "Information",              //13 + 29
    "R",                        //14 + 29
    "W",                        //15 + 29
    "WR",                       //16 + 29
    "Save",                     //17 + 29
    "File %s exists, Replace or not?", //18 + 29
#endif
    NULL
};

#if defined(_MGCHARSET_GB) | defined (_MGCHARSET_GBK) | defined (_MGCHARSET_GB18030)
static const char* SysText_GB [] =
{
    "\xb4\xb0\xbf\xda\x0",
    "\xbf\xaa\xca\xbc\x0",
    "\xcb\xa2\xd0\xc2\xb1\xb3\xbe\xb0\x0",
    "\xb9\xd8\xb1\xd5\xcb\xf9\xd3\xd0\xb4\xb0\xbf\xda\x0",
    "\xbd\xe1\xca\xf8\xbb\xe1\xbb\xb0\x0",
    "\xb4\xb0\xbf\xda\xb2\xd9\xd7\xf7\x0",
    "\xd7\xee\xd0\xa1\xbb\xaf\x0",
    "\xd7\xee\xb4\xf3\xbb\xaf\x0",
    "\xbb\xd6\xb8\xb4\x0",
    "\xb9\xd8\xb1\xd5\x0",
    "\xc8\xb7\xb6\xa8\x0",
    "\xcf\xc2\xd2\xbb\xb2\xbd\x0",
    "\xc8\xa1\xcf\xfb\x0",
    "\xc9\xcf\xd2\xbb\xb2\xbd\x0",
    "\xca\xc7\x28\x59\x29\x0",
    "\xb7\xf1\x28\x4e\x29\x0",
    "\xd6\xd5\xd6\xb9\x28\x41\x29\x0",
    "\xd6\xd8\xca\xd4\x28\x52\x29\x0",
    "\xba\xf6\xc2\xd4\x28\x49\x29\x0",
    "\xb9\xd8\xd3\xda\x20\x4d\x69\x6e\x69\x47\x55\x49\x2e\x2e\x2e\x0",
    "\xb4\xf2\xbf\xaa\xce\xc4\xbc\xfe\x0",
    "\xb1\xa3\xb4\xe6\xce\xc4\xbc\xfe\x0",
    "\xd1\xd5\xc9\xab\xd1\xa1\xd4\xf1\x0",
    "\xc7\xd0\xbb\xbb\xb2\xe3\x0",
    "\xc9\xbe\xb3\xfd\xb2\xe3\x0",
    "\xb4\xed\xce\xf3\x0",
    "\xcd\xbc\xb1\xea\x0",
    "\xb5\xb1\xc7\xb0\xc2\xb7\xbe\xb6\x0",
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_MGCTRL_LISTVIEW)
    "\xce\xc4\xbc\xfe\x0",
    "\xb2\xe9\xd5\xd2\xce\xbb\xd3\xda\x0",
    "\xc9\xcf\xd2\xbb\xbc\xb6\x0",
    "\xc3\xfb\xb3\xc6\x0",
    "\xb4\xf3\xd0\xa1\x0",
    "\xb7\xc3\xce\xca\xc8\xa8\xcf\xde\x0",
    "\xc9\xcf\xb4\xce\xd0\xde\xb8\xc4\xca\xb1\xbc\xe4\x0",
    "\xb4\xf2\xbf\xaa\x0",
    "\xce\xc4\x20\xbc\xfe\x20\xc3\xfb\x0",
    "\xce\xc4\xbc\xfe\xc0\xe0\xd0\xcd\x0",
    "\xcf\xd4\xca\xbe\xd2\xfe\xb2\xd8\xce\xc4\xbc\xfe\x0",
    "\xb6\xd4\xb2\xbb\xc6\xf0\xa3\xac\xce\xb4\xd5\xd2\xb5\xbd\xd6\xb8\xb6\xa8\xb5\xc4\xc4\xbf\xc2\xbc\xa3\xba\x20\x25\x73\x20\x0",
    "\xb2\xbb\xc4\xdc\xb6\xc1\xc8\xa1\x20\x25\x73\x20\x21\x0",
    "\xb6\xd4\x20\x25\x73\x20\xc3\xbb\xd3\xd0\xd0\xb4\xc8\xa8\xcf\xde\x21\x0",
    "\xcc\xe1\xca\xbe\xd0\xc5\xcf\xa2\x0",
    "\xb6\xc1\x0",
    "\xd0\xb4\x0",
    "\xb6\xc1\xd0\xb4\x0",
    "\xb1\xa3\xb4\xe6\x0",
#endif
};
#endif

#ifdef _MGCHARSET_BIG5
static const char* SysText_BIG5 [] =
{
    "\xb5\xa1\xa4\x66\x0",
    "\xc9\xdb\xa9\x6c\x0",
    "\xa8\xea\xb7\x73\xad\x49\xb4\xba\x0",
    "\xc3\xf6\xb3\xac\xa9\xd2\xa6\xb3\xb5\xa1\xa4\x66\x0",
    "\xb5\xb2\xa7\xf4\xb7\x7c\xb8\xdc\x0",
    "\xb5\xa1\xa4\x66\xbe\xde\xa7\x40\x0",
    "\xb3\xcc\xa4\x70\xa4\xc6\x0",
    "\xb3\xcc\xa4\x6a\xa4\xc6\x0",
    "\xab\xec\xce\x60\x0",
    "\xc3\xf6\xb3\xac\x0",
    "\xda\xcc\xa9\x77\x0",
    "\xa4\x55\xa4\x40\xa8\x42\x0",
    "\xa8\xfa\xae\xf8\x0",
    "\xa4\x57\xa4\x40\xa8\x42\x0",
    "\xac\x4f\x28\x59\x29\x0",
    "\xa7\x5f\x28\x4e\x29\x0",
    "\xb2\xd7\xa4\xee\x28\x41\x29\x0",
    "\xad\xab\xb8\xd5\x28\x52\x29\x0",
    "\xa9\xbf\xb2\xa4\x28\x49\x29\x0",
    "\xc3\xf6\xa4\x5f\x20\x4d\x69\x6e\x69\x47\x55\x49\x2e\x2e\x2e\x0",
    "\xa5\xb4\xb6\x7d\xa4\xe5\xa5\xf3\x0",
    "\xab\x4f\xa6\x73\xa4\xe5\xa5\xf3\x0",
    "\xc3\x43\xa6\xe2\xbf\xef\xbe\xdc\x0",
    "\xa4\xc1\xb4\xab\xbc\x68\x0",
    "\xa7\x52\xb0\xa3\xbc\x68\x0",
    "\xbf\xf9\xbb\x7e\x0",
    "\xb9\xcf\xbc\xd0\x0",
    "\xb7\xed\xab\x65\xb8\xf4\xae\x7c\x0",
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_MGCTRL_LISTVIEW)
    "\xa4\xe5\xa5\xf3\x0",
    "\xac\x64\xa7\xe4\xa6\xec\xa4\x5f\x0",
    "\xa4\x57\xa4\x40\xaf\xc5\x0",
    "\xa6\x57\xba\xd9\x0",
    "\xa4\x6a\xa4\x70\x0",
    "\xb3\x58\xb0\xdd\xc5\x76\xad\xad\x0",
    "\xa4\x57\xa6\xb8\xad\xd7\xa7\xef\xae\xc9\xb6\xa1\x0",
    "\xa5\xb4\xb6\x7d\x0",
    "\xa4\xe5\x20\xa5\xf3\x20\xa6\x57\x0",
    "\xa4\xe5\xa5\xf3\xc3\xfe\xab\xac\x0",
    "\xc5\xe3\xa5\xdc\xc1\xf4\xc2\xc3\xa4\xe5\xa5\xf3\x0",
    "\xb9\xef\xa4\xa3\xb0\x5f\xa1\x41\xa5\xbc\xa7\xe4\xa8\xec\xab\xfc\xa9\x77\xaa\xba\xa5\xd8\xbf\xfd\xa1\x47\x20\x25\x73\x20\x0",
    "\xa4\xa3\xaf\xe0\xc5\xaa\xa8\xfa\x20\x25\x73\x20\x21\x0",
    "\xb9\xef\x20\x25\x73\x20\xa8\x53\xa6\xb3\xbc\x67\xc5\x76\xad\xad\x0",
    "\xb4\xa3\xa5\xdc\xab\x48\xae\xa7\x0",
    "\xc5\xaa\x0",
    "\xbc\x67\x0",
    "\xc5\xaa\xbc\x67\x0",
    "\xab\x4f\xa6\x73\x0",
#endif
};
#endif

void __mg_init_local_sys_text (void)
{
    const char* charset = GetSysCharset (TRUE);

    local_SysText = SysText;

    if (charset == NULL)
        charset = GetSysCharset (FALSE);

#ifdef _MGCHARSET_GB
    if (strcmp (charset, FONT_CHARSET_GB2312_0) == 0) {
        local_SysText = SysText_GB;
	}
#endif

#ifdef _MGCHARSET_GBK
    if (strcmp (charset, FONT_CHARSET_GBK) == 0) {
        local_SysText = SysText_GB;
	}
#endif

#ifdef _MGCHARSET_GB18030
    if (strcmp (charset, FONT_CHARSET_GB18030_0) == 0) {
        local_SysText = SysText_GB;
	}
#endif

#ifdef _MGCHARSET_BIG5
    if (strcmp (charset, FONT_CHARSET_BIG5) == 0) {
        local_SysText = SysText_BIG5;
	}
#endif

}

const char* GUIAPI GetSysText (unsigned int id)
{
    if (id > IDS_MGST_MAXNUM)
        return NULL;
        
    return local_SysText [id];
}

#ifdef _MGCHARSET_UNICODE
static const char* SysText_GB_UTF8 [] =
{
    "\xe7\xaa\x97\xe5\x8f\xa3\x0",
    "\xe5\xbc\x80\xe5\xa7\x8b\x0",
    "\xe5\x88\xb7\xe6\x96\xb0\xe8\x83\x8c\xe6\x99\xaf\x0",
    "\xe5\x85\xb3\xe9\x97\xad\xe6\x89\x80\xe6\x9c\x89\xe7\xaa\x97\xe5\x8f\xa3\x0",
    "\xe7\xbb\x93\xe6\x9d\x9f\xe4\xbc\x9a\xe8\xaf\x9d\x0",
    "\xe7\xaa\x97\xe5\x8f\xa3\xe6\x93\x8d\xe4\xbd\x9c\x0",
    "\xe6\x9c\x80\xe5\xb0\x8f\xe5\x8c\x96\x20\x0",
    "\xe6\x9c\x80\xe5\xa4\xa7\xe5\x8c\x96\x20\x0",
    "\xe6\x81\xa2\xe5\xa4\x8d\x0",
    "\xe5\x85\xb3\xe9\x97\xad\x0",
    "\xe7\xa1\xae\xe5\xae\x9a\x0",
    "\xe4\xb8\x8b\xe4\xb8\x80\xe6\xad\xa5\x0",
    "\xe5\x8f\x96\xe6\xb6\x88\x0",
    "\xe4\xb8\x8a\xe4\xb8\x80\xe6\xad\xa5\x0",
    "\xe6\x98\xaf\x59\x29\x0",
    "\xe6\x98\xaf\x4e\x29\x0",
    "\xe7\xbb\x88\xe6\xad\xa2\x28\x41\x29\x0",
    "\xe9\x87\x8d\xe8\xaf\x95\x28\x52\x29\x0",
    "\xe5\xbf\xbd\xe7\x95\xa5\x28\x49\x29\x0",
    "\xe5\x85\xb3\xe4\xba\x8e\x20\x4d\x69\x6e\x69\x47\x55\x49\x2e\x2e\x2e\x0",
    "\xe6\x89\x93\xe5\xbc\x80\xe6\x96\x87\xe4\xbb\xb6\x0",
    "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6\x0",
    "\xe9\xa2\x9c\xe8\x89\xb2\xe9\x80\x89\xe6\x8b\xa9\x0",
    "\xe5\x88\x87\xe6\x8d\xa2\xe5\xb1\x82\x0",
    "\xe5\x88\xa0\xe9\x99\xa4\xe5\xb1\x82\x0",
    "\xe9\x94\x99\xe8\xaf\xaf\x0",
    "\xe5\x9b\xbe\xe6\xa0\x87\x0",
    "\xe5\xbd\x93\xe5\x89\x8d\xe8\xb7\xaf\xe5\xbe\x84\x0",
    "\xe6\x96\x87\xe4\xbb\xb6\x0",
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_MGCTRL_LISTVIEW)
    "\xe6\x9f\xa5\xe6\x89\xbe\xe4\xbd\x8d\xe4\xba\x8e\x0",
    "\xe4\xb8\x8a\xe4\xb8\x80\xe6\x98\xaf\x0",
    "\xe5\x90\x8d\xe7\xa7\xb0\x0",
    "\xe5\xa4\xa7\xe5\xb0\x8f\x0",
    "\xe8\xae\xbf\xe9\x97\xae\xe6\x9d\x83\xe9\x99\x90\x0",
    "\xe4\xb8\x8a\xe6\xac\xa1\xe4\xbf\xae\xe6\x94\xb9\xe6\x97\xb6\xe9\x97\xb4\x0",
    "\xe6\x89\x93\xe5\xbc\x80\x0",
    "\xe6\x96\x87\x20\x20\xe4\xbb\xb6\x20\x20\xe5\x90\x8d\x0",
    "\xe6\x96\x87\xe4\xbb\xb6\xe7\xb1\xbb\xe5\x9e\x8b\x0",
    "\xe6\x98\xbe\xe7\xa4\xba\xe9\x9a\x90\xe8\x97\x8f\xe6\x96\x87\xe4\xbb\xb6\x0",
    "\xe5\xaf\xb9\xe4\xb8\x8d\xe8\xb5\xb7\xef\xbc\x8c\xe6\x9c\xaa\xe6\x89\xbe\xe5\x88\xb0\xe6\x8c\x87\xe5\xae\x9a\xe7\x9a\x84\xe7\x9b\xae\xe5\xbd\x95\xef\xbc\x9a\x25\x73\x20\x0",
    "\xe4\xb8\x8d\xe8\x83\xbd\xe8\xaf\xbb\xe5\x8f\x96\x20\x25\x73\x20\x21\x0",
    "\xe5\xaf\xb9\x20\x25\x73\x20\xe6\xb2\xa1\xe6\x9c\x89\xe5\x86\x99\xe6\x9d\x83\xe9\x99\x90\x0",
    "\xe6\x8f\x90\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\x0",
    "\xe8\xaf\xbb\x0",
    "\xe5\x86\x99\x0",
    "\xe8\xaf\xbb\xe5\x86\x99\x0",
    "\xe4\xbf\x9d\xe5\xad\x98\x0",
#endif
};

static const char* SysText_BIG5_UTF8 [] =
{
    "\xe7\xaa\x97\xe5\x8f\xa3\x0",
    "\xe9\x96\x8b\xe5\xa7\x8b\x0",
    "\xe5\x88\xb7\xe6\x96\xb0\xe8\x83\x8c\xe6\x99\xaf\x0",
    "\xe9\x97\x9c\xe9\x96\x89\xe6\x89\x80\xe6\x9c\x89\xe7\xaa\x97\xe5\x8f\xa3\x0",
    "\xe7\xb5\x90\xe6\x9d\x9f\xe6\x9c\x83\xe8\xa9\xb1\x0",
    "\xe7\xaa\x97\xe5\x8f\xa3\xe6\x93\x8d\xe4\xbd\x9c\x0",
    "\xe6\x9c\x80\xe5\xb0\x8f\xe5\x8c\x96\x20\x0",
    "\xe6\x9c\x80\xe5\xa4\xa7\xe5\x8c\x96\x20\x0",
    "\xe6\x81\xa2\xe5\xbe\xa9\x0",
    "\xe9\x97\x9c\xe9\x96\x89\x0",
    "\xe7\xa2\xba\xe5\xae\x9a\x0",
    "\xe4\xb8\x8b\xe4\xb8\x80\xe6\xad\xa5\x0",
    "\xe5\x8f\x96\xe6\xb6\x88\x0",
    "\xe4\xb8\x8a\xe4\xb8\x80\xe6\xad\xa5\x0",
    "\xe6\x98\xaf\x59\x29\x0",
    "\xe5\x90\xa6\x4e\x29\x0",
    "\xe7\xb5\x82\xe6\xad\xa2\x28\x41\x29\x0",
    "\xe9\x87\x8d\xe8\xa9\xa6\x28\x52\x29\x0",
    "\xe5\xbf\xbd\xe7\x95\xa5\x28\x49\x29\x0",
    "\xe9\x97\x9c\xe4\xba\x8e\x20\x4d\x69\x6e\x69\x47\x55\x49\x2e\x2e\x2e\x0",
    "\xe6\x89\x93\xe9\x96\x8b\xe6\x96\x87\xe4\xbb\xb6\x0",
    "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6\x0",
    "\xe9\xa1\x8f\xe8\x89\xb2\xe9\x81\xb8\xe6\x93\x87\x0",
    "\xe5\x88\x87\xe6\x8f\x9b\xe5\xb1\xa4\x0",
    "\xe5\x88\xaa\xe9\x99\xa4\xe5\xb1\xa4\x0",
    "\xe9\x8c\xaf\xe8\xaa\xa4\x0",
    "\xe5\x9c\x96\xe6\xa8\x99\x0",
    "\xe7\x95\xb6\xe5\x89\x8d\xe8\xb7\xaf\xe5\xbe\x91\x0",
    "\xe6\x96\x87\xe4\xbb\xb6\x0",
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_MGCTRL_LISTVIEW)
    "\xe6\x9f\xa5\xe6\x89\xbe\xe4\xbd\x8d\xe4\xba\x8e\x0",
    "\xe4\xb8\x8a\xe4\xb8\x80\xe7\xb4\x9a\x0",
    "\xe5\x90\x8d\xe7\xa8\xb1\x0",
    "\xe5\xa4\xa7\xe5\xb0\x8f\x0",
    "\xe8\xa8\xaa\xe5\x95\x8f\xe6\xac\x8a\xe9\x99\x90\x0",
    "\xe4\xb8\x8a\xe6\xac\xa1\xe4\xbf\xae\xe6\x94\xb9\xe6\x99\x82\xe9\x96\x93\x0",
    "\xe6\x89\x93\xe9\x96\x8b\x0",
    "\xe6\x96\x87\x20\x20\xe4\xbb\xb6\x20\x20\xe5\x90\x8d\x0",
    "\xe6\x96\x87\xe4\xbb\xb6\xe9\xa1\x9e\xe5\x9e\x8b\x0",
    "\xe9\xa1\xaf\xe7\xa4\xba\xe9\x9a\xb1\xe8\x97\x8f\xe6\x96\x87\xe4\xbb\xb6\x0",
    "\xe5\xb0\x8d\xe4\xb8\x8d\xe8\xb5\xb7\xef\xbc\x8c\xe6\x9c\xaa\xe6\x89\xbe\xe5\x88\xb0\xe6\x8c\x87\xe5\xae\x9a\xe7\x9a\x84\xe7\x9b\xae\xe9\x8c\x84\xef\xbc\x9a\x25\x73\x20\x21\x0",
    "\xe4\xb8\x8d\xe8\x83\xbd\xe8\xae\x80\xe5\x8f\x96\x20\x25\x73\x20\x21\x0",
    "\xe5\xb0\x8d\x20\x25\x73\x20\xe6\xb2\x92\xe6\x9c\x89\xe5\xaf\xab\xe6\xac\x8a\xe9\x99\x90\x21\x0",
    "\xe6\x8f\x90\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\x0",
    "\xe8\xae\x80\x20\x0",
    "\xe5\xaf\xab\x0",
    "\xe8\xae\x80\xe5\xaf\xab\x0",
    "\xe4\xbf\x9d\xe5\xad\x98\x0",
#endif
};

const char** GUIAPI GetSysTextInUTF8 (const char* language)
{
    if (strncasecmp (language, "zh_CN", 5) == 0) {
        return SysText_GB_UTF8;
	}
    else if (strncasecmp (language, "zh_TW", 5) == 0) {
        return SysText_BIG5_UTF8;
	}

    return SysText;
}
#endif /* _MGCHARSET_UNICODE */

