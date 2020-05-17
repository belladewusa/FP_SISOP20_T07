# FP_SISOP20_T07

NABELLA DESYAWULANSARI 05311840000039
ACHSAN NOORSALAM 05311840000021


## command 1 : clear

tugas : perserta diminta membuat command pada vx-6 yang memiliki fungsi untuk membersihkan terminal


printf(1,"\033[2J\033[1;1H\n");

\033[2J  //membersihkan semua dari atas sampai bawah

\033[1;1H //menaruh kursor di kolom 1 baris 1

## command 2 : Head

tugas :perserta diminta membuat command pada vx-6 yang memiliki fungsi untuk menulis beberapa kalimat pertama(10 default) pada sebuah file


    main(int argc, char *argv[]) {
      int i;
      int fd = 0;	
      int x = 10;	
      char *file;	
      char a;
      
 menggunakan char *file untuk memasukkan file 
 
      if (argc <= 1) {	
            head(0, "", 10);	
            exit();
 
memberikan default 10 baris 


    if (a == '-') { 
			argv[i]++;
        x = atoi(argv[i]++);
        
        
 untuk menulis berapa yang baris yang diinginkan
 
    while((y = read(fd, buf, sizeof(buf))) > 0 )
       {
     for(x=0;x<=y ;x++)
      {				
      if(buf[x]!='\n'){			
       	printf(1,"%c",buf[x]);
    
untuk membaca dan menampilkan data perkarakter




## command 3 : tail 

tugas :perserta diminta membuat command pada vx-6 yang memiliki fungsi untuk menulis beberapa kalimat terahkir(10 default) pada sebuah file

## command 4 : MV

tugas :perserta diminta membuat command pada vx-6 yang memiliki fungsi untuk memindahkan sebuah file ke direktori baru

PENJELASAN CODINGAN 


 Perbedaan antara kedua sintaksis ini halus tetapi penting. 
Jika file header disertakan dalam <>, preprocessor akan mencari jalur direktori yang telah ditentukan untuk menemukan file header. 
Jika file header dilampirkan dalam "", preprocessor akan mencari file header di direktori yang sama dengan file sumber.

	#include "types.h"
	
Berbagai TIPE DATA digunakan di tempat lain

	#include "stat.h"

 <sys / stat.h> menentukan struktur data yang dikembalikan oleh fungsi fstat () , lstat () , dan stat ()
Fungsi stat() dan lstat() mengambil argumen nama file . Jika file tersebut merupakan tautan simbolis , stat() mengembalikan atribut dari target tautan,

	#include "user.h"

untuk GDB ,GDB adalah debugger gratis yang ditawarkan dari Proyek GNU
	
	#include "fcntl.h"

kontrol file

	#include "fs.h"

pembungkus sistem file

Void.Fungsi ini tidak mengembalikan nilai keluaran ( return output ) yang didapat dari hasil proses tersebut

fungsi untuk memindahkan src ke dest

		void move(char *src, char *dest)
		    {
		      if (link(src, dest)!=0) //copy
			{
			printf(1,"Unable to move, file cant link or not found\n");
			exit();
			}

		      if (unlink(src)!=0) //hapus
			{
			printf(1,"Unable to delete the old one\n");
			exit();
			}
		    }

membuka folder dan memindahkan file

	void aster(char *dest)
	    {
		//deklarasi
		int fd= open(".",O_RDONLY),cek;  //buka dir, cek
		int lndest= strlen(dest); // cek jumlah karakter(string) di dir
		struct stat st; // mengambil argumen nama file , mengembalikan atribut dari tautan target = st
		struct dirent de; //direktori yg dimasuki = de
		char buf[512]; // alokasi buffer 512 byte = 64 bit

  mmenambahkan/memindahkan  file ke folder  
  
         while(read(fd, &de, sizeof(de)) == sizeof(de)) 
            {
            cek= stat(de.name, &st);  
            if(cek == 0 && st.type == T_FILE) 
                {
                strcpy(buf, dest);
                strcpy(&buf[lndest],"/"); 
                strcpy(&buf[lndest+1], de.name);
                move(de.name,buf);
                }
            }
    }

	int main(int argc, char *argv[])
	    {
		//deklarasi variable
		int cek,i,lndest,fd;
		char buf[512];
		struct stat st;

jika tidak ada argumen     / proses argumen   

        if((fd = open(argv[argc-1],O_RDONLY))<0) //buka folder, read only
        {       
        cek=stat(argv[argc-1],&st); 
        lndest=strlen(argv[argc-1]);
        }
        
jika mengetik mv saja akan keluar info cara penggunaan 
      
      if (argc<2)
            {
            printf(1,"Usage: mv file dest\n");
            }
    
berhasil dipindahkan
     
     if(strcmp(argv[1],"*")==0) //perbandingan, untuk cek file ada
                {
                aster(argv[2]); //akan menjalankan fungsi aster
                exit();
                }

cek jika dest bukan direktori     
       
       if(cek==0 && st.type != T_DIR) 
            {
            printf(1,"Dest %s is not a directory.\n",argv[argc-1]);
            exit();
            }
    
link argumen ke sebuah direktori
       
       for(i=1; i<argc-1; i++)
        
menambahkan dari nama file ke nama direktori         {
          
	  strcpy(buf,argv[argc-1]);
            strcpy(&buf[lndest],"/");
            strcpy(&buf[lndest+1],argv[i]);
            move(argv[i],buf);       
        }
            
        exit(); 
    }



