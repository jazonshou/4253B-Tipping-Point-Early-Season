import pyperclip

# Auton namespaces (uncomment the auton you're working on)
auton = 'Skills'
# auton = 'AWP'
# auton = 'Left'
# auton = 'Right'


out = ''

# Opens the file where the path is stored temporarily
# Deletes all content of the file after processing
with open("scripts/text.txt", 'r+') as f:
    for line in f:
        out += line
    f.truncate(0)

# Makes sure user did not accidentally paste the already generated path
if(out.find('double') == -1):
    print('u high bro?')
    quit()

# Replace 'double' with 'Trajectory' 
out = 'Trajectory' + out[6:]

# Adds auton namespace next to path name
out = out[:11] + auton + '::' + out[11:]

# Removes '[][]'
val = out.find('[][]')
out = out[:val] + out[val+4:]

# Adds semicolon
out += ';'

# Copies path to clipboard
pyperclip.copy(out)

print('Path copied to clipboard!!!')