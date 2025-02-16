/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:08:16 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/16 23:15:58 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void check_wall(char *inpt)
{
    int a;
    int j;

    a = 0;
    j = 0;
    while(inpt[j] && inpt[j] != '\n')
    {
        if(inpt[j] == '1')
            a++;
        j++;
    }
    if(a != j)
        print_error("Erroor: check_wall\n");
}

int check_map(char *inpt)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(inpt[i])
    {
        if (inpt[0] == '1' && ( inpt[i] == '1' || inpt[i] == '0' || inpt[i] == 'C' || inpt[i] == 'P' || inpt[i] == 'E' || (inpt[i] == '\n' && inpt[i-1] == '1')))
            i++;
        else
            return(0);
    }
    return(1);
}

int check_palter_and_exit(char *inpt, char c)
{
    int i;
    int a;

    i = 0;
    a = 0;

    while(inpt[i])
    {
        if(inpt[i] == c)
            a++;
        i++;
    }
    return (a);
}

void check_width(char **inpt, int k)
{
    int i;
    int j;
    int t[k-1];

    i = 0;
    while(inpt[i])
    {
        j = 0;
        while(inpt[i][j])
            j++;
        if(j > 100)
            print_error("Erorr\n line2 100\n");
        if(inpt[i][j-1] != '\n')
            j++;
        t[i] = j;
        i++;
    }
    j = 0;
    while(i > 1)
    {
        if(t[j] != t[j+1])
            print_error("Error\n check_width\n");
        j++;
        i--;
    }
}
void validate_map(char **input, int k)
{
    int i;
    int j;
    int a;
    int t;

    i = 0;
    j = 0;
    a = 0;
    t = 0;
    while(input[i])
    {
        if(check_map(input[i]))
        {
            if(i == 0 || (k-1 == i && input[i]))
                check_wall(input[i]);
            j = j + check_palter_and_exit(input[i],'P');
            t = t + check_palter_and_exit(input[i],'E');
            a = a + check_palter_and_exit(input[i],'C');
        }
        else
            print_error("Error\n invalid map\n");
        i++;
    }
    if(j != 1 || t != 1 || a == 0)
        print_error("Error\n check_Collectible or check_player_and_exit\n");
}

int check_filr_ber(char *inpt)
{
    int i;
    int b;
    int a;
    char str[5] = ".ber";

    i = 0;
    b = 0;
    a = 0;
    while(inpt[i])
        i++;
    i = i - 4;
    while(b < 4)
    {
        if(inpt[i + b] == str[b])
            a++;
        b++;
    }
    if(a == 4)
        return(1);
    return (0);
    
}

int main(int ac, char **argv)
{
    int fd;
    char *line;
    int i = 0;
    char **str;
    int j = 0;
    int a;
    if (!check_filr_ber(argv[1]))
        print_error("Error\n not file.ber\n");
    fd = open(argv[1], O_RDONLY);
    if(!fd)
        print_error("Error1\n not file.ber\n");
    line = get_next_line(fd);
    if (!line)
        print_error("Error2\n");
    while(line)
    {
        str[i] = line;
        line = get_next_line(fd);
        if(i == 101)
            print_error("Error\n line100\n");
        i++;
    }
    str[i] = NULL;
    validate_map(str, i);
    check_width(str, i);
}
