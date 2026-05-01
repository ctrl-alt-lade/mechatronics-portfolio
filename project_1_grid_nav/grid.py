environment = [
    ['.', '.', 'R', '.', '.'],
    ['.', 'X', 'X', '.', '.'],
    ['.', '.', '.', '.', '.'],
    ['.', 'X', '.', 'X', '.'],
    ['.', '.', '.', '.', 'G']
]

robot_row = 0
robot_col = 2

print("Attempting to move DOWN...")

# --- THE COMBINED SENSOR ---
# We want to move DOWN. 
# Step 1: Check if moving DOWN keeps us inside the map (row must be less than 4).
# Step 2: Check if the specific spot we want to move to (robot_row + 1) is an 'X'.

# YOUR TURN: 
# Write an if statement that checks BOTH conditions using 'and'. 
# If both are safe: Erase old spot, move DOWN, draw new spot.
if (robot_row < 4) and (environment[robot_row + 1][robot_col] != 'X'):
    environment[robot_row][robot_col] = '.'
    environment[robot_row + 1][robot_col] = 'R'
    print("Movement Successful")
 # Else: Print "Collision Alert: Movement Blocked!"
else:
    print("Collision Alert: Movement Blocked")


# --- THE DISPLAY LOOP ---
for row in environment:
    print(row)