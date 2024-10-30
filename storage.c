#include"process.h"
#include"Date.h"
#include<unistd.h>
#define Can_Edit            0b10000000
#define Can_send            0b01000000
#define Request_Password    0b00100000
#define Acess_out           0b00010000
#define Buffer_Reader 100
#define Buffer_Writer 100
#define Fifo_Path "/tmp/sophie_storage_write"
#define Fifo_Path_Reader "/tmp/sophie_storage_reader"

struct Storage{
    char* FileName;
    Date create;
    Recove* recove;
    unsigned char* content;
    char priv;
};
typedef struct Storage Storage;

Storage create_Storage(const char* filename, unsigned char* bytes){
    Storage s;
    strcpy(s.FileName,filename);
    s.create = getCurrentDate();
    s.recove = create_Recove();
    strcpy(s.content,bytes);
    s.priv = Can_Edit | Can_send | Acess_out;
    return s;
}

int main(void){
    FILE* f = fopen("img.png", "rb");
    struct stat status;
    stat("img.png", &status);
    unsigned char* bytes = (unsigned char*) malloc(sizeof(char) * 128);
    fread(bytes,sizeof(char),128,f);
    fclose(f);
    printf("%02x \t %x \t %x \t %x \t %02x\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4]);
    printf("File size -> %li\n",status.st_size);
    /*
    Recove* r = create_Recove();
    for (int i = 0; i < 3; i++){
        sleep(1);
        add_new_point_date(r);
    }
    print_recove(r);
    r = Recove_pop(r);
    print_recove(r);*/
    //print_date(getCurrentDate());
    /*char pipe_paths[][100] = {Fifo_Path,Fifo_Path_Reader};
    create_pipes(pipe_paths,2);
    const char* s = read_process(Fifo_Path, Buffer_Reader);
    printf("%s\n",s);
    write_process(Fifo_Path_Reader,Buffer_Writer,"Puta <^-^>");*/
    return 0;
}