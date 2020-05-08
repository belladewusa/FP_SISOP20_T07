// digunakan untuk memindahkan file lama ke file baru 
// mv.c
//T07

#include "user.h" 

#include "stat.h" 

#include "types.h" 



int main (int argc, char *argv[])

{
	
  if (argc != 3)
  
  {
  	
    printf(2, "penggunaan: mv file_lama file_baru\n"); 
    
    exit(); 
    
  }

 if ((link(argv[1], argv[2]) < 0) || (unlink(argv[1]) < 0)) 
 // mengahapus file yang telah di pindahkan 
 
    printf(2, "mv %s to %s failed\n", argv[1], argv[2]); 


  exit(); 

}
