#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse_rec/parse_rec.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "No input file found!\n");
    }
    FILE *fp;
    if( (fp = fopen(argv[1], "r")) == NULL ){
        fprintf(stderr, "Error. File could not be opened.\n");
        return 0;
    }

    struct rec *list;
    int length;
    int i;
    list = rec_list_alloc(fp, &length);
    printf("reclist_alloc length %d\n", length);
    for(i = 0; i < length; i++){
        printf("h = %d, w = %d\n", list[i].height, list[i].width);
    }
    free(list);

    fclose(fp);
    return 0;
}
