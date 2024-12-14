import re
import os

# Function to parse the file
def parse_file(filename):
    # Lists to store results
    buttonsa = []
    buttonsb = []
    prizes = []

    # Regex patterns
    button_pattern = r"Button (\w): X\+(\d+), Y\+(\d+)"
    prize_pattern = r"Prize: X=(\d+), Y=(\d+)"

    with open(filename, 'r') as file:
        for line in file:
            # Match buttons
            button_match = re.match(button_pattern, line)
            if button_match:
                button_name = button_match.group(1)
                x_offset = int(button_match.group(2))
                y_offset = int(button_match.group(3))

                if button_name == 'A':
                    buttonsa.append([x_offset, y_offset])
                elif button_name == 'B':
                    buttonsb.append([x_offset, y_offset])

            # Match prizes
            prize_match = re.match(prize_pattern, line)
            if prize_match:
                x = int(prize_match.group(1)) + 10000000000000
                y = int(prize_match.group(2)) + 10000000000000
                prizes.append([x, y])

    return buttonsa, buttonsb, prizes

filename = 'input'  # Replace with the path to your file
buttonsa, buttonsb, prizes = parse_file(filename)

result = 0

for i, buttona in enumerate(buttonsa):
    print(i)
    ax = buttonsa[i][0]
    ay = buttonsa[i][1]
    bx = buttonsb[i][0]
    by = buttonsb[i][1]
    px = prizes[i][0]
    py = prizes[i][1]
    b_num = px * ay - py * ax
    b_den = bx * ay - by * ax
    if b_num % b_den:
      continue
    b = b_num / b_den
    a_num = px - b * bx
    a_den = ax
    if a_num % a_den:
        continue
    a = a_num / a_den

    result += 3 * a + b


print(result)