#include "types.h"
#include "stat.h"
#include "user.h"

char buf[1024];

void
head(int fd, char *name, int line)
{
    int x, y; 
    int z, i; 

    z = i = 0;

  while((y = read(fd, buf, sizeof(buf))) > 0 )
  {
    for(x=0;x<=y ;x++)
    {				
      if(buf[x]!='\n'){			
      	printf(1,"%c",buf[x]);
      }		
      else if (z == (line-1)){
	printf(1,"\n");	
	exit();
      }

      	printf(1,"\n");
      	z++;
      } 
    }
  }

  if(y < 0){
    printf(1, "head: error\n");
    exit();
  }
}



int 
main(int argc, char *argv[]) {
      int i;
      int fd = 0;	
      int x = 10;	
      char *file;	
      char a;

      file = ""; 

      if (argc <= 1) {	
            head(0, "", 10);	
            exit();
      }

      else {
            for (i = 1; i < argc; i++) {
		a = *argv[i];	
				
                  if (a == '-') { 
			argv[i]++;
                        x = atoi(argv[i]++);
                  }
				
                  else {	
			if ((fd = open(argv[i], 0)) < 0) {
                        printf(1, "head: tidak terbuka %s\n", argv[i]);
                        exit();
                        }
                  }
            }
		 
            head(fd, file, x);
            close(fd);
            exit();    

      }
}
