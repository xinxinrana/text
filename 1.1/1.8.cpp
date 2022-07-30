#include <iostream>
#include <Windows.h>
//模拟键盘发送单个的V按键

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
    SendInput(1, &ip, sizeof(INPUT));
}
int main(int argc, char const *argv[])
{
    for (int i = 1; i < 10; i++){

    SendCtrlV();
    }
    system("pause");
    return 0;
}
