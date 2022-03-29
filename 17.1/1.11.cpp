//对象操作文件
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

class Cfile
{
private:
    FILE *m_fp;      //文件指针
    bool m_bEnBuffer; //是否启用缓冲区,true-启用,false-关闭.

        public : Cfile(); //构造函数
    Cfile(bool enbuffer); //构造函数

    ~Cfile(); //析构函数

    //启 关 缓冲区
    void EnBuffer(bool enbuffer = true);

    //打开文件
    bool Open(const char *fileName, const char *openmode);

    //调用Fprintf往文件里面写内容
    void Fprintf(const char *fmt, ...);

    //调用Fgets 读取文件中的一行
    bool Fgets(char *strBuffer, const int readSize);

    //关闭文件指针
    void close(void);
};

int main(int argc,char *argv[])
{
  char f_name[] = {"1.9.cpp"};
 
  Cfile File;
 
  if (File.Open(f_name,"r")==false) { printf("File.Open(%s)失败。\n",f_name); return -1; }
 
  char strLine[301];
 
  while (true)
  { // 从文件中读取每一行
    if (File.Fgets(strLine,300)==false) break;
 
    printf("%s",strLine);   // 把从文件中读到的内容显示到屏幕
  }
}




Cfile::Cfile()
{
    m_fp = 0;
    m_bEnBuffer = true;
}

Cfile::Cfile(bool enbuffer)
{
    m_fp = 0;
    m_bEnBuffer = enbuffer;
}

Cfile::~Cfile()
{
    close();
}

void Cfile::EnBuffer(bool enbuffer)
{
    m_bEnBuffer = enbuffer;
}

bool Cfile::Open(const char *fileName, const char *openMode)
{
    close();

    if (m_fp = fopen(fileName, openMode))
        return true;
    else
        return false;
}

void Cfile::Fprintf(const char *fmt, ...)
{
    if (m_fp = 0)
        return;

    va_list ap;
    va_start(ap, fmt);
    vfprintf(m_fp, fmt, ap);

    va_end(ap);

    if (m_bEnBuffer)
        fflush(m_fp);
}

bool Cfile::Fgets(char *strBuffer, const int readSize)
{
    if (m_fp == 0)
        return false;

    memset(strBuffer, 0, readSize);

    if (fgets(strBuffer, readSize, m_fp) == 0)
        return false;
    return true;
}

void Cfile::close(void)
{
    if (m_fp != 0)
        fclose(m_fp);

    m_fp = 0;
}
