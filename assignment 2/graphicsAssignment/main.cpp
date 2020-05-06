
#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <windows.h>

#include <tchar.h>
#include <windows.h>
#include<bits/stdc++.h>
#include "point.h"
#include "line.h"
#include "circle.h"
#include "curve.h"

using namespace std;


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument,
                   int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof(WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx(&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx(
               0,                   /* Extended possibilites for variation */
               szClassName,         /* Classname */
               _T("Code::Blocks Template Windows App"),       /* Title Text */
               WS_OVERLAPPEDWINDOW, /* default window */
               CW_USEDEFAULT,       /* Windows decides the position */
               CW_USEDEFAULT,       /* where the window ends up on the screen */
               1200,                 /* The programs width */
               600,                 /* and height in pixels */
               HWND_DESKTOP,        /* The window is a child-window to desktop */
               NULL,                /* No menu */
               hThisInstance,       /* Program Instance handler */
               NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow(hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage(&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */
circle cir;
line lin;
curve cur;
bool flag = false;
bool input = false;
bool draw = true;
bool firstTime = true;
int x, y;
int choice = 4;
point c, r;
int counter;
vector<point> points;
vector<point> Hpoints;
vector<int> Hchoice;

DWORD WINAPI consoleInput(LPVOID lpParameter)
{

    if (firstTime)
    {
        firstTime = false;
        draw = true;
        return 0;

    }
    cout << "1- Line" << endl;
    cout << "2- Circle" << endl;
    cout << "3- Curve" << endl;
    cout << "4- New Frame" << endl;
    cout << "5- Exit" << endl;
    cout << "Your choice : " << endl;
    cin >> choice;
    if (choice == 5)
        exit(0);
    draw = true;
    return 0;
}

int main()
{
    DWORD myThreadID;
    HANDLE myHandle = CreateThread(0, 0, consoleInput, 0, 0, &myThreadID);
    CloseHandle(myHandle);
    return WinMain(GetModuleHandle(NULL), NULL, NULL, SW_SHOWNORMAL);
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT p;
    switch (message)                  /* handle the messages */
    {
    case WM_PAINT:
        BeginPaint(hwnd, &p);
        if (flag)
        {
            counter = 0;
            if (choice==4)
            {
                cir.frame(p.hdc,c,lin.length(c,r));
            }
            else if (choice==1)
            {
                lin.draw(p.hdc,points[0],points[1],c,r);
            }
            else if (choice==2)
            {
                cir.draw(p.hdc,points[0],c,r,lin.length(points[0],points[1]));
            }
            else if (choice==3)
            {
                cur.draw(p.hdc,points[0],points[1],points[2],points[3],c,r);
            }
            points.clear();
            flag = false;
            EndPaint(hwnd,&p);
            if(draw)
            {
                draw = false;
                return main();
            }
        }

        EndPaint(hwnd, &p);
        break;
    case WM_LBUTTONDOWN:
        if(!flag && choice!=3)
        {
            x = LOWORD(lParam);
            y = HIWORD(lParam);
            points.push_back(point(x,y));
            cout<<"point "<<points.size()<<endl;
            if (points.size()==2)
            {
                flag=true;

            }
            if(choice==4)
            {
                c=points[0];
                r=points[1];
            }
        }
        else if(!flag && choice==3)
        {
            x = LOWORD(lParam);
            y = HIWORD(lParam);
            points.push_back(point(x,y));
            cout<<"point "<<points.size()<<endl;
            if (points.size()==4)
                flag=true;
        }
        InvalidateRect(hwnd, NULL, false);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
        break;
    default:                      /* for messages that we don't deal with */
        return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}
