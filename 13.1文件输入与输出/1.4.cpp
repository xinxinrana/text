//二进制模式 文本模式
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char HEX2[10]; 
    char HEX1[10];
    for (int i = 0; i < 10; i++)
    {
        HEX1[i]=(char)((1+i)*0x02);
        printf("HEX1: %#04x\n",HEX1[i]);
    }

    FILE *fp;
    fp = fopen("file_2.txt","w+");

    fwrite(HEX1,sizeof(char),10,fp);
    fseek(fp,0l,SEEK_SET);
    fread(HEX2,sizeof(char),10,fp);

    for (int i = 0; i < 10; i++)
    {
        printf("HEX2: %#04x\n",HEX2[i]);
    }
    

    
    return 0;
}
