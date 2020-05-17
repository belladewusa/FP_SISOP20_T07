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
