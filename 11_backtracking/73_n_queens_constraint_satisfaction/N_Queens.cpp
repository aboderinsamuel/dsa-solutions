#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // 1. Storage for all valid board solutions we find.
    // Example: { {".Q..", "...Q", "Q...", "..Q."}, ... }
    vector<vector<string>> result;
    
    // 2. The current board we are building step-by-step.
    // Example for n=4: { "....", "....", "....", "....", }
    vector<string> board;
    
    // 3. Tracks columns that already have a queen so we don't put two queens in one column.
    // Example: If a queen is at col 1, this set contains {1}.
    unordered_set<int> cols;
    
    // 4. Tracks top-left to bottom-right diagonals. 
    // Math trick: row - col is always unique for every diagonal moving in this direction.
    unordered_set<int> diag1;
    
    // 5. Tracks bottom-left to top-right diagonals. 
    // Math trick: row + col is always unique for every diagonal moving in this direction.
    unordered_set<int> diag2;

    // The recursive function that tries to place queens row by row.
    // Let's assume n = 4, and we are tracking what happens when we place our first queen at row 0, col 0.
    void backtrack(int row, int n){
        
        // Base case: check if we have successfully placed a queen in every row (0 to n-1).
        // If row reaches 4, it means rows 0, 1, 2, and 3 all have queens.
        if(row == n){
            // Add our completed board to our master 'result' list.
            result.push_back(board);
            // Stop this specific path and go back to try other combinations.
            return;
        }
        
        // Try placing a queen in each column of the current 'row'.
        // We test col = 0, then col = 1, then col = 2, then col = 3.
        for(int col=0; col < n; col++){
            
            // Check if the spot (row, col) is safe from other queens.
            // It asks: Is 'col' taken? Is diagonal 1 (row - col) taken? Is diagonal 2 (row + col) taken?
            if(cols.count(col) || diag1.count(row - col) || diag2.count(row + col)){
                // If any of these are true, this spot is attacked! 
                continue; // Skip this column immediately and move to the next iteration of the loop.
            }
            
            // --- IF THE SPOT IS SAFE ---
            
            // Place the queen as 'Q' on our grid at the current row and column.
            // Example: board[0][0] becomes 'Q'. Board looks like: {"Q...", "....", "....", "...."}
            board[row][col] = 'Q';
            
            // Lock this column so no other queen can be placed in it.
            // cols set gets {0}.
            cols.insert(col);
            
            // Lock the downward diagonal passing through this square.
            // diag1 set gets (0 - 0) = {0}.
            diag1.insert(row - col);
            
            // Lock the upward diagonal passing through this square.
            // diag2 set gets (0 + 0) = {0}.
            diag2.insert(row + col);

            // Move to the next row (row + 1) to place the next queen, keeping 'n' the same.
            // This pauses our current work and jumps into a new 'backtrack' state for row 1.
            backtrack(row + 1, n);

            // --- BACKTRACKING STEP ---
            // This code runs when the backtrack(row + 1, n) call above finishes (either it found a solution or hit a dead end).
            // We must undo our choice at (row, col) to try putting the queen in the next available column instead.
            
            // Remove the queen by resetting the spot to a dot '.'.
            // Board[0][0] becomes '.'. Board looks like: {"....", "....", "....", "...."}
            board[row][col] = '.';
            
            // Free the column so it can be used in the next loop iteration.
            // cols set erases 0, becoming empty {}.
            cols.erase(col);
            
            // Free the downward diagonal.
            // diag1 set erases 0, becoming empty {}.
            diag1.erase(row - col);
            
            // Free the upward diagonal.
            // diag2 set erases 0, becoming empty {}.
            diag2.erase(row + col);
            
        // The loop goes back to the top: 'col' increases by 1 (e.g., moves to col 1), and we test the spot again.
        }
    }

public:
    // The main function that gets called when you run the program.
    vector<vector<string>> solveNQueens(int n) {
        
        // Initialize our 'board' variable with a size of 'n', where each row is a string of dots '.' of length 'n'.
        // Example for n=4: board becomes { "....", "....", "....", "....", }
        board = vector<string>(n, string(n, '.'));

        // Start the backtracking process at row 0, passing along our board size 'n'.
        // This kicks off the whole recursive trial-and-error process.
        backtrack(0, n);

        // After all recursive paths finish, return the collected 'result' list containing all valid board layouts.
        return result;
    }
};

```