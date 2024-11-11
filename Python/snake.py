import tkinter as tk
import random

# Game Constants
ROWS, COLS = 25, 25
TILE_SIZE = 25
WINDOW_WIDTH, WINDOW_HEIGHT = TILE_SIZE * COLS, TILE_SIZE * ROWS

class Tile:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Initialize Game Window
window = tk.Tk()
window.title("Snake Game")
window.resizable(False, False)
canvas = tk.Canvas(window, bg="black", width=WINDOW_WIDTH, height=WINDOW_HEIGHT)
canvas.pack()

# Center Window
screen_width, screen_height = window.winfo_screenwidth(), window.winfo_screenheight()
window_x = int((screen_width / 2) - (WINDOW_WIDTH / 2))
window_y = int((screen_height / 2) - (WINDOW_HEIGHT / 2))
window.geometry(f"{WINDOW_WIDTH}x{WINDOW_HEIGHT}+{window_x}+{window_y}")

# Game Variables
snake = Tile(TILE_SIZE * 5, TILE_SIZE * 5)  # Snake's head
food = Tile(TILE_SIZE * 10, TILE_SIZE * 10)  # Initial food position
velocityX, velocityY = 0, 0  # Initial direction
snake_body = [Tile(snake.x, snake.y)]  # Start snake body with head position
game_over = False
score = 0

# Change Direction Function
def change_direction(event):
    global velocityX, velocityY
    if game_over:
        return
    if event.keysym == "Up" and velocityY == 0:
        velocityX, velocityY = 0, -1
    elif event.keysym == "Down" and velocityY == 0:
        velocityX, velocityY = 0, 1
    elif event.keysym == "Left" and velocityX == 0:
        velocityX, velocityY = -1, 0
    elif event.keysym == "Right" and velocityX == 0:
        velocityX, velocityY = 1, 0

# Move Function
def move():
    global snake, food, snake_body, game_over, score

    if game_over:
        return

    # Update Snake's Head Position
    snake.x += velocityX * TILE_SIZE
    snake.y += velocityY * TILE_SIZE

    # Check Wall Collision
    if snake.x < 0 or snake.x >= WINDOW_WIDTH or snake.y < 0 or snake.y >= WINDOW_HEIGHT:
        game_over = True
        return

    # Check Self Collision
    for tile in snake_body[1:]:
        if snake.x == tile.x and snake.y == tile.y:
            game_over = True
            return

    # Check Food Collision
    if snake.x == food.x and snake.y == food.y:
        # Add new tile to snake body
        snake_body.append(Tile(snake.x, snake.y))
        food.x, food.y = random.randint(0, COLS - 1) * TILE_SIZE, random.randint(0, ROWS - 1) * TILE_SIZE
        score += 1
    else:
        # Move snake body forward
        snake_body = [Tile(snake.x, snake.y)] + snake_body[:-1]

# Draw Function
def draw():
    global game_over

    # Clear Canvas
    canvas.delete("all")

    # Draw Food
    canvas.create_rectangle(food.x, food.y, food.x + TILE_SIZE, food.y + TILE_SIZE, fill='red')

    # Draw Snake
    for tile in snake_body:
        canvas.create_rectangle(tile.x, tile.y, tile.x + TILE_SIZE, tile.y + TILE_SIZE, fill='lime green')

    # Display Game Over or Score
    if game_over:
        canvas.create_text(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, font="Arial 20", text=f"Game Over. Score: {score}", fill="white")
    else:
        canvas.create_text(30, 20, font="Arial 10", text=f"Score: {score}", fill="white")

    move()
    window.after(100, draw)

# Bind Key Events and Start Game
window.bind("<KeyRelease>", change_direction)
draw()
window.mainloop()
