/* Program for creating a font and zoom it */
/* Date: 15 Nov 2005 */
/* Author: Srinivas Nayak */
/* Compile using Microsoft VC++ 6.0 */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */

//this is a win32 application
//not a console application!

// testgraph.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

#define MAX_LOADSTRING 100
//*****************************
//*****************************
#include<stdio.h>
#include<math.h>
//*****************************
//*****************************
// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_TESTGRAPH, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_TESTGRAPH);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_TESTGRAPH);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_TESTGRAPH;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

	switch (message)
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam);
			wmEvent = HIWORD(wParam);
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
			RECT rt;
			GetClientRect(hWnd, &rt);
			//DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************

{
int x=100,y=100,color=500,row,col;
int original_height=10,original_width=10;
////// column == width , row == height //////
int original[10][10]={
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,4,4,0,0,0,0},
                    {0,0,0,4,4,4,4,0,0,0},
                    {0,0,4,4,0,0,4,4,0,0},
                    {0,4,4,0,0,0,0,4,4,0},
                    {0,4,4,0,0,0,0,4,4,0},
                    {0,4,4,4,4,4,4,4,4,0},
                    {0,4,4,4,4,4,4,4,4,0},
                    {0,4,4,0,0,0,0,4,4,0},
                    {0,4,4,0,0,0,0,4,4,0}
                  };
for (row=0;row<original_height;row++)
for (col=0;col<original_width;col++)
    if(original[row][col]==4)
        original[row][col]=8388352;

for (row=0;row<original_height;row++)
for (col=0;col<original_width;col++)
    SetPixel(hdc,400+col,50+row,original[row][col]);

int zoom[100][100];
int width_zoomfactor = 3;
int height_zoomfactor = 3;
int zoom_row,zoom_col;

for (zoom_row=0; zoom_row < original_height * height_zoomfactor; zoom_row++)
for (zoom_col=0; zoom_col < original_width * width_zoomfactor; zoom_col++)
    zoom[zoom_row][zoom_col] =0;

for (zoom_row=0,row=0; zoom_row < original_height * height_zoomfactor; zoom_row++,row++)
{
for (zoom_col=0,col=0; zoom_col < original_width * width_zoomfactor; zoom_col++,col++)
{
    zoom[zoom_row][zoom_col]= original[row][col];
    zoom_col +=width_zoomfactor-1;
}
    zoom_row +=height_zoomfactor-1;
}

int fill_green=0;

for (zoom_row=0; zoom_row < original_height * height_zoomfactor; zoom_row++)
for (zoom_col=0; zoom_col < original_width * width_zoomfactor; zoom_col++)
{
if(fill_green==0 && zoom[zoom_row][zoom_col]==8388352 && zoom[zoom_row][zoom_col-1]== 0)
    fill_green=1;
if(fill_green ==1 && zoom[zoom_row][zoom_col]==8388352 && zoom[zoom_row][zoom_col+1]== 8388352)
   fill_green= 0;
if(fill_green==1)
    zoom[zoom_row][zoom_col+1]= 8388352;
}
for (zoom_row=0; zoom_row < original_height * height_zoomfactor; zoom_row++)
for (zoom_col=0; zoom_col < original_width * width_zoomfactor; zoom_col++)
{
if(fill_green==0 && zoom[zoom_row][zoom_col]==8388352 && zoom[zoom_row][zoom_col-1]== 0)
    fill_green=1;
if(fill_green ==1 && zoom[zoom_row][zoom_col]==8388352 && zoom[zoom_row][zoom_col+1]== 8388352)
   fill_green= 0;
if(fill_green==1)
    zoom[zoom_row][zoom_col+1]= 8388352;
}
for (zoom_row=0; zoom_row < original_height * height_zoomfactor; zoom_row++)
for (zoom_col=0; zoom_col < original_width * width_zoomfactor; zoom_col++)
    SetPixel(hdc,zoom_col,zoom_row,zoom[zoom_row][zoom_col]);

}
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
//**********************************************************************
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
