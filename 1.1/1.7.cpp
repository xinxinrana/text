//获取鼠标位置
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char const *argv[])
{
    while (true){
        double maxX = GetSystemMetrics(SM_CXSCREEN);
        double maxY = GetSystemMetrics(SM_CYSCREEN);


        POINT *point = new POINT;
        GetCursorPos(point);

        cout << "鼠标位置："<<endl;
        cout << "X:"<<point->x<<endl;
        cout << "Y:"<<point->y<<endl;

        cout << "X(%):"<<(point->x)/maxX*100<<endl;
        cout << "Y(%):"<<(point->y)/maxY*100<<endl;
        
        int pointX = point->x;
        while (true)
        {
            GetCursorPos(point);
            // Sleep(10);
            // cout<<"1:"<<pointX<<endl;
            // cout<<"2:"<<point->x<<endl;
            Sleep(10);
            if(pointX != point->x)
            {
                
                break;
            }
        }
        Sleep(10);
        system("cls");
    }
    return 0;
}
