/*
** EPITECH PROJECT, 2018
** my_include
** File description:
** include
*/

#ifndef MY__INCLUDES
#define MY__INCLUDES

#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

struct global
{
	int checks;
	int check;
	int checkss;
	int chec;
	int x;
	int y;
	int nb;
	int end;
} struc;

typedef struct st_navy {
	char **map_other;
	char **map;
	int err;
	int game;
	int pid;
	int win;
	int player;
	char *str;
} navy;

int my_getnbr(char const *str);
char **create_map(char **map);
int check_attack(char *str);
int check_victory(char **map);
void connect_game(navy *st, char **av);
void connect_player(navy *st, char **av);
char *convert_int_str(int nb, char *str);
void display_map(char **map);
void game(navy *st);
void play(navy *st);
void recup_data(navy *st, char *str);
void recup_pid(navy *st);
void send_pid(navy *st, int pid);
void send_signal(char *attack, navy *st);
void wait_other(navy *st);
void display_game(navy *st);
char *get_next_line(int fd);
void display_map(char **map);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);

#endif /* MY__INCLUDES */
