# basic_ludo
A fun, console-based Ludo game built in C to help beginners master arrays, loops, functions, and logic. Learn real-world programming by simulating turn-based gameplay, token movement, and collision handling. Perfect for students and anyone exploring C with a hands-on project.
# 🎲 Ludo Game in C

A console-based implementation of the classic **Ludo** board game using the C programming language. This project is a simplified version of Ludo, focusing on token movement, dice rolls, turn-taking, and basic win conditions.

---

## 🚀 Features

- Supports **2 to 4 players**
- Turn-based dice rolling
- Basic movement rules (including 6 to release a token)
- Token collisions (send opponents back to home)
- Victory detection (when a player brings all tokens to the end)
- Simple and clear board and token display

---

## 🧠 How It Works

1. **Board Setup**:
   - The board is represented by a 1D array (`char board[74]`), simulating 52 main board positions + home tracks.
   - Each player has 4 unique tokens (e.g., A, B, C, D for Player 1).

2. **Token States**:
   - `0`: Inactive (locked at home)
   - `1`: Active (on board)
   - `2`: Reached final home

3. **Game Flow**:
   - Players take turns rolling a dice.
   - Rolling a 6 allows a player to bring a token out.
   - Active tokens move forward by dice value.
   - If a token lands on an opponent's token, the opponent’s token is sent back to home.
   - Tokens that complete 57 steps reach the final home area.
   - First player with all 4 tokens home wins.

---

## 💻 How to Compile and Run

1. **Compile the program**:
     gcc -o ludo_game ludo.c
2. **Run the game:**
     ./ludo_game
3. **Gameplay Instructions:**

Enter the number of players (2 to 4).

Each player rolls automatically during their turn.

Choose a token to move when prompted (1-4).

Enter 5 to skip your turn if no valid move is possible.

**✅ Pros (Educational Value)**
Structuring in C: Demonstrates modular programming via functions (initialize_board, move, handle, etc.)

2D Arrays: Shows effective use of arrays for managing multiple players and their tokens.

Randomization: Uses rand() and srand() for simulating dice rolls.

Game Logic: Introduces real-world logic implementation in code (turns, movement, conditions).

Collision Detection: Adds interaction between players, teaching conditional branching and logic.

User Input Handling: Engages users with input prompts and decision-making.

**⚠️ Cons / Areas for Improvement**
Board Representation: A flat array (board[74]) can be confusing; splitting the board and home tracks would improve clarity.

Collision Risk with Same Token Letter: Relies on unique token characters; potential for logical conflict if reused.

Limited Input Validation: Invalid or unintended inputs can break flow (e.g., non-numeric input).

No Safe Zones: Unlike classic Ludo, no safe cells (e.g., stars) are implemented.

No Extra Turn for Rolling 6: In traditional rules, rolling a 6 grants another turn.

**📚 Why This is Great for C Beginners**
Introduces core C concepts:

Arrays and nested loops

Conditional logic

Functions and modular code

Handling user input with scanf

Random number generation

Encourages algorithmic thinking with a familiar game

Fun and interactive way to learn structured programming

Offers room to grow: beginners can add new rules or improve features (safe zones, better UI, extra turn, saving progress, etc.)

**🛠️ Potential Extensions**
Add extra turn when rolling a 6

Improve board visualization with color (using ANSI escape codes)

Implement safe cells

GUI version using SDL or ncurses

Online multiplayer or AI opponent

**📜 License**
This project is open-source and free to use. Attribution is appreciated but not required.

**🙌 Contribute**
Feel free to fork, improve, and send a pull request if you'd like to add more features or fix bugs!
