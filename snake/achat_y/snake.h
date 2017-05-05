/*
** snake.h for snake.h in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:20:21 2017 Achat Youmer
** Last update Fri May  5 09:00:42 2017 Achat Youmer
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define TAILLE_BLOCK 20
typedef struct position_s{
  int x;
  int y;
}position_t;

typedef struct bout_s{
  SDL_Surface *bout;
  SDL_Rect position_actuelle;
  SDL_Rect position_precedente;
  struct bout_s *next;
}bout_t;

typedef struct liste_bout_s{
  bout_t *first;
  bout_t *last;
  int nbr;
} liste_t;

typedef struct con_dir_s {
  int continuer;
  char direction;
  SDL_Surface *snake_actuelle; 
}con_dir;

enum {DROITE, GAUCHE, HAUT, BAS};

typedef struct bonus_position_s{
  SDL_Surface *bonus;
  SDL_Rect position;
  int ind;
} bonus_position;

SDL_Rect init_position();
void my_putstr(char *str);
bonus_position bonus(SDL_Surface *ecran, SDL_Rect position_bonus, SDL_Rect position_snake
		     , position_t ecran_size);
void aff_surface(position_t ecran_size,SDL_Surface *ecran, liste_t *liste, SDL_Rect position, SDL_Surface *snake_dir[4]);
bout_t * create_bout();  
int cmp_position(SDL_Rect position_bonus, SDL_Rect position_snake);
SDL_Rect deplacement_infini(char direction, SDL_Rect position_init, position_t ecan_size);
con_dir evennement(SDL_Event event, int continuer, char deplacement, SDL_Surface *snake_dir[4]);
void snake(char **argv);
void ajouter_bout(SDL_Rect position_snake, liste_t *liste_bout);
SDL_Rect changer_position(position_t ecran_size);
int     myRand(int low, int high);
liste_t *display_liste(SDL_Surface *ecran,liste_t *liste, SDL_Rect position_snake, int ind);
liste_t *ajouter_liste(liste_t *liste);
liste_t *init_liste(SDL_Surface *ecran);
SDL_Rect cp_position(SDL_Surface *snake,SDL_Rect position1);
int game_over_mur(SDL_Rect position, position_t cord_mur[42], int continuer);
int display_murs(SDL_Surface *ecran, SDL_Rect position, int continuer, position_t ecran_size);
int rejouer(SDL_Surface *ecran, SDL_Surface *game_over, int nbr);
int colision_snake(liste_t *my_liste, int continuer);
void game_princ(SDL_Surface *ecran, position_t ecran_size);
int     my_getnbr(char *str);
void score(SDL_Surface *ecran, int ind);
int test_rejouer(SDL_Surface *ecran, int ind);
char *my_put_nbr(int n);
char *my_strcat(char *dest, char *src);
