#include <stdio.h>
#include <stdlib.h>

void getDir(int a, int dir[2]){
  if (a == 1)
  {
    dir[0] = 0;
    dir[1] = 1;
  }
  else if (a == 2)
  {
    dir[0] = 1;
    dir[1] = 0;
  }
  else if (a == 3)
  {
    dir[0] = 0;
    dir[1] = -1;
  }
  else if (a == 4)
  {
    dir[0] = -1;
    dir[1] = 0;
  }
}

int turnLeft(int dir){
  int a = dir == 1 ? 4 : dir == 4 ? 3 : dir == 3 ? 2 : 1;
  return a;
}

int turnRight(int dir){
  int a = dir == 1 ? 2 : dir == 2 ? 3 : dir == 3 ? 4 : 1;
  return a;
}

int main(int argc, char const *argv[])
{
  FILE* forras = fopen("be.txt", "r");
  FILE* eredmeny = fopen("ki.txt", "w");

  int x, y;
  int table[22][22];
  fscanf(forras, "%d,%d", &y, &x);

  for (int i = 0; i < 22; i++)
  {
    for (int j = 0; j < 22; j++)
    {
      table[i][j] = -100;
    }
    
  }
  
  int a;

  int row = 1;
  int col = 1;

  do
  {
    int num;
    char item;
    a = fscanf(forras, "%d%c", &num, &item);
    if (a == 0)
    {
      break;
    }
    table[row][col] = num;
    col++;
    if (item == '\n')
    {
      col = 1;
      row++;
    }
  } while (a != 0);

  int dir = 2;
  int koord[2] = {0, 0};
  int first = 1;

  while (x >= 0 && y >= 0 && x < 22 && y < 22)
  {
    if (table[y][x] > -100)
    {
      printf("%d ", table[y][x]);
      if (first == 1)
      {
        fprintf(eredmeny, "%d", table[y][x]);
        first = 0;
      }
      else
      {
        fprintf(eredmeny, "%c%d", ',', table[y][x]);
      }
    }
    
    table[y][x] = -200;
    dir = turnLeft(dir);
    getDir(dir, koord);
    if (table[y+koord[0]][x+koord[1]] == -200)
    {
      dir = turnRight(dir);
    }
    getDir(dir, koord);

    y += koord[0];
    x += koord[1];
  }
  fprintf(eredmeny, "\n");
  
  
  
  fclose(forras);
  fclose(eredmeny);
  return 0;
}
