#include "../libft/libft.h"

int file_extension_check(char *map_name)
{
    int     extension_index;
    char    *sample;

    extension_index = ft_strlen(map_name) - 4;
    sample = ".cub";
    if (ft_strncmp(&map_name[extension_index], sample, ft_strlen(&map_name[extension_index])) || (ft_strlen(map_name) < 5)){
        return (0);
    }
    return (1);
}
