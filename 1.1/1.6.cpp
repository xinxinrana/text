//点击和输入
#include <iostream>
#include <windows.h>
#define MAX_SCREEN_POINT 65536      //windows api定义屏幕最大位置

using namespace std;


void SendCtrlV()
{
    // Create a generic keyboard event structure
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    

    // Press the "V" key
    ip.ki.wVk = 'V';
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
 
    // Release the "V" key
    ip.ki.wVk = 'V';
    ip.ki.dwFlags = KEYEVENTF_KEYUP;

}




int main(int argc, char const *argv[])
{   

    // 百分比位置，
    double pointX= 70,pointY = 70;

    pointX = (pointX/100)*MAX_SCREEN_POINT;
    pointY = (pointY/100)*MAX_SCREEN_POINT;
    //屏幕点数最大值，与屏幕缩放有关系
    int pointXMAX = GetSystemMetrics(SM_CXSCREEN);  // 2k = 1440/1.25（缩放值） =1152，此时最大值就是 1152
    int pointYMAX = GetSystemMetrics(SM_CYSCREEN);

    mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, pointX, pointY, 0, 0);

    for (size_t i = 0; i < 10; i++)
    {
        mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
        SendCtrlV();

    }
    // for (size_t i = 0; i < 1000; i++)
    // {
    // SendCtrlV();
    // }
    
    system("pause");

    return 0;
}




//vvvvvvvvvvvvvvvvvvvv






























