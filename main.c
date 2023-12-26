#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cub3d.h"

int main(int argc, char **argv)
{
    if (argc < 1)
        exit(printf("Wrong argument count\n"));
    else{
        char **map = read_map("31.cub");
        if (map == NULL)
            return 0;
        int i = 0;
        while (map[i] != NULL){
            printf("%s\n", map[i]);
            i++;
        }


    }
}