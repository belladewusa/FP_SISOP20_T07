#include "user.h" 

#include "stat.h" 

#include "types.h" 



int main (int argc, char *argv[])

{
	
  if (argc != 3)
  
  {
  	
    printf(2, "Usage: mv oldname newname\n"); 
    
    exit(); 
    
  }

 if ((link(argv[1], argv[2]) < 0) || (unlink(argv[1]) < 0)) 
 // untuk mengahapus file yg sudah di moved 
 
    printf(2, "mv %s to %s failed\n", argv[1], argv[2]); 


  exit(); 

}
