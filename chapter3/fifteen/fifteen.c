// Implements Game of Fifteen (generalized to d x d)

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR "\033[32m"

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Saved locations of the blank tile
int blank_row;
int blank_col;

// Prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int a, int b);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greet user with instructions
    greet();

    // Initialize the board
    init();

    // Accept moves until game is won
    while (true)
    {
        // Clear the screen
        clear();

        // Draw the current state of the board
        draw();

        // Log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // Prompt for move
        int tile = get_int("Tile to move: ");

        // Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // Log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // Sleep thread for animation's sake
        usleep(50000);
    }

    // Close log
    fclose(file);

    // Success
    return 0;
}

// Clears screen using ANSI escape sequences
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Greets player
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

void
swap(int i, int j)
{
    int temp;
    for (int a = 0; a < d; a++)
    {
        for (int b = 0; b < d; b++)
        {
            if (board[a][b] == 0)
            {
                temp = board[a][b];
                board[a][b] = board[i][j];
                board[i][j] = temp;
                return;
            }
        }
    }
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    int i, j;
    int sv = d * d; // left most value
    for (i = 0; i < d; i++)
    {
        // rows
        for (j = 0; j < d; j++)
        {
            // columns
            board[i][j] = --sv;
        }
    }
    if (d % 2 == 0)
    {
        // swap 3 and 2 tiles if d is an even number
        int temp = board[i - 1][j - 2];
        board[i - 1][j - 2] = board[i - 1][j - 3];
        board[i - 1][j - 3] = temp;
    }
}

// Prints the board in its current state
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        // rows
        printf("\n");
        for (int j = 0; j < d; j++)
        {
            // columns
            if (board[i][j] == 0)
            {
                printf("%3c| ", 95); // underscore
                continue;
            }
            printf("%3d| ", board[i][j]);
        }
    }
    printf("\n\n");
}
bool
check(int row, int column)
{
    if (row == d - 1)
    {
        // last row
        if (column == 0)
        {
            // last row FIRST column |_
            if (board[row - 1][column] == 0)
            {
                return true;
            }
            else if (board[row][column + 1] == 0)
            {
                return true;
            }
        }
        else if (column == d - 1)
        {
            // last row LAST column _|
            if (board[row - 1][column] == 0)
            {
                return true;
            }
            else if (board[row][column - 1] == 0)
            {
                return true;
            }
        }
        else
        {
            // last row MID column
            if (board[row - 1][column] == 0)
            {
                return true;
            }
            else if (board[row][column - 1] == 0)
            {
                return true;
            }
            else if (board[row][column + 1] == 0)
            {
                return true;
            }
        }
    }
    else if (row == 0)
    {
        // first row
        if (column == 0)
        {
            // first row FIRST column |^
            if (board[row][column + 1] == 0)
            {
                return true;
            }
            else if (board[row + 1][column] == 0)
            {
                return true;
            }
        }
        else if (column == d - 1)
        {
            // first row LAST column ^|
            if (board[row][column - 1] == 0)
            {
                return true;
            }
            else if (board[row + 1][column] == 0)
            {
                return true;
            }
        }
        else
        {
            // top row MID column
            if (board[row + 1][column] == 0)
            {
                return true;
            }
            else if (board[row][column + 1] == 0)
            {
                return true;
            }
            else if (board[row][column - 1] == 0)
            {
                return true;
            }
        }
    }
    else if (column == 0)
    {
        // first column |->
        if (board[row - 1][column] == 0) // up
        {
            return true;
        }
        else if (board[row + 1][column] == 0) // down
        {
            return true;
        }
        else if (board[row][column + 1] == 0)
        {
            return true;    // -> right
        }
    }
    else if (column == d - 1)
    {
        // last column <-|
        if (board[row - 1][column] == 0) // up
        {
            return true;
        }
        else if (board[row + 1][column] == 0) // down
        {
            return true;
        }
        else if (board[row][column - 1] == 0)
        {
            return true;    // <- left
        }
    }
    else
    {
        if (board[row + 1][column] == 0) // row
        {
            return true;
        }
        else if (board[row - 1][column] == 0) // down
        {
            return true;
        }
        else if (board[row][column + 1] == 0) // ->
        {
            return true;
        }
        else if (board[row][column - 1] == 0) // <-
        {
            return true;
        }
    }

    return false;
}


// If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile)
{
    // check block for tile
    for (int i = 0; i < d; i++)   // row
    {
        for (int j = 0; j < d; j++)   // column
        {
            if (board[i][j] == tile)
            {
                if (!check(i, j)) // TODO
                {
                    return false;
                }
                else
                {
                    swap(i, j); // TODO
                    return true;
                }
            }
        }
    }
    return false;
}

// Returns true if game is won (i.e., board is in winning configuration), else false
bool won(void)
{
    int end = d * d - 1;
    int check = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == check && check <= end)
            {
                check = check + 1;
                continue;
            }
            else if (check > end)
            {
                return true;
            }
            else
            {
                break;
            }
        }
    }
    return false;
}

