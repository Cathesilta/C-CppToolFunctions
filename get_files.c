#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getFiles(string cate_dir)
{
    vector<string> files;//存放文件名
    
    DIR *dir;
    struct dirent *ptr;
    char base[1000];
    
    if ((dir=opendir(cate_dir.c_str())) == NULL)
    {   
        perror("Open dir error...");
        exit(1);
    }   

    while ((ptr=readdir(dir)) != NULL)
    {   
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
            continue;
        else if(ptr->d_type == 8)    ///file
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
            files.push_back(ptr->d_name);
        else if(ptr->d_type == 10)    ///link file
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
            continue;
        else if(ptr->d_type == 4)    ///dir
        {   
            files.push_back(ptr->d_name);
            /*  
                memset(base,'\0',sizeof(base));
                strcpy(base,basePath);
                strcat(base,"/");
                strcat(base,ptr->d_nSame);
                readFileList(base);
            */
        }   
    }   
    closedir(dir);
    
    return files;
}

int main(void)
{
    DIR *dir;
    string basePath = "/home/shen/user_666888/";

    ///get the current absoulte path

    cout<<"the current dir is : "<<basePath<<endl;


    cout<<endl<<endl;
    vector<string> files=getFiles(basePath);
    for (int i=0; i<files.size(); i++)
    {
        cout<<files[i]<<endl;
    }


    cout<<"end..."<<endl<<endl;
    return 0;
}
