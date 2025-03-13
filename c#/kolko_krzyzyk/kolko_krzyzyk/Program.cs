using System;

class Program
{
    static void Main(string[] args)
    {
        char[,] board = new char[3, 3];
        InitializeBoard(board);
        char currentPlayer = 'X';
        bool gameWon = false;

        while (!gameWon && !IsBoardFull(board))
        {
            PrintBoard(board);
            Console.WriteLine($"Gracz {currentPlayer}, wybierz wiersz i kolumnę (0, 1, 2):");
            int row = int.Parse(Console.ReadLine());
            int col = int.Parse(Console.ReadLine());

            if (board[row, col] == ' ')
            {
                board[row, col] = currentPlayer;
                gameWon = CheckWin(board, currentPlayer);

                if (gameWon)
                {
                    PrintBoard(board);
                    Console.WriteLine($"Gracz {currentPlayer} wygrywa!");
                }
                else
                {
                    currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
                }
            }
            else
            {
                Console.WriteLine("To pole jest już zajęte. Spróbuj ponownie.");
            }
        }

        if (!gameWon)
        {
            PrintBoard(board);
            Console.WriteLine("Remis!");
        }
    }

    static void InitializeBoard(char[,] board)
    {
        for (int i = 0; i < board.GetLength(0); i++)
        {
            for (int j = 0; j < board.GetLength(1); j++)
            {
                board[i, j] = ' ';
            }
        }
    }

    static void PrintBoard(char[,] board)
    {
        for (int i = 0; i < board.GetLength(0); i++)
        {
            for (int j = 0; j < board.GetLength(1); j++)
            {
                Console.Write(board[i, j]);
                if (j < board.GetLength(1) - 1)
                {
                    Console.Write("|");
                }
            }
            Console.WriteLine();
            if (i < board.GetLength(0) - 1)
            {
                Console.WriteLine("-----");
            }
        }
    }

    static bool CheckWin(char[,] board, char player)
    {
        for (int i = 0; i < 3; i++)
        {
            if ((board[i, 0] == player && board[i, 1] == player && board[i, 2] == player) ||
                (board[0, i] == player && board[1, i] == player && board[2, i] == player))
            {
                return true;
            }
        }

        if ((board[0, 0] == player && board[1, 1] == player && board[2, 2] == player) ||
            (board[0, 2] == player && board[1, 1] == player && board[2, 0] == player))
        {
            return true;
        }

        return false;
    }

    static bool IsBoardFull(char[,] board)
    {
        for (int i = 0; i < board.GetLength(0); i++)
        {
            for (int j = 0; j < board.GetLength(1); j++)
            {
                if (board[i, j] == ' ')
                {
                    return false;
                }
            }
        }
        return true;
    }
}
