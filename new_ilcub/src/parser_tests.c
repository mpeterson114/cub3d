#include "cub3d.h"

static int  check_valid_chars(t_program *cub, char map_val) 
{
    if (map_val != '1' && map_val != '0' && map_val != 'N' && map_val != 'S'
        && map_val != 'E' && map_val != 'W' && map_val != ' ')
        error_exit(cub, 15);
    if (map_val == 'N' || map_val == 'S' || map_val == 'E' || map_val == 'W')
        return (1);
    return (0);
}

static void  check_map_content(t_program *cub, char **map)
{
    int x;
    int y;
    int found_player;

    y = 0;
    found_player = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            while (map[y][x] == ' ' || map[y][x] == '\t'
			|| map[y][x] == '\r' || map[y][x] == '\v' 
            || map[y][x] == '\f')
                x++;
            found_player += check_valid_chars(cub, map[y][x]);
            x++;
        }
        y++;    
    }
    if (found_player > 1 || !found_player)
        error_exit(cub, 8);
}


static void check_empty_line(char *line, t_program *cub)
{
    static unsigned int line_count;
    static int in_flag;
    static int out_flag;

    if (line_count == 6 && ft_strlen(line) > 1 && !in_flag)
        in_flag = 1;
    if (line_count < 6 && ft_strlen(line) > 1)
        line_count++;
    if (ft_strlen(line) == 1 && in_flag && !out_flag)
        out_flag = 1;
    if ((ft_strlen(line) > 1 || *line != '\n') && out_flag)
        error_exit(cub, 14);  
}

static char *get_lines(int fd, t_program *cub)
{
    char *file;
    char *line;

    line = get_next_line(fd);
    file = ft_calloc(1, 1);
    if (!file)
        error_exit(cub, 4);
    while (line != NULL)
    {
        check_empty_line(line, cub);
        file = ft_strjoin_free(file, line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    return (file);
}

char **read_file(char **argv, t_program *cub)
{
    char *file;
    int fd;
    char **contents;
    char *buffer[1];

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        error_exit(cub, 13);
    if (read(fd, buffer, 1) == 0)
    {
        close(fd);
        error_exit(cub, 11);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        error_exit(cub, 13);
    file = get_lines(fd, cub);
    close(fd);
    contents = ft_split(file, '\n');
    free(file);
    return (contents);
}

static enum e_identifiers get_line_values(char *line)
{
    while (*line && (*line == ' ' || *line == '\t'))
        line++;
    if (ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "NO\t", 3))  // && cub->path_nwse[i] == NULL....
        return(NO);
    if (ft_strnstr(line, "SO ", 3) || ft_strnstr(line, "SO\t", 3))
        return (SO);
    if (ft_strnstr(line, "WE ", 3) || ft_strnstr(line, "WE\t", 3))
        return (WE);
    if (ft_strnstr(line, "EA ", 3) || ft_strnstr(line, "EA\t", 3))
        return (EA);
    if (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "F\t", 2))
        return (F);
    if (ft_strnstr(line, "C ", 2) || ft_strnstr(line, "C\t", 2))
        return (C);
    return (ERROR);
}

static char *get_texture_path(char *line, t_program *cub)
{
    char *texture_path;
    while (*line && (*line == ' ' || *line == '\t'))  // add more whitespace criteria...
        line++;
    line += 2;   //?????
    texture_path = ft_strtrim(line, " \t");  // make this apply to more whitespaces
    if (!ft_strlen(texture_path))
    {
        free(texture_path);
        error_exit(cub, 6); //"No path found for given texture\n"
    }
    return (texture_path);
}

// static t_rgb  get_color_path(char *line, t_program *cub)
// {
//     t_rgb color;
//     char *temp;
//     char **color_code;

//     while (*line && (*line == ' ' || *line == '\t'))
//     {
// 		line++;
// 	}
// 	line++;
//     temp = ft_strtrim(line, " \t");
// 	if (!ft_strlen(temp))
// 		error_exit(cub, 6);  // no C or F path 
// 	color_code = ft_split(temp, ',');
// 	if (ft_get_matrix_size(color_code) != 3)
//     {
//         ft_free_matrix(color_code);
//         error_exit(cub, 5);  // Color must be in R,G,B format\n
//     }
// 	if (!ft_isnum_str(color_code[0]) || !ft_isnum_str(color_code[1]) || !ft_isnum_str(color_code[2]))
//     {
//         ft_free_matrix(color_code);
//         error_exit(cub, 5);  //Color values must be numeric and between 0 and 255\n
//     }
// 	color.r = ft_atoi(color_code[0]);  //is malloc necessary here for new t_rgb color variable?
//     color.g = ft_atoi(color_code[1]);
//     color.b = ft_atoi(color_code[2]);
//     if (color.r > 255 || color.g > 255 || color.b > 255 
//         || color.r < 0 || color.g < 0 || color.b < 0)
//         error_exit(cub, 5);  // Color values must be numeric and between 0 and 255\n
//     free(temp);
//     ft_free_matrix(color_code);
//     return (color);
// }

// static int convert_rgb(t_rgb color)
// {
//     if (i == 0)
// 		cub->color_ceiling = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
// 	else
// 		cub->color_floor = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
// }

// color bit shifting function to convert to int??

void	init_color_floor_and_ceiling(t_program *cub, char *line, enum e_identifiers type_id)
{
	char	*tmp;
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		error_exit(cub, 4);
	if (line[1] != ' ')
		error_exit(cub, 5);
	tmp = line;
	rgb->r = my_atoi(cub, tmp);
	tmp = ft_strchr(tmp, ',');
	rgb->g = my_atoi(cub, tmp);
	++tmp;
	tmp = ft_strchr(tmp, ',');
	rgb->b = my_atoi(cub, tmp);
	if (type_id == C)
		cub->color_ceiling = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	else
		cub->color_floor = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	free(rgb);
}

static void    map_values(t_program *cub, char **contents)
{
    int i;
    enum e_identifiers type_id;

    i = 0;
    while (i < 6)
    {
        // printf("%s\n", contents[i]);
        type_id = get_line_values(contents[i]);
        if (type_id == ERROR)
            error_exit(cub, 6);  //"Invalid texture type\n"
        if (type_id == NO && cub->path_nswe[3] == NULL)
            cub->path_nswe[3] = get_texture_path(contents[i], cub); 
        else if (type_id == SO && cub->path_nswe[1] == NULL)
            cub->path_nswe[1] = get_texture_path(contents[i], cub);
        else if (type_id == WE && cub->path_nswe[0] == NULL)
            cub->path_nswe[0] = get_texture_path(contents[i], cub);
        else if (type_id == EA && cub->path_nswe[2] == NULL)
            cub->path_nswe[2] = get_texture_path(contents[i], cub);
        else if (type_id == F && cub->color_floor == -1)
        {
            init_color_floor_and_ceiling(cub, contents[i], type_id);
            //cub->color_floor = get_color_path(contents[i], cub);
            //cub->color_floor = convert_rgb()
        }
        else if (type_id == C)
            init_color_floor_and_ceiling(cub, contents[i], type_id);
        i++;
    }
}

static void copy_walls_check(char **copy_map, t_program *cub)
{
    int i;
    int j;

    i = -1;
    while (++i < (ft_get_matrix_size(copy_map)))
    {
        j = -1;
        while (++j < (int)ft_strlen(copy_map[i]))
        {
            if (copy_map[i][j] == '0' || copy_map[i][j] == 'N' || copy_map[i][j] == 'S' 
                || copy_map[i][j] == 'W' || copy_map[i][j] == 'E')
                {
                    if (copy_map[i][j + 1] == ' ' || copy_map[i][j - 1] == ' ' 
                    || copy_map[i + 1][j] == ' ' || copy_map[i - 1][j] == ' ')
                    {
                        ft_free_matrix(copy_map);
                        error_exit(cub, 10);    //"Map's walls are not closed\n"
                    }   
                }
        }
    }
}

/* Fills copy_map with the contents of the original map, centering it within the padding added to copy_map.
Padding around borders on copy_map remains filled with ' ' character */
static void paste_original(char **map, char ***copy_map, t_program *cub)
{
    int i;
    int j;

    i = 0;
    while (++i < cub->only_map_h + 1)
    {
        j = 0;
        while (++j < (int)ft_strlen(map[i - 1]) + 1)
            (*copy_map)[i][j] = map[i - 1][j - 1];
    }
}

/* Creates a copy of the original map with 1 row/column of padding added around all borders, then 
fills the map with the ' ' character */
static char **get_map_copy(t_program *cub, char **map)
{
    int i;
    int j;
    int width;
    char **copy_map;

    width = ft_longest_line(map);
    copy_map = ft_calloc((cub->only_map_h + 3), sizeof(char *));    // adding padding for null terminator + 1 extra cell on each side of map borders
    if (!copy_map)
        error_exit(cub, 4);
    i = -1;
    while (++i < cub->only_map_h + 2)  // 'i' iterating over rows along vertical axis, +2 to include added padding cells
    {
        copy_map[i] = ft_calloc(width + 3, sizeof(char)); // adding padding for null terminator + 1 extra cell on each side of map borders
        if (!copy_map[i])
            error_exit(cub, 4);
        j = -1;
        while (++j < width + 2)      // 'j' iterating over columns along horizontal axis, +2 to include added padding cells
            copy_map[i][j] = ' ';
        copy_map[i][j] = '\0';
    }
    copy_map[i] = NULL;
    paste_original(map, &copy_map, cub);
    return (copy_map);
}

static void    check_walls(t_program *cub, char **map)
{
    char **copy_map;

    copy_map = get_map_copy(cub, map);
    copy_walls_check(copy_map, cub);
    ft_free_matrix(copy_map);
}

// static char **get_trimmed_map(char **map, t_program *cub)
// {
//     int i;
//     char **trimmed_map;

//     i = 0;
//     trimmed_map = malloc(sizeof(char *) * (cub->only_map_h + 1));
//     while (i < cub->only_map_h)
//     {
//         trimmed_map[i] = ft_strtrim(map[i], " \t\n");
//         printf("%s\n", trimmed_map[i]);
//         i++;
//     }
//     trimmed_map[i] = NULL;
//     return (trimmed_map);
// }

// char *replace_tabs_with_spaces(char *line, int tab_width) {
//     int i, j = 0;
//     int len = 0;
//     char *new_line;

//     // Calculate new length accounting for tab width
//     for (i = 0; line[i]; i++) {
//         if (line[i] == '\t') {
//             len += tab_width;
//         } else {
//             len++;
//         }
//     }

//     // Allocate new line with the calculated length
//     new_line = malloc(sizeof(char) * (len + 1));
//     if (!new_line) {
//         return NULL; // Handle memory allocation error as needed
//     }

//     // Replace tabs with spaces
//     for (i = 0, j = 0; line[i]; i++) {
//         if (line[i] == '\t') {
//             int k;
//             for (k = 0; k < tab_width; k++) {
//                 new_line[j++] = ' ';
//             }
//         } else {
//             new_line[j++] = line[i];
//         }
//     }
//     new_line[j] = '\0';

//     return new_line;
// }

void    parser(char **argv, t_program *cub)
{
    char **contents;
    char **map;
    int i;
    //int tab_width = 4;
    //char **trimmed_map;

    contents = read_file(argv, cub);  //cub->map? assigned after all checks....
    map_values(cub, contents);
    // for (i = 0; contents[i] != NULL; i++) {
    //     char *new_line = replace_tabs_with_spaces(contents[i], tab_width);
    //     if (!new_line) {
    //         error_exit(cub, 4); // Handle memory allocation error
    //     }
    //     free(contents[i]);
    //     contents[i] = new_line;
    // }
    map = contents + 6;     //cub->only_map?
    cub->only_map_h = ft_get_matrix_size(map);  //cub->only_map_h??
    //trimmed_map = get_trimmed_map(map, cub);
    cub->map = malloc(sizeof(char *) * (cub->only_map_h + 1));
    if (!cub->map)
        error_exit(cub, 4); // Memory allocation error
    i = -1;
    while (++i < cub->only_map_h)
    {
        cub->map[i] = ft_strdup(map[i]);
        if (!cub->map[i])
        {
            error_exit(cub, 4);
            ft_free_matrix(contents);
            //ft_free_matrix(trimmed_map);
        }    
    }
    cub->map[cub->only_map_h] = NULL;
    check_map_content(cub, cub->map);   // ???? modify? **change to 'check_characters'
    check_walls(cub, cub->map);
    ft_free_matrix(contents);
    //ft_free_matrix(trimmed_map);
}



