//class的文件操作
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
 
// 文件操作类声明
class CFile
{
private:
  FILE *m_fp;        // 文件指针
  bool  m_bEnBuffer; // 是否启用缓冲区，true-启用；false-不启用
 
public:
  CFile();   // 类的构造函数
  CFile(bool bEnBuffer);   // 类的构造函数
 
 ~CFile();   // 类的析构函数
 
  void EnBuffer(bool bEnBuffer=true);  // 启、禁用缓冲区
 
  // 打开文件，参数与fopen相同，打开成功true，失败返回false         
  bool Open(const char *filename,const char *openmode);
 
  // 调用fprintf向文件写入数据
  void Fprintf(const char *fmt,... );
 
  // 调用fgets从文件中读取一行
  bool Fgets(char *strBuffer,const int ReadSize);
 
  // 关闭文件指针
  void Close();
};
 
int main(int argc,char *argv[])
{
  char f_name[] = {"1.9.cpp"};
 
  CFile File;
 
  if (File.Open(f_name,"r")==false) { printf("File.Open(%s)失败。\n",f_name); return -1; }
 
  char strLine[301];
 
  while (true)
  { // 从文件中读取每一行
    if (File.Fgets(strLine,300)==false) break;
 
    printf("%s",strLine);   // 把从文件中读到的内容显示到屏幕
  }
}
 
CFile::CFile()   // 类的构造函数
{
  m_fp=0;
  m_bEnBuffer=true;
}
 
CFile::CFile(bool bEnBuffer)   // 类的构造函数
{
  m_fp=0;
  m_bEnBuffer=bEnBuffer;
}
 
// 关闭文件指针
void CFile::Close()
{
  if (m_fp!=0) fclose(m_fp);  // 关闭文件指针
  m_fp=0;
}
 
CFile::~CFile()   // 类的析构函数
{
  Close();  // 调用Close释放资源
}
 
// 启、禁用缓冲区
void CFile::EnBuffer(bool bEnBuffer)
{
  m_bEnBuffer=bEnBuffer;
}
 
// 打开文件，参数与fopen相同，打开成功true，失败返回false         
bool CFile::Open(const char *filename,const char *openmode)
{
  Close();  // 打开新的文件之前，如果已经打开了文件，关闭它。
 
  if ( (m_fp=fopen(filename,openmode)) == 0 ) return false;
 
  return true;
}
 
// 调用fprintf向文件写入数据
void CFile::Fprintf(const char *fmt,...)
{
  if ( m_fp == 0 ) return;
 
  va_list arg;              //fmt的格式化很像(就是)printf的
  va_start(arg,fmt);        //arg 列表把可变参按顺序装在里面
  vfprintf(m_fp,fmt, arg);  //https://www.runoob.com/cprogramming/c-function-vfprintf.html
  //vfrintf frintf的可变参函数版,第三个参数用列表把原本分开的装起来了.
  //成功返回写入字符数,失败则负数
  va_end(arg);
 
  //若关闭缓冲区 在写入一次就将缓冲区的内容全部push  
  if ( m_bEnBuffer == false ) fflush(m_fp);

  // fflush:刷新流 stream 的输出缓冲区。
}
 
// 调用fgets从文件中读取一行
bool CFile::Fgets(char *strBuffer,const int ReadSize)
{
  if ( m_fp == 0 ) return false;
 
  memset(strBuffer,0,ReadSize);
 
  if (fgets(strBuffer,ReadSize,m_fp) == 0) return false;
 
  return true;
}