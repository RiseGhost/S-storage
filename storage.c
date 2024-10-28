#include"process.h"
#include"Date.h"
#include<unistd.h>
#define Buffer_Reader 100
#define Buffer_Writer 100
#define Fifo_Path "/tmp/sophie_storage_write"
#define Fifo_Path_Reader "/tmp/sophie_storage_reader"

struct Storage{
    char FileName[20];
    Date crate;
    Date update[];
};

int main(void){
    Recove* r = create_Recove();
    for (int i = 0; i < 3; i++){
        sleep(1);
        add_new_point_date(r);
    }
    print_recove(r);
    r = Recove_pop(r);
    print_recove(r);
    //print_date(getCurrentDate());
    /*char pipe_paths[][100] = {Fifo_Path,Fifo_Path_Reader};
    create_pipes(pipe_paths,2);
    const char* s = read_process(Fifo_Path, Buffer_Reader);
    printf("%s\n",s);
    write_process(Fifo_Path_Reader,Buffer_Writer,"Puta <^-^>");*/
    return 0;
}