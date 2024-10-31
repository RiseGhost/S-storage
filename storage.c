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

unsigned char User_Acess_erro = 0b00001111;

struct Storage{
    char* FileName;
    Date create;
    Recove* recove;
    unsigned char* content;
    unsigned char priv;
    unsigned short int UserID;
};
typedef struct Storage Storage;

void update_content_Storage(Storage* storage, unsigned char* bytes){
    storage->content = (unsigned char*) malloc(strlen(bytes));
    storage->content = bytes;
}

Storage create_Storage(const char* filename, unsigned char* bytes, unsigned short int UserID){
    Storage s;
    s.FileName = (char*) malloc(sizeof(char) * strlen(filename));
    strcpy(s.FileName,filename);
    s.create = getCurrentDate();
    s.recove = create_Recove();
    update_content_Storage(&s,bytes);
    s.priv = Can_Edit | Can_send | Acess_out;
    s.UserID = UserID;
    return s;
}

unsigned char* getcontent_Storage(Storage s, unsigned short int UserID){
    return (s.UserID == UserID) ? s.content : &User_Acess_erro;
}

int main(void){
    FILE* f = fopen("img.png", "rb");
    struct stat status;
    stat("img.png", &status);
    unsigned char* bytes = (unsigned char*) malloc(sizeof(char) * status.st_size);
    fread(bytes,sizeof(char),status.st_size,f);
    fclose(f);
    printf("Ficheiro lido com sucesso\n");
    Storage storage = create_Storage("img.png",bytes,1);
    printf("Stora criado com sucesso");
    unsigned char* img = getcontent_Storage(storage,1);
    
    FILE* ff = fopen("img_copy.png","wb");
    fwrite(img,sizeof(char),status.st_size,ff);
    fclose(ff);
    //printf("%02x \t %x \t %x \t %x \t %02x\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4]);
    //printf("File size -> %li\n",status.st_size);
    printf("\n\nshort int -> %li short -> %li int -> %li\n", sizeof(unsigned short int), sizeof(short), sizeof(char));
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