//stat函数使用
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#define SIZE_S 128
#define NO 0

#include<sys/stat.h>

//mkdir 创建目录
//rmdir 删除目录


#if NO
struct stat
{
    dev_t     st_dev;     /* ID of device containing file */文件使用的设备号
    ino_t     st_ino;     /* inode number */    索引节点号 
    mode_t    st_mode;    /* protection */  文件对应的模式，文件，目录等
    nlink_t   st_nlink;   /* number of hard links */    文件的硬连接数  
    uid_t     st_uid;     /* user ID of owner */    所有者用户识别号
    gid_t     st_gid;     /* group ID of owner */   组识别号  
    dev_t     st_rdev;    /* device ID (if special file) */ 设备文件的设备号
    off_t     st_size;    /* total size, in bytes */ 以字节为单位的文件容量   
    blksize_t st_blksize; /* blocksize for file system I/O */ 包含该文件的磁盘块的大小   
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */ 该文件所占的磁盘块  
    time_t    st_atime;   /* time of last access */ 最后一次访问该文件的时间   
    time_t    st_mtime;   /* time of last modification */ /最后一次修改该文件的时间   
    time_t    st_ctime;   /* time of last status change */ 最后一次改变该文件状态的时间   
};
#endif



int main(int argc, char const *argv[])
{
    struct stat dir_p;
    char dir_name[SIZE_S];
    memset(dir_name,0,sizeof(dir_name));
    memset(&dir_p,0,sizeof(dir_p));

    getcwd(dir_name,SIZE_S);        //获取当前路径
    strcat(dir_name,"/");
    strcat(dir_name,"测试路径001");


    if(stat(dir_name,&dir_p)!=0)
        {
            fprintf(stderr,"错误代码：%d 可能是：%s\n",errno,strerror(errno));
            // perror("errno");
            exit(0);
        }

    printf("%o\n",dir_p.st_mode);
    
    if (S_ISDIR(dir_p.st_mode))
    {
        printf("%s 是一个目录\n",dir_name);
    }
        
    if (S_ISREG(dir_p.st_mode))
    {
        printf("%s 是一个文件\n",dir_name);
    }
        
    {
        /* code */
    }
    
    
    
    
    
    // getchar();
    
    return 0;
}
