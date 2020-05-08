// memindahkan file ke folder
// mv.c
//T07
#include "fcntl.h"

#include "user.h"

#include "types.h"

#include "fs.h"	 

#include "stat.h"


char buffer[512]; 

char* fmtname(char *path); 

char* strcat(char *s1,char *s2); 


void mv_all(char *awal, char *akhir); 	

void mv(char *awal,char *akhir); 


int main(int argc, char *argv[])

{

  char *awal,*akhir; 

  if(argc<=2)

  {

    printf(1," penggunaan: mv awal akhir\n"); 

    exit(); 

  }

  if(argc==3)

  {

    if(argv[1][0]=='*')

    {

      akhir=argv[2]; 

      mv_all(".",akhir); 

      exit();  

    }

    else

    {

        awal=argv[1]; 

      akhir=argv[2]; 

      mv(awal,akhir); 

    }

    exit(); 	

  }

  if(argc==4)

  {

    if(argv[1][0]=='*')

    {


      awal=argv[2]; 

      akhir=argv[3]; 

      mv_all(awal,akhir); 	

    }

    exit(); 

  }

  exit(); 

}



char* fmtname(char *path)

{

  static char buf[DIRSIZ+1]; 

  char *p; 


// Temukan karakter pertama setelah slash terakhir.

  for(p=path+strlen(path); p >= path && *p != '/'; p--)

    ; 

  p++; 	



  // kembalikan blank-padded name.

  if(strlen(p) >= DIRSIZ)

    return p; 

  memmove(buf, p, strlen(p)); 

  memset(buf+strlen(p), ' ', DIRSIZ-strlen(p)); 

  return buf; 

}



char* strcat(char *s1,char *s2)

{

  char *b=s1; 

  while(*s1)++s1; 

  while(*s2)*s1++=*s2++; 

  *s1=0; 

  return b; 

}



void mv_all(char *awal, char *akhir)

{

  char buf[512], *p; 

  int fd; 

  struct dirent dr; 

  struct stat st; 

  

  stat(awal,&st); 	
	
  fd=open(awal,O_RDONLY); 

  

  if(st.type==T_FILE)

  {

    printf(1,"%s is a file\n", awal);	

    return; 

  }



  else if(st.type==T_DIR)

  {

    strcpy(buf, awal); 

    p = buf+strlen(buf); 

    *p++ = '/'; 

    

    while(read(fd, &dr, sizeof(dr)) == sizeof(dr))

    {

      if(dr.inum == 0)

        continue; 
      

      memmove(p, dr.name, DIRSIZ); 

      p[DIRSIZ] = 0; 

      

      if(stat(buf,&st)<0)

	  {

        printf(1,"mv *: file cannot be stats\n"); 

        continue; 

      }



      if(st.type==1)

      {

        if(fmtname(buf)[0]=='.')

        {

          continue; 	

        }

        

        char awals[512],dawal[512]; 

  

        //select awal

        strcpy(awals,awal); 

        strcat(awals,"/"); 

        strcat(awals,p); 

        

        //select akhir

        strcpy(dawal,akhir); 

        strcat(dawal,"/"); 

        strcat(dawal,p); 

      

      mkdir(dawal);

        mv_all(awals,dawal); 

  

        unlink(awals); 

      }

      else

      {        

        char awals[512],dawal[512]; 

      

      //select awal

        strcpy(awals,awal); 

        strcat(awals,"/"); 

        strcat(awals,p); 

        

        //select akhir

        strcpy(dawal,akhir); 

        strcat(dawal,"/"); 

        strcat(dawal,p); 

      

      //melakukan pemindahan 

      mv(awals,dawal); 

        unlink(awals); 

      } 

    }

  }

  close(fd); 

}



void mv(char *awal,char *akhir)

{

  int fdawal, fdakhir, n,flag=1; 

  char sec[512]; 

  

  fdawal=open(awal,O_RDWR); 

  fdakhir=open(akhir,O_RDWR); 

  

  if(fdakhir>=0)

  {

    flag=0; 

  }



  close(fdakhir); 

  fdakhir=open(akhir,O_RDWR | O_CREATE); 	



  if(fdawal<0 && fdakhir>=0){

    printf(1,"%s does not exist or is a directory\n",awal); 	

    if(flag)

    {

      unlink(akhir); 

    }



    close(fdawal); 

    close(fdakhir); 

    return; 

  }

  else if(fdawal<0 && fdakhir<0)

  {

    close(fdawal); 

    close(fdakhir); 

    return; 

  }

  else if(fdakhir<0 && fdawal>=0)

  {

    close(fdakhir); 

    fdakhir=open(sec,O_CREATE | O_RDWR); 	
  }

  

  while((n=read(fdawal,buffer,sizeof(buffer)))>0) 

    write(fdakhir,buffer,fdawal); 	

  

  unlink(awal); 

  

  close(fdawal); 	

  close(fdakhir); 

}

//FP20
