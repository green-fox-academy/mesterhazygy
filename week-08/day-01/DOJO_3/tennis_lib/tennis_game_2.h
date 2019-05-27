#ifndef TENNIS_GAME_TENNIS_GAME_2_H
#define TENNIS_GAME_TENNIS_GAME_2_H

typedef struct {
    int P1point;
    int P2point;
    char *player1_name;
    char *player2_name;
} tennis_game_2_t;

tennis_game_2_t create_tennis_game_2(const char player1_name[], const char player2_name[]);
void won_point_2(tennis_game_2_t *tennis_game, const char player_name[]);
const char *get_score_2(tennis_game_2_t *tennis_game);

#endif //TENNIS_GAME_TENNIS_GAME_2_H
